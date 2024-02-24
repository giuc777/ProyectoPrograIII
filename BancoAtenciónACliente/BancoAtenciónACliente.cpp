
#include <iostream>
#include "template.h"


struct Clientes {
    int id;
    string nombre; //Prestamos y Apertura
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
void imprimirEncabezado();
int submenu();
int menuModificar(bool esCola);
void Recorer(nodo*& pila, int* id, bool esCola);
void ModificarDato(nodo*& pila, int* id, bool esCola);
void buscarDato(nodo*& pila, int* id, bool esCola);
void imprimirCliente(nodo*& nodo, bool esCola, int constante, int aumento);

int main()
{
    nodo* pila = NULL, *primero=NULL, *ultimo = NULL;
    imprimirEncabezado();

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
        case3:
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (opcion != 3);

    
}

void imprimirEncabezado() {
    
    gotoxy(20, 7);std::cout << "  BBBBBB  AAAAAA  NNN   N  CCCCCC  OOOOO ";
    gotoxy(20, 8);std::cout << "  B     B A     A N   N N C       O    O ";
    gotoxy(20, 9); std::cout << "  BBBBBB  AAAAAA  N    NN C       O    O ";
    gotoxy(20, 10);std::cout << "  B     B A     A N    NN C       O    O ";
    gotoxy(20, 11);std::cout << "  BBBBBB  A     A N    NN  CCCCCC  OOOOO ";
    _getch();
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
            buscarDato(pila, &id, cola);
            break;
        case 5:
            ModificarDato(pila, &id, cola);
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
            buscarDato(primero, &id, cola);
            break;
        case 5:
            ModificarDato(primero, &id,cola);
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (operation != 6);
};


int submenu() {
    LimpiarPatalla();
    int opcion1;

    gotoxy(35, 7);cout << "MENU" << endl;
    gotoxy(15, 8);cout << "1. Agregar cliente" << endl;
    gotoxy(15, 9);cout << "2. Mostrar clientes" << endl;
    gotoxy(15, 10);cout << "3. Quitar cliente" << endl;
    gotoxy(15, 11);cout << "4. Buscar cliente" << endl;
    gotoxy(15, 12);cout << "5. Modificar datos de cliente" << endl;
    gotoxy(15, 13);cout << "6. atras" << endl;
    gotoxy(25, 14);cout << "Ingrese una opcion: ";
    cin >> opcion1;
    return opcion1;
}

int menu() {
    LimpiarPatalla();
    int opcion;
    gotoxy(35, 7);cout << "MENU" << endl;
    gotoxy(17, 8);cout << "1. Modulo de datos de apertura de cuenta (Pila)" << endl;
    gotoxy(17, 9);cout << "2. Modulo de datos de prestamos (Cola)" << endl;
    gotoxy(27, 10);cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
    
}

int menuModificar(bool esCola) {
    int option;

    cout << "Modificar: "<<endl;
    cout << "1. nombre" << endl;
    cout << "2. Apellido" << endl;
    cout << "3. DPI" << endl;
    cout << "4. telefono" << endl;
    cout << "5. Edad" << endl;
    cout << "6. Numero Nis" << endl;
    if (esCola) {
        cout << "7. Cantidad del prestamo" << endl;
        cout << "8. Ingreso base" << endl;
        cout << "9.Volver" << endl;
    }
    else {
        cout << "7. Primer deposito" << endl;
        cout << "8. Sexo" << endl;
        cout << "9. Fecha  de Nacimiento" << endl;
        cout << "10. Volver" << endl;
    }
    cin >> option;
    return option;

};

void imprimirCliente(nodo*& nodo, bool esCola, int constante, int aumento) {
    
    gotoxy(constante, aumento++);cout << "Se agrego los datos del cliente: ";
    gotoxy(constante, aumento++);cout << "Con un ID: " << nodo->cliente.id;
    gotoxy(constante, aumento++);cout << "Nombre: " << nodo->cliente.nombre;
    gotoxy(constante, aumento++);cout << "Apellido: " << nodo->cliente.apellido;
    gotoxy(constante, aumento++);cout << "DPI: " << nodo->cliente.DPI;
    gotoxy(constante, aumento++);cout << "Telefono: " << nodo->cliente.Telefono;
    gotoxy(constante, aumento++);cout << "Edad: " << nodo->cliente.edad;
    
  

    if (esCola) {
        gotoxy(constante, aumento++);cout << "Cantidad credito " << nodo->cliente.cantidad;
        gotoxy(constante, aumento++);cout << "Ingreso base " << nodo->cliente.ingresoBase << endl;
    }
    else {
        gotoxy(constante, aumento++);cout << "Cantidad primer deposito " << nodo->cliente.cantidad;
        gotoxy(constante, aumento++);cout << "Sexo " << nodo->cliente.sexo;
        gotoxy(constante, aumento++);cout << "Fecha nacimiento " << nodo->cliente.fechaNacimiento;
    }
    
};

string convertiraMayuscula(string nombre) {
    for (int i = 0; i < nombre.size(); i++) {
        nombre[i] = toupper(nombre[i]);
    }
    return nombre;
}

void pop(nodo*& inicio, int* id, bool esCola) {
    LimpiarPatalla();
    if (inicio != NULL) { // Si la pila o la cola no está vacía
        if (!esCola) {
            (*id)--;
        }
        nodo* aux = inicio; // Creamos nodo auxiliar y le asignamos la pila
        inicio = aux->siguiente; // Movemos el inicio al siguiente nodo
        delete aux; // Eliminamos el nodo auxiliar (el antiguo inicio de la pila)
    }
    else {
        if (esCola) {
            cout << "La cola está vacía." << endl;
        }
        else {
            cout << "La pila está vacía." << endl;
        }
    }

}

void ModificarDato(nodo*& inicio, int* id, bool esCola) {
    LimpiarPatalla();
    int idBuscando;
    int constante, aumento;
    gotoxy(15, 2);cout << "Ingrese el id del Usuario a modificar: ";
    gotoxy(15, 3);cin >> idBuscando;
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
        if (esCola) {
            LimpiarPatalla();
            constante = 20;
            aumento =  2;
            int optionUser;
            string nuevoValorString;
            int nuevoValorInt;

            do {
                gotoxy(15, 1);cout << "Eliga el dato del cliente quiere cambiar";
                imprimirCliente(encontrado, esCola, constante, aumento);
                optionUser = menuModificar(esCola);

                switch (optionUser)
                {
                case 1:
                    cin.ignore();
                    cout << "Ingrese el nuevo nombre: ";
                    getline(cin, nuevoValorString);
                    nuevoValorString = convertiraMayuscula(nuevoValorString);
                    encontrado->cliente.nombre = nuevoValorString;
                    LimpiarPatalla();
                    break;
                case 2: // Apellido
                    cin.ignore();
                    cout << "Ingresa el nuevo apellido: ";
                    getline(cin, nuevoValorString);
                    nuevoValorString = convertiraMayuscula(nuevoValorString);
                    encontrado->cliente.apellido = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 3: // DPI
                    cin.ignore();
                    cout << "Ingresa el nuevo DPI: ";
                    getline(cin, nuevoValorString);
                    encontrado->cliente.DPI = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 4: // Teléfono
                    cin.ignore();
                    cout << "Ingresa el nuevo teléfono: ";
                    getline(cin, nuevoValorString);
                    encontrado->cliente.Telefono = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 5: // Edad
                    cout << "Ingresa la nueva edad: ";
                    cin >> encontrado->cliente.edad;
                    LimpiarPatalla();
                    break;

                case 6: // Número NIS
                    cout << "Ingresa el nuevo número NIS: ";
                    cin >> encontrado->cliente.numeroNis;
                    LimpiarPatalla();
                    break;

                case 7: // Cantidad
                    cout << "Ingresa la cantidad del prestamo: ";
                    cin >> encontrado->cliente.cantidad;
                    LimpiarPatalla();
                    break;

                case 8: // Ingreso Base
                    cout << "Ingresa el nuevo ingreso base: ";
                    cin >> encontrado->cliente.ingresoBase;
                    LimpiarPatalla();
                    break;
                default:
                    break;
                }
            } while (optionUser != 9);
        }
        else {
            gotoxy(15, 5);cout << "Eliga el dato del cliente quiere cambiar";
            constante = 15;
            aumento = 6;
            imprimirCliente(encontrado, esCola, constante, aumento);
            int optionUser;
            string nuevoValorString;
            char nuevoValorChar;
            int nuevoValorInt;


            do {
                optionUser = menuModificar(esCola);

                switch (optionUser) {
                case 1: // Nombre
                    cin.ignore();
                    cout << "Ingresa el nuevo nombre: ";
                    getline(cin, nuevoValorString);
                    nuevoValorString = convertiraMayuscula(nuevoValorString);
                    encontrado->cliente.nombre = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 2: // Apellido
                    cin.ignore();
                    cout << "Ingresa el nuevo apellido: ";
                    getline(cin, nuevoValorString);
                    nuevoValorString = convertiraMayuscula(nuevoValorString);
                    encontrado->cliente.apellido = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 3: // DPI
                    cin.ignore();
                    cout << "Ingresa el nuevo DPI: ";
                    getline(cin, nuevoValorString);
                    encontrado->cliente.DPI = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 4: // Teléfono
                    cin.ignore();
                    cout << "Ingresa el nuevo teléfono: ";
                    getline(cin, nuevoValorString);
                    encontrado->cliente.Telefono = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 5: // Edad
                    cout << "Ingresa la nueva edad: ";
                    cin >> nuevoValorInt;
                    encontrado->cliente.edad = nuevoValorInt;
                    LimpiarPatalla();
                    break;

                case 6: // NIS
                    cout << "Ingresa el nuevo número NIS: ";
                    cin >> nuevoValorInt;
                    encontrado->cliente.numeroNis = nuevoValorInt;
                    LimpiarPatalla();
                    break;

                case 7: // Primer deposito
                    cout << "Ingresa el depósito de apertura: ";
                    cin >> nuevoValorInt;
                    encontrado->cliente.cantidad = nuevoValorInt;
                    LimpiarPatalla();
                    break;

                case 8: //  sexo
                    cout << "Ingresa el nuevo sexo (M/F): ";
                    cin >> nuevoValorChar;
                    encontrado->cliente.sexo = nuevoValorChar;
                    LimpiarPatalla();
                    break;

                case 9: // Fecha nacimiento
                    cin.ignore();
                    cout << "Ingresa la nueva fecha de nacimiento: ";
                    getline(cin, nuevoValorString);
                    encontrado->cliente.fechaNacimiento = nuevoValorString;
                    LimpiarPatalla();
                    break;

                    break;

                default:
                    break;
                }
            } while (optionUser != 10);
        
        }
    }
    _getch();
}


