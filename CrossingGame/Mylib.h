#pragma once
#include <conio.h> //Dung trong ham getch, clrsch
#include <fcntl.h> //Dung trong _O_WTEXT
#include <io.h> //Dung trong SetMode
#include<windows.h>

void FixConsoleWindow();

void GotoXY(int x, int y);

void ShowCur(bool CursorVisibility);

void SetColor(WORD color);

void textcolor(int x);

void setConsoleWindown(int w, int h);