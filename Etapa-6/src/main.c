#include <stdio.h>
#include "../include/tree.h"
#include "../include/symbol_table.h"
#include "../include/stack.h"
#include "../include/assembly.h"

extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
Stack *table_stack = NULL;

int main(int argc, char **argv)
{
  int ret = yyparse();
  yylex_destroy();
  if (arvore != NULL)
  {
    print_asm_code(generateAsm(((Node *)arvore)->code, table_stack));
  }

  free_ast(arvore);
  free_stack(table_stack);
  return ret;
}