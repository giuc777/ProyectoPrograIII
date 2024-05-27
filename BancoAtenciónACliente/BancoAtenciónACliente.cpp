#include <iostream>
#include "Nodos.h"
#include "template.h"
#include "FuncionesListas.h"
#include"FuncionesArboles.h"
#include "AVLFUNCIONES.h"
#include "menus.h"


void setColor(int color);
void dibujarMarco(int x, int y, int ancho, int alto);
void mostrarMenu(const std::string opciones[], int n, int seleccion, int x, int y);
int mostrarMenuInteractivo(const std::string opciones[], int n, int x, int y, int colorFondo);
string obtenerFechaActual();
void operacionesPila(nodo* pila);
void operacionesCola(nodo* cabecera, nodo* ultimo);
void pop(nodo*& inicio, int* id, bool esCola);
void push(nodo*& pila, int* id);
void pushCola(nodo*& primero, nodo*& ultimo, int* id);
void imprimirClienteRecorrer(nodo*& nodo, bool esCola, int constante, int aumento, string encabezado);
int Menu();
int mostrarMenuInteractivoSinBorrar(const std::string opciones[], int n, int x, int y, int colorFondo);
void imprimirEncabezado();
int submenu(bool);
int menuModificar(bool esCola);
void Recorer(nodo*& pila, int* id, bool esCola);
void ModificarDato(nodo*& pila, int* id, bool esCola);
void buscarDato(nodo*& pila, int* id, bool esCola);
void imprimirCliente(nodo*& nodo, bool esCola, int constante, int aumento, string encabezado);
//listas
int menuListas();
void operacionesListaSimple(NodoListaSimple*& cab, NodoListaSimple*& fin);
void insertarSimple(NodoListaSimple*& cab, NodoListaSimple*& fin, int* id);
void eliminarSimple(NodoListaSimple*& cab, NodoListaSimple*& fin, int* id);
void vaciarSimple(NodoListaSimple*& cab, NodoListaSimple*& fin, int* id);
void MostrarLista(NodoListaSimple*& cab, NodoListaSimple*& fin, int* id);
NodoListaSimple* buscarEnListaSimple(NodoListaSimple* inicio, int id);
void ResultadoBusquedaSimple(NodoListaSimple* inicio);
//Circular
int menuListaCircular();
void operacionesListaCircular(NodoListaCircular*& cab, NodoListaCircular*& fin);
void insertarCircular(NodoListaCircular*& cab, NodoListaCircular*& fin, int* id);
void eliminarCircular(NodoListaCircular*& cab, NodoListaCircular*& fin, int* id);
void vaciarCircular(NodoListaCircular*& cab, NodoListaCircular*& fin, int* id);
void MostrarCircular(NodoListaCircular*& cab, NodoListaCircular*& fin, int* id);
NodoListaCircular* buscarEnListaCircular(NodoListaCircular* inicio, int id);
void ResultadoBusquedaCircular(NodoListaCircular* inicio);

//Doblemente

int menuListaDoblemente();
void operacionesListaDoblemente(NodoListaDoblemente*& cab, NodoListaDoblemente*& fin);
void insertarDoblemente(NodoListaDoblemente*& cab, NodoListaDoblemente*& fin, int* id);
void eliminarDoblemente(NodoListaDoblemente*& cab, NodoListaDoblemente*& fin, int* id);
void vaciarDoblemente(NodoListaDoblemente*& cab, NodoListaDoblemente*& fin, int* id);
void MostrarDoblemente(NodoListaDoblemente*& cab, NodoListaDoblemente*& fin, int* id);
NodoListaDoblemente* buscarEnListaDoblemente(NodoListaDoblemente* inicio, int id);
void ResultadoBusquedaDoblemente(NodoListaDoblemente* inicio);


