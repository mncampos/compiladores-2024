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

    return stack->tables[--stack->size];
}

SymbolTable *peek_stack(const Stack *stack, unsigned short level)
{
    if (stack->size == 0 || level == 0 || level > stack->size)
    {
        return NULL;
    }

    return stack->tables[stack->size - level];
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

void isAlreadyDeclared(const Stack *stack, char *lex_value, int lineno)
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
                if (i == 0)
                {
                    printf("SEMANTIC ERROR: Attempted to declare symbol '%s' in line %d, but it is already declared in line %d (global scope).\n",
                           lex_value, lineno, symbol->line_number);
                }
                else
                {
                    printf("Attempted to declare symbol '%s' in line %d, but it is already declared in line %d (nested scope level %zu).\n",
                           lex_value, lineno, symbol->line_number, i + 1);
                }
                exit(ERR_DECLARED);
            }
        }
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
                        printf("SEMANTIC ERROR: Attempted to use variable '%s' as a function in line %d.\n", lex_value, lineno);
                        exit(ERR_VARIABLE);
                    }
                    if (kind == FUNCTION && symbol->value_type == IDENTIFIER)
                    {
                        printf("SEMANTIC ERROR: Attempted to use function '%s' as a variable in line %d.\n", lex_value, lineno);
                        exit(ERR_FUNCTION);
                    }
                }
            }
        }
    }
}
