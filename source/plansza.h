#pragma once
#include<stdlib.h>
#include<stdio.h>
#include"bugs.h"
/*wiersz na_wiersz(char* w);
gracz na_gracza(char* w);
//mo¿e siê przydadz¹*/
struct pole {
	int ryb;
	int numer;
};
struct wspol {
	int x;
	int y;
	struct wspol* next;
};
struct gracz {
	char* name;
	int id;
	int wynik;
};
typedef struct pole pole;
typedef struct wspol cords;
typedef struct gracz gracz;
typedef pole* wiersz;
typedef wiersz* plansza;
typedef FILE* plik;
int zmiennaint(char* s);
int czyn(char* s);
int wczytaj(char* in, plansza* p, int*m,int*n, gracz* g);
int zapisz(char* out, plansza p, int m, int n, gracz* g);
int policz(plansza p, int m, int n, int id);
void wypisz(plansza p,int m,int n,plik out);