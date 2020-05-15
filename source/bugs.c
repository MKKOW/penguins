#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include"bugs.h"
#include"plansza.h"
int czy_pole(char** w,int*g)
{
	if (isspace((*w)[2])==0&& (*w)[2]!='\0')
		return 0;
	if (**w<'0' || **w>'3')
		return 0;
	if (**w == '0')
	{
		if ((*w)[1]<'0' || (*w)[1]>'9')
		{
			return 0;
		}
	}
	else
	{
		if ((*w)[1] != '0')
			return 0;
	}
	g[(*w)[1] - '0']++;
	(*w) += 2;
	return 1;
}
int czy_naturalna(char** w)
{
	int x = 0;
	while (isspace(**w)==0&&**w!='\0')
	{
		x *= 10;
		if(**w < '0' || **w > '9')
		{
			return -1;
		}
		else
		{
			x += **w - '0';
			(*w)++;
		}
	}
	return x;
}
int czy_naturalna_s(char* w)
{
	int x = 0;
	while (isspace(*w) == 0 && *w != '\0')
	{
		x *= 10;
		if (*w < '0' || *w > '9')
		{
			return -1;
		}
		else
		{
			x += *w - '0';
			w++;
		}
	}
	return x;
}
int czy_wymiary(char* w,int* m,int* n)
{
	char* t = w;
	*m = 0;
	*n = 0;
	while (*t != '\0')
	{
		if (isspace(*t))
		{
			t++;
		}
		else if (*t < '0' || *t>'9')
		{
			*m = 0;
			*n = 0;
			return 0;
		}
		else if(*m==0)
		{
			*m = czy_naturalna(&t);
			if (*m == -1)
			{
				*m = 0;
				*n = 0;
				return 0;
			}
		}
		else if (*m != 0 && *n == 0)
		{
			*n = czy_naturalna(&t);
			if (*n == -1)
			{
				*m = 0;
				*n = 0;
				return 0;
			}
		}
		else if (*m != 0 && *n != 0)
		{
			*m = 0;
			*n = 0;
			return 0;
		}
	}
	return 1;
}
int czy_wiersz(char* w, int n,int*g)
{
	int i = 0;
	int j = 0;
	char* t = w;
	while (*t != '\0')
	{
		if (isspace(*t))
		{
			j++;
			t++;
		}
		else if (czy_pole(&t,g))
		{
			i++;
			j = 0;
		}
		else
		{
			return 0;
		}
	}
	if (i != n)
	{
		return 0;
	}
	return 1;
}
int czy_gracz(char* w)
{
	char* t = w;
	int id = 0;
	while (isspace(*t) == 0)
	{
		if (*t == '\0')
			return 0;
		t++;
	}
	if (*t == '\0')
	{
		return 0;
	}
	else
	{
		t++;
		if (*t > '0'&&*t <= '9')
		{
			id = *t - '0';
			t++;
			if (isspace(*t) == 0)
				return 0;
			t++;
			if (*t == '\0')
			{
				return 0;
			}
			else
			{
				if (czy_naturalna(&t))
				{
					t++;
					if (*t == '\0')
						return id;
					else
						return 0;
				}
				else
					return 0;
			}
		}
		else
			return 0;
	}
}
int sprawdzplik(plik p, int*m, int*n)
{
	char buf[1024];
	int g[10];
	int id[10];
	int f = 0;
	for (int i = 0; i < 10; i++)
	{
		id[i] = 0;
		g[i] = 0;
	}
	fgets(buf, 1024, p);
	if (czy_wymiary(buf, m, n) == 0)
	{
		printf("Blad przy wczytaniu: Bledne wymiary\n");
		return 0;
	}
	else
	{
		for (int i = 0; i < *m; i++)
		{
			fgets(buf, 1024, p);
			if (czy_wiersz(buf, *n,g)==0)
			{
				printf("Blad przy wczytaniu: Bledna plansza\n");
				return 0;
			}
		}
		while (fgets(buf,1024,p)!=NULL)
		{
			f++;
			int x = czy_gracz(buf);
			if (id[x] != 0)
			{
				printf("Blad przy wczytaniu: Bledny dwa takie same  id\n");
				return 0;
			}
			if (x == 0)
			{
				printf("Blad przy wczytaniu: Bledny gracz\n");
				return 0;
			}
			g[x] = 0;
		}
		for (int i = 1; i < 10; i++)
		{
			if (g[i] != 0)
			{
				printf("Blad przy wczytaniu: Bez panskie pingwiny\n");
				return 0;
			}
		}
	}
	if (f == 0)
	{
		return 2;
	}
	return 1;
}