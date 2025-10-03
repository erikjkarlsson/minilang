/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 33 "calc.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h> /* For fmod in future, or other math functions */

/* Custom header files for data structures. */
#include "env.h"  /* Defines the environment for variable storage. */
#include "calc.h" // Defines ASTNode, Value, etc.


/* Forward declarations of helper functions defined in the C section below. */
ASTNode *make_node(NodeType t);
Value *make_int(int x);
Value *make_float(double x);
Value *make_bool(bool b);
Value *make_unit();
Value *make_string(const char *s);
Value *make_func(Function *f);

/* The core interpreter function. */
Value *eval(ASTNode *node, Env *env);

/* Memory management functions. */
void free_value(Value *v);
void free_ast(ASTNode *node);
void yylex_destroy();

/* Global environment to store top-level bindings. */
static Env *global_env = NULL;

/* --- String Macros for Output and Errors --- */

/* Display strings for different value types. */
#define STR_SHOW_TRUE   "true"
#define STR_SHOW_FALSE  "false"
#define STR_SHOW_INT    "=> %d\n"
#define STR_SHOW_FLOAT  "=> %.6g\n"
#define STR_SHOW_BOOL   "=> %s\n"
#define STR_SHOW_STRING "=> \"%s\"\n"
#define STR_SHOW_FUNC   "=> <function>\n"
#define STR_SHOW_UNIT   "\n" /* Unit type prints nothing. */

/* Error message strings. */
#define STR_ERR_NON_BOOL_NOT      "Line %d: Error: NOT requires a boolean operand\n"
#define STR_ERR_IF_NON_BOOL       "Line %d: Error: IF condition must be a boolean\n"
#define STR_NON_FUN_CALL          "Line %d: Error: Attempted to call a non-function value\n"
#define STR_BIN_OP_TYPE_ERR       "Line %d: Error: Type mismatch in binary operation\n"
#define STR_ERR_UNKNOWN_AST_TYPE  "Line %d: Error: Unknown AST node type\n"
#define STR_ERR_MALLOC_CONC       "Fatal: malloc failed in string concat\n"
#define STR_ERR_DIV_ZERO          "Line %d: Error: Division by zero\n"
#define STR_ERR_MOD_ZERO          "Line %d: Error: Modulo by zero\n"
#define STR_UNARY_MINUS           "Line %d: Error: Unary minus requires a numeric operand\n"
#define STR_CALLOC_FAIL           "Line %d: Fatal, calloc failed in make_node\n"
#define STR_PARSE_ERR             "Line %d: Parse error: %s\n"

/* General strings. */
#define STR_GOODBYE             "Goodbye!\n"
#define STR_FILE_LOAD_ERROR     "Error loading file %s"
#define BANNER                  "Type 'quit' or 'exit' to leave.\n\n"


