#include "header.h"
//processing the received data from clients
int getPwd(char *buff){
    getcwd( buff, 100);
    if(buff != NULL){
        printf( "\n%s\n",buff);
    }else{
        perror("getcwd() Error");
        return (EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

int getLs(char *buff){
    struct stat sb;
    DIR *path;
    char date[100];
    char *dirName = ".";
    struct dirent *d;
    path = opendir(dirName);
    int f=0;
    if(path==NULL){
        perror("Cannot find directory");
        return (EXIT_FAILURE);
    }
    printf("\n");
    while((d = readdir(path)) != NULL){
   	 if (lstat(d->d_name, &sb) == -1) {
               perror("lstat()");
                return (EXIT_FAILURE);
         }
       	 switch (sb.st_mode & S_IFMT) {
            case S_IFDIR:{	
                            // printf("directory\n");
                             f=1;
                             break;
                         }
            case S_IFREG:{	
                             //printf("regular file\n");
                             f=2;
                             break;
                         }
         }
      	// printf("Last file modification:   %s", ctime(&sb.st_mtime));
      	 //strlcpy(date, ctime(&sb.st_mtime), sizeof(date));
         ctime_r(&sb.st_mtime,date);
    	 if(f==1)
        	strlcat( buff,"DIR ",MB);
    	 else if(f==2)
        	strlcat( buff,"REG ",MB);
     	 strlcat( buff, d->d_name, MB);
    	 strlcat( buff, " ", MB);
     	 strlcat( buff, date, MB);
     	 strlcat( buff, "\n", MB);
     	//printf("%s\n", buff);
    }
    return EXIT_SUCCESS;
}

int changeDir(char *dirName,char *buff){
    if(chdir( dirName) == -1){
        printf("No Such Directory\n");
        return  EXIT_FAILURE;
    }

    memset( buff, '\0',MB);
    getcwd(buff,100);
    if(buff != NULL){
        printf( "\n%s\n", buff);
    }else{
        perror("getcwd() Error");
        return (EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

int processRecvData( int socket, char *buffer) {
    char commandName[50], dirName[MB];	
    //MENU
    if(strncmp(buffer,"bye",3)==0){
	    return 0;
    }
    else if(strncmp( buffer, "pwd", 3) ==0) {
	    memset( buffer, 0, MB);
	    getPwd(buffer);
	    printf("\ngetPwd() success\n");
            serverSend( socket, buffer);        
	    memset(buffer,0,MB);
    }
    else if(strncmp(buffer, "ls",2) == 0) {
	    memset(buffer,0,MB);
	    getLs(buffer);
	    printf("\ngetLs() success\n");
	    serverSend(socket,buffer);
	    memset(buffer,'\0',MB);
    }	
    else if(strncmp(buffer,"cd",2)==0){
	    sscanf( buffer, "%s %s", commandName, dirName);
            changeDir(dirName, buffer);
            printf("\nchangeDir() success\n");
	    serverSend(socket,buffer);
	    memset(buffer,0,MB);
    }
    else{
 	   // memset(buffer,0,sizeof(buffer));
	    //buffer = "Please enter valid commands : pwd or ls or cd !\n";
            serverSend(socket, buffer);
	    memset(buffer,0,MB);
    }
    return 0;
}
