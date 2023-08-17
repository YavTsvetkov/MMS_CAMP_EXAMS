#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

void* average(void*);
int** nums;

typedef struct avg_nums{
    int M, N;
    float average;
} avg_nums;

int main(void)
{
    int N = 0, M = 0; // N-ROWS M-NUMBERS
    char filename[50];
    printf("N = ");
    scanf("%d", &N);
    printf("M = ");
    scanf("%d", &M);

    char rows[N][6];
    pthread_t threads[N];
    int nums_arr[N][M];
    nums = nums_arr;

    unsigned int row_num = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s", rows[i]);

        for (int j = 0; j < M; j++) {
            scanf("%d", &nums[i][j]);
        }
    }
    printf("Output file name: ");
    scanf("%s", filename);

    for (int i = 0; i < N; i++) {
        if (!strcmp(rows[i], "ROW")) {
            avg_nums avg;
            avg.M = M;
            avg.N = N;
            if(pthread_create(&threads[i], NULL, average, &avg) != 0){
                perror("Could not create a thread");
            }
        }
    }

    for (int i = 0; i < N; i++) {
       if(pthread_join(threads[i], NULL) != 0){
            perror("Could not join thread");
       }
    }

    FILE* f1 = fopen(filename, "w");

    if(f1 != NULL){
        perror("Could not create file");
    }

    // WRITE IN FILE HERE ...
    
    fclose(f1);

    return 0;
}


void* average(void* args)
{
    avg_nums* avg = (avg_nums*)args;
    int M = avg->M;
    int N = avg->N;

    for (int i = 0; i < M; i++) {
        avg->average += nums[N][M];
    }

    avg->average /= M;
}