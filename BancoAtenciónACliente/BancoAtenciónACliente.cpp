
#include <iostream>
#include "template.h"


struct Clientes {
    int id;
    string nombre; //P y A
    string apellido; //P y A
    string DPI;//P y A
    string Telefono; //P y A
    int edad; // P y A
    char sexo;//A
    string fechaNacimiento;// A
    int numeroNis;//P y A
    int cantidad;//P y A
    //Para prestamos
    int ingresoBase;
};


struct nodo {
    Clientes cliente;
    nodo* siguiente;
};

void operacionesPila(nodo* pila);
void operacionesCola(nodo* cabecera, nodo* ultimo);
void pop(nodo*& inicio, int* id, bool esCola);
void push(nodo*& pila, int*id);
void pushCola(nodo*& primero, nodo*& ultimo, int* id);
int menu();
int submenu();
void Recorer(nodo*& pila, int* id, bool esCola);
void ModificarDatoPila(nodo*& pila, int* id);
void buscarDatoPila(nodo*& pila, int* id);

int main()
{
    nodo* pila = NULL, *primero=NULL, *ultimo = NULL;
    

    int opcion, id = 0;
    do {
        opcion = menu();

        switch (opcion) {
        case 1:
            
            operacionesPila(pila);
            break;
            // Aquí puedes agregar más casos para más opciones
        case 2:
            operacionesCola(primero, ultimo);
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (opcion != 6);

    
}

void operacionesPila(nodo * pila) {
    int operation;
    int id = 0;
    bool cola = false;
    
    do {
        operation = submenu();

        switch (operation) {
        case 1:

            push(pila, &id);
            break;
            // Aquí puedes agregar más casos para más opciones
        case 2:
            Recorer(pila, &id, cola);
            break;
        case 3:
            pop(pila, &id, cola);
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
    } while (operation != 6);

};
void operacionesCola(nodo* primero, nodo* ultimo) {
    int operation;
    int id = 0;
    bool cola = true;

    do {
        LimpiarPatalla();
        operation = submenu();

        switch (operation) {
        case 1:

            pushCola(primero,ultimo, &id);
            break;
            // Aquí puedes agregar más casos para más opciones
        case 2:
            Recorer(primero, &id, cola);
            break;
        case 3:
            pop(primero, &id, cola);
            break;
        case 4:
            buscarDatoPila(primero, &id);
            break;
        case 5:
            ModificarDatoPila(primero, &id);
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (operation != 6);
};


int submenu() {
    LimpiarPatalla();
    int opcion1;
    cout << "\n\tMENU" << endl;
    cout << "1. Agregar cliente" << endl;
    cout << "2. Mostrar clientes" << endl;
    cout << "3. Quitar cliente" << endl;
    cout << "4. Buscar cliente" << endl;
    cout << "5. Modificar datos de cliente" << endl;
    cout << "6. atras" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion1;
    return opcion1;
}

int menu() {
    LimpiarPatalla();
    int opcion;
    cout << "\n\tMENU" << endl;
    cout << "1. Modulo de datos de apertura de cuenta (Pila)" << endl;
    cout << "2. Modulo de datos de prestamos (Cola)" << endl;
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

void pop(nodo*& inicio, int* id, bool esCola) {
    LimpiarPatalla();
    if (inicio != NULL) { // Si la pila no está vacía
        if (!esCola) {
            (*id)--;
        }
        nodo* aux = inicio; // Creamos nodo auxiliar y le asignamos la pila
        inicio = aux->siguiente; // Movemos el inicio de la pila al siguiente nodo
        delete aux; // Eliminamos el nodo auxiliar (el antiguo inicio de la pila)
    }
    else {
        cout << "La pila está vacía." << endl;
    }

}

void ModificarDatoPila(nodo*& inicio, int* id) {
    LimpiarPatalla();
    int idBuscando;
    cout << "Ingrese el id del Usuario a modificar: ";
    cin >> idBuscando;
    nodo* aux = inicio; // Creamos nodo auxiliar y le asignamos la pila
    nodo* encontrado = NULL;
    while (aux != NULL) { // Mientras no sea el final de la pila
        if (aux->cliente.id == idBuscando) {
            encontrado = aux;
        }
        aux = aux->siguiente; // Avanzamos a la siguiente posición
    }
    if (encontrado == NULL) {
        cout << "No hay resultados " << idBuscando;
    }
    else {
        string nuevoNombre = encontrado->cliente.nombre;
        int nuevaEdad = encontrado->cliente.edad;
        cout << "Nombre: "; cin >> nuevoNombre; cout << endl;
        cout << "Edad: "; cin >> nuevaEdad; cin.ignore(); cout << endl;

        // Modificamos directamente los datos del nodo encontrado
        encontrado->cliente.nombre = nuevoNombre;
        encontrado->cliente.edad = nuevaEdad;

        cout << "Datos acutalizados nombre: " << encontrado->cliente.nombre << " edad: " << encontrado->cliente.edad;

    }
    _getch();
}


void buscarDatoPila(nodo *&inicio, int* id) {
    LimpiarPatalla();
    if (inicio == NULL) {
        cout << "No hay clientes";
    }
    else {
        int idUser;
        cout << "Ingrese el id de usuario ";
        cin >> idUser;
        //nombre = convertiraMayuscula(nombre);
        nodo* aux = inicio; // Creamos nodo auxiliar y le asignamos la pila
        nodo* encontrado = NULL;
        while (aux != NULL) { // Mientras no sea el final de la pila
            if (aux->cliente.id == idUser) {
                encontrado = aux;
            }
            aux = aux->siguiente; // Avanzamos a la siguiente posición
        }
        if (encontrado == NULL) {
            cout << "No existe el cliente " << idUser;
        }
        else {
            cout << encontrado->cliente.nombre << " edad: "
                << encontrado->cliente.edad << " id: " << encontrado->cliente.id;
        }
    }
    _getch();
}

void pushCola(nodo*& primero, nodo*& ultimo, int* id) { //esto es para el prestamo
    LimpiarPatalla();
    (*id)++;
    string nombre;
    int edad;
    cout << "Ingrese nombre de cliente \n";
    cin >> nombre;
    nombre = convertiraMayuscula(nombre);
    //El apellido
    //IngresoMensual
    //
    cout << "Ingrese edad de cliente \n";
    cin >> edad;
    nodo* nuevo_nodo = new nodo();
    nuevo_nodo->cliente.nombre = nombre;
    nuevo_nodo->cliente.edad = edad;
    nuevo_nodo->cliente.id = *id;


    if (primero == NULL) {
        primero = nuevo_nodo;
        primero->siguiente = NULL;
        ultimo = primero;
    }
    else {
        ultimo->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = NULL;
        ultimo = nuevo_nodo;
    }

    cout << "Se agrego el cliente " << nuevo_nodo->cliente.nombre << " con id: " << nuevo_nodo->cliente.id;
    _getch();

}

void push(nodo*& pila, int* id) { //esto es para la apertura
    LimpiarPatalla();
    (*id)++;
    string nombre;
    //sexo
    //otras
    int edad;
    cout << "Ingrese nombre de cliente \n";
    cin >> nombre;
    nombre = convertiraMayuscula(nombre);
    cout << "Ingrese edad de cliente \n";
    cin >> edad;
    nodo* nuevo_nodo = new nodo();
    //nuevo_nodo->cliente.sexo = sexo
    nuevo_nodo->cliente.nombre = nombre;
    nuevo_nodo->cliente.edad = edad;
    nuevo_nodo->cliente.id = *id;
    nuevo_nodo->siguiente = NULL; // Inicializamos el puntero a NULL

    if (pila != NULL) { // Si la pila no está vacía
        
        nuevo_nodo->siguiente = pila; // El nuevo nodo apunta al inicio de la pila
    }
    pila = nuevo_nodo; // Ahora, el inicio de la pila es el nuevo nodo

    cout << "Se agrego el cliente " << nuevo_nodo->cliente.nombre << " con id: " << nuevo_nodo->cliente.id;
    _getch();

}
void Recorer(nodo*& inicio, int* id, bool esCola) {
    LimpiarPatalla();
    nodo* aux = inicio; // Creamos nodo auxiliar y le asignamos la pila

    while (aux != NULL) { // Mientras no sea el final de la pila
        cout << aux->cliente.nombre << " "<<aux->cliente.edad<<" id: "<<aux->cliente.id; // Imprimimos el dato
        if (esCola) { //Imprimir los datos del prestamo
            cout << " sguiente en cola-> ";
            //los datos para la cola
        }
        else { //Imprimir los datos de Apertura
            cout << endl;
        }
        aux = aux->siguiente; // Avanzamos a la siguiente posición
    }
    system("pause");
}

