typedef FILE* plik;
int czy_wymiary(char* w,int* m,int* n);//dzia≥a
int czy_wiersz(char* w,int n,int*g);//dzia≥a
int czy_gracz(char* w);//dzia≥a, zwraca id gracza jeúli wiersz dobrze sformatowany, 0 jeúli b≥πd
int czy_naturalna(char** w);//dzia≥a, przesuwa podany wskaønik na znak bia≥y za liczbπ, argumentem adres(&) wskaünika 
int czy_naturalna_s(char* w);//dzia≥a, nie modyfikuje argumentu
int czy_pole(char** w,int*g);//dzia≥a
int sprawdzplik(plik p, int*m, int*n);