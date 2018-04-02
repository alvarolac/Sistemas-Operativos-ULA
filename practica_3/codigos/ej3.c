#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;
  int estado;
  char *argumentos[] = {"./ej1.out"};

  pid = fork();
 
  if(pid == -1)
  {
    perror("Error en la ejecucion del fork");
    return 0;  
  }
  
  switch(pid)
  {
    case 0:
        execvp(argumentos[0], argumentos);
        perror("Error en la ejecucion del exec");
        return 0;
        
    default:
        wait(&estado);
        if(!estado)
          printf("\n\tCulmino la ejecucion del proceso hijo \n");
        else
          printf("\n\tError en la ejecucion del proceso hijo \n");  
        break;
  } 
  return 0;
}
