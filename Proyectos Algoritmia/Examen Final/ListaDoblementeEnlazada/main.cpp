/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 5 de julio de 2024, 8:48 p.m.
 */

#include <iostream>
using namespace std;

/*
 * 
 */

struct Nodo{
    int elemento;
    struct Nodo * siguiente;
    struct Nodo * anterior;
};

struct Lista{
    struct Nodo * cabeza;
    int longitud;
};

void construir(struct Lista &tad){
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

struct Nodo * crearNodo(int elemento, struct Nodo * anterior, 
        struct Nodo * siguiente){
    struct Nodo * nuevoNodo= new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->anterior=anterior;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

void insertarAlInicio(struct Lista &tad, int elemento){
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento=elemento;
    nuevoNodo->anterior=nullptr;
    nuevoNodo->siguiente=tad.cabeza;
    //INSERTAR
    if(tad.cabeza==nullptr) tad.cabeza=nuevoNodo;
    else{
        nuevoNodo->siguiente=tad.cabeza;
        tad.cabeza->anterior=nuevoNodo;
        tad.cabeza=nuevoNodo;
    }
}

struct Nodo * obtenerUltimoNodo(const struct Lista &tad){
    struct Nodo * anterior = nullptr, * recorrido = tad.cabeza;

    while(recorrido){
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    return anterior;
}

void insertarAlFinal(struct Lista &tad, int elemento){
    struct Nodo * ultimoNodo=obtenerUltimoNodo(tad);
    struct Nodo * nuevoNodo=crearNodo(elemento, ultimoNodo, nullptr);
    
    if (ultimoNodo==nullptr) tad.cabeza=nuevoNodo;
    else{
        ultimoNodo->siguiente=nuevoNodo;
    }
    tad.longitud++;
}

void imprimir(struct Lista &lista){
    struct Nodo * recorre=lista.cabeza;
    while(recorre){
        cout<<recorre->elemento<<' ';
        recorre=recorre->siguiente;
    }
    cout<<endl;
}

int main(int argc, char ** argv) {
    struct Lista lista, lista2;
    construir(lista);
    construir(lista2);
    
    insertarAlInicio(lista, 2);
    insertarAlInicio(lista, 3);
    insertarAlFinal(lista, 5);
    insertarAlFinal(lista, 9);
    
    insertarAlFinal(lista2, 4);
    insertarAlFinal(lista2, 6);
    insertarAlInicio(lista2, 7);
    insertarAlInicio(lista2, 1);
    
    imprimir(lista);
    imprimir(lista2);
    
    
    return 0;
}

