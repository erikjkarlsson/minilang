MLN - MiniLaNg
==============

A interpreter / REPL for a tiny functional programming language implemented in
Flex and Bison (C).


```mln
(λx.x(1))(λy.1 + y)
(λx.(x)(1))(λy.1 + y)
=> 2

(λx.λy.x+y)(1)(2)
=> 3

# Pass itself as argument to allow for recursion
const f := λg.λy.
    if (y <= 1)
    then 1
    else (y * g(g)(y - 1))
=> 𝝺g.λy.if y <= 1 then 1 else y * ((g)(g))(y - 1)
# Define factorial
const fact := f(f)
=> 𝝺y.if y <= 1 then 1 else y * ((g)(g))(y - 1)
fact(10)
=> 3628800

(\x.\y.\z.x+y/z)(1)(2)(3)
(((λx.λy.λz.x + y / z)(1))(2))(3)
=> 1.67

```







Features
--------

- **Functional Programming**:  First-class functions, closures, and lambda expressions
- **Static Scoping**: Lexical scoping with proper closure capture
- **Strong Typing**: Runtime type checking with clear error messages
- **Multiple Data Types**: Integers, floats, booleans, strings, and functions
- **Control Structures**: If-then-else expressions with boolean logic
- **Variable Binding**: Let expressions for local bindings and constants
- **Arithmetic Operations**: Full set of mathematical infix operators with proper precedence
- **String Operations**: String concatenation and manipulation

- **File Execution**: Run MLN scripts from files

How To Execute Files
--------------------

```shell
# Read file directly
$ ./bin/ml tests/math.mln

# Send file content through standard input
$ ./bin/ml < tests/math.mln
```

Language Syntax
---------------

### Basic Expressions

```mln
# Numbers
42
3.14159
-123

# Booleans
true
false

# Strings
"Hello, World!"
"MLN Language"

# Variables
x
myVariable
PI
```

### Arithmetic Operations

```mln
# Basic arithmetic
1 + 2 * 3        # => 7
(1 + 2) * 3      # => 9
10 / 3           # => 3.33333
10 % 3           # => 1

# Comparison
5 > 3            # => true
5 <= 3           # => false
10 == 10         # => true
1 != 2           # => true
```

### Boolean Logic

```mln
T and F   # => false
T or F    # => true
not T         # => false
```


Todo:

 - [ ] `T or (1 / 0)` should return `T` without computing `(1 / 0)`
 - [ ] Any value not equal to `F` should behave as `T`.


### String Operations

```mln
"Hello" + " " + "World"  # => "Hello World"
```

Todo:
 - [ ] Format strings `"Count: {42+1}" => "Count: 43"`
 - [ ] Num to string conversion `str(12) => "12"`
 - [ ] String to num conversion `num("12"") => 12`
 - [ ] Standard Output `put("hello world\n")`

### Variable Bindings

```mln
# Local / scoped variables
let x := 10 in x * 2
# => 20

# Nested bindings
let    x := 5
in let y := x + 5
   in  x + y
# => 10

# Multiple bindings
let    x := 1
in let y := 2 + x
in let z := (3 * x) + y
    in x + y + z
# => 10
```

Todo:
 - [ ] Allow for multivar definition in one `let` expression, i.e;

 ```mln
let x := 1
    y := 2
    z := 3
in x + y + z
```

### Functions

```mln
# Lambda expressions

\x. x + 1
# => <function>

\x. \y. x + y
# => <function>

# Function application

(\x. x * 2)(5)
# => 10

(\x. \y. x + y)(1)(2)
# => 3

# Higher-order functions

let    f := \x. \y. x + y
in let g := f(5)
    in g(3)
# => 8

# Recursive functions

# Example: Factorial
let f := \g. \n.
   if (n <= 1)
   then 1
   else n * g(g)(n - 1)
in let fact := f(f)
    in fact(10)

# => 3628800
```

### Control Structures

```mln

# If-then-else expressions

if T then 42 else 1
# => 42

# Complex conditions
# Example: Check if x is in range (0,10)

let x := 11
in if (x > 0) and (x < 10)
   then "Between 0 and 10"
   else "Outside range"
# => "Outside range"

# Nested conditions
let x := 11
in if x > 0
   then if x > 100
        then "Large"
        else "Medium"
   else "Small"
# => "Medium"
```

### Constants

```mln

# Constants

const PI       := 3.14159
const MAX_SIZE := 1000
const GREETING := "Hello"
# => 3.14159
# => 1000
# => "Hello"

PI
# => 3.14159

MAX_SIZE
# => 1000

const PI := 3.14
=> 3.14
const PI := 3.11
=> 3.11
PI
# => 3.11
```


