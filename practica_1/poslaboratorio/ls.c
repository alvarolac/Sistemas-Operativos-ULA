#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
  int directorio = 0, archivos = 0;
  int opt=0;

 

  while ((opt = getopt(argc, argv, "hfd")) != -1) 
  {
    switch (opt) 
    {
      case 'h':
        printf("\n -- Programa que lista el contenido del \n  directorio actual o alguna ruta indicada --\n");
        printf("\n  SINOPSIS \n");
        printf("      $ ./ls [opciones] [fichero]\n");
        printf("\n  OPCIONES \n");
        printf("      [-h]  Ayuda del Programa\n");
        printf("      [-f]  Imprimir solo archivos\n");
        printf("      [-d]  Imprimir solo directorio\n");
        printf("\n  SISTEMAS OPERATIVOS ULA A-2106\n\n");
        exit(0);
        break;

      case 'f':
        archivos = 1;
        break;
     
      case 'd':
        directorio = 1;
        break;
     
      default: 
        fprintf(stderr, "\n  Ejecución: %s [-h] [-f] [-d] [ruta]\n\n  -h para desplegar la ayuda.\n\n",argv[0]);
        exit(0);
    }
  }

  if(directorio && archivos)
  {
    if(argc == 4)
    {
      printf("\n Imprimir archivos y directorios en ruta %s\n\n", *(argv+3));
    }
    else if(argc == 3  && optind == 2)
    {
      printf("\n Imprimir archivos y directorios en ruta %s\n\n", *(argv+2));
    }  
    else if(argc == 3)
    {
      printf("\n Imprimir archivos y directorios, directorio actual\n\n");
    }
    
    else if(argc == 2 && optind == 2)
    {
      printf("\n Imprimir archivos y directorios, directorio actual\n\n");
    }

  }

  else if(archivos)
  {
    if(argc == 3)
    {
      printf("\n Imprimir archivos en ruta %s\n\n", *(argv+2));
    }
    else if(argc == 2)
    {
      printf("\n Imprimir archivos, directorio actual\n\n");  
    }
  }  

  else if(directorio)
  {
    if(argc == 3)
    {
      printf("\n Imprimir directorios en ruta %s\n\n", *(argv+2));
    }
    else if(argc == 2)
    {     
      printf("\n Imprimir directorios, directorio actual\n\n");
    }  
  }

  else if(!directorio && !archivos)
  {
    if(argc == 2)
    {
      printf("\n Imprimir contenido en ruta %s\n\n", *(argv+1));   
    }
    else if(argc == 1)
    {
      printf("\n Imprimir contenido, directorio actual\n\n");
    }
  }
     
  return 0;
}