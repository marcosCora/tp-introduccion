#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include "pila.h"
#include <time.h>


///prototipado
void muestra_menu();
int cargaArreglo(int a[], int dim);
int cargaArregloAleatorio(int a[], int dim);
void muestraArreglo(int v, int a[]);
void arreglo2Pila(int v, int a[], Pila *p);
void cargaPilaRandom(Pila *p);
int pila2Arreglo(int a[], int dim, Pila p);
int buscaDatoArreglo(int v, int a[], int dato);

///constantes
const int DIM = 20;
const int ESC = 27;

int main()
{

    ///variables
    char opcion;

    Pila pilarda;
    inicpila(&pilarda);
    int dato, encontrado;


    ///arreglos
    int arreglo1[DIM];
    int vArreglo1 = 0;


    do
    {
       system("cls");
       muestra_menu();
       opcion = getch();
       system("cls");

        switch(opcion)
        {
        case 49:
            vArreglo1 = cargaArreglo(arreglo1, DIM);
            break;

        case 50:
            vArreglo1 = cargaArregloAleatorio(arreglo1, DIM);
            printf("Ya se cargo el arreglo aleatorio...\n\n");
            system("pause");
            break;

        case 51:
            printf("Este es el arreglo:\n\n");
            muestraArreglo(vArreglo1, arreglo1);
            printf("\n\n");
            system("pause");
            break;

        case 52:
            arreglo2Pila(vArreglo1, arreglo1, &pilarda);
            printf("Esta es la pila: \n\n");
            mostrar(&pilarda);
            printf("\n\n");
            system("pause");
            break;

        case 53:
            cargaPilaRandom(&pilarda);
            printf("Esta es la pila random: \n");
            mostrar(&pilarda);
            printf("\n\n");

            system("pause");
            break;

        case 54:
            vArreglo1 = pila2Arreglo(arreglo1, DIM, pilarda);
            printf("Este es el arreglo con los datos de la pila:\n\n");
            muestraArreglo(vArreglo1, arreglo1);
            printf("\n\n");
            system("pause");
            break;

        case 55:
            printf("Ingrese un dato a buscar: ");
            scanf("%d", &dato);

            encontrado = buscaDatoArreglo(vArreglo1, arreglo1, dato);

            if(encontrado != 0)
            {
                printf("\nEl dato %d SE encuentra en el arreglo...", dato);
                printf("\n\n");
            }
            else
            {
                printf("\nEl dato %d NO se encuentra en el arreglo...", dato);
                printf("\n\n");

            }

            system("pause");
            break;

        case 56:


            system("pause");
            break;
        }



    }while(opcion != ESC);


    return 0;
}

void muestra_menu()
{
    printf("\t\t<<ELIGA UNA OPCION>>");
    printf("\n\n");
    printf("1-Carga arreglo manual\n");
    printf("2-Carga arreglo aleatorio\n");
    printf("3-Muestra arreglo\n");
    printf("4-Pasa arreglo a pila\n");
    printf("5-Carga pila random y la muestra\n");
    printf("6-Pila a arreglo\n");
    printf("\n\n");
    printf("Ingrese ESC si desea salir");
}

///carga un arreglo

int cargaArreglo(int a[], int dim)
{
    char opcion;
    int v = 0;

    printf("cargue el arreglo...\n");
    while(v<dim && opcion != ESC)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &a[v]);
        v++;

        printf("ESC si desea salir...");
        opcion = getch();
        system("cls");
    }

    return v;
}

///carga un arreglo aleatorio

int cargaArregloAleatorio(int a[], int dim)
{
    int v;
    for(v = 0; v<dim; v++)
    {
        a[v] = rand() % 50;
    }

    return v;
}

///muesttra arreglo

void muestraArreglo(int v, int a[])
{
    for(int i = 0; i<v; i++)
    {
        if(i%10 == 0)
        {
            printf("\n");
        }
        printf(" -|%d| ", a[i]);

    }


}

///pasa arreglo a pila

void arreglo2Pila(int v, int a[], Pila *p)
{

    for(int i = 0; i<v; i++)
    {
        apilar(p, a[i]);
    }
}

///carga pila random

void cargaPilaRandom(Pila *p)
{
    int dato = 0;
    int cont = 0;

    while(cont < 10)
    {
        dato = rand()%50;

        apilar(p, dato);

        cont++;
    }

}

///de pila a arreglo

int pila2Arreglo(int a[], int dim, Pila p)
{
    int v = 0;
    Pila aux;
    inicpila(&aux);
    while(v < dim && !pilavacia(&p) )
    {
        a[v] = tope(&p);

        apilar(&aux, desapilar(&p));

        v++;
    }

    return v;
}

///busca dato en arreglo retorna 1 verdadero 0 falso

int buscaDatoArreglo(int v, int a[], int dato)
{
    int i = 0;
    int flag = 0;

    while(i < v && flag == 0)
    {
        if(a[i] == dato)
        {
            flag = 1;
        }
        i++;
    }

    return flag;
}




