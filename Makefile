# Makefile for Matrix Multiplication example
#
# Jim Teresco, CS 338, Williams College
# CS 341, Mount Holyoke College
# CS 400/CS 335, Siena College
#
CFILES=matmult.c timer.c
OFILES=$(CFILES:.c=.o)
CC=gcc -Wall

matmult:	$(OFILES)
	$(CC) -o matmult $(OFILES)

clean::
	/bin/rm -f matmult $(OFILES)

matmult.o:	timer.h
timer.o:	timer.h
