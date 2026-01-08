#pragma once
#include "bloczek.h"
#include <vector>

using namespace std;

class Plansza {
public:
	void PokazPlansze();
	Plansza(const char* input);
	~Plansza();
	void OneTurn(int x, int y, char gdzie);
	void Move(int xRuszanego, int yRuszanego, int xNowego, int yNowego);
	bool IsMovable(int xRuszanego, int yRuszanego, char Gdzie);
	bool CanFall(int x, int y);
	int IsNextToItsType(int x, int y); // 0-nie, 1-lewo, 2-prawo, 3-lewo i prawo, 4-dol, 5-dol i lewo, 6-dol i prawo, 7, wszedzie 
	void DeleteNextToIt(int x, int y, int whichTypeOfDeletion);
	void UsunBloczek(int x, int y);
	char IsWon();
	/*
	CanFall
	IsNextToItsType

	*/
private:
	int wysokosc = 0;
	int szerokosc = 0;
	vector <Bloczek>plansza;
	string nazwa;
};
