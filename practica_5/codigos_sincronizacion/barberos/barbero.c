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


void shmem_init(shmem_data *);
void show_mon(shmem_data *);
void exit_signal(int);

int main() {
  system("clear");
  printf("\n_______________________  Barbero Dormilon _______________________\n\n");
  fflush(stdout);
  printf("\t-------------------------\n");
  fflush(stdout);
  printf("...zZzZz...\n");
  fflush(stdout);
 
  key_t id_shmem = ftok(ROUTE, ID);
  void *pto_shmem;
  shmem_data *pto_inf;
  int i = 0, shmem;  

  int sem;
  if ((sem  = semget(SEM_ID, 1, IPC_CREAT | 0644)) < 0) {
    perror("Error al abrir el semÃ¡foro\n");
    return(-1);
  }
  
  semctl(sem, 0, SETVAL, 1); //Un barbero
  //semctl(sem, 0, SETVAL, 2); //Dos barberos

  signal(2, exit_signal);

 
  //Creacion del segmento de memoria compartida
  if((shmem = shmget(id_shmem, sizeof(shmem_data), IPC_CREAT | 0666)) < 0) 
  {
		perror("shmget");
		exit(EXIT_FAILURE);
	}

  //Vinculacion al segmento
	if ((pto_shmem = shmat(shmem, NULL, 0)) == (char *) -1) 
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	
	//Inicializacion
	pto_inf = (shmem_data *) pto_shmem;
  shmem_init(pto_inf);
  
  while(1)
  {
    show_mon(pto_inf);
    usleep(100000);
  }
   
  return(0);
}


void shmem_init(shmem_data *pto_inf)
{
  int i=0;
	pto_inf->pid_mon = getpid();
	for(i; i<10; i++)
	{
	  pto_inf->array_p.pid = 0;
	  pto_inf->array_p.mensaje = 0;
	}  
}

void show_mon(shmem_data *pto_inf)
{
  int i=0;

    if(pto_inf->array_p.pid != 0)
    {
      printf("Cliente \t%d\t%d\n", pto_inf->array_p.pid, pto_inf->array_p.mensaje); 
      fflush(stdout);
      if(pto_inf->array_p.mensaje == 5)
        printf("\nChao\n\n");
      fflush(stdout);    
    }
    
    pto_inf->array_p.pid = 0;
}

void exit_signal(int num_signal)
{
  int i = 0, shmem;
  key_t id_shmem = ftok(ROUTE, ID);
  
  int sem;
  if ((sem  = semget(SEM_ID, 1, 0644)) < 0) {
    perror("Error al abrir el semaforo\n");
    exit(EXIT_FAILURE);
  }

  if (semctl(sem, 0, IPC_RMID, 0) == -1) 
  {
    perror("Error al eliminar el semaforo");
    exit(EXIT_FAILURE);
  }

  if((shmem = shmget(id_shmem, sizeof(shmem_data), 0666)) < 0) 
  {
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	
	if (shmctl(shmem, IPC_RMID, 0) < 0) 
	{
		perror("shmctl(IPC_RMID)");
		exit(EXIT_FAILURE);
	}	
	
	system("clear");
	printf("Hasta luego!\n");
  exit(EXIT_SUCCESS);  
}
