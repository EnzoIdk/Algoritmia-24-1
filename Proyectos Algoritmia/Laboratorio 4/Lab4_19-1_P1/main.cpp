/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 31 de mayo de 2024, 05:13 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "Cola.h"
using namespace std;
#include "funcionesCola.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

struct NodoArbol *buscarNodo(struct NodoArbol *nodo,int dato){
    if(nodo==nullptr) return nodo;
    else{
        if(nodo->elemento==dato) return nodo;
        else{
            if(nodo->elemento>dato) return buscarNodo(nodo->izquierda,dato);
            else return buscarNodo(nodo->derecha,dato);
        }
    }
}

void enAmplitud(struct ArbolBinarioBusqueda arbol){
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

void insertarEnOrdenRecursivo(struct NodoArbol * nodo,struct ArbolBinarioBusqueda &arbol){
    if(not esNodoVacio(nodo)){
        insertarEnOrdenRecursivo(nodo->izquierda,arbol);
        insertar(arbol,nodo->elemento);
        insertarEnOrdenRecursivo(nodo->derecha,arbol);
    }
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbolBin;
    construir(arbolBin);
    insertar(arbolBin,60);
    insertar(arbolBin,20);
    insertar(arbolBin,80);
    insertar(arbolBin,70);
    insertar(arbolBin,90);
    cout<<"En Orden:    ";enOrden(arbolBin);cout<<endl;
    cout<<"En Amplitud: ";enAmplitud(arbolBin);cout<<endl;
    struct NodoArbol *aux;
//    aux=buscarNodo(arbolBin.arbolBinario.raiz,60);
//    cout<<"El elemento 60 se encuentra en la altura: "<<alturaRecursivo(aux)<<endl;
//    eliminarNodo(arbolBin,80);
//    enOrden(arbolBin);
    struct ArbolBinario arbol1,arbol2,arbol3,arbol4,arbol5;
    construir(arbol1);
//    plantarArbolBinario(arbol1,nullptr,60,nullptr);
    plantarArbolBinario(arbol2,nullptr,20,nullptr);
    plantarArbolBinario(arbol3,nullptr,80,nullptr);
    plantarArbolBinario(arbol4,arbol3,90,arbol2);
    plantarArbolBinario(arbol5,nullptr,70,nullptr);
    plantarArbolBinario(arbol1,arbol4,60,arbol5);
    recorrerEnOrden(arbol1);cout<<endl;
    struct ArbolBinarioBusqueda arbolCopia;
    construir(arbolCopia);
    insertarEnOrdenRecursivo(arbol1.raiz,arbolCopia);
    enOrden(arbolCopia);cout<<endl;
    enAmplitud(arbolCopia);
//    cout<<altura(arbol3);
    return 0;
}

/*cadena y un entero, la otra solo enteros. Recorrer por amplitud,
 pasar de un AB a un ABB: inserta ordenado
 de ABB  a AB, se hacen consideraciones para el llenado
 * que aparezcan en el mismo nivel
 * ABB nivel 2
 * el AB en el nivel 3
 Saca el valor de uno, tipo posorden, solo valores
 Es hijo, cuenta nodos,cuenta nivel*/