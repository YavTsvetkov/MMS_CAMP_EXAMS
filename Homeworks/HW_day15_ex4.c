#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void display(FILE *fi);
void display_text(FILE *fi);
void append_byte(FILE *fi);
FILE* cut_bytes(FILE *fi, char* filename);
void replace_bytes(FILE *fi);

int main(int argc, char *argv[])
{
    char filename[100];
    if (argc > 1){
        strcpy(filename, argv[1]);
    }

    FILE* fi = fopen(filename, "r+");

    if(fi == NULL){
        perror("Could not open the file");
        return -1;
    }

    setbuf(stdin, NULL);

    while (1) {
        printf("\n\nEnter command (d/t/a/c/e): \n");
        char c = getchar();
        rewind(fi);

        switch (c) {
            case 'd':
                display(fi);
                break;

            case 't':
                display_text(fi);
                break;

            case 'a':
                append_byte(fi);
                break;

            case 'c':
                fi = cut_bytes(fi, filename);
                break;

            case 'e':
                replace_bytes(fi);
                break;

            case EOF:
                fclose(fi);
                return 0;

            default:
                printf("Invalid command: %c\n", c);
                break;
        }

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    fclose(fi);
    return 0;
}

void display(FILE *fi){
    uint8_t byte = 0;
    while (fread(&byte, sizeof(byte), 1, fi) != 0)
    {
        printf("%x ", byte);
    }
}

void display_text(FILE *fi){
    char char_byte = 0;
    while (fread(&char_byte, sizeof(char_byte), 1, fi) != 0)
    {
        printf("%c", char_byte);
    }
}

void append_byte(FILE *fi){
    uint8_t byte = 0;
    if (fscanf(stdin, "%hhx", &byte) > 0)
    {
        fseek(fi, 0, SEEK_END);
        fwrite(&byte, sizeof(byte), 1, fi);
    }
    else
    {
        perror("Failed writing to file");
    }
}

FILE* cut_bytes(FILE *fi, char* filename)
{
    size_t start_index = 0, end_index = 0;
    uint8_t byte = 0;
    if (fscanf(stdin, "%ld %ld", &start_index, &end_index) == 2)
    {
        FILE *tmp_fi = fopen("temp.txt", "w+");
        while (ftell(fi) <= start_index)
        {
            fread(&byte, sizeof(byte), 1, fi);
            fwrite(&byte, sizeof(byte), 1, tmp_fi);
        }
        int off = end_index - start_index;
        fseek(fi, off, SEEK_CUR);
        while (fread(&byte, sizeof(byte), 1, fi) > 0)
        {
            fwrite(&byte, sizeof(byte), 1, tmp_fi);
        }
        fclose(fi);
        if (remove(filename) != 0)
        {
            perror("Error removing the file!");
        }

        if (rename("temp.txt", filename) != 0)
        {
            perror("Error renaming the file!");
        }
        return tmp_fi;
    }
}
void replace_bytes(FILE *fi){
    size_t index = 0;
    uint8_t byte = 0;
    if (fscanf(stdin, "%ld %hhx", &index, &byte) == 2)
    {
        fseek(fi, index, SEEK_SET);
        fwrite(&byte, sizeof(byte), 1, fi);
    }
}