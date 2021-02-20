//#include "../unpipc.h"
#include "sys/unistd.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char** argv)
{
    int fd[2],n;
    char c;
    pid_t childpid;

    pipe(fd);  /* assume a full-duplex pipe (e.g., SVR4) */
    if((childpid = Fork()) == 0){
        sleep(3);
        if((n = read(fd[0], &c, 1)) != 1) err_quit("child: read returned %d", n);
        printf("child read %c\n",c);
        write(fd[0], "c", 1);
        exit(0);
    }

    write(fd[1], "p", 1);
    if((n = read(fd[1], &c, 1)) != 1) err_quit("parent: read returnned %d", n);
    printf("parent read %c\n", c);
    exit(0);
}