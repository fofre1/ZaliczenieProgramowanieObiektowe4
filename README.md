// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

template <class Typ, class U>
U suma(Typ Zmienna, int pocz, int ile) {
    U sum = 0;
    for (int i = pocz; i < pocz + ile; i++)
        sum += Zmienna[i];
    return sum;
}

bool Parzysta(int zmienna) {
    return zmienna % 2 == 0;
}

bool Pierwsza(int zmienna) {
    for (int i = 2; i < zmienna / 2; i++) {
        if (zmienna % i) return false;
    }
    return true;
}

template <class Typ>
bool MniejszaOd7(Typ zmienna) {
    return (zmienna < 7);
}

/*
int IleSpelnia(int tab[], int ile, bool (*Kryterium)(int)) {
    int suma=0;
    for (int i = 0; i < ile; i++) {
        suma += Kryterium(tab[i]);
    }
    return suma;
 
}*/

template <class T, class K>
int IleSpelnia(T tab[], int ile, K Kryterium) {
    T suma = 0;
    for (int i = 0; i < ile; i++) {
        suma += Kryterium(tab[i]);
    }
    return suma;
}



/*
int suma(int tab[], int pocz, int ile) {
    int sum = 0;
    for (int i = pocz; i < pocz+ile; i++)
        sum += tab[i];
    return sum;
}

float suma(float tab[], int pocz, int ile) {
    float sum = 0;
    for (int i = pocz; i < pocz + ile; i++)
        sum += tab[i];
    return sum;
}
*/

struct Kwadrat {
    bool operator()(float x) {
        double p = sqrt(x);
        return p == (int)p;
    }
};


int main()
{
    int tab[] = { 5, 6, 7, 8, 19 };
    std::cout << suma<int[], int>(tab, 0, 5)<<std::endl;

    float tabf[] = { 5, 6.6, 7, 3, 9 };
    std::cout << suma<float[], float>(tabf, 0, 5) << std::endl;
    
    vector<int> tabv= { 5, 6, 7, 8, 9 };
    std::cout << suma<vector<int>, int>(tabv, 0, 5) << std::endl;

    std::cout<<"Ile parzystych?: " << IleSpelnia(tab, 5, Parzysta) << std::endl;
    std::cout<<"Ile jest liczb pierszych?: " << IleSpelnia(tab, 5, Pierwsza) << std::endl;
    std::cout << "Ile mniejszch niz 7?: " << IleSpelnia(tabf, 5, MniejszaOd7<float>) << std::endl;
    Kwadrat k;
    std::cout << "Kwadraty?: " << IleSpelnia(tabf, 5, MniejszaOd7<float>) << std::endl;

}

