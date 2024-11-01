/* Mateus Nunes Campos - 00268613  */

%{
#include <stdio.h>
#include "parser.tab.h"
%}

%option yylineno
%option noyywrap


SPACE [ \t\r\f\n]
SPECIAL_CHARACTERS [-!*\/%+<>{}()=,;]

%%


(\/\/).* {}
{SPACE} {}


"int" {return TK_PR_INT; }
"float" { return TK_PR_FLOAT; }
"if" { return TK_PR_IF; }
"else" { return TK_PR_ELSE; }
"while" { return TK_PR_WHILE; }
"return" { return TK_PR_RETURN; }

"<=" { return TK_OC_LE; }
">=" { return TK_OC_GE; }
"==" { return TK_OC_EQ; }
"!=" { return TK_OC_NE; }
"&" { return TK_OC_AND; }
"|" { return TK_OC_OR; }


    /*REGRA DOS LITERAIS */
[0-9]+ { return TK_LIT_INT; }
[0-9]*\.[0-9]+ { return TK_LIT_FLOAT; }


    /* REGRA DOS IDENTIFICADORES */
([a-z]|_)([a-z]|[0-9]|_)* { return TK_IDENTIFICADOR; }

{SPECIAL_CHARACTERS} { return yytext[0]; }

. { return TK_ERRO; }

%%

int get_line_number(void) {
    return yylineno;
}