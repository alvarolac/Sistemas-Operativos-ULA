#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

void manejador_alarma(int);

void texto_letra(char *);

int main() {

	// temporizador 1		
	struct itimerspec tempo1;

	// temporizador 2
	struct itimerspec tempo2;

	timer_t reloj1;
  timer_t reloj2;

  // Inicializacion relojes
	timer_create(CLOCK_REALTIME, 0, &reloj1);	
	timer_create(CLOCK_REALTIME, 0, &reloj2);	

	signal(SIGALRM, manejador_alarma);

 	// Duracion de la alarma Tempo 1
  tempo1.it_value.tv_sec = 60;
	tempo1.it_value.tv_nsec = 000000000;

	// Repeticion de la alarma Tempo 1
	tempo1.it_interval.tv_sec = 0;
	tempo1.it_interval.tv_nsec = 000000000;

  // Activacion Tempo 1
 	timer_settime(reloj1, 0, &tempo1, NULL);


  system("clear");

  char buffer[1000];
	char opcion = 'n';

  strcpy(buffer, "\n\t Este es un mensaje de la Agencia Nacional U571-A. \n\t Este Mensaje se autodestruira en 60 segundos a partir del inicio de su ejecución. \n\t Si elige conocer la misión tendrá solo 5 segundos para aceptarla. \n\t Conocer la misión puede comprometer su vida. \n\t Suerte...! \n\n\n\t    ¿Desea conocer la Misión? [s/n]: \0");



  texto_letra(buffer);
 	scanf("%c",&opcion);

  if(opcion == 's')
  {
    strcpy(buffer, "\n\t      Su misión consiste en encontrar las dos únicas soluciones para la ecuación:\n\n\t        a^n + b^n = z^n  \n\n\t      La combinación de los números resultantes conforman las coordenadas donde \n\t      se encuentra escondido un objeto que compromete la seguridad nacional. \n\n\n\t      ¿Acepta la Misión? [s/n]: \0");

    texto_letra(buffer);
    getchar();

    // Duracion de la alarma Tempo 2
    tempo2.it_value.tv_sec = 5;
	  tempo2.it_value.tv_nsec = 000000000;

	  // Repeticion de la alarma Tempo 2
	  tempo2.it_interval.tv_sec = 0;
	  tempo2.it_interval.tv_nsec = 000000000;

    // Activacion Tempo 2
   	timer_settime(reloj2, 0, &tempo2, NULL);


    scanf("%c",&opcion);                                                                    
        
   	
    
    if(opcion == 's')
    {
      timer_delete(reloj1);
      timer_delete(reloj2);
      strcpy(buffer, "\n\t Gracias! Suerte Salvando La Nación! ... Autodestrucción! \n\n");
      texto_letra(buffer);
      system("clear");
    }
    else
    {
      strcpy(buffer, "\n\t Le has fallado a tu Nación ... autodestrucción! \n\n");
      texto_letra(buffer);
      system("clear");

    }
  }
  else
  {
    strcpy(buffer, "\n\t Le has fallado a tu Nación ... autodestrucción! \n\n");
    texto_letra(buffer);
    system("clear");
  }

	

	return(0);
}


void texto_letra(char *buffer)
{
  int i=0;
  while(buffer[i] != '\0')
	{
    printf("%c", buffer[i]);
	  fflush(stdout);
    i++;
    usleep(50000);
  }
}


void manejador_alarma(int sig_num) 
{
  char buffer[1000];
	strcpy(buffer, "\n\t Tiempo expirado. Le has fallado a tu nación ... autodestrucción! \n\n");
  texto_letra(buffer);
  system("clear");
  exit(0);
}
