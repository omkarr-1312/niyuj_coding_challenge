CC = gcc
LIBPATH = ../lib/
LIB = createClientSocket.o sendRecv.o clientSendRecv.o

HEADER = $(LIBPATH)header.h

runC: client.o $(LIB)
	$(CC) -o runC client.o $(LIB)

client.o: client.c $(HEADER)
	$(CC) -c client.c

createClientSocket.o: $(LIBPATH)createClientSocket.c $(HEADER)  
	$(CC) -c $(LIBPATH)createClientSocket.c

sendRecv.o: $(LIBPATH)sendRecv.c $(HEADER)
	$(CC) -c $(LIBPATH)sendRecv.c

clientSendRecv.o: $(LIBPATH)clientSendRecv.c $(HEADER)
	$(CC) -c $(LIBPATH)clientSendRecv.c

clean: 
	rm $(LIB) client.o runC
