#include<stdio.h>
#include"napisy.h"
#include<string.h>
int zmiennaint(char* s)//zamiana s na int (zakladam ze s jest poprawnie sformatowane)
{
	int x = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		x *= 10;
		x += s[i] - '0';
		i++;
	}
	return x;
}
int czyn(char* s)//sprawdzenie czy s jest liczba naturslna
{
	if (strlen(s) == 0)
	{
		return 0;
	}
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] - '0' < 0 || s[i] - '0'>9)
		{
			return 0;
		}
		i++;
	}
	return 1;
}
void kopiujnapis(char* c, char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
}
int czyliczba(char *s)
{
	if (strlen(s) == 0)
	{
		return 0;
	}
	int i = 0;
	int czyprzecinek = 0;
	while (s[i] != '\0')
	{

		if (s[i] == ',' || s[i] == '.')
		{
			s[i] = '.';
			czyprzecinek++;
			if (czyprzecinek > 1)
			{
				return 0;
			}
		}
		else if (s[i] - '0' < 0 || s[i] - '9'>9)
		{
			return 0;
		}
		i++;
	}
	return 1;
}
double zamiendouble(char* s)// zamiana s na double (nie zakladam ze s jest poprawnie sformatowane)
{
	int i = 0;
	double x = 0;
	double dzielnik = 1;
	int czyprzecinek = 0;
	if (czyliczba(s) == 1)
	{
		while (s[i] != '\0')
		{
			if (s[i] != '.')
			{
				x *= 10;
				x += s[i] - '0';
			}
			else
			{
				czyprzecinek = 1;
				dzielnik /= 10;
			}
			if (czyprzecinek == 1)
			{
				dzielnik *= 10;
			}
			i++;
		}
		x /= dzielnik;
	}
	else
	{
		x = -1000;
	}
	return x;
}
int wczytajn()
{
	char x[20];
	do {
		scanf("%s", x);
	} while (czyn(x) == 0);
	return zmiennaint(x);
}
int porownaj(char* a, char* b)
{
	int i = 0;
	while (a[i] != '\0'&&b[i] != '\0')
	{
		if (a[i] > b[i])
			return 1;
		i++;
	}
	return 0;
}
int sprawdz_czy_nazwa(char* w)
{
	int i = 1;
	if (strlen(w) == 0)
	{
		return 0;
	}
	if (w[0]<'A' || w[0]>'Z')
	{
		return 0;
	}
	while (w[i] != '\0')
	{
		if (w[i]<'a' || w[i]>'z')
		{
			return 0;
		}
		i++;
	}
	return 1;
}