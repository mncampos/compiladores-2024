#include "../include/symbol_table.h"

SymbolTable *create_symbol_table(size_t initial_capacity)
{
    SymbolTable *table = (SymbolTable *)calloc(1, sizeof(SymbolTable));
    if (table == NULL)
    {
        fprintf(stderr, "Falha ao alocar memória para a nova tabela de símbolos! \n");
        return NULL;
    }

    table->data = (TableData *)calloc(initial_capacity, sizeof(TableData));
    if (table->data == NULL)
    {
        fprintf(stderr, "Falha ao alocar memória para dados da tabela de símbolos! \n");
        return NULL;
    }
    table->capacity = initial_capacity;
    table->size = 0;

    return table;
}

void free_symbol_table(SymbolTable *table)
{
    if (table == NULL)
    {
        return;
    }

    for (size_t i = 0; i < table->size; ++i)
    {
        free(table->data[i].lex_value);
    }
    free(table->data);
    free(table);
}

int insert_symbol(SymbolTable *table, TableData entry)
{
    if (table->size >= table->capacity)
    {
        size_t new_capacity = table->capacity * 2;
        TableData *new_data = (TableData *)realloc(table->data, new_capacity * sizeof(TableData));
        if (!new_data)
            return -1;
        table->data = new_data;
        table->capacity = new_capacity;
    }
    table->data[table->size++] = entry;
    return 0;
}

TableData *find_symbol(const SymbolTable *table, const char *lex_value)
{
    for (size_t i = 0; i < table->size; ++i)
    {
        if (strcmp(table->data[i].lex_value, lex_value) == 0)
        {
            return &table->data[i];
        }
    }
    return NULL;
}