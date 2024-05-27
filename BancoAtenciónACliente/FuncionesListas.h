#pragma once
#include "Nodos.h"
#ifndef FUNCIONESLISTAS_H
#define FUNCIONESLISTAS_H
#include"menus.h"



int menuListas() {
    int opcionSubmenu = 1;
    const int OPCIONES = 6;

    int x = 22;
    int y = 5;
    int colorS = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
    string opciones[OPCIONES] = { "Nueva transferencia", "Mostrar Transferencias", "Quitar trasnferencias","Buscar Transferencia", "Vaciar registro", "atras"};
    opcionSubmenu = mostrarMenuInteractivo(opciones, OPCIONES, x, y, colorS);
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
    fecha = obtenerFechaActual();

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
        gotoxy(constante, aumentar++);cout << "DPI cliente: " << actual->Cliente.DPI;
        gotoxy(constante, aumentar++);cout << "Fecha: " << actual->Cliente.fecha;
        gotoxy(constante, aumentar++); cout << "Siguiente ->" << actual->sig;
        gotoxy(constante, aumentar++); cout << "------------------------------";
        aumentar = aumentar + 1;
        actual = actual->sig;
    }
    _getch();
};

//Listas circular
int menuListaCircular() {
    int opcionSubmenu = 1;
    const int OPCIONES = 6;

    int x = 22;
    int y = 5;
    int color = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
    string opciones[OPCIONES] = { "Nueva Remesa", "Mostrar remesa", "Quitar Remesa","Buscar Remesa", "Vaciar Registro", "Atras"};
    opcionSubmenu = mostrarMenuInteractivo(opciones, OPCIONES, x, y, color);

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
    fecha = obtenerFechaActual();

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
            gotoxy(constante, aumentar++);cout << "DPI cliente: " << actual->Cliente.DPI;
            gotoxy(constante, aumentar++);cout << "Fecha: " << actual->Cliente.fecha;
            gotoxy(constante, aumentar++);cout << "Pais origen remesa: " << actual->Cliente.paisOrigen;
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
    int opcionSubmenu = 1;
    const int OPCIONES = 6;

    int x = 22;
    int y = 5;
    int color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE;
    string opciones[OPCIONES] = { "Nuevo Depoito", "Mostrar Depositos", "Quitar Deposito", "Buscar Deposito","Vaciar registro","atras"};
    opcionSubmenu = mostrarMenuInteractivo(opciones, OPCIONES, x, y, color);

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
    fecha = obtenerFechaActual();

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
            gotoxy(constante, aumentar++);cout << "DPI cliente: " << actual->Cliente.dpi;
            gotoxy(constante, aumentar++);cout << "Fecha: " << actual->Cliente.fecha;
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


//Recorridos
NodoListaSimple* buscarEnListaSimple(NodoListaSimple* inicio, int id) {
    NodoListaSimple* actual = inicio;
    while (actual != nullptr) {
        if (actual->Cliente.idTrans == id) {
            return actual; // Se encontró el nodo
        }
        actual = actual->sig;
    }
    return nullptr; // No se encontró el nodo
}

// Función para buscar un nodo específico en una lista circular
NodoListaCircular* buscarEnListaCircular(NodoListaCircular* inicio, int id) {
    if (inicio == nullptr) return nullptr;

    NodoListaCircular* actual = inicio;
    do {
        if (actual->Cliente.idRemesa == id) {
            return actual; // Se encontró el nodo
        }
        actual = actual->sig;
    } while (actual != inicio);

    return nullptr; // No se encontró el nodo
}

// Función para buscar un nodo específico en una lista doblemente enlazada
NodoListaDoblemente* buscarEnListaDoblemente(NodoListaDoblemente* inicio, int id) {
    NodoListaDoblemente* actual = inicio;
    while (actual != nullptr) {
        if (actual->Cliente.idDeposito == id) {
            return actual; // Se encontró el nodo
        }
        actual = actual->sig;
    }
    return nullptr; // No se encontró el nodo
}


void ResultadoBusquedaSimple(NodoListaSimple* inicio) {
    LimpiarPatalla();
    int id;
    gotoxy(20, 2);cout << "Ingrese el id del usuario: ";
    gotoxy(20, 3);cin >> id;
    NodoListaSimple* busqueda = buscarEnListaSimple(inicio, id);
    if (busqueda != nullptr) {
        
        gotoxy(20, 5);cout << "Se encontro al cliente con " << id;
        int constante = 20, aumentar = 7;
        gotoxy(constante, aumentar++); cout << "------------------------------";
        gotoxy(constante, aumentar++);cout << "Numero de transferencia: " << busqueda->Cliente.idTrans;
        gotoxy(constante, aumentar++);cout << "Cantidad : " << busqueda->Cliente.cantidad;
        gotoxy(constante, aumentar++);cout << "Cuenta retirada : " << busqueda->Cliente.cuenta1;
        gotoxy(constante, aumentar++);cout << "Cuenta acreditada : " << busqueda->Cliente.cuenta2;
        gotoxy(constante, aumentar++);cout << "DPI cliente " << busqueda->Cliente.DPI;
        gotoxy(constante, aumentar++);cout << "Fecha " << busqueda->Cliente.fecha;
        gotoxy(constante, aumentar++); cout << "------------------------------";
    }
    else {
        LimpiarPatalla();
        cout << "No hay resultados del id" << id;
    }
}

void ResultadoBusquedaCircular(NodoListaCircular*inicio) {
    LimpiarPatalla();
    int id;
    gotoxy(20, 2);cout << "Ingrese el id del usuario: ";
    gotoxy(20, 3);cin >> id;
    NodoListaCircular * busqueda = buscarEnListaCircular(inicio, id);
    if (busqueda != nullptr) {
        int constante = 20, aumentar = 7;
        gotoxy(20, 5);cout << "Se encontro al cliente con " << id;
        gotoxy(constante, aumentar++); cout << "------------------------------";
        gotoxy(constante, aumentar++);cout << "Numero de remesa: " << busqueda->Cliente.idRemesa;
        gotoxy(constante, aumentar++);cout << "Cantidad: " << busqueda->Cliente.cantidad;
        gotoxy(constante, aumentar++);cout << "Nombre del cliente: " << busqueda->Cliente.nombre;
        gotoxy(constante, aumentar++);cout << "Apellido del cliente: " << busqueda->Cliente.apellido;
        gotoxy(constante, aumentar++);cout << "DPI cliente: " << busqueda->Cliente.DPI;
        gotoxy(constante, aumentar++);cout << "Fecha: " << busqueda->Cliente.fecha;
        gotoxy(constante, aumentar++);cout << "Pais origen remesa: " << busqueda->Cliente.paisOrigen;
        gotoxy(constante, aumentar++); cout << "------------------------------";
    }
    else {
        LimpiarPatalla();
        cout << "No hay resultados del id" << id;
    }

}

void ResultadoBusquedaDoblemente(NodoListaDoblemente*inicio) {
    LimpiarPatalla();
    int id;
    gotoxy(20, 2);cout << "Ingrese el id del usuario: ";
    gotoxy(20, 3);cin >> id;
    NodoListaDoblemente* busqueda = buscarEnListaDoblemente(inicio, id);
    if (busqueda != nullptr) {
        int constante = 20, aumentar = 7;
        gotoxy(20, 5);cout << "Se encontro al cliente con " << id;
        gotoxy(constante, aumentar++); cout << "------------------------------";
        gotoxy(constante, aumentar++);cout << "Numero de deposito: " << busqueda->Cliente.idDeposito;
        gotoxy(constante, aumentar++);cout << "Cantidad: " << busqueda->Cliente.cant;
        gotoxy(constante, aumentar++);cout << "Nombre del cliente: " << busqueda->Cliente.nombre;
        gotoxy(constante, aumentar++);cout << "Apellido del cliente: " << busqueda->Cliente.apellido;
        gotoxy(constante, aumentar++);cout << "DPI cliente: " << busqueda->Cliente.dpi;
        gotoxy(constante, aumentar++);cout << "Fecha: " << busqueda->Cliente.fecha;
        gotoxy(constante, aumentar++); cout << "------------------------------";
    }
    else {
        LimpiarPatalla();
        cout << "No hay resultados del id" << id;
    }


}
#endif