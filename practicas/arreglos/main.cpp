                                       /*
NOMBRE: Juan Jose González
LEGAJO: 23456
LABORATORIO: --
EJERCICIO: practicas
                                       
                                       */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void cargarVentas(int *ventas, int N)
{
    int k = 0;
    for (k = 0;k < N;k++)
    {
        *(ventas + k) = rand()%301;
    }
    return;
}
void imprimirTabla(int *codigos, int *ventas, int N) //imprime una tabla con los codigos de los productos y las ventas de los mismos
{
    int k = 0;
    printf(" _________________________ \n");
    printf("|  codigo   | N de ventas |");
    printf("\n|-----------|-------------|\n");
    for (k = 0;k < N;k++)
    {
        printf("|    %d      |     %3d     |\n", *(codigos+k),*(ventas+k));
    }
    printf("|___________|_____________|\n\n");
    return;
}
void copiarArreglos(int*original1, int*original2, int*copia1, int *copia2, int N)
{
    int k = 0;
    for (k = 0;k < N;k++)
    {
        *(copia1 + k) = *(original1 + k);
        *(copia2 + k) = *(original2 + k);
    }
    return;
}

void swap(int* a, int* b) //funcion auxiliar para llamar al momento de ordenar
{
    int temp = *a;
    *a =* b;
    *b = temp;
    return;
}

void ordenarPorVentas(int* codigos, int* ventas, int N) //ordena por seleccion de mayor a menor
{
    int pasada; 
    int posMin;
    int j;
    for (pasada = 0;pasada < N;pasada++)
    {
        posMin = pasada;
        for (j = posMin;j < N;j++) //a partir del "tope" impuesto por pasada, busca el mayor de los elemento del resto de arreglo sin ordenar
        {
            if (*(ventas + j) > *(ventas + posMin))  posMin = j; 
else if(*(ventas+j)==*(ventas+posMin) &&*(codigos+j)<*(codigos+posMin)) posMin = j;
        }
        swap((ventas + posMin), (ventas + pasada));
        swap((codigos + posMin), (codigos + pasada));//para no perder la relacion de orden efectuo el swap en ambis arreglos -->intercambio el elemento revisado, por el mayor de los elementos de alrreglo sin ordenar, si el valor de ventas coincide, se colocara en primer orden el que posea un codigo menor
    }
    return;
}
int busquedaBinariaPorCodigo(int*codigos, int clave,int N) //la busqueda se efectua sobre los arreglos copiados, ya que para este punto, los arreglosorignales estan ordenados en base a precios, y para efectuar la busqueda bunaria es necesario que esten ordenados en cuanto al parametro a buscar, en este caso los codigos
{
    int mayor= N-1;
    int menor=0;
    int medio;
    while (menor<=mayor)
    {
        medio = (mayor + menor) / 2;
        if (*(codigos + medio) == clave) return medio;
        else if (*(codigos + medio) < clave) menor = medio + 1;
        else mayor = medio - 1;
    }
    return -1;
}

void totalYPromedio(int *codigo, int*ventas, int N, int*total, double *promedio)
{
    int k = 0;
    for (k = 0;k < N;k++)
    {
        *total += *(ventas + k);
    }
    *promedio = (double) *total / N;
    return;
}
void encimaDelPromedio(int *codigo, int*ventas, int N, double *promedio)
{
    int i = 0;
    printf("\nSucursales que estan por encima del promedio:  \n");
    printf(" _________________________ \n");
    printf("|  codigo   | N de ventas |");
    printf("\n|-----------|-------------|\n");
    for (i = 0;i < N;i++)
    {
        if(*(ventas+i)>=*promedio)
        printf("|    %d      |     %3d     |\n", *(codigo + i), *(ventas + i));
    }
    printf("|___________|_____________|\n\n");
}

void masCercanaAlPromedio(int* codigo, int* ventas, int N, const double* promedio)
{ 
    //fabs() (si son double/float) 
    // abs() (si son int)
    int i = 0;
    double difTemp = 0.0;
    int contador = 0;
    double minDif = fabs(*(ventas)-*promedio);//evalua la minima diferencia respecto al promedio la incializo en uno de los elementos para asegurar al menor 1 comparacion respecto el resto del arreglo;
    for (i = 0;i < N;i++)
    {
        difTemp =fabs( (*(ventas + i) - *promedio));
        if (difTemp < minDif)
        {
            minDif = difTemp;
            contador = i;
        }
    }
    printf("\nLa sucursal mas  cercana al promedio de ventas fue la N %d, con un total de %d ventas, respecto el promedio de %.2lf\n",*(codigo+contador), *(ventas+contador), *promedio);
    return;
    }
int main()
{
    srand(time(NULL));
    const int N = 8;
    int codigo[N] = {1,2,3,4,5,6,7,8};
    int ventas[N];
    int copiaV[N];
    int copiaC[N];
    int ventasTotales=0; double promedioDeVentas=0;
    int *total=&ventasTotales; double *promedio=&promedioDeVentas;
    int resultadoB = 0;
    int parametro=0; //es el codigo a buscar en la funcion de busqueda binaria
    cargarVentas(ventas, N);
    imprimirTabla(codigo, ventas, N);
    copiarArreglos(codigo, ventas, copiaC, copiaV, N);
    ordenarPorVentas(codigo, ventas, N);
    imprimirTabla(codigo, ventas, N);
    printf("\ndesea conocer las ventas de alguna Sucursal?\nIngrese su codigo:  \n");
    scanf("%d", &parametro);
    resultadoB=busquedaBinariaPorCodigo(copiaC,parametro, N);
    if (resultadoB != -1)printf("\nLas ventas de la sucursal %d, son %d\n", parametro, *(copiaV+resultadoB));
    else printf("\nSucursal %d no encontrada \n", parametro);
    totalYPromedio(codigo, ventas, N, total, promedio);
    printf("\nEl total de ventas es de %d, y el promedio de ventas de la cadena es de %.2lf\n", *total, *promedio);
    encimaDelPromedio(codigo, ventas, N, promedio);
    masCercanaAlPromedio(codigo, ventas, N, promedio);
	return 0;
}