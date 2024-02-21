#ifndef _template_H
#define _template_H


#include <conio.h>;
#include <math.h>;
#include <time.h>;
#include <fsrmerr.h>;
#include <iostream>;
#include <windows.h>; 
#include <string.h>
#include <cctype>
#include <string>
using namespace std;


void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
void LimpiarPatalla() {
    system("cls");
}
#endif // !1
