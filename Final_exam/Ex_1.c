#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<time.h>

#define ITEMS_COUNT 10

char random_char(int index);

char* valuts[] = {"USD", "BGN", "RUB", "EUR", "CAD"};

typedef struct BankAccount{
    uint16_t id;
    char owner[100];
    float balance;
    char valuta[5];
} BankAccount;

typedef struct node{
    BankAccount data;
    struct node* next;
}node;

void print_list(node* head);

node* create_new_node();

int main()
{
    node* head = NULL;

    for(int i = 0; i < ITEMS_COUNT; i++)
    {
        if (head == NULL)
        {
            head = create_new_node();
            head->next = NULL;
        }
        else {
            head->next = create_new_node();
            head->next->next = NULL;
        }
    }
    print_list(head);
    return 0;
}

node* create_new_node()
{
    static int id = 0;
    node* new_node = malloc(sizeof(node));
    new_node->data.id = id++;

    char final_str[101];
    final_str[0]= '\0';
    int words_count = 1 + rand() % 5;

    for (int i = 0; i < words_count; i++) { 
      int size = 1 + rand() % 20;
      char str[size];
      int j, index;
      for (j = 0; j < size-2; j++) {
        index = rand() % 53;
        str[j] = random_char(index);
      }
      str[j] = '\0';
      strcat(final_str, str);
    }

    strcpy( new_node->data.owner, final_str);
    new_node->data.balance = (rand() % 10000000)/100.;
    strcpy(new_node->data.valuta ,valuts[rand()%5]);

    new_node->next = NULL;

    return new_node;
}

char random_char(int index) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return charset[index];
}

void print_list(node* head){
    while(head != NULL){
        printf("id:%2d owner:%20s balance: %.2f currency: %5s\n", head->data.id, head->data.owner, 
                        head->data.balance, head->data.valuta );
        head = head->next;
    }   
}