#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define MAX_F_NAME_LEN 64

int main(int argc, char *argv[])
{
    char input[MAX_LEN];
    char output[MAX_LEN];
    char file[MAX_F_NAME_LEN];
    if (argc == 1){
        if (fgets(input, MAX_LEN, stdin) != NULL){
            fputs(input, stdout);
        }
    } 
    else if (argc == 2){
        
        strcpy(file, argv[1]);
        FILE* f1 = fopen(file, "r");

        if(f1 == NULL){
            perror("Could not open the file!");
            return -1;
        }else {
            fgets(output, MAX_LEN, f1);
            fputs(output, stdout);
        }
        fclose(f1);
    }
    else if (argc > 2){

        int file_names_count = argc - 1;
        char* files[file_names_count];
        for (size_t i = 0; i < file_names_count; i++)
        {
            char* fi = malloc(strlen(argv[i+1])+1);
            strcpy(fi, argv[i+1]);
            files[i] = fi;
        }

        for (size_t j = 0; j < file_names_count; j++)
        {
            FILE* f1 = fopen(files[j], "r");
            if(f1 == NULL){
                perror("Could not open the file!");
                return -1;
            }else {
                fgets(output, MAX_LEN, f1);
                fputs(output, stdout);
            }
            fclose(f1);
        }

        for (size_t j = 0; j < file_names_count; j++)
        {
            free(files[j]);
        }
    }

    return 0;
}