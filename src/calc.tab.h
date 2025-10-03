/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CALC_TAB_H_INCLUDED
# define YY_YY_CALC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_ID = 258,                    /* T_ID  */
    T_INT = 259,                   /* T_INT  */
    T_FLOAT = 260,                 /* T_FLOAT  */
    T_STR = 261,                   /* T_STR  */
    T_SYM = 262,                   /* T_SYM  */
    T_NAME = 263,                  /* T_NAME  */
    T_PLUS = 264,                  /* T_PLUS  */
    T_MINUS = 265,                 /* T_MINUS  */
    T_MULTIPLY = 266,              /* T_MULTIPLY  */
    T_DIVIDE = 267,                /* T_DIVIDE  */
    T_MOD = 268,                   /* T_MOD  */
    T_LEFT = 269,                  /* T_LEFT  */
    T_RIGHT = 270,                 /* T_RIGHT  */
    T_BLEFT = 271,                 /* T_BLEFT  */
    T_BRIGHT = 272,                /* T_BRIGHT  */
    T_TRUE = 273,                  /* T_TRUE  */
    T_FALSE = 274,                 /* T_FALSE  */
    T_IF = 275,                    /* T_IF  */
    T_THEN = 276,                  /* T_THEN  */
    T_ELSE = 277,                  /* T_ELSE  */
    T_LET = 278,                   /* T_LET  */
    T_IN = 279,                    /* T_IN  */
    T_SET = 280,                   /* T_SET  */
    T_FUN = 281,                   /* T_FUN  */
    T_ARROW = 282,                 /* T_ARROW  */
    T_TYPE = 283,                  /* T_TYPE  */
    T_COLON = 284,                 /* T_COLON  */
    T_AND = 285,                   /* T_AND  */
    T_OR = 286,                    /* T_OR  */
    T_NOT = 287,                   /* T_NOT  */
    T_EQ = 288,                    /* T_EQ  */
    T_NEQ = 289,                   /* T_NEQ  */
    T_LT = 290,                    /* T_LT  */
    T_GT = 291,                    /* T_GT  */
    T_LTE = 292,                   /* T_LTE  */
    T_GTE = 293,                   /* T_GTE  */
    T_CONST = 294,                 /* T_CONST  */
    T_DO = 295,                    /* T_DO  */
    T_END = 296,                   /* T_END  */
    T_SEMICOLON = 297,             /* T_SEMICOLON  */
    T_COMMA = 298,                 /* T_COMMA  */
    T_NEWLINE = 299,               /* T_NEWLINE  */
    T_QUIT = 300,                  /* T_QUIT  */
    T_LAMBDA = 301,                /* T_LAMBDA  */
    UMINUS = 302                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 101 "calc.y"

    char *id;
    int ival;
    double fval;
    char *sval;
    char *name;
    struct Value *value;
    struct ASTNode *node;
    struct ExprList *elist;

#line 122 "calc.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CALC_TAB_H_INCLUDED  */
