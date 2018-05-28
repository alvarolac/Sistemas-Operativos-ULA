#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <signal.h>
#include <sys/sem.h>
#include "memsh.h"

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
  srand(getpid());
 
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
	
	pto_inf = (shmem_data *) pto_shmem;
  	pos = shmem_init(pto_inf);
  
  if(pos == -1)
  {
    if(shmdt(pto_shmem) == -1) 
	  {
		  perror("shmdt");
		  exit(EXIT_FAILURE);
	  }

    printf("\tMonitor sin espacio!!!\n\n");
    exit(EXIT_SUCCESS);
  }
 
  llamadaSemaforo(sem, 0, -1);

  repeticion = rand()%(100-10+1)+10; 
  for(i=0; i<repeticion; i++)
  {
    pto_inf->array_p[pos].numero++;
    printf("Numero: %d\n",i);
    usleep(500000);  
  }
  
  pto_inf->array_p[pos].termino = 1;
  if(shmdt(pto_shmem) == -1) 
	{
	  perror("shmdt");
	  exit(EXIT_FAILURE);
	}

  llamadaSemaforo(sem, 0, 1);
   
  return(0);
}

int shmem_init(shmem_data *pto_inf)
{
  int i=0;
	pto_inf->pid_mon = getpid();
	for(i; i<10; i++)
	  if(pto_inf->array_p[i].pid == 0)
	  {
	    pto_inf->array_p[i].pid = getpid();
	    return i; 
	  }
	return -1;
} 
 
