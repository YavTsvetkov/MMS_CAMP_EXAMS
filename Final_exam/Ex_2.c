#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdint.h>
#include<sys/wait.h>
#include<fcntl.h>

int sum_of_all = 0;

int main(int argc, char *argv[])
{
    int fd[argc-1][2];

    for (int i = 1; i < argc; i++) {
        pipe(fd[i]);
        int sum = 0; 
        uint64_t number = 0;

        int pid = fork();

        if(pid == 0){   // CHILD
            FILE* temp;
            temp = fopen(argv[i], "r");
            if(temp != NULL){
                perror("Could not open file");
            }

           while (fread(&number, sizeof(uint64_t), 1,temp ) > 0){
            printf("number: %ld \n\n", number);
                while (number > 0) {
                    int m = number % 10;
                    sum = sum + m;
                    number = number / 10;   
                }
           }

           close(fd[i][0]);
           write(fd[i][1], &sum, sizeof(sum));
        }  

        else {
            int temp = 0;
            for(int i = 0; i < argc; i++){
                close(fd[i][1]);
                read(fd[i][0], &temp, sizeof(temp));
                close(fd[i][0]);
                sum_of_all += temp;
            }
            printf("sum_of_all: %d\n", sum_of_all);
        }
    }

    return 0;
}