void buscarDato(nodo *&inicio, int* id, bool esCola) {
    LimpiarPatalla();
    if (inicio == NULL) {
        cout << "No hay clientes";
    }
    else {
        int idUser;
        gotoxy(7, 3);cout << "Ingrese el numero de cuenta del usuario o numero de prestamo (id)";
        gotoxy(35, 4);cin >> idUser;
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
            int constante = 25, aumento = 5;
            imprimirCliente(encontrado, esCola, constante, aumento);
        }
    }
    _getch();
}

void pushCola(nodo*& primero, nodo*& ultimo, int* id) { //esto es para el prestamo
    LimpiarPatalla();
    (*id)++;
    string nombre, apellido, DPI, telefono, fechadenacimiento;
    int edad, numeroNis, cantidad, ingresoBase;
    int constante = 20, aumento = 4;
   
    gotoxy(constante, aumento++);cout << "Ingrese el nombre de cliente";
    cin.ignore();
    gotoxy(constante, aumento++);getline(cin, nombre);

    gotoxy(constante, aumento++);cout << "Ingrese el apellido de cliente";
    gotoxy(constante, aumento++);getline(cin, apellido);

    gotoxy(constante, aumento++);cout << "Ingrese DPI de cliente";
    gotoxy(constante, aumento++);cin >> DPI;
    gotoxy(constante, aumento++);cout << "Ingrese telefono del cliente";
    gotoxy(constante, aumento++);cin >> telefono;
    
    nombre = convertiraMayuscula(nombre);
    apellido = convertiraMayuscula(apellido);
    //El apellido
    //IngresoMensual
    //
    gotoxy(constante, aumento++);cout << "Ingrese edad del cliente";
    gotoxy(constante, aumento++);cin >> edad;
    gotoxy(constante, aumento++);cout << "Ingrese nuemro del NIS  de cliente";
    gotoxy(constante, aumento++);cin >> numeroNis;
    gotoxy(constante, aumento++);cout << "Ingrese cantidad del prestamo del cliente";
    gotoxy(constante, aumento++);cin >> cantidad;
    gotoxy(constante, aumento++);cout << "Ingrese ingreso Base del cliente";
    gotoxy(constante, aumento++);cin >> ingresoBase;

    nodo* nuevo_nodo = new nodo();
    nuevo_nodo->cliente.nombre = nombre;
    nuevo_nodo->cliente.edad = edad;
    nuevo_nodo->cliente.apellido = apellido;
    nuevo_nodo->cliente.DPI = DPI;
    nuevo_nodo->cliente.Telefono = telefono;
    nuevo_nodo->cliente.numeroNis = numeroNis;
    nuevo_nodo->cliente.cantidad = cantidad;
    nuevo_nodo->cliente.ingresoBase = ingresoBase;
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
    LimpiarPatalla();
    constante = 20;
    aumento = 4;
    gotoxy(constante, aumento++);cout << "Se agrego los datos del cliente: ";
    gotoxy(constante, aumento++);cout << "Con un ID: " << nuevo_nodo->cliente.id;
    gotoxy(constante, aumento++);cout << "Nombre: " << nuevo_nodo->cliente.nombre;
    gotoxy(constante, aumento++);cout << "Apellido: " << nuevo_nodo->cliente.apellido;
    gotoxy(constante, aumento++);cout << "DPI: " << nuevo_nodo->cliente.DPI;
    gotoxy(constante, aumento++);cout << "Telefono: " << nuevo_nodo->cliente.Telefono;
    gotoxy(constante, aumento++);cout << "Edad: " << nuevo_nodo->cliente.edad;
    gotoxy(constante, aumento++);cout << "Cantidad credito " << nuevo_nodo->cliente.cantidad;
    gotoxy(constante, aumento++);cout << "Ingreso base " << nuevo_nodo->cliente.ingresoBase << endl;
    _getch();


}

