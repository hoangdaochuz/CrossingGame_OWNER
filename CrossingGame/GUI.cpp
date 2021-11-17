#include "Mylib.h"
#include "GUI.h"
extern int yMove;

void CDRAW::printBox(int x, int y, int w, int h) {

	//Vẽ đường ngang
	for (int i = x + 1; i < x + w; i++) {
		GotoXY(i, y); wcout << L'─';           //Đường ngang trên
		GotoXY(i, y + h); wcout << L'─';	   //Đường ngang dưới
	}

	//Vẽ đường dọc
	for (int i = y + 1; i < y + h; i++) {
		GotoXY(x, i); wcout << L'│';		   //Đường dọc trái
		GotoXY(x + w, i); wcout << L'│';	   //Đường dọc phải
	}

	//Lấp đầy 4 góc của hộp
	GotoXY(x, y); wcout << L'┌';			   //Góc trái trên
	GotoXY(x + w, y); wcout << L'┐';           //Góc phải trên
	GotoXY(x, y + h); wcout << L'└';		   //Góc trái dưới
	GotoXY(x + w, y + h); wcout << L'┘';       //Góc phải dưới

}
void CDRAW::printThankYou(int x, int y) {
	SetColor(10);
	printBox(x + 35, y + 16, 28, 2);
	GotoXY(x + 41, y + 17);  wcout << "Press Esc to Exit";
	int color = 0;

	while (1) {
		SetColor(color);
		if (color > 15)
			color = 0;

		GotoXY(x, y);     wcout << " __________  __    __  ________  __    __  __   ___     ___    ___ ________  __     __    __";
		GotoXY(x, y + 1); wcout << "|___    ___||  |  |  ||   __   ||  \\  |  ||  | /  /     \\  \\  /  /|   __   ||  |   |  |  |  |";
		GotoXY(x, y + 2); wcout << "    |  |    |  |__|  ||  |  |  ||   \\ |  ||  |/  /       \\  \\/  / |  |  |  ||  |   |  |  |  |";
		GotoXY(x, y + 3); wcout << "    |  |    |   __   ||  |__|  ||  |\\\\|  ||     /         \\    /  |  |  |  ||  |   |  |  |__|";
		GotoXY(x, y + 4); wcout << "    |  |    |  |  |  ||  |  |  ||  | \\|  ||  |\\  \\         |  |   |  |__|  ||  |___|  |   __";
		GotoXY(x, y + 5); wcout << "    |__|    |__|  |__||__|  |__||__|  \\__||__| \\__\\        |__|   |________||_________|  |__|";

		if (_kbhit()) {
			char press = _getch();
			if (press == 27) return;
		}
		color++;
		Sleep(1);
	}
}
void CDRAW::printBigCar(int x, int y) {
	GotoXY(x, y);     wcout << "        _______________" << endl;
	GotoXY(x, y + 1); wcout << "       / / |  |  |  |  \\" << endl;
	GotoXY(x, y + 2); wcout << " _____/ /  |__|  |__|   \\" << endl;
	GotoXY(x, y + 3); wcout << "|_|     __        __    |" << endl;
	GotoXY(x, y + 4); wcout << "|______/  \\______/  \\___|" << endl;
	GotoXY(x, y + 5); wcout << "       \\__/      \\__/" << endl;
}
void CDRAW::printBigBird(int x, int y) {
	GotoXY(x, y);     wcout << "      .---.        .-----------";
	GotoXY(x, y + 1); wcout << "     /     \\  __  /    ------";
	GotoXY(x, y + 2); wcout << "    / /     \\(  )/    -----";
	GotoXY(x, y + 3); wcout << "   //////   ' \\/ `   ---";
	GotoXY(x, y + 4); wcout << "  //// / // :    : ---";
	GotoXY(x, y + 5); wcout << " // /   /  /`    '--";
	GotoXY(x, y + 6); wcout << "//          //..\\\\";
	GotoXY(x, y + 7); wcout << "       ====UU====UU====";
	GotoXY(x, y + 8); wcout << "           '//||\\\\`";
	GotoXY(x, y + 9); wcout << "             ''``";
}

