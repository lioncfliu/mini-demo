#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char* argv[]) 
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s <fifo_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    printf("fifo:", argv[1]); 
    if (mkfifo(argv[1], 0644) < 0) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    
    printf("create file `%s` success!\n", argv[1]);
    return 0;
}
