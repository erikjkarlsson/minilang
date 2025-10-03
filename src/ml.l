/* @file ml.l
 * @brief lexer
 */

/**************************************************************************\
 *                                                                        *
 *  This program is free software: you can redistribute it and/or modify  *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation, version 3.                              *
 *                                                                        *
 *  This program is distributed in the hope that it will be useful, but   *
 *  WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU      *
 *  General Public License for more details.                              *
 *                                                                        *
 *  You should have received a copy of the GNU General Public License     *
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.  *
 *                                                                        *
\**************************************************************************/

%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ml.tab.h"

static char *dupstr(const char *s) { return s ? strdup(s) : NULL; }

char *process_string(const char *str) {
    size_t len = strlen(str) - 2;
    char *result = malloc(len + 1);
    if (!result) {
        fprintf(stderr, "Fatal: malloc failed in process_string at line %d \n", yylineno);
        exit(EXIT_FAILURE);
    }
    char *p = result;
    for (const char *q = str + 1; *q && *q != '"'; q++) {
        if (*q == '\\') {
            q++;
            switch (*q) {
                case 'n': *p++ = '\n'; break;
                case 't': *p++ = '\t'; break;
                case '"': *p++ = '\"'; break;
                case '\\':*p++ = '\\'; break;
                default:  *p++ = *q; break;
            }
        } else {
            *p++ = *q;
        }
    }
    *p = '\0';
    return result;
}
%}
/* Definitions */
DIGIT       [0-9]
LETTER      [a-zA-Z_]
IDENT       {LETTER}({LETTER}|{DIGIT})*
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+
STRING      \"([^\\\"]|\\.)*\"
WHITESPACE  [ \t]+
COMMENT     #.*

%%

{WHITESPACE}    { /* Ignore whitespace */ }
{COMMENT}       { /* Ignore comments */ }
\n              { return T_NEWLINE; }

 /* Keywords */
"if"            { return T_IF; }
"then"          { return T_THEN; }
"else"          { return T_ELSE; }
"let"           { return T_LET; }
"in"            { return T_IN; }
"fun"           { return T_FUN; }
"const"         { return T_CONST; }
"do"            { return T_DO; }
"end"           { return T_END; }
"T"          { return T_TRUE; }
"F"         { return T_FALSE; }
"and"           { return T_AND; }
"or"            { return T_OR; }
"not"           { return T_NOT; }
"quit"          { return T_QUIT; }

 /* Operators */
"+"             { return T_PLUS; }
"-"             { return T_MINUS; }
"*"             { return T_MULTIPLY; }
"/"             { return T_DIVIDE; }
"%"             { return T_MOD; }
":="            { return T_SET; }
"=="            { return T_EQ; }
"!="            { return T_NEQ; }
"<"             { return T_LT; }
">"             { return T_GT; }
"<="            { return T_LTE; }
">="            { return T_GTE; }
"->"            { return T_ARROW; }
"::"            { return T_TYPE; }
":"             { return T_COLON; }
"\\"            { return T_LAMBDA; }


 /* Delimiters */
"("             { return T_LEFT; }
")"             { return T_RIGHT; }
"["             { return T_BLEFT; }
"]"             { return T_BRIGHT; }
";"             { return T_SEMICOLON; }
","             { return T_COMMA; }

 /* Literals */
{INTEGER}       { yylval.ival = atoi(yytext); return T_INT; }
{FLOAT}         { yylval.fval = atof(yytext); return T_FLOAT; }
{STRING}        { yylval.sval = process_string(yytext); return T_STR; }
{IDENT}         { yylval.name = dupstr(yytext); return T_SYM; }

 /* Error handling */
.               { fprintf(stderr, "Lexical error at line %d: unexpected character '%c'\n",
                    yylineno,  yytext[0]); }

%%
