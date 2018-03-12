#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

// -- Funcion manejadora de señales
void captura_signal(int);



int main()
{
  int i=0;

  /* Conociendo el numero de proceso asignado por el SO */
  pid_t mi_pid = getpid();

  /* Asignando manejador a c/u de las señales */
  for(i=1;i<65;i++)
    signal(i, captura_signal);

  /* Auto envio de señales */
  for(i=1;i<65;i++)
  {
    printf("- Señal Enviada Nro: %d\n", i);
    fflush(stdout);

    
    if(i!=9 && i!=19 && i!=30 && i!=32 && i!=33)   
      kill(mi_pid, i);
    else
    {
      /* Señales NO manejables*/
      printf("--> Señal %d no manejable\n",i);
      fflush(stdout);
    }
  }

  /* Espera por una señal */
  pause();
  printf(" ...Finalizado!!! \n");

  return 0;
}


// ++ Funcion manejadora de señales
void captura_signal(int num_signal)
{
  printf("   + Señal recibida numero: %d\n", num_signal);
  fflush(stdout);
}
