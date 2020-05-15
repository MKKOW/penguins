#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ai.h"
#include"bugs.h"
#include"plansza.h"
#include"interaktywna.h"
//#define AI
int main(int argc, char*argv[])
{
	int faza;
	char* in;
	char* out;
	int penguins=0;
	if (argc == 5&&strcmp(argv[1],"phase=placement")==0)
	{
		faza = 1;
			penguins = zmiennaint(argv[2]+9);
			in = argv[3];
			out = argv[4];
	}
	else if (argc == 4&& strcmp(argv[1], "phase=movement") == 0)
	{
		faza = 2;
		in = argv[2];
		out = argv[3];
	}
	else
	{
		return 3;
	}
	gracz g[10];
	for (int i = 0; i < 10; i++)
	{
		g[i].name = NULL;
		g[i].id = 0;
		g[i].wynik = 0;
	}
	int m = 0;
	int n = 0;
	plansza p=NULL;
	if (wczytaj(in, &p, &m,&n,g) == 0)
	{
		return 2;
	}
	/**/
	cords *lista = NULL;
	int rtr = 0;
#ifdef AI
	rtr=ai(&p, m, n, g, faza, penguins);
#else
rtr = interaktywna(&p, m, n, g, faza, penguins);
#endif
	zapisz(out, p, m, n, g);
	return rtr;
}