#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int printed_chars = 0;
    char c;
    while ((c = *fmt)) {
        if (c == '%') {
            fmt++;
            switch (*fmt) {
                case 'd':
                    printed_chars += printf("%d", va_arg(args, int));
                    break;
                case 'f':
                    printed_chars += printf("%f", va_arg(args, double));
                    break;
                case 'c':
                    putc(va_arg(args, int), stdout);
                    printed_chars++;
                    break;
                default:
                    putc(c, stdout);
                    printed_chars++;
            }
        } else {
            putc(c, stdout);
            printed_chars++;
        }
        fmt++;
    }

    va_end(args);

    return printed_chars;
}

int main() {
    int num = 42;
    char ch = 'A';
    double dbl = 3.14159;

    int printed = my_printf("Printing an integer: %d\n", num);
    printed += my_printf("Printing a character: %c\n", ch);
    printed += my_printf("Printing a float: %f\n", dbl);

    printf("Total characters printed: %d\n", printed);

    return 0;
}
