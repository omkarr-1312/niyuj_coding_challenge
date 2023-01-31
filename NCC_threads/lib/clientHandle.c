#include"header.h"

/* accept() */
int Accept( int sockfd, SA *addr, socklen_t *addrlen){
    int n;
    n_client++;
    if((n= accept(sockfd, addr, addrlen)) < 0){      
        fprintf( stderr,"[-]accept() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+]Client Connected\n");
    return (n);
}

int clientHandle( int listenfd, int *newSocketfd){
    struct sockaddr_in clientAddress;
    socklen_t len = sizeof(struct sockaddr);
    char buff[MB];
    memset(buff,0,sizeof(buff));
    memset( &clientAddress, '\0', sizeof(clientAddress));
    *newSocketfd = Accept( listenfd, (SA *)&clientAddress, &len);
    printf("[+]Connection Established with %s:%d - Client(%d)\n\n", inet_ntop( AF_INET, &clientAddress.sin_addr, buff, sizeof(buff)), ntohs(clientAddress.sin_port), n_client);
    return n_client;
}