void push(nodo*& pila, int* id) { //esto es para la apertura
    LimpiarPatalla();
    (*id)++;
    int constante = 20, aumento = 4;
    string nombre, apellido, DPI, Telefono, fechaNacimiento;
    char Sexo;
    int edad, numeroNis, cantidad;
    gotoxy(constante, aumento++);cout << "Ingrese el nombre de cliente \n";
    cin.ignore();
    gotoxy(constante, aumento++);getline(cin, nombre);
    
    gotoxy(constante, aumento++);cout << "Ingrese el apellido de cliente \n";
    gotoxy(constante, aumento++);getline(cin, apellido);
    
    gotoxy(constante, aumento++);cout << "Ingrese el DPI de cliente \n";
    gotoxy(constante, aumento++);cin >> DPI;
    
    gotoxy(constante, aumento++);cout << "Ingrese el numero de telefono de cliente \n";
    gotoxy(constante, aumento++);cin >> Telefono;
    
    gotoxy(constante, aumento++);cout << "Ingrese edad de cliente \n";
    gotoxy(constante, aumento++);cin >> edad;
    
    gotoxy(constante, aumento++);cout << "Ingrese el sexo del cliente (M/F)  \n";
    gotoxy(constante, aumento++);cin >> Sexo;
    
    gotoxy(constante, aumento++);cout << "Ingrese la fecha de nacimiento de cliente (d/m/a) \n";
    gotoxy(constante, aumento++);cin >> fechaNacimiento;
   
    gotoxy(constante, aumento++);cout << "Ingrese el numero de NIS de cliente \n";
    gotoxy(constante, aumento++);cin >> numeroNis;
   
    gotoxy(constante, aumento++);cout << "Ingresela cantidad depositada de cliente \n";
    gotoxy(constante, aumento++);cin >> cantidad;
    
    
    nombre = convertiraMayuscula(nombre);
    apellido = convertiraMayuscula(apellido);
    nodo* nuevo_nodo = new nodo();
 
    nuevo_nodo->cliente.nombre = nombre;
    nuevo_nodo->cliente.apellido = apellido;
    nuevo_nodo->cliente.DPI = DPI;
    nuevo_nodo->cliente.Telefono = Telefono;
    nuevo_nodo->cliente.edad = edad;
    nuevo_nodo->cliente.sexo = Sexo;
    nuevo_nodo->cliente.fechaNacimiento = fechaNacimiento;
    nuevo_nodo->cliente.numeroNis = numeroNis;
    nuevo_nodo->cliente.cantidad = cantidad;
    nuevo_nodo->cliente.id = *id;
    nuevo_nodo->siguiente = NULL; // Inicializamos el puntero a NULL

    if (pila != NULL) { // Si la pila no está vacía

        nuevo_nodo->siguiente = pila; // El nuevo nodo apunta al inicio de la pila
    }
    pila = nuevo_nodo; // Ahora, el inicio de la pila es el nuevo nodo
    LimpiarPatalla();
    constante = 20;
    aumento = 4;
    gotoxy(constante, aumento++);cout << "Se agrego los datos del cliente: ";
    gotoxy(constante, aumento++);cout << "Con un ID: " << nuevo_nodo->cliente.id;
    gotoxy(constante, aumento++);cout << "Nombre: " << nuevo_nodo->cliente.nombre;
    gotoxy(constante, aumento++);cout << "Apellido: " << nuevo_nodo->cliente.apellido;
    gotoxy(constante, aumento++);cout << "DPI: " << nuevo_nodo->cliente.DPI;
    gotoxy(constante, aumento++);cout << "Telefono: " << nuevo_nodo->cliente.Telefono;
    gotoxy(constante, aumento++);cout << "Edad: " << nuevo_nodo->cliente.edad;
    gotoxy(constante, aumento++);cout << "Sexo: " << nuevo_nodo->cliente.sexo;
    gotoxy(constante, aumento++);cout << "Fecha nacimiento: " << nuevo_nodo->cliente.fechaNacimiento;
    gotoxy(constante, aumento++);cout << "NIS: " << nuevo_nodo->cliente.numeroNis;
    gotoxy(constante, aumento++);cout << "Cantidad: " << nuevo_nodo->cliente.cantidad << endl;
    _getch();

}

