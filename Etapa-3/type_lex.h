/* MATEUS NUNES CAMPOS - 00268613  GUILHERME DE SOUSA CIRUMBOLO - 00330049 */

#ifndef TYPE_LEX_H
#define TYPE_LEX_H

enum type_lex {
    LEX_LIT_INT,
    LEX_LIT_FLOAT,
    LEX_IDENTIFIER
};

typedef struct TypeLex {
    int line;
    enum type_lex type;
    char* value;

} TypeLex;

// Função para criar um novo tipo léxico
TypeLex* new_lex_type(int line, int type, char* value);

#endif
