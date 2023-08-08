#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define PROD_COUNT 40

char *product_names[] = {"pasta", "cheese", "tomato", "lasanga", "chicken", 
                    "rise", "bacon"};

typedef struct Product
{
     double old_price; // 8
     double new_price; // 8
     unsigned int id; // 4         
     char product_type; // 1
     char product_name[11]; // 11
} Product;

void genRandomProducts(Product* prods);
void printProds(Product* prods);

int main()
{
    Product prods[40];
    genRandomProducts(prods);
    printProds(prods);
    return 0;
}

void genRandomProducts(Product* prods)
{
    for (size_t i = 0; i < PROD_COUNT; i++){ 
        prods[i].id = i;
        prods[i].product_type = 'A' + rand() % 4;
        prods[i].new_price = ((rand() % 10045) + 499)/100.;
        prods[i].old_price = ((rand() % 10045) + 499)/100.;
        strcpy(prods[i].product_name, product_names[rand()%7]);  // 0 - 6 elements
    }
}

void printProds(Product* prods){
     for (size_t i = 0; i < PROD_COUNT; i++){ 
        printf("[id]: %d [product_type]: %c [product_name]: %s [new_price]: %lf [old_price]: %lf\n",
        prods[i].id, prods[i].product_type, prods[i].product_name, prods[i].new_price, prods[i].old_price);
     }
}