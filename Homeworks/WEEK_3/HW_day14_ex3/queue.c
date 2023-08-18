#include "queue.h"

void init_queue(Queue* queue) {
    queue->front = queue->rear = -1;
}

_Bool q_is_empty(Queue* queue) {
    return queue->front == -1;
}

_Bool q_is_full(Queue* queue) {
    return (queue->rear + 1) % QUEUE_SIZE == queue->front;
}

void enqueue(Queue* queue, int value) {
    if (q_is_full(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (q_is_empty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    }
    queue->data[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (q_is_empty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % QUEUE_SIZE;
    }
    return value;
}