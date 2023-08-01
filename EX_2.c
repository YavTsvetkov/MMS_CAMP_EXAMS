#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct car{
    char model[20];
    uint8_t maxspeed;
    double price;
} Car;

int (*getComparator(int n))(const void*, const void*);
int cmp_brand_asc (const void*, const void*);
int cmp_brand_desc(const void*, const void*);
int cmp_speed_asc(const void*, const void*);
int cmp_speed_desc(const void*, const void*);
int cmp_price_desc(const void*, const void*);
int cmp_price_asc(const void*, const void*);

void init_Cars(Car* cars, size_t size);
char* car_brands[] = {"VW", "Ford", "Opel", "BMW", "Mazda", "Honda", "Seat", "Fiat", "Mini"};

int main(void)
{
    Car cars[10];
    int sort_func_id = 0;
    init_Cars(cars, 10);

    printf("Input sortig method 1-6: ");
    scanf("%d", &sort_func_id);

    int (*f_ptr)(const void*, const void*) = getComparator(sort_func_id);
    qsort(cars, 10, sizeof(Car), f_ptr);

    for(size_t i = 0; i < 10; i++)
    {
        printf("cars[%d] -> model[%s] -> maxspeed[%d] -> price[%lf]\n",
             i, cars[i].model, cars[i].maxspeed, cars[i].price);
    }

    return 0;
}

void init_Cars(Car* cars, size_t size)
{
    for(size_t i = 0 ; i < size; i++){
        // No idea why the line below doesn't work );
        // strcpy(&(cars[i].model), car_brands[rand() % 10]); 
        cars[i].maxspeed = 300 - (rand() % 201);
        cars[i].price = 50000.00; // make this random
    }
}

int (*getComparator(int n))(const void*, const void*){
    if(n==1) {
        return &cmp_brand_asc;
    }
    if(n==2) {
        return &cmp_brand_desc;
    }
    if(n==3) {
        return &cmp_speed_asc;
    }
    if(n==4) {
        return &cmp_speed_desc;
    }
    if(n==5) {
        return &cmp_price_asc;
    }
    if(n==6) {
        return &cmp_price_desc;
    }
}

int cmp_brand_asc(const void* c1, const void* c2){
    Car* car1 = c1;
    Car* car2 = c2;

    return strcmp(car1->model, car1->model);
}

int cmp_brand_desc(const void* c1, const void* c2){
    Car* car1 = c1;
    Car* car2 = c2;
    return strcmp(car1->model, car1->model) ? -1 : 1;
}

int cmp_speed_asc(const void* c1, const void* c2){
    Car* car1 = c1;
    Car* car2 = c2;
    return car1->maxspeed >= car2->maxspeed ? 1 : -1;
}

int cmp_speed_desc(const void* c1, const void* c2){
    Car* car1 = c1;
    Car* car2 = c2;
    return car1->maxspeed >= car2->maxspeed ? -1 : 1;
}

int cmp_price_desc(const void* c1, const void* c2){
    Car* car1 = c1;
    Car* car2 = c2;
    return car1->price >= car2->price ? -1 : 1;
}

int cmp_price_asc(const void* c1, const void* c2){
    Car* car1 = c1;
    Car* car2 = c2;
    return car1->price >= car2->price ? 1 : -1;
}