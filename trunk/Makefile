# Makefile for asciihl
CC=gcc
CFLAGS=-std=c99 -g -Wall
LFLAGS=
BIN=asciihl

$(BIN): main.o
	$(CC) $(CFLAGS) -o $(BIN) main.o

%.o: %.c
	$(CC) -c $(CFLAGS) $<

.PHONY: clean
clean:
	rm -rf *.o $(BIN)
