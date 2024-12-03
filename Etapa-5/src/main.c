#include <stdio.h>
#include "../include/tree.h"
#include "../include/symbol_table.h"
#include "../include/stack.h"

extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
Stack *table_stack = NULL;

void exporta (void *arvore){
  asd_print_graphviz(arvore);
};
int main (int argc, char **argv)
{
  int ret = yyparse(); 
  exporta (arvore);
  yylex_destroy();
  free_ast(arvore);
  free_stack(table_stack);
  return ret;
}