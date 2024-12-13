#include "iloc.h"

Instruction *new_instruction(char *mnemonic, char *arg1, char *arg2, char *arg3)
{
    if (mnemonic == NULL)
    {
        fprintf(stderr, "Mnemonico não pode ser NULL.\n");
        return NULL;
    }

    Instruction *instruction = malloc(sizeof(Instruction));
    if (instruction == NULL)
    {
        perror("Falha ao alocar memória para a nova instrução.");
        return NULL;
    }

    instruction->mnemonic = strdup(mnemonic);
    if (instruction->mnemonic == NULL)
    {
        perror("Falha ao alocar memória para o mnemônico");
        free(instruction);
        return NULL;
    }

    instruction->first_arg = arg1 ? strdup(arg1) : NULL;
    if (arg1 && instruction->first_arg == NULL)
    {
        perror("Falha ao alocar memória para o first_arg");
        free(instruction->mnemonic);
        free(instruction);
        return NULL;
    }

    instruction->second_arg = arg2 ? strdup(arg2) : NULL;
    if (arg2 && instruction->second_arg == NULL)
    {
        perror("Falha ao alocar memória para o second_arg");
        free(instruction->first_arg);
        free(instruction->mnemonic);
        free(instruction);
        return NULL;
    }

    instruction->third_arg = arg3 ? strdup(arg3) : NULL;
    if (arg3 && instruction->third_arg == NULL)
    {
        perror("Falha ao alocar memória para o third_arg");
        free(instruction->second_arg);
        free(instruction->first_arg);
        free(instruction->mnemonic);
        free(instruction);
        return NULL;
    }

    return instruction;
}

void free_instruction(Instruction *instruction)
{
    if (instruction)
    {
        free(instruction->mnemonic);
        free(instruction->first_arg);
        free(instruction->second_arg);
        free(instruction->third_arg);
        free(instruction);
    }
}

Instruction *copy_instruction(Instruction *instruction)
{
    Instruction *inst = (Instruction *)malloc(sizeof(Instruction));
    if (inst == NULL)
    {
        perror("Falha ao alocar memória para a nova instrução.");
        return NULL;
    }

    if (instruction->mnemonic != NULL)
    {
        inst->mnemonic = strdup(instruction->mnemonic);
        if (inst->mnemonic == NULL)
        {
            perror("Falha ao duplicar o mnemonic da instrução.");
            free(inst);
            return NULL;
        }
    }

    if (instruction->first_arg != NULL)
    {
        inst->first_arg = strdup(instruction->first_arg);
        if (inst->first_arg == NULL)
        {
            perror("Falha ao duplicar o primeiro argumento da instrução.");
            free(inst->mnemonic);
            free(inst);
            return NULL;
        }
    }

    if (instruction->second_arg != NULL)
    {
        inst->second_arg = strdup(instruction->second_arg);
        if (inst->second_arg == NULL)
        {
            perror("Falha ao duplicar o segundo argumento da instrução.");
            free(inst->first_arg);
            free(inst->mnemonic);
            free(inst);
            return NULL;
        }
    }

    if (instruction->third_arg != NULL)
    {
        inst->third_arg = strdup(instruction->third_arg);
        if (inst->third_arg == NULL)
        {
            perror("Falha ao duplicar o terceiro argumento da instrução.");
            free(inst->second_arg);
            free(inst->first_arg);
            free(inst->mnemonic);
            free(inst);
            return NULL;
        }
    }

    return inst;
}

