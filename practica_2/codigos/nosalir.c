#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

// -- Funciones manejadoras de senales
void captura_c(int);
void captura_z(int);
void captura_bar(int);

int main()
{
  int i=0;

  /* Conociendo el numero de proceso asignado 
     por el SO */
  
  pid_t mi_pid = getpid();
  printf("\n\t Mi PID es: %d\n\n", mi_pid);

  /* Asignando manejador a c/u de las senales */
  signal(2, captura_c);   // SIGINT
  signal(3, captura_bar); // SIGQUIT
  signal(20, captura_z);  // SIGTSTOP

  


  while(1)
  {
    printf(".");
    fflush(stdout);
    sleep(1);
  }
  
  printf(" ...Finalizado!!! \n");
  return 0;
}

// ++ Funciones manejadoras de senales
void captura_c(int num_signal)
{
  printf(" No terminare la ejecucion \n");
  fflush(stdout);
}

void captura_z(int num_signal)
{
  printf(" No pausare la ejecucion \n");
  fflush(stdout);
}

void captura_bar(int num_signal)
{
  printf(" Esto tampoco funcionara \n");
  fflush(stdout);
}
