#include <stdio.h>
#include <stdlib.h>

char* encode_str(char* str, int size);
int is_even(int n);
char char_encode(char c);
void print_str(char* str);

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    if(n > 500){
        printf("Invalid size!\n");
        return -1;
    }

    char input[501];
    printf("Input a numerical string: ");
    scanf("%s", input);

    char *res = encode_str(input, n);

   print_str(res);
    
    free(res);
    return 0;
}

char* encode_str(char* str, int size){
    char *str2 = malloc(size*sizeof(char));
    for(size_t i = 0; i < size-1; i++){
        if(is_even(i)){
            str2[i] = (str[i] - '0') + 'A';
        }   
        else{
            str2[i] = char_encode(str[i]);
        }
    }
    str2[size-1] = '\0';
    return str2;
}

int is_even(int n)
{
    return n % 2 == 0 ? 1 : 0;
}

char char_encode(char c)
{
    switch (c){
        case '0':
            c = '!';
        break;
            case '1':
            c = '#';
        break;
            case '2':
            c = '/';
        break;
            case '3':
            c = '~';
        break;
            case '4':
            c = '=';
        break;
            case '5':
            c = '"';
        break;
            case '6':
            c = '\\';
        break;
            case '7':
            c = '>';
        break;
            case '8':
            c = '.';
        break;
            case '9':
            c = ',';
      break;
};

    return c;
}

void print_str(char* str)
{
    while(*str != '\0')
    {
        printf("%c", *str);
        str++;
    }
}