/* 
 * File:   funcionesListavertice.cpp
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:39 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "ListaVertice.h"

using namespace std;
#include "funcionesListaArista.h"
#include "funcionesListaVertice.h"

void construirListaVertice(struct ListaVertice & listaVertice){
    listaVertice.cabeza = nullptr;
    listaVertice.longitud = 0;
}

bool esListaVerticeVacio(struct ListaVertice listaVertice){
    return listaVertice.cabeza == nullptr;
}

bool seEncuentraVerticeLista(struct ListaVertice listaVertice, char llave){
    struct NodoListaVertice * recorrido = listaVertice.cabeza;
    while(recorrido != nullptr and recorrido->elemento != llave){        
        recorrido = recorrido->siguiente;
    }
    return recorrido != nullptr; 
}

struct NodoListaVertice * crearNodoV(char elemento, struct NodoListaVertice * siguiente){
    struct NodoListaVertice * nuevoNodo = new struct NodoListaVertice;
    
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    construirListaAristas(nuevoNodo->listaArista);
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía
/*Obtiene el último nodo de la lista*/
struct NodoListaVertice * obtenerUltimoNodoV( struct ListaVertice  listaVertice){
    struct NodoListaVertice * ultimo = nullptr;
    struct NodoListaVertice * recorrido = listaVertice.cabeza;
    
    while(recorrido != nullptr){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

void insertarVerticeAlFinal(struct ListaVertice & listaVertice, char elemento){
    struct NodoListaVertice * ultimoNodo = obtenerUltimoNodoV(listaVertice);
    struct NodoListaVertice * nuevoNodo = crearNodoV(elemento, nullptr);
   
    if (ultimoNodo == nullptr)  /*Si la lista está vacia*/
        listaVertice.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else    //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    listaVertice.longitud++;
}

struct NodoListaVertice * obtenerNodoVertice(struct ListaVertice listaVertice, char clave){
    struct NodoListaVertice * recorrido = listaVertice.cabeza;
    while((recorrido != nullptr) and (recorrido->elemento != clave)){        
        recorrido = recorrido->siguiente;
    }
    return recorrido;        
}

bool seEncuentraAristaLista(struct ListaVertice listaVertice, char verticeOrigen, char verticeDestino){
    struct NodoListaVertice * nodoVerticeOrigen = obtenerNodoVertice(listaVertice, verticeOrigen);
    if (nodoVerticeOrigen == nullptr)
	return false;
    return seEncuentraAristaEnListaArista(nodoVerticeOrigen->listaArista, verticeDestino);
}

void insertarListaAristas(struct ListaVertice & listaVertice, char verticeOrigen, char verticeDestino){
    struct NodoListaVertice * nodoVerticeOrigen = obtenerNodoVertice(listaVertice, verticeOrigen);
    if (nodoVerticeOrigen == nullptr){
        cout<<"Error al insertar la lista de arista. No se ha encontrado el vértice"<<verticeOrigen<<endl;
        return;
    }

    if ( not seEncuentraAristaEnListaArista(nodoVerticeOrigen->listaArista, verticeDestino)){
        insertarAristaAlFinal(nodoVerticeOrigen->listaArista, verticeDestino);
    }
}

void eliminarDeListaDeAristas(struct ListaVertice & listaVertice, char verticeOrigen, char verticeDestino){
    struct NodoListaVertice * nodoVerticeOrigen = obtenerNodoVertice(listaVertice, verticeOrigen);
    if (nodoVerticeOrigen != nullptr)
        eliminarAristaEnLista(nodoVerticeOrigen->listaArista, verticeDestino);

}

void eliminarVerticeEnLista(struct ListaVertice & listaVertice, char vertice){
    struct NodoListaVertice * ultimoNodo = nullptr;
    struct NodoListaVertice * recorrido = listaVertice.cabeza;

    while(recorrido != nullptr and recorrido->elemento != vertice){
        ultimoNodo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    if (recorrido != nullptr){
        if (ultimoNodo == nullptr)
            listaVertice.cabeza=recorrido->siguiente;
        else    
            ultimoNodo->siguiente = recorrido->siguiente;
        destruirListaArista(recorrido->listaArista);
        free(recorrido);
        listaVertice.longitud--;
    }
}

void destruirListaVertice(struct ListaVertice & listaVertice){    
    struct NodoListaVertice * recorrido = listaVertice.cabeza;
    while(recorrido != nullptr){
    	destruirListaArista(recorrido->listaArista);
        struct NodoListaVertice * nodoAEliminar = recorrido;        
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    listaVertice.cabeza = nullptr;
    listaVertice.longitud = 0;
}