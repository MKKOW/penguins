typedef FILE* plik;
int czy_wymiary(char* w,int* m,int* n);//dzia�a
int czy_wiersz(char* w,int n,int*g);//dzia�a
int czy_gracz(char* w);//dzia�a, zwraca id gracza je�li wiersz dobrze sformatowany, 0 je�li b��d
int czy_naturalna(char** w);//dzia�a, przesuwa podany wska�nik na znak bia�y za liczb�, argumentem adres(&) wska�nika 
int czy_naturalna_s(char* w);//dzia�a, nie modyfikuje argumentu
int czy_pole(char** w,int*g);//dzia�a
int sprawdzplik(plik p, int*m, int*n);