#line 135 "calc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "calc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_ID = 3,                       /* T_ID  */
  YYSYMBOL_T_INT = 4,                      /* T_INT  */
  YYSYMBOL_T_FLOAT = 5,                    /* T_FLOAT  */
  YYSYMBOL_T_STR = 6,                      /* T_STR  */
  YYSYMBOL_T_SYM = 7,                      /* T_SYM  */
  YYSYMBOL_T_NAME = 8,                     /* T_NAME  */
  YYSYMBOL_T_PLUS = 9,                     /* T_PLUS  */
  YYSYMBOL_T_MINUS = 10,                   /* T_MINUS  */
  YYSYMBOL_T_MULTIPLY = 11,                /* T_MULTIPLY  */
  YYSYMBOL_T_DIVIDE = 12,                  /* T_DIVIDE  */
  YYSYMBOL_T_MOD = 13,                     /* T_MOD  */
  YYSYMBOL_T_LEFT = 14,                    /* T_LEFT  */
  YYSYMBOL_T_RIGHT = 15,                   /* T_RIGHT  */
  YYSYMBOL_T_BLEFT = 16,                   /* T_BLEFT  */
  YYSYMBOL_T_BRIGHT = 17,                  /* T_BRIGHT  */
  YYSYMBOL_T_TRUE = 18,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 19,                   /* T_FALSE  */
  YYSYMBOL_T_IF = 20,                      /* T_IF  */
  YYSYMBOL_T_THEN = 21,                    /* T_THEN  */
  YYSYMBOL_T_ELSE = 22,                    /* T_ELSE  */
  YYSYMBOL_T_LET = 23,                     /* T_LET  */
  YYSYMBOL_T_IN = 24,                      /* T_IN  */
  YYSYMBOL_T_SET = 25,                     /* T_SET  */
  YYSYMBOL_T_FUN = 26,                     /* T_FUN  */
  YYSYMBOL_T_ARROW = 27,                   /* T_ARROW  */
  YYSYMBOL_T_TYPE = 28,                    /* T_TYPE  */
  YYSYMBOL_T_COLON = 29,                   /* T_COLON  */
  YYSYMBOL_T_AND = 30,                     /* T_AND  */
  YYSYMBOL_T_OR = 31,                      /* T_OR  */
  YYSYMBOL_T_NOT = 32,                     /* T_NOT  */
  YYSYMBOL_T_EQ = 33,                      /* T_EQ  */
  YYSYMBOL_T_NEQ = 34,                     /* T_NEQ  */
  YYSYMBOL_T_LT = 35,                      /* T_LT  */
  YYSYMBOL_T_GT = 36,                      /* T_GT  */
  YYSYMBOL_T_LTE = 37,                     /* T_LTE  */
  YYSYMBOL_T_GTE = 38,                     /* T_GTE  */
  YYSYMBOL_T_CONST = 39,                   /* T_CONST  */
  YYSYMBOL_T_DO = 40,                      /* T_DO  */
  YYSYMBOL_T_END = 41,                     /* T_END  */
  YYSYMBOL_T_SEMICOLON = 42,               /* T_SEMICOLON  */
  YYSYMBOL_T_COMMA = 43,                   /* T_COMMA  */
  YYSYMBOL_T_NEWLINE = 44,                 /* T_NEWLINE  */
  YYSYMBOL_T_QUIT = 45,                    /* T_QUIT  */
  YYSYMBOL_T_LAMBDA = 46,                  /* T_LAMBDA  */
  YYSYMBOL_UMINUS = 47,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_expr = 51,                      /* expr  */
  YYSYMBOL_term = 52,                      /* term  */
  YYSYMBOL_factor = 53,                    /* factor  */
  YYSYMBOL_primary = 54,                   /* primary  */
  YYSYMBOL_if_expr = 55,                   /* if_expr  */
  YYSYMBOL_let_expr = 56,                  /* let_expr  */
  YYSYMBOL_lambda_expr = 57,               /* lambda_expr  */
  YYSYMBOL_block_expr = 58,                /* block_expr  */
  YYSYMBOL_assignment = 59,                /* assignment  */
  YYSYMBOL_const_def = 60,                 /* const_def  */
  YYSYMBOL_stmt_list = 61,                 /* stmt_list  */
  YYSYMBOL_expr_seq = 62                   /* expr_seq  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   182,   182,   185,   219,   220,   221,   222,   223,   224,
     237,   238,   239,   240,   241,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   259,   260,   261,   262,   269,
     270,   272,   274,   285,   286,   287,   288,   289,   290,   291,
     298,   310,   322,   339,   343,   351,   361,   368,   378,   382,
     390,   394
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_ID", "T_INT",
  "T_FLOAT", "T_STR", "T_SYM", "T_NAME", "T_PLUS", "T_MINUS", "T_MULTIPLY",
  "T_DIVIDE", "T_MOD", "T_LEFT", "T_RIGHT", "T_BLEFT", "T_BRIGHT",
  "T_TRUE", "T_FALSE", "T_IF", "T_THEN", "T_ELSE", "T_LET", "T_IN",
  "T_SET", "T_FUN", "T_ARROW", "T_TYPE", "T_COLON", "T_AND", "T_OR",
  "T_NOT", "T_EQ", "T_NEQ", "T_LT", "T_GT", "T_LTE", "T_GTE", "T_CONST",
  "T_DO", "T_END", "T_SEMICOLON", "T_COMMA", "T_NEWLINE", "T_QUIT",
  "T_LAMBDA", "UMINUS", "$accept", "program", "statement", "expr", "term",
  "factor", "primary", "if_expr", "let_expr", "lambda_expr", "block_expr",
  "assignment", "const_def", "stmt_list", "expr_seq", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -43,    69,   -43,   -43,   -43,   -43,   -24,   321,   112,   112,
     -43,   -43,   112,     9,   321,    10,   112,   -43,   -26,    13,
     -43,   129,    -3,     7,   -43,   -43,   -43,   -43,   -43,   -22,
     -21,   112,   -43,     7,     4,   144,     8,   189,     1,     7,
     -23,   159,   -17,   -43,     0,   321,   321,   112,   112,   112,
     112,   112,   112,   112,   112,   -43,   -43,   321,   321,   321,
     112,   -43,   -43,   247,   -43,   112,   -43,   112,   112,   112,
      21,   112,   -43,   112,    -3,    -3,   278,   256,   286,   286,
     286,   286,   286,   286,     7,     7,     7,   198,   -43,   208,
     238,   247,     6,   -43,   247,   -43,   112,   112,   112,   247,
     247,   247
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    33,    34,    37,    38,     0,     0,     0,
      35,    36,     0,     0,     0,     0,     0,     4,     0,     0,
       3,     0,    10,    25,    29,    11,    12,    13,    14,     0,
       0,     0,    38,    31,     0,    50,     0,     0,     0,    30,
       0,     0,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     5,     0,     0,     0,
       0,     7,     8,    45,    39,     0,    44,     0,     0,     0,
       0,    48,    43,     0,    23,    24,    16,    15,    17,    18,
      19,    20,    21,    22,    26,    27,    28,     0,    51,     0,
       0,    47,     0,    49,    42,    32,     0,     0,     0,    40,
      41,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   -43,    -1,   -42,    -2,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -39,   -36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    20,    35,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    42,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      21,    31,    69,    74,    75,    33,    70,    34,    57,    58,
      59,    37,    39,    45,    46,    41,    38,    40,    43,    64,
      44,    60,    61,    62,    72,    66,    68,    73,    92,    88,
      63,    98,    93,     0,    47,    48,     0,    49,    50,    51,
      52,    53,    54,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,     0,    84,    85,    86,     0,    87,
       0,     0,     0,     0,     0,     0,    89,    90,    91,     2,
      41,     0,    94,     3,     4,     5,     6,     0,     0,     7,
       0,     0,     0,     8,     0,     9,     0,    10,    11,    12,
       0,     0,    13,     0,     0,    99,   100,   101,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,    15,    16,
       0,     0,     0,    17,    18,    19,     3,     4,     5,    32,
       0,     0,     7,     0,     0,     0,     8,     0,     9,     0,
      10,    11,    12,     0,     0,    13,     0,     0,    45,    46,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
       0,     0,    16,    45,    46,     0,     0,     0,    19,    47,
      48,     0,    49,    50,    51,    52,    53,    54,    45,    46,
       0,    55,     0,    56,    47,    48,     0,    49,    50,    51,
      52,    53,    54,     0,     0,     0,     0,    65,     0,    47,
      48,     0,    49,    50,    51,    52,    53,    54,    45,    46,
       0,    71,     0,     0,     0,     0,     0,    45,    46,     0,
      67,     0,     0,    95,     0,     0,     0,    45,    46,    47,
      48,     0,    49,    50,    51,    52,    53,    54,    47,    48,
      96,    49,    50,    51,    52,    53,    54,     0,    47,    48,
       0,    49,    50,    51,    52,    53,    54,    45,    46,     0,
       0,     0,     0,     0,     0,     0,    45,    46,     0,     0,
       0,     0,    97,     0,     0,    45,    46,     0,    47,    48,
       0,    49,    50,    51,    52,    53,    54,    47,    48,     0,
      49,    50,    51,    52,    53,    54,    47,    45,    46,    49,
      50,    51,    52,    53,    54,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    50,    51,    52,    53,    54,     0,     0,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    32,     0,
       0,     7,     0,     0,     0,     8,     0,     0,     0,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14
};

static const yytype_int8 yycheck[] =
{
       1,    25,    25,    45,    46,     7,    29,     8,    11,    12,
      13,    12,    14,     9,    10,    16,     7,     7,    44,    15,
       7,    14,    44,    44,    41,    17,    25,    27,     7,    65,
      31,    25,    71,    -1,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    57,    58,    59,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,     0,
      71,    -1,    73,     4,     5,     6,     7,    -1,    -1,    10,
      -1,    -1,    -1,    14,    -1,    16,    -1,    18,    19,    20,
      -1,    -1,    23,    -1,    -1,    96,    97,    98,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    44,    45,    46,     4,     5,     6,     7,
      -1,    -1,    10,    -1,    -1,    -1,    14,    -1,    16,    -1,
      18,    19,    20,    -1,    -1,    23,    -1,    -1,     9,    10,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,     9,    10,    -1,    -1,    -1,    46,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,     9,    10,
      -1,    42,    -1,    44,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,     9,    10,
      -1,    42,    -1,    -1,    -1,    -1,    -1,     9,    10,    -1,
      21,    -1,    -1,    15,    -1,    -1,    -1,     9,    10,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    30,    31,
      22,    33,    34,    35,    36,    37,    38,    -1,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    -1,    -1,
      -1,    -1,    24,    -1,    -1,     9,    10,    -1,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    30,     9,    10,    33,
      34,    35,    36,    37,    38,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    -1,    -1,    33,
      34,    35,    36,    37,    38,     4,     5,     6,     7,    -1,
      -1,    10,    -1,    -1,    -1,    14,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,     0,     4,     5,     6,     7,    10,    14,    16,
      18,    19,    20,    23,    32,    39,    40,    44,    45,    46,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    25,     7,    53,    51,    51,    62,    51,     7,    53,
       7,    51,    61,    44,     7,     9,    10,    30,    31,    33,
      34,    35,    36,    37,    38,    42,    44,    11,    12,    13,
      14,    44,    44,    51,    15,    43,    17,    21,    25,    25,
      29,    42,    41,    27,    52,    52,    51,    51,    51,    51,
      51,    51,    51,    51,    53,    53,    53,    51,    62,    51,
      51,    51,     7,    61,    51,    15,    22,    24,    25,    51,
      51,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    53,
      53,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      55,    56,    57,    58,    58,    59,    60,    60,    61,    61,
      62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     3,
       6,     6,     4,     3,     3,     3,     6,     4,     2,     3,
       1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_T_ID: /* T_ID  */
