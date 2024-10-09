%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror (char const *mensagem);
extern int yylineno;
%}



%define parse.error verbose   

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_IF
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_IDENTIFICADOR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_ERRO

%%

// Definição da gramática
programa:
    declaracoes;

declaracoes:
    declaracao | declaracoes declaracao;

declaracao:
    tipo TK_IDENTIFICADOR ';' | tipo TK_IDENTIFICADOR '=' expressao ';';

tipo:
    TK_PR_INT | TK_PR_FLOAT;

expressao:
    TK_LIT_INT
    | TK_LIT_FLOAT
    | TK_IDENTIFICADOR
    | expressao '+' expressao
    | expressao '-' expressao
    | expressao '*' expressao
    | expressao '/' expressao
    | expressao TK_OC_LE expressao
    | expressao TK_OC_GE expressao
    | expressao TK_OC_EQ expressao
    | expressao TK_OC_NE expressao
    | expressao TK_OC_AND expressao
    | expressao TK_OC_OR expressao
    ;

%%

// Função de erro
void yyerror(const char *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}