#pragma once
#include "Nodos.h"
#include "template.h"
#include"menus.h"
#ifndef FUNCIONESARBOLES_H
#define FUNCIONESARBOLES_H


int menuABB() {
    int opcionSubmenu = 1;
    const int OPCIONES = 7;

    int x = 22;
    int y = 5;
    int colorS = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE;
    string opciones[OPCIONES] = { "Nuevo retiro","Mostrar retiros","Quitar retiros","Buscar retiro","Recorrer","Modificar retiro", "atras"};
    opcionSubmenu = mostrarMenuInteractivo(opciones, OPCIONES, x, y, colorS);

    return opcionSubmenu;
};

NodoABB* crearNodo(int cant, string nombre, string cuenta, string fecha, string DPI, string apellido, NodoABB* padre) {
    NodoABB* nuevo_nodo = new NodoABB();

    nuevo_nodo->Cliente.cantidad = cant;
    nuevo_nodo->Cliente.nombre = nombre;
    nuevo_nodo->Cliente.apellido = apellido;
    nuevo_nodo->Cliente.cuenta = cuenta;
    nuevo_nodo->Cliente.fecha = fecha;
    nuevo_nodo->Cliente.DPI = DPI;
    nuevo_nodo->d = NULL;
    nuevo_nodo->i = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}



void insertarABB(NodoABB*& arbol, int cantidad, string nombre, string cuenta, string fecha, string DPI, string apellido, NodoABB* padre) {

    if (arbol == NULL) {
        NodoABB* nuevo_nodo = crearNodo(cantidad, nombre, cuenta, fecha, DPI, apellido, padre);
        arbol = nuevo_nodo;
    }
    else {
        int ValorRaiz = arbol->Cliente.cantidad;
        if (cantidad < ValorRaiz) {//Si el valor es menor a la cantidad raíz se inserta a la izquierda
            insertarABB(arbol->i, cantidad, nombre, cuenta, fecha, DPI, apellido, arbol);
        }
        else {
            insertarABB(arbol->d, cantidad, nombre, cuenta, fecha, DPI, apellido, arbol);
        }
    }

};

void AgregarNodoABB(NodoABB*& arbol) {
    int constante = 20, aumentar = 2;
    LimpiarPatalla();
    int cantidad;
    string nombre, cuenta, fecha, dpi, apellido;
    gotoxy(constante, aumentar++);cout << "Ingrese DPI del cliente: ";
    gotoxy(constante, aumentar++);cin >> dpi;
    gotoxy(constante, aumentar++);cout << "Ingrese la cuenta a retirar: ";
    gotoxy(constante, aumentar++);cin >> cuenta;
    gotoxy(constante, aumentar++);cout << "Ingrese la cantidad: ";
    gotoxy(constante, aumentar++);cin >> cantidad;
    gotoxy(constante, aumentar++);cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    gotoxy(constante, aumentar++);getline(cin, nombre);
    gotoxy(constante, aumentar++);cout << "Ingrese el apellido del cliente: ";
    gotoxy(constante, aumentar++);getline(cin, apellido);
    fecha = obtenerFechaActual();
    insertarABB(arbol, cantidad, nombre, cuenta, fecha, dpi, apellido, NULL);
    gotoxy(constante, aumentar++);cout << "Se completo el retiro de la catidad de " << cantidad;
    _getch();
}

NodoABB* NodominimoABB(NodoABB* arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->i) {
        return NodominimoABB(arbol->i);
    }
    else {
        return arbol;
    }
};

void mostrarABB(NodoABB* arbol, int cont, int vert, bool primeraVez) {
    if (arbol == NULL) {
        return;
    }
    else {
        gotoxy(cont, vert++); cout << arbol->Cliente.nombre;
        gotoxy(cont, vert++); cout << arbol->Cliente.cantidad;
        if (arbol->i && arbol->d) {
            // Si tiene dos hijos, dibuja las ramas "/" y "\"
            int tempVert = vert;
            if (primeraVez) {
                gotoxy(cont - 10, vert); cout << "/";
                gotoxy(cont + 13, tempVert); cout << "\\";
                int tempContLeft = cont - 11;
                int tempContRight = cont + 11;
                mostrarABB(arbol->i, tempContLeft, vert + 1, false);
                mostrarABB(arbol->d, tempContRight, vert + 1, false);
            }
            else {
                gotoxy(cont - 2, vert); cout << "/";
                gotoxy(cont + 7, tempVert); cout << "\\";
                int tempContLeft = cont - 4;
                int tempContRight = cont + 5;
                mostrarABB(arbol->i, tempContLeft, vert + 1, false);
                mostrarABB(arbol->d, tempContRight, vert + 1, false);
            }

            
        }
        else {
            // Si tiene un hijo, dibuja la rama correspondiente
            // y continua la impresión en esa dirección.
            if (arbol->i) {
                cont = cont - 4;
                gotoxy(cont, vert++); cout << "/";
                mostrarABB(arbol->i, cont, vert, primeraVez);
            }
            if (arbol->d) {
                cont = cont + 5;
                gotoxy(cont, vert++); cout << "\\";
                mostrarABB(arbol->d, cont, vert, primeraVez);
            }
        }
    }
    
}



