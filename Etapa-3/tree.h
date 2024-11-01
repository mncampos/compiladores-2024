/* MATEUS NUNES CAMPOS - 00268613  GUILHERME DE SOUSA CIRUMBOLO - 00330049 */
#include "type_lex.h"

#ifndef TREE_H
#define TREE_H

typedef struct node {
    TypeLex* lex_value;
    int children_quantity;
    struct node** children;
} Node;


//Cria um novo nó na árvore com valor léxico
Node* new_node(TypeLex* lex_value);

//Cria um novo nó na árvore com apenas label, sem valor léxico
Node* new_simple_node(char* value);

//Libera recursivamente a memória na árvore
void free_ast(Node* root);

//Adiciona um filho a um nó na árvore
void add_child(Node* parent, Node* child);

//Exporta a árvore
void exporta(void* arvore);



#endif