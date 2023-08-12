struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity);

_Bool isEmpty(struct Stack* stack);

char peek(struct Stack* stack);

char pop(struct Stack* stack);

void push(struct Stack* stack, char op);