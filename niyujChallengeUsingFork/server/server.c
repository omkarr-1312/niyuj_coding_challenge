#include "../lib/header.h"

int main(void){
    int listenfd=0;
    int clientSocket = 0;
    char recvBuff[MB];
    memset(recvBuff,0,sizeof(recvBuff));
    pid_t childpid;
    // calling socket(), bind(), listen() with error handling
    createServerSocket( &listenfd);
    while(1){
	n_client = clientHandle(listenfd,&clientSocket);
	if((childpid = fork())==0){
		close(listenfd);
		listenfd = -1;
		while(1){
			serverRecv(clientSocket,recvBuff);
			if(strncmp(recvBuff,"bye",3)==0){
				printf("\n[+]Disconnected from - Client(%d)\n\n",n_client);
				break;
			}
		}
		close(clientSocket);
		clientSocket = -1;
		exit(EXIT_SUCCESS);
	}
	else{
		printf("\nChildpid(%d)=%d\n",n_client,childpid);
	}
	close(clientSocket);
    }
    close(listenfd);
    // cleanup();
    printf("\n...Terminating the session...\n");
    return (EXIT_SUCCESS);
}
