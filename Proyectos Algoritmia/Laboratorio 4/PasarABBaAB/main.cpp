/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 31 de mayo de 2024, 08:21 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "ArbolBinarioBusqueda.h"
#include "Pila.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesPila.h"

struct NodoArbol *buscarNodo(struct NodoArbol *nodo,int dato){
    if(esNodoVacio(nodo)) return nullptr;
    else{
        if(nodo->elemento==dato) return nodo;
        else{
            if(nodo->elemento>dato) return buscarNodo(nodo->izquierda,dato);
            else return buscarNodo(nodo->derecha,dato);
        }
    }
}

void enPostOrdenIterativo(struct ArbolBinarioBusqueda arbol){
    struct Pila pila;
    struct NodoArbol *parbol;
    if(esArbolVacio(arbol)) return;
    int ultimo=0,alto;
    construir(pila);
    parbol=arbol.arbolBinario.raiz;
    while(true){
        while(parbol){
            apilar(pila,parbol->elemento);
            parbol=parbol->izquierda;
        }
        alto=cima(pila);
        parbol=buscarNodo(arbol.arbolBinario.raiz,alto);
        if(parbol->derecha!=nullptr and ultimo!=parbol->derecha->elemento){
            parbol=parbol->derecha;
        }
        else{
            ultimo=desapilar(pila);
            imprimeNodo(parbol);
            parbol=nullptr;
        }
        if(esPilaVacia(pila)) break;
    }
    destruirPila(pila);
}

void enPreOrdenIterativo(struct ArbolBinarioBusqueda arbol){
    struct NodoArbol *parbol;
    struct Pila pila;
    if(esArbolVacio(arbol)) return;
    int dato;
    construir(pila);
    parbol=arbol.arbolBinario.raiz;
    apilar(pila,parbol->elemento);
    while(!esPilaVacia(pila)){
        dato=desapilar(pila);
        parbol=buscarNodo(arbol.arbolBinario.raiz,dato);
        imprimeNodo(parbol);
        if(!esNodoVacio(parbol->derecha)) apilar(pila,parbol->derecha->elemento);
        if(!esNodoVacio(parbol->izquierda)) apilar(pila,parbol->izquierda->elemento);
    }
    destruirPila(pila);
}

void insertarRecursivoAB(struct NodoArbol *&nodo,int dato){
    if(esNodoVacio(nodo)) nodo=crearNuevoNodoArbol(nullptr,dato,nullptr);
    else{
        if(esNodoVacio(nodo->izquierda)) insertarRecursivoAB(nodo->izquierda,dato);
        else insertarRecursivoAB(nodo->derecha,dato);
    }
}

void insertarAB(struct ArbolBinario &arbol,int dato){
    insertarRecursivoAB(arbol.raiz,dato);
}

void pasarABBaAB(struct ArbolBinarioBusqueda arbol1,struct ArbolBinario &arbol2){
    struct Pila pila;
    struct NodoArbol *parbol;
    if(esArbolVacio(arbol1)) return;
    int ultimo=0,alto;
    construir(pila);
    parbol=arbol1.arbolBinario.raiz;
    while(true){
        while(parbol){
            apilar(pila,parbol->elemento);
            parbol=parbol->izquierda;
        }
        alto=cima(pila);
        parbol=buscarNodo(arbol1.arbolBinario.raiz,alto);
        if(parbol->derecha!=nullptr and ultimo!=parbol->derecha->elemento){
            parbol=parbol->derecha;
        }
        else{
            ultimo=desapilar(pila);
            insertarAB(arbol2,ultimo);
            parbol=nullptr;
        }
        if(esPilaVacia(pila)) break;
    }
    destruirPila(pila);
}

struct NodoArbol *recorreEInserta(struct NodoArbol *nodo){
    struct NodoArbol *izq,*der,*parbol;
    if(esNodoVacio(nodo)) return nullptr;
    izq=recorreEInserta(nodo->izquierda);
    der=recorreEInserta(nodo->derecha);
    parbol=crearNuevoNodoArbol(izq,nodo->elemento,der);
    return parbol;
}

void pasarABBaABSimple(struct ArbolBinarioBusqueda arbol1,struct ArbolBinario &arbol2){
    if(esArbolVacio(arbol1)) return;
    struct NodoArbol *parbol=recorreEInserta(arbol1.arbolBinario.raiz);
    arbol2.raiz=parbol;
}

void despachar(struct NodoArbol *parbol,int cantidad){
    if(cantidad==0) return;
    struct NodoArbol *aux=minimoArbol(parbol);
    if(aux->elemento/10<=cantidad){ /*se borra y se elimina el nodo*/
        cantidad-=aux->elemento/10;
        parbol=eliminarNodoRecursivo(parbol,aux->elemento);
        despachar(parbol,cantidad);
    }
    else{
        aux->elemento-=cantidad*10;
        cantidad=0;
    }
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol1;
    construir(arbol1);
    insertar(arbol1,30);
    insertar(arbol1,25);
    insertar(arbol1,35);
    insertar(arbol1,23);
    insertar(arbol1,27);
    insertar(arbol1,33);
    insertar(arbol1,37);
    enOrden(arbol1);cout<<endl;
    enPostOrdenIterativo(arbol1);cout<<endl;
    struct ArbolBinario arbol2;
    construir(arbol2);
//    pasarABBaAB(arbol1,arbol2);
//    recorrerPostOrden(arbol2);
    pasarABBaABSimple(arbol1,arbol2);
    recorrerPostOrden(arbol2);cout<<endl;
    struct ArbolBinarioBusqueda almacen;
    construir(almacen);
    insertar(almacen,10*10+1);
    insertar(almacen,3*10+5);
    insertar(almacen,15*10+3);
    insertar(almacen,8*10+6);
    insertar(almacen,14*10+7);
    insertar(almacen,10*10+4);
//    preOrden(almacen);cout<<endl;
    enPreOrdenIterativo(almacen);cout<<endl;
    despachar(almacen.arbolBinario.raiz,12);
    enPreOrdenIterativo(almacen);cout<<endl;
    return 0;
}

