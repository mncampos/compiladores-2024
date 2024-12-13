#include "linked_list.h"

InstructionList *new_list()
{
    InstructionList *head = (InstructionList *)malloc(sizeof(InstructionList));
    if (head == NULL)
    {
        fprintf(stderr, "Falha ao alocar memória para nova lista. \n");
        return NULL;
    }
    head->next = NULL;
    head->instruction = NULL;
    return head;
}

InstructionList *add_instruction(InstructionList *list, Instruction *instruction)
{
    if (list == NULL || instruction == NULL)
    {
        fprintf(stderr, "Instrução ou lista não podem ser nulos.\n");
        return NULL;
    }

    if (list->instruction == NULL)
    {
        list->instruction = instruction;
    }
    else
    {
        InstructionList *current = list;
        while (current->next != NULL)
        {
            current = current->next;
        }

        InstructionList *new_node = new_list();
        if (new_node == NULL)
        {
            fprintf(stderr, "Falha ao alocar memória para nova lista de instruções.\n");
            return NULL;
        }

        new_node->instruction = instruction;
        new_node->next = NULL;
        current->next = new_node;
    }

    return list;
}

InstructionList *copy_list(InstructionList *destination, InstructionList *source)
{
    if (destination == NULL || source == NULL)
    {
        fprintf(stderr, "Lista de destino ou de origem são nulas.\n");
        return NULL;
    }

    InstructionList *current = destination;
    while (source != NULL)
    {
        Instruction *inst = copy_instruction(source->instruction);
        if (inst == NULL)
        {
            fprintf(stderr, "Falha ao copiar instrução.\n");
            return NULL;
        }

        current = add_instruction(current, inst);
        if (current == NULL)
        {
            fprintf(stderr, "Falha ao adicionar instrução na lista de destino.\n");
            return NULL;
        }

        source = source->next;
    }

    return destination;
}

void free_list(InstructionList *list)
{
    while (list != NULL)
    {
        InstructionList *next_node = list->next;

        if (list->instruction != NULL)
        {
            free_instruction(list->instruction);
        }

        free(list);

        list = next_node;
    }
}
void print_list(InstructionList *list)
{
    while (list != NULL)
    {
        print_instruction(list->instruction);
        list = list->next;
    }
}