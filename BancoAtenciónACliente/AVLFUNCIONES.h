#pragma once
#include "template.h"
#define AVLFUNCIONES_H
#include "Nodos.h"

int menuAVL() {
    LimpiarPatalla();
    int opcionSubmenu = 1;
    int maxOpcion = 6;
    char tecla;


    system("color F0");
    do {
        gotoxy(20, 2); cout << ("********************MENU******************");
        gotoxy(20, 3); cout << ((opcionSubmenu == 1) ? "*-> Nuevo pago de luz" : "  Nuevo pago de luz*  ");
        gotoxy(20, 4); cout << ((opcionSubmenu == 2) ? "*-> Mostrar pagos de luz" : "  Mostrar pago de luz*  ");
        gotoxy(20, 5); cout << ((opcionSubmenu == 3) ? "*-> Quitar pagos" : "  Quitar pago *  ");
        gotoxy(20, 6); cout << ((opcionSubmenu == 4) ? "*-> Buscar pago " : "  Buscar pago*  ");
        gotoxy(20, 7); cout << ((opcionSubmenu == 5) ? "*-> Recorrer" : "  Recorrer*  ");
        gotoxy(20, 8); cout << ((opcionSubmenu == 6) ? "*-> atras" : " atras*  ");
        gotoxy(20, 9); cout << ("*********************************************");

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


//Insertar

int obtenerAltura(NodoAVL* nodo) {
    return nodo ? nodo->altura : 0;
}

int obtenerFactorBalance(NodoAVL* nodo) {
    if (!nodo) return 0;
    return obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho);
}

NodoAVL* rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierdo;
    NodoAVL* T2 = x->derecho;

    x->derecho = y;
    y->izquierdo = T2;

    y->altura = max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;
    x->altura = max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;

    return x;
}

NodoAVL* rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecho;
    NodoAVL* T2 = y->izquierdo;

    y->izquierdo = x;
    x->derecho = T2;

    x->altura = max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;
    y->altura = max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;

    return y;
}

NodoAVL* crearNodoAVL(string nombre, string apellido, string fecha, string dpi, int NoNis, int cantidad) {
    NodoAVL* nuevo_nodo = new NodoAVL();
    nuevo_nodo->cliente.nombre = nombre;
    nuevo_nodo->cliente.apellido = apellido;
    nuevo_nodo->cliente.dpi = dpi;
    nuevo_nodo->cliente.fecha = fecha;
    nuevo_nodo->cliente.NoNis = NoNis;
    nuevo_nodo->cliente.cantidad = cantidad;
    nuevo_nodo->altura = 1;
    nuevo_nodo->derecho = nullptr;
    nuevo_nodo->izquierdo = nullptr;

    

    return nuevo_nodo;
}


