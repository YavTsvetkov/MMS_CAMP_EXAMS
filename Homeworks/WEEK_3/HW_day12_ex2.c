#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void resizeArr(float **nums, size_t size);
void initArr(float *nums, size_t size, size_t expanssionAmount, int step);
void printArr(float *nums, size_t size);

int main()
{
    float* nums = NULL;

    size_t size = 0;
    size_t n = 0, i = 0;
    while(i < 3){
        printf("Enter a number of elements to expand the array by: \n");
        scanf("%ld", &n);
        size += n;
        resizeArr(&nums, size);
        initArr(nums, size, n, i);
        i++;
    } 
    printArr(nums, size);

    return 0;
}

void resizeArr(float **nums, size_t size)
{
    if ((*nums = (float*)realloc(*nums, size*sizeof(float))) == NULL)
    {
        perror("Could not realloc!\n");
        exit(-1);
    }
}

void initArr(float *nums, size_t size, size_t expansionAmount, int step)
{
    size_t old_size = size - expansionAmount;
    srand(time(NULL));

    for (size_t i = old_size; i < size; i++)
    {
        nums[i] = step + (float)rand() / RAND_MAX;
    }
}

void printArr(float *nums, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        printf("arr[%ld] = %lf \n", i , nums[i]);
    }
}