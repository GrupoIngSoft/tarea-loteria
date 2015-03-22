#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define TAM 14

int rdtsc()
{
    __asm__ __volatile__("rdtsc");
}

int buscarNumero(int numero, int arreglo[], int tam)
{
    int i, stop=0;
    for(i=0;(i<tam && stop==0);i++)
    {
        if(arreglo[i]==numero)
        {
            stop=1;
        }
    }
    return stop;
}

void opcionGuionG(int day, int month, int year, int hour, int min, int sec)
{
    FILE *archivo;
    int inicio=1;
    int fin=25;
    int num_aleatorio;
    int numeros[TAM]={-1};
    int fstop;
    int i,j,aux=0;
    srand(rdtsc());
    for(i=0;i<TAM;i++)
    {
        do{
            num_aleatorio=inicio+rand()%(fin-inicio+1);
            fstop=buscarNumero(num_aleatorio,numeros,TAM);
            }while(fstop);
            numeros[i]=num_aleatorio;
    }
    for (i=1; i<TAM; i++)
    {
        for (j=0 ; j<TAM - 1; j++)
        {
            if (numeros[j] > numeros[j+1])
            {
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }
    archivo = fopen("archivoTareaSoftware.csv", "a");
	if(archivo == NULL)
	{
		printf("No se pudo abrir el archivo para su escritura\n");
		exit(0);
	}
	fprintf(archivo, "%d-",year);
	if(month < 10)
	{
		fprintf(archivo, "0");
	}
	fprintf(archivo, "%d-",month);
	if(day < 10)
	{
		fprintf(archivo, "0");
	}
	fprintf(archivo, "%d ", day);
	if(hour < 10)
	{
		fprintf(archivo, "0");
	}
	fprintf(archivo, "%d:", hour);
	if(min < 10)
	{
		fprintf(archivo, "0");
	}
	fprintf(archivo, "%d:", min);
	if(sec < 10)
	{
		fprintf(archivo, "0");
	}
	fprintf(archivo, "%d;", sec);
	for(i = 0; i < TAM-1; i++)
	{
		if(numeros[i] < 10)
		{
			fprintf(archivo, "0");
		}
		fprintf(archivo, "%d;",numeros[i]);
	}
	fprintf(archivo, "%d", numeros[TAM-1]);
	fprintf(archivo, "\n");
	fclose(archivo);
}

void opcionGuionV(int day, int month, int year)
{
	printf("Fecha de compilacion: ");
	if(day < 10)
	{
		printf("0");
	}
	printf("%d-", day);
	if(month < 10)
	{
		printf("0");
	}
	printf("%d-%d\n", month, year);
	printf("Integrantes: Cesar Riutor, Diego Esparza, Rafael Vivar\n");
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
	
	if(argc == 1 || argc > 2)
	{
		printf("USO: %s + [-v] o [-g]", argv[0]);
		return 0;
	}
	if(strcmp(argv[1],"-g")!=0 && strcmp(argv[1],"-v")!=0)
	{
		printf("USO: %s + [-v] o [-g]", argv[0]);
		return 0;
	}
	if(strcmp(argv[1],"-g")==0)
    {
        opcionGuionG(day, month, year, hour, min, sec);
    }
    if(strcmp(argv[1],"-v")==0)
    {
        opcionGuionV(day, month, year);
    }
    return EXIT_SUCCESS;
}