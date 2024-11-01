#include <stdio.h>
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta (void *arvore);
int main (int argc, char **argv)
{
  int ret = yyparse(); 
  printf("vou exportar");
  exporta (arvore);
  printf("sucesso");
  yylex_destroy();
  return ret;
}
