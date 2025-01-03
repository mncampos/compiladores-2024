#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "iloc.h"

typedef struct iloc_list {
    Instruction* instruction;
    struct iloc_list* next;
} InstructionList;

InstructionList* new_list();
InstructionList* add_instruction(InstructionList* list, Instruction* instruction);
InstructionList* copy_list(InstructionList* destination, InstructionList* source);

void free_list(InstructionList* list);
void print_list(InstructionList* list);

#endif //LINKED_LIST_H