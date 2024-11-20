#include "../include/stack.h"

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

// Free the stack
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

SymbolTable* peek_stack(const Stack* stack, unsigned short level) {
    if (stack->size == 0 || level == 0 || level > stack->size) {
        return NULL;
    }

    return stack->tables[stack->size - level];
}