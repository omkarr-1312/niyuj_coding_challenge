#include"header.h"

/* socket() */
int Socket( int family, int type, int protocol){
    int n = socket(family, type, protocol);
    if(n < 0){
        fprintf( stderr,"[-]send() error with error number : %d\n",errno);
        perror("Error Description ");
        exit(EXIT_FAILURE);
    }
    printf("[+]Socket Created\n");
    return (n);
}

/* bind() */
int Bind( int sockfd,SA *addr, socklen_t addrlen){
    int n = bind(sockfd,addr,addrlen);
    if(n < 0){
        fprintf( stderr,"[-]bind() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+]Bind Successful\n");
    return (n);
}

/* listen() */
int Listen( int sockfd, int backlog){
    int n = listen(sockfd, backlog);
    char *ptr;
    if( (ptr = getenv("LISTENQ")) != NULL){
        backlog = atoi(ptr);
    }
    if(n < 0){
        fprintf( stderr,"[-]listen() error with error number : %d\n",errno);
        perror("Error Description ");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+]Listening for the Client...\n\n");
    return (n);
}

void createServerSocket( int *listenfd){
    struct sockaddr_in serverAddress;
    *listenfd = Socket( AF_INET, SOCK_STREAM, 0);
    const int opt = 1;
    if( setsockopt( *listenfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, (char *)&opt, sizeof(opt))<0){
        perror("setsockopt(SO_REUSEADDR | SO_REUSEPORT) Error\n");
        close(*listenfd);
        exit(EXIT_FAILURE);
    }
    memset( &serverAddress, '\0', sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_addr.s_addr = htons(INADDR_ANY);
    Bind( *listenfd, (SA *)&serverAddress, sizeof(serverAddress));
    Listen( *listenfd, BACKLOG);
}
