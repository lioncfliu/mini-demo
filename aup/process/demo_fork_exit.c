#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void func(int status, void *arg) {
    printf("<on_exit> (%d, %s)\n", status, (char *)arg);
}

void func1(void) { printf("<atexit> (func1)\n"); }
void func2(void) { printf("<atexit> (func2)\n"); }
void func3(void) { printf("<atexit> (func3)\n"); }

int main(int argc, char* argv[])
{
    signal(SIGCHLD, SIG_IGN);

    on_exit(func, "on_exit_3");
    on_exit(func, "on_exit_2");
    on_exit(func, "on_exit_1");

    atexit(func1);
    atexit(func2);
    atexit(func3);


    pid_t fpid = fork();
    
    if (fpid < 0) {
        perror("fork() error");
        exit(EXIT_FAILURE);
    } else if (fpid == 0) {
        exit(0);
    } else {
        sleep(3);
    }
    
    printf("quit_proc(%d) . .. ...\n", getpid());
    return 0;
}
