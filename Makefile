# Author: Guilherme Henrique Rojas V. de Lima
# Email: guihen@linux.ime.usp.br

# -- MAKEFILE -- #

# -- Variaveis de Configuracao -- #
CC = gcc
#CFLAGS = -g -I. -Wall -pedantic -ansi
CFLAGS = -Wall -ansi -pedantic -O2 
LDFLAGS = -L.

RM = /bin/rm -f

# -- Geracao do executavel -- #
main: CARD_STACK.o main.o
	$(CC) $(CFLAGS) -o main main.o CARD_STACK.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c 

CARD_STACK.o:
	$(CC) $(CFLAGS) -c CARD_STACK.c

# -- Clean -- #
clean:
	$(RM) main *.o
