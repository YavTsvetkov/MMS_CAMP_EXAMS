#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Invalid arguments count\n");
        return 1;
    }
    qsort(argv + 1, argc - 1, sizeof(char *), compare_strings);

    char outputFileName[100];
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    FILE *outputFile = fopen(outputFileName, "r");
    if (outputFile) {
        printf("Error: File '%s' already exists.\n", outputFileName);
        fclose(outputFile);
        return 1;
    }

    outputFile = fopen(outputFileName, "w");
    if (!outputFile) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        fprintf(outputFile, "%s\n", argv[i]);
    }

    fclose(outputFile);
    return 0;
}
