#include <stdio.h>
#include <stdint.h>

typedef union myD {
    double number;
    struct d {
        unsigned long int mantissa : 53;
        unsigned int exponent : 10;
        unsigned int sign : 1;
    };
} myDouble;

int main() {
    myDouble converter;
    myDouble* converter_ptr = &converter;
    converter.number = 7.2;

    printf("Double value: %lf\n", converter.number);

    printf("Sign bit: %d\n", ((struct d*)converter_ptr)->sign);
    printf("Exponent: %d\n", ((struct d*)converter_ptr)->exponent);
    printf("Mantissa: %lu\n", ((struct d*)converter_ptr)->mantissa);

    return 0;
}

