#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int numeros[14];

/*void generarVectorRandom()
{
	srand(time(NULL));
	for(int i = 0; i < 14; i++)
	{
		int num = 1 + rand()%25;
		if(i > 0)
		{
			for(int j = 0; j < i ; j++)
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
	for(int ord = 0; ord < 14; ord ++)
	{
		for(int aux = ord + 1; aux < 14; aux++)
		{
			int temp;
			if(numeros[ord] > numeros[aux])
			{
				temp = numeros[ord];
				numeros[ord] = numeros[aux];
				numeros[aux] = temp;
			}
		}
	}
}*/

void mensajeGuionV(int dd, int mm, int aa)
{
	
	cout << "Fecha de compilacion: " << dd << '/' << mm << '/' << aa <<endl;
	cout << "Integrantes: criutor, maapakn, rvivar88" << endl;
}

void mensajeGuionG(int dd, int mm, int aa, int hh, int min, int ss)
{
	ofstream archivo;
	archivo.open("archivo.txt", ios::app);
	archivo << aa << '-' << mm << '-' << dd << " " << hh << ':' << min << ':' << ss << ';';
	srand(time(NULL));
	for(int i = 0; i < 14; i++)
	{
		int num = 1 + rand()%25;
		if(i > 0)
		{
			for(int j = 0; j < i ; j++)
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
	for(int ord = 0; ord < 14; ord ++)
	{
		for(int aux = ord + 1; aux < 14; aux++)
		{
			int temp;
			if(numeros[ord] > numeros[aux])
			{
				temp = numeros[ord];
				numeros[ord] = numeros[aux];
				numeros[aux] = temp;
			}
		}
	}
	for(int i = 0; i < 14; i++)
	{
		archivo << numeros[i] << ';';
	}
	archivo << endl;
	archivo.close();
}

int main(int argc, char *argv[])
{
	
	time_t t = time(0);
	struct tm * actual = localtime(&t);
	int dd = actual -> tm_mday;
	int mm = actual -> tm_mon + 1;
	int aa = actual -> tm_year + 1900;
	int hh = actual -> tm_hour;
	int min = actual -> tm_min;
	int ss = actual -> tm_sec;
	if(strcmp("-v", argv[1]) == 0)
	{
		mensajeGuionV(dd, mm, aa);
	}
	if(strcmp("-g", argv[1]) == 0)
	{
		mensajeGuionG(dd, mm, aa, hh, min, ss);
	}
	/*if(argc != 1)
	{
		cout << "Uso: <nombre del programa> + [-v] / [-g]" << endl;
	}*/
	return 0;
}