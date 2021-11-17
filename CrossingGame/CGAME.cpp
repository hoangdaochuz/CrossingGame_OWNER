#include"CGAME.h"

//Luong chuong trinh
//PlayGame -> While (StartGame, Resest Game, Update Pos)

bool IS_RUNNING = false;
extern CGAME* cg;//Biến toàn cục của hàm main
extern char MOVING;//biến lấy kí tự nhấn phím

//Hàm tạo
CGAME::CGAME() {
	axh = NULL;
	axt = NULL;
	ad = NULL;
	cn = NULL;
	level = 1;
}

//Hàm hủy
CGAME::~CGAME() {
	delete[]axh;
	axh = NULL;
	delete[]axt;
	axt = NULL;
	delete[]ad;
	ad = NULL;
	delete cn;
	level = 1;
}

void CGAME::DebugOutput(int x) {
	GotoXY(x, 33); wcout << "Level " << cg->level;
	GotoXY(x, 34); wcout << "People Poss x: " << cg->cn->getX() << " y: " << cg->cn->getY() <<" ";
	GotoXY(x, 35); wcout << "People status: " << cg->cn->getMState();
	
	int oldPos;
	for (int i = 0; i < getNumObjects(); i++) {
		GotoXY(x, 1 + i); wcout << "Xe hoi " << i << " poss x:" << cg->axh[i].getX() << " y:" << cg->axh[i].getY();
	}
	for (int i = 0; i < getNumObjects(); i++) {
		GotoXY(x,1 + getNumObjects() + i); wcout <<"Xe tai " << i << " poss x:" << cg->axt[i].getX() << " y:" << cg->axt[i].getY();
	}
	for (int i = 0; i < getNumObjects(); i++) {
		GotoXY(x, 1 + getNumObjects()*2 + i); wcout << "Con doi " << i << " poss x:" << cg->ad[i].getX() << " y:" << cg->ad[i].getY();
	}
	for (int i = 0; i < getNumObjects(); i++) {
		GotoXY(x, 1 + getNumObjects() * 3 + i); wcout << "Ca sau " << i << " poss x:" << cg->acs[i].getX() << " y: " << cg->acs[i].getY();
	}
}

void CGAME::setLevel(int level) {
	level = level;
}

int CGAME::getLevel() {
	return level;
}

//Hàm set số lượng object tối đa trong một level
void CGAME::setNumbetObjects(int num) {
	this->numObjects = num;
}

//Hàm lấy số lượng object tối đa trong một level
int CGAME::getNumObjects() {
	if (level == 1) {
		this->numObjects = MAX_LV1;
	}
	else if (level == 2) {
		this->numObjects = MAX_LV2;
	}
	else if (level == 3) {
		this->numObjects = MAX_LV3;
	}
	else if (level == 4) {
		this->numObjects = MAX_LV4;
	}

	return this->numObjects;
}

//Khởi tạo giá trị mặc định cho Game
void CGAME::resetGame(int level) {
	cg->setLevel(level);
	int maxObjectInLevel = cg->getNumObjects();//So doi tuong xe, con vat toi da trong mot tro choi
	
	//Khoi tao danh sach xe hoi
	axh = new CCAR[maxObjectInLevel];
	for (int i = 0; i < maxObjectInLevel; i++) {
		axh[i].setX(2);
		axh[i].setY(YCAR);
	}

	//Khoi tao danh sach xe tai
	axt = new CTRUCK[maxObjectInLevel];
	for (int i = 0; i < maxObjectInLevel; i++) {
		axt[i].setX(2);
		axt[i].setY(YTRUCK);
	}

	//Khoi tao danh sach con doi
	ad = new CBAT[maxObjectInLevel];
	for (int i = 0; i < maxObjectInLevel; i++) {
		ad[i].setX(RIGHT_ANIMAL);
		ad[i].setY(YBAT);
	}

	//Khoi tao danh sach con ca sau
	acs = new CCROCODILE[maxObjectInLevel];
	for (int i = 0; i < maxObjectInLevel; i++) {
		acs[i].setX(RIGHT_ANIMAL);
		acs[i].setY(YCROC);
	}

	cn = new CPEOPLE();
}

