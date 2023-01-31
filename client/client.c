#include "../lib/header.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("[-]Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int sockfd=0;
    char sendBuff[MB];
    char recvBuff[MB];
   // memset(sendBuff,0,sizeof(sendBuff));
    //memset(recvBuff,0,sizeof(recvBuff));
    createClientSocket( &sockfd, argv[1]);

    while(1){
	    memset(sendBuff,0,sizeof(sendBuff));
	    if(read(0,sendBuff,MB) != 0){
	    	clientSend(sockfd,sendBuff);
	    }
	    if(strncmp(sendBuff, "bye", 3) == 0){
           	close(sockfd);
            	printf("[-]Disconnected from server.\n");
            	exit(1);
            }

	   // printf("RecvBuff: %s\n",recvBuff);
	    memset(recvBuff,0,sizeof(recvBuff));
	    clientRecv(sockfd,recvBuff);
	    printf("\n%s\n\n",recvBuff);
    }
    close(sockfd);
    return (EXIT_SUCCESS);
}
