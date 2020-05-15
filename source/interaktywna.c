#include"interaktywna.h"
#include<stdio.h>
#include<stdlib.h>
//#define AI
#ifndef AI
#include<Windows.h>
#include<conio.h>
#endif
#include"bugs.h"
#include"plansza.h"
#include<string.h>
#include"napisy.h"
const char* nasze = "mma";
int analiza(plansza p, int m, int n, gracz* g, int faza, cords** lista, int* id) {
	
	int retrn = 0; //zeby wiedziec co returnowac, tzn czy mozliwy jest jakikolwiek ruch
	*id = 0;
	int e = 0;
	for (int i=0; i < 10; i++)
	{
		if (g[i].id != 0) {
			if (strcmp(g[i].name, nasze) == 0)
			{
				*id = g[i].id;
				e = 1;
				break;
			}
		}
	}
	if (e == 0)
	{
		for (int i = 0; i < 10; i++)
		{
				if (g[i].id != i)
				{
					char* nazwa = malloc(sizeof(char)*strlen(nasze));
					strcpy(nazwa, nasze);
					g[i].name = nazwa;
					g[i].id = i;
					*id = i;
					g[i].wynik = 0;
					break;
				}
		}
	}
	if (faza == 1) {
		cords *pierw = NULL;
		cords* pom = malloc(sizeof(cords));
		cords*pom2 = NULL;
		for (int i = 0; i < m; i++) {

			
			for (int j = 0; j < n; j++) {
				if (p[i][j].numer == 0 && p[i][j].ryb == 1) {
					if (pierw == NULL)
						pierw = pom;
					pom->y = i;
					pom->x = j;
					pom->next = malloc(sizeof(cords));
					pom2 = pom;
					pom = pom->next;
					retrn = 1;
				}
			}
		}
		if (pierw != NULL)
		{
			if (pierw->next == pom)
			{
				pierw->next = NULL;
			}
		}
		free(pom);
		pom2->next = NULL;
		*lista = pierw;
		return retrn;
	}
	else {
		cords *pierw=NULL;
		cords* pom=malloc(sizeof(cords));
		cords*pom2=NULL;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (p[i][j].numer == *id) {
					if (pierw == NULL)
						pierw = pom;
					if (sasiednie(p, i, j, m, n) == 1) {
						pom->y = i;
						pom->x = j;
						pom->next = malloc(sizeof(cords));
						pom2 = pom;
						pom = pom->next;
						retrn = 1;
					}
				}
			}
		}
		if (pierw != NULL)
		{
			if (pierw->next == pom)
			{
				pierw->next = NULL;
			}
		}
		free(pom);
		if (pom2 != NULL) {
			pom2->next = NULL;
		}
		*lista = pierw;
		return retrn;
	}
}
#ifndef AI
void wypisz_(plansza p, int m, int n, cords * lista)
{
	int f = 0;
	cords*wsk = lista;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (lista == NULL)
	{
		printf("   ");
		for (int g = 0; g < n; g++)
		{
			SetConsoleTextAttribute(hConsole, 8);
			printf("%d ", g + 1);
			SetConsoleTextAttribute(hConsole, 7);
			if (g < 9)
				printf(" ");
		}
		printf("\n");
		for (int i = 0; i < m; i++)
		{
			SetConsoleTextAttribute(hConsole, 8);
			printf("%d ", i + 1);
			SetConsoleTextAttribute(hConsole, 7);
			if (i < 9)
				printf(" ");
			for (int j = 0; j < n; j++)
			{
				printf("%d%d ", p[i][j].ryb, p[i][j].numer);
			}
			printf("\n");
		}
		return;
	}
	if (wsk->next == NULL)
	{
		f = 1;
	}
	printf("   ");
	for (int g = 0; g < n; g++)
	{
		SetConsoleTextAttribute(hConsole, 8);
		printf("%d ", g + 1);
		SetConsoleTextAttribute(hConsole, 7);
		if(g<9)
			printf(" ");
	}
	printf("\n");
	for (int i = 0; i < m; i++)
	{
		SetConsoleTextAttribute(hConsole, 8);
		printf("%d ", i + 1);
		SetConsoleTextAttribute(hConsole, 7);
		if (i < 9)
			printf(" ");
		for (int j = 0; j < n; j++)
		{
			if(p[i][j].numer!=0)
				SetConsoleTextAttribute(hConsole, 3);
			if (f == 1)
			{
				cords*a = malloc(sizeof(cords));
				cords*b = malloc(sizeof(cords));
				a->x = wsk->x;
				a->y = wsk->y;
				a->next = b;
				b->x = j;
				b->y = i;
				b->next = NULL;
				if (czy_ruch(a,p,m,n))
				{
					SetConsoleTextAttribute(hConsole, 10);
				}
				if (wsk->x == j && wsk->y == i)
				{
					SetConsoleTextAttribute(hConsole, 4);
				}
				free(a);
				free(b);
			}
			 else if (wsk->x == j && wsk->y == i)
				{
				SetConsoleTextAttribute(hConsole, 10);
					if (wsk->next != NULL)
					{
						wsk=wsk->next;
					}
				}
			if(p[i][j].ryb==0&&p[i][j].numer==0)
				SetConsoleTextAttribute(hConsole, 0);
			printf("%d%d ", p[i][j].ryb, p[i][j].numer);
			SetConsoleTextAttribute(hConsole, 7);
		}
		printf("\n");
	}
}
#endif
unsigned int list_size(cords* lista)
{
	unsigned int c = 0;

	while (lista)
	{
		c++;
		lista = lista->next;
	}
	return c;
}
void wykonaj(plansza* p, cords* lista, gracz* g, int id)
{
	unsigned int l_size = list_size(lista);
	int x = 0;
	int y = 0;
	if (l_size == 1)
	{
		x = lista->x;
		y = lista->y;
		(*p)[y][x].numer = g[id].id;
		(*p)[y][x].ryb = 0;
		g[id].wynik++;
	}
	else
	{
		x = lista->x;
		y = lista->y;
		(*p)[y][x].numer = 0;
		x=lista->next->x;
		y=lista->next->y;
		(*p)[y][x].numer = g[id].id;
		g[id].wynik += (*p)[y][x].ryb;
		(*p)[y][x].ryb = 0;
	}
}
int sasiednie(plansza p, int x, int y, int m, int n) {
	if (x + 1 < m) {
		if (p[x + 1][y].ryb != 0 && p[x + 1][y].numer == 0) {
			return 1;
		}
	}
	if (x - 1 >= 0) {
		if (p[x - 1][y].ryb != 0 && p[x - 1][y].numer == 0) {
			return 1;
		}
	}
	if (y + 1 < n) {
		if (p[x][y + 1].ryb != 0 && p[x][y + 1].numer == 0) {
			return 1;
		}
	}
	if (y - 1 >= 0) {
		if (p[x][y - 1].ryb != 0 && p[x][y - 1].numer == 0) {
			return 1;
		}
	}
	return 0;
}
int czy_dp(int x, int y, cords* lista)//sprawdza czy pole o x,y jest w liscie
{
	//cords *wsk = lista;
	while (lista != NULL)
	{
		if (lista->x == x && lista->y == y)
		{
			return 1;
		}
		else
		{
			lista = lista->next;
		}
	}
	return 0;
}
int czy_ruch(cords* ruch, plansza p, int m, int n)
{
	if (ruch->next == NULL)
		return 0;
	if (ruch->x >= n || ruch->x < 0 || ruch->y >= m || ruch->y < 0 || ruch->next->x >= n || ruch->next->x < 0 || ruch->next->y >= m || ruch->next->y < 0  )
		return 0;
	if (ruch->x == ruch->next->x&&ruch->y == ruch->next->y)
	{
		return 0;
	}
	if (ruch->x == ruch->next->x)
	{
		int min = 0;
		int max = 0;
		if (ruch->y < ruch->next->y)
		{
			min = ruch->y;
			max = ruch->next->y;
		}
		else
		{
			max = ruch->y;
			min = ruch->next->y;
		}
		for (int i = min; i <= max; i++)
		{
			if (i != ruch->y)
			{
				if (p[i][ruch->x].ryb == 0)
				{
					return 0;
				}
			}
			if (i != ruch->y) {
				if (p[i][ruch->x].numer != 0)
				{
					return 0;
				}
			}
		}
		return 1;
	}
	if (ruch->y == ruch->next->y)
	{
		int min = 0;
		int max = 0;
		if (ruch->x < ruch->next->x)
		{
			min = ruch->x;
			max = ruch->next->x;
		}
		else
		{
			max = ruch->x;
			min = ruch->next->x;
		}
		for (int i = min; i <= max; i++)
		{
			if (i != ruch->x)
			{
				if (p[ruch->y][i].ryb == 0)
				{
					return 0;
				}
			}
			if (i != ruch->x) {
				if (p[ruch->y][i].numer != 0)
				{
					return 0;
				}
			}
		}
		return 1;
	}
	return 0;
}
#ifndef AI
int interaktywna(plansza* p, int m, int n, gracz* g, int faza,int pin)
{
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
		cords *przed=malloc(sizeof(cords));
		cords *po=malloc(sizeof(cords));
		przed->x = -1;
		przed->y = -1;
		po->x = -1;
		po->y = -1;
		po->next = NULL;
		przed->next = NULL;
		printf("FAZA nr %d\n", faza);
		while (czy_dp(przed->x, przed->y, lista) == 0) {
			while (czy_dp(przed->x, przed->y, lista) == 0)
			{
				wypisz_(*p, m, n, lista);
				printf("Podaj x pola:\n");
				while (przed->x <= 0 || przed->x > n)
				{
					przed->x = wczytajn();
				}
				printf("Podaj y pola:\n");
				while (przed->y <= 0 || przed->y > m)
				{
					przed->y = wczytajn();
				}
				przed->x--;
				przed->y--;
				if (czy_dp(przed->x, przed->y, lista) == 0)
				{
					printf("Nie mozesz wybrac tego pola\n");
					przed->x=-1;
					przed->y = -1;
				}
			}
			
			if (faza == 2)
			{
				wypisz_(*p, m, n, przed);
				printf("By zmienic pingiwina podaj x=0 lub y=0\n");
				while (czy_ruch(przed,*p,m,n)==0) 
				{
					printf("Podaj x pola:\n");
					while (po->x < 0 || po->x > n)
					{
						po->x = wczytajn();
					}
					printf("Podaj y pola:\n");
					while (po->y < 0 || po->y > m)
					{
						po->y = wczytajn();
					}
					if (po->x == 0 || po->y == 0)
					{
						przed->x = -1;
						przed->y = -1;
						po->x = -1;
						po->y = -1;
						break;
					}
					else
					{
						po->x--;
						po->y--;
						przed->next = po;
					}
					if (czy_ruch(przed,*p,m,n) == 0)
					{
						printf("Nie mozesz wybrac tego pola\n");
						po->x = -1;
						po->y = -1;
						przed->next = NULL;
					}
				}
			}
		}
			wykonaj(p, przed, g, id);
			free(przed);
			free(po);
			cords*wsk = lista->next;
			cords*wsk1;
			free(lista);
			while (wsk->next != NULL)
			{
				wsk1 = wsk;
				wsk = wsk->next;
				free(wsk1);
			}
			free(wsk);
			printf("wykonano ruch\n");
			return 0;
	}
	else
	{
		return 1;
	}
}
#endif