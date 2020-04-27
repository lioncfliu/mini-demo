#include <iostream>
#include <unistd.h>
#include <sys/epoll.h>

int main(int argc, char* argv[]) 
{
    int ep_fd, nfds;
    struct epoll_event ev, events[5];
    ep_fd = epoll_create(1);

    ev.data.fd = STDIN_FILENO;
    ev.events = EPOLLIN|EPOLLET;

    epoll_ctl(ep_fd, EPOLL_CTL_ADD, STDIN_FILENO, &ev);
    
    for ( ; ; ) {
        nfds = epoll_wait(ep_fd, events, 5, -1);
        for (int i = 0; i <nfds; i++) {
            std::cout<<"Hello World !" <<std::endl;
        }
    }
}