//Arboles
void operacionesABB(NodoABB *&);
int menuABB();
int menuOrden();
NodoABB* crearNodo(int cant, string nombre, string cuenta, string fecha, string DPI, string apellido, NodoABB* );
void insertarABB(NodoABB *&, int cantidad, string nombre, string cuenta, string fecha, string DPI, string apellido, NodoABB* padre);
void AgregarNodoABB(NodoABB*& arbol);
void mostrarABB(NodoABB*arbol, int cont, int vert, bool);
bool busquedaABB(NodoABB*, int cant, NodoABB**);
void resulBusqABB(NodoABB*);
void ordenABB(NodoABB*);
void preOrdenABB(NodoABB*);
void inOrdenABB(NodoABB*);
void postOrdenABB(NodoABB*);
void destruirNodoABB(NodoABB*);
void reemplazarNodoABB(NodoABB*, NodoABB*);
NodoABB* NodominimoABB(NodoABB*);
void eliminarNodoABB(NodoABB*);
void eliminarABB(NodoABB*, int dato);
int menuModificarABB();
NodoABB* ReestructurarABB(NodoABB* arbol, int cantidad, string nombre, string cuenta, string fecha, string dpi, string apellido, NodoABB* padre, int cantidadEliminar);
void modificarABB(NodoABB* arbol);


//Arboles AVL
int menuAVL();
void operacioesAVL(NodoAVL*);
NodoAVL* crearNodoAVL(string nombre, string apellido, string fecha, string dpi, int NoNis, int cantidad);
int obtenerAltura(NodoAVL* nodo);
int obtenerFactorBalance(NodoAVL* nodo);
NodoAVL* rotacionDerecha(NodoAVL* y);
NodoAVL* rotacionIzquierda(NodoAVL* x);
NodoAVL* insertarAVL(NodoAVL* nodo, string nombre, string apellido, string fecha, string dpi, int NoNis, int cantidad);
NodoAVL* obtenerNodoMinimo(NodoAVL* nodo);
NodoAVL* eliminarAVL(NodoAVL* raiz, int dato);
NodoAVL* buscarAVL(NodoAVL* raiz, int dato);
void mostrarAVL(NodoAVL* nodo, int cont, int vert, bool primeraVez);
void obtenerDatosAVL(NodoAVL*& arbol);
void preOrdenAVL(NodoABB*);
void inOrdenAVL(NodoABB*);
void postOrdenAVL(NodoABB*);
void ordenAVL(NodoAVL* arbol);
bool buscarNodoAVL(NodoAVL* arbol, int cant, NodoAVL** aux);
void busquedaAVl(NodoAVL* arbol);
int menuModificarAVL();
NodoAVL* ReestructurarAVL(NodoAVL* nodo, string nombre, string apellido, string fecha, string dpi, int NoNis, int cantidad, int cantidadEliminar);
void modificarAVL(NodoAVL* arbol);

