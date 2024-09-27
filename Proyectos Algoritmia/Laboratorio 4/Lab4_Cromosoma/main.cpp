/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 20 de mayo de 2024, 12:36
 */

#include <cstdlib>
#include <iostream>
#include "NodoArbol.h"
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"

#define N 5

using namespace std;

int cantidadCombinaciones = 0;

struct NodoArbol * crearNuevoNodoArbolNew(struct NodoArbol * arbolIzquierdo, 
                               int elemento, int valor, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->valor = valor;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinarioNew(struct ArbolBinario & arbol, struct NodoArbol * arbolIzquierdo,
                         int elemento, int valor, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNew(arbolIzquierdo, elemento, valor, arbolDerecho);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinarioNew(struct NodoArbol * &raiz, struct NodoArbol * arbolIzquierdo,
                         int elemento, int valor, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNew(arbolIzquierdo, elemento, valor, arbolDerecho);
    raiz = nuevoNodo;
}

void insertaValorArbolRecursivo(struct NodoArbol * &raiz, int elemento, int valor){
    if (raiz==nullptr){
        plantarArbolBinarioNew(raiz,nullptr,elemento,valor,nullptr);
        return;
    }
    insertaValorArbolRecursivo(raiz->izquierda,0,valor);
    insertaValorArbolRecursivo(raiz->derecha,1,valor);
}

void insertaValorArbol(struct ArbolBinario & arbol,int valor){
    insertaValorArbolRecursivo(arbol.raiz, 0, valor);
}

void imprimeAmplitudRecursivo(struct NodoArbol * nodo){
    if (not esNodoVacio(nodo)){
        if (not esNodoVacio(nodo->izquierda))
            imprimeNodo(nodo->izquierda);
        if (not esNodoVacio(nodo->derecha))
            imprimeNodo(nodo->derecha);
        imprimeAmplitudRecursivo(nodo->izquierda);
        imprimeAmplitudRecursivo(nodo->derecha);
    }
}

void recorreAmplitud(const struct ArbolBinario &arbol){
    if (not esArbolVacio(arbol)){
        imprimeNodo(arbol.raiz);
        imprimeAmplitudRecursivo(arbol.raiz);
    }
}

void determinaCantidadRecursivo(struct NodoArbol *raiz,int peso,int pesoParcial){
    pesoParcial = pesoParcial + raiz->elemento*raiz->valor;
    if (raiz->izquierda==nullptr && raiz->derecha==nullptr){    
        if (pesoParcial==peso){
            cantidadCombinaciones++;
        }
        return;
    }
    determinaCantidadRecursivo(raiz->izquierda,peso,pesoParcial);
    determinaCantidadRecursivo(raiz->derecha,peso,pesoParcial);
}

int determinaCantidadRecursivo2(struct NodoArbol *raiz,int peso,int pesoParcial){
    pesoParcial = pesoParcial + raiz->elemento*raiz->valor;
    if (raiz->izquierda==nullptr && raiz->derecha==nullptr){    
        if (pesoParcial==peso){
            return 1;
        }
        return 0;
    }
    return determinaCantidadRecursivo2(raiz->izquierda,peso,pesoParcial) + determinaCantidadRecursivo2(raiz->derecha,peso,pesoParcial);
}

int determinarCantidadCombinaciones2(struct ArbolBinario cromosoma,int peso){
    int pesoParcial = 0;
    return determinaCantidadRecursivo2(cromosoma.raiz,peso,pesoParcial);
}

void determinarCantidadCombinaciones(struct ArbolBinario cromosoma,int peso){
    int pesoParcial = 0;
    determinaCantidadRecursivo(cromosoma.raiz,peso,pesoParcial);
}

/*
 * 
 */


int main(int argc, char** argv) {
    int arreglo[N] = {10,50,20,30,40};
    int cantidad = 5;
    ArbolBinario cromosoma;
    construir(cromosoma);
    plantarArbolBinarioNew(cromosoma,nullptr,0,0,nullptr);
    for (int i=0; i<cantidad; i++){
        insertaValorArbol(cromosoma,arreglo[i]);
    }
    recorrerPreOrden(cromosoma);
//    recorreAmplitud(cromosoma);
    int peso = 70;
    determinarCantidadCombinaciones(cromosoma,peso);
    cout << "Combinaciones: " << cantidadCombinaciones << endl;
    cout << "Combinaciones: " << determinarCantidadCombinaciones2(cromosoma,peso) << endl;
    return 0;
}

