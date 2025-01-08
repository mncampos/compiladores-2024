#include "assembly.h"

char *get_asm_code(char *iloc_mnemonic)
{
    static MnemonicMap map[] = {
        {"sub", "subl"},
        {"add", "addl"},
        {"mult", "imul"},
        {"cmp_LE", "setle"},
        {"cmp_EQ", "sete"},
        {"cmp_LT", "setl"},
        {"cmp_GT", "setg"},
        {"cmp_GE", "setge"},
        {"cmp_NE", "setne"}};

    static size_t map_size = sizeof(map) / sizeof(map[0]);

    for (int i = 0; i < map_size; ++i)
    {
        if (strcmp(iloc_mnemonic, map[i].iloc_mnemonic) == 0)
        {
            return map[i].asm_code;
        }
    }

    fprintf(stderr, "Mnemônico iloc %s inválido - não encontrado um asm equivalente.\n", iloc_mnemonic);
    exit(1);
}

InstructionList *generateAsm(InstructionList *iloc_list, Stack *table_stack)
{
    InstructionList *asm_instruction_list = new_list();
    InstructionList *current = iloc_list;
    while (current != NULL)
    {
        translate_iloc(current->instruction, asm_instruction_list, table_stack);
        current = current->next;
    }
    return asm_instruction_list;
}

char *add_dollar_symbol(char *index)
{
    size_t len = strlen("$") + strlen(index) + 1;
    char *new = malloc(len);
    strcpy(new, "$");
    strcat(new, index);
    return new;
}

