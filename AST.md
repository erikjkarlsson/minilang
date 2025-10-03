# Formal Definition of the Functional Language MLN


MLN language is a
 - **dynamically-typed**
 - **lexically-scoped** (and mostly)
 - **functional**

And supports:

- First-class functions (lambdas with closures)
- Eager evaluation (call-by-value)
- Imperative features (mutable variables, assignment, sequencing)
- Standard arithmetic, logical, and comparison operators
- Conditional expressions (`if-then-else`)
- Local bindings (`let-in`)
- Top-level constant and variable definitions


Lexical Structure
-----------------
**Terminals:**

  - **Literals:** `INT`, `FLOAT`, `STRING`, `true` (T), `false` (F)
  - **Identifiers:** `[a-zA-Z_][a-zA-Z_0-9]*`
  - **Keywords:** `if`, `then`, `else`, `let`, `in`, `const`, `var`, `do`, `end`, `fun`, `and`, `or`, `not`, `quit`
  - **Operators:** `+`, `-`, `*`, `/`, `%`, `:=`, `==`, `!=`, `<`, `>`, `<=`, `>=`
  - **Delimiters:** `(`, `)`, `[`, `]`, `;`, `,`, `.`, `:`, `->`, `::`
  - **Lambda:** `λ` (or `\`, `𝝺`, `𝜆`, `𝛌`, `𝞴`)


Context-Free Grammar
--------------------

 - Keyywords: `if, then, else, let, in, const, var, do, end, fun, and, or, not, quit`

 - Operators: `+, -, *, /, %, :=, ==, !=, <, >, <=, >=`

 - Delimiters: `(, ), [, ], ;, ,, ., :`

 - Lambda Symbols: `λ, \, 𝝺, 𝜆, 𝛌, 𝞴`




### Identifiers and Literals

```
ID      ::= (a-z | A-Z | '_') (a-z | A-Z | 0-9 | '_')*
INT     ::= (0-9)+
FLOAT   ::= (0-9)+ '.' (0-9)+
STRING  ::= '"' (any char except '"' or '\' | escape sequence)* '"'
BOOL    ::= 'T' | 'F'
NL      ::= '\n'
```

### Top-Level

```
PROGRAM   ::= ε                         (* An empty program *)
            | PROGRAM STATEMENT

STATEMENT ::= EXPR (';' | NL)
            | ASSIGNMENT NL
            | CONSTDEF NL
            | MVARDEF NL
            | 'quit' NL
            | NL                        (* An empty line *)
```

### Definitions and Assignments

```
ASSIGNMENT ::= ID ':=' EXPR

CONSTDEF   ::= 'const' ID [':' ID] ':=' EXPR

MVARDEF    ::= 'mvar' ID [':' ID] ':=' EXPR
```

### Expressions incl. Operator Precedence

```
EXPR       ::= LOGIC_OR_EXPR
             | IFEXPR
             | LETEXPR
             | LAMBDAEXPR
             | BLOCKEXPR

LOGIC_OR_EXPR ::= LOGIC_AND_EXPR
                | LOGIC_OR_EXPR 'or' LOGIC_AND_EXPR

LOGIC_AND_EXPR ::= COMPARISON_EXPR
                 | LOGIC_AND_EXPR 'and' COMPARISON_EXPR

COMPARISON_EXPR ::= ARITH_EXPR
                  | ARITH_EXPR ('==' | '!=' | '<' | '>' | '<=' | '>=') ARITH_EXPR

ARITH_EXPR ::= TERM
             | ARITH_EXPR ('+' | '-') TERM

TERM       ::= FACTOR
             | TERM ('*' | '/' | '%') FACTOR

FACTOR     ::= PRIMARY
             | 'not' FACTOR
             | '-' FACTOR                 (* Unary minus *)
             | FACTOR '(' EXPR ')'        (* Function Application *)

PRIMARY    ::= INT
             | FLOAT
             | STRING
             | BOOL
             | ID
             | '(' EXPR ')'
```

### Control Flow and Scoping (Expressions)

```
OPT_NL   ::= NL | ε                    (* Represents zero or one newline *)

IFEXPR   ::= 'if' EXPR OPT_NL 'then' EXPR OPT_NL 'else' EXPR

LETEXPR  ::= 'let' ID ':=' EXPR OPT_NL 'in' EXPR

LAMBDAEXPR ::= ('λ' | '\') ID OPT_NL '.' OPT_NL EXPR

BLOCKEXPR  ::= 'do' STMTLIST 'end'
             | '[' EXPRSEQ ']'
```


### Blocks (Lists of Expressions)

```
STMTLIST   ::= EXPR ';'
             | EXPR ';' STMTLIST

EXPRSEQ    ::= EXPR
             | EXPR ',' EXPRSEQ
```


### 1.3 Operator Precedence (Low to High)

1. Assignment (`:=`) - right associative
2. Logical OR (`or`) - left associative
3. Logical AND (`and`) - left associative
4. Comparison (`==`, `!=`, `<`, `>`, `<=`, `>=`) - non-associative
5. Addition/Subtraction (`+`, `-`) - left associative
6. Multiplication/Division/Modulo (`*`, `/`, `%`) - left associative
7. Unary operators (`not`, unary `-`) - right associative
8. Function application - left associative


## 2. Abstract Syntax Tree (AST)
### 2.1 Node Types

```
NodeType ::= NODE_VAL        -- Literal value
          |  NODE_VAR        -- Variable reference
          |  NODE_UNOP       -- Unary operation
          |  NODE_BINOP      -- Binary operation
          |  NODE_IF         -- Conditional expression
          |  NODE_LET        -- Local binding
          |  NODE_LAMBDA     -- Anonymous function
          |  NODE_CALL       -- Function application
          |  NODE_ASSIGN     -- Assignment
          |  NODE_CONST      -- Constant definition
          |  NODE_MVAR       -- Mutable variable definition
          |  NODE_SEQ        -- Sequence of expressions
```

### 2.2 AST Structure

```
ASTNode ::= ValNode(Value)
         |  VarNode(name: String)
         |  UnopNode(op: Operator, operand: ASTNode)
         |  BinopNode(op: Operator, left: ASTNode, right: ASTNode)
         |  IfNode(cond: ASTNode, then_expr: ASTNode, else_expr: ASTNode)
         |  LetNode(name: String, value: ASTNode, body: ASTNode)
         |  LambdaNode(param: String, param_type: String?, ret_type: String?, body: ASTNode)
         |  CallNode(fn: ASTNode, arg: ASTNode)
         |  AssignNode(name: String, value: ASTNode)
         |  ConstNode(name: String, type_name: String?, value: ASTNode)
         |  MVarNode(name: String, type_name: String?, value: ASTNode)
         |  SeqNode(exprs: List<ASTNode>)
```

### 2.3 Value Types

```
ValueType ::= VAL_INT      -- Integer
           |  VAL_FLOAT    -- Floating point
           |  VAL_BOOL     -- Boolean
           |  VAL_STRING   -- String
           |  VAL_FUNC     -- Function closure
           |  VAL_UNIT     -- Unit type (void)

Value ::= IntVal(ival: Integer)
       |  FloatVal(fval: Float)
       |  BoolVal(bval: Boolean)
       |  StringVal(sval: String)
       |  FuncVal(func: Function)
       |  UnitVal

Function ::= (param: String, param_type: String?, ret_type: String?,
              body: ASTNode, env: Environment)
```

## AST Nodes

**Node Types and Structure:**

 - `NODE_VAL`: A literal value.
   * `val`: A `Value` structure holding an integer, float, boolean, string, or function.

 - `NODE_VAR`: A variable reference.
   * `name`: `string` (the identifier name).

 - `NODE_UNOP`: A unary operation.
   * `op`: `token` (e.g., `T_MINUS`, `T_NOT`).
   * `operand`: `ASTNode*` (the expression to operate on).

 - `NODE_BINOP`: A binary operation.
   * `op`: `token` (e.g., `T_PLUS`, `T_EQ`).
   * `left`: `ASTNode*` (the left-hand side expression).
   * `right`: `ASTNode*` (the right-hand side expression).

 - `NODE_IF`: An if-then-else conditional.
   * `cond`: `ASTNode*` (the condition).
   * `then_expr`: `ASTNode*` (the "then" branch).
   * `else_expr`: `ASTNode*` (the "else" branch).

 - `NODE_LET`: A local, immutable binding.
   * `name`: `string` (the identifier being bound).
   * `value`: `ASTNode*` (the expression defining the value).
   * `body`: `ASTNode*` (the expression where the binding is visible).

 - `NODE_ASSIGN`: An assignment to an existing variable.
   * `name`: `string` (the identifier to update).
   * `value`: `ASTNode*` (the new value expression).

 - `NODE_CONST` / `NODE_MVAR`: A definition in the current scope.
   * `name`: `string` (the identifier to define).
   * `value`: `ASTNode*` (the value expression).

 - `NODE_LAMBDA`: An anonymous function (closure).
   * `param`: `string` (the parameter name).
   * `body`: `ASTNode*` (the function's body expression).

 - `NODE_CALL`: A function application.
   * `fn`: `ASTNode*` (the expression that evaluates to a function).
   * `arg`: `ASTNode*` (the argument expression).

 - `NODE_SEQ`: A sequence of expressions.
   * `elist`: `ExprList*` (a linked list of expressions to evaluate in order).

We define the evaluation rules using the judgment `E |- e ↓ v`, which reads: "In
environment `E`, expression `e` evaluates to value `v`".

The set of runtime values `v`
where `v ::= n (integer) | f (float) | b (boolean) | s (string) | <λx.e, E> (closure) | unit`

A closure `<λx.e, E>` is a pair containing a lambda AST and the lexical environment `E`.

Environments `E` are mappings from identifiers `x` to a constant or value. The
`eval` code implies a stateful environment for `const`/`mvar` definitions and
assignments. A simplified model is a mapping from identifiers to values with a
mutability flag: `E: id :--> (v, is_const)`.

Let `E |- e ↓ v` is written as `[[e]]E = v` in operational semantics and denotes
the evaluation of expression `e` in environment `E`.

### Literals (R1-4):

    1. `E |- n ↓ n` (int)
    2. `E |- f ↓ f` (float)
    3. `E |- b ↓ b` (bool)
    4. `E |- s ↓ s` (str)

### Variable Lookup (R5):

    ```
    E(x) = (v, is_const)
    --------------------
        E |- x ↓ v
    ```

### Unary Boolean Negation (R6):

    ```
    E |- e ↓ v
    v' = ¬v
    --------------- (for op = not)
    E |- not e ↓ v'
    ```

### Unary Numerical Negation (R7)

    ```
    E |- e ↓ v
    v' = -v
    --------------- (for op = -)
    E |- -e ↓ v'
    ```

### Infix Expressions / Binary Operations (R8):

    ```
    E |- e₁ ↓ v₁      E |- e₂ ↓ v₂
    v = v₁ (+) v₂
    ---------------------------------
        E |- e₁ op e₂ ↓ v
    ```

Where `(+)` is a meta-function representing the
operation logic in `eval_binop` [src/ml.y](src/ml.y)

 1. If `op` is `+`, `(+)` performs numeric
    addition or string concatenation based on types.

 2. If `op` is `*`, `/`, `-`, etc., `(+)` performs the
    corresponding arithmetic operation (with type promotion
    from int to float if necessary).

 3. If `op` is `==`, `<`, `and`, etc., `(+)` performs the
    corresponding comparison or logical operation.

### If true Expression (R9):

    ```
    E |- e_cond ↓ true     E |- e_then ↓ v
    ---------------------------------------
    E |- if e_cond then e_then else e_else ↓ v
    ```

### If false Expression (R10):

    ```
    E |- e_cond ↓ false    E |- e_else ↓ v
    ---------------------------------------
    E |- if e_cond then e_then else e_else ↓ v
    ```

### Lambda Expression (R11):
    ```
    ---------------------------------
    E |- λx.e ↓ <λx.e, E>
    ```

A lambda evaluates to a closure, capturing its
environment at evaluation / definition.

### Function Application (R12):

    ```
    E |- e_fn ↓ <λx.e_body, E_closure>      E |- e_arg ↓ v_arg
    E_closure[x |-> (v_arg, false)] |- e_body ↓ v_result
    ---------------------------------------------------------
            E |- e_fn(e_arg) ↓ v_result
    ```

This rule demonstrates lexical scoping: the function body (`e_body`) is
evaluated in the environment where the function was defined (`E_closure`),
extended with the argument binding `x |-> v_arg`.

### Let Expression (R13):

    ```
    E |- e_val ↓ v_val
    E[x |-> (v_val, true)] |- e_body ↓ v_body
    ------------------------------------------
    E |- let x := e_val in e_body ↓ v_body
    ```

`E[x |-> v]` denotes creating a new environment by extending
`E` with a binding for `x`. This binding is local to `e_body`.

### Sequence (R14):

    ```
    E |- e₁ ↓ v₁      E |- e₂ ↓ v₂   ...   E |- e_n ↓ v_n
    -----------------------------------------------------
    E |- {e₁, e₂, ..., e_n} ↓ v_n
    ```

The value of a sequence is the value of its final expression.

This assumes expressions have no side effects on
the environment `E`. For stateful definitions, see
below.

Stateful Semantics for Definitions and Assignments
--------------------------------------------------

To model the stateful nature of `const`, `mvar`, and assignment, the judgment
must be changed to `E |- e ↓ v, E'`, showing that evaluation produces a new
environment `E'`.

### Constant/Mutable Definition (R15):

    ```
    E |- e_val ↓ v, E'
    E'' = E'[x |-> (v, is_const)]
    -------------------------------------- (where is_const is true for `const`, false for `mvar`)
    E |- const x := e_val ↓ v, E''
    ```

The environment is modified by adding a new binding.

### Assignment (R16):

    ```
    E |- e_val ↓ v, E'
    E'' = update(E', x, v)
    -------------------------
    E |- x := e_val ↓ v, E''
    ```

The environment is modified by updating the value
associated with `x`. This rule would fail if `x` was
marked as a constant.





Operational Semantics
---------------------

### Literals

```
[[n]]E = n                           (integer literal)
[[f]]E = f                           (float literal)
[["s"]]E = s                         (string literal)
[[T]]E = true                        (boolean true)
[[F]]E = false                       (boolean false)
[[x]]E = E(x)                        (variable lookup)
```

Literals evaluate to their corresponding values.

### Unary Operations

```
[[not e]]p = ¬[[e]]p                  if [[e]]p : Bool
[[-e]]p = -[[e]]p                     if [[e]]p : Int ∪ Float
```

### Infix / Binary Operations

Arithmetic (for numeric types)
```
[[e₁ + e₂]]p = [[e₁]]p + [[e₂]]p       (also string concatenation)
[[e₁ - e₂]]p = [[e₁]]p - [[e₂]]p
[[e₁ * e₂]]p = [[e₁]]p × [[e₂]]p
[[e₁ / e₂]]p = [[e₁]]p ÷ [[e₂]]p       if [[e₂]]p ≠ 0
[[e₁ % e₂]]p = [[e₁]]p mod [[e₂]]p     if [[e₂]]p ≠ 0
```

Note that if one operand is FLOAT and the other is INT, promote INT to FLOAT.

### Comparison:

```
[[e₁ op e₂]]p = [[e₁]]p op [[e₂]]p     where op ∈ {==, !=, <, >, <=, >=}
```

### Logical (for Boolean types)

```
[[e₁ and e₂]]p = [[e₁]]p ∧ [[e₂]]p
[[e₁ or e₂]]p = [[e₁]]p ∨ [[e₂]]p
```

### Conditionals

```
[[if e₁ then e₂ else e₃]]p = {
    [[e₂]]p  if [[e₁]]p = true
    [[e₃]]p  if [[e₁]]p = false
}
```
If and only if `[[e₁]]p : Bool`

### Let Bindings

```
[[let x := e₁ in e₂]]p = [[e₂]]p'
    where v₁ = [[e₁]]p
          p' = p[x |-> v₁]
```

Creates a new local environment extending `p` with binding `x |-> v₁`.

### Lambda Expressions (Closures)

```
[[λx.e]]p = ⟨x, e, p⟩
```

Returns a function closure capturing parameter `x`, body `e`, and the current
environment `p`.

### Function Application

```
[[e₁(e₂)]]p = [[e]]p'
    where ⟨x, e, p_closure⟩ = [[e₁]]p
          v = [[e₂]]p
          p' = p_closure[x |-> v]
```

If and only if `[[e₁]]p` is a function value.

### Assignment

```
[[x := e]]p = v
    where v = [[e]]p
          p := p[x |-> v]    (side effect: update environment)
```

Requires: `x` must already exist in `p` and not be marked as constant.

### Definitions

Constant:
```
[[const x := e]]p = v
    where v = [[e]]p
          p := p[x |-> v, immutable]
```

Mutable variable:
```
[[var x := e]]p = v
    where v = [[e]]p
          p := p[x |-> v, mutable]
```

Sequences:

```
[[{e₁, e₂, ..., eₙ}]]p = [[eₙ]]pₙ
    where pᵢ = environment after evaluating eᵢ
```

Or (with semicolons):

```
[[do e₁; e₂; ...; eₙ; end]]p = [[eₙ]]pₙ
```

Evaluates each expression in sequence and returns the value of the last
expression.

Types
-----

The language uses dynamic typing with the following runtime types:

  - **Int**      : Integer numbers
  - **Float**    : Floating-point numbers
  - **Bool**     : Boolean values (`true`, `false`)
  - **String**   : Text strings
  - **Function** : First-class function closures `(param → body)`
  - **Unit**     : Void type (represents no value)

**Type checking** occurs during runtime when evaluation taks place, with errors
reported for type mismatches.

Environment Model
-----------------

```
Environment = Map<String, (Value, isConst: Bool)>
```

- Environments form a **chain** (lexical scoping)
- Variable lookup searches the chain from innermost to outermost scope
- Assignments update existing bindings (if mutable)
- Function closures **capture** their defining environment
