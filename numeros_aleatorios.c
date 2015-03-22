#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define TAM 14

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

int main(int argc , char* argv[])
{
	if(strcmp(argv[1],"-g")==0)
	{
	
    int min=1;
    int max=25;
    int num_aleatorio;
    int numeros[TAM]={-1};
    int fstop;
    int i;
    srand(time(NULL));
    
    for(i=0;i<TAM;i++)
    {
        do{
            num_aleatorio=min+rand()%(max-min+1);
            fstop=buscarNumero(num_aleatorio,numeros,TAM);
            }while(fstop);
        numeros[i]=num_aleatorio;
        
    }
    
    
    			FILE* Numeros;
        		Numeros = fopen("numeros.csv","a");
        
    			time_t tiempo = time(0);
                struct tm *tlocal = localtime(&tiempo);
                char output[128];
                strftime(output,128,"%d-%m-%y %H:%M:%S",tlocal);
                fprintf(Numeros,"%s;",output);
                
                for(i=0;i<TAM;i++){
                    fprintf(Numeros,"%d;",numeros[i]);
                }
                
                fprintf(Numeros,"\n");
                
                fclose(Numeros);
	}
	if(strcmp(argv[1],"-v")==0)
    {
        
    }
    if(strcmp(argv[1],"-g")!=0 && strcmp(argv[1],"-v")!=0)
    {
        printf("opcion invalida!\n");
    }
    return 0;
}