void print_instruction(Instruction *instruction)
{
    if (instruction == NULL || instruction->mnemonic == NULL)
    {
        fprintf(stderr, "Instrução não pode ser nula.\n");
        return;
    }

    const char *mnemonic = instruction->mnemonic;

    if (strcmp(mnemonic, "storeAI") == 0 || strcmp(mnemonic, "storeAO") == 0)
    {
        printf("%s %s => %s, %s", mnemonic, instruction->first_arg, instruction->second_arg, instruction->third_arg);
    }
    else if (strcmp(mnemonic, "loadAI") == 0 || strcmp(mnemonic, "loadAO") == 0)
    {
        printf("%s %s, %s => %s", mnemonic, instruction->first_arg, instruction->second_arg, instruction->third_arg);
    }
    else if (strcmp(mnemonic, "loadI") == 0)
    {
        printf("%s %s => %s", mnemonic, instruction->first_arg, instruction->second_arg);
    }
    else if (strcmp(mnemonic, "label") == 0)
    {
        printf("%s:", instruction->first_arg);
    }
    else if (strcmp(mnemonic, "cbr") == 0)
    {
        printf("%s %s => %s, %s", mnemonic, instruction->first_arg, instruction->second_arg, instruction->third_arg);
    }
    else if (strcmp(mnemonic, "jumpI") == 0)
    {
        printf("%s => %s", mnemonic, instruction->first_arg);
    }
    else if (
        strcmp(mnemonic, "add") == 0 ||
        strcmp(mnemonic, "sub") == 0 ||
        strcmp(mnemonic, "mult") == 0 ||
        strcmp(mnemonic, "div") == 0 ||
        strcmp(mnemonic, "cmp_EQ") == 0 ||
        strcmp(mnemonic, "cmp_NE") == 0 ||
        strcmp(mnemonic, "cmp_GE") == 0 ||
        strcmp(mnemonic, "cmp_LE") == 0 ||
        strcmp(mnemonic, "cmp_GT") == 0 ||
        strcmp(mnemonic, "cmp_LT") == 0 ||
        strcmp(mnemonic, "and") == 0 ||
        strcmp(mnemonic, "or") == 0)
    {
        printf("%s %s, %s => %s", mnemonic, instruction->first_arg, instruction->second_arg, instruction->third_arg);
    }
    else
    {
        fprintf(stderr, "Mnemonico desconhecidoc: %s\n", mnemonic);
    }

    printf("\n");
}

char *create_label()
{
    static int label_num = 0;

    int length = snprintf(NULL, 0, "L%d", label_num);

    if (length < 0)
    {
        return NULL;
    }

    char *label = malloc(length + 1);
    if (!label)
    {
        perror("Falha ao alocar memória para nova label.");
        return NULL;
    }

    snprintf(label, length + 1, "L%d", label_num);
    label_num++;
    return label;
}

char *create_temporary()
{
    static int temp_num = 0;

    int length = snprintf(NULL, 0, "r%d", temp_num);
    if (length < 0)
    {
        return NULL;
    }

    char *temp_name = malloc(length + 1);
    if (!temp_name)
    {
        perror("Falha ao alocar memória para novo temporário.");
        return NULL;
    }

    snprintf(temp_name, length + 1, "r%d", temp_num);
    temp_num++;
    return temp_name;
}

char *unary_instruction(char *op)
{
    if (!strcmp(op, "!"))
    {
        return "cmp_EQ";
    }
    if (!strcmp(op, "-"))
    {
        return "mult";
    }
    fprintf(stderr, "Operador unário inválido: %s\n", op);
    return NULL;
}

char *get_constant(char *op)
{
    if (!strcmp(op, "!"))
    {
        return "0";
    }
    if (!strcmp(op, "-"))
    {
        return "-1";
    }
    fprintf(stderr, "Constante inválida: %s\n", op);
    return NULL;
}

char *binary_instruction(char *op)
{
    if (!strcmp(op, "+"))
    {
        return "add";
    }
    if (!strcmp(op, "-"))
    {
        return "sub";
    }
    if (!strcmp(op, "*"))
    {
        return "mult";
    }
    if (!strcmp(op, "/"))
    {
        return "div";
    }
    if (!strcmp(op, "=="))
    {
        return "cmp_EQ";
    }
    if (!strcmp(op, "!="))
    {
        return "cmp_NE";
    }
    if (!strcmp(op, ">"))
    {
        return "cmp_GT";
    }
    if (!strcmp(op, "<"))
    {
        return "cmp_LT";
    }
    if (!strcmp(op, "<="))
    {
        return "cmp_LE";
    }
    if (!strcmp(op, ">="))
    {
        return "cmp_GE";
    }
    if (!strcmp(op, "&"))
    {
        return "and";
    }
    if (!strcmp(op, "|"))
    {
        return "or";
    }
    fprintf(stderr, "Operador binário inválido: %s\n", op);
    return NULL;
}
