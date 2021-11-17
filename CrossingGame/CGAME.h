#pragma once
#include"CPEOPLE.h"
#include"CANIMAL.h"
#include"CVEHICLE.h"
#include"GUI.h"

#include<ctime>
#include<thread>
#include<fstream>
#include<string>



#define WIDTHROAD 130
#define HEIGHTROAD 6
#define LEFTROAD 0
#define RIGHT_VEHICLE 100
#define RIGHT_ANIMAL 96

#define YCAR 8
#define YBAT 14
#define YCROC 26
#define YTRUCK 20

#define MAX_LV1 3
#define MAX_LV2 4
#define MAX_LV3 5
#define MAX_LV4 6




class CGAME {
private:
	CVEHICLE* axh;
	CVEHICLE* axt;
	CANIMAL* ad;
	CANIMAL* acs;
	CPEOPLE* cn;

	int level;
	int numObjects;
public:

	CGAME();
	~CGAME();
	void drawGame();
	
	CVEHICLE* getCars();
	CVEHICLE* getTrucks();
	CANIMAL* getBats();
	CANIMAL* getCrocodile();
	CPEOPLE *getPeople();
	
	void setNumbetObjects(int num);
	int getNumObjects();

	void setLevel(int level);
	int getLevel();

	void resetGame(int);
	void exitGame(thread*);
	void PlayGame();
	void startGame();
	void pauseGame();
	void resumeGame();
	void saveGame();
	void loadGame();
	void DebugOutput(int x);
	void updatePosPeople(char);
	void updatePosVehicle(CVEHICLE*, int y);
	void updatePosAnimal(CANIMAL*, int y);
	bool controlTrafficLight(int x, int y, int mode = 0, int time = 4);
};

void SubThread();
//Ham phu lay ten tap tin de save game
string takeFile();
//Ham phu de kiem tra game co dang chay => Tranh TH nguoi choi bam resume game trong khi game da chay roi
bool gameIsRunning();