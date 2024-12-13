/* MATEUS NUNES CAMPOS - 00268613  GUILHERME DE SOUSA CIRUMBOLO - 00330049 */
#include "type_lex.h"
#include "linked_list.h"

#ifndef TREE_H
#define TREE_H

typedef struct node {
    TypeLex* lex_value;
    int children_quantity;
    struct node** children;
    InstructionList *code;
    char* temp_name;
} Node;


//Cria um novo nó na árvore com valor léxico informado
Node* new_node(TypeLex* lex_value);

//Cria um novo nó na árvore com apenas label, sem valor léxico
Node* new_simple_node(char* value);

//Libera recursivamente a memória na árvore
void free_ast(Node* root);

//Adiciona um filho a um nó na árvore
void add_child(Node* parent, Node* child);

//Infere o tipo de um nodo raiz de expressão
int typeInfer(int type_1, int type_2);

//Gera o código da expressão
void gen_code(Node* op, char* first_op, char* second_op, int is_binary);

// Funçoes do professor
void asd_print(Node *tree);
void asd_print_graphviz(Node *tree);



#endif