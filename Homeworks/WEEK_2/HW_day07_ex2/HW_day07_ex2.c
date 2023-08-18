#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "stack_arr.h"

#define MAX_EXPRESSION_LENGTH 100

int precedence(char op);

int evaluateExpression(char* expression) {
    int i;
    struct Stack* values = createStack(strlen(expression));
    struct Stack* operators = createStack(strlen(expression));

    for (i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i]))
            push(values, expression[i] - '0');
        else if (expression[i] == '(')
            push(operators, expression[i]);
        else if (expression[i] == ')') {
            while (!isEmpty(operators) && peek(operators) != '(') {
                int val2 = pop(values);
                int val1 = pop(values);
                char op = pop(operators);
                if (op == '+')
                    push(values, val1 + val2);
                else if (op == '*')
                    push(values, val1 * val2);
                else if (op == '^')
                    push(values, (int)pow(val1, val2));
            }
            pop(operators);
        } else if (expression[i] == '+' || expression[i] == '*' || expression[i] == '^') {
            while (!isEmpty(operators) && peek(operators) != '(' &&
                   precedence(expression[i]) <= precedence(peek(operators))) {
                int val2 = pop(values);
                int val1 = pop(values);
                char op = pop(operators);
                if (op == '+')
                    push(values, val1 + val2);
                else if (op == '*')
                    push(values, val1 * val2);
                else if (op == '^')
                    push(values, (int)pow(val1, val2));
            }
            push(operators, expression[i]);
        }
    }

    while (!isEmpty(operators)) {
        int val2 = pop(values);
        int val1 = pop(values);
        char op = pop(operators);
        if (op == '+')
            push(values, val1 + val2);
        else if (op == '*')
            push(values, val1 * val2);
        else if (op == '^')
            push(values, (int)pow(val1, val2));
    }

    return pop(values);
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*')
        return 2;
    else if (op == '+')
        return 1;
    return 0;
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}