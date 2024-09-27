/* 
 * File:   funcionesListaArista.cpp
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 11:02 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaArista.h"

using namespace std;
#include "funcionesListaArista.h"

void construirListaAristas(struct ListaArista & listaArista){
    listaArista.cabeza = nullptr;
    listaArista.longitud = 0;
}

bool seEncuentraAristaEnListaArista(struct ListaArista listaArista, char llave){
    struct NodoListaArista * recorrido = listaArista.cabeza;
    while((recorrido != nullptr) and (recorrido->elemento != llave)){        
        recorrido = recorrido->siguiente;
    }
    return recorrido != nullptr;    
}

struct NodoListaArista * crearNodoA(char elemento, struct NodoListaArista * siguiente){
    struct NodoListaArista * nuevoNodo = new struct NodoListaArista;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía
/*Obtiene el último nodo de la lista*/
struct NodoListaArista * obtenerUltimoNodoA(struct ListaArista  listaArista){
    struct NodoListaArista * ultimo = nullptr;
    struct NodoListaArista * recorrido = listaArista.cabeza;
    
    while(recorrido != nullptr){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

void insertarAristaAlFinal(struct ListaArista & listaArista, char vertice){
    struct NodoListaArista * ultimoNodo = obtenerUltimoNodoA(listaArista);
    struct NodoListaArista * nuevoNodo = crearNodoA(vertice, nullptr);
   
    if (ultimoNodo == nullptr)  /*Si la lista está vacia*/
        listaArista.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else    //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    listaArista.longitud++;
}


void eliminarAristaEnLista(struct ListaArista & listaArista, char vertice){
    struct NodoListaArista * ultimo = nullptr;
    struct NodoListaArista * recorrido = listaArista.cabeza;
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

void destruirListaArista(struct ListaArista & listaArista){    
    struct NodoListaArista * recorrido = listaArista.cabeza;
    while(recorrido != nullptr){
        struct NodoListaArista * nodoAEliminar = recorrido;        
        recorrido = recorrido->siguiente;
        delete(nodoAEliminar);
    }
    listaArista.cabeza = nullptr;
    listaArista.longitud = 0;
}