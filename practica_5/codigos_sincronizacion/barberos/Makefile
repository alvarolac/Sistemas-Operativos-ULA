CC  = gcc
INC =
OPC = -g -c
LIB =
LIBH = -pthread
EXECUTABLES = cliente barbero

.c.o:
	$(CC) $(OPC) $(INC) $<

all: $(EXECUTABLES)

cliente: cliente.o
	$(CC) -o $@ $< $(LIB)

barbero: barbero.o
	$(CC) -o $@ $< $(LIB)

clean:
	rm -fr *~ *.o $(EXECUTABLES)

