#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int n = 0;
    printf("before fork: n = %d\n", n);

    pid_t fpid = fork();
    
    if (fpid < 0) {
        perror("fork() error");
        exit(EXIT_FAILURE);
    } else if (fpid == 0) {
        n++;
        printf("child_proc(%d, %d): n = %d\n", getpid(), getppid(), n);
        sleep(5);
        exit(5);
    } else {
        n--;
        printf("parent_proc(%d): n = %d\n", getpid(), n);
        
        int stat;
        pid_t pid;
        for ( ; ; ) {
            pid = waitpid(fpid, &stat, WNOHANG);
            if (pid > 0) { 
                break;
            } else { 
                sleep(1);
                printf("wait child ...\n");
            }
        }
        if (WIFEXITED(stat)) {
            printf("child_proc(%d) exits with %d\n", pid, WEXITSTATUS(stat));
        }
    }
    
    printf("quit_proc(%d) . .. ...\n", getpid());
    return 0;
}
