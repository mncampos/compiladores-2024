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
    lista_funcoes | /* vazio */;

lista_funcoes:
    funcao | lista_funcoes funcao;

funcao:
    TK_IDENTIFICADOR '=' lista_parametros '>' tipo bloco_comandos;

lista_parametros:
    /* vazio */ | lista_parametros TK_OC_OR parametro;

parametro:
    TK_IDENTIFICADOR '<' '-' tipo;

tipo:
    TK_PR_INT | TK_PR_FLOAT;

bloco_comandos:
    '{' lista_comandos '}';

lista_comandos:
    /* vazio */ | lista_comandos comando;

comando:
    declaracao_variavel ';'
    | atribuicao ';'
    | chamada_funcao ';'
    | retorno ';'
    | bloco_comandos
    | controle_fluxo;

declaracao_variavel:
    tipo lista_variaveis;

lista_variaveis:
    TK_IDENTIFICADOR
    | lista_variaveis ',' TK_IDENTIFICADOR
    | lista_variaveis ',' TK_IDENTIFICADOR TK_OC_LE literal;

literal:
    TK_LIT_INT | TK_LIT_FLOAT;

atribuicao:
    TK_IDENTIFICADOR '=' expressao;

chamada_funcao:
    TK_IDENTIFICADOR '(' lista_argumentos ')';

lista_argumentos:
    /* vazio */ | lista_argumentos ',' expressao | expressao;

retorno:
    TK_PR_RETURN expressao;

controle_fluxo:
    TK_PR_IF '(' expressao ')' bloco_comandos TK_PR_ELSE bloco_comandos
    | TK_PR_IF '(' expressao ')' bloco_comandos
    | TK_PR_WHILE '(' expressao ')' bloco_comandos;

expressao:
    expressao_binaria
    | expressao_unaria
    | TK_IDENTIFICADOR
    | literal
    | chamada_funcao
    | '(' expressao ')';

expressao_binaria:
    expressao '+' expressao
    | expressao '-' expressao
    | expressao '*' expressao
    | expressao '/' expressao
    | expressao '%' expressao
    | expressao '<' expressao
    | expressao '>' expressao
    | expressao TK_OC_LE expressao
    | expressao TK_OC_GE expressao
    | expressao TK_OC_EQ expressao
    | expressao TK_OC_NE expressao
    | expressao TK_OC_AND expressao
    | expressao TK_OC_OR expressao;

expressao_unaria:
    '-' expressao | '!' expressao;

%%

// Função de erro
void yyerror(const char *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}