//Vẽ đường
void CGAME::drawGame() {
	CDRAW cdraw;
	for (int i = 0; i <= HEIGHTROAD * 6; i += HEIGHTROAD) {
		for (int j = 0; j < WIDTHROAD; j++) {
			GotoXY(j, i); wcout << L'─';
		}
	}
	GotoXY(WIDTHROAD, 0); wcout << L'┐';
	for (int i = 1; i <= HEIGHTROAD * 6 - 1; i++) {
		GotoXY(WIDTHROAD, i); wcout << L'│';
	}
	GotoXY(WIDTHROAD, HEIGHTROAD * 6); wcout << L'┘';

	//Hop con nho ben duoi
	cdraw.printBox(137, 17, 35, 19);
	GotoXY(138, 18); wcout << L"use      or         to move";
	GotoXY(138, 19); wcout << L"Press: ' ' to pause game ";
	GotoXY(138, 20); wcout << L"Press: ' ' to resume game ";
	GotoXY(138, 21); wcout << L"Press: ' ' to load game ";
	SetColor(_LIGHTBLUE); GotoXY(138 + 4, 18); wcout << L"WASD"; GotoXY(138 + 12, 18); wcout << L"↑ ← ↓ →";
	GotoXY(138 + 8, 19); wcout << L"P"; GotoXY(138 + 8, 20); wcout << L"R"; GotoXY(138 + 8, 21); wcout << L"L";
	SetColor(_WHITE);


		
}
//Cho xe di chuyển
void CGAME::updatePosVehicle(CVEHICLE *xe, int y) {
	int flag = 0, xOld;
	int maxObjectInLevel = cg->getNumObjects();//So doi tuong xe, con vat toi da trong mot tro choi
	for (int i = 0; i < maxObjectInLevel; i++) {
		int x = xe[i].getX(); 
		int y = xe[i].getY();

		if (i == 0) {
			DeleteImageOld(x - 2, y, 10, 4);//Xóa vị trí xe cũ để in xe mới
			xe[i].Move(x, y);//Di chuyển xe
			xe[i].setX(x + 2);
		}
		else if (i != 0) {
			//Để cho xe đầu tiên chạy được một đoạn rồi mới cho các xe sau chạy
			if (xe[i - 1].getX() >= 24 || x >= 24) {
				DeleteImageOld(x - 2, y, 10, 4);
				xe[i].Move(x, y);
				xe[i].setX(x + 2);
			}
		}

		if (xe[i].getX() == RIGHT_VEHICLE) {
			flag = 1;//Để thiết lập lại ví trí xe khi đến cuối đường
			xOld = xe[i].getX();
			xe[i].setX(LEFTROAD + 2);
		}
		if (flag == 1) {
			DeleteImageOld(xOld - 2, y, 10, 4);//Xóa ảnh object cuối cùng
			flag = 0;
		}
		xe[i].setY(y);
	}
}

//Tương tự như hàm updatePosVehicle
void CGAME::updatePosAnimal(CANIMAL *dv, int y) {
	int flag = 0, xOld;
	int maxObjectInLevel = cg->getNumObjects();//So doi tuong xe, con vat toi da trong mot tro choi
	for (int i = 0; i < maxObjectInLevel; i++) {
		int x = dv[i].getX();
		int y = dv[i].getY();

		if (i == 0) {
			DeleteImageOld(x + 2, y, 10, 4);
			dv[i].Move(x, y);
			dv[i].setX(x - 2);
		}
		else if (i != 0) {
			if (dv[i - 1].getX() <= 72 || x <= 72) {
				DeleteImageOld(x + 2, y, 10, 4);
				dv[i].Move(x, y);
				dv[i].setX(x - 2);
			}
		}

		if (dv[i].getX() == LEFTROAD) {
			flag = 1;
			xOld = dv[i].getX();
			dv[i].setX(RIGHT_ANIMAL);
		}
		if (flag == 1) {
			DeleteImageOld(xOld + 2, y, 10, 4);
			flag = 0;
		}
		dv[i].setY(y);
	}
}

CVEHICLE* CGAME::getCars() {
	return axh;
}

CVEHICLE* CGAME::getTrucks() {
	return axt;
}

CANIMAL* CGAME::getBats() {
	return ad;
}

CANIMAL* CGAME::getCrocodile() {
	return acs;
}

//Hàm kiểm tra có đụng vào vật cản không
CPEOPLE *CGAME::getPeople() {
	cn->isImpact(axh, cg->getNumObjects());
	cn->isImpact(axt, cg->getNumObjects());
	cn->isImpact(ad, cg->getNumObjects());
	cn->isImpact(acs, cg->getNumObjects());
	
	return cn;
}

