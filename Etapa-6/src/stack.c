#include "../include/stack.h"
#include "stack.h"

Stack *create_stack(size_t initial_capacity)
{
    Stack *stack = malloc(sizeof(Stack));
    if (!stack)
        return NULL;

    stack->tables = malloc(initial_capacity * sizeof(SymbolTable *));
    if (!stack->tables)
    {
        free(stack);
        return NULL;
    }

    stack->size = 0;
    stack->capacity = initial_capacity;
    return stack;
}

void free_stack(Stack *stack)
{
    if (!stack)
        return;

    for (size_t i = 0; i < stack->size; ++i)
    {
        free_symbol_table(stack->tables[i]);
    }

    free(stack->tables);
    free(stack);
}

int push_stack(Stack *stack, SymbolTable *table)
{
    if (stack->size >= stack->capacity)
    {
        size_t new_capacity = stack->capacity * 2;
        SymbolTable **new_tables = realloc(stack->tables, new_capacity * sizeof(SymbolTable *));
        if (!new_tables)
            return -1;

        stack->tables = new_tables;
        stack->capacity = new_capacity;
    }

    stack->tables[stack->size++] = table;
    return 0;
}

SymbolTable *pop_stack(Stack *stack)
{
    if (stack->size == 0)
        return NULL;

    return stack->tables[stack->size];
}

SymbolTable *peek_stack(const Stack *stack, unsigned short level)
{
    if (stack->size == 0 || level == 0 || level > stack->size)
    {
        return NULL;
    }

    return stack->tables[stack->size - level];
}

TableData *find_stack_symbol(const Stack *stack, const char *lex_value)
{
    for (size_t i = 0; i < stack->size; i++)
    {
        TableData *data = find_symbol(stack->tables[i], lex_value);
        if (data != NULL)
        {
            return data;
        }
    }
    printf("\nErro ao encontrar símbolo.");
    exit(1);
}

TableData *find_register(Stack *stack, char *lex_value)
{
    for (size_t i = 0; i < stack->size; i++)
    {
        TableData *data = find_symbol(stack->tables[i], lex_value);
        if (data != NULL)
        {
            return data;
        }
    }

    insert_symbol(peek_stack(stack, 1), 0, REGISTER, NULL_TYPE, lex_value);
    return find_register(stack, lex_value);
}

void print_all_tables(const Stack *stack)
{

    if (stack == NULL || stack->tables == NULL)
    {
        printf("Stack is empty or uninitialized.\n");
        return;
    }

    printf("Stack contains %zu tables:\n", stack->size);
    for (size_t i = 0; i < stack->size; i++)
    {
        print_symbol_table(stack->tables[i]);
        printf("\n");
    }
}

void isAlreadyDeclared(const SymbolTable *current_table, char *lex_value, int lineno)
{
    if (current_table == NULL)
    {
        printf("Error: Scope is uninitialized.\n");
        exit(-1);
    }

    TableData *symbol = find_symbol(current_table, lex_value);
    if (symbol != NULL)
    {
        printf("SEMANTIC ERROR: Attempted to declare symbol '%s' in line %d, but it is already declared in line %d.\n",
               lex_value, lineno, symbol->line_number);

        exit(ERR_DECLARED);
    }
}

void isUndeclared(const Stack *stack, char *lex_value, int lineno)
{
    if (stack == NULL || stack->tables == NULL)
    {
        printf("Error: Stack is uninitialized.\n");
        exit(-1);
    }

    for (size_t i = 0; i < stack->size; i++)
    {
        SymbolTable *table = peek_stack(stack, stack->size - i);

        if (table != NULL)
        {
            TableData *symbol = find_symbol(table, lex_value);
            if (symbol != NULL)
            {
                return;
            }
        }
    }
    printf("SEMANTIC ERROR: Attempted attribution operation with undeclared symbol '%s' in line %d.\n",
           lex_value, lineno);
    exit(ERR_UNDECLARED);
}

void isKindCorrect(const Stack *stack, char *lex_value, Kind kind, int lineno)
{
    if (stack == NULL || stack->tables == NULL)
    {
        printf("Error: Stack is uninitialized.\n");
        exit(-1);
    }

    for (size_t i = 0; i < stack->size; i++)
    {
        SymbolTable *table = peek_stack(stack, stack->size - i);

        if (table != NULL)
        {
            TableData *symbol = find_symbol(table, lex_value);
            if (symbol != NULL)
            {
                if (kind == symbol->value_type)
                {
                    return;
                }

                else
                {
                    if (kind == IDENTIFIER && symbol->value_type == FUNCTION)
                    {
                        printf("SEMANTIC ERROR: Attempted to use function '%s' as a variable in line %d.\n", lex_value, lineno);
                        exit(ERR_FUNCTION);
                    }
                    if (kind == FUNCTION && symbol->value_type == IDENTIFIER)
                    {
                        printf("SEMANTIC ERROR: Attempted to use variable '%s' as a function in line %d.\n", lex_value, lineno);
                        exit(ERR_VARIABLE);
                    }
                }
            }
        }
    }
}
