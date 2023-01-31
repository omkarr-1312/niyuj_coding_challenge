//Header
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/un.h>
#include <time.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <bsd/string.h>
#include <sys/sysmacros.h>
#include <fcntl.h>

//Macros
#define MB 1024
#define MAXLINE 4096
#define MAXBUFF 8192
#define SERVER_PORT 54321
#define BACKLOG 10
#define MAX_NAME_SIZE 20
#define NO_OF_CLIENTS 10
#define CONNECTED "Connection Established...\n"

#define SA struct sockaddr
//global variable
static int n_client = 0;

// Function Declarations

// Server Functions
void createServerSocket( int *listenfd);
int Socket( int family, int type, int protocol);
int Bind( int sockfd, SA *addr, socklen_t addrlen);
int Listen( int sockfd, int backlog);
int clientHandle( int listenfd, int *newSocketfd);
int Accept( int sockfd, SA *addr, socklen_t *addrlen);
int serverRecv( int listenfd, char *buff);
void serverSend( int listenfd, char *buff);
int processRecvData(int socket,char *buffer);
int getPwd(char *buff);
int getLs(char *buff);
int changeDir(char *dirName,char *buff);

// Common Functions
int Send( int sockfd,void *buff, size_t length, int flags);
int Recv( int sockfd, void *buff, size_t length, int flags);

// Client Functions
void createClientSocket( int *sockfd, char *IP);
int Connect( int sockfd, SA *addr, socklen_t addrlen);
void clientSend( int listenfd, char *buff);
void clientRecv( int listenfd, char *buff);

// ssize_t Write( int sockfd, sockaddr_invoid *buff, size_t count);
// ssize_t Read( int sockfd, void *buff, size_t count);
