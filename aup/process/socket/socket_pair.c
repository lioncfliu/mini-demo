#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) 
{
    signal(SIGCHLD, SIG_IGN); 

    int sockfds[2];
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockfds) < 0) {
        perror("socketpair");
        exit(EXIT_FAILURE);
    } 
    int parent_fd = sockfds[0];
    int child_fd = sockfds[1];
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        close(child_fd);
        char buf[BUF_SIZE+1] = "from parant_proc";
        int nbuf = strlen(buf);
        send(parent_fd, buf, nbuf, 0);
        
        nbuf = recv(parent_fd, buf, BUF_SIZE, 0);
        buf[nbuf] = 0;
        
        printf("parent_proc(%d) recv_msg: %s\n", getpid(), buf);
        close(parent_fd);
    }
    else if (pid == 0) {
        
        close(parent_fd);
        char buf[BUF_SIZE+1] = "from child_proc";
        int nbuf = strlen(buf);
        send(child_fd, buf, nbuf, 0);
        
        nbuf = recv(child_fd, buf, BUF_SIZE, 0);
        buf[nbuf] = 0;
        
        printf("child_proc(%d) recv_msg: %s\n", getpid(), buf);
        close(child_fd);
    }

    return 0;
}