Todo:
 - [ ] Use `var` instead of `const` since it is a global mutable.
 - [ ] Use `:=` when a value is mutated, and `=` when a value is first set.

### Blocks and Sequences

```mln
10;  20;  30;
# => 30
```

Todo:

 - [ ] Fix do blocks

### Variable Assignment

```mln
const x := 1
=> 1
const x := x + 1
=> 2
const x := x + 1
=> 3
const x := x + 1
=> 4
```

## Operator Precedence

From highest to lowest precedence:

  1.  `()` (Function application)
  2.  `-` (Unary minus), `not`
  3.  `*`, `/`, `%` (Multiplication, Division, Modulo)
  4.  `+`, `-` (Addition, Subtraction)
  5.  `==`, `!=`, `<`, `>`, `<=`, `>=` (Comparison)
  6.  `and`
  7.  `or`

Todo: Finish this

## Built-in Functions

Currently, the language focuses on core language features. Future versions may include:

Todo:
  - `put(value)` - Print a value to stdout
  - `read()` - Read input from stdin
  - `len(string)` - Get string length
  - `fst(list)` - Get first element of list
  - `snd(list)` - Get list without first element
  - `[1 2 3 4]` - List
  - `[1]+[1 2 3 4] => [1 1 2 3 4]` - Concatenate lists
  - `[1 1 2 3 4]!1 => 1` - Element index
  - `[1 1 2 3 4] drop 1 => [1 2 3 4]` - Drop
  - `[1 1 2 3 4] take 1 => [1]` - Take
  - `1 : 2` - Pair

## Examples

### (Working) Fibonacci Sequence

```mln
let iter := \f. \n.
    if n <= 1
    then n
    else f(f)(n - 1) + f(f)(n - 2)
  in let fib := iter(iter)
     in fib(3)
# => 55
```


### (TODO) Higher-Order Functions

```mln
# Map function
let iter := \g. \f. \list.
  if list == [] then []
  else [f(head(list))] + iter(g)(f)(tail(list))
in let map := iter(iter)
   in map(\x. x * 2)([1 2 3])

let double := \x. x * 2
in map(double)([1, 2, 3, 4])
# => [2, 4, 6, 8]
```

### (TODO) Mathematical Calculations

```mln
# Area of circle
const PI := 3.14159
let circle_area := \radius. PI * radius * radius
in circle_area(5)
# => 78.53975

# Quadratic formula
let quadratic := \a. \b. \c.
  let discriminant := b * b - 4 * a * c
  in if discriminant < 0
     then "No real roots"
     else let sqrt_disc := sqrt(discriminant)
     in   let root1     := (-b + sqrt_disc) / (2 * a)
     in   let root2     := (-b - sqrt_disc) / (2 * a)
     in root1
in quadratic(1)(2)(3)
```

Should work after `sqrt` has been added.

## Running MLN

### Interactive Mode

```bash
$ ./bin/ml
Type 'quit' or 'exit' to leave.

"hello"
=> "hello"
```

### Script Mode

```bash
$ ./bin/ml test/math.mln
=> 1.23
=> 123
=> 10
=> 114.23
  [...]
=> -100
=> 11
=> 0
=> -40
=> -40
=> -40
=> 0
=> 3
Goodbye!
```

## Building from Source

### Prerequisites

 - `GCC`
 - `Flex`
 - `Bison`
 - `GNU Make`

### Building

```bash
# Build binary
$ make bin/ml
# or
$ make all

# Run tests
$ make test

# Clean trash files
$ make clean
```

(TODO) Error Handling
---------------------

Example error messages:
```
Line 3: Error: Division by zero
Line 5: Error: IF condition must be a boolean
Line 7: Error: NOT requires a boolean operand
```

Design Philosophy
-----------------
**MLN** is a functional language inspired by Lisp and Haskell designed to:

  1. Combine the use of regular mathematical syntax with Lambda expressions
  2. Simple and small
  3. Easy to understand its implementation.


Todo
----

Planned features for future versions:
 
 - [ ] Encode lambda terms as numbers instead of
       as their string value as expressions like
       `\x.\x.x+x` becomes meaningless.
 - [ ] List and array data structures

 - [ ] Haskell like pattern matching

 - [ ] Scheme like macros

 - [ ] Pretty syntax for named functions

 - [ ] Input / Output
   - STDIN / STDOUT
   - File descriptor read / write
   - tcp

 - [ ] Standard library

 - [ ] Tail call optimization

 - [ ] Memoization

 - [ ] Type checking and inference

 - [ ] Byte-code interpreter

 - [ ] Simple compiler

License
-------

This project (mln) is licensed under the GNU General Public License v3.0 see the
`LICENSE` file for more details.

    Copyright (c) 2026 blu3

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3.

    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
