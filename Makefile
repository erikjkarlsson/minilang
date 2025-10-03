# Directories
BIN       := bin/ml
SRC_D     := src
LIB_D     := c-utils/src
OBJ_D     := obj
LIBS_D    := libs

# Test files
UNITTESTS := tests/test1.mln

# Source files
BISON_SRC := $(SRC_D)/ml.y
FLEX_SRC  := $(SRC_D)/ml.l
ENV_SRC   := $(SRC_D)/env.c
LIB_SRC   := $(LIB_D)/stringlib.c

# Generated files
BISON_OUT := $(SRC_D)/ml.tab.c $(SRC_D)/ml.tab.h
FLEX_OUT  := $(SRC_D)/lex.yy.c
LIB_OBJ   := $(OBJ_D)/stringlib.o

# Compiler flags
CC        := gcc
CFLAGS    := -g -O2 -Wall
LDFLAGS   := -L$(LIBS_D) -Wl,-rpath,$(LIBS_D)
INCLUDES  := -I$(SRC_D) -I$(LIB_D)

.PHONY: all clean test dirs

all: dirs $(BIN)

# Create necessary directories
dirs:
	@mkdir -p bin
	@mkdir -p $(OBJ_D)
	@mkdir -p $(LIBS_D)

# Bison: Generate parser
$(SRC_D)/ml.tab.c $(SRC_D)/ml.tab.h: $(BISON_SRC)
	cd $(SRC_D) && bison -Wconflicts-sr -t -v -d ml.y

# Flex: Generate lexer
$(SRC_D)/lex.yy.c: $(FLEX_SRC) $(SRC_D)/ml.tab.h
	cd $(SRC_D) && flex ml.l

# Compile external library as object file
$(OBJ_D)/stringlib.o: $(LIB_D)/stringlib.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile external library as object file
$(OBJ_D)/fileutils.o: $(LIB_D)/fileutils.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link everything together
$(BIN): $(SRC_D)/lex.yy.c $(SRC_D)/ml.tab.c $(SRC_D)/ml.tab.h $(ENV_SRC) $(OBJ_D)/fileutils.o $(OBJ_D)/stringlib.o
	$(CC) $(CFLAGS) $(INCLUDES) \
		$(SRC_D)/lex.yy.c \
		$(SRC_D)/ml.tab.c \
		$(ENV_SRC) \
		$(OBJ_D)/stringlib.o \
		$(OBJ_D)/fileutils.o \
		-o $(BIN) \
		-lm
	@echo "Build complete: $(BIN)"

# Clean build artifacts
clean:
	rm -f ./$(SRC_D)/ml.tab.c $(SRC_D)/ml.tab.h $(SRC_D)/lex.yy.c
	rm -f ./$(SRC_D)/ml.output
	rm -f ./$(OBJ_D)/*.o
	rm -f ./$(BIN)
	@echo "Clean complete"

# Run tests
test: $(BIN)
	@echo "Running tests..."
	./$(BIN) < $(UNITTESTS)

# Run interactive mode
run: $(BIN)
	./$(BIN)
