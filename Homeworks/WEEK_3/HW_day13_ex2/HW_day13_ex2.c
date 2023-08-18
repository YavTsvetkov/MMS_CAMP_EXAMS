#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "linked_list.h"

#define COUNT 10

void gen_book_list(LL* list, int count);
void init_book_random(Book *b);
char* gen_rand_str(size_t min_len, size_t max_len); 
void bubbleSort(LL* ll);
void swapNodes(Node* head, Node** node1, Node** node2);

int main(void)
{
   LL* books_list = init_linked_list();
   gen_book_list(books_list, COUNT);
   print_books_list(books_list);
   printf("\n\n ----------------------------------------- \n\n");
   bubbleSort(books_list);
   print_books_list(books_list);

    // node->d.author -> FREE
    // node->d.heading -> FREE

    return 0;
}

void gen_book_list(LL* list, int count)
{
    for(size_t i = 0; i < count; i++){
        Book new_book;
        init_book_random(&new_book);
        push_front(new_book, list);
    }
}

void init_book_random(Book *b){
    strcpy(b->author, gen_rand_str(10, 20));
    strcpy(b->heading, gen_rand_str(10, 20));
    b->pages = rand() % 2001 + 5;
    b->price = ((float)rand() / RAND_MAX) * 1000.0;
}

char* gen_rand_str(size_t min_len, size_t max_len) {

    int size = rand() % (max_len - min_len + 1) + min_len;
    char* str = (char*)malloc((size + 1) * sizeof(char));
    
        for (int i = 0; i < size; i++) {
            if (rand() % 2 == 0) {
                str[i] = 'a' + rand() % 26;
            } else {
                str[i] = 'A' + rand() % 26;
            }
        }
        str[size] = '\0';
        return str;
}

                            //current     curre->next
void swapNodes(Node* head, Node** node1, Node** node2)
{
    if(*node1 == *node2)
        return;
    
    Node *node1_prev = head;
    while(node1_prev->next != *node1)
    {
        node1_prev = node1_prev->next;
    }

    struct Node* temp = (*node2)->next;
    (*node2)->next = (*node1)->next;
    node1_prev->next = *node2;
    *node1 = *node2;

}


// void swapNodes(struct Node** head, struct Node* node1, struct Node* node2) {
//     if (node1 == node2)
//         return; 
    
//     struct Node* prev1 = NULL;
//     struct Node* curr1 = *head;

//     while (curr1 != NULL && curr1 != node1) {
//         prev1 = curr1;
//         curr1 = curr1->next;
//     }
    
//     struct Node* prev2 = NULL;
//     struct Node* curr2 = *head;

//     while (curr2 != NULL && curr2 != node2) {
//         prev2 = curr2;
//         curr2 = curr2->next;
//     }
    
//     if (curr1 == NULL || curr2 == NULL) {
//         return;
//     }
    
//     if (prev1 != NULL) {
//         prev1->next = curr2;
//     } else {
//         *head = curr2;
//     }
    
//     if (prev2 != NULL) {
//         prev2->next = curr1;
//     } else {
//         *head = curr1;
//     }
    
//     struct Node* temp = curr2->next;
//     curr2->next = curr1->next;
//     curr1->next = temp;
// }
  
// An optimized version of Bubble Sort
void bubbleSort(LL* ll)
{
    Node* head = ll->head;
    size_t count = COUNT; // Assuming COUNT is the number of nodes in the linked list
    
    for(size_t i = 0; i < count; i++)
    {
        Node* current = head; // Use a separate pointer to traverse the linked list
        while(current->next != NULL){
            if (strcmp(current->d.heading, current->next->d.heading) == -1)
            {
                swapNodes(&(ll->head), current, current->next);
            }
            
            current = current->next;
        }
    }
}
    