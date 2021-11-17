#include"CPEOPLE.h"

void CPEOPLE::Up(int y) {
	if(mY > 5)
		mY -= y;
}

void CPEOPLE::Left(int x) {
	if(mX > 0)
		mX -= x;
}

void CPEOPLE::Right(int x) {
	if(mX < 104)
		mX += x;
}

void CPEOPLE::Down(int y) {
	if(mY < 30)
		mY += y;
}

CPEOPLE::CPEOPLE() {
	mX = XPEOPLE;
	mY = YPEOPLE;
	mState = true;
}

CPEOPLE::~CPEOPLE() {
	mX = 0;
	mY = 0;
	mState = false;
}

//Kiểm tra có va chạm vào xe không?
bool CPEOPLE::isImpact(const CVEHICLE* xe, int n) {
	for (int i = 0; i < n; i++) {
		if (mX >= xe[i].getX() && mX <= (xe[i].getX() + 11) && (mY-1) == xe[0].getY() ) {
			this->mState = false;
			return true;
		}
	}
	
	return false;
}

//Có va chạm vào động vật không
bool CPEOPLE::isImpact(const CANIMAL* dv, int n) {
	for (int i = 0; i < n; i++) {
		if (mX >= dv[i].getX() && mX <= dv[i].getX() + 11 && (mY - 1) == dv[0].getY() ) {
			this->mState = false;
			return true;
		}
	}

	
	return false;
}

//Nếu va chạm thì trạng thái là chết
bool CPEOPLE::isDead() {
		if (mState == false) {
			return true;
		}
		return false;
	}

//Kiểm tra người chơi đã đến đích để chuyển sang level mới
bool CPEOPLE::isFinish() {
	if (mY >= 0 && mY <= 6)
		return true;

	return false;
}

