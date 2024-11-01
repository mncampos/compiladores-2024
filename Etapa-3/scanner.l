/* MATEUS NUNES CAMPOS - 00268613  GUILHERME DE SOUSA CIRUMBOLO - 00330049 */

%{
#include <stdio.h>
#include "parser.tab.h"
#include "type_lex.h"
#include  <string.h>
int get_line_number(void);
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
[0-9]+ {yylval.valor_lexico = new_lex_type(get_line_number(), LEX_LIT_INT, strdup(yytext)); return TK_LIT_INT; }
[0-9]*\.[0-9]+ {yylval.valor_lexico = new_lex_type(get_line_number(), LEX_LIT_FLOAT, strdup(yytext)); return TK_LIT_FLOAT; }


    /* REGRA DOS IDENTIFICADORES */
([a-z]|_)([a-z]|[0-9]|_)* { yylval.valor_lexico = new_lex_type(get_line_number(), LEX_IDENTIFIER, strdup(yytext)); return TK_IDENTIFICADOR; }

{SPECIAL_CHARACTERS} { return yytext[0]; }

. { return TK_ERRO; }

%%

int get_line_number(void) {
    return yylineno;
}