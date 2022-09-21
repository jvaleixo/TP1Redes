all: truco
truco: truco.o 
	gcc truco.o -o truco
truco.o: truco.c 
	gcc -o truco.o truco.c -c -W -Wall -ansi -pedantic
clean:
	rm -rf *.o *~ truco