#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if(argc == 3){
        char *filename = argv[1];
        int N = atoi(argv[2]);
        int fd = 0;

        fd = open(filename, O_WRONLY | O_CREAT, 0777);
        uint64_t nums[N];
        for (int i = 0; i < N; i++) {
            nums[i] = i;
        }

        write(fd, nums, N*sizeof(uint64_t));
        close(fd);
    }

    return 0;
}