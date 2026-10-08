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

typedef const int ci;
void imprimir(char palabras[][20], int FIL)
{
	int i = 0; printf("\nPalabras dentro del arreglo: \n");
	for (i = 0;i < FIL;i++)
	{
		printf("%10s", palabras[i]);
	}
	return;
}
void ingresarClave(char* arr)
{
	printf("\nIngrese la palabra a buscar\n");
	scanf("%19s", arr); // El 19s es la restriccion de 19 caracteres (19 para escribir y el 20 del arrreglo clave es reservado para el \0).
	return;
}
int buscarPalabra(char palabras[][20], char* clave, const int FIL, const int COL)
{
	int i = 0;
	int j = 0;
	char auxiliarC[20];
	char auxiliar2[8][20];
	strcpy(auxiliarC,clave);   // Copio la clave ingresada por usuario.
	while (auxiliarC[i] != '\0')
	{
		auxiliarC[i] = tolower(auxiliarC[i]);  // Paso a minusculas la copia de la cadena.
		i++;
	}
	auxiliarC[i] = '\0'; // Coloco el terminador a mano.
	for (i = 0;i < FIL;i++)
	{
		for (j = 0;j < COL;j++)
		{
			auxiliar2[i][j] = palabras[i][j]; // Copio el arreglo de cadenas.
		}
	}
	for (i = 0;i < FIL;i++)
	{
		j = 0;  // Reinicio del indice de columnas.
		while (auxiliar2[i][j] != '\0')
		{
			auxiliar2[i][j] = tolower(auxiliar2[i][j]);
			j++;
		}
		auxiliar2[i][j] = '\0'; // Coloco al final de cada cadena el terminador a mano.
	}
	for (i = 0;i < FIL;i++)
	{
		if (strcmp(auxiliar2[i], auxiliarC) == 0) return i;
	}

	return -1;
}
int main()
{
	ci COL = 20;
	ci FIL = 8;
	int hallado=0;
	char elementos[FIL][COL] = { "CaJa","Mascota","Auto","versor","mente","iglesia","dos","sol"};
	char clave[COL];
	imprimir(elementos, FIL);
	int opcion;
		ingresarClave(clave);
		hallado = buscarPalabra(elementos, clave, FIL, COL);
		if (hallado != -1)
		{
			printf("\Coincidencia:  %s en la posicion %d del arreglo de cadenas\n", elementos[hallado], hallado);
		}
		else printf("\nPalabra %s no hallada\n", clave);
	return 0;
}
