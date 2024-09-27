/* 
 * File:   funcionesLista.cpp
 * Author: ANA RONCAL
 * Created on 8 de octubre de 2023, 05:44 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "NodoPuntaje.h"
#include "Lista.h"
using namespace std;
#include "funcionesLista.h"

/*Valores iniciales de la lista*/
void construir(struct Lista & tad){
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & tad){
    return tad.cabeza == nullptr;
}

/*Crea un nuevo nodo con los datos dados como parÃ¡metros*/
struct NodoPuntaje * crearNodo(const char * equipo, int puntaje, struct NodoPuntaje * siguiente){
    struct NodoPuntaje * nuevoNodo = new struct NodoPuntaje;
    strcpy(nuevoNodo->equipo, equipo);
    nuevoNodo->puntaje = puntaje;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

/*retorna el anterior al que tiene el elemento*/
struct NodoPuntaje * obtenerNodoAnterior(const struct Lista & tad, int puntaje){
    struct NodoPuntaje * anterior = nullptr;
    struct NodoPuntaje * recorrido = tad.cabeza;
    while((recorrido != nullptr) and (recorrido->puntaje > puntaje)){
        anterior = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return anterior;    
}


/*inserta un nodo en orden*/
void insertarEnOrden(struct Lista & tad, const char * equipo, int puntaje){
   
    struct NodoPuntaje * nodoAnterior = obtenerNodoAnterior(tad, puntaje);   
    struct NodoPuntaje * nuevoNodo = crearNodo(equipo, puntaje, nullptr);
    /*Si nodoAnterior es igual a nulo, la lista estÃ¡ vacia, se debe
     insertar al inicio, no hay nodos menores que elemento*/
    if (nodoAnterior == nullptr){ /*la lista estÃ¡ vacia*/
        nuevoNodo->siguiente = tad.cabeza;
        tad.cabeza = nuevoNodo;
    }else{    
        nuevoNodo->siguiente = nodoAnterior->siguiente;
        nodoAnterior->siguiente = nuevoNodo;
    }
    tad.longitud++;     
}

void imprime( struct Lista tad){
    cout<<fixed;   
    cout<<setprecision(2); 
    if (esListaVacia(tad)){
        cout<<"La lista estÃ¡ vacÃ­a"<<endl;
        return;
    }
    else{
        struct NodoPuntaje * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout<<"[";

        while(recorrido != nullptr){
            /*Este artificio coloca la primera coma despuÃ©s de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout<<", ";
            estaImprimiendoLaCabeza = 0;
            cout<<recorrido->equipo<<" "<<recorrido->puntaje;        
            recorrido = recorrido->siguiente;
        }
        cout<<"]"<<endl;
    }
}