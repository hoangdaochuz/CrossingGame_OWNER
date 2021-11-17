
#pragma once
#include"GUI.h"


class CVEHICLE {
	int mX, mY;
public:
	virtual void Move(int, int);

	int getX() const {
		return mX;
	}
	int getY() const{
		return mY;
	}
	void setX(int x) {
		mX = x;
	}
	void setY(int y) {
		mY = y;
	}
};

class CCAR : public CVEHICLE {
public:
	void Move(int xCar, int yCar);
	void printSmallCarLTR(int xCar,int yCar);
};

class CTRUCK : public CVEHICLE {
public:
	void Move(int xTruck, int yTruck);
	void printSmallTruck(int xTruck,int yTruck);
};