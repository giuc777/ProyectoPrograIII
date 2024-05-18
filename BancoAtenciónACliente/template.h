#ifndef _template_H
#define _template_H

#include <algorithm>
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

void haciaAbajo(int constante, int* aumento) {
    *aumento++;
    return gotoxy(constante, *aumento);
}

int menuOrden() {
    LimpiarPatalla();
    int opcionSubmenu = 1;
    int maxOpcion = 4;
    char tecla;


    system("color F0");
    do {
        gotoxy(20, 2); cout << ("********************MENU******************");
        gotoxy(20, 3); cout << ((opcionSubmenu == 1) ? "*-> Pre-orden" : "  Pre-orden*  ");
        gotoxy(20, 4); cout << ((opcionSubmenu == 2) ? "*-> In-orden" : "  In-orden*  ");
        gotoxy(20, 5); cout << ((opcionSubmenu == 3) ? "*-> Post-orden" : "  Post - orden *  ");
        gotoxy(20, 6); cout << ((opcionSubmenu == 4) ? "*-> atras" : " atras*  ");
        gotoxy(20, 7); cout << ("*********************************************");

        tecla = _getch();

        switch (tecla) {
        case 73: // Flecha arriba
            opcionSubmenu = (opcionSubmenu > 1) ? opcionSubmenu - 1 : maxOpcion;
            break;

        case 80: // Flecha abajo
            opcionSubmenu = (opcionSubmenu < maxOpcion) ? opcionSubmenu + 1 : 1;
            break;

        case 13: // Enter
            break;
        }

    } while (tecla != 13);

    return opcionSubmenu;
};


#endif // !1
