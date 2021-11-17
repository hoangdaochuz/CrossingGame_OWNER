#include"CANIMAL.h"

void CANIMAL::Move(int xAnimal, int yAnimal) {
	mX = xAnimal;
	mY = yAnimal;
}


void CCROCODILE::Move(int xCroc, int yCroc) {
	this->printSmallCrocodile(xCroc, yCroc);
}

void CCROCODILE::printSmallCrocodile(int x, int y) {
	GotoXY(x, y);	  wcout << "   _     _^ ";
	GotoXY(x, y + 1); wcout << " _/'|-^-//";
	GotoXY(x, y + 2); wcout << "|^______/";
	GotoXY(x, y + 3); wcout << " o     o";
}

void CBAT::Move(int xBat, int yBat) {
	this->printSmallBat(xBat, yBat);
}

void CBAT::printSmallBat(int x, int y) {
	GotoXY(x, y);     wcout << "__       __";
	GotoXY(x, y + 1); wcout << ") \\__V__/ (";
	GotoXY(x, y + 2); wcout << " )__   __(";
	GotoXY(x, y + 3); wcout << "    `-'";
}