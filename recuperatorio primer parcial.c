#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

///prototipados

int cargaTemperaturasArreglo(int a[], int dim);
void muestraArregloTemp(int v, int a[]);
int cargaArregloTemperaturasRand(int a [], int v, int DIM);
void arreglo2Pila(int a[], int v, Pila *mayor, Pila *menor);
void mostrarPila(Pila p);
int temperaturaMinimaAreglo(int v, int a[]);
int cuentaPila(Pila p, int dato);
int sumaPila(Pila p, int dato);
float promedioPila(Pila p, int dato);


///constantes

#define ESC 27
#define DIM 10

int main()
{
    int temperaturas[DIM];
    int vTemperaturas = 0;
    int menorTemp = 0;
    int dato = 0;
    int suma = 0;
    int cont = 0;
    float promedio = 0;

    Pila menores;
    Pila mayores;
    inicpila(&menores);
    inicpila(&mayores);

    ///ejercicio 1
    printf("Cargando temperaturas...\n");
    vTemperaturas = cargaTemperaturasArreglo(temperaturas, DIM);
    ///vTemperaturas = cargaArregloTemperaturasRand(temperaturas, vTemperaturas, DIM);

    ///ejercicio 2

    printf("Este es el arreglo de temperaturas: \n\n");
    muestraArregloTemp(vTemperaturas, temperaturas);
    printf("\n\n");
    system("pause");
    system("cls");

    ///ejercicio 3

    arreglo2Pila(temperaturas, vTemperaturas, &mayores, &menores);
    printf("Ya se hizo el pasaje corespondiente...\n\n");

    ///ejercicio 4
    printf("Esta es la pila de mayores temperaturas:");
    mostrarPila(mayores);

    printf("\n\nEsta es la pila de menores temperaturas:\n\n");
    mostrarPila(menores);
    printf("\n\n");
    system("pause");
    system("cls");

    ///ejercicio 5

    menorTemp = temperaturaMinimaAreglo(vTemperaturas, temperaturas);

    printf("La menor temperatura es: %d\n\n", menorTemp);
    system("pause");
    system("cls");

    ///ejercicio 6

    printf("Ingrese la minimma temperatura para contar: ");
    scanf("%d", &dato);
    cont = cuentaPila(mayores, dato);

    printf("Esta es la cantidad de datos que contiene la pila: %d\n\n", cont);

    ///ejercicio 7

    printf("Ingrese la minimma temperatura a sumar: ");
    scanf("%d", &dato);
    suma = sumaPila(mayores, dato);

    printf("Esta es la suma de los datos mayores al que usted ingreso: %d\n\n", suma);
    system("pause");
    system("cls");

    ///ejercicio 8

    promedio = promedioPila(mayores, dato);

    printf("El promedio de la pila es de: %.2f\n\n", promedio);

    system("pause");
    system("cls");

    return 0;
}

///funciones

///ejercicio 1 ccargatemperaturas en un arreglo

int cargaTemperaturasArreglo(int a[], int dim)
{
    char opcion;
    int v = 0;

    while(v < dim && opcion != ESC)
    {

        do
        {
            printf("Ingrese una temperatura: ");
            scanf("%d", &a[v]);

        }while(a[v] < -100 || a[v] > 60);
        v++;

        printf("ESC para salir: ");
        opcion = getch();
        system("cls");

    }
    return v;
}

///ejercicio 2 muestra el areglo de temperaturas

void muestraArregloTemp(int v, int a[])
{
    for(int i = 0; i<v; i++)
    {
        printf(" -|%d| ", a[i]);
    }

}

///ejercicio 3 pasa a pilas las menores temp y otra las mayores temp

void arreglo2Pila(int a[], int v, Pila *mayor, Pila *menor)
{
    for(int i = 0; i<v; i++)
    {
        if(a[i] <= 0)
        {
            apilar(menor, a[i]);
        }
        else
        {
            apilar(mayor, a[i]);
        }
    }

}

///ejercicio 4 muestra pila

void mostrarPila(Pila p)
{
    Pila aux;
    inicpila(&aux);
    printf("\n\nTOPE-----------------------BASE\n");
    while(!pilavacia(&p))
    {
        printf("| %d |",tope(&p));
        apilar(&aux,desapilar(&p));
    }
    printf("\nTOPE-----------------------BASE");

}

///ejercicio 5 busca minima temperatura en el arrego

int temperaturaMinimaAreglo(int v, int a[])
{
    int menor = a[0];

    for(int i = 1; i<v; i++)
    {
        if(a[i] < menor)
        {
            menor = a[i];
        }
    }

    return menor;
}

///Hacer una función que cuente las temperaturas de una pila, mayores a un valor dado
/// (el valor se recibe porparámetro).

///ejercicio 6

int cuentaPila(Pila p, int dato)
{
    int cont = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        if(tope(&p) > dato)
        {
            cont++;
        }
        apilar(&aux, desapilar(&p));
    }


   return cont;
}




///ejercicio 7 suma pila de mayores temperaturas

int sumaPila(Pila p, int dato)
{
    int suma = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        if(tope(&p) > dato)
        {
            suma += tope(&p);
        }
        apilar(&aux, desapilar(&p));
    }


   return suma;
}


///ejercicio 8 saca promedio de la pila mayores

float promedioPila(Pila p, int dato)
{
    float promedio = 0;

    promedio = sumaPila(p, dato)/cuentaPila(p, dato);

    return promedio;
}
