/* MATEUS NUNES CAMPOS - 00268613  GUILHERME DE SOUSA CIRUMBOLO - 00330049 */
#include "type_lex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

TypeLex *new_lex_type(int line, int type, char *value)
{
    TypeLex *new_lex = (TypeLex *)calloc(1, sizeof(TypeLex));

    if (new_lex == NULL)
    {
        fprintf(stderr, "Falha ao alocar memória para TypeLex! \n");
        return NULL;
    }

    new_lex->line = line;
    new_lex->type = type;
    new_lex->value = (char *)malloc(strlen(value) + 1);

    if (new_lex->value == NULL)
    {
        fprintf(stderr, "Falha ao alocar memória para o valor de TypeLex!\n");
        free(new_lex);
        return NULL;
    }

    strcpy(new_lex->value, value);

    return new_lex;
}