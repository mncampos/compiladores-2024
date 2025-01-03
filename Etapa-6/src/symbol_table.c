#include "../include/symbol_table.h"
#include "symbol_table.h"

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
    table->offset = 0;

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

int resize_symbol_table(SymbolTable *table)
{
    size_t new_capacity = table->capacity * 2;
    TableData *new_data = realloc(table->data, new_capacity * sizeof(TableData));
    if (!new_data)
    {
        return 0;
    }
    table->data = new_data;
    table->capacity = new_capacity;
    return 1;
}

int insert_symbol(SymbolTable *table, unsigned int line_number, int value_type, int symbol_type, char *lex_value)
{
    if (table->size >= table->capacity)
    {
        if (!resize_symbol_table(table))
        {
            return -1;
        }
    }

    TableData *entry = &table->data[table->size];
    entry->line_number = line_number;
    entry->value_type = (Kind)value_type;
    entry->symbol_type = (DataType)symbol_type;

    int length = snprintf(NULL, 0, "%d", table->offset);
    entry->offset = malloc(length + 1);
    snprintf(entry->offset, length + 1, "%d", table->offset);
    table->offset += sizeof(int);
    entry->temp_name = create_temporary();

    entry->lex_value = malloc(strlen(lex_value) + 1);
    if (!entry->lex_value)
    {
        return -1;
    }
    strcpy(entry->lex_value, lex_value);

    table->size++;
    return 1;
}

TableData *find_symbol(const SymbolTable *table, const char *lex_value)
{
    if (!table || !lex_value)
        return NULL;

    for (size_t i = 0; i < table->size; ++i)
    {
        if (strcmp(table->data[i].lex_value, lex_value) == 0)
        {
            return &table->data[i];
        }
    }
    return NULL;
}


DataType getType(const SymbolTable *table, const char *lex_value)
{
    for (size_t i = 0; i < table->size; ++i)
    {
        if (strcmp(table->data[i].lex_value, lex_value) == 0)
        {
            return table->data[i].symbol_type;
        }
    }
    return -1;
}

void print_symbol_table(const SymbolTable *table)
{
    if (!table || table->size == 0)
    {
        printf("The symbol table is empty.\n");
        return;
    }

    printf("Symbol Table:\n");
    printf("+-----+----------------+------------+-------------+----------------+\n");
    printf("| No. | Line Number    | Kind       | Data Type   | Lexical Value  |\n");
    printf("+-----+----------------+------------+-------------+----------------+\n");

    for (size_t i = 0; i < table->size; i++)
    {
        TableData *entry = &table->data[i];

        const char *value_type_str =
            (entry->value_type == IDENTIFIER) ? "Identifier" : "Function";

        const char *symbol_type_str =
            (entry->symbol_type == 1) ? "Int" : "Float";

        printf("| %-3zu | %-14u | %-10s | %-11s | %-14s |\n",
               i + 1,
               entry->line_number,
               value_type_str,
               symbol_type_str,
               entry->lex_value);
    }

    printf("+-----+----------------+------------+-------------+----------------+\n");
}
