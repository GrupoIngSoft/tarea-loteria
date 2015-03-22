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

void archivoG(int day, int month, int year, int hour, int sec)
{
    FILE *archivo;
    int min=1;
    int max=25;
    int num_aleatorio;
    int numeros[TAM]={-1};
    int fstop;
    int i,j,aux=0;
    srand(rdtsc());
    for(i=0;i<TAM;i++)
    {
        do{
            num_aleatorio=min+rand()%(max-min+1);
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
    archivo = fopen("archivoDos.csv", "a");
	if(archivo == NULL)
	{
		printf("No se pudo abrir el archivo para su escritura\n");
		exit(0);
	}
	fprintf(archivo, "%d-%d-%d %d:%d:%d;", year, month, day, hour, min, sec);
	for(i = 0; i < TAM; i++)
	{
		fprintf(archivo, "%d;",numeros[i]);
	}
	fprintf(archivo, "\n");
	fclose(archivo);
}

void infV(int day, int month, int year)
{
    printf("Fecha: %d-%d-%d\n", day, month, year);
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

	if(strcmp(argv[1],"-g")==0)
    {
        archivoG(day, month, year, hour, sec);
    }
    if(strcmp(argv[1],"-v")==0)
    {
        infV(day, month, year);
    }
    if(strcmp(argv[1],"-g")!=0 && strcmp(argv[1],"-v")!=0)
    {
        printf("opcion invalida!\n");
    }
    return 0;
}
