
#include "sock.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h>

#define PORT_NUM   8888

void child_waiter(int sig)
{
    //wait(NULL);
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
}

void process_request(int fd)
{
    if (fork() == 0)
    {
        dup2(fd, 1);
        close(fd);

        execlp("date", "date", NULL);
        exit(-1);
    }
}

int main(int argc, char **argv)
{
    int sock, fd;

    signal(SIGCHLD, child_waiter);

    if ((sock = make_server_socket(PORT_NUM)) == -1) {
        perror("make sock");
        return -1;
    }

    while (1) {
        fd = accept(sock, NULL, NULL);
        if (fd == -1) {
            perror("accept");
            break;
        }

        process_request(fd);
        close(fd);
    }

    close(sock);
    return 0;
}