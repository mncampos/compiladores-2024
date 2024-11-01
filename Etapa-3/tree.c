/* MATEUS NUNES CAMPOS - 00268613  GUILHERME DE SOUSA CIRUMBOLO - 00330049 */
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *new_node(TypeLex *lex_value)
{
    Node *new_node = (Node *)calloc(1, sizeof(Node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Falha ao alocar memória para o novo nodo! \n");
        return NULL;
    }

    new_node->lex_value = lex_value;
    new_node->children = NULL;
    new_node->children_quantity = 0;

    return new_node;
}

Node *new_simple_node(char *value)
{
    Node *new_node = calloc(1, sizeof(Node));
    TypeLex *aux = calloc(1, sizeof(TypeLex));

    if (new_node == NULL || aux == NULL)
    {
        fprintf(stderr, "Falha ao alocar memória para o novo nodo! \n");
        free(new_node);
        free(aux);
        return NULL;
    }

    aux->value = value;
    new_node->lex_value = aux;
    new_node->children = NULL;
    new_node->children_quantity = 0;

    return new_node;
}

void free_ast(Node *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children_quantity; ++i)
    {
        free_ast(root->children[i]);
    }

    free(root->children);
    free(root);
}

void add_child(Node *parent, Node *child)
{
    if (parent == NULL || child == NULL)
        return;

    Node **new_children = (Node **)realloc(parent->children, (parent->children_quantity + 1) * sizeof(Node *));

    if (new_children == NULL)
    {
        fprintf(stderr, "Falha ao alocar memória para o novo filho! \n");
        free(new_children);
        return;
    }

    parent->children = new_children;
    parent->children[parent->children_quantity] = child;
    parent->children_quantity++;
}

void exporta(void *arvore)
{
    if (arvore == NULL)
        return;
    Node *root = (Node *)arvore;

    if (root->lex_value != NULL)
    {
        printf("%p [label=\"%s\"];\n", (void *)root, root->lex_value->value);
    }
    else
    {
        printf("%p [label=\"<NULL>\"];\n", (void *)root);
    }
    for (int i = 0; i < root->children_quantity; i++)
    {
        printf("%p, %p\n", (void *)root, (void *)(root->children[i]));
    }
    for (int i = 0; i < root->children_quantity; i++)
    {
        exporta(root->children[i]);
    }
}
