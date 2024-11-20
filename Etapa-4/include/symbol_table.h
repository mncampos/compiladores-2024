#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "type_lex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum value_type
{
    DATA_IDENTIFIER,
    DATA_FUNCTION
} ValueType;

typedef enum symbol_type
{
    INT_TYPE,
    FLOAT_TYPE
} SymbolType;

typedef struct table_data
{
    unsigned int line_number;
    ValueType value_type;
    SymbolType symbol_type;
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
int insert_symbol(SymbolTable *table, TableData entry);
TableData *find_symbol(const SymbolTable *table, const char *lex_value);

#endif // SYMBOL_TABLE_H
