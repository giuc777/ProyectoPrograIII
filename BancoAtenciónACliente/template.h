
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

string obtenerFechaActual() {
    // Obtener el tiempo actual
    time_t tiempoActual = time(0);

    // Convertir a tiempo local de manera segura
    tm ahora;
    localtime_s(&ahora, &tiempoActual);

    // Crear un buffer para la fecha formateada
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", &ahora);

    return string(buffer);
}

// Función para dibujar un cuadro en la consola
void dibujarCuadro(int x, int y, int ancho, int alto) {
    gotoxy(x, y); std::cout << char(218);
    for (int i = 1; i < ancho; i++) std::cout << char(196);
    std::cout << char(191);

    for (int i = 1; i < alto; i++) {
        gotoxy(x, y + i); std::cout << char(179);
        gotoxy(x + ancho, y + i); std::cout << char(179);
    }

    gotoxy(x, y + alto); std::cout << char(192);
    for (int i = 1; i < ancho; i++) std::cout << char(196);
    std::cout << char(217);
}


#endif // !1
