#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadoble.h"

int main(int argc, char const *argv[])
{
  // Validacion del numero de parametros
  if (argc != 2)
  {
    printf("Parametros Incorrectos \n");
    return -1;
  }

  lista * listaNumeros;

  //reserva memoria para la lista
  if((listaNumeros = (lista *)malloc(sizeof(lista))) == NULL)    
    return -1;  

  inicializar(listaNumeros);

  int i, num;
  int cant = atoi(argv[1]);

  for(i=0; i<cant; i++)
  {
    scanf("%d", &num);
    if(insertar(listaNumeros, ((void *)&num)) == -2)
      printf("-- Clave existente\n");
  }

  listar((void *)listaNumeros);

  for(i=0; i<cant; i+=5)
  {
    num = i;
    if(eliminar(listaNumeros, (void *)&num) == -1)
      printf("-- No se encontro Elemento\n");
  }

  for(i=0; i<cant+10; i+=10)
  {
    if((posN(i,listaNumeros)) != NULL)
      printf("Elemento: %d\n", (posN(i,listaNumeros))->dato);
    else
      printf(">> No se encontro Elemento\n");
  }

  quicksort((void *)listaNumeros);
  listar((void *)listaNumeros);

  if(listaNumeros->card > 1)
    destructor(listaNumeros);

  free(listaNumeros);
  return 0;
}
