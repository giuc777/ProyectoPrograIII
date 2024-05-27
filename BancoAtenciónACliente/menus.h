#include <iostream>
#include <conio.h>
#include <windows.h>
#include "template.h"
#ifndef MENUS_H
#define MENUS_H

// Función para configurar el color de fondo y del texto
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Función para dibujar el marco del menú
void dibujarMarco(int x, int y, int ancho, int alto) {
    // Esquinas del marco
    gotoxy(x, y);
    std::cout << char(218); // esquina superior izquierda
    gotoxy(x + ancho, y);
    std::cout << char(191); // esquina superior derecha
    gotoxy(x, y + alto);
    std::cout << char(192); // esquina inferior izquierda
    gotoxy(x + ancho, y + alto);
    std::cout << char(217); // esquina inferior derecha

    // Bordes horizontales
    for (int i = 1; i < ancho; ++i) {
        gotoxy(x + i, y);
        std::cout << char(196); // línea horizontal superior
        gotoxy(x + i, y + alto);
        std::cout << char(196); // línea horizontal inferior
    }

    // Bordes verticales
    for (int i = 1; i < alto; ++i) {
        gotoxy(x, y + i);
        std::cout << char(179); // línea vertical izquierda
        gotoxy(x + ancho, y + i);
        std::cout << char(179); // línea vertical derecha
    }
}

// Función para mostrar el menú dentro del marco
void mostrarMenu(const std::string opciones[], int n, int seleccion, int x, int y) {
    for (int i = 0; i < n; ++i) {
        gotoxy(x + 1, y + 1 + i);
        if (i == seleccion) {
            std::cout << "=> " << opciones[i] << std::endl;
        }
        else {
            std::cout << "   " << opciones[i] << std::endl;
        }
    }
}

// Implementación de la función del menú interactivo
int mostrarMenuInteractivo(const std::string opciones[], int n, int x, int y, int colorFondo) {
    int seleccion = 0;
    bool corriendo = true;
    int ancho = 40; // Ancho del marco
    int alto = n + 1; // Alto del marco (número de opciones + 1 para margen)

    setColor(colorFondo);

    while (corriendo) {
        system("cls"); // Limpiar la pantalla
        dibujarMarco(x, y, ancho, alto);
        mostrarMenu(opciones, n, seleccion, x, y);

        // Detectar la tecla presionada
        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            seleccion = (seleccion - 1 + n) % n;
            break;
        case 80: // Flecha abajo
            seleccion = (seleccion + 1) % n;
            break;
        case 13: // Enter
            corriendo = false; // Salir del bucle para procesar la opción seleccionada
            break;
        }
    }

    setColor(7); // Restablecer el color predeterminado (gris sobre negro)

    return seleccion + 1; // Ajustar la selección para que coincida con las opciones del menú
}

int menuOrden() {
    int opcionSubmenu = 1;
    const int OPCIONES = 4;

    int x = 22;
    int y = 5;
    int colorS = FOREGROUND_BLUE | FOREGROUND_GREEN | 0;



    string opciones[OPCIONES] = { "Pre-orden","In-orden","Post-orden","atras" };
    opcionSubmenu = mostrarMenuInteractivo(opciones, OPCIONES, x, y, colorS);

    return opcionSubmenu;
};
/*
   int opcionSubmenu = 1;
const int OPCIONES = 6;

int x = 22;
int y = 5;
string opciones[OPCIONES] = {  };
opcionSubmenu = mostrarMenuInteractivo(opciones, OPCIONES, x, y);
  */


int mostrarMenuInteractivoSinBorrar(const std::string opciones[], int n, int x, int y, int colorFondo) {
    int seleccion = 0;
    bool corriendo = true;
    int ancho = 40; // Ancho del marco
    int alto = n + 1; // Alto del marco (número de opciones + 1 para margen)


    while (corriendo) {
     
        mostrarMenu(opciones, n, seleccion, x, y);

        // Detectar la tecla presionada
        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            seleccion = (seleccion - 1 + n) % n;
            break;
        case 80: // Flecha abajo
            seleccion = (seleccion + 1) % n;
            break;
        case 13: // Enter
            corriendo = false; // Salir del bucle para procesar la opción seleccionada
            break;
        }
    }

    setColor(7); // Restablecer el color predeterminado (gris sobre negro)

    return seleccion + 1; // Ajustar la selección para que coincida con las opciones del menú
}


#endif