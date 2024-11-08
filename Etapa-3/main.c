#include <stdio.h>
#include "tree.h"
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta (void *arvore){
  asd_print_graphviz(arvore);
};
int main (int argc, char **argv)
{
  int ret = yyparse(); 
  exporta (arvore);
  yylex_destroy();
  free_ast(arvore);
  return ret;
}