CC  = gcc
INC =
OPC = -g -c
LIB =
obj = $(patsubst %.c,%.o,$(wildcard *.c))

.c.o:
	$(CC) $(OPC) $(INC) $<

all:	$(obj) ej1.out

ej1.out: ej1.o
	$(CC) -o $@ $^

clean:
	rm -fr *.o *.out
