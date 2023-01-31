CC = gcc
LIBPATH = ../lib/
LIB = createClientSocket.o send_recv.o clientSendRecv.o

HEADER = $(LIBPATH)header.h

runC: client.o $(LIB)
	$(CC) -o runC client.o $(LIB)

client.o: client.c $(HEADER)
	$(CC) -c client.c

createClientSocket.o: $(LIBPATH)createClientSocket.c $(HEADER)  
	$(CC) -c $(LIBPATH)createClientSocket.c

send_recv.o: $(LIBPATH)send_recv.c $(HEADER)
	$(CC) -c $(LIBPATH)send_recv.c

clientSendRecv.o: $(LIBPATH)clientSendRecv.c $(HEADER)
	$(CC) -c $(LIBPATH)clientSendRecv.c

clean: 
	rm $(LIB) client.o runC