void CGAME::startGame() {
	CDRAW cdraw;
	system("cls");
	ShowCur(0);
	//cdraw.printLoading(); 

	system("cls");
	SetColor(_GRAY);

	IS_RUNNING = true;//Khởi tạo biến là true để bắt đầu thread vào trò chơi
}

void CGAME::pauseGame() {
	IS_RUNNING = false;
}

void CGAME::resumeGame() {
	IS_RUNNING = true;
}

bool gameIsRunning() {
	if (IS_RUNNING == true)
		return true;
	return false;
}

void CGAME::updatePosPeople(char MOVING) {
	//Lấy các vị trí x cũ và y cũ để xóa ảnh đối tượng cũ in đối tượng mới
	int xOld = cn->getX();
	int yOld = cn->getY();
	DeleteImageOld(xOld, yOld, 4, 3);
	if (MOVING == 'W' || MOVING == _UPkey) {
		cn->Up(6);//Bước đi lên
	}
	else if (MOVING == 'S' || MOVING == _DOWNkey) {
		cn->Down(6);//Bước đi xuống
	}
	else if (MOVING == 'A' || MOVING == _LEFTkey) {
		
		cn->Left(3);//Qua trái
	}
	else if (MOVING == 'D' || MOVING == _RIGHTkey) {
		cn->Right(3);//Qua phải
	}
	printPeople(cn->getX() , cn->getY());//Bắt đầu in người
	
}

//Ham cap nhap


void CGAME::PlayGame() {
	while (IS_RUNNING) {
		
		CDRAW cdraw;
		cdraw.printLevel(144, 1, cg->getLevel());
		cg->DebugOutput(178);
		cg->updatePosPeople(MOVING);

		
		
		//Kiểm tra tình trạng người chơi còn sống không?
		/*if (!cg->getPeople()->isDead()) {*/
		//}
		MOVING = ' ';

		//Kiểm tra người chơi đến đích chưa để qua màn mới
		if (cg->getPeople()->isFinish()) {
			if (cg->getLevel() < 5) {
				cg->level++;
			}
			else if (cg->getLevel() >= 5) {
				cg->level = 1;
			}
			system("cls");
			cg->resetGame(cg->level);
			cg->startGame();
			continue;
		}

		if (cg->getPeople()->isDead()) {
			system("cls");
			cdraw.printMessageWhenLose();
			break;
		}
		
		
		
		if (cg->controlTrafficLight(133, 13, 0)) {
			cg->updatePosAnimal(ad, YBAT);
		}
		if (cg->controlTrafficLight(133, 19, 1)) {
			
			cg->updatePosVehicle(axh, YCAR);
		} 
		if (cg->controlTrafficLight(133, 25, 0)) {
			
			cg->updatePosAnimal(acs, YCROC);
		} 
		if (cg->controlTrafficLight(133, 7, 1)) {
			cg->updatePosVehicle(axt, YTRUCK);
		}
			
			
			
		
		
		
		
		
		cg->drawGame();
		
		

		if(cg->getLevel() == 1)
			Sleep(100);
		else if (cg->getLevel() == 2) {
			Sleep(80);
		}
		else if (cg->getLevel() == 3) {
			Sleep(50);
		}
		else if (cg->getLevel() == 4) {
			Sleep(30);
		}
	}
}

//Hàm lấy tên file để lưu dữ liệu
string takeFile() {
	string tailFile = ".txt";
	string headFile;
	wcout << "Enter a file's name: ";
	getline(cin, headFile);
	string file = headFile + tailFile;
	return file;
}

void CGAME::saveGame() {
	string file = takeFile();
	ofstream fout;
	fout.open(file, ios::out);

	if (fout.fail())
		wcout << "Can not open the file!";
	else {
		//Luu so luong doi tuong max trong mot level

		int listObjects = cg->getNumObjects();
		fout << listObjects << " ";

		//Luu vi tri cua cac xe hoi
		for (int i = 0; i < listObjects; i++) {
			fout << axh[i].getX() << " " << axh[i].getY() << " ";
		}

		//Luu vi tri cac con doi
		for (int i = 0; i < listObjects; i++) {
			fout << ad[i].getX() << " " << ad[i].getY() << " ";
		}

		//Luu vi tri cua cac xe tai
		for (int i = 0; i < listObjects; i++) {
			fout << axt[i].getX() << " " << axt[i].getY() << " ";
		}

		//Luu vi tri cac con ca sau
		for (int i = 0; i < listObjects; i++) {
			fout << acs[i].getX() << " " << acs[i].getY() << " ";
		}

		//Luu vi tri, trang thai song cua nguoi
		fout << cn->getX() << " " << cn->getY() << " " << cn->getMState() << " ";

		//Luu level
		fout << cg->getLevel();

		fout.close();
	}

}

