CC = gcc 
LIBPATH = ../lib/
LIB = createServerSocket.o sendRecv.o clientHandle.o processRecvData.o serverRecvSend.o
HEADER = $(LIBPATH)header.h

runS: server.o $(LIB)
	$(CC) server.o $(LIB) -lbsd -o runS

server.o: server.c
	$(CC) -c server.c

createServerSocket.o: $(LIBPATH)createServerSocket.c $(HEADER)
	$(CC) -c $(LIBPATH)createServerSocket.c

sendRecv.o: $(LIBPATH)sendRecv.c $(HEADER)  
	$(CC) -c $(LIBPATH)sendRecv.c

clientHandle.o: $(LIBPATH)clientHandle.c  $(HEADER)         
	$(CC) -c $(LIBPATH)clientHandle.c

processRecvData.o: $(LIBPATH)processRecvData.c $(HEADER)
	$(CC) -c $(LIBPATH)processRecvData.c

serverRecvSend.o: $(LIBPATH)serverRecvSend.c $(HEADER)
	$(CC) -c $(LIBPATH)serverRecvSend.c

clean: 
	rm $(LIB) server.o runS
