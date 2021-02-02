#include "unistd.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "netinet/ip.h"
#include "time.h"

#define	MAXLINE		4096	/* max text line length */
#define	LISTENQ		1024	/* 2nd argument to listen() */

int main(int argc, char **argv)
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //not to bind the socket to a specific IP.
    servaddr.sin_port = htons(13); /* daytime server */

    bind(listenfd, (struct sockaddr*) & servaddr, sizeof(servaddr));
    listen(listenfd, LISTENQ);

    for(;;){
        connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
        
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));
    }
}