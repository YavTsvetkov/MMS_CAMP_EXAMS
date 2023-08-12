#include <stdio.h>
#include <stdint.h>

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*));
int cmpInt(const void* a, const void* b);
int cmpDouble(const void* a, const void* b);

int main(void)
{
    int arr[] = {1,2,-1,3,5,11,12,13,2,100,22};
	int* max = findMax(arr, sizeof(arr)/sizeof(int), sizeof(int), cmpInt);
	printf("%d\n", *max);

    double arr_d[] = {0, 1.33, -2.432, 4.23, 7.574, - 9.34};
	double* max_d = findMax(arr_d, sizeof(arr_d)/sizeof(double), sizeof(double), cmpDouble);
	printf("%lf\n", *max_d);

	return 0;
}

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*))
{
    void *max_el = arr;               
    for(size_t i = 0; i < n; i++)
    {   
        arr = (char*)arr + elem_s; 

        if (cmp(max_el, arr) == 1){
            max_el = arr;
        }
    }

    return max_el;
}

int cmpInt(const void* a,const void* b) {
	return *(int*)a > *(int*)b ? -1 : 1;
}

int cmpDouble(const void* a, const void* b) {
	return *(double*)a > *(double*)b ? -1 : 1;
}