//Màn hình chính khi vào game
void CDRAW::printHomePage(int x, int y, int w, int h) {
	CDRAW cdraw;
	cdraw.printBanner(44, 7);

	SetColor(_PINK);//Mau hong
	for (int i = x; i <= x + w; i++) {
		GotoXY(i, 13); wcout << L'-';
	}

	SetColor(_GREEN);//Mau xanh la
	cdraw.printBigCar(45, 19);

	SetColor(_RED);//Mau do

	GotoXY(x + 40, y + 16); wcout << "START GAME";
	GotoXY(x + 40, y + 17); wcout << "LOAD GAME";
	GotoXY(x + 40, y + 18); wcout << "INSTRUCTIONS";
	GotoXY(x + 40, y + 19); wcout << "ABOUT US";
	GotoXY(x + 40, y + 20); wcout << "EXIT GAME";

	SetColor(_BLUE);
	cdraw.printBigBird(96, 18);

	SetColor(_PINK);//Mau hong
	printBox(x, y, w, h);
}
void CDRAW::printAboutUs() {
	SetColor(_LIGHTBLUE);
	int tmp = 70;
	printBox(tmp+3, 21, 28, 2);
	GotoXY(tmp, 2);  wcout << L"              .-\"\"\"-.";
	GotoXY(tmp, 3);  wcout << L"             / .===. \\";
	GotoXY(tmp, 4);  wcout << L"             \\/ 6 6 \\/";
	GotoXY(tmp, 5);  wcout << L"             ( \\___/ )";
	GotoXY(tmp, 6);  wcout << L" ________ooo__\\_____/____________";
	GotoXY(tmp, 7);  wcout << L" /                                \\";
	GotoXY(tmp, 8);  wcout << L"| MEMBERS                          |";
	GotoXY(tmp, 9);  wcout << L"| 20127212 Nguyen Truong Minh Khoi |";
	GotoXY(tmp, 10); wcout << L"| 20127233 Huynh The Long          |";
	GotoXY(tmp, 11); wcout << L"| 20127459 Le Quoc Dat             |";
	GotoXY(tmp, 12); wcout << L"| 20127522 Nguyen Huu Khai         |";
	GotoXY(tmp, 13); wcout << L"| 20127551 Nguyen Huu Loc          |";
	GotoXY(tmp, 14); wcout << L"\\_____________________ooo________/";
	GotoXY(tmp, 15); wcout << L"              |  |  |";
	GotoXY(tmp, 16); wcout << L"              |_ | _|";
	GotoXY(tmp, 17); wcout << L"              |  |  |";
	GotoXY(tmp, 18); wcout << L"              |__|__|";
	GotoXY(tmp, 18); wcout << L"              /-'Y'-\\";
	GotoXY(tmp, 19); wcout << L"             (__/ \\__)";
	GotoXY(tmp+6, 22);  wcout << "Press Esc to Exit";

	
	while (1) {
		if (_kbhit()) {
			char press = _getch();
			if (press == 27) return;
		}
	}
	
}
void CDRAW::printInstructions() {
	SetColor(_LIGHTBLUE);
	int tmp = 50;
	printBox(tmp+30, 21, 28, 2);
	GotoXY(tmp, 5);  wcout << L" ____________________________________________________________________________________";
	GotoXY(tmp, 6);  wcout << L"/\\                                                                                   \\";
	GotoXY(tmp, 7);  wcout << L"\\_| Huong dan                                                                         |"; 
	GotoXY(tmp, 8);  wcout << L"   | Dung cac phim WASD hoac ↑ ← ↓ → de di chuyen                                     |";
	GotoXY(tmp, 9);  wcout << L"   | Di chuyen len dau de qua level tiep theo                                         |";
	GotoXY(tmp, 10); wcout << L"   | Tranh cac chuong ngai vat khi di chuyen                                          |";
	GotoXY(tmp, 11); wcout << L"   | Khi den do, cac chuong ngai vat se dung lai, ban co the loi dung de choi tot hon |";
	GotoXY(tmp, 12); wcout << L"   |   _______________________________________________________________________________|";
	GotoXY(tmp, 13); wcout << L"   \\_/_________________________________________________________________________________/";

	SetColor(_LIGHTYELLOW); GotoXY(tmp + 19, 8); wcout << L"WASD"; GotoXY(tmp + 29, 8); wcout << L"↑ ← ↓ →";
	SetColor(_RED); GotoXY(tmp + 9, 11); wcout << L"den do";
	SetColor(_LIGHTBLUE);
	while (1) {
		if (_kbhit()) {
			char press = _getch();
			if (press == 27) return;
		}
		GotoXY(tmp + 32, 22);  wcout << "Press Esc to Exit";
	}
}
//EXIT GAME
void CDRAW::printAgainHomePage() {
	CDRAW cdraw;
	system("cls");
	ShowCur(0);
	cdraw.printHomePage(40, 6, 90, 25);
	SetColor(_LIGHTYELLOW);
	GotoXY(77, yMove); wcout << L'»';
}
void CDRAW::printLoading() {
	CDRAW cdraw;
	system("cls");
	ShowCur(0);
	int percent = 10;
	SetColor(7); printBox(32, 20, 101, 2);
	int xOld = 23;
	thread musicCar(MusicCarLoading);
	for (int i = 33; i <= 123; i += 10) {
		SetColor(7); GotoXY(137, 21); wcout << percent << "%";
		textcolor(121); GotoXY(i, 21); wcout << "          ";
		textcolor(0);

		DeleteImageOld(xOld, 11, 10, 9);
		SetColor(3); cdraw.printCarLoading(i, 16);

		percent += 10;
		xOld += 10;
		Sleep(600);
	}
	musicCar.join();
	wcout << endl << endl << endl;
	textcolor(_BLACK);
}
void CDRAW::printCarLoading(int x, int y) {
	GotoXY(x, y);     wcout << "   ____";
	GotoXY(x, y + 1); wcout << " _/_||_\\_";
	GotoXY(x, y + 2); wcout << "|        |";
	GotoXY(x, y + 3); wcout << "`(o)--(o)'";
}
void CDRAW::printBanner(int x, int y) {
	SetColor(_YELLOW);
	GotoXY(x, y);       wcout << " _______  _______  _______  _______  _______    _______  _______  _______  ______";
	GotoXY(x, y + 1);   wcout << "|  _____||  ___  ||  ___  ||  _____||  _____|  |  ___  ||  ___  ||  ___  ||  ___ \\";
	GotoXY(x, y + 2);   wcout << "| |      | |___| || |   | || |_____ | |_____   | |___| || |   | || |___| || |   \\ |";
	GotoXY(x, y + +3); wcout << "| |_____ | |  \\ \\ | |___| | _____| | _____| |  | |  \\ \\ | |___| || |   | || |___/ |";
	GotoXY(x, y + 4);   wcout << "|_______||_|   \\_\\|_______||_______||_______|  |_|   \\_\\|_______||_|   |_||______/";

}





