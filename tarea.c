#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int numeros[14];

void opcionGuionV(int day, int month, int year)
{
	printf("Fecha: %d-%d-%d\n", day, month, year);
	printf("Integrantes: criutor, maapakn, rvivar88\n");
}

/*int buscarNumero(int numero, int arreglo[], int tam)
{
	int i, stop = 0;
	for(i = 0; (i < tam && stop == 0); i++)
	{
		if(arreglo[i] == numero)
		{
			stop = 1;
		}
	}
	return stop;
}*/

void opcionGuionG(int day, int month, int year, int hour, int min, int sec)
{
	FILE *archivo;
	int i;
	int c;
	int aux;
	int inicio = 1;
	int fin = 25;
	int num_random;
	int fstop;
	
	srand(time(NULL));
	
	/*for(i = 0; i < 14; i++)
	{
		do{
			num_random = inicio+rand()%(fin - inicio + 1);
			fstop = buscarNumero(num_random, numeros, 14);
		}while(fstop);
	}*/
	
	for(i = 0; i < 14; i++)
	{
		int num = 1 + rand()%25;
		if(i > 0)
		{
			int j;
			for(j = 0; j < i ; j++)
			{
				if(num == numeros[j])
				{
					num = 1 + rand()%25;
					j=-1;
				}
			}
		}
		numeros[i] = num;
	}
	
	for(c = 0; c < 14; c++)
	{
		for(aux = c + 1; aux < 14; aux++)
		{
			int temp;
			if(numeros[c] > numeros[aux])
			{
				temp = numeros[c];
				numeros[c] = numeros[aux];
				numeros[aux] = temp;
			}
		}
	}
	
	
	archivo = fopen("archivoDos.txt", "a");
	if(archivo == NULL)
	{
		printf("No se pudo abrir el archivo para su escritura\n");
		exit(0);
	}
	fprintf(archivo, "%d-%d-%d %d:%d:%d ", year, month, day, hour, min, sec);
	for(i = 0; i < 14; i++)
	{
		fprintf(archivo, "%d; ",numeros[i]);
	}
	fprintf(archivo, "\n");
	fclose(archivo);
}

int main(int argc, char *argv[])
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int day = tm.tm_mday;
	int month = tm.tm_mon + 1;
	int year = tm.tm_year + 1900;
	int hour = tm.tm_hour;
	int min = tm.tm_min;
	int sec = tm.tm_sec;
	if(strcmp("-v", argv[1]) == 0)
	{
		opcionGuionV(day, month, year);
	}
	if(strcmp("-g", argv[1]) == 0)
	{
		opcionGuionG(day, month, year, hour, min, sec);
	}
	return 0;
}