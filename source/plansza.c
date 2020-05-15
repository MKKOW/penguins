#include"plansza.h"
#include"bugs.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"napisy.h"
#include<string.h>
int wczytaj(char* in, plansza* p, int*m , int* n, gracz* g)
{
	plik ins = fopen(in, "r");
	if (ins == NULL)
	{
		return 0;
	}
	int r = sprawdzplik(ins, m, n);
	if (r == 0)
	{
		return 0;
	}
	fclose(ins);
	ins = fopen(in, "r");
	if (ins == NULL)
	{
		return 0;
	}
	
	wiersz w = (wiersz)malloc(*n * sizeof(pole));
	*p = (wiersz*)malloc(*m * sizeof(w));
	for (int i = 0; i < *m; i++)
	{
		(*p)[i] = (wiersz)malloc(*n * sizeof(pole));
	}
	char buff[1024];
	fgets(buff, 1024, ins);
	for (int i = 0; i < *m; i++)
	{
		fgets(buff, 1024, ins);
		for (int j = 0; j < *n; j++)
		{
			(*p)[i][j].ryb = buff[j * 3]-'0';
			(*p)[i][j].numer = buff[j * 3+1]-'0';
		}
	}
	if (r == 1)
	{
		while (fgets(buff, 1024, ins) != NULL)
		{
			int i = 0;
			while (isspace(buff[i]) == 0)
			{
				i++;
			}
			char* nazwa;
			nazwa = (char*)malloc(i * sizeof(*nazwa));
			for (int j = 0; j < i; j++)
			{
				nazwa[j] = buff[j];
			}
			nazwa[i] = '\0';
			int id = buff[i + 1] - '0';
			int j = i + 3;
			while (isspace(buff[j]) == 0)
			{
				j++;
			}
			char* wy = (char*)malloc(j * sizeof(*wy));
			for (int l = 0; l < j; l++)
			{
				if (buff[l + i + 3] != '\n')
					wy[l] = buff[l + i + 3];
				else
					wy[l] = '\0';
			}
			int wynik = zmiennaint(wy);
			g[id].id = id;
			g[id].name = nazwa;
			g[id].wynik = wynik;
		}
	}
	return 1;
}
void wypisz(plansza p,int m,int n,plik out)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fprintf(out,"%d%d ", p[i][j].ryb, p[i][j].numer);
		}
		fprintf(out,"\n");
	}
}
int zapisz(char* outs, plansza p, int m, int n, gracz* g)
{
	plik out= fopen(outs, "w");
	if (out == NULL)
	{
		printf("Nie moge otworzy pliku zapis.txt do zapisu!\n");
		return 2;
	}
	int i = 1;

	fprintf(out, "%d %d\n", m, n);
	wypisz(p, m, n, out);
	while (g[i].id > 0 && g[i].id < 10)
	{
		if (g[i].id != 0)
		{
			fprintf(out, "%s %d %d\n", g[i].name, g[i].id, g[i].wynik);
		}
		i++;
	}


	for (i = 0; i < m; i++)
	{
		free(p[i]);
	}
	free(p);
	i = 0;
	while (g[i].name != NULL)
	{
		free(g[i].name);
		i++;
	}

	fclose(out);
	return 1;
}

int policz(plansza p, int m, int n, int id)
{
	int x = 0;
	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			if (p[i][j].numer == id)
			{
				x++;
			}
		}
	return x;
}
