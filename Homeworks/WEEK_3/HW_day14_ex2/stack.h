#include "linkedlist.h"

#ifndef STACK_H
#define STACK_H 
 
typedef LL Stack;

Stack* init_stack()
{
   return init_linked_list();
}

void push(Data new_elem, Stack *stack){
    push_front(new_elem, stack);
}

void pop(Data* new_elem, Stack *stack){
    pop_front(stack, new_elem);
}

void print_stack(Stack *stack)
{
    print_linked_list(stack);
}

void deinit_stack(Stack *stack){
    deinit_linked_list(stack);
}

#endif
