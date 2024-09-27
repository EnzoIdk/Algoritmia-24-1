/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: julia
 *
 * Created on 5 de julio de 2024, 20:57
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Lista.h"
#include "funcionesLista.h"

struct Nodo * crearNodoNew(int elemento, struct Nodo * siguiente,struct Nodo *anterior) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    nuevoNodo->anterior = anterior;
    
    return nuevoNodo;
}

void insertarencolaNew(struct Lista & tad, int elemento) {

    struct Nodo * ultimoNodo = tad.cola;
    struct Nodo * nuevoNodo = crearNodoNew(elemento, nullptr,nullptr);

    if (ultimoNodo == nullptr){/*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        tad.cola = nuevoNodo;
    } 
    else{ //La lista ya tiene nodos
        nuevoNodo->anterior = ultimoNodo;
        ultimoNodo->siguiente = nuevoNodo;
        tad.cola = nuevoNodo;
    }
    tad.longitud++;
}

void insertarAlInicioNew(struct Lista & tad, int elemento) {

    /*Se va cambiar por la función crear nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->anterior = nullptr;
    tad.cabeza->anterior = nuevoNodo;
    nuevoNodo->siguiente = tad.cabeza;

    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

void imprimeAlReves(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cola;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento;
            recorrido = recorrido->anterior;
        }
        cout << "]" << endl;
    }
}

int main(int argc, char** argv) {
    Lista listaDoble;
    construir(listaDoble);
    int arr[5]={21,12,45,23,78};
    for(int i=0;i<5;i++){
        insertarAlInicioNew(listaDoble,arr[i]);
    }
    insertarAlInicioNew(listaDoble,15);
    
    imprime(listaDoble);
    cout<<endl;
    imprimeAlReves(listaDoble);
    
    return 0;
}

