#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include "iloc.h"
#include "symbol_table.h"
#include "stack.h"
#include "linked_list.h"
#include <string.h>
#include <stdlib.h>

typedef struct {
     char * iloc_mnemonic;
     char * asm_code;
} MnemonicMap;




 char * get_asm_code( char * iloc_mnemonic);
InstructionList * generateAsm(InstructionList *iloc_list, Stack * table);
void translate_iloc(Instruction * iloc_op, InstructionList * assembly_instruction_list, Stack * table );
char * get_offset( char * shift);
void print_asm_code(InstructionList * list);



#endif // ASSEMBLY_H