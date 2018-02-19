#ifndef LISTADOBLE_H
#define LISTADOBLE_H

/*--Estructura Nodo que Compone la Lista Doble--*/
typedef struct _node	
{
  int dato;
  struct _node * ptoSg;
  struct _node * ptoAn;
}nodo;

/*--Estructura Lista, compuesta de Nodos, con punteros 
  al primer elemento y al ultimo--*/ 
typedef struct _list
{
  nodo *inicio;
  nodo *fin;
  int card;
}lista;


//-- Prototipos de las Funciones -------------------------

//Inicializa las variables de la lista
void inicializar(lista *);

//Inserta por el ultimo elemento de la lista
int insertar(lista *, void *);

//Lista los elementos de la lista
void listar(void * );

//Nodo en pos, Devuelve el nodo en la posicion 
nodo * posN(int, lista *);

//Metodo de ordenamiento Quicksort, de menor a mayor
void quicksort(void *);

//Destructor de la lista
void destructor(lista * );


//-- Definicion de las Funciones --------------------------

void inicializar(lista *ptolista)
{
  ptolista->inicio = NULL;
  ptolista->fin = NULL;
  ptolista->card = 0;
}

int insertar(lista *ptolista, void * dato)
{
  return 0;
}


int eliminar(lista *ptolista, void * dato)
{
  return 1;
}


void listar (void * ptolista)
{ 
  printf("*\n");
}


void destructor(lista * ptolista)
{
  return;
}


nodo * posN(int pos, lista * ptolista)
{ 
  return NULL;
}


void quicksort(void * ptolista)
{
  return;
}

#endif
