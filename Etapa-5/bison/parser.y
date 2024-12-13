%{
// GRUPO O
// MATEUS NUNES CAMPOS - 00268613
// GUILHERME DE SOUSA CIRUMBOLO - 00330049
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"

int yylex(void);
void yyerror (char const *mensagem);
extern int yylineno;
extern char **ytext;
extern void *arvore;
extern Stack *table_stack;
DataType current_type = -1;
%}

%code requires { #include "../include/tree.h" }
%code requires { #include "../include/stack.h" }
%union {
     TypeLex* valor_lexico;
     Node* tree;
}

%define parse.error verbose


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
%token<valor_lexico> TK_PR_INT
%token<valor_lexico> TK_PR_FLOAT

%type<valor_lexico> tipo
%type<tree> literal
%type<tree> programa
%type<tree> lista_funcoes
%type<tree> funcao
%type<tree> cabecalho
%type<tree> corpo
%type<tree> bloco_comandos
%type<tree> comando
%type<tree> comandos
%type<tree> lista_de_comandos
%type<tree> declaracao_variavel
%type<tree> variavel
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
%type<tree> expr_eq
%type<tree> expr_cmp
%type<tree> expr_sum
%type<tree> expr_mult
%type<tree> expr_unaria
%type<tree> parenteses
%type<tree> op


%start begin_program;

%%

// Definição da gramática

// Programa  principal

/* Um programa na linguagem é composto por uma
 lista de funções, sendo esta lista opcional. */

begin_program: criar_pilha_tabelas empilha_tabela  programa



programa:
    lista_funcoes desempilha_tabela  {
        $$ = $1;
        arvore = $$;
    }
    | /* vazio */ {
        $$ = NULL;
        arvore = $$;
    }


criar_pilha_tabelas : {table_stack = create_stack(1);}
empilha_tabela : {push_stack(table_stack, create_symbol_table(1));}
desempilha_tabela : {pop_stack(table_stack);}


// Funções

/*  Cada função é definida por um cabeçalho e um
 corpo. */

lista_funcoes:
    funcao lista_funcoes {
        $$ = $1;
        add_child($$, $2);
    }
    | funcao {
        $$ = $1;
    }

funcao:
    cabecalho corpo desempilha_tabela {
        $$ = $1;
        add_child($$, $2);
    }

/*  O cabeçalho consiste no nome da função,  o caractere igual ’=’, uma lista de parâmetros, o
 operador maior ’>’ e o tipo de retorno. O tipo da função pode ser float ou int. A lista de parâmetros
  é composta por zero ou mais parâmetros de entrada, separados por TK_OC_OR. Cada parâmetro é definido
   pelo seu nome seguido do caractere menor ’<’, seguido do caractere menos ’-’, seguido do tipo. */

cabecalho:
    TK_IDENTIFICADOR '=' empilha_tabela lista_parametros '>' tipo {
        
        $$ = new_node($1);
        
        isAlreadyDeclared(peek_stack(table_stack,2), $1->value, $1->line);
        insert_symbol(peek_stack(table_stack, 2), $1->line, FUNCTION, $6->type, $1->value);
        $$->lex_value->type = $6->type;
    }

lista_parametros:
    lista_parametros TK_OC_OR TK_IDENTIFICADOR '<' '-' tipo { isAlreadyDeclared(peek_stack(table_stack,1), $3->value, $3->line); insert_symbol(peek_stack(table_stack,1), $3->line, IDENTIFIER, $6->type, $3->value ); }
    | TK_IDENTIFICADOR '<' '-' tipo {isAlreadyDeclared(peek_stack(table_stack,1), $1->value, $1->line); insert_symbol(peek_stack(table_stack,1), $1->line, IDENTIFIER, $4->type, $1->value );  }
    | /* vazio */


/*O corpo da função é um bloco de comandos. */
corpo: '{' lista_de_comandos '}' {
        $$ = $2;
    }


//Tipos e Literais

literal:
    TK_LIT_INT {
        $$ = new_node($1);
        $$->lex_value->type = LEX_LIT_INT;
    }
    | TK_LIT_FLOAT {
        $$ = new_node($1);
        $$->lex_value->type = LEX_LIT_FLOAT;
    }

tipo:
    TK_PR_INT
    | TK_PR_FLOAT
      

// Bloco de Comandos
/* Um bloco de comandos é definido entre chaves, e consiste em uma sequência, possivelmente vazia, de comandos simples cada um terminado por
 ponto-e-vírgula. Um bloco de comandos é considerado como umcomandoúnico simples, recursivamente,
 e pode ser utilizado em qualquer construção que aceite um comando simples. */
bloco_comandos:
    '{' empilha_tabela lista_de_comandos desempilha_tabela '}' {
        $$ = $3;
    }

/*  Os comandos simples da linguagem podem ser:
    declaração de variável, atribuição, construções de fluxo de controle,
    operação de retorno, um bloco de comandos, e chamadas de função */
comando:
    comandos ';' {
        $$ = $1;
    }

comandos:
    bloco_comandos {
        if ($1 != NULL) {
            $$ = $1;
        }
    }
    | chamada_funcao {
        $$ = $1;
    }
    | retorno {
        $$ = $1;
    }
    | controle_fluxo {
        $$ = $1;
    }
    | atribuicao {
        $$ = $1;
    }

lista_de_comandos:
    comando lista_de_comandos {
        if ($1 != NULL) {
            $$ = $1;
            if ($2 != NULL) {
                add_child($$, $2);
            }
        } else {
            $$ = $2;
        }
    }
    | declaracao_variavel ';' lista_de_comandos {
        if ($1 != NULL) {
            $$ = $1;
            if ($1->children_quantity == 3) {
                Node* aux = $1->children[2];
                while (aux->children_quantity == 3) {
                    aux = aux->children[2];
                }
                add_child(aux, $3);
            } else {
                add_child($$, $3);
            }
        } else {
            $$ = $3;
        }
    }
    | /* vazio */ {
        $$ = NULL;
    }


// Variáveis

/*  Declaração de Variável: Consiste no tipo da variável seguido de uma lista composta de pelo menos um nome de variável (identificador) separadas por vírgula. Os tipos podem ser int e float.
 Uma variável pode ser opcionalmente inicializada caso sua declaração seja seguida do operador composto TK_OC_LE e de um literal. */
declaracao_variavel:
    tipo lista_variaveis {
        current_type = $1->type;
        $$ = $2;
    }

lista_variaveis:
    variavel {
        $$ = $1;
    }
    | variavel ',' lista_variaveis {
        if ($1 != NULL) {
            $$ = $1;
            if ($3 != NULL) {
                add_child($$, $3);
            }
        } else {
            $$ = $3;
        }
    }

variavel:
    TK_IDENTIFICADOR {
        $$ = NULL;
        isAlreadyDeclared(peek_stack(table_stack,1), $1->value, $1->line);
        insert_symbol(peek_stack(table_stack, 1), $1->line, IDENTIFIER, current_type, $1->value);
    }
    | TK_IDENTIFICADOR TK_OC_LE literal {
        $$ = new_simple_node("<=");
        Node* new = new_node($1);
        new->lex_value->type = current_type;
        add_child($$, new);
        add_child($$, $3);

        isAlreadyDeclared(peek_stack(table_stack,1), $1->value, $1->line);
        insert_symbol(peek_stack(table_stack, 1), $1->line, IDENTIFIER, current_type, $1->value);
    }


// Atribuicao
/* O comando de atribuição consiste em um identificador seguido pelo caractere de igualdade seguido por uma expressão. */
atribuicao:
    TK_IDENTIFICADOR '=' expr {

        
        isUndeclared(table_stack, $1->value, $1->line);
        isKindCorrect(table_stack, $1->value, IDENTIFIER, $1->line);

        $$ = new_simple_node("=");
        Node* new = new_node($1);
        new->lex_value->type = $$->lex_value->type;
        add_child($$, new);
        add_child($$, $3);

        TableData* data = find_symbol(peek_stack(table_stack, 1), $1->value);
        $$->lex_value->type = data->symbol_type;
        $$->code = add_instruction($$->code, new_instruction("loadI", data->offset, data->temp_name, NULL));
        $$->code = add_instruction($$->code, new_instruction("storeAO", $3->temp_name, data->temp_name, "rfp"));



    }

// Chamada de função
/* Uma chamada de função consiste no nome da função, seguida de argumentos entre parênteses separados por vírgula. Um argumento pode ser uma expressão. */
chamada_funcao:
    TK_IDENTIFICADOR '(' lista_args ')' {

        size_t new_length = strlen($1->value) + strlen("call ") + 1;
        char* buffer = malloc(new_length);
        if (buffer) {
            snprintf(buffer, new_length, "call %s", $1->value);
            $$ = new_simple_node(buffer);
            add_child($$, $3);
        }

        
        isUndeclared(table_stack, $1->value, $1->line);
        isKindCorrect(table_stack, $1->value, FUNCTION, $1->line);
    }

lista_args:
    expr {
        $$ = $1;
    }
    | expr ',' lista_args {
        $$ = $1;
        add_child($$, $3);
    }

// Comando de Retorno
/* Trata-se do token return seguido de uma expressão. */
retorno:
    TK_PR_RETURN expr {
        $$ = new_simple_node("return");
        add_child($$, $2);
    }



//Controle de fluxo
/* A linguagem
 possui uma construção condicional e uma iterativa para controle estruturado de fluxo. A condicional consiste no token if seguido de uma expressão entre parênteses e então por um bloco de
 comandos obrigatório. O else, sendo opcional, deve sempre aparecer após o bloco do if, e é seguido de um bloco de comandos, obrigatório caso o else seja empregado. Temos apenas uma cons
trução de repetição que é o token while seguido de uma expressão entre parênteses e de um bloco de comandos */
controle_fluxo:
    if {
        $$ = $1;
    }
    | while {
        $$ = $1;
    }

if:
    TK_PR_IF '(' expr ')' bloco_comandos {
        $$ = new_simple_node("if");
        add_child($$, $3);
        char* label1 = create_label();
        char* label2 = create_label();
        char* label3 = create_label();

        add_instruction($$->code, new_instruction("cbr", $3->temp_name, label1, label2));
        add_instruction($$->code, new_instruction("label", label1, NULL, NULL));

        if ($5 != NULL) {
            add_child($$, $5);
        }

        add_instruction($$->code, new_instruction("jumpI", label3, NULL, NULL));
        add_instruction($$->code, new_instruction("label", label2, NULL, NULL));
    }
    | TK_PR_IF '(' expr ')' bloco_comandos TK_PR_ELSE bloco_comandos {
        $$ = new_simple_node("if");
        add_child($$, $3);
        char* label1 = create_label();
        char* label2 = create_label();
        char* label3 = create_label();

        add_instruction($$->code, new_instruction("cbr", $3->temp_name, label1, label2));
        add_instruction($$->code, new_instruction("label", label1, NULL, NULL));
        if ($5 != NULL) {
            add_child($$, $5);
        }

        add_instruction($$->code, new_instruction("jumpI", label3, NULL, NULL));
        add_instruction($$->code, new_instruction("label", label2, NULL, NULL));

        if ($7 != NULL) {
            add_child($$, $7);
        }

        add_instruction($$->code, new_instruction("label", label3, NULL, NULL));
    }

while:
    TK_PR_WHILE '(' expr ')' bloco_comandos {
        $$ = new_simple_node("while");

        char* label1 = create_label();
        char* label2 = create_label();
        char* label3 = create_label();
        $$->code = add_instruction(new_list(), new_instruction("label", label3, NULL, NULL));
        add_child($$, $3);
        add_instruction($$->code, new_instruction("cbr", $3->temp_name, label1, label2));
        add_instruction($$->code, new_instruction("label", label1, NULL, NULL));

        if ($5 != NULL) {
            add_child($$, $5);
        }

        add_instruction($$->code, new_instruction("jumpI", label3, NULL, NULL));
        add_instruction($$->code, new_instruction("label", label2, NULL, NULL));
    }


//Expressões
/*  Expressões tem operandos e operadores, sendo este opcional. Os operandos podem ser (a) identificadores, (b) literais e (c) chamada de função ou (d) outras expressões, podendo portanto ser for
madas recursivamente pelo emprego de operadores. Elas também permitem o uso de parênteses para forçar uma associatividade ou precedência diferente daquela tradicional. A associatividade
 é à esquerda (portanto implemente recursão à esquerda nas regras gramaticais). */
expr:
    expr_or {
        $$ = $1;
    }

expr_or:
    expr_or TK_OC_OR expr_and {
        $$ = new_simple_node("|");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_and {
        $$ = $1;
    }

expr_and:
    expr_and TK_OC_AND expr_eq {
        $$ = new_simple_node("&");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_eq {
        $$ = $1;
    }

expr_eq:
    expr_eq TK_OC_EQ expr_cmp {
        $$ = new_simple_node("==");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_eq TK_OC_NE expr_cmp {
        $$ = new_simple_node("!=");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_cmp {
        $$ = $1;
    }

expr_cmp:
    expr_cmp '<' expr_sum {
        $$ = new_simple_node("<");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_cmp '>' expr_sum {
        $$ = new_simple_node(">");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_cmp TK_OC_LE expr_sum {
        $$ = new_simple_node("<=");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_cmp TK_OC_GE expr_sum {
        $$ = new_simple_node(">=");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_sum {
        $$ = $1;
    }

expr_sum:
    expr_sum '+' expr_mult {
        $$ = new_simple_node("+");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_sum '-' expr_mult {
        $$ = new_simple_node("-");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_mult {
        $$ = $1;
    }

expr_mult:
    expr_mult '*' expr_unaria {
        $$ = new_simple_node("*");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_mult '/' expr_unaria {
        $$ = new_simple_node("/");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_mult '%' expr_unaria {
        $$ = new_simple_node("%");
        $$->lex_value->type = typeInfer($1->lex_value->type, $3->lex_value->type);
        add_child($$, $1);
        add_child($$, $3);
        gen_code($$, $1->temp_name, $3->temp_name, 1);
    }
    | expr_unaria {
        $$ = $1;
    }

expr_unaria:
    '!' expr_unaria {
        $$ = new_simple_node("!");
        $$->lex_value->type = $2->lex_value->type;
        add_child($$, $2);
        char* temp_name = create_temporary();
        add_instruction($$->code, new_instruction("loadI", get_constant($$->lex_value->value), temp_name, NULL));
        gen_code($$, $2->temp_name, temp_name, 0);
    }
    | '-' expr_unaria {
        $$ = new_simple_node("-");
        $$->lex_value->type = $2->lex_value->type;
        add_child($$, $2);
         char* temp_name = create_temporary();
        add_instruction($$->code, new_instruction("loadI", get_constant($$->lex_value->value), temp_name, NULL));
        gen_code($$, $2->temp_name, temp_name, 0);
    }
    | parenteses {
        $$ = $1;
    }

parenteses:
    '(' expr ')' {
        $$ = $2;
    }
    | op {
        $$ = $1;
    }

op:
    TK_IDENTIFICADOR {
        
        isUndeclared(table_stack, $1->value, $1->line);
        isKindCorrect(table_stack,$1->value, IDENTIFIER, $1->line);
        $1->type = getType(peek_stack(table_stack, 1), $1->value);
        $$ = new_node($1);

        TableData* data = find_symbol(peek_stack(table_stack, 1), $1->value);
        $$->temp_name = create_temporary();
        $$->code = add_instruction(new_list(), new_instruction("loadAO", data->temp_name, "rfp", $$->temp_name));
    }
    | literal {
        $$ = $1;
        $$->temp_name = create_temporary();
        $$->code = add_instruction(new_list(), new_instruction("loadI", $$->lex_value->value, $$->temp_name, NULL));
    }
    | chamada_funcao {
        $$ = $1;
    }


%%

// Função de erro
void yyerror(const char *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}