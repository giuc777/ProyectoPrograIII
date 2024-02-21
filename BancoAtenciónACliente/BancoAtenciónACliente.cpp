
#include <iostream>
#include "template.h"

struct Clientes {
    int id;
    string nombre;
    int edad;
};

struct nodo {
    Clientes cliente;
    nodo* siguiente;
};

void pop(nodo*& pila, int* id);
void push(nodo*& pila, int*id);
int menu();
void RecorerPila(nodo*& pila, int* id);
void ModificarDatoPila(nodo*& pila, int* id);
void buscarDatoPila(nodo*& pila, int* id);

int main()
{
    nodo* pila = NULL;
    int opcion, id = 0;
    do {
        opcion = menu();

        switch (opcion) {
        case 1:
            
            push(pila, &id);
            break;
            // Aquí puedes agregar más casos para más opciones
        case 2:
            RecorerPila(pila, &id);
            break;
        case 3:
            pop(pila, &id);
            break;
        case 4:
            buscarDatoPila(pila, &id);
            break;
        case 5:
            ModificarDatoPila(pila, &id);
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (opcion != 6);

    
}

int menu() {
    LimpiarPatalla();
    int opcion;
    cout << "\n\tMENU" << endl;
    cout << "1. Agregar elemento a la pila" << endl;
    cout << "2. Recorrer Pila" << endl;
    cout << "3.Salir"<<endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}

string convertiraMayuscula(string nombre) {
    for (int i = 0; i < nombre.size(); i++) {
        nombre[i] = toupper(nombre[i]);
    }
    return nombre;
}
void pop(nodo*& pila, int* id) {
    LimpiarPatalla();
    if (pila != NULL) { // Si la pila no está vacía
        (*id)--;
        nodo* aux = pila; // Creamos nodo auxiliar y le asignamos la pila
        pila = aux->siguiente; // Movemos el inicio de la pila al siguiente nodo
        delete aux; // Eliminamos el nodo auxiliar (el antiguo inicio de la pila)
    }
    else {
        cout << "La pila está vacía." << endl;
    }

}

void ModificarDatoPila(nodo*& pila, int* id) {
    LimpiarPatalla();
    string nombre;
    cout << "Ingrese el nombre de Usuario a modificar: ";
    cin >> nombre;
    nombre = convertiraMayuscula(nombre);
    nodo* aux = pila; // Creamos nodo auxiliar y le asignamos la pila
    nodo* encontrado = NULL;
    while (aux != NULL) { // Mientras no sea el final de la pila
        if (aux->cliente.nombre == nombre) {
            encontrado = aux;
        }
        aux = aux->siguiente; // Avanzamos a la siguiente posición
    }
    if (encontrado == NULL) {
        cout << "NO hay resultados " + nombre;
    }
    else {
        string nuevoNombre = encontrado->cliente.nombre;
        int nuevaEdad = encontrado->cliente.edad;
        cout << "Nombre: "; cin >> nuevoNombre; cout << endl;
        cout << "Edad: "; cin >> nuevaEdad; cin.ignore(); cout << endl;

        // Modificamos directamente los datos del nodo encontrado
        encontrado->cliente.nombre = nuevoNombre;
        encontrado->cliente.edad = nuevaEdad;

    }
    _getch();
}


void buscarDatoPila(nodo *&pila, int* id) {
    LimpiarPatalla();
    string nombre;
    cout << "Ingrese el nombre de usuario ";
    cin >> nombre;
    
    nodo* aux = pila; // Creamos nodo auxiliar y le asignamos la pila
    nodo* encontrado = NULL;
    while (aux != NULL) { // Mientras no sea el final de la pila
        if (aux->cliente.nombre == nombre) {
            encontrado = aux;
        }
        aux = aux->siguiente; // Avanzamos a la siguiente posición
    }
    if (encontrado == NULL) {
        cout << "NO hay resultados "+nombre;
    }
    else {
        cout << encontrado->cliente.nombre << " " << encontrado->cliente.edad;
    }
    _getch();
}


void push(nodo*& pila, int* id) {
    LimpiarPatalla();
    (*id)++;
    string nombre;
    int edad;
    cout << "Ingrese nombre de cliente \n";
    cin >> nombre;
    for (int i = 0; i < nombre.size(); i++) {
        nombre[i] = toupper(nombre[i]);
    }
    cout << "Ingrese edad de cliente \n";
    cin >> edad;
    nodo* nuevo_nodo = new nodo();
    nuevo_nodo->cliente.nombre = nombre;
    nuevo_nodo->cliente.edad = edad;
    nuevo_nodo->cliente.id = *id;
    nuevo_nodo->siguiente = NULL; // Inicializamos el puntero a NULL

    if (pila != NULL) { // Si la pila no está vacía
        
        nuevo_nodo->siguiente = pila; // El nuevo nodo apunta al inicio de la pila
    }
    pila = nuevo_nodo; // Ahora, el inicio de la pila es el nuevo nodo

}
void RecorerPila(nodo*& pila, int* id) {
    LimpiarPatalla();
    nodo* aux = pila; // Creamos nodo auxiliar y le asignamos la pila

    while (aux != NULL) { // Mientras no sea el final de la pila
        cout << aux->cliente.nombre << " "<<aux->cliente.edad<<" id: "<<aux->cliente.id<<endl; // Imprimimos el dato
        aux = aux->siguiente; // Avanzamos a la siguiente posición
    }
    system("pause");
}

