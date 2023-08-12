#include "stack.h"
#include "stdio.h"
#include "stdlib.h"

int main(void){
    Stack *stack = init_stack();

    printf("Pushing elements: \n");
    for (int i = 1; i <= 5; i++) {
        Data d;
        d.val = i;
        printf("Push(%d)\n",d.val);
        push(d, stack);
    }

    printf("Stack elements: ");
    print_stack(stack);

    for (int i = 0; i < 3; i++) {
        Data popped_element;
        pop(&popped_element, stack);
        printf("Popped: %d\n", popped_element.val);
    }

    printf("Stack elements after popping: ");
    print_stack(stack);

    deinit_stack(stack);
}
