#include <stdio.h>
#include <stdint.h>

#define TINT 0
#define TCHAR 1
#define TFLOAT 2
#define TUINT8 3
#define TUINT16 4
#define TUINT32 5
#define TUINT64 6

void printValue(const void* valuePtr, uint8_t flag);

int main()
{
    int i = 12;
    char c = 'B';
    float f = 2.67;
    uint8_t ui = 25;
    uint16_t _ui = 362;
    uint32_t ul = 73423; 
    uint64_t ull = 902341; 

    void* ptr = &i;
    printValue(ptr, TINT);

    ptr = &c;
    printValue(ptr, TCHAR);

    ptr = &f;
    printValue(ptr, TFLOAT);

    ptr = &ui;
    printValue(ptr, TUINT8);

    ptr = &_ui;
    printValue(ptr, TUINT16);

    ptr = &ul;
    printValue(ptr, TUINT32);

    ptr = &ull;
    printValue(ptr, TUINT64);

    return 0;
}

void printValue(const void* valuePtr, uint8_t flag){

    switch (flag)
    {
    case 0:
        printf("%d\n", *((int*)valuePtr));
        break;
    case 1:
        printf("%c\n", *((char*)valuePtr));
        break;
    case 2:
        printf("%f\n", *((float*)valuePtr));
        break;    
    case 3:
        printf("%u\n", *((uint8_t*)valuePtr));
        break;
    case 4:
        printf("%u\n", *((uint16_t*)valuePtr));
        break;
    case 5:
        printf("%u\n", *((uint32_t*)valuePtr));
        break;
    case 6:
        printf("%lu\n", *((uint64_t*)valuePtr));
        break;     
    default:
        printf("Invalid type!\n");
        break;
    }
}