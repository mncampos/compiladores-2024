%{
// MATEUS NUNES CAMPOS - 00268613
// GUILHERME DE SOUSA CIRUMBOLO - 00330049
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror (char const *mensagem);
extern int yylineno;
extern char **ytext;
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

atribuicao: TK_IDENTIFICADOR '=' expressao;

//Chamada de função

chamada_funcao: TK_IDENTIFICADOR '(' lista_args ')';
lista_args: expressao ',' lista_args | expressao;

// Comando de Retorno

retorno: TK_PR_RETURN expressao;

//Controle de fluxo

controle_fluxo: if | while;
if: TK_PR_IF '(' expressao ')' corpo | TK_PR_IF '(' expressao ')' corpo TK_PR_ELSE corpo ;
while: TK_PR_WHILE  '(' expressao ')' corpo ; 

//Expressões -> Precedência maior fica mais embaixo
expressao: expressao TK_OC_OR produto
         |  expressao TK_OC_AND produto
         |  expressao TK_OC_NE produto
         |  expressao TK_OC_EQ produto
         |  expressao TK_OC_GE produto
         |  expressao TK_OC_LE produto
         |  expressao '>' produto
         |  expressao '<' produto
         |  expressao '-' produto
         |  expressao '+' produto
         |  produto
         ;

produto: produto '%' primario
       |  produto '/' primario 
       |  produto '*' primario
       |  primario
       ;

primario: '!' primario
        |  '-' primario
        | '(' expressao ')'
        | TK_IDENTIFICADOR | TK_LIT_FLOAT | TK_LIT_INT | chamada_funcao
        ;


%%

// Função de erro
void yyerror(const char *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}