bool busquedaABB(NodoABB* arbol, int cant, NodoABB** aux) {
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->Cliente.cantidad == cant) {
        *aux = arbol;
        return true;
    }
    else if (cant < arbol->Cliente.cantidad) {
        return busquedaABB(arbol->i, cant, aux);
    }
    else {
        return busquedaABB(arbol->d, cant, aux);
    }
}; 

void resulBusqABB(NodoABB* arbol, int constante, int aumentar) {
    LimpiarPatalla();
    int buscar;
    gotoxy(20, 2);cout << "Ingrese la cantidad a buscar: ";
    gotoxy(20, 3);cin>>buscar;

    NodoABB* aux = NULL;
   
    if (busquedaABB(arbol, buscar, &aux)) {
        gotoxy(20, 5);cout<<"Se encontro la cantidad de "<<buscar;
        
        gotoxy(constante, aumentar++);cout << "Detalles: ";
        gotoxy(constante, aumentar++);cout << "Nombre: " <<aux->Cliente.nombre;
        gotoxy(constante, aumentar++);cout << "Apellido: " << aux->Cliente.apellido;
        gotoxy(constante, aumentar++);cout << "DPI: " << aux->Cliente.DPI;
        gotoxy(constante, aumentar++);cout << "Retirado: " << aux->Cliente.cantidad;
        gotoxy(constante, aumentar++);cout << "cuenta: " << aux->Cliente.cuenta;
        gotoxy(constante, aumentar++);cout << "Fecha: " << aux->Cliente.fecha;
    }
    else {
        gotoxy(20, 5);cout << "No se encontro " << buscar;
    }

    _getch();

};



void preOrdenABB(NodoABB* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->Cliente.cantidad << " - ";
        preOrdenABB(arbol->i);
        preOrdenABB(arbol->d);
    }
};

void inOrdenABB(NodoABB* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        inOrdenABB(arbol->i);
        cout << arbol->Cliente.cantidad<<" - ";
        inOrdenABB(arbol->d);
    }
};


void postOrdenABB(NodoABB* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        postOrdenABB(arbol->i);
        postOrdenABB(arbol->d);
        cout << arbol->Cliente.cantidad << " - ";
    }
};

void ordenABB(NodoABB* arbol) {
    int operation;

    do {
        LimpiarPatalla();
        operation = menuOrden();

        switch (operation) {
        case 1:
            LimpiarPatalla();
            preOrdenABB(arbol);
            _getch();
            break;
        case 2:
            LimpiarPatalla();
            inOrdenABB(arbol);
            _getch();
            break;
        case 3:
            LimpiarPatalla();
            postOrdenABB(arbol);
            _getch();
        default:
            cout << "Opción no válida." << endl;
        }
    } while (operation != 4);
}



void destruirNodoABB(NodoABB*eliminar) {
    eliminar->d = NULL;
    eliminar->i = NULL;
    delete eliminar;
};

