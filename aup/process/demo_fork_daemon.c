#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("before deamon ... \n");

    if (daemon(0,0) < 0) {
        perror("deamon error");
        exit(EXIT_FAILURE);
    }
    printf("before deamon ... \n");
    
    FILE *fp = fopen("/tmp/daemon_test.log", "a");
    if(fp == NULL){
        perror("fopen error");
        exit(EXIT_FAILURE);
    }

    for( ; ;){
        fprintf(fp, "A");
        fflush(fp);
        sleep(2);
    }

    return 0;
}