#line 157 "calc.y"
            { free(((*yyvaluep).id)); }
#line 1040 "calc.tab.c"
        break;

    case YYSYMBOL_T_STR: /* T_STR  */
#line 157 "calc.y"
            { free(((*yyvaluep).sval)); }
#line 1046 "calc.tab.c"
        break;

    case YYSYMBOL_T_SYM: /* T_SYM  */
#line 157 "calc.y"
            { free(((*yyvaluep).name)); }
#line 1052 "calc.tab.c"
        break;

    case YYSYMBOL_T_NAME: /* T_NAME  */
#line 157 "calc.y"
            { free(((*yyvaluep).name)); }
#line 1058 "calc.tab.c"
        break;

    case YYSYMBOL_program: /* program  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1064 "calc.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1070 "calc.tab.c"
        break;

    case YYSYMBOL_expr: /* expr  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1076 "calc.tab.c"
        break;

    case YYSYMBOL_term: /* term  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1082 "calc.tab.c"
        break;

    case YYSYMBOL_factor: /* factor  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1088 "calc.tab.c"
        break;

    case YYSYMBOL_primary: /* primary  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1094 "calc.tab.c"
        break;

    case YYSYMBOL_if_expr: /* if_expr  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1100 "calc.tab.c"
        break;

    case YYSYMBOL_let_expr: /* let_expr  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1106 "calc.tab.c"
        break;

    case YYSYMBOL_lambda_expr: /* lambda_expr  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1112 "calc.tab.c"
        break;

    case YYSYMBOL_block_expr: /* block_expr  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1118 "calc.tab.c"
        break;

    case YYSYMBOL_assignment: /* assignment  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1124 "calc.tab.c"
        break;

    case YYSYMBOL_const_def: /* const_def  */
#line 158 "calc.y"
            { free_ast(((*yyvaluep).node)); }
#line 1130 "calc.tab.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: %empty  */
#line 182 "calc.y"
                            { (yyval.node) = NULL; }
