PROG=teste
CC=gcc -g

all: rubronegra.o
	${CC} -o ${PROG} main.c rubronegra.o
rubronegra.o:  rubronegra.c rubronegra.h
	${CC} -c -o rubronegra.o rubronegra.c
clean:
	rm -rf *~ *.o ./\#*
