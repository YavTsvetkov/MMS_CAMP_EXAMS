#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[],
                    size_t* dest_cnt);

int isEven(int);
int isPrime(int);
int isPositive(int);
int getOnesCount(int);
int getNumSquared(int);
int emptyMap(int);

int main()
{
    int arr[] = {2,3,-12,-34,65,43,23,77,84};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int dest[n];
    size_t dest_cnt = 0;

    filter_and_map(arr, n, isEven, emptyMap, dest, &dest_cnt);

    for(int i = 0; i < dest_cnt; i++){
        printf("%d\n", dest[i]);
    }

    printf("-------------------------------------------------------\n");

    dest_cnt = 0;
    filter_and_map(arr, n, isPrime, getNumSquared, dest, &dest_cnt);

    for(int i = 0; i < dest_cnt; i++){
        printf("%d\n", dest[i]);
    }

    printf("-------------------------------------------------------\n");

    dest_cnt = 0;
    filter_and_map(arr, n, isPositive, getOnesCount, dest, &dest_cnt);

    for(int i = 0; i < dest_cnt; i++){
        printf("%d\n", dest[i]);
    }

    return 0;
}

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[],
                    size_t *dest_cnt)
                    {
                        for(int i = 0; i < n; i++)
                        {
                            if(filter_f(arr[i]))
                            {
                                dest[*dest_cnt] = map_f(arr[i]);
                                (*dest_cnt)++;
                            }
                        }
                    }

int isEven(int num)
{
    return (num % 2 == 0) ? 1 : 0;
}

int isPositive(int num)
{
    return (num > 0) ? 1 : 0;
}

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int emptyMap(int num)
{
    return num;
}

int getNumSquared(int num)
{
    return num * num;
}

int getOnesCount(int num)
{
    unsigned int mask = 1;
    int onesCount = 0;
    for(int i = 0; i < 8 * sizeof(int); i++)
    {
       onesCount += !!(num & (mask << i));
    }
    
    return onesCount;
}