void translate_iloc_cmp(Instruction *iloc_op, InstructionList *assembly_instruction_list, Stack *table_stack)
{
    if (strcmp(iloc_op->mnemonic, "cmp_GE") == 0 || strcmp(iloc_op->mnemonic, "cmp_LE") == 0 || strcmp(iloc_op->mnemonic, "cmp_GT") == 0 || strcmp(iloc_op->mnemonic, "cmp_LT") == 0 || strcmp(iloc_op->mnemonic, "cmp_NE") == 0 || strcmp(iloc_op->mnemonic, "cmp_EQ") == 0)
    {
        TableData *data = find_stack_symbol(table_stack, iloc_op->first_arg);
        char *str1 = get_offset(data->offset);
        TableData *data2 = find_stack_symbol(table_stack, iloc_op->second_arg);
        char *str2 = get_offset(data2->offset);
        TableData *data3 = find_register(table_stack, iloc_op->third_arg);
        char *str3 = get_offset(data3->offset);

        add_instruction(assembly_instruction_list, new_instruction("movl", str1, "%ebx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("cmpl", str2, "%ebx", NULL));
        add_instruction(assembly_instruction_list, new_instruction(get_asm_code(iloc_op->mnemonic), "%al", NULL, NULL));
        add_instruction(assembly_instruction_list, new_instruction("movzbl", "%al", "%ebx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("movl", "%ebx", str3, NULL));
        free(str1);
        free(str2);
        free(str3);
    }
    if (strcmp(iloc_op->mnemonic, "and") == 0 || strcmp(iloc_op->mnemonic, "or") == 0)
    {
        TableData *data = find_stack_symbol(table_stack, iloc_op->first_arg);
        char *str1 = get_offset(data->offset);
        TableData *data2 = find_stack_symbol(table_stack, iloc_op->second_arg);
        char *str2 = get_offset(data2->offset);
        TableData *data3 = find_register(table_stack, iloc_op->third_arg);
        char *str3 = get_offset(data3->offset);
        char *label1 = create_label();
        char *label2 = create_label();

        add_instruction(assembly_instruction_list, new_instruction("cmpl", !strcmp(iloc_op->mnemonic, "and") ? "$0" : "$1", str1, NULL));
        add_instruction(assembly_instruction_list, new_instruction("je", label1, "%ebx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("cmpl", !strcmp(iloc_op->mnemonic, "and") ? "$0" : "$1", str2, NULL));
        add_instruction(assembly_instruction_list, new_instruction("je", label1, "%ebx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("movl", !strcmp(iloc_op->mnemonic, "and") ? "$0" : "$1", str3, NULL));
        add_instruction(assembly_instruction_list, new_instruction("jmp", label2, NULL, NULL));
        add_instruction(assembly_instruction_list, new_instruction("label", label1, NULL, NULL));
        add_instruction(assembly_instruction_list, new_instruction("movl", !strcmp(iloc_op->mnemonic, "and") ? "$0" : "$1", str3, NULL));
        add_instruction(assembly_instruction_list, new_instruction("label", label2, NULL, NULL));

        free(str1);
        free(str2);
        free(str3);
        free(label1);
        free(label2);
    }
    if (strcmp(iloc_op->mnemonic, "jumpI") == 0)
    {
        add_instruction(assembly_instruction_list, new_instruction("jmp", iloc_op->first_arg, NULL, NULL));
    }
    else if (strcmp(iloc_op->mnemonic, "label") == 0)
    {
        add_instruction(assembly_instruction_list, new_instruction("label", iloc_op->first_arg, NULL, NULL));
    }
    else if (strcmp(iloc_op->mnemonic, "cbr") == 0)
    {
        TableData *data = find_stack_symbol(table_stack, iloc_op->first_arg);
        char *str1 = get_offset(data->offset);

        add_instruction(assembly_instruction_list, new_instruction("cmpl", "$0", str1, NULL));
        add_instruction(assembly_instruction_list, new_instruction("je", iloc_op->third_arg, NULL, NULL));
        add_instruction(assembly_instruction_list, new_instruction("jmp", iloc_op->second_arg, NULL, NULL));
        free(str1);
    }
}

void translate_iloc_arithmetic(Instruction *iloc_op, InstructionList *assembly_instruction_list, Stack *table_stack)
{
    if (strcmp(iloc_op->mnemonic, "add") == 0 || strcmp(iloc_op->mnemonic, "sub") == 0 || strcmp(iloc_op->mnemonic, "mult") == 0)
    {
        TableData *data = find_stack_symbol(table_stack, iloc_op->first_arg);
        char *str1 = get_offset(data->offset);
        TableData *data2 = find_stack_symbol(table_stack, iloc_op->second_arg);
        char *str2 = get_offset(data2->offset);
        TableData *data3 = find_register(table_stack, iloc_op->third_arg);
        char *str3 = get_offset(data3->offset);

        add_instruction(assembly_instruction_list, new_instruction("movl", str1, "%ebx", NULL));
        add_instruction(assembly_instruction_list, new_instruction(get_asm_code(iloc_op->mnemonic), str2, "%ebx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("movl", "%ebx", str3, NULL));
        free(str1);
        free(str2);
        free(str3);
    }
    if (strcmp(iloc_op->mnemonic, "div") == 0)
    {
        TableData *data = find_stack_symbol(table_stack, iloc_op->first_arg);
        char *str1 = get_offset(data->offset);
        TableData *data2 = find_stack_symbol(table_stack, iloc_op->second_arg);
        char *str2 = get_offset(data2->offset);
        TableData *data3 = find_register(table_stack, iloc_op->third_arg);
        char *str3 = get_offset(data3->offset);

        add_instruction(assembly_instruction_list, new_instruction("movl", str1, "%eax", NULL));
        add_instruction(assembly_instruction_list, new_instruction("cltd", NULL, NULL, NULL));
        add_instruction(assembly_instruction_list, new_instruction("idivl", str2, NULL, NULL));
        add_instruction(assembly_instruction_list, new_instruction("movl", "%eax", str3, NULL));
        free(str1);
        free(str2);
        free(str3);
    }
    else
        translate_iloc_cmp(iloc_op, assembly_instruction_list, table_stack);
}

void translate_iloc(Instruction *iloc_op, InstructionList *assembly_instruction_list, Stack *table_stack)
{

    if (strcmp(iloc_op->mnemonic, "loadI") == 0)
    {
        TableData *data = find_register(table_stack, iloc_op->second_arg);
        char *str1 = add_dollar_symbol(iloc_op->first_arg);
        char *str2 = (char *)get_offset(data->offset);
        add_instruction(assembly_instruction_list, new_instruction("movl", str1, str2, NULL));
        free(str1);
        free(str2);
    }
    else if (strcmp(iloc_op->mnemonic, "loadAO") == 0)
    {
        TableData *data = find_register(table_stack, iloc_op->first_arg);
        char *str1 = get_offset(data->offset);
        TableData *data2 = find_register(table_stack, iloc_op->third_arg);

        char *str2 = get_offset(data2->offset);
        add_instruction(assembly_instruction_list, new_instruction("movslq", str1, "%rbx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("movq", "%rbp", "%rdx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("subq", "%rbx", "%rdx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("movl", "(%rdx)", "%ebx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("movl", "%ebx", str2, NULL));
        free(str1);
        free(str2);
    }
    else if (strcmp(iloc_op->mnemonic, "storeAO") == 0)
    {
        TableData *data = find_register(table_stack, iloc_op->first_arg);
        char *str1 = get_offset(data->offset);
        TableData *data2 = find_register(table_stack, iloc_op->second_arg);
        char *str2 = get_offset(data2->offset);

        add_instruction(assembly_instruction_list, new_instruction("movslq", str2, "%rbx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("movq", "%rbp", "%rdx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("subq", "%rbx", "%rdx", NULL));
        add_instruction(assembly_instruction_list, new_instruction("movl", str1, "%eax", NULL));
        add_instruction(assembly_instruction_list, new_instruction("movl", "%eax", "(%rdx)", NULL));
        free(str1);
        free(str2);
    }
    else if (strcmp(iloc_op->mnemonic, "return") == 0)
    {
        TableData *data = find_stack_symbol(table_stack, iloc_op->first_arg);
        char *str1 = get_offset(data->offset);
        add_instruction(assembly_instruction_list, new_instruction("movl", str1, "%eax", NULL));
        free(str1);
    }
    else
        translate_iloc_arithmetic(iloc_op, assembly_instruction_list, table_stack);
}

char *get_offset(char *shift)
{
    size_t buffer_size = snprintf(NULL, 0, "-%s(%%rbp)", shift) + 1;
    char *res = malloc(buffer_size);
    if (res == NULL)
    {
        fprintf(stderr, "Falha ao alocar memória.\n");
        exit(1);
    }

    snprintf(res, buffer_size, "-%s(%%rbp)", shift);

    return res;
}

void print_asm_op(Instruction *op)
{
    if (strcmp(op->mnemonic, "label") == 0)
    {
        printf("%s:\n", op->first_arg);
        return;
    }

    printf("\t");

    if (strcmp(op->mnemonic, "cltd") == 0)
    {
        printf("%s", op->mnemonic);
    }
    else if (strcmp(op->mnemonic, "idivl") == 0 || strcmp(op->mnemonic, "setle") == 0 || strcmp(op->mnemonic, "setge") == 0 ||
             strcmp(op->mnemonic, "setg") == 0 || strcmp(op->mnemonic, "setl") == 0 || strcmp(op->mnemonic, "sete") == 0 ||
             strcmp(op->mnemonic, "setne") == 0 || strcmp(op->mnemonic, "je") == 0 || strcmp(op->mnemonic, "jmp") == 0)
    {
        printf("%s %s", op->mnemonic, op->first_arg);
    }
    else if (strcmp(op->mnemonic, "movl") == 0 || strcmp(op->mnemonic, "addl") == 0 || strcmp(op->mnemonic, "subl") == 0 ||
             strcmp(op->mnemonic, "imul") == 0 || strcmp(op->mnemonic, "cmpl") == 0 || strcmp(op->mnemonic, "movzbl") == 0 ||
             strcmp(op->mnemonic, "movslq") == 0 || strcmp(op->mnemonic, "addq") == 0 || strcmp(op->mnemonic, "subq") == 0 ||
             strcmp(op->mnemonic, "movq") == 0)
    {
        printf("%s %s, %s", op->mnemonic, op->first_arg, op->second_arg);
    }
    else
    {
        printf("Instrução desconhecida: %s\n", op->mnemonic);
    }

    printf("\n");
}

void print_asm_code(InstructionList *list)
{
    printf(".globl	main\n.type	main, @function\nmain:\n.LFB0:\n\tpushq	%%rbp\n\tmovq	%%rsp, %%rbp\n");
    while (list != NULL)
    {
        print_asm_op(list->instruction);
        list = list->next;
    }
    printf("\tpopq	%%rbp\n\tret\n");
}
