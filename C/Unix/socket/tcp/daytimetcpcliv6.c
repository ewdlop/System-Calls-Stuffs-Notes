#include "../../unp.h"
#include "stdio.h"
#include "stdlib.h"
#include "netinet/ip.h"

#define	MAXLINE		4096	/* max text line length */

int main(int argc, char** argv)
{
    
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if(argc != 2)
        err_quit("usage: a.out <IPaddress>");
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0) < 0))
        err_sys("socket error");
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13); //convert values between host and network byte order
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) 
    /* convert IPv4 and IPv6 addresses from text to binary form. This function converts the character string src into a network
       address structure in the af address family, then copies the
       network address structure to dst.*/
        err_quit("inet_pton error for %s", argv[1]);
    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
        err_sys("connection error");
    while (( n = read(sockfd, recvline, MAXLINE)) > 0)
    {
        recvline[n] = 0; //null terminate
        if(fputs(recvline, stdout) == EOF)//output of characters and strings
            err_sys("fputs error");
    }
    if( n < 0) err_sys("read error");
    exit(0);
}