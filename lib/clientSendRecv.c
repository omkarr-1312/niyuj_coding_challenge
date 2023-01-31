#include"header.h"

/* clientRecv */
void clientRecv( int listenfd, char *buff){
    int readBytes = 0;
    memset( buff, '\0', sizeof(buff));
    readBytes = Recv(  listenfd, buff,MB, 0);
    if(readBytes == 0){
        printf("[-]Client Disconnected.\n");
        exit(0);
    }
}

/* clientSend */
void clientSend( int listenfd, char *buff){
    int writeBytes = 0;
    writeBytes = Send( listenfd,buff, strlen(buff),0);
}

