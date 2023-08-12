#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[],
                    size_t* dest_cnt);

int isPositive(int);
int addOne(int);

int main()
{
    int arr[] = {2,3,-12,-34,65,43,23,77,84};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int dest[n];
    size_t dest_cnt = 0;

    filter_and_map(arr, n, isPositive, addOne, dest, &dest_cnt);

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

int isPositive(int num)
{
    return (num > 0) ? 1 : 0;
}

int addOne(int num)
{
    return ++num;
}