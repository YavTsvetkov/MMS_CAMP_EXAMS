#ifndef STACK_H
#define STACK_H
#include <stdio.h>

#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

void init_stack(Stack* stack);
_Bool stack_is_empty(Stack* stack);
_Bool stack_is_full(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);

#endif
