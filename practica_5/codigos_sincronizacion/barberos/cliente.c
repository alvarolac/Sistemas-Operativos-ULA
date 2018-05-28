#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <signal.h>
#include "memsh.h"
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>

int shmem_init(shmem_data *);

int llamadaSemaforo(int semId, int semNum, int op) 
{
  struct sembuf sops;
  sops.sem_num = semNum;
  sops.sem_op = op;
  sops.sem_flg = 0;
  return (semop(semId, &sops, 1)); /*devuelve -1 si error */
}

int main()
{
  system("clear");
  printf("\n--> Proceso %d \n\n",getpid());
 
  key_t id_shmem = ftok(ROUTE, ID);
  void *pto_shmem;
  shmem_data *pto_inf;
  int i = 0, shmem, pos, repeticion;  

  int sem;
  if ((sem  = semget(SEM_ID, 1, 0644)) < 0) {
    perror("Error al abrir el semaforo\n");
    exit(EXIT_FAILURE);
  }

  //Busqueda del segmento de memoria compartida
  if((shmem = shmget(id_shmem, sizeof(shmem_data), 0666)) < 0) 
  {
		perror("shmget");
		exit(EXIT_FAILURE);
	}

  //Vinculacion al segmento
	if((pto_shmem = shmat(shmem, NULL, 0)) == (char *) -1) 
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	
  int tiempo = 0;

  pto_inf = (shmem_data *) pto_shmem;
  printf("Esperando por barbero...\n");
  fflush(stdout);
  llamadaSemaforo(sem, 0, -1);
  pto_inf->array_p.mensaje = 0;
  shmem_init(pto_inf);
  
  int msg;

  sleep(2);
  printf("Sentandome...\n");
  fflush(stdout);
  sleep(1);
  printf("Hablando con el barbero... ");
  fflush(stdout);
  while(tiempo < 5)
  {
    msg = pto_inf->array_p.mensaje = tiempo+1;
    printf("%d ", msg);
    fflush(stdout);
    pto_inf->array_p.pid = getpid();
    sleep(1);
    tiempo++;
  }
  llamadaSemaforo(sem, 0, 1);
  printf("\n\nChao..\n"); 
  fflush(stdout);
  /*llamadaSemaforo(sem, 0, 1);
  sleep(2);
  printf("\n\nSaliendo...\n");
  fflush(stdout);*/

  if(shmdt(pto_shmem) == -1) 
	{
	  perror("shmdt");
	  exit(EXIT_FAILURE);
	}
   
  return(0);
}

int shmem_init(shmem_data *pto_inf)
{
	pto_inf->array_p.pid = getpid();    
	return 0;
} 
 
