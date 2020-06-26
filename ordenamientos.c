#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27
#define DIMA 50

int carga_arreglo (int a[], int v, int dim);
void muestra_arreglo (int a[], int v);
int busca_menor (int a[], int v);
int busca_mayor (int a[], int v);
int busca_pos_menor (int a[], int v, int pos);
void ordenamiento_seleccion (int a[], int v);
int inserta_dato_arreglo(int a[], int v, int dim, int dato);
void inserta_dato_arreglo_paso1(int a[], int v, int dato);
void ordenamiento_insercion(int a[], int v);

int main()
{
    int arreglo[DIMA];
    int varreglo = 0;
    int menor;
    int mayor;
    int dato;

    varreglo = carga_arreglo(arreglo, varreglo, DIMA);

    printf("este es el arreglo: \n\n");
    ///muestra_arreglo(arreglo, varreglo);

    /**menor = busca_menor(arreglo, varreglo);
    printf("el menor elemento del arreglo es: %d\n\n", menor);

    mayor = busca_mayor(arreglo, varreglo);
    printf("el mayor elemento del arreglo es: %d\n\n", mayor);

    ordenamiento_seleccion(arreglo, varreglo);
    printf("este es el arreglo ordenado por seleccion:\n");
    muestra_arreglo(arreglo, varreglo); */

    /**printf("ingrese un dato a insertar en un arreglo ya ordenado: ");
    scanf("%d", &dato);
    printf("\n\n");
    inserta_dato_arreglo(arreglo, varreglo, DIMA, dato);*/

    ordenamiento_insercion(arreglo, varreglo);
    muestra_arreglo(arreglo, varreglo);


    return 0;
}


///carga arreglo

int carga_arreglo (int a[], int v, int dim)
{
    char opcion;

    while (opcion!=ESC && v<dim)
    {
        printf("ingrese arreglo INT: ");
        scanf("%d", &a[v]);
        v++;

        printf("ingrese ESC si desea salir: ");
        opcion=getch();
        system("cls");
    }
    return v;
}

///muestra arreglo

void muestra_arreglo (int a[], int v)
{
    int i;

    for (i=0; i<v; i++)
    {
        printf("|%d|-", a[i]);
    }
    printf("\n\n");
}

///busca menor elemento

int busca_menor (int a[], int v)
{
    int i = 0;
    int menor = a[i];

    for (i=1; i<v; i++)
    {
        if (a[i]<menor)
        {
            menor = a[i];
        }
    }
    return menor;
}

///busca mayor elemento

int busca_mayor (int a[], int v)
{
    int i = 0;
    int mayor = a[i];

    for (i=1; i<v; i++)
    {
        if (a[i]>mayor)
        {
            mayor = a[i];
        }
    }
    return mayor;
}

///busca pos menor

int busca_pos_menor (int a[], int v, int pos) ///recibe arreglo, validos, y la pocision que se
                                              ///encuentran parados
{
    int posmenor = pos;

    int menor = a[pos]; ///se almacena el dato menor del arreglo

    int i = pos+1; ///recorre el arreglo desde la posicion 1 ya que se toma como "menor elemento" al
                   ///que esta en la posicion 0

    while (i<v) ///recorre todo el arreglo
    {
        if (a[i]<menor) ///compara el dato que se encunetra en la posicion 1 con el que esta
                        ///almacenado en menor y si es sierto pasa lo siguiente:
        {
            menor = a[i]; ///cambia el valor de menor por el valor que se encuentra en i
            posmenor = i; ///en posmenor almacena la posicion del menor elemento del areglo
        }
        i++; ///decrementa el subindice
    }
    return posmenor; ///retorna la posicion de donde se encunetra el menor elemento
}

///ordenamiento por selecccion

void ordenamiento_seleccion (int a[], int v)///recibe el arreglo y los validos
{
    int posmenor; ///almacena el subindice donde se encuentra el menor elemento
    int i =0; ///subindice
    int aux; ///variable auxilar para hacer traspaso de datos

    while(i<v-1) ///recorre todo el arreglo hasta validos - 1
    {
        posmenor = busca_pos_menor(a, v, i); ///almacena en posmenor lo que retorna la funcion de
                                             /// busca pos menor
        aux = a[posmenor]; ///iguala el valor que contiene el arreglo(el menor) en esa posicion a aux
        a[posmenor] = a[i]; ///posmenor toma como valor el valor de i
        a[i]= aux; /// iguala la posicion i con aux que contiene el menor elemento de arreglo

        i++; ///incrementa i
    }
}

///inserta dato en arreglo ordenado

int inserta_dato_arreglo(int a[], int v, int dim, int dato) ///recibe el arreglo, los validos que
///contiene ese arreglo, la dimension del arreglo y el dato a insertar
{
    int i = v-1; /// esta variable empieza desde el final del arreglo

    while (i>=0 && a[i]>dato && v<dim) /// evalua si el dato es menor al contenido de esa posicion
    ///del arreglo sigue moviendo un lugar hasta encontrar que el dato sea mayor al contenido del arreglo
    {
        a[i+1] = a[i]; ///se copia el dato de i una posicion mas adelante del arreglo
        i--; ///decrementa el subindice
    }
    a[i+1] = dato; /// se copia el dato una posicion mas adelante que el numero del arreglo ya que menor

    return v+1; ///retorna validos + 1 ya que se le agrega un dato al arreglo
}

///primer paso para poder ordenar un elemento por insercion

void inserta_dato_arreglo_paso1(int a[], int v, int dato) ///recibe el arreglo, los validos que
///contiene ese arreglo y el dato a insertar
{
    int i = v; /// esta variable empieza desde el final del arreglo

    while (i>=0 && a[i]>dato) /// evalua si el dato es menor al contenido de esa posicion
    ///del arreglo sigue moviendo un lugar hasta encontrar que el dato sea mayor al contenido del arreglo
    {
        a[i+1] = a[i]; ///se copia el dato de i una posicion mas adelante del arreglo
        i--; ///decrementa el subindice
    }
    a[i+1] = dato; /// se copia el dato una posicion mas adelante que el numero del arreglo ya que menor
}

///ordenamiento por insercion

void ordenamiento_insercion(int a[], int v)
{
    int i = 0;

    while (i<v-1)
    {
        inserta_dato_arreglo_paso1(a, i, a[i+1]);///llaama a la funcion del primer paso
        i++;
    }
}


