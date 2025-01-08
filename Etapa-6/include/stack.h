#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdlib.h>
#include "symbol_table.h" 

#define ERR_UNDECLARED 10 //2.3
#define ERR_DECLARED 11 //2.3
#define ERR_VARIABLE 20 //2.4
#define ERR_FUNCTION 21 //2.4

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
TableData* find_stack_symbol(const Stack* stack, const char* lex_value);


//Error handling
void isAlreadyDeclared(const SymbolTable *current_table, char *lex_value, int lineno);
void isUndeclared(const Stack* stack, char* lex_value, int lineno);
void isKindCorrect(const Stack* stack,char* lex_value,  Kind kind, int lineno);
TableData *find_register(Stack *stack, char *lex_value);
void print_all_tables(const Stack* stack);


#endif //STACK_H
