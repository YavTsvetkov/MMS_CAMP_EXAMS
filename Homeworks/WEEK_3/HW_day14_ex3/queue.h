#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>

#define QUEUE_SIZE 100

typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue* queue);
_Bool q_is_empty(Queue* queue);
_Bool q_is_full(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);

#endif
