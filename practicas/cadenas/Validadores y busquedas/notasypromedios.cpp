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
void promedioPorAlumno(char *nombre[4], int notas[][3], float* promedios,int FIL, int COL)
{
	int i = 0;
	int pasada = 0;
	for (pasada = 0;pasada < FIL;pasada++)
	{
		for (i = 0;i < COL;i++)
		{
			promedios[pasada] += notas[pasada][i];
		}
		promedios[pasada] = (float)promedios[pasada] / COL;
	}
	return;
}
void inicarAregloDePunteros(char *ptr[], char alumnos[][20], int FIL)
{
	int i= 0;
	for (i = 0;i < FIL;i++)
	{
		ptr[i] = alumnos[i];
	}
	return;
}
void imprimirNotas(char *nombre[4], int notas[][3],float *promedio, int FIL, int COL)
{
	int i=0;
	int alumno = 0;
	printf(" _______________________________________________________\n");
	printf("|  Alumno       |   M1   |   M2   |   M3   |  Promedio  |\n");
	printf("|---------------|--------|--------|--------|------------|\n");
	for (alumno = 0;alumno < FIL;alumno++)
	{
		printf("| %8s      ", *(nombre + alumno));
		for (i = 0;i < COL;i++)
		{
			printf("|   %2d   ", notas[alumno][i]);
		}
		printf("|  %.2f      |\n", *(promedio+alumno));
	}
	printf("|_______________|________|________|________|____________|\n\n");
	return;
} void ordenarPorPromedio(float* promedio, char *ptr[], int notas[][3], int FIL)
{
	int j = 0;
	int pasada = 0;
	float temp;
	int posMin;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	char* nombreTemporal;
	for (pasada = 0;pasada < FIL;pasada++)
	{
		posMin = pasada;
		temp = promedio[pasada];
		n1 = notas[pasada][0];
		n2 = notas[pasada][1];
		n3 = notas[pasada][2];
		nombreTemporal = ptr[pasada];
		for (j = pasada;j < FIL;j++)
		{
			if (promedio[j] > promedio[posMin])posMin = j;
			else if (promedio[j] == promedio[posMin] && strcmp(ptr[j], ptr[posMin]) < 0)posMin = j;
		}
		promedio[pasada] = promedio[posMin];
		promedio[posMin] = temp; // swap de promedios

		notas[pasada][0] = notas[posMin][0];
		notas[posMin][0] = n1;
		notas[pasada][1] = notas[posMin][1];
		notas[posMin][1] = n2;
		notas[pasada][2] = notas[posMin][2];
		notas[posMin][2] = n3;
		ptr[pasada] = ptr[posMin];
		ptr[posMin] = nombreTemporal;
	}
	return;
}
int buscarAlumno(char* ptr[], char clave[20], int FIL, int COL)
{
	int i = 0;
	int j = 0;
	char copia[20];
	char copiaNombres[4][20];
	for (i = 0;i < FIL;i++)
	{
		strcpy(copiaNombres[i], *(ptr + i));
	}
	
	for (i = 0;i < FIL;i++)
	{
		j = 0; //reinicio del indice de columnas.
		while (copiaNombres[i][j] != '\0')
		{
			copiaNombres[i][j] = tolower(copiaNombres[i][j]);
			j++;
		}
		copiaNombres[i][j] = '\0'; // Agrego el terminador a mano.
	}
	i = 0; // reinicio del indice i.

	strcpy(copia, clave);
	while (copia[i]!='\0')
	{
		copia[i] = tolower(copia[i]);
		i++;
	}
	copia[i] = '\0'; // AGrego el terminador a mano para evitar comparar basura.
	for (i = 0;i < FIL;i++)
	{
		if (strcmp(copia, copiaNombres[i]) == 0)return i;
	}
	return -1;
}
int main()
{
	char clave[20];
	const int FIL = 4;            // N de alumnos.
	const int COL = 3;            // N de materias
	int hallado = 0;
	static float promedios[FIL];  // Agrego static para que c inicialice el arreglo en 0, y que no tenga "basura".
	char* ptr[4];                 // Apunta a los 4 nombres para al momento de ordenar hacerlo por subindice y no con strcpy.
	char alumnos[FIL][20] = { "Nicolas","Nerea", "Mauro", "Messi" };
	int notas[FIL][COL] =
	{
	{ 10,6,4 },
	{9,5,6},
	{5,9,8},
	{6,8,8} };
	inicarAregloDePunteros(ptr, alumnos, FIL);
	promedioPorAlumno(ptr, notas, promedios, FIL, COL);
	imprimirNotas(ptr, notas, promedios, FIL, COL);
	ordenarPorPromedio(promedios, ptr, notas, FIL);
	imprimirNotas(ptr, notas, promedios, FIL, COL);
	printf("\nDesea buscar la nota de un alumno?  \n");
	scanf("%19s", clave);
	hallado = buscarAlumno(ptr, clave, FIL, COL);
	if (hallado != -1) printf("\nEl alumno %s tiene un promedio de %.2f\n\n", *(ptr + hallado), *(promedios + hallado));
	else printf("El alumno \" %s \" no fue encontrado\n\n", clave);
return 0;
}