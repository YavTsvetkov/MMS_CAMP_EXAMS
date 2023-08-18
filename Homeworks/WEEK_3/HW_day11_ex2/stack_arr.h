
typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
}Stack;

Stack* createStack(unsigned capacity);

_Bool isEmpty(Stack* stack);

int peek(Stack* stack);

int pop(Stack* stack);

void push(Stack* stack, int op);

void destroyStack(Stack* stack);