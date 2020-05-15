#include"interaktywna.h"
#include<stdio.h>
#include<stdlib.h>
#include"bugs.h"
#include"plansza.h"
#include<string.h>
#include"napisy.h"
#include"ai.h"
int ai(plansza * p, int m, int n, gracz * g, int faza, int pin)
{
	srand(time(0));
	cords* lista = NULL;
	int id = 0;
	if (analiza(*p, m, n, g, faza, &lista, &id))
	{
		if (faza == 1)
		{
			int f = policz(*p, m, n, id);
			if (f > pin)
			{
				return 3;
			}
			if (f == pin)
			{
				return 1;
			}
		}
		
		if (lista==NULL)
			return 1;
		cords *przed = malloc(sizeof(cords));
		cords *po = malloc(sizeof(cords));
		przed->x = lista->x;
		przed->y = lista->y;
		po->x = lista->x;
		po->y = lista->y;
		po->next = NULL;
		przed->next = NULL;
		int z = list_size(lista);
		if (z != 1 )
		{
			z = rand() % z;
			cords* pom = lista;
			for (int i = 0; i < z; i++)
				pom = pom->next;

			przed->x = pom->x;
			przed->y = pom->y;
		}
		if (faza == 2)
		{
			przed->next = po;
			do {
				z = rand() % 4;
				if (z == 0)
				{
					po->x = przed->x + 1;
					po->y = przed->y;
				}
				if (z == 1)
				{
					po->x = przed->x;
					po->y = przed->y + 1;
				}
				if (z == 2)
				{
					po->x = przed->x - 1;
					po->y = przed->y;
				}
				if (z == 3)
				{
					po->x = przed->x;
					po->y = przed->y - 1;
				}
			} while (czy_ruch(przed, *p,m,n) == 00);
		}
		wykonaj(p, przed, g, id);
		free(przed);
		free(po);
		cords*wsk = lista->next;
		cords*wsk1;
		free(lista);
		while (wsk!= NULL)
		{
			wsk1 = wsk;
			wsk = wsk->next;
			free(wsk1);
		}
		free(wsk);
		return 0;
	}
	else
	{
		return 1;
	}
}
