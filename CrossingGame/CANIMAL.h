#pragma once
#include"GUI.h"



class CANIMAL{
	int mX, mY;
public:
	virtual void Move(int, int);
	int getX() const{
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

class CBAT : public CANIMAL {
public:
	void Move(int xBat, int yBat);
	void printSmallBat(int xBat,int yBat);
};

class CCROCODILE : public CANIMAL {
public:
	void Move(int xCroc, int yCroc);
	void printSmallCrocodile(int xCroc,int yCroc);

};