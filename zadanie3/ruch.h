#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Plansza;

class Ruch {
public:
	void Move(Plansza plansza, int xRuszanego, int yRuszanego, int xNowego, int yNowego);
	/*
	IsMovable
	CanFall
	IsNextToItsType

	*/

private:
};
