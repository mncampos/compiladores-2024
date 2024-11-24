/* MATEUS NUNES CAMPOS - 00268613  GUILHERME DE SOUSA CIRUMBOLO - 00330049 */
#include "../include/tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

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

  if (root->lex_value) {
    free_type_lex(root->lex_value);
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

static int inferRules(int first_type, int second_type)
{
  if (first_type == LEX_LIT_FLOAT || second_type == LEX_LIT_FLOAT)
  {
    return LEX_LIT_FLOAT;
  }
  else
    return LEX_LIT_INT;
}

int typeInfer(Node *root)
{
  int type = -1;
  if (root != NULL)
  {
    for (int i = 0; i < root->children_quantity; i++)
    {
      type = inferRules(type, typeInfer(root->children[i]));
    }
    return type;
  }
  return -1;
}
static void _asd_print(FILE *foutput, Node *tree, int profundidade)
{
  int i;
  if (tree != NULL)
  {
    fprintf(foutput, "%d%*s: Nó '%s' tem %d filhos:\n", profundidade, profundidade * 2, "", tree->lex_value->value, tree->children_quantity);
    for (i = 0; i < tree->children_quantity; i++)
    {
      _asd_print(foutput, tree->children[i], profundidade + 1);
    }
  }
}

void asd_print(Node *tree)
{
  FILE *foutput = stderr;
  if (tree != NULL)
  {
    _asd_print(foutput, tree, 0);
  }
  else
  {
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

static void _asd_print_graphviz(Node *tree)
{
  int i;
  if (tree != NULL)
  {
    printf("  %p [label=\"%s\"];\n", tree, tree->lex_value->value);
    for (i = 0; i < tree->children_quantity; i++)
    {
      printf("  %p,%p\n", tree, tree->children[i]);
      _asd_print_graphviz(tree->children[i]);
    }
  }
}

void asd_print_graphviz(Node *tree)
{
  if (tree != NULL)
  {
    _asd_print_graphviz(tree);
  }
}
