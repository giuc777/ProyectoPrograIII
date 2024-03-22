#pragma once
#include "Nodos.h"
#ifndef FUNCIONESLISTAS_H
#define FUNCIONESLISTAS_H


int menuListas() {
    LimpiarPatalla();
    int opcionSubmenu = 1;
    int maxOpcion = 5;
    char tecla;


    system("color F0");
    do {
        gotoxy(20, 2); cout << ("********************MENU******************");
        gotoxy(20, 3); cout << ((opcionSubmenu == 1) ? "*-> Nueva trasnferencia" : "   Nueva trasnferencia*  ");
        gotoxy(20, 4); cout << ((opcionSubmenu == 2) ? "*-> Mostrar trasnferencias" : "   Mostrar trasnferencias*  ");
        gotoxy(20, 5); cout << ((opcionSubmenu == 3) ? "*-> Quitar trasnferencias" : "  Quitar trasnferencias*  ");
        gotoxy(20, 6); cout << ((opcionSubmenu == 4) ? "*-> Vaciar registro" : "  Vaciar registro*  ");
        gotoxy(20, 7); cout << ((opcionSubmenu == 5) ? "*-> atras" : " atras*  ");
        gotoxy(20, 8); cout << ("*********************************************");

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



void insertarSimple(NodoListaSimple*& cab, NodoListaSimple*& fin, int* id) {
    (*id)++;
    LimpiarPatalla();
    int idCliente, cantidad;
    string cuenta1, cuenta2, fecha, dpi;
    cout << "Ingrese DPI del cliente para transferencia: \n";
    cin >> dpi;
    cout << "\n Ingrese la cantidad: \n";
    cin >> cantidad;
    cout << "\n Ingrese la cuenta a retirar: \n";
    cin >> cuenta1;
    cout << "\n Ingrese la cuenta a transferir: \n";
    cin >> cuenta2;
    cout << "\n Ingrese la fecha: \n";
    cin >> fecha;

    NodoListaSimple* nuevo = new NodoListaSimple;
    nuevo->Cliente.idTrans = *id;
    nuevo->Cliente.DPI =dpi ;
    nuevo->Cliente.cantidad = cantidad;
    nuevo->Cliente.cuenta1 = cuenta1;
    nuevo->Cliente.cuenta2 = cuenta2;
    nuevo->Cliente.fecha = fecha;
    nuevo->sig = NULL;

    if (cab == NULL || cab->Cliente.cantidad > nuevo->Cliente.cantidad) {
        nuevo->sig = cab;
        cab = nuevo;
    }
    else {
        NodoListaSimple* actual = cab;
        while (actual->sig != NULL && actual->sig->Cliente.cantidad < nuevo->Cliente.cantidad) {
            actual = actual->sig;
        }
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
    }

    cout << "Se completo la trasferencia no."<<nuevo->Cliente.idTrans;
    _getch();
};
void eliminarSimple(NodoListaSimple*& cab, NodoListaSimple*& fin, int* id) {

    LimpiarPatalla();

    if (cab != NULL) {
        int idEliminar;
        cout << "Ingrese el id de la trasferencia a eliminar: \n";
        cin >> idEliminar;
        NodoListaSimple* aux;
        NodoListaSimple* anterior = NULL;

        aux = cab;

        while ((aux != NULL) && (aux->Cliente.idTrans != idEliminar)) {
            anterior = aux;
            aux = aux->sig;
        }

        if (aux == NULL) {
            cout << "El elemento no ha sido encontrado.";
        }
        else if (anterior == NULL) {
            cab = cab->sig;
            delete aux;
        }
        else {
            anterior->sig = aux->sig;
            delete aux;
        }
    }
    else {
        cout << "No hay elementos";
    }
    _getch();
};
void vaciarSimple(NodoListaSimple*& cab, NodoListaSimple*& fin, int* id) {
    LimpiarPatalla();
    NodoListaSimple* aux;

    while (cab != NULL) {
        aux = cab;
        cab = aux->sig;
        delete aux;
    }

    fin = NULL;
    cout << "Se ha vaciado el registro";
    _getch();
};
void MostrarLista(NodoListaSimple*& cab, NodoListaSimple*& fin, int* id) {
    LimpiarPatalla();
    NodoListaSimple* actual = new NodoListaSimple;
    actual = cab;

    while (actual != NULL) {
        cout << actual->Cliente.cantidad << " -> ";
        actual = actual->sig;
    }
    _getch();
};

//Listas circular
int menuListaCircular() {
    LimpiarPatalla();
    int opcionSubmenu = 1;
    int maxOpcion = 5;
    char tecla;


    system("color F0");
    do {
        gotoxy(20, 2); cout << ("********************MENU******************");
        gotoxy(20, 3); cout << ((opcionSubmenu == 1) ? "*-> Nueva Remesa" : "   Nueva Remesa*  ");
        gotoxy(20, 4); cout << ((opcionSubmenu == 2) ? "*-> Mostrar Remesas" : "   Mostrar Remesas*  ");
        gotoxy(20, 5); cout << ((opcionSubmenu == 3) ? "*-> Quitar Remesas" : "  Quitar Remesas*  ");
        gotoxy(20, 6); cout << ((opcionSubmenu == 4) ? "*-> Vaciar registro" : "  Vaciar registro*  ");
        gotoxy(20, 7); cout << ((opcionSubmenu == 5) ? "*-> atras" : " atras*  ");
        gotoxy(20, 8); cout << ("*********************************************");

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


void insertarCircular(NodoListaCircular*& cab, NodoListaCircular*& fin, int* id) {
    (*id)++;
    LimpiarPatalla();
    int cantidad;
    string nombre, apellido, paisOrigen, dpi, fecha;
    cout << "Ingrese DPI del cliente que recibe la remesa: \n";
    cin >> dpi;
    cout << "\n Ingrese la cantidad: \n";
    cin >> cantidad;
    cout << "\n Ingrese el nombre del cliente: \n";
    cin.ignore();
    getline(cin, nombre);
    cout << "\n Ingrese el apellido del cliente: \n";
    cin.ignore();
    getline(cin, apellido);
    cout << "\n Ingrese el pais de origen: \n";
    cin >> paisOrigen;
    cout << "\n Ingrese la fecha: \n";
    cin >> fecha;

    NodoListaCircular* nuevoNodo = new NodoListaCircular;
    nuevoNodo->Cliente.nombre = nombre;
    nuevoNodo->Cliente.apellido = apellido;
    nuevoNodo->Cliente.DPI = dpi;
    nuevoNodo->Cliente.fecha = fecha;
    nuevoNodo->Cliente.paisOrigen = paisOrigen;
    nuevoNodo->Cliente.cantidad = cantidad;
    nuevoNodo->Cliente.idRemesa = *id;

    if (cab == nullptr) {
        cab = nuevoNodo;
        fin = nuevoNodo;
        nuevoNodo->sig = cab;
    }
    else if (cab->Cliente.cantidad >= nuevoNodo->Cliente.cantidad) {
        nuevoNodo->sig = cab;
        cab = nuevoNodo;
        fin->sig = cab;
    }
    else {
        NodoListaCircular* temp = cab;
        while (temp->sig != fin && temp->sig->Cliente.cantidad < nuevoNodo->Cliente.cantidad) {
            temp = temp->sig;
        }
        if (temp->sig == fin && fin->Cliente.cantidad < nuevoNodo->Cliente.cantidad) { // insertar al final
            fin->sig = nuevoNodo;
            fin = nuevoNodo;
            fin->sig = cab;
        }
        else { // insertar en medio
            nuevoNodo->sig = temp->sig;
            temp->sig = nuevoNodo;
        }
    }
}

void eliminarCircular(NodoListaCircular*& cab, NodoListaCircular*& fin, int* id) {
    LimpiarPatalla();
    if (cab != NULL) {
        int idEliminar;
        cout << "Ingrese el id de la remesa a eliminar: \n";
        cin >> idEliminar;
        NodoListaCircular* temp = cab;
        NodoListaCircular* prev = NULL;
        while (temp->Cliente.idRemesa != idEliminar) {

        }
       
    }
    else {
        cout << "No hay remesas";
    }
};

void vaciarCircular(NodoListaCircular*& cab, NodoListaCircular*& fin, int* id) {

};
void MostrarCircular(NodoListaCircular*& cab, NodoListaCircular*& fin, int* id) {
    LimpiarPatalla();
    NodoListaCircular* actual = new NodoListaCircular;
    actual = cab;

    do{
        cout << "Con la cantidad " <<actual->Cliente.cantidad<<" " << &actual->Cliente << actual->Cliente.cantidad << " ->  siguiente " << actual->sig << " ";
        actual = actual->sig;
    } while (actual != cab);
    _getch();
};


#endif