void CGAME::loadGame() {

	string file = takeFile();
	ifstream fin;
	fin.open(file, ios::in);

	if (fin.fail()) {
		wcout << "Can not open the file!";
	}
	else {
		//Lay so luong object trong mot game
		

		int numObjects;
		fin >> numObjects; this->setNumbetObjects(numObjects);

		//Lay vi tri danh sach cac xe hoi
		int* tempCars = new int[numObjects * 2];
		for (int i = 0; i < numObjects * 2; i += 2) {
			fin >> tempCars[i];
			fin >> tempCars[i + 1];
		}

		int index = 0;
		for (int i = 0; i < numObjects * 2; i += 2) {
			axh[index].setX(tempCars[i]);
			axh[index].setY(tempCars[i + 1]);
			index++;
		}

		delete[]tempCars; tempCars = NULL;

		//Lay danh sach cac con doi
		int* tempBats = new int[numObjects * 2];
		for (int i = 0; i < numObjects * 2; i += 2) {
			fin >> tempBats[i];
			fin >> tempBats[i + 1];
		}

		index = 0;
		for (int i = 0; i < numObjects * 2; i += 2) {
			ad[index].setX(tempBats[i]);
			ad[index].setY(tempBats[i + 1]);
			index++;
		}

		delete[]tempBats; tempBats = NULL;

		//Lay danh sach xe tai
		int* tempTrucks = new int[numObjects * 2];
		for (int i = 0; i < numObjects * 2; i += 2) {
			fin >> tempTrucks[i];
			fin >> tempTrucks[i + 1];
		}

		index = 0;
		for (int i = 0; i < numObjects * 2; i += 2) {
			axt[index].setX(tempTrucks[i]);
			axt[index].setY(tempTrucks[i + 1]);
			index++;
		}

		delete[]tempTrucks; tempTrucks = NULL;

		//Lay danh sach cac con ca sau
		int* tempCros = new int[numObjects * 2];
		for (int i = 0; i < numObjects * 2; i += 2) {
			fin >> tempCros[i];
			fin >> tempCros[i + 1];
		}

		index = 0;
		for (int i = 0; i < numObjects * 2; i += 2) {
			acs[index].setX(tempCros[i]);
			acs[index].setY(tempCros[i + 1]);
			index++;
		}

		delete[]tempCros; tempCros = NULL;

		int xPeople, yPeople;
		fin >> xPeople >> yPeople;

		cn->setX(xPeople); cn->setY(yPeople);
		bool state;
		fin >> state;
		cn->setMState(state);

		int level;
		fin >> level;
		cg->setLevel(level);

		IS_RUNNING = true;

		fin.close();
	}
}

//EXIT GAME
void CGAME::exitGame(thread *t1) {
	IS_RUNNING = false;
	t1->join();//Kết thúc tiểu trình
}

//Tiểu trình phụ in các đối tượng trong trò chơi
void SubThread() {
	cg->PlayGame();
}

bool CGAME::controlTrafficLight(int x, int y, int mode, int timeZ) {
	srand(time(0));
	clock_t TimeZero = clock(); //Start timer
	double deltaTime = 0;
	double secondsToDelay = 2;
	deltaTime = (((clock()) / CLOCKS_PER_SEC / timeZ % 2) + (mode))%2;
	GotoXY(138, 22); wcout << deltaTime;
	int i = deltaTime;
	
	CDRAW cdraw;
	GotoXY(x - 1, y); wcout << L"|  |";
	GotoXY(x - 1, y + 2); wcout << L"|  |";
	if (i) {
		
		GotoXY(x, y + 2); SetColor(_LIGHTGREEN); wcout << L"▓▓";
		SetColor(_WHITE);
		return true;
	}
	else {
		
		GotoXY(x, y); SetColor(_RED); wcout << L"▓▓";
		SetColor(_WHITE);
		return false;
	}
	
}