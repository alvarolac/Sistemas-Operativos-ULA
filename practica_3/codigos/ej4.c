#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NRO_THR 5

pthread_t info_hilos[NRO_THR];

typedef struct
{
  unsigned char dia;
  unsigned char mes;
  unsigned short int anio;
}t_fecha;

typedef struct
{
  unsigned int id;
  t_fecha fecha;
}t_hilo;

t_hilo parametros_hilos[NRO_THR];

void * manejador_hilos(t_hilo *pto) 
{
  printf("\n\tHILO ID: %d\n", pto->id);
  printf("\tFecha: %d/%d/%d\n",pto->fecha.dia,pto->fecha.mes //
	                          ,pto->fecha.anio);
  
  fflush(stdout);
  pthread_exit((void *)(&(pto->id)));
}


int main() 
{
  int i;
  t_hilo *retorno;

  for (i = 0; i < NRO_THR; i++)
  {
    parametros_hilos[i].id = i;
    parametros_hilos[i].fecha.dia = 10+i;
	  parametros_hilos[i].fecha.mes = 4+i;
	  parametros_hilos[i].fecha.anio = 2016+i;
    pthread_create(&info_hilos[i],NULL,(void *)&manejador_hilos //
	                 ,(void *)&parametros_hilos[i]);
  } 
	
  printf("\n\t*** Hilos de Ejecucion Creados! \n\n");
  
  printf("\n");
  for (i = 0; i < NRO_THR; i++) 
  {
    pthread_join(info_hilos[i], (void *)&retorno);
    printf("\t --> El Hilo Nro:%d, Retorno el valor: %d\n", i, retorno->id);
    fflush(stdout);
  }
  printf("\n\t\a*** Todos los Hilos han terminado su ejecucion!\n\n");
  return 0;
}
