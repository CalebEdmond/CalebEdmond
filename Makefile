CC=gcc
CFLAGS=-I.
DEPS=alcanos.h
OBJS=parsear.o salida.o alcanos.o proyecto1.o diagramas.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

proyecto1: $(OBJS)
	$(CC) -o $@ $(OBJS)
