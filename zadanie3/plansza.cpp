#include "plansza.h"
void Plansza::PokazPlansze()
{
	for (int i = 0; i < wysokosc * szerokosc; i++) {
		if (i != 0 && i % szerokosc == 0)
			cout << endl;
		cout << plansza[i].typ;
	}
}

Plansza::Plansza(const char* input)
{
	fstream plik;
	plik.open(input, ios::in);
	if (!plik.is_open()) {
		cout << "Nie mozna otworzyc pliku" << endl;
		return;
	}
	plik >> wysokosc >> szerokosc;
	string nazwa;
	plik >> nazwa;
	char a;
	this->nazwa = nazwa;
	for (int i = 0; i < wysokosc * szerokosc; i++) {
		plik >> a;
		Bloczek w;
		w.typ = a;
		plansza.push_back(w);
	}
}

Plansza::~Plansza()
{
}


void Plansza::Move(int xRuszanego, int yRuszanego, int xNowego, int yNowego)
{
	Bloczek temp = this->plansza[yNowego * szerokosc + xNowego];
	this->plansza[yNowego * szerokosc + xNowego] = this->plansza[yRuszanego * szerokosc + xRuszanego];
	this->plansza[yRuszanego * szerokosc + xRuszanego] = temp;
}

bool Plansza::IsMovable(int xRuszanego, int yRuszanego, char gdzie)
{
	int ruch=0; //1 - lewo, 2 - prawo, 0 - niewlasciwa wartosc
	if (xRuszanego > this->szerokosc || yRuszanego > this->wysokosc || xRuszanego < 0 || yRuszanego < 0)
		return 0;
	if (this->plansza[yRuszanego * szerokosc + xRuszanego].typ == '#' || this->plansza[yRuszanego * szerokosc + xRuszanego].typ == '-')
		return 0;
	if (gdzie == 'L' || gdzie == 'l')
		ruch = 1;
	else if (gdzie == 'P' || gdzie == 'p')
		ruch = 2;
	else
		return 0;
	switch (ruch) {
	case 1:
		if (xRuszanego == 0)
			return 0;
		if (this->plansza[yRuszanego * szerokosc + xRuszanego - 1].typ != '-')
			return 0;
		break;
	case 2:
		if (xRuszanego == this->szerokosc-1)
			return 0;
		if (this->plansza[yRuszanego * szerokosc + xRuszanego + 1].typ != '-')
			return 0;
		break;
	}
	return 1;
}

bool Plansza::CanFall(int x, int y)
{
	if (this->plansza[y * szerokosc + x].typ == '#')
		return 0;
	if (y == wysokosc - 1)
		return 0;
	if (this->plansza[(y + 1) * szerokosc + x].typ != '-')
		return 0;
	return 1;
}
// 0-nie, 1-lewo, 2-prawo, 3-lewo i prawo, 4-dol, 5-dol i lewo, 6-dol i prawo, 7 wszedzie
int Plansza::IsNextToItsType(int x, int y)
{
	int isNextTo = 0;
	//Prawo
	if (x < this->szerokosc - 1 && this->plansza[y * szerokosc + x + 1].typ == this->plansza[y * szerokosc + x].typ)
		isNextTo += 2;
	//Lewo
	if (x>0 && this->plansza[y * szerokosc + x - 1].typ == this->plansza[y * szerokosc + x].typ)
		isNextTo += 1;
	//Dó³
	if (y < this->wysokosc - 1 && this->plansza[(y + 1) * szerokosc + x].typ == this->plansza[y * szerokosc + x].typ)
		isNextTo += 4;
	return isNextTo;
}


void Plansza::UsunBloczek(int x, int y)
{
	this->plansza[y * szerokosc + x].typ = '-';
}


void Plansza::DeleteNextToIt(int x, int y, int whichTypeOfDeletion)
{
	const int LEWO = 1, PRAWO = 2, DOL = 4;
	// 0-nie, 1-lewo, 2-prawo, 3-lewo i prawo, 4-dol, 5-dol i lewo, 6-dol i prawo, 7, wszedzie
	switch (whichTypeOfDeletion) {
	case 0:
		return;
	case LEWO:
		UsunBloczek(x - 1, y);
		break;
	case PRAWO:
		UsunBloczek(x + 1, y);
		break;
	case PRAWO+LEWO:
		UsunBloczek(x + 1, y);
		UsunBloczek(x - 1, y);
		break;
	case DOL:
		UsunBloczek(x, y + 1);
		break;
	case LEWO+DOL:
		UsunBloczek(x - 1, y);
		UsunBloczek(x, y + 1);
		break;
	case PRAWO+DOL:
		UsunBloczek(x + 1, y);
		UsunBloczek(x, y + 1);
		break;
	case LEWO+PRAWO+DOL:
		UsunBloczek(x - 1, y);
		UsunBloczek(x + 1, y);
		UsunBloczek(x, y + 1);
		break;
	default:
		return;
	}
	UsunBloczek(x, y);
}

void Plansza::OneTurn(int x, int y, char gdzie)
{
	int aktualneX=x, aktualneY=y;
	if (IsMovable(x, y, gdzie)){
		if (gdzie == 'P' || gdzie == 'p') {
			Move(x, y, x + 1, y);
			aktualneX++;
		}
		else if (gdzie == 'L' || gdzie == 'l') {
			Move(x, y, x - 1, y);
			aktualneX--;
		}
		while (CanFall(aktualneX, aktualneY)) {
			Move(aktualneX, aktualneY, aktualneX, aktualneY+1);
			aktualneY++;
		}
		DeleteNextToIt(aktualneX, aktualneY, IsNextToItsType(aktualneX, aktualneY));
		for (int i = 0; i < (wysokosc-1) * szerokosc; i++) {
			int ax=i%szerokosc, ay=(i-ax)/szerokosc;
			if (CanFall(ax, ay))
				Move(ax, ay, ax, ay + 1);
		}
		bool p=true;
		while (p) {
			bool a = false;
			for (int i = 0; i < (wysokosc - 1) * szerokosc; i++) {
				if (this->plansza[i].typ == '-' || this->plansza[i].typ == '#')
					continue;
				int ax = i % szerokosc, ay = (i - ax) / szerokosc;
				if (CanFall(ax, ay)) {
					Move(ax, ay, ax, ay + 1);
					a = 1;
				}
			}
			for (int i = 0; i < (wysokosc - 1) * szerokosc; i++) {
				if (this->plansza[i].typ == '-' || this->plansza[i].typ == '#')
					continue;
				int ax = i % szerokosc, ay = (i - ax) / szerokosc;
				if (IsNextToItsType(ax, ay)) {
					DeleteNextToIt(ax, ay, IsNextToItsType(ax, ay));
					a = 1;
				}
			}
			p = a;
		}
	}
	
}

char Plansza::IsWon()
{
	int ax, ay;
	int czyJestRuch = 0, czyJestBloczek = 0;
	for (int i = 0; i < (wysokosc) * szerokosc; i++) {
		if (this->plansza[i].typ != '-' && this->plansza[i].typ != '#')
			czyJestBloczek++;
	}
	if (czyJestBloczek == 0)
		return 2;
	for (int i = 0; i < (wysokosc) * szerokosc; i++) {
		if (this->plansza[i].typ == '-' || this->plansza[i].typ == '#')
			continue;
		ax = i % szerokosc;
		ay = i / szerokosc;
		if (IsMovable(ax, ay, 'P') == 1 || IsMovable(ax, ay, 'L') == 1)
			czyJestRuch++;
	}
	if (czyJestRuch == 0)
		return 3;
	return 1;
}