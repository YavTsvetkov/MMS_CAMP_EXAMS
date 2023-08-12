#include <stdio.h>

#define MAX(x, y, z) ((x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z))

#define MIN(x, y, z) ((x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z))

#define SETBIT(mask, bit) ((mask) |= (1 << (bit)))

#define CLEARBIT(mask, bit) ((mask) &= ~(1 << (bit)))

#define INVERSEBIT(mask, bit) ((mask) ^= (1 << (bit)))

#define CHECKBIT(mask, bit) (((mask) >> (bit)) & 1)

#define SWAP(a, b) (a) ^= (b); (b) ^= (a); (a) ^= (b);

int main() {
    int x = 5, y = 9, z = 3;
    
    printf("Max of %d, %d, %d: %d\n", x, y, z, MAX(x, y, z));
    printf("Min of %d, %d, %d: %d\n", x, y, z, MIN(x, y, z));

    unsigned int mask = 0b0000101;
    printf("Original mask: 0x%X\n", mask);

    SETBIT(mask, 3);
    printf("After SETBIT(2): 0x%X\n", mask);

    CLEARBIT(mask, 3);
    printf("After CLEARBIT(5): 0x%X\n", mask);

    INVERSEBIT(mask, 1);
    printf("After INVERSEBIT(1): 0x%X\n", mask);

    printf("CHECKBIT(3): %d\n", CHECKBIT(mask, 3));

    int a = 7, b = 13;
    printf("Before SWAP: a = %d, b = %d\n", a, b);
    SWAP(a, b);
    printf("After SWAP: a = %d, b = %d\n", a, b);

    return 0;
}
