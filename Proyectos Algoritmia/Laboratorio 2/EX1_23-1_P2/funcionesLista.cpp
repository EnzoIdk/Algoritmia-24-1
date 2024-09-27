/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 12:11 PM
 */

#include <iostream>
#include <iomanip> /*formato de números*/
#include <fstream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

/*Valores iniciales de la lista*/
void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.fin2=nullptr;
    tad.fin3=nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista  & tad) {
    return tad.longitud;
}

/*inserta un nodo siempre al final de la cola*/
void insertarencola(struct Lista & tad, int prioridad,const char *codigo) {

    struct Nodo * nuevoNodo = crearNodo(prioridad,codigo, nullptr);

    if (esListaVacia(tad)){/*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        tad.cola = nuevoNodo;
        if(prioridad==2) tad.fin2=nuevoNodo;
        else if(prioridad==3) tad.fin3=nuevoNodo;
    } 
    else{ //La lista ya tiene nodos
        if(prioridad==3){
            if(tad.fin3==nullptr){
                nuevoNodo->siguiente=tad.cabeza;
                tad.cabeza=nuevoNodo;
                tad.fin3=nuevoNodo;
            }
            else{ /*si habían de prioridad 3*/
                if(tad.fin3->siguiente==nullptr) tad.cola=nuevoNodo;
                nuevoNodo->siguiente=tad.fin3->siguiente;
                tad.fin3->siguiente=nuevoNodo;
                tad.fin3=nuevoNodo;
            }
        }
        else if(prioridad==2){
            if(tad.fin2==nullptr){
                if(tad.fin3==nullptr){ /*no habían 3*/
                    nuevoNodo->siguiente=tad.cabeza;
                    tad.cabeza=nuevoNodo;
                    tad.fin2=nuevoNodo;
                }
                else{ //no habían 2 pero sí 3
                    nuevoNodo->siguiente=tad.fin3->siguiente;
                    tad.fin3->siguiente=nuevoNodo;
                    tad.fin2=nuevoNodo;
                }
            }
            else{ //sí habían 2
                if(tad.fin2->siguiente==nullptr) tad.cola=nuevoNodo;
                nuevoNodo->siguiente=tad.fin2->siguiente;
                tad.fin2->siguiente=nuevoNodo;
                tad.fin2=nuevoNodo;
            }
        }
        else{
            nuevoNodo->siguiente=tad.cola->siguiente;
            tad.cola->siguiente=nuevoNodo;
            tad.cola=nuevoNodo;
        }
    }
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(int elemento,const char *codigo, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->codigo=codigo;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}


int retornaCabeza(const struct Lista & tad){
    return tad.cabeza->elemento;
}



void eliminaCabeza(struct Lista & tad) {
    struct Nodo * nodoAEliminar = tad.cabeza;
    if (nodoAEliminar != nullptr) {
        tad.cabeza = tad.cabeza->siguiente;
        delete nodoAEliminar;
        tad.longitud--;
    }
}

/*Elimina el último elemento de la lista, es llamado cola*/
void eliminaCola(struct Lista & tad) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * penultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        if (ultimo != nullptr)
            penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (ultimo != nullptr) {
        //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
        if (penultimo == nullptr)
            tad.cabeza = nullptr;
        else
            penultimo->siguiente = nullptr;
        delete ultimo;
        tad.longitud--;
    }
}

void destruir(struct Lista & tad) {
    /*recorrido apunta al inicio del tad*/
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->codigo<<':'<<recorrido->elemento;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}