// 
// created by lioncfliu on 2020/04/25 .
// referrenced from http://blog.chinaunix.net/uid-28541347-id-4232252.html .
//

#include <iostream>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

const size_t kMaxLine       = 5;
const size_t kOpenMax       = 100;
const size_t kListenQueue   = 20;
const int    kServerPort    = 5000;
const int    kInfTim        = 1000;
#define INFTIM 1000

// set fd to nonblocking
void set_nonblocking(int fd) 
{
   int options;
   
    options = fcntl(fd, F_GETFL); 
    if (options < 0) {
        perror("fcntl(fd, GETFL)");
        exit(1);
    }
    options = options|O_NONBLOCK;
    if (fcntl(fd, F_SETFL, options) < 0) {
        perror("fcntl(fd, SETFL, options)");
        exit(1);
    }
}

int main(int argc, char* argv[]) 
{
    int i, max_i, listen_fd, conn_fd, sock_fd, ep_fd, nfds, port_number;
    ssize_t n;
    char line[kMaxLine];
    socklen_t client_len;
    
    if (2 == argc ) {
        if ( (port_number = atoi(argv[1])) < 0) {
            fprintf(stderr, "Usage: %s port_number \a\n", argv[0]);
            return 1;
        }
    } else {
       fprintf(stderr, "Usage: %s port_number \a\n", argv[0]);
       return 1; 
    }

    struct epoll_event  ev, events[20];
    ep_fd = epoll_create(256);
    struct sockaddr_in client_addr, server_addr;
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    set_nonblocking(listen_fd); // nonblocking
    ev.data.fd = listen_fd; // fd to watch
    ev.events = EPOLLIN|EPOLLET; // evnets to watch
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, listen_fd, &ev);
    bzero(&server_addr, sizeof(server_addr));
    char local_addr[] = "127.0.0.1";
    //inet_aton(local_addr, &(server_addr.sin_addr));

    inet_pton(AF_INET, local_addr, &(server_addr.sin_addr));
    std::cout<< "addr:"<< local_addr <<",port_number:" << port_number <<std::endl;
   
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    bind(listen_fd, (sockaddr *)&server_addr, sizeof(server_addr));
    listen(listen_fd, kListenQueue);
    max_i = 0;
    for ( ; ; ) {
        nfds = epoll_wait(ep_fd, events, 20, 500);
        for (i = 0; i < nfds ; i++) {
            if (events[i].data.fd == listen_fd) {
                conn_fd = accept(listen_fd, (sockaddr *) &client_addr,  &client_len);
                if (conn_fd < 0) {
                    perror("conn_fd < 0");
                    exit(1);
                }
                char *str = inet_ntoa(client_addr.sin_addr);
                std::cout<<"accept a connection from "<< str <<std::endl;
                ev.data.fd = conn_fd;
                ev.events = EPOLLIN | EPOLLET;
                epoll_ctl(ep_fd, EPOLL_CTL_ADD, conn_fd, &ev);
            } else if (events[i].events & EPOLLIN) {
                std::cout<<"EPOLLIN" <<std::endl;
                if ( (sock_fd = events[i].data.fd) < 0 ) {
                    continue;
                }
                if ( (n = read(sock_fd, line, kMaxLine)) < 0) {
                    if (errno == ECONNRESET) {
                        close(sock_fd);
                        events[i].data.fd = -1;
                    } else {
                        std::cout<<"readline error" <<std::endl;
                    }
                } else if (n == 0) {
                    close(sock_fd);
                    events[i].data.fd = -1;
                }
                line[n] = '\0';
                std::cout<<"read " << line<< std::endl;
                ev.data.fd = sock_fd;
                ev.events = EPOLLOUT|EPOLLET;
                epoll_ctl(ep_fd, EPOLL_CTL_MOD, sock_fd, &ev);
            } else if (events[i].events & EPOLLOUT) {
                std::cout<<"EPOLLOUT" <<std::endl;
                sock_fd = events[i].data.fd;
                write(sock_fd, line, n);
                ev.data.fd = sock_fd;
                ev.events = EPOLLIN|EPOLLET;
                epoll_ctl(ep_fd, EPOLL_CTL_MOD, sock_fd, &ev);
            }
        }
    }
    

    return 0;
}
