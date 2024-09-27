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
    tad.finVips=nullptr;
    tad.finClientes=nullptr;
    tad.cola = nullptr;
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
void insertarencola(struct Lista & tad, int elemento,char prioridad) {
    struct Nodo * nuevoNodo = crearNodo(elemento,prioridad, nullptr);
    /*primer cambio, acá se colocó lo de lista vacía y se borró lo de último nodo*/
    if (esListaVacia(tad)){/*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        tad.cola = nuevoNodo;
        /*añadir las prioridades*/
        if(prioridad=='V') tad.finVips=nuevoNodo;
        if(prioridad=='C') tad.finClientes=nuevoNodo;
    } 
    else{ //La lista ya tiene nodos
        if(prioridad=='V'){ //llega un vip
            if(tad.finVips==nullptr){ /*aún no habían vips*/
                nuevoNodo->siguiente=tad.cabeza;
                tad.cabeza=nuevoNodo;
                tad.finVips=nuevoNodo;
            }
            else{ /*ya habían vips*/
                if(tad.finVips->siguiente==nullptr) tad.cola=nuevoNodo;
                nuevoNodo->siguiente=tad.finVips->siguiente; //que ambos apunten al mismo nodo
                tad.finVips->siguiente=nuevoNodo; //que el fin existente apunte al nuevo nodo
                tad.finVips=nuevoNodo; //ahora se asigna recién al nuevo nodo como nuevo fin
            }
        }
        else if(prioridad=='C'){ //llega un cliente
            if(tad.finClientes==nullptr){ //aún no habían clientes
                if(tad.finVips==nullptr){ //tampoco vips
                    nuevoNodo->siguiente=tad.cabeza;
                    tad.cabeza=nuevoNodo; //se vuelve la cabeza
                    tad.finClientes=nuevoNodo;
                }
                else{ //no habían clientes pero sí vips
                    nuevoNodo->siguiente=tad.finVips->siguiente;
                    tad.finVips->siguiente=nuevoNodo;
                    tad.finClientes=nuevoNodo;
                }
            }
            else{ //ya habían clientes
                if(tad.finClientes->siguiente==nullptr) tad.cola=nuevoNodo;
                nuevoNodo->siguiente=tad.finClientes->siguiente;
                tad.finClientes->siguiente=nuevoNodo;
                tad.finClientes=nuevoNodo;
            }
        }
        else{ //llega un random, siempre irá a la cola
            nuevoNodo->siguiente=tad.cola->siguiente;
            tad.cola->siguiente=nuevoNodo;
            tad.cola=nuevoNodo;
        }
    }
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(int elemento, char prioridad,struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->prioridad=prioridad;
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

//por último modificamos la impresión
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
            cout << recorrido->prioridad<<'-'<<recorrido->elemento;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}