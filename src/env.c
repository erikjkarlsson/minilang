/**
 * @file env.c
 * @beief Environment / State-handling
 * Copyright (c) 2026 blu3
 **/

 /************************************************************************** \
 * *
 * This program is free software: you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation, version 3.                                *
 * *
 * This program is distributed in the hope that it will be useful, but     *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
 * General Public License for more details.                                *
 * *
 * You should have received a copy of the GNU General Public License       *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.    *
 * *
 \**************************************************************************/

#include "env.h"

extern void free_value(Value *v);
extern int yylineno;

/* Environment Reference Counting Helpers */

/**
 * @brief Increases the reference count of an environment.
 * @param env The environment to retain.
 */
void env_retain(Env *env) {
    if (env) {
        env->ref_count++;
    }
}

/**
 * @brief Decreases the reference count of an environment.
 * Frees the environment if the count drops to zero.
 * @param env The environment to release.
 */
void env_release(Env *env) {
    if (!env) return;

    if (env->ref_count > 0) {
        env->ref_count--;
    }

    if (env->ref_count == 0) {
        // Only free the current scope when the last reference is gone.
        // The original free_env logic (renamed to env_cleanup_bindings)
        // is now responsible for the memory deallocation.
        free_env(env, false);
    }
}

/**
 * @brief Frees all bindings and the Env struct itself, without recursing up the parent chain.
 * This is the actual memory deallocation logic, now called by free_env.
 * @param env The environment to clean up.
 */
static void env_cleanup_bindings(Env *e) {
    if (!e) return;

    Env *parent = e->parent;
    e->parent = NULL;
    Binding *b = e->bindings;
    while (b) {
        Binding *nxt = b->next;
        if (b->val) {
            free_value(b->val);
        }
        if (b->name) {
            free(b->name);
        }
        free(b);
        b = nxt;
    }

    e->bindings = NULL;

    // Now safe to free current
    free(e);
}
/* ---------- Environment Implementation ---------- */
Env *new_env(Env *parent) {

    Env *e = calloc(1, sizeof(Env));

    if (!e) {

        fprintf(stderr, "Fatal: calloc failed in new_env\n");
        exit(EXIT_FAILURE);
    }
    e->parent = parent;
    e->bindings = NULL;
    e->ref_count = 1;
    return e;
}

/**
 * @brief Frees an environment. If ref_count is 0, it cleans up all resources.
 * If recurse is true, it frees parents (used for global/REPL cleanup).
 * If recurse is false, it only frees the current scope if its ref_count is 0.
 *
 * NOTE: For local scopes in 'eval', free_env(local, false) will be replaced
 * by env_release(local), which only calls cleanup if ref_count is 0.
 *
 * @param env The environment to free.
 * @param recurse Whether to free parent environments as well.
 */
// In 'env.c'

// The 'free_env' function is for administrative cleanup (like REPL exit).
// It should recursively free parents regardless of their ref_count, but it
// should call env_cleanup_bindings() only on the current environment.

void free_env(Env *env, bool recurse) {
    if (!env) return;

    Env *e = env;
    while (e) {
        Env *next_env = e->parent;

        // Decrement the reference count if it's not the REPL's final cleanup
        // (This is tricky. For a clean REPL exit, we need to force-free).
        // Let's assume 'free_env(global_env, true)' is the *only* place
        // 'recurse=true' is used.

        // Clean up the current environment's bindings and the Env struct itself.
        // We *must not* use env_cleanup_bindings here if the environment is still
        // referenced by a closure, unless we are truly doing final, recursive cleanup.

        // If 'recurse' is true (e.g., REPL exit), we force cleanup.
        // If 'recurse' is false, it means we are trying to free a local scope.
        // Local scopes should be freed by eval directly via 'env_cleanup_bindings',
        // not via free_env.

        if (recurse) {
            env_cleanup_bindings(e); // Force free for global cleanup
        } else {
            // Local scopes are typically cleaned up by eval calling
            // env_cleanup_bindings(local_env) OR env_release(closure_env).
            // This function (free_env) is often redundant/confusing if used for local scopes.
            // Let's assume you only use env_release for closures and free_env
            // for REPL exit.
            // If you use free_env(local, false) for local scope cleanup,
            // it means local scopes DO NOT use ref counting, and should be freed here.
            env_cleanup_bindings(e); // Assume local scope cleanup requires this
        }

        if (!recurse) break;
        e = next_env;
    }
}
void env_set(Env *env, char *name, Value *val, bool is_const) {
    Binding *b = malloc(sizeof(Binding));

    if (!b) {
        fprintf(stderr, "Line %d: Fatal, malloc failed for '%s' in env_set\n", yylineno, name);
        exit(EXIT_FAILURE);
    }

    b->name = dupstr(name);
    b->val = val;
    b->is_const = is_const;
    b->next = env->bindings;
    env->bindings = b;
}

Value *env_get(Env *env, char *name) {
    for (Env *e = env; e; e = e->parent) {
        for (Binding *b = e->bindings; b; b = b->next) {
            if (strcmp(b->name, name) == 0) {
                /* return a duplicate so caller owns the result and can free it */
                return dup_value(b->val);
            }
        }
    }
    fprintf(stderr, "Line %d: Error undefined variable '%s'\n", yylineno, name);
    return NULL;
}

void env_update(Env *env, char *name, Value *val) {
    for (Env *e = env; e; e = e->parent) {
        for (Binding *b = e->bindings; b; b = b->next) {
            if (strcmp(b->name, name) == 0) {
                if (b->is_const) {
                    fprintf(stderr, "Line %d: Error cannot assign to constant '%s'\n", yylineno, name);
                    return;
                }
                if (b->val) {
                    free_value(b->val);
                }
                b->val = val;
                return;
            }
        }
    }
    fprintf(stderr, "Line %d: Error assignment to undefined variable '%s'\n", yylineno, name);
}
