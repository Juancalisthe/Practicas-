/*
NOMBRE: Juan Jose González
LEGAJO: 23456
LABORATORIO:--
EJERCICIO:--

									   */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define N 6
#define LARGO 20
void iniciarPunteros(char s[][LARGO], char *p[])
{
	int i = 0;
	for (i = 0;i < N;i++)
	{
		p[i] = s[i];
	}
	return;
}
void imprimirProductos(char *p[], double precios[])
{
	int i = 0;
	printf("Productos       |     precios\n");
	for (i = 0;i < N;i++)
	{
		printf("%10s      |    %4.2lf\n", p[i], precios[i]);
	}
	return;
}
void ordenarPorPrecios(char productos[][LARGO], double *precios, char *p[])  // Ordena los arreglos manteniendo la coherencia,  en base a los precios,  y como criterio auxiliar,  si 2 precios son identicos,  ordena alfabeticamente (a-z).
{
	int pasada = 0;
	int j = 0;
	int posMin;
	char *temp;
	double tempf;
	for (pasada = 0;pasada < N;pasada++)
	{
		posMin = pasada;
		tempf = precios[pasada];
		temp = p[pasada];
		for (j = posMin;j < N;j++)
		{
			if (precios[j] < precios[posMin]) posMin = j;
			else if (precios[j] == precios[posMin] && strcmp(p[j], p[posMin])<0) posMin = j;

		}
		precios[pasada] = precios[posMin];
		precios[posMin] = tempf;
		p[pasada] = p[posMin];
		p[posMin] = temp;
	}

	return;
}
int buscarProducto(char* productos[], char* clave)
{
	int i = 0;
	char copia[LARGO];
	strcpy(copia, clave);
	copia[i] = toupper(copia[i]); // Como conozco elarreglo,  para simplificar un poco,  paso la primer letra de la clave a mayusculas,  y el resto a minusculas.
		i++;
	while (copia[i] != '\0')
	{
		copia[i] = tolower(copia[i]);
		i++;
	}
	copia[i]='\0';
			for (i = 0;i < N;i++)
	{
		if (strcmp(productos[i], copia) == 0)return i;
	}

	return -1;
}
void baratoYCaro(char *productos[], double *precios)
{
	int i = 0;
	double max=0.0;
	double min = 10000.0;
	char productoCaro[LARGO];
	char productoBarato[LARGO];
	for (i = 0;i < N;i++)
	{
		if (precios[i] < min)
		{
			min = precios[i];
			strcpy(productoBarato, productos[i]);
		}
		if (precios[i] > max)
		{
			max = precios[i];
			strcpy(productoCaro, productos[i]);
		}

	}
	printf("\nEl producto mas barato es: %s  (%.2lf)\n", productoBarato, min);
	printf("\nEl producto mas caro es: %s  (%.2lf)\n", productoCaro, max);
	return;
}
int main()
{
	char productos[N][LARGO] = { "Lata", "Mate", "Olla", "Agua", "Botella", "Pollo" };
	char* ptr[N]; // Arreglo de punteros para ordenar por indice el arreglo de productos.
	char buscar[LARGO];
	int hallado=0;
	double precios[N] = {2.48,  1.21, 2.48 , 1 , 8 ,2.48 };
	iniciarPunteros(productos, ptr);
	imprimirProductos(ptr, precios);
	ordenarPorPrecios(productos, precios, ptr);
	printf("\nProductos Ordenados por precios:\n");
	imprimirProductos(ptr, precios);
	printf("Desea saber el precio de algun producto?    ");
	gets_s(buscar, LARGO - 1);
	hallado = buscarProducto(ptr, buscar);
	if (hallado != -1)printf("\nEl producto %s cuesta $%2.2lf\n", ptr[hallado], precios[hallado]);
	else printf("\nProducto %s no hallado\n", buscar);
	baratoYCaro(ptr, precios);

	return 0;
}