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
        gotoxy(20, 3); cout << ((opcionSubmenu == 1) ? "*-> Nueva trasnferencia" : " Nueva trasnferencia*  ");
        gotoxy(20, 4); cout << ((opcionSubmenu == 2) ? "*-> Mostrar trasnferencias" : " Mostrar trasnferencias*  ");
        gotoxy(20, 5); cout << ((opcionSubmenu == 3) ? "*-> Quitar trasnferencias" : " Quitar trasnferencias*  ");
        gotoxy(20, 6); cout << ((opcionSubmenu == 4) ? "*-> Vaciar registro" : " Vaciar registro*  ");
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
    int constante = 20, aumentar = 2;
    LimpiarPatalla();
    int idCliente, cantidad;
    string cuenta1, cuenta2, fecha, dpi;
    gotoxy(constante, aumentar++);cout << "Ingrese DPI del cliente para transferencia: ";
    gotoxy(constante, aumentar++);cin >> dpi;
    gotoxy(constante, aumentar++);cout << "Ingrese la cantidad: ";
    gotoxy(constante, aumentar++);cin >> cantidad;
    gotoxy(constante, aumentar++);cout << "Ingrese la cuenta a retirar: ";
    gotoxy(constante, aumentar++);cin >> cuenta1;
    gotoxy(constante, aumentar++);cout << "Ingrese la cuenta a transferir: ";
    gotoxy(constante, aumentar++);cin >> cuenta2;
    gotoxy(constante, aumentar++);cout << "Ingrese la fecha: ";
    gotoxy(constante, aumentar++);cin >> fecha;

    NodoListaSimple* nuevo = new NodoListaSimple;
    nuevo->Cliente.idTrans = *id;
    nuevo->Cliente.DPI = dpi;
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

    gotoxy(constante, aumentar++);cout << "Se completo la trasferencia no." << nuevo->Cliente.idTrans;
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
    int constante = 20, aumentar = 2;
    gotoxy(constante, 1);cout << "Ordenados de menor a mayor segun la cantidad";

    while (actual != NULL) {
        gotoxy(constante, aumentar++); cout << "------------------------------";
        gotoxy(constante, aumentar++);cout << "Numero de transferencia: " << actual->Cliente.idTrans;
        gotoxy(constante, aumentar++);cout << "Cantidad : " << actual->Cliente.cantidad;
        gotoxy(constante, aumentar++);cout << "Cuenta retirada : " << actual->Cliente.cuenta1;
        gotoxy(constante, aumentar++);cout << "Cuenta acreditada : " << actual->Cliente.cuenta2;
        gotoxy(constante, aumentar++);cout << "DPI cliente " << actual->Cliente.DPI;
        gotoxy(constante, aumentar++);cout << "Fecha " << actual->Cliente.fecha;
        gotoxy(constante, aumentar++); cout << "Siguiente ->" << actual->sig;
        gotoxy(constante, aumentar++); cout << "------------------------------";
        aumentar = aumentar + 1;
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
        gotoxy(20, 3); cout << ((opcionSubmenu == 1) ? "*-> Nueva Remesa" : "  Nueva Remesa*  ");
        gotoxy(20, 4); cout << ((opcionSubmenu == 2) ? "*-> Mostrar Remesas" : "  Mostrar Remesas*  ");
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
    int constante = 20, aumentar = 2;
    int cantidad;
    string nombre, apellido, pais, dpi, fecha;
    gotoxy(constante, aumentar++);cout << "Ingrese DPI del cliente que recibe la remesa: ";
    gotoxy(constante, aumentar++);cin >> dpi;
    gotoxy(constante, aumentar++);cout << "Ingrese la cantidad: ";
    gotoxy(constante, aumentar++);cin >> cantidad;
    gotoxy(constante, aumentar++);cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    gotoxy(constante, aumentar++);getline(cin, nombre);
    gotoxy(constante, aumentar++);cout << "Ingrese el apellido del cliente: ";
    gotoxy(constante, aumentar++);getline(cin, apellido);
    gotoxy(constante, aumentar++);cout << "Ingrese el pais de origen: ";
    gotoxy(constante, aumentar++);cin >> pais;
    gotoxy(constante, aumentar++);cout << "Ingrese la fecha: ";
    gotoxy(constante, aumentar++);cin >> fecha;

    NodoListaCircular* nuevoNodo = new NodoListaCircular;
    nuevoNodo->Cliente.nombre = nombre;
    nuevoNodo->Cliente.apellido = apellido;
    nuevoNodo->Cliente.DPI = dpi;
    nuevoNodo->Cliente.fecha = fecha;
    nuevoNodo->Cliente.paisOrigen = pais;
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
        do {
            if (temp->Cliente.idRemesa == idEliminar) {
                if (prev == NULL) { // Eliminar el primer nodo
                    if (cab == fin) { // Si solo hay un nodo en la lista
                        cab = NULL;
                        fin = NULL;
                    }
                    else {
                        cab = cab->sig;
                        fin->sig = cab;
                    }
                }
                else { // Eliminar un nodo que no es el primero
                    prev->sig = temp->sig;
                    if (temp == fin) { // Si el nodo a eliminar es el último
                        fin = prev;
                    }
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->sig;
        } while (temp != cab);
        cout << "El id de la remesa " << idEliminar << " no se encontró en la lista.\n";
    }
    else {
        cout << "No hay remesas";

    }
    _getch();
}


void vaciarCircular(NodoListaCircular*& cab, NodoListaCircular*& fin, int* id) {
    NodoListaCircular* temp = cab;
    while (cab != fin) {
        cab = cab->sig;
        delete temp;
        temp = cab;
    }
    if (fin != nullptr) {
        delete fin;
    }
    cab = nullptr;
    fin = nullptr;
}

void MostrarCircular(NodoListaCircular*& cab, NodoListaCircular*& fin, int* id) {
    LimpiarPatalla();
    NodoListaCircular* actual = new NodoListaCircular;
    actual = cab;
    int constante = 20, aumentar = 2; 
    gotoxy(constante, 1);cout << "Ordenados de menor a mayor segun la cantidad";

    if (cab != NULL) {
        do {
            gotoxy(constante, aumentar++); cout << "------------------------------";
            gotoxy(constante, aumentar++); cout << "Direccion: "<<&actual->Cliente;
            gotoxy(constante, aumentar++);cout << "Numero de remesa: " << actual->Cliente.idRemesa;
            gotoxy(constante, aumentar++);cout << "Cantidad: " << actual->Cliente.cantidad;
            gotoxy(constante, aumentar++);cout << "Nombre del cliente: " << actual->Cliente.nombre;
            gotoxy(constante, aumentar++);cout << "Apellido del cliente: " << actual->Cliente.apellido;
            gotoxy(constante, aumentar++);cout << "DPI cliente " << actual->Cliente.DPI;
            gotoxy(constante, aumentar++);cout << "Fecha " << actual->Cliente.fecha;
            gotoxy(constante, aumentar++);cout << "Pais origen remesa " << actual->Cliente.paisOrigen;
            gotoxy(constante, aumentar++); cout << "Siguiente ->" << actual->sig;
            gotoxy(constante, aumentar++); cout << "------------------------------";
            aumentar = aumentar + 1;
            actual = actual->sig;
        } while (actual != cab);
    }
    else {
        cout << "No hay registros";
    }
    _getch();
};


int menuListaDoblemente() {
    LimpiarPatalla();
    int opcionSubmenu = 1;
    int maxOpcion = 5;
    char tecla;


    system("color F0");
    do {
        gotoxy(20, 2); cout << ("********************MENU******************");
        gotoxy(20, 3); cout << ((opcionSubmenu == 1) ? "*-> Nuevo Deposito" : "  Nuevo Deposito*  ");
        gotoxy(20, 4); cout << ((opcionSubmenu == 2) ? "*-> Mostrar Depositos" : "  Mostrar Depositos*  ");
        gotoxy(20, 5); cout << ((opcionSubmenu == 3) ? "*-> Quitar Deposito" : "  Quitar Deposito*  ");
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

void insertarDoblemente(NodoListaDoblemente*& cab, NodoListaDoblemente*& fin, int* id) {
    (*id)++;
    LimpiarPatalla();
    int cant, constante = 20, aumentar=2;
    string nombre, apellido, dpi, fecha;
    gotoxy(constante, aumentar++);cout << "Ingrese DPI del cliente que deposita: ";
    gotoxy(constante, aumentar++);cin >> dpi;
    gotoxy(constante, aumentar++);cout << "Ingrese la cantidad: ";
    gotoxy(constante, aumentar++);cin >> cant;
    gotoxy(constante, aumentar++);cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    gotoxy(constante, aumentar++);getline(cin, nombre);
    gotoxy(constante, aumentar++);cout << "Ingrese el apellido del cliente: ";
    gotoxy(constante, aumentar++); getline(cin, apellido);
    gotoxy(constante, aumentar++);cout << "Ingrese la fecha: ";
    gotoxy(constante, aumentar++);cin >> fecha;

    NodoListaDoblemente* nuevoNodo = new NodoListaDoblemente;
    nuevoNodo->Cliente.nombre = nombre;
    nuevoNodo->Cliente.apellido = apellido;
    nuevoNodo->Cliente.dpi = dpi;
    nuevoNodo->Cliente.fecha = fecha;
    nuevoNodo->Cliente.cant = cant;
    nuevoNodo->Cliente.idDeposito = *id;

    if (cab == nullptr) {
        cab = nuevoNodo;
        fin = nuevoNodo;
        nuevoNodo->sig = nullptr;
        nuevoNodo->ant = nullptr;
    }
    else if (cab->Cliente.cant >= nuevoNodo->Cliente.cant) {
        nuevoNodo->sig = cab;
        cab->ant = nuevoNodo;
        cab = nuevoNodo;
    }
    else {
        NodoListaDoblemente* temp = cab;
        while (temp->sig != nullptr && temp->sig->Cliente.cant < nuevoNodo->Cliente.cant) {
            temp = temp->sig;
        }
        if (temp->sig == nullptr) { // insertar al final
            temp->sig = nuevoNodo;
            nuevoNodo->ant = temp;
            fin = nuevoNodo;
        }
        else { // insertar en medio
            nuevoNodo->sig = temp->sig;
            nuevoNodo->ant = temp;
            temp->sig->ant = nuevoNodo;
            temp->sig = nuevoNodo;
        }
    }
}


void eliminarDoblemente(NodoListaDoblemente*& cab, NodoListaDoblemente*& fin, int* id) {
    LimpiarPatalla();
    if (cab != NULL) {
        int idDeposito;
        cout << "Ingrese el id de la remesa a eliminar: \n";
        cin >> idDeposito;
        NodoListaDoblemente* temp = cab;
        NodoListaDoblemente* prev = NULL;
        while (temp != NULL) {
            if (temp->Cliente.idDeposito == idDeposito) {
                if (prev == NULL) { // Eliminar el primer nodo
                    cab = cab->sig;
                    if (cab != NULL) {
                        cab->ant = NULL;
                    }
                    else {
                        fin = NULL;
                    }
                }
                else if (temp->sig == NULL) { // Eliminar el último nodo
                    prev->sig = NULL;
                    fin = prev;
                }
                else { // Eliminar un nodo que no es el primero ni el último
                    prev->sig = temp->sig;
                    temp->sig->ant = prev;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->sig;
        }
        cout << "El id de el deposito " << idDeposito << " no se encontró en la lista.\n";
    }
    else {
        cout << "No hay remesas";
    }
    _getch();
}

void vaciarDoblemente(NodoListaDoblemente*& cab, NodoListaDoblemente*& fin, int* id) {
    NodoListaDoblemente* temp;
    while (cab != nullptr) {
        temp = cab;
        cab = cab->sig;
        delete temp;
    }
    fin = nullptr;
}


void MostrarDoblemente(NodoListaDoblemente*& cab, NodoListaDoblemente*& fin, int* id) {
    LimpiarPatalla();
    NodoListaDoblemente* actual = cab;
    int constante = 20, aumentar = 2;
    gotoxy(constante, 1);cout << "Ordenados de menor a mayor segun la cantidad";

    if (cab != NULL) {
        while (actual != NULL) {
            gotoxy(constante, aumentar++); cout << "------------------------------";
            gotoxy(constante, aumentar++); cout << "Direccion: " << &actual->Cliente;
            gotoxy(constante, aumentar++);cout << "Numero de deposito: " << actual->Cliente.idDeposito;
            gotoxy(constante, aumentar++);cout << "Cantidad: " << actual->Cliente.cant;
            gotoxy(constante, aumentar++);cout << "Nombre del cliente: " << actual->Cliente.nombre;
            gotoxy(constante, aumentar++);cout << "Apellido del cliente: " << actual->Cliente.apellido;
            gotoxy(constante, aumentar++);cout << "DPI cliente " << actual->Cliente.dpi;
            gotoxy(constante, aumentar++);cout << "Fecha " << actual->Cliente.fecha;
            gotoxy(constante, aumentar++);cout << "Anterior:  " << &actual->ant;
            gotoxy(constante, aumentar++); cout << "Siguiente ->" << actual->sig;
            gotoxy(constante, aumentar++); cout << "------------------------------";
            aumentar = aumentar + 1;
            actual = actual->sig;
        }
    }
    else {
        cout << "No hay registros";
    }
    _getch();
};







#endif