#line 1400 "calc.tab.c"
    break;

  case 3: /* program: program statement  */
#line 185 "calc.y"
                            {
          /* If the statement produced an AST ($2 is not NULL)... */
        if ((yyvsp[0].node)) {
            /* Evaluate the AST in the global environment. */
            Value *v = eval((yyvsp[0].node), global_env);

            /* If evaluation produced a result... */
            if (v) {
                /* Print the result based on its type. */
                switch(v->type) {
                    case VAL_INT:    printf(STR_SHOW_INT, v->ival); break;
                    case VAL_FLOAT:  printf(STR_SHOW_FLOAT, v->fval); break;
                    case VAL_BOOL:
                        printf(STR_SHOW_BOOL,
                               v->bval ? STR_SHOW_TRUE : STR_SHOW_FALSE);
                        break;
                    case VAL_STRING: printf(STR_SHOW_STRING, v->sval); break;
                    case VAL_FUNC:   printf(STR_SHOW_FUNC); break;
                    case VAL_UNIT:   /* Print nothing for unit type */ break;
                }
                /* Free the resulting value from the evaluation. */
                free_value(v);
            }
            /* Free the AST for the statement now that we're done with it. */
            free_ast((yyvsp[0].node));
        }
    }
#line 1432 "calc.tab.c"
    break;

  case 4: /* statement: T_NEWLINE  */
#line 219 "calc.y"
                            { (yyval.node) = NULL; }
#line 1438 "calc.tab.c"
    break;

  case 5: /* statement: expr T_NEWLINE  */
#line 220 "calc.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1444 "calc.tab.c"
    break;

  case 6: /* statement: expr T_SEMICOLON  */
#line 221 "calc.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1450 "calc.tab.c"
    break;

  case 7: /* statement: assignment T_NEWLINE  */
#line 222 "calc.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1456 "calc.tab.c"
    break;

  case 8: /* statement: const_def T_NEWLINE  */
#line 223 "calc.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1462 "calc.tab.c"
    break;

  case 9: /* statement: T_QUIT T_NEWLINE  */
#line 224 "calc.y"
                            {
        printf(STR_GOODBYE);
        free_env(global_env, true); /* Free the global environment. */
        yylex_destroy();            /* Clean up the lexer. */
        exit(0);
    }
#line 1473 "calc.tab.c"
    break;

  case 15: /* expr: expr T_OR expr  */
#line 243 "calc.y"
                            { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_OR; }
#line 1479 "calc.tab.c"
    break;

  case 16: /* expr: expr T_AND expr  */
#line 244 "calc.y"
                            { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_AND; }
#line 1485 "calc.tab.c"
    break;

  case 17: /* expr: expr T_EQ expr  */
#line 245 "calc.y"
                            { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_EQ; }
#line 1491 "calc.tab.c"
    break;

  case 18: /* expr: expr T_NEQ expr  */
#line 246 "calc.y"
                            { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_NEQ; }
#line 1497 "calc.tab.c"
    break;

  case 19: /* expr: expr T_LT expr  */
#line 247 "calc.y"
                            { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_LT; }
#line 1503 "calc.tab.c"
    break;

  case 20: /* expr: expr T_GT expr  */
#line 248 "calc.y"
                            { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_GT; }
#line 1509 "calc.tab.c"
    break;

  case 21: /* expr: expr T_LTE expr  */
#line 249 "calc.y"
                            { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_LTE; }
#line 1515 "calc.tab.c"
    break;

  case 22: /* expr: expr T_GTE expr  */
#line 250 "calc.y"
                            { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_GTE; }
#line 1521 "calc.tab.c"
    break;

  case 23: /* expr: expr T_PLUS term  */
#line 251 "calc.y"
                            { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_PLUS; }
#line 1527 "calc.tab.c"
    break;

  case 24: /* expr: expr T_MINUS term  */
#line 252 "calc.y"
                            { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_MINUS; }
#line 1533 "calc.tab.c"
    break;

  case 26: /* term: term T_MULTIPLY factor  */
#line 260 "calc.y"
                             { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_MULTIPLY; }
#line 1539 "calc.tab.c"
    break;

  case 27: /* term: term T_DIVIDE factor  */
#line 261 "calc.y"
                             { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_DIVIDE; }
#line 1545 "calc.tab.c"
    break;

  case 28: /* term: term T_MOD factor  */
#line 262 "calc.y"
                             { (yyval.node) = make_node(NODE_BINOP); (yyval.node)->binop.left=(yyvsp[-2].node); (yyval.node)->binop.right=(yyvsp[0].node); (yyval.node)->binop.op=T_MOD; }
#line 1551 "calc.tab.c"
    break;

  case 30: /* factor: T_NOT factor  */
#line 270 "calc.y"
                             { (yyval.node) = make_node(NODE_UNOP); (yyval.node)->unop.operand=(yyvsp[0].node); (yyval.node)->unop.op=T_NOT; }
#line 1557 "calc.tab.c"
    break;

  case 31: /* factor: T_MINUS factor  */
#line 272 "calc.y"
                                  { (yyval.node) = make_node(NODE_UNOP); (yyval.node)->unop.operand=(yyvsp[0].node); (yyval.node)->unop.op=T_MINUS; }
#line 1563 "calc.tab.c"
    break;

  case 32: /* factor: factor T_LEFT expr T_RIGHT  */
#line 274 "calc.y"
                                 {
        (yyval.node) = make_node(NODE_CALL);
        (yyval.node)->call.fn = (yyvsp[-3].node);
        (yyval.node)->call.arg = (yyvsp[-1].node);
    }
#line 1573 "calc.tab.c"
    break;

  case 33: /* primary: T_INT  */
