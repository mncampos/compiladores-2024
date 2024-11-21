#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "type_lex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum kind
{
    IDENTIFIER,
    FUNCTION
} Kind; // Natureza

typedef enum data_type
{
    INT_TYPE,
    FLOAT_TYPE
} DataType; // Tipo do dado 

typedef struct table_data
{
    unsigned int line_number;
    Kind value_type;
    DataType symbol_type;
    char *lex_value;

} TableData;

typedef struct symbol_table
{
    TableData *data;
    size_t size;
    size_t capacity;
} SymbolTable;

SymbolTable *create_symbol_table(size_t initial_capacity);
void free_symbol_table(SymbolTable *table);
int insert_symbol(SymbolTable *table, unsigned int line_number, int value_type, int symbol_type, char * lex_value);
int resize_symbol_table(SymbolTable *table);
TableData *find_symbol(const SymbolTable *table, const char *lex_value);

//debug

void print_symbol_table(const SymbolTable *table);

#endif // SYMBOL_TABLE_H
