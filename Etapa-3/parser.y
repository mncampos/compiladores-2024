%{
// MATEUS NUNES CAMPOS - 00268613
// GUILHERME DE SOUSA CIRUMBOLO - 00330049
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int yylex(void);
void yyerror (char const *mensagem);
extern int yylineno;
extern char **ytext;
extern void *arvore;
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
%token TK_ERRO

%token<valor_lexico> TK_IDENTIFICADOR
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT

%type<valor_lexico> literal
%type<tree> programa
%type<tree> lista_funcoes
%type<tree> funcao
%type<tree> cabecalho
%type<tree> parametros
%type<tree> lista_parametros
%type<tree> corpo
%type<tree> tipo
%type<tree> bloco_comandos
%type<tree> comando
%type<tree> lista_de_comandos
%type<tree> declaracao_variavel
%type<tree> lista_variaveis
%type<tree> atribuicao
%type<tree> chamada_funcao
%type<tree> lista_args
%type<tree> retorno
%type<tree> controle_fluxo
%type<tree> if
%type<tree> while
%type<tree> expr
%type<tree> expr_and
%type<tree> expr_or
%type<tree> op_eq
%type<tree> expr_eq
%type<tree> op_cmp
%type<tree> expr_cmp
%type<tree> op_sum
%type<tree> expr_sum
%type<tree> op_mult
%type<tree> expr_mult
%type<tree> op_unario
%type<tree> expr_unaria
%type<tree> parenteses
%type<tree> op



%union {
    struct TypeLex* valor_lexico;
    struct  Node* tree;
}

%%

// Definição da gramática

// Programa  principal

programa: lista_funcoes | /* vazio */;

// Funções

lista_funcoes:  funcao | lista_funcoes funcao;
funcao: cabecalho corpo;
cabecalho: TK_IDENTIFICADOR parametros tipo;
parametros : '='lista_parametros'>';
lista_parametros: TK_IDENTIFICADOR '<' '-' tipo TK_OC_OR lista_parametros | TK_IDENTIFICADOR '<' '-' tipo | /* vazio */
corpo: bloco_comandos;

//Tipos e Literais
literal: TK_LIT_INT | TK_LIT_FLOAT;
tipo: TK_PR_INT | TK_PR_FLOAT;

// Bloco de Comandos

bloco_comandos: '{' lista_de_comandos '}' | '{' '}';

comando:    declaracao_variavel 
            | bloco_comandos 
            | chamada_funcao 
            | retorno 
            | controle_fluxo
            | atribuicao;

lista_de_comandos: comando ';' lista_de_comandos | comando ';';

// Variáveis

declaracao_variavel:  tipo lista_variaveis;
lista_variaveis:  TK_IDENTIFICADOR ',' lista_variaveis 
                | TK_IDENTIFICADOR TK_OC_LE literal ',' lista_variaveis 
                | TK_IDENTIFICADOR TK_OC_LE literal | TK_IDENTIFICADOR;

//Atribuicao

atribuicao: TK_IDENTIFICADOR '=' expr;

//Chamada de função

chamada_funcao: TK_IDENTIFICADOR '(' lista_args ')';
lista_args: expr ',' lista_args | expr;

// Comando de Retorno

retorno: TK_PR_RETURN expr;

//Controle de fluxo

controle_fluxo: if | while;
if: TK_PR_IF '(' expr ')' corpo | TK_PR_IF '(' expr ')' corpo TK_PR_ELSE corpo ;
while: TK_PR_WHILE  '(' expr ')' corpo ; 

//Expressões
expr: expr_or;
expr_or: expr_or TK_OC_OR expr_and | expr_and;
expr_and: expr_and TK_OC_AND expr_eq | expr_eq;
op_eq: TK_OC_EQ | TK_OC_NE;
expr_eq: expr_eq op_eq expr_cmp | expr_cmp;
op_cmp: '<' | '>' | TK_OC_LE | TK_OC_GE;
expr_cmp: expr_cmp op_cmp expr_sum | expr_sum;
op_sum: '+' | '-';
expr_sum: expr_sum op_sum expr_mult | expr_mult;
op_mult: '*' | '/' | '%' ;
expr_mult: expr_mult op_mult expr_unaria | expr_unaria;
op_unario: '!' | '-'; 
expr_unaria: op_unario expr_unaria | parenteses;
parenteses: '(' expr ')' | op;
op: TK_IDENTIFICADOR | literal | chamada_funcao;

%%

// Função de erro
void yyerror(const char *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}