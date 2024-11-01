%{
// GRUPO O
// MATEUS NUNES CAMPOS - 00268613
// GUILHERME DE SOUSA CIRUMBOLO - 00330049
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror (char const *mensagem);
extern int yylineno;
extern char **ytext;
extern void *arvore;
%}

%code requires { #include "tree.h" }
%union {
     TypeLex* valor_lexico;
     Node* tree;
}

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


%%

// Definição da gramática

// Programa  principal

/* Um programa na linguagem é composto por uma
 lista de funções, sendo esta lista opcional. */

programa: lista_funcoes { $$ = $1; arvore = $$;  printf("arvore valida");   }
        | /* vazio */  { $$ = NULL }

// Funções

/*  Cada função é definida por um cabeçalho e um
 corpo. */

lista_funcoes:  lista_funcoes funcao 
             | funcao

funcao: cabecalho corpo


/*  O cabeçalho consiste no nome da função,  o caractere igual ’=’, uma lista de parâmetros, o
 operador maior ’>’ e o tipo de retorno. O tipo da função pode ser float ou int. A lista de parâmetros
  é composta por zero ou mais parâmetros de entrada, separados por TK_OC_OR. Cada parâmetro é definido
   pelo seu nome seguido do caractere menor ’<’, seguido do caractere menos ’-’, seguido do tipo. */

cabecalho: TK_IDENTIFICADOR parametros tipo
parametros : '='lista_parametros'>';
lista_parametros: TK_IDENTIFICADOR '<' '-' tipo TK_OC_OR lista_parametros 
                | TK_IDENTIFICADOR '<' '-' tipo 
                | /* vazio */

/*O corpo da função é um bloco de comandos. */
corpo: bloco_comandos;

//Tipos e Literais

literal: TK_LIT_INT       
       | TK_LIT_FLOAT     

tipo: TK_PR_INT 
    | TK_PR_FLOAT;

// Bloco de Comandos
/* Um bloco de comandos é definido entre chaves, e consiste em uma sequência, possivelmente vazia, de comandos simples cada um terminado por
 ponto-e-vírgula. Um bloco de comandos é considerado como umcomandoúnico simples, recursivamente,
 e pode ser utilizado em qualquer construção que aceite um comando simples. */
bloco_comandos: '{' lista_de_comandos '}' 
              | '{' '}';


/*  Os comandos simples da linguagem podem ser:
 declaração de variável, atribuição, construções de f luxo de controle, operação de retorno, um bloco de comandos, e chamadas de função */
comando: declaracao_variavel 
       | bloco_comandos 
       | chamada_funcao 
       | retorno 
       | controle_fluxo
       | atribuicao;

lista_de_comandos: comando ';' lista_de_comandos 
                 | comando ';';

// Variáveis

/*  Declaração de Variável: Consiste no tipo da variável seguido de uma lista composta de pelo menos um nome de variável (identificador) separadas por vírgula. Os tipos podem ser int e float.
 Uma variável pode ser opcionalmente inicializada caso sua declaração seja seguida do operador composto TK_OC_LE e de um literal. */
declaracao_variavel: tipo lista_variaveis

lista_variaveis: TK_IDENTIFICADOR ',' lista_variaveis 
               | TK_IDENTIFICADOR TK_OC_LE literal ',' lista_variaveis 
               | TK_IDENTIFICADOR TK_OC_LE literal
               | TK_IDENTIFICADOR;

//Atribuicao
/* O comando de atribuição consiste em um identificador seguido pelo caractere de igualdade seguido por uma expressão. */
atribuicao: TK_IDENTIFICADOR '=' expr 
                                    

//Chamada de função
/* Uma chamada de função consiste no nome da função, seguida de argumentos entre parênteses separados por vírgula. Um argumento pode ser uma expressão. */
chamada_funcao: TK_IDENTIFICADOR '(' lista_args ')'; 

lista_args: expr ',' lista_args 
          | expr;

// Comando de Retorno
/* Trata-se do token return seguido de uma expressão. */
retorno: TK_PR_RETURN expr 


//Controle de fluxo
/* A linguagem
 possui uma construção condicional e uma iterativa para controle estruturado de fluxo. A condicional consiste no token if seguido de uma expressão entre parênteses e então por um bloco de
 comandos obrigatório. O else, sendo opcional, deve sempre aparecer após o bloco do if, e é seguido de um bloco de comandos, obrigatório caso o else seja empregado. Temos apenas uma cons
trução de repetição que é o token while seguido de uma expressão entre parênteses e de um bloco de comandos */
controle_fluxo: if 
              | while;

if: TK_PR_IF '(' expr ')' corpo 
  | TK_PR_IF '(' expr ')' corpo TK_PR_ELSE corpo ;

while: TK_PR_WHILE  '(' expr ')' corpo ; 

//Expressões
/*  Expressões tem operandos e operadores, sendo este opcional. Os operandos podem ser (a) identificadores, (b) literais e (c) chamada de função ou (d) outras expressões, podendo portanto ser for
madas recursivamente pelo emprego de operadores. Elas também permitem o uso de parênteses para forçar uma associatividade ou precedência diferente daquela tradicional. A associatividade
 é à esquerda (portanto implemente recursão à esquerda nas regras gramaticais). */
expr: expr_or  

expr_or: expr_or TK_OC_OR expr_and 
       | expr_and;

expr_and: expr_and TK_OC_AND expr_eq 
       | expr_eq;

op_eq: TK_OC_EQ 
       | TK_OC_NE;

expr_eq: expr_eq op_eq expr_cmp 
       | expr_cmp;

op_cmp: '<' 
       | '>' 
       | TK_OC_LE 
       | TK_OC_GE;

expr_cmp: expr_cmp op_cmp expr_sum 
       | expr_sum;

op_sum: '+' 
       | '-';

expr_sum: expr_sum op_sum expr_mult 
       | expr_mult;

op_mult: '*' 
       | '/' 
       | '%' ;

expr_mult: expr_mult op_mult expr_unaria 
       | expr_unaria;

op_unario: '!' 
       | '-'; 

expr_unaria: op_unario expr_unaria 
       | parenteses;

parenteses: '(' expr ')' 
       | op;

op: TK_IDENTIFICADOR 
       | literal 
       | chamada_funcao;

%%

// Função de erro
void yyerror(const char *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}