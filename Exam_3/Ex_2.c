#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct liked_list {
    Node* head;
} ll;

 void print(struct Node *cll);
 Node* insertAfter(Node *cll, int skipCount, int newElem);
 void freeList(Node *cll);

 size_t size = 0;

int main(int argc, char* argv[]){
    int N = 0;
    printf("Enter value for N: ");
    scanf("%d", &N);
    int nums[N];
    size = N;
    
    for (int i = 0; i < N; i++){
        scanf("%d", &nums[i]);
    }
 
    ll lli;
    lli.head = NULL;

    Node *head = lli.head;
    for(int i = 0; i < N; i++){
        Node *new_node = malloc(sizeof(Node));
        new_node->data = nums[i];

        if(head == NULL)
        {
            head = new_node;
            lli.head = head;
        }
        else
        {
            head->next = new_node;
            head = head->next;
        }
    }
    head->next = lli.head;

    print(lli.head);

    printf("\n\n ------------------- \n\n");

    insertAfter(lli.head, 0, 69);
    print(lli.head);

    printf("\n\n ------------------- \n\n");

    freeList(lli.head);
}

void print(struct Node *cll)
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", cll->data);
        cll = cll->next;
    }   
}

Node* insertAfter(Node *cll, int skipCount, int newElem)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = newElem;

    if(skipCount < 0 || skipCount > 1000000){
        perror("Skipcount out of bounds\n");
        return new_node;
    }

    for(int i = 0; i < skipCount; i++)
    {
        cll = cll->next;
    }

    Node *temp = cll->next;
    cll->next = new_node;
    new_node->next = temp;
    size++;

    return new_node;
}

void freeList(Node *cll)
{
    for(int i = 0; i < size; i++)
    {
       Node* temp = cll;
        cll = cll->next;
        free(temp);
    }
}
