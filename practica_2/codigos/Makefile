CC  = gcc
INC =
OPC = -g -c
LIB = -lrt
obj = $(patsubst %.c,%.o,$(wildcard *.c))

.c.o:
	$(CC) $(OPC) $(INC) $<

all:	$(obj) autostop.out capturasignal.out clasificacion.out nosalir.out tempo_poxis.out timer_usuario.out

autostop.out: autostop.o
	$(CC) -o $@ $^

capturasignal.out: capturasignal.o
	$(CC) -o $@ $^

clasificacion.out: clasificacion.o
	$(CC) -o $@ $^ $(LIB)

nosalir.out: nosalir.o
	$(CC) -o $@ $^ $(LIB)

tempo_poxis.out: tempo_poxis.o
	$(CC) -o $@ $^ $(LIB)

timer_usuario.out: timer_usuario.o
	$(CC) -o $@ $^ $(LIB)

clean:
	rm -fr *.o *.out
