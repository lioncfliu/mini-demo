#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signum) 
{
    printf("received signal: %d\n", signum);
    exit(0);
}

int main(int argc, char* argv[]) 
{
    signal(SIGINT, handle_signal);
    for ( ; ; ) {
        printf("running . .. ...\n");
        sleep(1);
    }
    return 0;
}

