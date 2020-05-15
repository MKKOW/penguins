#pragma once
#include"plansza.h"
int czy_dp(int x, int y, cords* lista);
int interaktywna(plansza* p, int m, int n, gracz* g, int faza,int pin);
/*
zwraca
0 - program wykona� prawid�owy ruch
1 - program nie m�g� wykona� �adnego ruchu (w przypadku pierwszej fazy, wszystkie pingwiny
ju� wcze�niej zosta�y umieszczone na planszy, w przypadku fazy drugiej, �aden pingwin nie
mo�e wykona� ruchu)
3 - b��d wewn�trzny programu
*/

void wypisz_(plansza p, int m, int n, cords* lista);//wypisuje na ekran plansze, pod�wietla pola z pingwinami/mozliwe ruchy
int analiza(plansza p, int m, int n, gracz* g, int faza, cords** lista, int* id);
/*analizuje czy mozliwe jest wykonanie jakiegos ruchu, 
	zapisuje w cords* lista liste mozliwych ruchow
	w int* id numer naszego gracza
	w przypadku gdy nie ma nszego gracza dopisuje go w odpowiednim miejscu tablicy g
zwraca
	0 - jak nie jest mozliwy zaden ruch
	1 - jak sa mozliwe ruchy*/
void wykonaj(plansza* p, cords* lista, gracz* g, int id);// modyfikuje plansze, dodaje wynik graczowi
int sasiednie(plansza p, int x, int y, int m, int n);
int czy_ruch(cords*ruch, plansza p,int m ,int n);
unsigned int list_size(cords* lista);