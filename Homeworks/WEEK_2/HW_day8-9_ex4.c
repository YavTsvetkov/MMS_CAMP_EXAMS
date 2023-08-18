#include <stdio.h>
#include <stdint.h>

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index);
int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index);
int checkBits(uint32_t* maskArr, size_t nitems, size_t bit_index);
void printBinary(uint32_t* maskArr, size_t nitems);

int main(void)
{
    uint32_t maskArr[] = {0xFFFFFFFF, 0xAAAAAAAA, 0x55555555};
    size_t nitems = sizeof(maskArr) / sizeof(maskArr[0]);

    printBinary(maskArr, nitems);
    printf("\n");
    size_t bit_index_to_set = 5;
    int set_result = setBits(maskArr, nitems, bit_index_to_set);

    printBinary(maskArr, nitems);
    printf("\n");

    printf("Set bit %zu: %s\n", bit_index_to_set, set_result == 0 ? "Success" : "Failure");

    printf("\n");
    printBinary(maskArr, nitems);
    printf("\n");

    size_t bit_index_to_clear = 2;
    int clear_result = clearBits(maskArr, nitems, bit_index_to_clear);

    printBinary(maskArr, nitems);
    printf("\n");
    printf("Clear bit %zu: %s\n", bit_index_to_clear, clear_result == 0 ? "Success" : "Failure");

    return 0;
}

void printBinary(uint32_t* maskArr, size_t nitems) {
        int size = sizeof(maskArr[0]) * 8;
    for (size_t i = 0; i < nitems; i++) {
        uint32_t num = maskArr[i];

        for (int j = size - 1; j >= 0; j--) {
            uint32_t bit = (num >> j) & 1;
            printf("%u", bit);
        }

        printf("\n");
    }
}

int checkBits(uint32_t* maskArr, size_t nitems, size_t bit_index)
{
    int result = 0;
    for(size_t i = 0; i < nitems; i++)
    {
        if (!!(maskArr[i] & (1u << bit_index)))
        {
            if (i > 0 && result == 0)
                return -1;
            else
                result = 1;
        }
        else{
            if (i > 0 && result == 1)
                return -1;
        }
    }

    return result;
}

int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index)
{
    int result = 0;
    for(size_t i = 0; i < nitems; i++)
    {
       maskArr[i] = maskArr[i] | (1u << bit_index);
    }

    result = checkBits(maskArr, nitems, bit_index);

    return result == 1 ? 0 : -1;
}

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index)
{
    int result = 0;
    for(size_t i = 0; i < nitems; i++)
    {
        maskArr[i] = maskArr[i] & ~((1u << bit_index));
    }

    result = checkBits(maskArr, nitems, bit_index);

    return result == 0 ? 0 : -1;
}
