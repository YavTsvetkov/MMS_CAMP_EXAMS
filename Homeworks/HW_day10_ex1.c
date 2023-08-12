#include <stdio.h>
#include <stdint.h>
#include <string.h>

void swapBytes(uint16_t* word); 

int main(void)
{
    uint16_t word = 0xABCD;
    printf("%X\n", word);
    swapBytes(&word);
    printf("%X\n", word);
    return 0;
}

void swapBytes(uint16_t* word){
    char bytes[2];
    memcpy(bytes, word, 2);

    char swap = bytes[0];
    bytes[0] = bytes[1];
    bytes[1] = swap;

    memcpy(word, bytes, 2);
}