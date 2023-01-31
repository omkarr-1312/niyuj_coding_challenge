#include"header.h"

/* serverRecv */
int serverRecv( int listenfd, char *buff){
    int readBytes = 0;
    memset(buff, '\0', sizeof(buff));
    readBytes = Recv( listenfd, buff,MB, 0);
    printf("\nServerRec() success: Buffer= %s ReadBytes: %d\n",buff,readBytes);
    if(readBytes != 0)
   	 processRecvData( listenfd, buff);
}

/* serverSend */
void serverSend( int listenfd, char *buff){
    int writeBytes = 0;
    writeBytes = Send( listenfd, buff, strlen(buff), 0);
    printf("\n[CLIENT : %d] || Wrote [%d] number of bytes || BYTES = %s \n", listenfd, writeBytes, buff);
    memset(buff,0,sizeof(buff));
}

