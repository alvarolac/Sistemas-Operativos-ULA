CC  = gcc
INC =
OPC = -g -c
LIB =
LIBH = -pthread
EXECUTABLES = ej1.out ej2.out ej3.out ej4.out

.c.o:
	$(CC) $(OPC) $(INC) $<

all: $(EXECUTABLES)

ej1.out: ej1.o
	$(CC) -o $@ $< $(LIB)

ej2.out: ej2.o
	$(CC) -o $@ $< $(LIB)

ej3.out: ej3.o
	$(CC) -o $@ $< $(LIB)

ej4.out: ej4.o
	$(CC) -o $@ $< $(LIBH)

clean:
	rm -fr *~ *.o $(EXECUTABLES)

