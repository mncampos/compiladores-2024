#ifndef ILOC_H
#define ILOC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* mnemonic;
    char* first_arg;
    char* second_arg;
    char* third_arg;
} Instruction;

Instruction* new_instruction(char* mnemonico, char* arg1, char* arg2, char* arg3);
Instruction* copy_instruction(Instruction* instruction);
void print_instruction(Instruction* instruction);
char* create_label();
char* create_temporary();
char* unary_instruction(char* op);
char* binary_instruction(char* op);
char* get_constant(char* op);
void free_instruction(Instruction *instruction);

#endif // ILOC_H