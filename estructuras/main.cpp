/*
NOMBRE: Juan Jose González
LEGAJO: 23456
LABORATORIO:
EJERCICIO:

                                       */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    char nombre[20];
    int codigo;
    double precio;
    int stock;

}Producto;
void cargarArreglo(Producto arr[])
{
    arr[0] = { "lata",310,20.2,200};
    arr[1] = { "pan",421,10,15 };
    arr[2] = { "sal",830,2,20 };
    arr[3] = { "agua",144,5,30 };
    arr[4] = { "aceite",750,16,30 };
    arr[5] = { "chocolate",123,40.5,400 };
    return;
}

void imprimirProductos(Producto arr[], int N)
{
    int i = 0;
    printf("  Producto     codigo    precio    stock\n");
    printf("--------------------------------------------\n");
    for (i = 0;i < N;i++)
    {
        printf("%9s      %3d       %3.2lf       %3d  \n",arr[i].nombre, arr[i].codigo, arr[i].precio, arr[i].stock);
    }

    return;
}

void aplicarDescuento(Producto *producto)
{
    int descuento= 0;
    descuento = (rand() % 10 );
    producto->precio = (double)producto->precio - (producto->precio *( descuento/100.0)) ;
    printf("\nDescuento aplicado= %d%% --> al %s\n", descuento, producto->nombre);
    return;
}
void ordenarPorPrecio(Producto arr[], int N) //se va a autilizar eñ algoritmo de seleccion para efectuar la ordenacion en base a precios (de menor a mayor)
{
    int j=0;
    int posMin = 0;
    int pasada = 0;
    Producto temp; //para efectuar el swap  ;
    for (pasada = 0;pasada < N;pasada++)
    {
        temp = arr[pasada];
        posMin = pasada;
        for (j = posMin;j < N;j++)
        {
            if (arr[j].precio < arr[posMin].precio)posMin=j; //busqueda y asignacion del menor elemento a posmin;
        }
        //swap  ;
        arr[pasada] = arr[posMin];
        arr[posMin] = temp; //la comparacion se efectua mediante los precios, pero el swap intercambiando los elementos del arreglo, ya que una de las ventajas de la estructura, es que no se debe tener cuidado con la concordancia
    }

    return;
}
int busquedaPorCodigo(Producto arr[], int N, int clave) //como el arreglo esta ordenado en base a los precios, para la busqueda por code se va a aefectuar busqueda secuencial
{
    int pasada = 0;
    int i = 0;
    for (i = 0;i < N;i++)
    {
        if (arr[i].codigo == clave) return i;
    }
    return -1;
}
void stockTotal(Producto arr[], int N)
{
    int i = 0;
    int total=0;
    for (i = 0;i < N;i++)
    {
        total += arr[i].stock;
    }
    printf("\nEl total de productos es de %d\n", total);
}
int main()
{
    const int N = 6;
    srand(time(NULL));
    int hallado = 0; int clave = 0;
    Producto productos[N]; //arreglo de tipo producto llamada producto (se tiene 6 productos)
    Producto* p=productos+4;//puntero a variable tipo producto
    cargarArreglo(productos);
    imprimirProductos(productos, N);
    aplicarDescuento(p);
    puts("");
    imprimirProductos(productos, N);
    puts("");
    ordenarPorPrecio(productos, N);
    printf("\nProductos ordenados por precio\n\n");
    imprimirProductos(productos, N);
    printf("\ndesea buscar un producto por codigo?  ");
    scanf("%d", &clave);
    hallado=busquedaPorCodigo(productos, N, clave);
    if (hallado != -1)printf("Coincidencia: %s  $%.2lf\n\n", productos[hallado].nombre, productos[hallado].precio);
    else printf("Preducto %d no encontrado\n\n", clave);
    stockTotal(productos, N);
    return 0;
}