void Recorer(nodo*& inicio, int* id, bool esCola) {
    LimpiarPatalla();
    nodo* aux = inicio; // Creamos nodo auxiliar y le asignamos la pila

    while (aux != NULL) { // Mientras no sea el final de la pila
        if (esCola) { //Imprimir los datos del prestamo
            cout << "** " " Numero de prestamo: " << aux->cliente.id<<" " << aux->cliente.nombre << " Apellido:" << aux->cliente.apellido << " DPI: " << aux->cliente.DPI << " Telefono: " << aux->cliente.Telefono << " Edad: " << aux->cliente.edad << " Numero Nis: " << aux->cliente.numeroNis << " Ingreso mensual: " << aux->cliente.ingresoBase << " Cantidad prestamo: " << aux->cliente.cantidad << " siguiente en cola -> ";
            //los datos para la cola
        }
        else { //Imprimir los datos de Apertura
            cout << "** " " Numero de cuenta: " << aux->cliente.id <<" " << aux->cliente.nombre << " Apellido:" << aux->cliente.apellido << " DPI: " << aux->cliente.DPI << " Telefono: " << aux->cliente.Telefono << " Edad: " << aux->cliente.edad << " Sexo: " << aux->cliente.sexo << " Fecha de nacimiento: " << aux->cliente.fechaNacimiento << " Numero de NIS: " << aux->cliente.numeroNis << " Cantidad inicial: " << aux->cliente.cantidad << endl; // Imprimimos el dato
        }
        aux = aux->siguiente; // Avanzamos a la siguiente posición
    }
    system("pause");
}
//P = nombre, apellido, DPI, Telefono, edad, numeroNis, cantidad, ingresos
