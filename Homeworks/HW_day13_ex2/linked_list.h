#include<stdio.h>
#include<stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H 1

typedef struct Book{
    char heading[150];
    char author[100];
    unsigned int pages;
    float price;
} Book;

typedef struct Node {
    Book d;
    struct Node *next;
} Node;

typedef struct LL {
    Node *head;
    Node *tail;
} LL;

void print_books_list(LL *ll);
void push_back(Book new_data, LL *ll);
void pop_back(LL *ll, Book *result);
void push_front(Book new_data, LL *ll);
void pop_front(LL *ll, Book *result);
LL* init_linked_list();
void deinit_linked_list(LL* ll);

#endif