#line 285 "calc.y"
                              { (yyval.node) = make_node(NODE_VAL); (yyval.node)->val = make_int((yyvsp[0].ival)); }
#line 1579 "calc.tab.c"
    break;

  case 34: /* primary: T_FLOAT  */
#line 286 "calc.y"
                              { (yyval.node) = make_node(NODE_VAL); (yyval.node)->val = make_float((yyvsp[0].fval)); }
#line 1585 "calc.tab.c"
    break;

  case 35: /* primary: T_TRUE  */
#line 287 "calc.y"
                              { (yyval.node) = make_node(NODE_VAL); (yyval.node)->val = make_bool(true); }
#line 1591 "calc.tab.c"
    break;

  case 36: /* primary: T_FALSE  */
#line 288 "calc.y"
                              { (yyval.node) = make_node(NODE_VAL); (yyval.node)->val = make_bool(false); }
#line 1597 "calc.tab.c"
    break;

  case 37: /* primary: T_STR  */
#line 289 "calc.y"
                              { (yyval.node) = make_node(NODE_VAL); (yyval.node)->val = make_string((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1603 "calc.tab.c"
    break;

  case 38: /* primary: T_SYM  */
#line 290 "calc.y"
                              { (yyval.node) = make_node(NODE_VAR); (yyval.node)->var = (yyvsp[0].name); }
#line 1609 "calc.tab.c"
    break;

  case 39: /* primary: T_LEFT expr T_RIGHT  */
#line 291 "calc.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 1615 "calc.tab.c"
    break;

  case 40: /* if_expr: T_IF expr T_THEN expr T_ELSE expr  */
#line 298 "calc.y"
                                      {
        (yyval.node) = make_node(NODE_IF);
        (yyval.node)->ifexpr.cond = (yyvsp[-4].node);
        (yyval.node)->ifexpr.then_expr = (yyvsp[-2].node);
        (yyval.node)->ifexpr.else_expr = (yyvsp[0].node);
    }
#line 1626 "calc.tab.c"
    break;

  case 41: /* let_expr: T_LET T_SYM T_SET expr T_IN expr  */
#line 310 "calc.y"
                                     {
        (yyval.node) = make_node(NODE_LET);
        (yyval.node)->let.name = (yyvsp[-4].name);
        (yyval.node)->let.value = (yyvsp[-2].node);
        (yyval.node)->let.body = (yyvsp[0].node);
    }
#line 1637 "calc.tab.c"
    break;

  case 42: /* lambda_expr: T_LAMBDA T_SYM T_ARROW expr  */
#line 322 "calc.y"
                                {
        (yyval.node) = make_node(NODE_LAMBDA);
        (yyval.node)->lambda.param = (yyvsp[-2].name);
        (yyval.node)->lambda.param_type = NULL; /* Type annotations are optional */
        (yyval.node)->lambda.ret_type = NULL;
        (yyval.node)->lambda.body = (yyvsp[0].node);
    }
#line 1649 "calc.tab.c"
    break;

  case 43: /* block_expr: T_DO stmt_list T_END  */
#line 339 "calc.y"
                         {
        (yyval.node) = make_node(NODE_SEQ);
        (yyval.node)->seq.elist = (yyvsp[-1].elist);
    }
#line 1658 "calc.tab.c"
    break;

  case 44: /* block_expr: T_BLEFT expr_seq T_BRIGHT  */
#line 343 "calc.y"
                                {
        (yyval.node) = make_node(NODE_SEQ);
        (yyval.node)->seq.elist = (yyvsp[-1].elist);
    }
#line 1667 "calc.tab.c"
    break;

  case 45: /* assignment: T_SYM T_SET expr  */
#line 351 "calc.y"
                     {
        (yyval.node) = make_node(NODE_ASSIGN);
        (yyval.node)->assign.name = (yyvsp[-2].name);
        (yyval.node)->assign.value = (yyvsp[0].node);
    }
#line 1677 "calc.tab.c"
    break;

  case 46: /* const_def: T_CONST T_SYM T_COLON T_SYM T_SET expr  */
#line 361 "calc.y"
                                           {
        (yyval.node) = make_node(NODE_CONST);
        (yyval.node)->cdef.name = (yyvsp[-4].name);
        (yyval.node)->cdef.type_name = (yyvsp[-2].name);
        (yyval.node)->cdef.value = (yyvsp[0].node);
    }
#line 1688 "calc.tab.c"
    break;

  case 47: /* const_def: T_CONST T_SYM T_SET expr  */
#line 368 "calc.y"
                               {
        (yyval.node) = make_node(NODE_CONST);
        (yyval.node)->cdef.name = (yyvsp[-2].name);
        (yyval.node)->cdef.type_name = NULL;
        (yyval.node)->cdef.value = (yyvsp[0].node);
    }
#line 1699 "calc.tab.c"
    break;

  case 48: /* stmt_list: expr T_SEMICOLON  */
#line 378 "calc.y"
                     {
        ExprList *e = malloc(sizeof(ExprList));
        e->expr = (yyvsp[-1].node); e->next = NULL; (yyval.elist) = e;
    }
#line 1708 "calc.tab.c"
    break;

  case 49: /* stmt_list: expr T_SEMICOLON stmt_list  */
#line 382 "calc.y"
                                 {
        ExprList *e = malloc(sizeof(ExprList));
        e->expr = (yyvsp[-2].node); e->next = (yyvsp[0].elist); (yyval.elist) = e;
    }
#line 1717 "calc.tab.c"
    break;

  case 50: /* expr_seq: expr  */
#line 390 "calc.y"
         {
        ExprList *e = malloc(sizeof(ExprList));
        e->expr = (yyvsp[0].node); e->next = NULL; (yyval.elist) = e;
    }
#line 1726 "calc.tab.c"
    break;

  case 51: /* expr_seq: expr T_COMMA expr_seq  */
#line 394 "calc.y"
                            {
        ExprList *e = malloc(sizeof(ExprList));
        e->expr = (yyvsp[-2].node); e->next = (yyvsp[0].elist); (yyval.elist) = e;
    }
#line 1735 "calc.tab.c"
    break;


#line 1739 "calc.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 400 "calc.y"


/*
 * ============================================================================
 * C CODE SECTION
 * ============================================================================
 * This section contains the implementation of the interpreter, helper
 * functions for building the AST and Values, and memory management routines.
 * ============================================================================
 */


/*
 * ----------------------------------------------------------------------------
 * HELPER FUNCTIONS
 * ----------------------------------------------------------------------------
 */

/**
 * @brief Creates a new ASTNode of a given type.
 * @param t The NodeType for the new node.
 * @return A pointer to the newly allocated and initialized ASTNode.
 */
ASTNode *make_node(NodeType t)
{
    ASTNode *n = calloc(1, sizeof(ASTNode));
    if (!n) {
        fprintf(stderr, STR_CALLOC_FAIL, yylineno);
        exit(EXIT_FAILURE);
    }
    n->type = t;
    n->lineno = yylineno; // Store the line number for error reporting.
    return n;
}


/*
 * ----------------------------------------------------------------------------
 * VALUE CONSTRUCTORS
 * ----------------------------------------------------------------------------
 * These functions create `Value` structs for the interpreter. They handle
 * memory allocation and initialization for different data types.
 */

Value *make_int(int x) {
    Value *v = malloc(sizeof(Value));
    v->type = VAL_INT;
    v->ival = x;
    return v;
}

Value *make_float(double x) {
    Value *v = malloc(sizeof(Value));
    v->type = VAL_FLOAT;
    v->fval = x;
    return v;
}

Value *make_bool(bool b) {
    Value *v = malloc(sizeof(Value));
    v->type = VAL_BOOL;
    v->bval = b;
    return v;
}

Value *make_unit() {
    Value *v = malloc(sizeof(Value));
    v->type = VAL_UNIT;
    return v;
}

Value *make_string(const char *s) {
    Value *v = malloc(sizeof(Value));
    v->type = VAL_STRING;
    v->sval = strdup(s); /* Use strdup for safety. */
    return v;
}

Value *make_func(Function *f) {
    Value *v = malloc(sizeof(Value));
    v->type = VAL_FUNC;
    v->func = f;
    return v;
}

/*
 * ----------------------------------------------------------------------------
 * INTERPRETER / EVALUATOR
 * ----------------------------------------------------------------------------
 */

/* Forward declaration for the binary operation helper. */
Value *eval_binop(ASTNode *node, Env *env, Value *l, Value *r);

/**
 * @brief Recursively evaluates an ASTNode in a given environment.
 *
 * This function is the core of the interpreter. It traverses the AST
 * post-order and computes a `Value` for each node.
 *
 * @param node The ASTNode to evaluate.
 * @param env The environment (scope) in which to evaluate the node.
 * @return A pointer to a new `Value` struct representing the result.
 * The caller is responsible for freeing this value.
 */
Value *eval(ASTNode *node, Env *env) {
    if (!node) return make_unit();

    switch(node->type) {
        case NODE_VAL:
            /* A value node simply returns a copy of its stored value. */
            return dup_value(node->val);

        case NODE_VAR:
            /* Look up the variable's value in the current environment. */
            return env_get(env, node->var);

        case NODE_UNOP: {
            Value *v = eval(node->unop.operand, env);
            if (!v) return make_unit();

            Value *retval = NULL;
            if (node->unop.op == T_NOT) {
                if (v->type == VAL_BOOL) {
                    retval = make_bool(!v->bval);
                } else {
                    fprintf(stderr, STR_ERR_NON_BOOL_NOT, node->lineno);
                    retval = make_unit();
                }
            } else if (node->unop.op == T_MINUS) { /* Unary minus */
                if (v->type == VAL_INT) {
                    retval = make_int(-v->ival);
                } else if (v->type == VAL_FLOAT) {
                    retval = make_float(-v->fval);
                } else {
                    fprintf(stderr, STR_UNARY_MINUS, node->lineno);
                    retval = make_unit();
                }
            }
            free_value(v);
            return retval;
        }

        case NODE_BINOP: {
            Value *l = eval(node->binop.left, env);
            Value *r = eval(node->binop.right, env);
            Value *res = eval_binop(node, env, l, r);
            free_value(l);
            free_value(r);
            return res;
        }

        case NODE_IF: {
            Value *c = eval(node->ifexpr.cond, env);
            if (!c) return make_unit();

            if (c->type != VAL_BOOL) {
                fprintf(stderr, STR_ERR_IF_NON_BOOL, node->lineno);
                free_value(c);
                return make_unit();
            }

            bool is_true = c->bval;
            free_value(c);

            /* Evaluate either the 'then' or 'else' branch. */
            return eval(is_true ? node->ifexpr.then_expr : node->ifexpr.else_expr, env);
        }

  case NODE_LET: {
            /* Evaluate the value to be bound. */
            Value *v = eval(node->let.value, env);
            if (!v) return make_unit();

            /* Create a new, nested environment. */
            Env *local = new_env(env);
            env_set(local, node->let.name, v, false); /* Add the new binding. */

            /* Evaluate the body of the 'let' in the new environment. */
            Value *retval = eval(node->let.body, local);

            /* The local environment now owns 'v', so we don't free 'v' here. */
            // free_env(local, false); // OLD: Simple free
            env_release(local);       // <-- MODIFIED: Use release instead of free
            return retval;
        }
        case NODE_ASSIGN: {
            Value *v = eval(node->assign.value, env);
            if (!v) return make_unit();

            /* Update the variable in the environment. */
            env_update(env, node->assign.name, v);
            /* Assignment expression evaluates to the assigned value. */
            return dup_value(v);
        }

        case NODE_CONST: {
            Value *val = eval(node->cdef.value, env);
            if (!val) return make_unit();

            env_set(env, node->cdef.name, val, true); /* Set as constant. */
            return dup_value(val);
        }

    case NODE_LAMBDA: {
            /* Create a function closure. */
            Function *f = malloc(sizeof(Function));
            f->param = strdup(node->lambda.param);
            f->param_type = node->lambda.param_type ? strdup(node->lambda.param_type) : NULL;
            f->ret_type = node->lambda.ret_type ? strdup(node->lambda.ret_type) : NULL;
            f->body = node->lambda.body;
            /* IMPORTANT: Capture the current environment. This is the closure. */
            f->env = env;
            env_retain(env); // <-- ADDED: Retain a reference to the captured environment!
            return make_func(f);
        }
  case NODE_CALL: {
            /* Evaluate the function expression itself. */
            Value *fn_val = eval(node->call.fn, env);
            if (!fn_val) return make_unit();

            if (fn_val->type != VAL_FUNC) {
                fprintf(stderr, STR_NON_FUN_CALL, node->lineno);
                free_value(fn_val);
                return make_unit();
            }

            /* Evaluate the argument. */
            Value *arg_val = eval(node->call.arg, env);
            if (!arg_val) {
                free_value(fn_val);
                return make_unit();
            }

            /* Create a new environment for the function call, chained to the function's closure environment. */
            Env *local = new_env(fn_val->func->env);
            env_set(local, fn_val->func->param, arg_val, false);

            /* Evaluate the function body in this new environment. */
            Value *res = eval(fn_val->func->body, local);

            free_value(fn_val);
            /* arg_val is now owned by the local environment and freed by free_env. */
            // free_env(local, false); // OLD: Simple free
            env_release(local);        // <-- MODIFIED: Use release instead of free
            return res;
        }

        case NODE_SEQ: {
            Value *last = make_unit();
            /* Evaluate each expression in the sequence. */
            for (ExprList *it = node->seq.elist; it; it = it->next) {
                free_value(last); /* Free result of the previous expression. */
                last = eval(it->expr, env);
                if (!last) last = make_unit(); /* Ensure 'last' is never NULL. */
            }
            /* The value of the sequence is the value of the last expression. */
            return last;
        }

        default:
            fprintf(stderr, STR_ERR_UNKNOWN_AST_TYPE, node->lineno);
            return make_unit();
    }
}

/**
 * @brief Helper function to evaluate binary operations.
 *
 * It handles type checking, promotion (int to float), and performing the
 * actual operation for numeric, boolean, and string types.
 *
 * @param node The NODE_BINOP AST node.
 * @param env The current environment.
 * @param l The evaluated left-hand side value.
 * @param r The evaluated right-hand side value.
 * @return A new Value holding the result of the operation.
 */
Value *eval_binop(ASTNode *node, Env *env, Value *l, Value *r)
{
    if (!l || !r) {
        fprintf(stderr, STR_BIN_OP_TYPE_ERR, node->lineno);
        return make_unit();
    }

    /* Check operand types. */
    bool left_is_number = l->type == VAL_INT || l->type == VAL_FLOAT;
    bool right_is_number = r->type == VAL_INT || r->type == VAL_FLOAT;
    bool lr_is_string = l->type == VAL_STRING && r->type == VAL_STRING;

    /* --- String Concatenation --- */
    if (node->binop.op == T_PLUS && lr_is_string) {
        size_t len_l = strlen(l->sval);
        size_t len_r = strlen(r->sval);
        char* new_s = malloc(len_l + len_r + 1);
        if (!new_s) {
            fprintf(stderr, STR_ERR_MALLOC_CONC);
            exit(EXIT_FAILURE);
        }
        memcpy(new_s, l->sval, len_l);
        memcpy(new_s + len_l, r->sval, len_r + 1);
        Value *result = make_string(new_s);
        free(new_s);
        return result;
    }

    /* --- Numeric Operations --- */
    else if (left_is_number && right_is_number) {
        /* Promote to float if either operand is a float. */
        bool is_float = l->type == VAL_FLOAT || r->type == VAL_FLOAT;
        double lf = (l->type == VAL_FLOAT) ? l->fval : (double)l->ival;
        double rf = (r->type == VAL_FLOAT) ? r->fval : (double)r->ival;

        switch (node->binop.op) {
            case T_PLUS:     return is_float ? make_float(lf + rf) : make_int((int)(lf + rf));
            case T_MINUS:    return is_float ? make_float(lf - rf) : make_int((int)(lf - rf));
            case T_MULTIPLY: return is_float ? make_float(lf * rf) : make_int((int)(lf * rf));
            case T_DIVIDE:
                if (rf == 0.0) {
                    fprintf(stderr, STR_ERR_DIV_ZERO, node->lineno);
                    return make_unit();
                }
                /* Division of two ints might produce a float, so we always promote. */
                if (!is_float && (l->ival % r->ival != 0)) {
                    return make_float(lf / rf);
                }
                return is_float ? make_float(lf / rf) : make_int((int)(lf / rf));
            case T_MOD:
                if (rf == 0.0) {
                    fprintf(stderr, STR_ERR_MOD_ZERO, node->lineno);
                    return make_unit();
                }
                /* Modulo is defined for integers. */
                return make_int((int)lf % (int)rf);
            case T_EQ:  return make_bool(lf == rf);
            case T_NEQ: return make_bool(lf != rf);
            case T_LT:  return make_bool(lf < rf);
            case T_GT:  return make_bool(lf > rf);
            case T_LTE: return make_bool(lf <= rf);
            case T_GTE: return make_bool(lf >= rf);
        }
    }

    /* --- Boolean Operations --- */
    else if (l->type == VAL_BOOL && r->type == VAL_BOOL) {
        switch(node->binop.op) {
            case T_AND: return make_bool(l->bval && r->bval);
            case T_OR:  return make_bool(l->bval || r->bval);
            case T_EQ:  return make_bool(l->bval == r->bval);
            case T_NEQ: return make_bool(l->bval != r->bval);
        }
    }

    /* If none of the above conditions matched, it's a type error. */
    fprintf(stderr, STR_BIN_OP_TYPE_ERR, node->lineno);
    return make_unit();
}


/*
 * ----------------------------------------------------------------------------
 * MEMORY MANAGEMENT
 * ----------------------------------------------------------------------------
 */

/**
 * @brief Frees a Value struct and any heap-allocated data it contains.
 * @param v The Value to free.
 */

/**
 * @brief Frees a Value struct and any heap-allocated data it contains.
 * @param v The Value to free.
 */
void free_value(Value *v) {
    if (!v) return;

    switch (v->type) {
        case VAL_STRING:
            free(v->sval);
            break;
        case VAL_FUNC:
            if (v->func) {
                free(v->func->param);
                free(v->func->param_type);
                free(v->func->ret_type);

                // --- MODIFIED: Release the captured environment reference ---
                env_release(v->func->env);
                // ----------------------------------------------------------

                /* The function's body (ASTNode) and environment are owned by other *
                 * parts of the program (AST or parent environments) and are not    *
                 * freed here to prevent double-freeing.                            */
                free(v->func);
            }
            break;
        default:
            /* Other types (INT, FLOAT, BOOL, UNIT) don't have nested allocations. */
            break;
    }
    free(v);
}

/**
 * @brief Recursively frees an entire Abstract Syntax Tree.
 * @param node The root of the AST (or sub-tree) to free.
 */
void free_ast(ASTNode *node) {
    if (!node) return;

    switch(node->type) {
        case NODE_VAL:
            free_value(node->val);
            break;
        case NODE_VAR:
            free(node->var);
            break;
        case NODE_UNOP:
            free_ast(node->unop.operand);
            break;
        case NODE_BINOP:
            free_ast(node->binop.left);
            free_ast(node->binop.right);
            break;
        case NODE_IF:
            free_ast(node->ifexpr.cond);
            free_ast(node->ifexpr.then_expr);
            free_ast(node->ifexpr.else_expr);
            break;
        case NODE_LET:
            free(node->let.name);
            free_ast(node->let.value);
            free_ast(node->let.body);
            break;
        case NODE_ASSIGN:
            free(node->assign.name);
            free_ast(node->assign.value);
            break;
        case NODE_CONST:
            free(node->cdef.name);
            free(node->cdef.type_name);
            free_ast(node->cdef.value);
            break;
        case NODE_LAMBDA:
            free(node->lambda.param);
            free(node->lambda.param_type);
            free(node->lambda.ret_type);

            /* The lambda body's ownership is transferred to the Function struct
             * when it is evaluated. The AST of the body is freed when the
             * function object is eventually garbage collected or the program ends.
             * So we DO NOT free it here. free_ast(node->lambda.body); */
            break;
        case NODE_CALL:
            free_ast(node->call.fn);
            free_ast(node->call.arg);
            break;
        case NODE_SEQ: {
            ExprList *curr = node->seq.elist;
            while (curr) {
                ExprList *next = curr->next;
                free_ast(curr->expr);
                free(curr);
                curr = next;
            }
            break;
        }
        default:
            break;
    }
    free(node);
}

/*
 * ----------------------------------------------------------------------------
 * MAIN PROGRAM AND ERROR HANDLING
 * ----------------------------------------------------------------------------
 */

/**
 * @brief The main entry point for the interpreter.
 *
 * Sets up the global environment and runs the parser in a loop, either
 * from a file or from standard input (REPL mode).
 */
int main(int argc, char **argv)
{
    global_env = new_env(NULL); /* Initialize the global scope. */

    /* File processing mode */
    if (argc > 1) {
        char* filename = argv[1];
        FILE* file_ptr = fopen(filename, "r");

        if (file_ptr == NULL) {
            printf(STR_FILE_LOAD_ERROR, filename);
            return 1;
        }
        yyin = file_ptr; /* Point the lexer to the file. */
        do {
            yyparse();
        } while (!feof(yyin));
        fclose(file_ptr);
    }
    /* Interactive REPL mode */
    else {
        printf(BANNER);
        yyin = stdin; /* Point the lexer to standard input. */
        do {
            fflush(stdout);
            yyparse();
        } while (!feof(yyin));
    }

    /* Cleanup */
    free_env(global_env, true);
    yylex_destroy();
    return 0;
}

/**
 * @brief Error reporting function called by Bison on a parse error.
 * @param s The error message string from Bison.
 */
void yyerror(const char* s) {
    fprintf(stderr, STR_PARSE_ERR, yylineno, s);
}
