#pragma once
#include "template.h"
#ifndef NODOS_H
#define NODOS_H


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


struct ClientesTrasnferencias {
    int idTrans, cantidad;
    string cuenta1, cuenta2, fecha, DPI;
};
struct ClientesRetiro {
    int cantidad;
    string nombre,apellido, cuenta, fecha, DPI;
};

struct ClientesRemesas {
    int idRemesa, cantidad;
    string DPI, nombre, apellido, paisOrigen, fecha;
};

struct ClientesDepositos {
    int cant, idDeposito;
    string nombre, apellido, fecha, dpi;
};

struct nodo {
    Clientes cliente;
    nodo* siguiente;
};

struct NodoListaSimple {
    ClientesTrasnferencias Cliente;
    NodoListaSimple* sig;
};

struct NodoListaCircular {
    ClientesRemesas Cliente;
    NodoListaCircular* sig;
};

struct NodoListaDoblemente {
    ClientesDepositos Cliente;
    NodoListaDoblemente* sig;
    NodoListaDoblemente* ant;
};

struct NodoABB {
    ClientesRetiro Cliente;
    NodoABB* i;
    NodoABB* d;
    NodoABB* padre;
};

#endif