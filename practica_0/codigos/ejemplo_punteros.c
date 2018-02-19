# include <stdio.h>
# include <stdlib.h>

// Prototipos de funciones
void sumaValor ( float *);
void sumaArreglo ( void *);

/* Funcion main que recibe parametros de ejecucion */
int main ( int argc , char const * argv [])
{
    // Variable de tipo Flotante
    float a = 3.5;

    if ( argc == 2)
        a = atof ( argv [1]);

    /* El nombre de un arreglo es un puntero
       a su primera direccion de memoria */

    // Arreglo de tipo Entero
    long b [10] , i = 0;

    // Declaracion de punteros
    float * ptoa = NULL;
    long * ptob = NULL;

    // Asignacion de punteros

    ptoa = & a;
    ptob = b;
    printf ( " \n\n Sizeof Test : \n");
    printf ( " - Size (a): %d \n", sizeof (a));
    printf ( " - Size (b[0]): %d \n\n", sizeof (b[0]));
    printf ( " - Size (ptoa): %d \n", sizeof(ptoa));
    printf ( " - Size (ptob): %d \n\n", sizeof(ptob));
    printf ( " - Size (*ptoa): %d \n", sizeof(*ptoa));
    printf ( " - Size (*ptob): %d \n", sizeof(*ptob));

    // Dando valores al arreglo
    for (i = 0; i < 10; ++i)
        b[i] = i;

    // Valor de la variable llamada a
    printf ("\n Valor de (a): %.2f \n", a);
    printf (" Direccion de (a): %p \n", &a);

    // Valor del arreglo llamado b
    printf ("\n Valor del Arreglo (b): ");

    for (i = 0; i < 10; ++i)
        printf("[%d]", b[ i ]);
    printf("\n");

    printf("Direccion del Arreglo (b): %p \n\n", b);

    // llamado a la funcion suma Arreglo
    // cast de puntero int a puntero void

    sumaArreglo((void *)b);
    sumaValor(&a);

    // Valor del arreglo llamado b
    printf(" \nValor del Arreglo (b): ");

    for(i = 0; i < 10; ++i)
        printf("[%d]",b[i]);
    printf("\n");
    printf ("Direccion del Arreglo (b): %p \n\n", b);

    // Valor de la variable llamada a
    printf (" Valor de (a): %.2f \n", a);
    printf (" Direccion de (a): %p \n\n", &a);
    
    return 0;
}

void sumaValor ( float * a )
{

    /* Funcion que recibe una referencia a una variable
       de tipo flotante y modifica su valor sumandole 4.1 */

    * a = * a +4.1;
    return ;
}

void sumaArreglo ( void * pto )
{

    /* Funcion que recibe una referencia a un arreglo
       de tipo entero y modifica cada una de sus
       posiciones sumandole 5 al valor ahi guardado */

    int * p = ( int *) pto ;
    int i = 0;
    printf(" \nDireccion en Funcion (b): %p \n", p);
    printf(" Valor en Funcion (b [3]): %d \n\n", (*p+3));

    for(i = 0; i < 10; i++)
        p[i] = (*(p+i))+5;
}