int main()
{
    nodo* pila = NULL, * primero = NULL, * ultimo = NULL;
    NodoListaSimple* cab = NULL, * fin = NULL;
    NodoListaCircular* cabCircular = NULL, * finCircular = NULL;
    NodoListaDoblemente* cabDoblemente = NULL, * finDoblemente = NULL;
    NodoABB* arbol = NULL;
    NodoAVL* raiz = nullptr;

    imprimirEncabezado();

    int opcion, id = 0;
    do {
        opcion = Menu();

        switch (opcion) {
        case 1:

            operacionesPila(pila);
            break;
            // Aquí puedes agregar más casos para más opciones
        case 2:
            operacionesCola(primero, ultimo);
            break;
        case 3:
            operacionesListaSimple(cab, fin);
            break;
        case 4:
            operacionesListaCircular(cabCircular, finCircular);
            break;
        case 5:
            operacionesListaDoblemente(cabDoblemente, finDoblemente);
            break;
        case 6:
            operacionesABB(arbol);
            break;
        case 7:
            operacioesAVL(raiz);
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (opcion != 8);


}

void imprimirEncabezado() {
    // Cambiar temporalmente el color del texto a amarillo sobre un fondo oscuro
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    std::string text[] = {
        " BBBBBB  AAAAAA  NNN   N  k     kk    XX    XX ",
        " B     B A     A N   N N  k    kk     XX    XX ",
        " BBBBBB  AAAAAA  N    NN  kkkkk        XXXXX  ",
        "B     B A     A N    NN   kk   kk     XX    XX ",
        " BBBBBB A     A N    NN   kk     kk   XX    XX "
    };

    int x = 17, y = 7; // Ajustar la posición inicial para centrar el texto si es necesario
    for (const std::string& line : text) {
        gotoxy(x, y++);
        for (char c : line) {
            std::cout << c;
            Sleep(10); // Retraso de 20 milisegundos entre cada carácter
        }
    }

    // Restablecer el color del texto a su valor predeterminado
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);

    std::string text1 = "BIENVENIDO A  BankX";

    int x1 = 30, y2 = 15; // Ajustar la posición inicial para centrar el texto si es necesario
    for (char c : text1) {
        gotoxy(x1++, y2);
        std::cout << c;
        Sleep(50); // Retraso de 50 milisegundos entre cada carácter
    }

    _getch();
}

void operacionesPila(nodo* pila) {
    int operation;
    int id = 0;
    bool cola = false;

    do {
        operation = submenu(cola);

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
void operacionesListaSimple(NodoListaSimple*& cab, NodoListaSimple*& fin) {
    int operation;
    int id = 0;

    do {
        operation = menuListas();

        switch (operation) {
        case 1:

            insertarSimple(cab, fin, &id);
            break;
            // Aquí puedes agregar más casos para más opciones
        case 2:
            MostrarLista(cab, fin, &id);
            break;
        case 3:
            eliminarSimple(cab, fin, &id);
            break;
        case 4:
            ResultadoBusquedaSimple(cab);
            _getch();
            break;
        case 5:
            vaciarSimple(cab, fin, &id);
            break;

        default:
            cout << "Opción no válida." << endl;
        }
    } while (operation != 6);

};

void operacionesListaCircular(NodoListaCircular*& cab, NodoListaCircular*& fin) {
    int operation;
    int id = 0;

    do {
        operation = menuListaCircular();

        switch (operation) {
        case 1:

            insertarCircular(cab, fin, &id);
            break;
            // Aquí puedes agregar más casos para más opciones
        case 2:
            MostrarCircular(cab, fin, &id);
            break;
        case 3:
            eliminarCircular(cab, fin, &id);
            break;
        case 4:
            ResultadoBusquedaCircular(cab);
            _getch();
            break;
        case 5:
            vaciarCircular(cab, fin, &id);
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (operation != 6);

};

void operacionesListaDoblemente(NodoListaDoblemente*& cab, NodoListaDoblemente*& fin) {
    int operation;
    int id = 0;

    do {
        operation = menuListaDoblemente();

        switch (operation) {
        case 1:

            insertarDoblemente(cab, fin, &id);
            break;
            // Aquí puedes agregar más casos para más opciones
        case 2:
            MostrarDoblemente(cab, fin, &id);
            break;
        case 3:
            eliminarDoblemente(cab, fin, &id);
            break;
        case 4:
            ResultadoBusquedaDoblemente(cab);
            _getch();
            break;
        case 5:
            vaciarDoblemente(cab, fin, &id);
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (operation != 6);

};

void operacionesCola(nodo* primero, nodo* ultimo) {
    int operation;
    int id = 0;
    bool cola = true;

    do {
        LimpiarPatalla();
        operation = submenu(cola);

        switch (operation) {
        case 1:

            pushCola(primero, ultimo, &id);
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
            ModificarDato(primero, &id, cola);

            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (operation != 6);
};

void operacionesABB(NodoABB *&Arbol) {
    int operation;
    int cont = 38;
    int vert = 1;
    int eliminar;
    bool primera = true;
    int constante = 20, aumentar = 7;
    do {
        LimpiarPatalla();
        operation = menuABB();

        switch (operation) {
       
        case 1:
            AgregarNodoABB(Arbol);
            break;
        case 2:
            LimpiarPatalla();
            mostrarABB(Arbol, cont, vert, primera);
            _getch();
            break;
        case 3:
            LimpiarPatalla();
            gotoxy(20, 2);cout << "Ingrese dato a eliminar";
            gotoxy(20, 3);cin>>eliminar;
            eliminarABB(Arbol, eliminar);
            gotoxy(20, 5);cout<<"Eliminando...";
            _getch();
            break;
;        case 5:
            ordenABB(Arbol);
            break;
        case 4:
            resulBusqABB(Arbol, constante, aumentar);
            break;
        case 6:
            modificarABB(Arbol);
        default:
            cout << "Opción no válida." << endl;
        }
    } while (operation != 7);
};

void operacioesAVL(NodoAVL*raiz) {;
    int cont = 38;
    int vert = 1;;
    bool primera = true;
    int operation, valorb;
  
    NodoAVL* resultado = nullptr;
 
    do {
        LimpiarPatalla();
        operation = menuAVL();

        switch (operation) {

        case 1:
            LimpiarPatalla();
            obtenerDatosAVL(raiz);
            break;
        case 2:
            LimpiarPatalla();
            mostrarAVL(raiz, cont, vert, primera);
            _getch();
            break;
        case 3:
            LimpiarPatalla();
            cout << "Valor a eliminar: \n";
            cin >> valorb;
            eliminarAVL(raiz, valorb);
            _getch();
            
            break;
        case 4:
            busquedaAVl(raiz);
            break;
        case 5:
            ordenAVL(raiz);
            break;
        case 6:
            modificarAVL(raiz);
            break;
        default:
            break;
        }
    } while (operation != 7);
};

int submenu(bool escola) {
    
    int opcionSubmenu = 1;
    const int OPCIONES = 6;
    int colorFondo;
    if (escola) {
        colorFondo = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;
    }
    else {
        colorFondo = FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_RED;
    }
    int x = 22;
    int y = 5;
    string opciones[OPCIONES] = { "Agregar Cliente", "Mostrar Cliente", "Quitar Cliente", "Buscar Cliente", "Modificar cliente", "Atras"};
    opcionSubmenu = mostrarMenuInteractivo(opciones, OPCIONES, x, y, colorFondo);


    return opcionSubmenu;
}


int Menu() {
    const int OPCIONES = 8;
    int opcionMenuPrincipal = 1;
    int colorFondo = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; // Azul claro


    int x = 22;
    int y = 5;
    string opciones[OPCIONES] = { "Apertura de Cuentas (PILAS)", "Prestamos (COLAS)", "Trasferencias (LISTA SIMPLE)", "Depositos (LISTA CIRCULAR)", "Remesas (LISTA DOBLE ENLAZADA)", "Retiros (ABB)", "Pagos de Luz (AVL)", "SALIR"};
    opcionMenuPrincipal = mostrarMenuInteractivo(opciones, OPCIONES, x, y, colorFondo);

    return opcionMenuPrincipal;
}


int menuModificar(bool esCola) {
    int opcionGeneral = 1;


    if (esCola) {

        system("color 2F");
        const int OPCIONES = 9;
        int colorFondo = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; // Blanco sobre azul
        int x = 45;
        int y = 3;
        string opciones[OPCIONES] = { "Modificar Nombre" , "Modificar Apellido ", "Modificar DPI ", "Modificar Telefono ", "Modificar Edad ", "Modificar Numero NIS", "Modificar Monto de Prestamo", "Modificar Ingreso Base", "Volver" };
        opcionGeneral = mostrarMenuInteractivoSinBorrar(opciones, OPCIONES, x, y, colorFondo);
        

        return opcionGeneral;
    }


    else {
        system("color 2F");
        const int OPCIONES = 10;
        int opcionMenuPrincipal = 1;
        int colorFondo = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; // Blanco sobre azul
        int x = 45;
        int y = 3;
        string opciones[OPCIONES] = { "Modificar Nombre" , "Modificar Apellido ", "Modificar DPI ", "Modificar Telefono", "Modificar Edad ", "Modificar Numero NIS", "Modificar Primer Deposito ", "Modificar Sexo ", "Modificar Fecha Nacimiento: ", "Volver" };
        opcionGeneral = mostrarMenuInteractivoSinBorrar(opciones, OPCIONES, x, y, colorFondo);
       

        return opcionGeneral;
    }

}

void imprimirCliente(nodo*& nodo, bool esCola, int constante, int aumento, string encabezado) {

    gotoxy(constante, aumento++); cout << encabezado;
    gotoxy(constante, aumento++); cout << "Con un ID: " << nodo->cliente.id;
    gotoxy(constante, aumento++); cout << "Nombre: " << nodo->cliente.nombre;
    gotoxy(constante, aumento++); cout << "Apellido: " << nodo->cliente.apellido;
    gotoxy(constante, aumento++); cout << "DPI: " << nodo->cliente.DPI;
    gotoxy(constante, aumento++); cout << "Telefono: " << nodo->cliente.Telefono;
    gotoxy(constante, aumento++); cout << "Edad: " << nodo->cliente.edad;



    if (esCola) {
        gotoxy(constante, aumento++); cout << "Cantidad credito: " << nodo->cliente.cantidad;
        gotoxy(constante, aumento++); cout << "Ingreso base: " << nodo->cliente.ingresoBase << endl;
    }
    else {
        gotoxy(constante, aumento++); cout << "Primer deposito : " << nodo->cliente.cantidad;
        gotoxy(constante, aumento++); cout << "Sexo: " << nodo->cliente.sexo;
        gotoxy(constante, aumento++); cout << "Fecha nacimiento: " << nodo->cliente.fechaNacimiento;
    }

};

void imprimirClienteRecorrer(nodo*& nodo, bool esCola, int constante, int aumento, string encabezado) {

    gotoxy(constante, aumento++); cout << encabezado << nodo->cliente.id;
    gotoxy(constante, aumento++); cout << "Nombre: " << nodo->cliente.nombre;
    gotoxy(constante, aumento++); cout << "Apellido: " << nodo->cliente.apellido;
    gotoxy(constante, aumento++); cout << "DPI: " << nodo->cliente.DPI;
    gotoxy(constante, aumento++); cout << "Telefono: " << nodo->cliente.Telefono;
    gotoxy(constante, aumento++); cout << "Direccion memoria: " << &nodo->cliente;

    if (esCola) {
        gotoxy(constante, aumento++); cout << "Cantidad credito " << nodo->cliente.cantidad;
        gotoxy(constante, aumento++); cout << "Ingreso base " << nodo->cliente.ingresoBase << endl;
    }
    else {
        gotoxy(constante, aumento++); cout << "Cantidad primer deposito " << nodo->cliente.cantidad;
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
    gotoxy(15, 2); cout << "Ingrese el id del Usuario a modificar: ";
    gotoxy(15, 3); cin >> idBuscando;
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
            constante = 5;
            aumento = 4;
            int optionUser;
            string nuevoValorString, encabezado = "Cliente: ";
            int nuevoValorInt;

            do {
                gotoxy(15, 1); cout << "Eliga el dato del cliente quiere cambiar";
                imprimirCliente(encontrado, esCola, constante, aumento, encabezado);
                optionUser = menuModificar(esCola);

                switch (optionUser)
                {
                case 1:
                    cin.ignore();
                    system("color 2F");
                    cout << "Ingrese el nuevo nombre: ";
                    getline(cin, nuevoValorString);
                    nuevoValorString = convertiraMayuscula(nuevoValorString);
                    encontrado->cliente.nombre = nuevoValorString;
                    LimpiarPatalla();
                    break;
                case 2: // Apellido
                    cin.ignore();
                    system("color 2F");
                    cout << "Ingresa el nuevo apellido: ";
                    getline(cin, nuevoValorString);
                    nuevoValorString = convertiraMayuscula(nuevoValorString);
                    encontrado->cliente.apellido = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 3: // DPI
                    cin.ignore();
                    system("color 2F");
                    cout << "Ingresa el nuevo DPI: ";
                    getline(cin, nuevoValorString);
                    encontrado->cliente.DPI = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 4: // Teléfono
                    cin.ignore();
                    system("color 2F");
                    cout << "Ingresa el nuevo teléfono: ";
                    getline(cin, nuevoValorString);
                    encontrado->cliente.Telefono = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 5: // Edad
                    system("color 2F");
                    cout << "Ingresa la nueva edad: ";
                    cin >> encontrado->cliente.edad;
                    LimpiarPatalla();
                    break;

                case 6: // Número NIS
                    system("color 2F");
                    cout << "Ingresa el nuevo número NIS: ";
                    cin >> encontrado->cliente.numeroNis;
                    LimpiarPatalla();
                    break;

                case 7: // Cantidad
                    system("color 2F");
                    cout << "Ingresa la cantidad del prestamo: ";
                    cin >> encontrado->cliente.cantidad;
                    LimpiarPatalla();
                    break;

                case 8: // Ingreso Base
                    system("color 2F");
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

            constante = 5;
            aumento = 4;
            int optionUser;
            string nuevoValorString, encabezado = "Cliente: ";

            char nuevoValorChar;
            int nuevoValorInt;


            do {
                LimpiarPatalla();
                gotoxy(15, 1); cout << "Eliga el dato del cliente quiere cambiar";
                imprimirCliente(encontrado, esCola, constante, aumento, encabezado);
                optionUser = menuModificar(esCola);

                switch (optionUser) {
                case 1: // Nombre
                    system("color 2F");
                    cin.ignore();
                    cout << "Ingresa el nuevo nombre: ";
                    getline(cin, nuevoValorString);
                    nuevoValorString = convertiraMayuscula(nuevoValorString);
                    encontrado->cliente.nombre = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 2: // Apellido
                    system("color 2F");
                    cin.ignore();
                    cout << "Ingresa el nuevo apellido: ";
                    getline(cin, nuevoValorString);
                    nuevoValorString = convertiraMayuscula(nuevoValorString);
                    encontrado->cliente.apellido = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 3: // DPI
                    system("color 2F");
                    cin.ignore();
                    cout << "Ingresa el nuevo DPI: ";
                    getline(cin, nuevoValorString);
                    encontrado->cliente.DPI = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 4: // Teléfono
                    cin.ignore();
                    system("color 2F");
                    cout << "Ingresa el nuevo telefono: ";
                    getline(cin, nuevoValorString);
                    encontrado->cliente.Telefono = nuevoValorString;
                    LimpiarPatalla();
                    break;

                case 5: // Edad
                    system("color 2F");
                    cout << "Ingresa la nueva edad: ";
                    cin >> nuevoValorInt;
                    encontrado->cliente.edad = nuevoValorInt;
                    LimpiarPatalla();
                    break;

                case 6: // NIS
                    system("color 2F");
                    cout << "Ingresa el nuevo numero NIS: ";
                    cin >> nuevoValorInt;
                    encontrado->cliente.numeroNis = nuevoValorInt;
                    LimpiarPatalla();
                    break;

                case 7: // Primer deposito
                    system("color 2F");
                    cout << "Ingresa el deposito de apertura: ";
                    cin >> nuevoValorInt;
                    encontrado->cliente.cantidad = nuevoValorInt;
                    LimpiarPatalla();
                    break;

                case 8: //  sexo
                    system("color 2F");
                    cout << "Ingresa el nuevo sexo (M/F): ";
                    cin >> nuevoValorChar;
                    encontrado->cliente.sexo = nuevoValorChar;
                    LimpiarPatalla();
                    break;

                case 9: // Fecha nacimiento
                    system("color 2F");
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


void buscarDato(nodo*& inicio, int* id, bool esCola) {
    LimpiarPatalla();
    if (inicio == NULL) {
        cout << "No hay clientes";
    }
    else {
        int idUser;
        string encabezado = "Cliente: ";
        gotoxy(7, 3); cout << "Ingrese el numero de cuenta del usuario o numero de prestamo (id)";
        gotoxy(35, 4); cin >> idUser;
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
            imprimirCliente(encontrado, esCola, constante, aumento, encabezado);
        }
    }
    _getch();
}

void pushCola(nodo*& primero, nodo*& ultimo, int* id) { //esto es para el prestamo
    LimpiarPatalla();
    (*id)++;
    string nombre, apellido, DPI, telefono, fechadenacimiento;
    int edad, numeroNis, cantidad, ingresoBase;
    int constante = 20, aumento =3;

    gotoxy(constante, aumento++); cout << "Ingrese DPI de cliente";
    gotoxy(constante, aumento++); cin >> DPI;
    gotoxy(constante, aumento++); cout << "Ingrese el nombre de cliente";
    cin.ignore();
    gotoxy(constante, aumento++); getline(cin, nombre);
    gotoxy(constante, aumento++); cout << "Ingrese el apellido de cliente";
    gotoxy(constante, aumento++); getline(cin, apellido);
    gotoxy(constante, aumento++); cout << "Ingrese telefono del cliente";
    gotoxy(constante, aumento++); cin >> telefono;

    nombre = convertiraMayuscula(nombre);
    apellido = convertiraMayuscula(apellido);
    //El apellido
    //IngresoMensual
    //
    gotoxy(constante, aumento++); cout << "Ingrese edad del cliente";
    gotoxy(constante, aumento++); cin >> edad;
    gotoxy(constante, aumento++); cout << "Ingrese nuemro del NIS  de cliente";
    gotoxy(constante, aumento++); cin >> numeroNis;
    gotoxy(constante, aumento++); cout << "Ingrese cantidad del prestamo del cliente";
    gotoxy(constante, aumento++); cin >> cantidad;
    gotoxy(constante, aumento++); cout << "Ingrese ingreso Base del cliente";
    gotoxy(constante, aumento++); cin >> ingresoBase;

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
    gotoxy(constante, aumento++); cout << "Se agrego los datos del cliente: ";
    gotoxy(constante, aumento++); cout << "Con un ID: " << nuevo_nodo->cliente.id;
    gotoxy(constante, aumento++); cout << "Nombre: " << nuevo_nodo->cliente.nombre;
    gotoxy(constante, aumento++); cout << "Apellido: " << nuevo_nodo->cliente.apellido;
    gotoxy(constante, aumento++); cout << "DPI: " << nuevo_nodo->cliente.DPI;
    gotoxy(constante, aumento++); cout << "Telefono: " << nuevo_nodo->cliente.Telefono;
    gotoxy(constante, aumento++); cout << "Edad: " << nuevo_nodo->cliente.edad;
    gotoxy(constante, aumento++); cout << "Cantidad credito " << nuevo_nodo->cliente.cantidad;
    gotoxy(constante, aumento++); cout << "Ingreso base " << nuevo_nodo->cliente.ingresoBase << endl;
    _getch();


}

void push(nodo*& pila, int* id) { //esto es para la apertura
    LimpiarPatalla();
    (*id)++;
    int constante = 20, aumento = 4;
    string nombre, apellido, DPI, Telefono, fechaNacimiento;
    char Sexo;
    int edad, numeroNis, cantidad;

    gotoxy(constante, aumento++); cout << "Ingrese el DPI de cliente: \n";
    gotoxy(constante, aumento); cin >> DPI;

    gotoxy(constante, aumento++); cout << "Ingrese el nombre de cliente \n";
    cin.ignore();
    gotoxy(constante, aumento++); getline(cin, nombre);

    gotoxy(constante, aumento++); cout << "Ingrese el apellido de cliente \n";
    gotoxy(constante, aumento++); getline(cin, apellido);

    

    gotoxy(constante, aumento++); cout << "Ingrese el numero de telefono de cliente \n";
    gotoxy(constante, aumento++); cin >> Telefono;

    gotoxy(constante, aumento++); cout << "Ingrese edad de cliente \n";
    gotoxy(constante, aumento++); cin >> edad;

    gotoxy(constante, aumento++); cout << "Ingrese el sexo del cliente (M/F)  \n";
    gotoxy(constante, aumento++); cin >> Sexo;

    gotoxy(constante, aumento++); cout << "Ingrese la fecha de nacimiento de cliente (d/m/a) \n";
    gotoxy(constante, aumento++); cin >> fechaNacimiento;

    gotoxy(constante, aumento++); cout << "Ingrese el numero de NIS de cliente \n";
    gotoxy(constante, aumento++); cin >> numeroNis;

    gotoxy(constante, aumento++); cout << "Ingresela cantidad depositada de cliente \n";
    gotoxy(constante, aumento++); cin >> cantidad;


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
    gotoxy(constante, aumento++); cout << "Se agrego los datos del cliente: ";
    gotoxy(constante, aumento++); cout << "Con un ID: " << nuevo_nodo->cliente.id;
    gotoxy(constante, aumento++); cout << "Nombre: " << nuevo_nodo->cliente.nombre;
    gotoxy(constante, aumento++); cout << "Apellido: " << nuevo_nodo->cliente.apellido;
    gotoxy(constante, aumento++); cout << "DPI: " << nuevo_nodo->cliente.DPI;
    gotoxy(constante, aumento++); cout << "Telefono: " << nuevo_nodo->cliente.Telefono;
    gotoxy(constante, aumento++); cout << "Edad: " << nuevo_nodo->cliente.edad;
    gotoxy(constante, aumento++); cout << "Sexo: " << nuevo_nodo->cliente.sexo;
    gotoxy(constante, aumento++); cout << "Fecha nacimiento: " << nuevo_nodo->cliente.fechaNacimiento;
    gotoxy(constante, aumento++); cout << "NIS: " << nuevo_nodo->cliente.numeroNis;
    gotoxy(constante, aumento++); cout << "Cantidad: " << nuevo_nodo->cliente.cantidad << endl;
    _getch();

}

void Recorer(nodo*& inicio, int* id, bool esCola) {
    LimpiarPatalla();
    nodo* aux = inicio; // Creamos nodo auxiliar y le asignamos la pila
    int constante = 25, aumento = 2, espacioCola = 36, contador = 0, espacioverticalCola = 5;
    string encabezado = "Cliente no. ";

    if (esCola) {
        constante = 1;
    }

    while (aux != NULL) { // Mientras no sea el final de la pila
        if (esCola) { //Imprimir los datos del prestamo

            encabezado = encabezado;
            imprimirClienteRecorrer(aux, esCola, constante, aumento, encabezado);
            contador++;
            espacioCola = espacioCola + 2;
            if (contador != 2) {
                gotoxy(espacioCola, espacioverticalCola); cout << "-> ";
                constante = espacioCola + 6;
            }
            else {
                aumento = aumento + 10;
                constante = 1;
                espacioverticalCola = espacioverticalCola + 10;
                espacioCola = 36;
                contador = 0;
            }

            //los datos para la cola
        }
        else { //Imprimir los datos de Apertura
            encabezado = encabezado;
            imprimirClienteRecorrer(aux, esCola, constante, aumento, encabezado);
            aumento = aumento + 9;
        }
        aux = aux->siguiente; // Avanzamos a la siguiente posición
    }
    if (esCola) {
        gotoxy(constante, aumento);
    }
    cout << endl;

    _getch();
}
//P = nombre, apellido, DPI, Telefono, edad, numeroNis, cantidad, ingresos
