all: truco server client
truco: truco.o 
	gcc truco.o -o truco
truco.o: truco.c truco.h
	gcc -o truco.o truco.c -c -W -Wall -ansi -pedantic
server: server.o
	gcc server.o -o server
server.o: server.c
	gcc -o server.o server.c -c -W -Wall -ansi -pedantic
client: client.o
	gcc client.o -o client
client.o: client.c
	gcc -o client.o client.c -c -W -Wall -ansi -pedantic	
clean:
	rm -rf *.o *~ truco server client