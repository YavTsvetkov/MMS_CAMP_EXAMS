#include "stack.h"

void init_stack(Stack* stack) {
    stack->top = -1;
}

_Bool stack_is_empty(Stack* stack) {
    if (stack->top == -1)
        return 1;
    else 
        return 0;
}

_Bool stack_is_full(Stack* stack) {
    if (stack->top == STACK_SIZE - 1)
        return 1;
    else 
        return 0;
}

void push(Stack* stack, int value) {
    if (stack_is_full(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    if (stack_is_empty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->data[stack->top--];
}
