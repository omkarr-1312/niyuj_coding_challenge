#include "header.h"

/* send() */
int Send( int sockfd,void *buff, size_t length, int flags){
    int n = send( sockfd, buff, length, flags);
    if(n < 0){
        fprintf( stderr,"[-]send() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return (n);
}

/* recv() */
int Recv( int sockfd, void *buff, size_t length, int flags){
    int n = recv( sockfd, buff, length, flags);
    if(n < 0){
        fprintf( stderr,"[-]recv() error with error number : %d\n", errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return (n);
}


