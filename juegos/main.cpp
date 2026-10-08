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
void mesa()
{
	printf("    _______________________________________________________________________\n");
	printf("   /     | 3 | 6 | 9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 | 33 | 36 |  2 a 1 |\n");
	printf("  /      |___|___|___|____|____|____|____|____|____|____|____|____|________|\n");
	printf(" /       |   |   |   |    |    |    |    |    |    |    |    |    |  2 a 1 | \n");
	printf("<   0    | 2 | 5 | 8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 35 |        |        \n");
	printf(" \\       |___|___|___|____|____|____|____|____|____|____|____|____|________|\n");
	printf("  \\      | 1 | 4 | 7 | 10 | 13 | 16 | 19 | 22 | 25 | 28 | 31 | 34 | 2 a 1  |      \n");
	printf("   \\_____|___|___|___|____|____|____|____|____|____|____|____|____|________|   \n");
	printf("         |                |                   |                   |           \n  ");
	printf("       |    1ra docena  |    2da docena     |    3ra docena     |           \n ");
	printf("        |_______|________|___________________|___________________|          \n  ");
	printf("       |       |        |         |         |         |         |           \n  ");
	printf("       |  1-18 |   PAR  |  Negro  |  Rojo   |  IMPAR  |  19-36  |         \n ");
	printf("        |_______|________|_________|_________|_________|_________|          \n  ");
}

void imprimirApuesta()
{
	printf("\nCuenta con 500 monedas");
	printf("\nSeleccione (1) para apostar a un NUMERO");
	printf("\nSeleccione (2) para apostar PAR");
	printf("\nSeleccione (3) para apostar IMPAR");
	printf("\nSeleccione (4) para apostar a una DOCENA");
	printf("\nSeleccione (5) para apostar a una COLUMNA");
	printf("\nSeleccione (6) para apostar a PASA/FALTA");
	printf("\nSeleccione (7) para apostar a ROJO");
	printf("\nSeleccione (8) para apostar a NEGRO");
	printf("\nSeleccione (9) para apostar SALIR\n\n");
}

void juego()
{
	int opcion;
	static int monedas = 500;
	int apuesta = 0;
	int docena = 0;
	int columna = 0;
	int pasa = 0;
	int numero = 0;
	int bola;
	int error;
	int usos = 0; // Variable que se usa para contar las interacciones del usuario y volver a imprimir la mesa.
	do
	{
		error = 0;
		int ganancia = 0;
		bola = rand() % 37;
		printf("\n\nQue apuesta desea Efectuar?\n");
		scanf("%d", &opcion);
		if (opcion != 9 && opcion >= 1 && opcion <= 8)
		{
			printf("Cuanto va a apostar?  ");
			scanf("%d", &apuesta);
		}
		switch (opcion)
		{
		case 1: //pleno
			printf("a que numero apuesta?  ");
			scanf("%d", &numero);
			if (numero == bola) ganancia = apuesta * 36;
			else ganancia = 0; break;

		case 2:  //par
			if (bola != 0 && bola % 2 == 0) ganancia = apuesta * 2;
			else
				ganancia = 0;

			break;
		case 3:  //impar
			if (bola != 0 && bola % 2 != 0) ganancia = apuesta * 2;
			else
				ganancia = 0;
			break;
		case 4:  //docena
			printf("\nA que docena desea apostar?  ");
			scanf("%d", &docena);
			if (docena >= 1 && docena <= 3)
			{
				if (docena == 1 && bola >= 1 && bola <= 12)
				{
					ganancia = apuesta * 3;
				}
				else if (docena == 2 && bola >= 13 && bola <= 24)
				{
					ganancia = apuesta * 3;
				}
				else if (docena == 3 && bola >= 25)
				{
					ganancia = apuesta * 3;
				}
			}
			else {
				printf("\nopcion invalida chaval\n");
				error = 1;
			}

			break;

		case 5:
			printf("\nA que columna desea apostar?  ");
			scanf("%d", &columna);
			if (bola != 0)
			{
				if (columna == 1 && (bola - 1) % 3 == 0)
					ganancia = apuesta * 3;
				else if (columna == 2 && (bola - 2) % 3 == 0)
					ganancia = apuesta * 3;
				else if (columna == 3 && bola % 3 == 0)
					ganancia = apuesta * 3;
				else if (columna < 1 || columna > 3)
				{
					printf("\nopcion invalida\n");
					error = 1;
				}
			}
			else ganancia = 0;
			break;
		case 6: //pasa/falta
			printf("\nSelecciones 1 para apostar 1-18 y 2 para apostar 19-36  ");
			scanf("%d", &pasa);
			if (pasa == 1 || pasa == 2)
			{
				if (pasa == 1 && bola >= 1 && bola <= 18) ganancia = apuesta * 2;
				else if (pasa == 2 && bola >= 19 && bola <= 36) ganancia = apuesta * 2;
				else ganancia = 0;
			}
			else
			{
				printf("\nOpcion invalida");
				error = 1;
			}
			break;
		case 7: if (bola != 0)
		{
			if ((bola >= 1 && bola <= 10 && bola % 2 != 0)|| (bola >= 19 && bola <= 28 && bola % 2 != 0)) ganancia = apuesta * 2;
			else if (( bola >= 11 && bola < 19 && bola % 2 == 0)|| (bola >= 29 && bola % 2 == 0)) ganancia = apuesta * 2;
			else ganancia = 0;
		}
			  else ganancia = 0;
			break;
		case 8:
			if (bola != 0)
			{
				if ((bola >= 1 && bola <= 10 && bola % 2 == 0) || (bola >= 19 && bola <= 28 && bola % 2 == 0)) ganancia = apuesta * 2;
				else if ((bola >= 11 && bola < 19 && bola % 2 != 0) || (bola >= 29 && bola % 2 != 0)) ganancia = apuesta * 2;
				else ganancia = 0;
			}
			else ganancia = 0;
			break;
	

		case 9: printf("\nGracias por utilizar este programa :)\n"); break;
		default: printf("\nopcion invalida\n");break;
		}
		if (opcion >= 1 && opcion <= 8 && error == 0)
		{
			monedas = monedas - apuesta + ganancia;
			printf("\nGirando... Tirando bola... ");
			printf("\nLa bola cayo en la casilla %d", bola);
			if (ganancia > 0)
			{
				printf("\nEn esta jugada sus ganancias fueron de: %d\n", ganancia - apuesta);
				printf("\nSu saldo es de $%d ", monedas);
			}
			else
			{
				printf("\nen esta ronda perdio $%d\n", apuesta);
				printf("\nSu saldo es de $%d \n", monedas);
			}
			if (monedas <= 0)

			{
				printf("\nte quedaste sin monedas, fin del juego\n");
				opcion = 9;
			}
			usos++;
			if (usos % 3 == 0)
			{
				mesa();
				imprimirApuesta();
			}
		}
	} while (opcion != 9);


}

int main()
{
	srand(time(NULL));
	mesa();
	imprimirApuesta();
	juego();
	return 0;
}