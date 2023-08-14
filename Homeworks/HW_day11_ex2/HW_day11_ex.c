#include "stack_arr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define CAPACITY 50

_Bool isDigit(int digit);
_Bool isOper(char oper);

int operation(int a, int b, char op);

int main(void)
{
    char expression[2 * CAPACITY];
    Stack* operands = createStack(CAPACITY);

    printf("Enter an expression in reversed polish notation: \n");
    fgets(expression, sizeof(expression), stdin);

    char* token = strtok(expression, " \t\n");
    while (token != NULL)
    {
        if (isDigit(*token)) {
            push(operands, atoi(token));
        }
        else if (isOper(*token)) {
            int A = pop(operands);
            int B = pop(operands);
            int res = operation(A, B, *token);
            push(operands, res);
        }
        token = strtok(NULL, " \t\n");
    }
    printf("Result is: %d\n", peek(operands));
    destroyStack(operands);
    return 0;
}

_Bool isOper(char oper) {
    return (oper == '+' || oper == '-' || oper == '*');
}

_Bool isDigit(int digit) {
    return (digit >= '0' && digit <= '9');
}

int operation(int a, int b, char op) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return a * b;
    else
        return INT_MIN;
}