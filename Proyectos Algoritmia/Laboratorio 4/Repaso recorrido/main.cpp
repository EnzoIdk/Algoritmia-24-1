/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 30 de mayo de 2024, 08:28 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesArbolesBB.h"        
using namespace std;
#include "Pila.h"
#include "Cola.h"
#include "funcionesPila.h"
#include "funcionesCola.h"


/*si las funciones de pila y cola admitieran nodos, se haría todo igual pero
 sin necesidad de buscarlos al desapilar o desencolar porque ya te los devuelve*/
struct NodoArbol *buscarNodo(struct NodoArbol *nodo,int dato){
    if(nodo==nullptr) return nullptr;
    else{
        if(nodo->elemento==dato) return nodo;
        else{
            if(nodo->elemento>dato) return buscarNodo(nodo->izquierda,dato);
            else return buscarNodo(nodo->derecha,dato);
        }
    }
}

/*Izq Der Raiz*/
void postOrdenIterativa(ArbolBinarioBusqueda arbol){
    struct NodoArbol *parbol;
    int ultimo=0,alto;
    struct Pila stack;
    if(esArbolVacio(arbol)) return;
    construir(stack);
    parbol=arbol.arbolBinario.raiz;
    while(true){
        /*apilamos todo a la izquierda*/
        while(parbol){
            apilar(stack,parbol->elemento);
            parbol=parbol->izquierda;
        }
        /*sacamos el que esté al final*/
        alto=cima(stack);
        parbol=buscarNodo(arbol.arbolBinario.raiz,alto);
        if(parbol->derecha!=nullptr and ultimo!=parbol->derecha->elemento){
            parbol=parbol->derecha;
        }
        else{
            ultimo=desapilar(stack);
//            cout<<ultimo<<" ";
            imprimeNodo(parbol);
            parbol=nullptr;
        }
        if(esPilaVacia(stack)) break;
    }
    destruirPila(stack);
}

/*Izq Raiz Der*/
void enOrdenIterativa(struct ArbolBinarioBusqueda arbol){
    struct NodoArbol *parbol;
    struct Pila stack;
    if(esArbolVacio(arbol)) return;
    construir(stack);
    parbol=arbol.arbolBinario.raiz;
    int dato;
    while(true){
        while(parbol){
            apilar(stack,parbol->elemento);
            parbol=parbol->izquierda;
        }
        if(esPilaVacia(stack)) break;
        dato=desapilar(stack);
        parbol=buscarNodo(arbol.arbolBinario.raiz,dato);
//        cout<<dato<<" ";
        imprimeNodo(parbol);
        parbol=parbol->derecha;
    }
    destruirPila(stack);
}

/*Raiz Izq Der*/
void preOrdenIterativa(struct ArbolBinarioBusqueda arbol){
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

/*por cada nivel del árbol*/
void enAmplitudIterativo(struct ArbolBinarioBusqueda arbol){
    struct NodoArbol *parbol;
    struct Cola cola;
    if(esArbolVacio(arbol)) return;
    int dato;
    construir(cola);
    parbol=arbol.arbolBinario.raiz;
    encolar(cola,parbol->elemento);
    while(!esColaVacia(cola)){
        dato=desencolar(cola);
        parbol=buscarNodo(arbol.arbolBinario.raiz,dato);
        imprimeNodo(parbol);
        if(!esNodoVacio(parbol->izquierda)) encolar(cola,parbol->izquierda->elemento);
        if(!esNodoVacio(parbol->derecha)) encolar(cola,parbol->derecha->elemento);
    }
    destruirCola(cola);
}

void recorrerCola(struct NodoArbol *nodo,struct Cola &cola){
    if(!esNodoVacio(nodo)){
//        imprimeNodo(nodo);
        if(!esNodoVacio(nodo->izquierda)) encolar(cola,nodo->izquierda->elemento);
        if(!esNodoVacio(nodo->derecha)) encolar(cola,nodo->derecha->elemento);
        recorrerCola(nodo->izquierda,cola);
        recorrerCola(nodo->derecha,cola);
    }
}

void enAmplitudRecursivo(struct ArbolBinarioBusqueda arbol){
    struct NodoArbol *parbol;
    struct Cola cola;
    if(esArbolVacio(arbol)) return;
    construir(cola);
    parbol=arbol.arbolBinario.raiz;
    encolar(cola,parbol->elemento);
    recorrerCola(parbol,cola);
    imprime(cola);
}

void recorrerSinCola(struct NodoArbol *nodo,int nivel){
    if(esNodoVacio(nodo)) return;
    if(nivel==0) imprimeNodo(nodo);
    else if(nivel>0){
        recorrerSinCola(nodo->izquierda,nivel-1);
        recorrerSinCola(nodo->derecha,nivel-1);
    }
}

void enAmplitudSinCola(struct ArbolBinarioBusqueda arbol){
    int alto=altura(arbol.arbolBinario);
    cout<<"De la raiz a las hojas"<<endl;
    for(int nivel=0;nivel<=alto;nivel++) recorrerSinCola(arbol.arbolBinario.raiz,nivel);
    cout<<endl<<"De las hojas a la raiz"<<endl;
    for(int nivel=alto;nivel>=0;nivel--) recorrerSinCola(arbol.arbolBinario.raiz,nivel);
}

int main(int argc, char** argv) {
//    struct ArbolBinario arbol,arbol1,arbol2,arbol3,arbol4;
//    construir(arbol);
//    plantarArbolBinario(arbol,nullptr,100,nullptr);
//    plantarArbolBinario(arbol1,nullptr,25,nullptr);
//    plantarArbolBinario(arbol2,nullptr,75,nullptr);
//    plantarArbolBinario(arbol3,arbol1,50,arbol2);
//    plantarArbolBinario(arbol4,nullptr,150,nullptr);
//    plantarArbolBinario(arbol,arbol3,100,arbol4);
//    /*ÁRBOL:
//     *             100
//     *          50     150
//     *       25    75
//     */
//    recorrerEnOrden(arbol);
//cout << endl;
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,100);
    insertar(arbol,50);
    insertar(arbol,150);
    insertar(arbol,125);
    insertar(arbol,175);
    insertar(arbol,200);
    insertar(arbol,25);
    insertar(arbol,75);
//    postOrden(arbol);cout<<endl
//  ÁRBOL:
//               100
//             /    \
//           50     175
//         /  \    /   \
//       25   75  125  175
//                       \
//                      200
//
    recorrerPreOrden(arbol.arbolBinario);cout<<endl;
    recorrerEnOrden(arbol.arbolBinario);cout<<endl;
    recorrerPostOrden(arbol.arbolBinario);cout<<endl;
    cout<<"En PreOrden:  ";preOrdenIterativa(arbol);cout<<endl;
    cout<<"En Orden:     ";enOrdenIterativa(arbol);cout<<endl;
    cout<<"En PostOrden: ";postOrdenIterativa(arbol);cout<<endl;
    cout<<"En Amplitud (iterativo): ";enAmplitudIterativo(arbol);cout<<endl;
    cout<<"En Amplitud (recursivo): ";enAmplitudRecursivo(arbol);
    cout<<"En Amplitud (sin cola):  ";cout<<endl;
    enAmplitudSinCola(arbol);
    return 0;
}

