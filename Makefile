# Author: Guilherme Henrique Rojas V. de Lima
# Email: guihen@linux.ime.usp.br

# -- MAKEFILE -- #

# -- Variaveis de Configuracao -- #
CC = gcc
CFLAGS = -g -I. -Wall -pedantic -ansi
LDFLAGS = -L.

RM = /bin/rm -f

# -- Geracao do executavel -- #
main:
	$(CC) $(CFLAGS) -o main main.c

# -- Clean -- #
clean:
	$(RM) main
