#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int printf_time(const char *format, ...) {
    time_t now;
    struct tm *tm_info;
    time(&now);
    tm_info = localtime(&now);

    char time_str[20];
    strftime(time_str, sizeof(time_str), "%d.%m.%Y %H:%M:%S", tm_info);
    printf("[%s] ", time_str);

    va_list args;
    va_start(args, format);
    int result = vprintf(format, args);
    va_end(args);

    return result;
}

int main() {
    printf_time("This is a message with time: %d\n", 42);
    printf_time("Another message with time: %s\n", "Hello, World!");

    return 0;
}
