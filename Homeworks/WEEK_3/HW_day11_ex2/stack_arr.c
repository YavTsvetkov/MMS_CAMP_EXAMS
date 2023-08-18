#include "stack_arr.h"
#include <stdlib.h>
#include <limits.h>

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

_Bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

int peek(Stack* stack) {
    if(!isEmpty(stack))
        return stack->array[stack->top];
    else
        return INT_MIN;
}

int pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return CHAR_MIN;
}

void push(Stack* stack, int op) {
    stack->array[++stack->top] = op;
}

void destroyStack(Stack* stack) {
    if (stack) {
        free(stack->array);
        free(stack);
    }
}