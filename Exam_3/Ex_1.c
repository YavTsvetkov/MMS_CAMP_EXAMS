#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    int mode = 0; // 2- binary 1- hex
    char* filename;
    if (argc == 3)
    {
        filename = argv[1];
        if(argv[2][0] == 'H'){
            mode = 1;
        }
        else if (argv[2][0] == 'B'){
            mode = 2;
        }
    }

   FILE* f1 = fopen(filename, "r");

   if(f1 == NULL){
    exit(-1);
   }
    char byte = 0;

   while(fread(&byte, sizeof(char), 1, f1) == 1)
   {
    if(mode == 1){
        printf("%x ", byte);
    }
    else if (mode == 2){
        int remainder = 0;
        int binary = 0;
        int i = 1;
        while (byte != 0) {
            remainder = byte % 2;
            byte /= 2;
            binary += remainder * i;
            i *= 10;
        }
        printf("%d ", binary);
    }
   }

    fclose(f1);
    return 0;
}

