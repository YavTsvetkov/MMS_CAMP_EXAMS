#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main() {
    Stack stack;
    init_stack(&stack);

    Queue queue;
    init_queue(&queue);

    printf("Pushed to stack: %d\n", 10);
    push(&stack, 10);
    printf("Enqueude in queue: %d\n", 20);
    enqueue(&queue, 20);

    printf("Popped from stack: %d\n", pop(&stack));
    printf("Dequeued from queue: %d\n", dequeue(&queue));

    return 0;
}