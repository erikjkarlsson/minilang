#ifndef TRACE_STACK_H
#define TRACE_STACK_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>

// Maximum depth of the trace stack

#ifndef TRACE_STACK_MAX_DEPTH
#define TRACE_STACK_MAX_DEPTH 16
#endif

typedef unsigned short u16_t;

// Structure to hold a single trace entry
typedef struct {
    const char* func_name;
    const char* file_name;
    u16_t line_number;
} trace_entry_t;

// The trace stack itself
typedef struct {
    trace_entry_t entries[TRACE_STACK_MAX_DEPTH];
    u16_t depth;
} trace_stack_t;

// Initialize the trace stack
static inline void trace_stack_init(trace_stack_t* stack);

// Log a function call or position
#define TRACE_STACK(stack, func_name) \
    trace_stack_log(stack, func_name, __FILE__, __LINE__)

// Log a specific position within a function
#define TRACE_STACK_POS(stack, func_name, pos_name) \
    trace_stack_log(stack, func_name ":" pos_name, __FILE__, __LINE__)

// Log an entry
static inline void trace_stack_log(trace_stack_t* stack, const char* func_name, const char* file_name, u16_t line_number);

// Display the current backtrace
static inline void trace_stack_dump(trace_stack_t* stack, FILE* out);

// Save the current state of the trace stack
static inline void trace_stack_save(trace_stack_t* stack, const char* filename);

// Restore the trace stack from a saved state
static inline int trace_stack_restore(trace_stack_t* stack, const char* filename);

// Install signal handlers to display backtrace on exceptions
static inline void trace_stack_install_signal_handlers(trace_stack_t* stack);


// Initialize the trace stack
static inline void trace_stack_init(trace_stack_t* stack) {
    stack->depth = 0;
    memset(stack->entries, 0, sizeof(stack->entries));
}

// Log an entry
static inline void
trace_stack_log(trace_stack_t* stack,
                const char* func_name,
                const char* file_name,
                u16_t line_number) {
    if (stack->depth < TRACE_STACK_MAX_DEPTH) {
        trace_entry_t* entry = &stack->entries[stack->depth++];
        entry->func_name = func_name;
        entry->file_name = file_name;
        entry->line_number = line_number;
    }
}

// Display the current backtrace
static inline void
trace_stack_dump(trace_stack_t* stack, FILE* out) {
    fprintf(out, "Backtrace (most recent call last):\n");
    for (u16_t i = stack->depth - 1; i > 0; --i) {
        const trace_entry_t* entry = &stack->entries[i];
        fprintf(out, "  %s (%s:%d)\n",
                entry->func_name,
                entry->file_name,
                entry->line_number);
    }

    fflush(out);
}

// Save the current state of the trace stack
static inline void
trace_stack_save(trace_stack_t* stack, const char* filename) {
    FILE* f = fopen(filename, "wb");
    if (f) {
        fwrite(stack, sizeof(trace_stack_t), 1, f);
        fclose(f);
    }
}

// Restore the trace stack from a saved state
static inline int trace_stack_restore(trace_stack_t *stack,
                                        const char *filename)
{
    FILE* f = fopen(filename, "rb");
    if (f) {
        fread(stack, sizeof(trace_stack_t), 1, f);
        fclose(f);
        return 0;  // success
    }
    return -1;  // failure
}


// Signal handler to display backtrace
static inline void
signal_handler(int sig, siginfo_t* info, void* ucontext) {
    trace_stack_t* stack = (trace_stack_t*) info->si_value.sival_ptr;
    fprintf(stderr, "Received signal %d; dumping call graph:\n", sig);
    trace_stack_dump(stack, stderr);

    // Re-raise the signal to trigger default handling
    signal(sig, SIG_DFL);
    raise(sig);
}

// Install signal handlers to display backtrace on exceptions
static inline void
trace_stack_install_signal_handlers(trace_stack_t* stack) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;

    // Common fatal signals
    const int sigs[] = {SIGSEGV, SIGABRT, SIGBUS, SIGILL, SIGFPE};
    for (size_t i = 0; i < sizeof(sigs) / sizeof(sigs[0]); ++i) {
        sigaction(sigs[i], &sa, NULL);

        // Send signal to ourselves with stack pointer
        kill(getpid(), sigs[i]);
    }
}

#ifdef __cplusplus
namespace trace_stack {
// C++ exception handler to display backtrace
static inline
void cpp_exception_handler() {
    try {
        throw;  // re-throw the current exception
    } catch (const std::exception& e) {
        fprintf(stderr, "Caught C++ exception: %s\n", e.what());
        // Assuming a global trace_stack_t instance named 'g_trace_stack'
        extern trace_stack_t g_trace_stack;
        fprintf(stderr, "Dumping backtrace:\n");
        trace_stack_dump(&g_trace_stack, stderr);
        throw;  // re-throw to propagate the exception
    }
}

static inline
void install_cpp_exception_handler(trace_stack_t* stack) {
    std::set_terminate(cpp_exception_handler);
}
}  // namespace trace_stack
#endif  // __cplusplus


// C++ exception handler to display backtrace
#ifdef __cplusplus
namespace trace_stack {
void install_cpp_exception_handler(trace_stack_t* stack);
}
#endif

#endif  // TRACE_STACK_H
