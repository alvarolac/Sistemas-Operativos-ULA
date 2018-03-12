#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarma_accion(int sig_num)
{
	printf("Tiempo expirado. Saliendo...\n\n");
	exit(0);
}

int main()
{
	char user[20];

	signal(SIGALRM, alarma_accion);

	printf("\n\t Nombre de Usuario: ");
	fflush(stdout);

  // Inicio de alarma
	alarm(10);
	fgets(user,10,stdin);
  
  // Fin de alarma
	alarm(0);

	printf("\n\t Usuario: %s\n\n", user);
	
  return 0;
}