void reemplazarNodoABB(NodoABB*arbol, NodoABB*nuevoNodo) {
    if (arbol->padre) {
        if (arbol->Cliente.cantidad == arbol->padre->i->Cliente.cantidad) {
            // Esta parte es el error ya que si el nodo que queremos eliminar es un nodo hoja, y el nodo es una hoja derecha, tendríamos un nullpointerexception al querer obtener el dato de la hoja izquierda porque no existe
            arbol->padre->i = nuevoNodo;


        }
        else if (arbol->Cliente.cantidad == arbol->padre->d->Cliente.cantidad) {
            arbol->padre->d = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre;
    }
};

void eliminarNodoABB(NodoABB* eliminar) {
    if (eliminar->i && eliminar->d) {
        NodoABB* menor = NodominimoABB(eliminar->d);
        eliminar->Cliente.nombre = menor->Cliente.nombre;
        eliminar->Cliente.apellido = menor->Cliente.apellido;
        eliminar->Cliente.cantidad = menor->Cliente.cantidad;
        eliminar->Cliente.cuenta = menor->Cliente.cuenta;
        eliminar->Cliente.DPI = menor->Cliente.DPI;
        eliminar->Cliente.fecha = menor->Cliente.fecha;
        eliminarNodoABB(menor); 

    }
    else if (eliminar->i) {
        reemplazarNodoABB(eliminar, eliminar->i);
        destruirNodoABB(eliminar);
    }
    else if (eliminar->d) {
        reemplazarNodoABB(eliminar, eliminar->d);
        destruirNodoABB(eliminar);
    }
    else {//No tiene hijos
        reemplazarNodoABB(eliminar, NULL);
        destruirNodoABB(eliminar);
    }
}

void eliminarABB(NodoABB* arbol, int dato) {
    if (arbol == NULL) {
        return;
    }
    else if (dato < arbol->Cliente.cantidad) {
        eliminarABB(arbol->i, dato);//Busca por la izquierda
    }
    else if (dato > arbol->Cliente.cantidad) {
        eliminarABB(arbol->d, dato);
    }
    else {
        eliminarNodoABB(arbol);
    }
}

int menuModificarABB() {
    int optionGeneral = 1;
    system("color 2F");
    const int OPCIONES = 6;
    int colorFondo = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; // Blanco sobre azul
    int x = 45;
    int y = 3;
    string opciones[OPCIONES] = { "Modificar Nombre" , "Modificar Apellido ", "Modificar DPI ", "Modificar Cantidad Retiro ", "Modificar Cuenta ", "Volver" };
    optionGeneral = mostrarMenuInteractivoSinBorrar(opciones, OPCIONES, x, y, colorFondo);
    return optionGeneral;
}

NodoABB* ReestructurarABB(NodoABB* arbol, int cantidad, string nombre, string cuenta, string fecha, string dpi, string apellido, NodoABB* padre, int cantidadEliminar) {
    insertarABB(arbol, cantidad, nombre, cuenta, fecha, dpi, apellido, NULL);
    eliminarABB(arbol, cantidadEliminar);
    NodoABB* nuevo_nodo = NULL;
    busquedaABB(arbol, cantidad, &nuevo_nodo);
    return nuevo_nodo;
};

void modificarABB(NodoABB* arbol) {
    LimpiarPatalla();
    int constante = 5;
    int aumentar = 4;
    int optionUser;
    string nuevoValorString;
    int nuevoValorInt;
    int buscar;
    gotoxy(20, 2);cout << "Ingrese la cantidad a buscar: ";
    gotoxy(20, 3);cin >> buscar;

    NodoABB* aux = NULL;

    if (busquedaABB(arbol, buscar, &aux)) {
        
        NodoABB* encontrado = aux;
        

        do {
            LimpiarPatalla();
            gotoxy(20, 2);cout << "Cliente a modificar:  " << encontrado->Cliente.DPI;

            gotoxy(constante, aumentar++);cout << "Detalles";
            gotoxy(constante, aumentar++);cout << "Nombre: " << encontrado->Cliente.nombre;
            gotoxy(constante, aumentar++);cout << "Apellido: " << encontrado->Cliente.apellido;
            gotoxy(constante, aumentar++);cout << "DPI: " << encontrado->Cliente.DPI;
            gotoxy(constante, aumentar++);cout << "Retirado: " << encontrado->Cliente.cantidad;
            gotoxy(constante, aumentar++);cout << "cuenta: " << encontrado->Cliente.cuenta;
            gotoxy(constante, aumentar++);cout << "cuenta: " << encontrado->Cliente.fecha;

            optionUser = menuModificarABB();

            switch (optionUser)
            {
            case 1:
                cin.ignore();
                system("color 2F");
                gotoxy(constante, 12);
                cout << "Ingrese el nuevo nombre: ";
                getline(cin, nuevoValorString);
                encontrado->Cliente.nombre = nuevoValorString;
                LimpiarPatalla();
                aumentar = 4;
                break;
            case 2: // Apellido
                cin.ignore();
                system("color 2F");
                gotoxy(constante, 12);
                cout << "Ingresa el nuevo apellido: ";
                getline(cin, nuevoValorString);
                encontrado->Cliente.apellido = nuevoValorString;
                LimpiarPatalla();
                aumentar = 4;
                break;

            case 3: // DPI
                cin.ignore();
                system("color 2F");
                gotoxy(constante, 12);
                cout << "Ingresa el nuevo DPI: ";
                getline(cin, nuevoValorString);
                encontrado->Cliente.DPI = nuevoValorString;
                LimpiarPatalla();
                aumentar = 4;
                break;

            case 4: // Teléfono
                cin.ignore();
                system("color 2F");
                gotoxy(constante, 12);
                cout << "Ingresa el monto del retiro: ";
                cin>>nuevoValorInt;
                encontrado = ReestructurarABB(arbol, nuevoValorInt, aux->Cliente.nombre, aux->Cliente.cuenta, aux->Cliente.fecha, aux->Cliente.DPI, aux->Cliente.apellido, NULL, buscar);;
                LimpiarPatalla();
                aumentar = 4;
                break;

            case 5: // Edad
                cin.ignore();
                system("color 2F");
                gotoxy(constante, 12);
                cout << "Ingresa la cuenta afectada: ";
                getline(cin, nuevoValorString);
                encontrado->Cliente.cuenta = nuevoValorString;
                LimpiarPatalla();
                aumentar = 4;
                break;

            default:
                break;
            }
        } while (optionUser != 6);


    }
    else {
        gotoxy(20, 5);cout << "No se encontro " << buscar;
    }


    
    

}
#endif

//struct ClientesRetiro {
//int idRetiro, cantidad;
//string nombreCliente, cuenta, fecha, DPI;
//}