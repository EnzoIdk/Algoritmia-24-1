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
    /*nuevos parámetros para evaluar el fin por prioridad*/
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
/*MODIFICADO*/
void insertarencola(struct Lista & tad, int fecha,const char *codigo,int prioridad) {
    
    struct Nodo * nuevoNodo = crearNodo(fecha,codigo,prioridad, nullptr);

    if (esListaVacia(tad)){/*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        tad.cola = nuevoNodo;
        if(prioridad==3) tad.fin3=nuevoNodo; 
        if(prioridad==2) tad.fin2=nuevoNodo; 
    } 
    else{ //La lista ya tiene nodos
        if(prioridad==3){ /*si entra uno >80*/
            if(tad.fin3==nullptr){ /*si no habían >80*/
                nuevoNodo->siguiente=tad.cabeza;
                tad.cabeza=nuevoNodo;
                tad.fin3=nuevoNodo;
            }
            else{
                if(tad.fin3->siguiente==nullptr) tad.cola=nuevoNodo; /*si habían solo >80*/
                nuevoNodo->siguiente=tad.fin3->siguiente;
                tad.fin3->siguiente=nuevoNodo;
                tad.fin3=nuevoNodo;
            }
        }
        else if(prioridad==2){ /*si entra uno <10*/
            if(tad.fin2==nullptr){ /*si no habían <10*/
                if(tad.fin3==nullptr){ /*si tampoco habían >80*/
                    nuevoNodo->siguiente=tad.cabeza;
                    tad.cabeza=nuevoNodo;
                    tad.fin2=nuevoNodo;
                }
                else{ /*no habían <10 pero sí >80*/
                    nuevoNodo->siguiente=tad.fin3->siguiente;
                    tad.fin3->siguiente=nuevoNodo;
                    tad.fin2=nuevoNodo;
                }
            }
            else{
                if(tad.fin2->siguiente==nullptr) tad.cola=nuevoNodo; /*si habían solo >10*/
                nuevoNodo->siguiente=tad.fin2->siguiente;
                tad.fin2->siguiente=nuevoNodo;
                tad.fin2=nuevoNodo;
            }
        }
        else{ /*entra uno en el rango [10,80] se va a la cola*/
            nuevoNodo->siguiente=tad.cola->siguiente;
            tad.cola->siguiente=nuevoNodo;
            tad.cola=nuevoNodo;
        }
    }
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
/*MODIFICADO*/
struct Nodo * crearNodo(int fecha,const char *codigo,int prioridad, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = fecha;
    nuevoNodo->codigo= codigo;
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
/*MODIFICADO*/
void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    int dd,mm,aa;
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
            /*recordar que guardamos la fecha en elemento*/
            aa=(recorrido->elemento)/10000;
            mm=((recorrido->elemento)/100)%100;
            dd=(recorrido->elemento)%100;
            cout << dd<<'/'<<mm<<'/'<<aa<<' '<<recorrido->codigo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}