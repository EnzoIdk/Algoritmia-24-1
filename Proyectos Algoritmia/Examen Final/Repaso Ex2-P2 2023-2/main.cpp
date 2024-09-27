/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 3 de julio de 2024, 8:43 p.m.
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "Lista.h"
#include "funciones.h"

#define P 6

bool estaPresente(struct Lista &lista, char letra, char * palabra, 
        int cantLetras){
    struct Nodo * aux=lista.cabeza, * ant=nullptr;
    while(aux){
        if(aux->elemento==letra){
            if(ant==nullptr) lista.cabeza=aux->siguiente;
            else ant->siguiente=aux->siguiente;
            aux->siguiente=nullptr;
            delete aux;
            return true;
        }
        ant=aux;
        aux=aux->siguiente;
    }
    return false;
}

bool encuentraPalabra(struct Lista &lista, char palabra[], 
        struct NodoArbol * parbol, int cantLetras){
    bool inic, izq, der;
    if(parbol){
        if(estaPresente(lista, parbol->elemento, palabra, cantLetras)) 
            inic=true;
        else{
            insertarAlFinal(lista, parbol->elemento);
            return false;
        }
        izq=encuentraPalabra(lista, palabra, parbol->izquierda, cantLetras);
        der=encuentraPalabra(lista, palabra, parbol->derecha, cantLetras);
        return inic and (der or izq);
    }
    return true;
}

void insertarPalabra(struct Lista &lista, char * palabra, int nl){
    for(int i=0; i<nl; i++){
        insertarAlFinal(lista, palabra[i]);
    }
}

void buscaPalabras(char palabras[6][10], struct ArbolBinario &arbolLetras, 
        int numPalabras){
    struct Lista lista;
    int nl;
    for(int i=0; i<numPalabras; i++){
        nl=strlen(palabras[i]);
        //INICIALIZAMOS LA LISTA
        construir(lista);
        insertarPalabra(lista, palabras[i], nl);
        //BUSCAMOS
        if(encuentraPalabra(lista, palabras[i], arbolLetras.raiz, nl)){
            cout<<palabras[i]<<' ';
        }
        destruir(lista);
    }
}

int main(int argc, char ** argv) {
    
    struct ArbolBinario arbolLetras;
    construir(arbolLetras);
    char palabrasValidas[6][10]={
        {'H', 'I', 'J', 'O'},
        {'F', 'I', 'N', 'A', 'L'},
        {'M', 'U', 'N', 'D', 'O'},
        {'D', 'E', 'L'},
        {'D', 'I', 'A'},
        {'C', 'I', 'C', 'L', 'O'},
    };
    
    struct NodoArbol * izq=crearNuevoNodoArbol(nullptr, (int)'F', nullptr);
    struct NodoArbol * der=crearNuevoNodoArbol(nullptr, (int)'T', nullptr);
    struct NodoArbol * temp=crearNuevoNodoArbol(izq, (int)'A', der);
    //
    der=crearNuevoNodoArbol(temp, (int)'N', nullptr);
    izq=crearNuevoNodoArbol(nullptr, (int)'O', nullptr);
    temp=crearNuevoNodoArbol(izq, (int)'C', nullptr);
    izq=crearNuevoNodoArbol(temp, (int)'C', nullptr);
    der=crearNuevoNodoArbol(izq, (int)'I', der);
    //
    struct NodoArbol * derF=der;
    //
    izq=crearNuevoNodoArbol(nullptr, (int)'T', nullptr);
    der=crearNuevoNodoArbol(izq, (int)'G', nullptr);
    izq=crearNuevoNodoArbol(nullptr, (int)'R', nullptr);
    temp=crearNuevoNodoArbol(izq, (int)'D', der);
    izq=crearNuevoNodoArbol(nullptr, (int)'E', nullptr);
    temp=crearNuevoNodoArbol(izq, (int)'D', temp);
    //
    arbolLetras.raiz=crearNuevoNodoArbol(temp, (int)'L', derF);
//    recorrerPostOrden(arbolLetras);
    buscaPalabras(palabrasValidas, arbolLetras, P);    
    
    return 0;
}

