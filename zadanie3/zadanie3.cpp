#include <iostream>
#include <fstream>
#include "plansza.h"
#include "bloczek.h"



int main(){
    int x, y;
    char a;
    Plansza test("1.txt");
    string ruch;
    char wygrana = 1; //1-gra trwa, 2-gra wygrana, 3-gra przegrana
    while (wygrana == 1) {
        test.PokazPlansze();
        cout << endl << "Czym chcesz ruszyć: "<<endl<<"Pozycja x: ";
        cin >> x;
        cout << "Pozycja y: ";
        cin >> y;
        cout << "Lewo (L) / Prawo (P): ";
        cin >> a;
        test.OneTurn(x, y, a);
        wygrana = test.IsWon();
        system("cls");
    }
    if (wygrana == 2)
        cout << "Gratulacje, wygrales" << endl;
    if (wygrana == 3)
        cout << "Przegrana, nie ma wiecej ruchow" << endl;
    
}   