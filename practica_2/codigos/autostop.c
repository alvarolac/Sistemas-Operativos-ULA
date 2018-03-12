#include<unistd.h>    /* Funciones estandard de unix */
#include<sys/types.h> /* Definiciones de tipos, ej: pid_t */  
#include<signal.h>    /* Nombre de seniales y prototipo kill() */
#include<stdio.h>     /* Entrada y salida estandard*/

int main()
{
  //Conozco mi PID  
  pid_t my_pid = getpid();
  printf("PID: %d", my_pid);
  fflush(stdout);

  //Envio senial de parada
  kill(my_pid, SIGSTOP);

  while(1)
    printf("*.-");
  
  return 0;
}
