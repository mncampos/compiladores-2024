#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdlib.h>
#include "symbol_table.h" 

typedef struct stack {
    SymbolTable** tables; 
    size_t size;          
    size_t capacity;      
} Stack;

Stack* create_stack(size_t initial_capacity);
void free_stack(Stack* stack);
int push_stack(Stack* stack, SymbolTable* table);
SymbolTable* pop_stack(Stack* stack);
SymbolTable* peek_stack(const Stack* stack, unsigned short level);

#endif //STACK_H
