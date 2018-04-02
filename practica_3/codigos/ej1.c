#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct
{
  unsigned char dia;
  unsigned char mes;
  unsigned short int anio;
}t_fecha;

void funcion_generica(t_fecha *fecha);
float numero;

int main() {

  t_fecha fecha;
	pid_t pid;
  numero = 3.141593;	
  funcion_generica(&fecha);	
  	
	pid = fork();

	if (pid == -1) 
	{
		perror("Error al crear nuevo Hijo.\n");
		return(1);
	}

	if (pid) 
	{
		printf("\n\t -- Mi PID es %d, Soy el padre de %d\n", getpid(), pid);
		printf("\t -- Mi Padre es %d.\n ", getppid());
		printf("\t -- Numero: %.4f\n", numero);
		printf("\t -- Fecha: %d/%d/%d.\n ", fecha.dia,fecha.mes,fecha.anio);	
		fflush(stdout);
	} 
	else 
	{
		printf("\n\t ~~ Mi PID es %d, Soy el hijo de %d\n", getpid(), getppid());
		printf("\t ~~ Numero: %.4f\n", numero);
		printf("\t ~~ Fecha: %d/%d/%d.\n\n", fecha.dia,fecha.mes,fecha.anio);
		fflush(stdout);
		fecha.dia++;
    fecha.mes++;
    fecha.anio++;	
	}

  printf("\t --> Fecha: %d/%d/%d.\n\n", fecha.dia,fecha.mes,fecha.anio);

  sleep(7);
  
	return(0);
}

void funcion_generica(t_fecha *fecha)
{
  fecha->dia = 28;
  fecha->mes = 07;
  fecha->anio = 2016; 
}