NodoAVL* insertarAVL(NodoAVL* nodo, string nombre, string apellido, string fecha, string dpi, int NoNis, int cantidad) {
    if (!nodo) return crearNodoAVL(nombre, apellido, fecha, dpi, NoNis, cantidad);

    if (cantidad < nodo->cliente.cantidad)
        nodo->izquierdo = insertarAVL(nodo->izquierdo, nombre, apellido, fecha, dpi, NoNis, cantidad);
    else if (cantidad > nodo->cliente.cantidad)
        nodo->derecho = insertarAVL(nodo->derecho, nombre, apellido, fecha, dpi, NoNis, cantidad);
    else
        return nodo;

    nodo->altura = 1 + max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

    int balance = obtenerFactorBalance(nodo);

    if (balance > 1 && cantidad < nodo->izquierdo->cliente.cantidad)
        return rotacionDerecha(nodo);

    if (balance < -1 && cantidad > nodo->derecho->cliente.cantidad)
        return rotacionIzquierda(nodo);

    if (balance > 1 && cantidad > nodo->izquierdo->cliente.cantidad) {
        nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && cantidad < nodo->derecho->cliente.cantidad) {
        nodo->derecho = rotacionDerecha(nodo->derecho);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void obtenerDatosAVL(NodoAVL*& arbol) {
    int constante = 20, aumentar = 2;
    LimpiarPatalla();
    int cantidad, NoNis;
    string nombre, fecha, dpi, apellido;
    gotoxy(constante, aumentar++); cout << "Ingrese DPI del cliente: ";
    gotoxy(constante, aumentar++); cin >> dpi;
    gotoxy(constante, aumentar++); cout << "Ingrese la cantidad: ";
    gotoxy(constante, aumentar++); cin >> cantidad;
    gotoxy(constante, aumentar++); cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    gotoxy(constante, aumentar++); getline(cin, nombre);
    gotoxy(constante, aumentar++); cout << "Ingrese el apellido del cliente: ";
    gotoxy(constante, aumentar++); getline(cin, apellido);
    gotoxy(constante, aumentar++); cout << "Ingrese la fecha: ";
    gotoxy(constante, aumentar++); cin >> fecha;
    gotoxy(constante, aumentar++); cout << "Ingrese el numero de NIS: ";
    gotoxy(constante, aumentar++); cin >> NoNis;
    arbol = insertarAVL(arbol, nombre, apellido, fecha, dpi, NoNis, cantidad);
    gotoxy(constante, aumentar++); cout << "Se completo el pago de " << cantidad;
    _getch();
}


NodoAVL* obtenerNodoMinimo(NodoAVL* nodo) {
    NodoAVL* actual = nodo;
    while (actual->izquierdo != nullptr)
        actual = actual->izquierdo;
    return actual;
}

NodoAVL* eliminarAVL(NodoAVL* raiz, int dato) {
    // 1. Realizar la eliminación normal de un BST
    if (raiz == nullptr)
        return raiz;

    if (dato < raiz->cliente.cantidad)
        raiz->izquierdo = eliminarAVL(raiz->izquierdo, dato);
    else if (dato > raiz->cliente.cantidad)
        raiz->derecho = eliminarAVL(raiz->derecho, dato);
    else {
        // Nodo con solo un hijo o sin hijos
        if ((raiz->izquierdo == nullptr) || (raiz->derecho == nullptr)) {
            NodoAVL* temp = raiz->izquierdo ? raiz->izquierdo : raiz->derecho;

            // Sin hijo
            if (temp == nullptr) {
                temp = raiz;
                raiz = nullptr;
            }
            else // Un hijo
                *raiz = *temp; // Copiar el contenido del hijo no vacío

            delete temp;
        }
        else {
            // Nodo con dos hijos: obtener el sucesor en inorden (el menor en el subárbol derecho)
            NodoAVL* temp = obtenerNodoMinimo(raiz->derecho);

            // Copiar el valor del sucesor en este nodo
            raiz->cliente.cantidad = temp->cliente.cantidad;

            // Eliminar el sucesor en inorden
            raiz->derecho = eliminarAVL(raiz->derecho, temp->cliente.cantidad);
        }
    }

    // Si el árbol tiene solo un nodo, devolverlo
    if (raiz == nullptr)
        return raiz;

    // 2. Actualizar la altura del nodo actual
    raiz->altura = 1 + max(obtenerAltura(raiz->izquierdo), obtenerAltura(raiz->derecho));

    // 3. Obtener el factor de balance del nodo actual
    int balance = obtenerFactorBalance(raiz);

    // 4. Si el nodo está desbalanceado, hay 4 casos a considerar

    // Caso Izquierda-Izquierda
    if (balance > 1 && obtenerFactorBalance(raiz->izquierdo) >= 0)
        return rotacionDerecha(raiz);

    // Caso Izquierda-Derecha
    if (balance > 1 && obtenerFactorBalance(raiz->izquierdo) < 0) {
        raiz->izquierdo = rotacionIzquierda(raiz->izquierdo);
        return rotacionDerecha(raiz);
    }

    // Caso Derecha-Derecha
    if (balance < -1 && obtenerFactorBalance(raiz->derecho) <= 0)
        return rotacionIzquierda(raiz);

    // Caso Derecha-Izquierda
    if (balance < -1 && obtenerFactorBalance(raiz->derecho) > 0) {
        raiz->derecho = rotacionDerecha(raiz->derecho);
        return rotacionIzquierda(raiz);
    }

    return raiz;
}

NodoAVL* buscarAVL(NodoAVL* raiz, int dato) {
    if (raiz == nullptr || raiz->cliente.cantidad == dato)
        return raiz;

    if (dato < raiz->cliente.cantidad)
        return buscarAVL(raiz->izquierdo, dato);

    return buscarAVL(raiz->derecho, dato);
}

void mostrarAVL(NodoAVL* nodo, int cont, int vert, bool primeraVez) {
    if (nodo == nullptr) {
        return;
    }
    else {
        gotoxy(cont, vert++); cout << nodo->cliente.nombre;
        gotoxy(cont, vert++); cout << nodo->cliente.cantidad;
        if (nodo->izquierdo && nodo->derecho) {
            // Si tiene dos hijos, dibuja las ramas "/" y "\"
            int tempVert = vert;
            if (primeraVez) {
                gotoxy(cont - 10, vert); cout << "/";
                gotoxy(cont + 13, tempVert); cout << "\\";
                int tempContLeft = cont - 11;
                int tempContRight = cont + 11;
                mostrarAVL(nodo->izquierdo, tempContLeft, vert + 1, false);
                mostrarAVL(nodo->derecho, tempContRight, vert + 1, false);
            }
            else {
                gotoxy(cont - 2, vert); cout << "/";
                gotoxy(cont + 7, tempVert); cout << "\\";
                int tempContLeft = cont - 4;
                int tempContRight = cont + 5;
                mostrarAVL(nodo->izquierdo, tempContLeft, vert + 1, false);
                mostrarAVL(nodo->derecho, tempContRight, vert + 1, false);
            }
        }
        else {
            // Si tiene un hijo, dibuja la rama correspondiente y continúa la impresión en esa dirección.
            if (nodo->izquierdo) {
                cont = cont - 4;
                gotoxy(cont, vert++); cout << "/";
                mostrarAVL(nodo->izquierdo, cont, vert, primeraVez);
            }
            if (nodo->derecho) {
                cont = cont + 5;
                gotoxy(cont, vert++); cout << "\\";
                mostrarAVL(nodo->derecho, cont, vert, primeraVez);
            }
        }
    }
}

void preOrdenAVL(NodoAVL* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->cliente.cantidad << " - ";
        preOrdenAVL(arbol->izquierdo);
        preOrdenAVL(arbol->derecho);
    }
};

void inOrdenAVL(NodoAVL* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        inOrdenAVL(arbol->izquierdo);
        cout << arbol->cliente.cantidad << " - ";
        inOrdenAVL(arbol->derecho);
    }
};


void postOrdenAVL(NodoAVL* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        postOrdenAVL(arbol->izquierdo);
        postOrdenAVL(arbol->derecho);
        cout << arbol->cliente.cantidad << " - ";
    }
};

void ordenAVL(NodoAVL* arbol) {
    int operation;

    do {
        LimpiarPatalla();
        operation = menuOrden();

        switch (operation) {
        case 1:
            LimpiarPatalla();
            preOrdenAVL(arbol);
            _getch();
            break;
        case 2:
            LimpiarPatalla();
            inOrdenAVL(arbol);
            _getch();
            break;
        case 3:
            LimpiarPatalla();
            postOrdenAVL(arbol);
            _getch();
        default:
            cout << "Opción no válida." << endl;
        }
    } while (operation != 4);
}


