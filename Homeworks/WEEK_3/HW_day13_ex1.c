#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 50

struct Node
{
    int num;
    struct Node *previuos;
    struct Node *next;
};

typedef struct Node Node;

typedef struct queue
{
    Node* head;
    Node* tail;

} De_queue;

void push_front(De_queue*, int num);
void push_back(De_queue*, int num);
int pop_front(De_queue**);
int pop_back(De_queue**);
void init_de_queue(De_queue**);
void print_queue(De_queue*);
void de_init_queue(De_queue*);

int main(void) {
    De_queue *q_ptr = NULL;
    init_de_queue(&q_ptr);

    printf("Pushing elements to the front of the deque:\n");
    push_front(q_ptr, 10);
    push_front(q_ptr, 20);
    push_front(q_ptr, 30);

    print_queue(q_ptr);

    printf("\nPushing elements to the back of the deque:\n");
    push_back(q_ptr, 40);
    push_back(q_ptr, 50);
    push_back(q_ptr, 60);

    print_queue(q_ptr);

    printf("\nPopping elements from the front of the deque:\n");
    printf("Popped: %d \n", pop_front(&q_ptr));
    printf("Popped: %d \n", pop_front(&q_ptr));

    print_queue(q_ptr);

    printf("\nPopping elements from the back of the deque:\n");
    printf("Popped: %d \n", pop_back(&q_ptr));
    printf("Popped: %d \n", pop_back(&q_ptr));
    printf("Popped: %d \n", pop_back(&q_ptr));
    printf("Popped: %d \n", pop_back(&q_ptr));

    print_queue(q_ptr);
    de_init_queue(q_ptr);

    return 0;
}

void init_de_queue(De_queue **q){
    *q = malloc(sizeof(De_queue));
    (*q)->head = NULL;
    (*q)->tail = NULL;
}

void push_front(De_queue *q, int num){
    Node *new_node = malloc(sizeof(Node));
    new_node->num = num;
    new_node->next = NULL;
    new_node->previuos = NULL;

    if(q->head == NULL) //Empty queue
    {
        q->head = new_node;
        q->tail = new_node;
    } 
    else{
        Node *temp = q->head;
        q->head = new_node;
        q->head->next = temp;
        q->head->previuos = NULL;
        temp->previuos = q->head;
    }
}

void push_back(De_queue *q, int num){
  Node *new_node = malloc(sizeof(Node));
    new_node->num = num;
    new_node->next = NULL;
    new_node->previuos = NULL;

    if(q->tail == NULL) //Empty queue
    {
        q->head = new_node;
        q->tail = new_node;
    } 
    else{
        Node *temp = q->tail;
        q->tail = new_node;
        q->tail->next = NULL;

        q->tail->previuos = temp;
        temp->next = q->tail;
    }
}

int pop_front(De_queue **q){

if((*q)->head == NULL) // EMPTY
{
    perror("Trying to pop from empty queue!");
    exit(-1);
}
else if((*q)->tail == (*q)->head) // ONE ELEM
{
    int data = (*q)->head->num;
    free((*q)->head);
    (*q) = NULL;
    return data;
}
else{
    Node* temp = (*q)->head;
    int data = temp->num;
    (*q)->head = (*q)->head->next;
    free(temp);
    (*q)->head->previuos = NULL;
    return data;
}
}

int pop_back(De_queue **q){

if((*q)->tail == NULL)
{
    perror("Trying to pop from empty queue!");
    exit(-1);
}
else if((*q)->tail == (*q)->head) // ONE ELEM
{
    int data = (*q)->tail->num;
    free((*q)->tail);
    (*q) = NULL;
    return data;
}
else{
    Node* temp = (*q)->tail;
    int data = temp->num;
    (*q)->tail = (*q)->tail->previuos;
    free(temp);
    (*q)->tail->next = NULL;
    return data;
}
}

void print_queue(De_queue *q)
{
    if(q != NULL){
        De_queue temp_q = *q;
        while(temp_q.head != NULL)
        {
            printf("%d ", temp_q.head->num);
            temp_q.head = temp_q.head->next;
        }
        printf("\n");
    }
}

void de_init_queue(De_queue *q)
{
    if(q != NULL){
        if(q->head == q->tail){
            free(q->head);
        } 
        else{
            free(q->head);
            free(q->tail);
        }
    }
}

