#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define COUNT 10

typedef struct {
    char title[150];
    char author[100];
    int pages;
    float price;
} Book;

void generate_random_data(Book* books, int count);
char* generateRandomCharArray(size_t min_size, size_t max_size);
void print_books(Book* books, int count);
int compare_titles_asc(const void* a, const void* b); 
int compare_titles_desc(const void* a, const void* b);
int compare_authors_asc(const void* a, const void* b);
int compare_authors_desc(const void* a, const void* b);
int compare_pages_asc(const void* a, const void* b);
int compare_pages_desc(const void* a, const void* b);
int compare_price_asc(const void* a, const void* b);
int compare_price_desc(const void* a, const void* b);

int main() {
    Book books[COUNT];
    generate_random_data(books, COUNT);

    qsort(books, COUNT, sizeof(Book), compare_titles_asc);
    printf("\n --- Sorted by Title (Ascending): --- \n");
    print_books(books, COUNT);

    qsort(books, COUNT, sizeof(Book), compare_titles_desc);
    printf("\n --- Sorted by Title (Descending): --- \n");
    print_books(books, COUNT);

    qsort(books, COUNT, sizeof(Book), compare_authors_asc);
    printf("\n --- Sorted by Author (Ascending): --- \n");
    print_books(books, COUNT);

    qsort(books, COUNT, sizeof(Book), compare_authors_desc);
    printf("\n --- Sorted by Author (Descending): --- \n");
    print_books(books, COUNT);

    qsort(books, COUNT, sizeof(Book), compare_pages_asc);
    printf("\n --- Sorted by Pages (Ascending): --- \n");
    print_books(books, COUNT);

    qsort(books, COUNT, sizeof(Book), compare_pages_desc);
    printf("\n --- Sorted by Pages (Descending): --- \n");
    print_books(books, COUNT);

    qsort(books, COUNT, sizeof(Book), compare_price_asc);
    printf("\n --- Sorted by Price (Ascending): --- \n");
    print_books(books, COUNT);

    qsort(books, COUNT, sizeof(Book), compare_price_desc);
    printf("\n --- Sorted by Price (Descending): --- \n");
    print_books(books, COUNT);

    return 0;
}

void generate_random_data(Book* books, int count) {
    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        strcpy(books[i].title, generateRandomCharArray(10, 20));
        strcpy(books[i].author, generateRandomCharArray(10, 20));
        
        books[i].pages =  5 + rand() % 1995;
        books[i].price = (100 + rand() % 100000) / 100.;
    }
}

char* generateRandomCharArray(size_t min_size, size_t max_size) {
    int size = rand() % (max_size - min_size + 1) + min_size;
    char* array = (char*)malloc((size + 1) * sizeof(char));
    
    if (array) {
        for (int i = 0; i < size; i++) {
            if (rand() % 2 == 0) {
                array[i] = 'a' + rand() % 26;
            } else {
                array[i] = 'A' + rand() % 26;
            }
        }
        array[size] = '\0';
    }
    
    return array;
}

void print_books(Book* books, int count) {
    for (int i = 0; i < count; i++) {
        printf("[Title]: %20s  ", books[i].title);
        printf("[Author]: %20s  ", books[i].author);
        printf("[Pages]: %4d  ", books[i].pages);
        printf("[Price]: %.2f \n", books[i].price);
    }
}

int compare_titles_asc(const void* a, const void* b) {
    return strcmp(((Book*)a)->title, ((Book*)b)->title);
}

int compare_titles_desc(const void* a, const void* b) {
    return strcmp(((Book*)b)->title, ((Book*)a)->title);
}

int compare_authors_asc(const void* a, const void* b) {
    return strcmp(((Book*)a)->author, ((Book*)b)->author);
}

int compare_authors_desc(const void* a, const void* b) {
    return strcmp(((Book*)b)->author, ((Book*)a)->author);
}

int compare_pages_asc(const void* a, const void* b) {
    return ((Book*)a)->pages - ((Book*)b)->pages;
}

int compare_pages_desc(const void* a, const void* b) {
    return ((Book*)b)->pages - ((Book*)a)->pages;
}

int compare_price_asc(const void* a, const void* b) {
    return ((Book*)a)->price - ((Book*)b)->price;
}

int compare_price_desc(const void* a, const void* b) {
    return ((Book*)b)->price - ((Book*)a)->price;
}