void printPeople(int x, int y) {
	GotoXY(x, y);	  wcout << " O";
	GotoXY(x, y + 1); wcout << "/|\\";
	GotoXY(x, y + 2); wcout << "/ \\";
}
void MusicCarLoading() {
	PlaySound(TEXT("smb_world_clear.wav"), NULL, SND_SYNC);
}
void DeleteImageOld(int x, int y, int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = x; j <= x + w; j++) {
			GotoXY(j, y); wcout << " ";
		}
		y++;
	}
}

void CDRAW::printLevel(int x, int y, int level) {
	SetColor(_LIGHTBLUE);
	GotoXY(x, y + 0);  wcout << L" .----------------. ";
	GotoXY(x, y + 1);  wcout << L"| .-Level--------. |";
	GotoXY(x, y + 8);  wcout << L"| |              | |";
	GotoXY(x, y + 9);  wcout << L"| '--------------' |";
	GotoXY(x, y + 10); wcout << L" '----------------' ";
	SetColor(_LIGHTGREEN);
	GotoXY(x-2, y + 12); wcout << L"<!-- - - - - - - - - -->";
	GotoXY(x-2, y + 13); wcout << L"<!--Your score:      -->";
	GotoXY(x-2, y + 14); wcout << L"<!-- - - - - - - - - -->";
	SetColor(_LIGHTBLUE);
	if (level == 1) {
		GotoXY(x, y + 2);  wcout << L"| |     __       | |";
		GotoXY(x, y + 3);  wcout << L"| |    /  |      | |";
		GotoXY(x, y + 4);  wcout << L"| |    `| |      | |";
		GotoXY(x, y + 5);  wcout << L"| |     | |      | |";
		GotoXY(x, y + 6);  wcout << L"| |    _| |_     | |";
		GotoXY(x, y + 7);  wcout << L"| |   |_____|    | |";

	}
	else if (level == 2) {
		GotoXY(x, y + 2);  wcout << L"| |    _____     | |";
		GotoXY(x, y + 3);  wcout << L"| |   / ___ `.   | |";
		GotoXY(x, y + 4);  wcout << L"| |  |_/___) |   | |";
		GotoXY(x, y + 5);  wcout << L"| |   .'____.'   | |";
		GotoXY(x, y + 6);  wcout << L"| |  / /____     | |";
		GotoXY(x, y + 7);  wcout << L"| |  |_______|   | |";
	}
	else if (level == 3) {
		GotoXY(x, y + 2);  wcout << L"| |    ______    | |";
		GotoXY(x, y + 3);  wcout << L"| |   / ____ `.  | |";
		GotoXY(x, y + 4);  wcout << L"| |   `'  __) |  | |";
		GotoXY(x, y + 5);  wcout << L"| |   _  |__ '.  | |";
		GotoXY(x, y + 6);  wcout << L"| |  | \\____) |  | |";
		GotoXY(x, y + 7);  wcout << L"| |   \\______.'  | |";
	}
	else if (level == 4) {
		GotoXY(x, y + 2);  wcout << L"| |   _    _     | |";
		GotoXY(x, y + 3);  wcout << L"| |  | |  | |    | |";
		GotoXY(x, y + 4);  wcout << L"| |  | |__| |_   | |";
		GotoXY(x, y + 5);  wcout << L"| |  |____   _|  | |";
		GotoXY(x, y + 6);  wcout << L"| |      _| |_   | |";
		GotoXY(x, y + 7);  wcout << L"| |     |_____|  | |";
	}
	else if (level == 5) {
		GotoXY(x, y + 2);  wcout << L"| |   _______    | |";
		GotoXY(x, y + 3);  wcout << L"| |  |  _____|   | |";
		GotoXY(x, y + 4);  wcout << L"| |  | |____     | |";
		GotoXY(x, y + 5);  wcout << L"| |  '_.____''.  | |";
		GotoXY(x, y + 6);  wcout << L"| |  | \\____) |  | |";
		GotoXY(x, y + 7);  wcout << L"| |   \\______.'  | |";
	}

	SetColor(_WHITE);




}

void CDRAW::printMessageWhenLose() {
	int xPos = 20;
	int yPos = 10;
	for (int i = xPos; i <= xPos + 100; i++) {
		GotoXY(i, yPos); wcout << L"_";
		GotoXY(i, yPos + 5); wcout << L"_";
	}
	for (int j = yPos; j <= yPos + 5; j++) {
		GotoXY(xPos, j); wcout << L"|";
		GotoXY(xPos + 100, j); wcout << L"|";
	}

	GotoXY(xPos + 5, yPos + 2); wcout << L"YOU LOSE";
	GotoXY(xPos + 5, yPos + 3); wcout << "PRESS Y TO CONTINUE OR ANY KEY TO EXIT";

}