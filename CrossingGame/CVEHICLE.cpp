#include"CVEHICLE.h"

void CVEHICLE::Move(int xVehicle, int yVehicle) {
	mX = xVehicle;
	mY = yVehicle;
}

void CCAR::Move(int xCar, int yCar) {
	this->printSmallCarLTR(xCar, yCar);
}

void CCAR::printSmallCarLTR(int x, int y) {
	GotoXY(x, y);     wcout << "   _____";
	GotoXY(x, y + 1); wcout << " _/[] []\\_";
	GotoXY(x, y + 2); wcout << "|_________|";
	GotoXY(x, y + 3); wcout << "  O     O";
}

void CTRUCK::Move(int xTruck, int yTruck) {
	this->printSmallTruck(xTruck, yTruck);
}

void CTRUCK::printSmallTruck(int x, int y) {
	GotoXY(x, y);     wcout << L" ______";
	GotoXY(x, y + 1); wcout << L"│      │__";
	GotoXY(x, y + 2); wcout << L"│______│__│";
	GotoXY(x, y + 3); wcout << L" O        O";
}