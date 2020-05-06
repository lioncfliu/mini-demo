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
    struct sigaction act;
    act.sa_handler = handle_signal;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    
    sigaction(SIGINT, &act, NULL);
    for ( ; ; ) {
        printf("running . .. ...\n");
        sleep(1);
    }
    return 0;
}

