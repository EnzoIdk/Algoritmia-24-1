/* 
 * File:   funcionesArista.cpp
 * Author: Ana Roncal
 * 
 * Created on 20 de junio de 2024, 13:08
 */

#include <iostream>
#include "Arista.h"
#include "Vertice.h"
using namespace std;
#include "funcionesArista.h"
#include "funcionesVertice.h"

void construirListaAristas(struct Arista & listaArista){
    listaArista.cabeza = nullptr;
    listaArista.longitud = 0;
}

void insertarAristaAlFinal(struct Arista & listaArista, int vertice, double ponderado){
    struct NodoArista * ultimoNodo = obtenerUltimoNodoA(listaArista);
    struct NodoArista * nuevoNodo = crearNodoA(vertice, nullptr, ponderado);
   
    if (ultimoNodo == nullptr)  /*Si la lista está vacia*/
        listaArista.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else    //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    listaArista.longitud++;
}

bool seEncuentraAristaEnListaArista(struct Arista listaArista, int llave){
    struct NodoArista * recorrido = listaArista.cabeza;
    while((recorrido != nullptr) and (recorrido->elemento != llave)){        
        recorrido = recorrido->siguiente;
    }
    return recorrido != nullptr;    
}

struct NodoArista * crearNodoA(int elemento, struct NodoArista * siguiente, double ponderado){
    struct NodoArista * nuevoNodo = new struct NodoArista;

    nuevoNodo->elemento = elemento;
    nuevoNodo->ponderado = ponderado;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía
/*Obtiene el último nodo de la lista*/
struct NodoArista * obtenerUltimoNodoA(struct Arista  listaArista){
    struct NodoArista * ultimo = nullptr;
    struct NodoArista * recorrido = listaArista.cabeza;
    
    while(recorrido != nullptr){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}


void eliminarAristaEnLista(struct Arista & listaArista, int vertice){
    struct NodoArista * ultimo = nullptr;
    struct NodoArista * recorrido = listaArista.cabeza;
    while(recorrido != nullptr and recorrido->elemento != vertice){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    if (recorrido != nullptr){
        if (ultimo == nullptr)
            listaArista.cabeza = recorrido->siguiente;
        else    
            ultimo->siguiente = recorrido->siguiente;        
        delete recorrido;
        listaArista.longitud--;
    }
}

void destruirListaArista(struct Arista & listaArista){    
    struct NodoArista * recorrido = listaArista.cabeza;
    while(recorrido != nullptr){
        struct NodoArista * nodoAEliminar = recorrido;        
        recorrido = recorrido->siguiente;
        delete(nodoAEliminar);
    }
    listaArista.cabeza = nullptr;
    listaArista.longitud = 0;
}