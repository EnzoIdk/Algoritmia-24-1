/* 
 * File:   funcionesArbolesBB.cpp
 * Author: ANA RONCAL
 * Created on 19 de septiembre de 2023, 10:46 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "ArbolBinario.h"

using namespace std;

#include "funcionesArbolesBinarios.h"

void construir(struct ArbolBinario & arbol) {
    arbol.raiz = nullptr;
}

bool esNodoVacio(struct NodoArbol * nodo) {
    return nodo == nullptr;
}

bool esArbolVacio(const struct ArbolBinario & arbol) {
    return esNodoVacio(arbol.raiz);
}

struct NodoArbol * crearNuevoNodoArbol(struct NodoArbol * arbolIzquierdo,
        int elemento, struct NodoArbol * arbolDerecho) {
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elementoNodoArbol = elemento;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct NodoArbol * arbolIzquierdo,
        int elemento, struct NodoArbol * arbolDerecho) {

    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo, elemento, arbolDerecho);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct ArbolBinario arbolIzquierdo,
        int elemento, struct ArbolBinario arbolDerecho) {

    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo.raiz, elemento, arbolDerecho.raiz);
    arbol.raiz = nuevoNodo;
}

int raiz(struct NodoArbol * nodo) {
    if (esNodoVacio(nodo)) {
        cout << "No se puede obtener ra�z de un �rbol vacio" << endl;
        exit(1);
    }
    return nodo->elementoNodoArbol;
}

struct NodoArbol * hijoDerecho(const struct ArbolBinario & arbol) {
    if (esArbolVacio(arbol)) {
        cout << "No se puede obtener ra�z de un �rbol vacio" << endl;
        exit(1);
    }
    return arbol.raiz->derecha;
}

struct NodoArbol * hijoIzquierdo(const struct ArbolBinario & arbol) {
    if (esArbolVacio(arbol)) {
        cout << "No se puede obtener ra�z de un �rbol vacio" << endl;
        exit(1);
    }

    return arbol.raiz->izquierda;
}

void imprimeRaiz(const struct ArbolBinario & arbol) {
    imprimeNodo(arbol.raiz);
}

void imprimeNodo(struct NodoArbol * nodo) {
    cout << setw(5) << nodo->elementoNodoArbol;
}

void recorrerEnOrdenRecursivo(struct NodoArbol * nodo) {
    //izquierda, padre, derecha
    if (not esNodoVacio(nodo)) {
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimeNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

/*En �rbol, se lleva a cabo visitando el hijo izquierdo del nodo, luego el nodo
 luego todos los restantes, comenzando por la ra�z*/
void recorrerEnOrden(const struct ArbolBinario & arbol) {
    /*Imprime en orden*/
    if (not esArbolVacio(arbol)) {
        recorrerEnOrdenRecursivo(arbol.raiz);
    }
}

void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo) {
    //padre, izquierda, derecha
    if (not esNodoVacio(nodo)) {
        imprimeNodo(nodo);
        recorrerEnPreOrdenRecursivo(nodo->izquierda);
        recorrerEnPreOrdenRecursivo(nodo->derecha);
    }
}

/*recorrido descendente, se lleva a cabo visitando cada nodo, seguido de sus hijos,
 luego todos los restantes, comenzando por la ra�z*/
void recorrerPreOrden(const struct ArbolBinario & arbol) {
    if (not esArbolVacio(arbol)) {
        recorrerEnPreOrdenRecursivo(arbol.raiz);
    }
}

void recorrerEnPostOrdenRecursivo(struct NodoArbol * nodo) {
    //izquierda, derecha, padre
    if (not esNodoVacio(nodo)) {
        recorrerEnPostOrdenRecursivo(nodo->izquierda);
        recorrerEnPostOrdenRecursivo(nodo->derecha);
        imprimeNodo(nodo);
    }
}

/*recorrido ascendente, se lleva a cabo visitando los hijos, y luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerPostOrden(const struct ArbolBinario & arbol) {

    if (not esArbolVacio(arbol)) {
        recorrerEnPostOrdenRecursivo(arbol.raiz);
    }
}

int maximo(int a, int b) {
    return a >= b ? a : b;
}

int alturaRecursivo(struct NodoArbol * nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 0;
    else
        return 1 + maximo(alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int altura(const struct ArbolBinario & arbol) {
    return alturaRecursivo(arbol.raiz); //como el arbol ha sido construido no va apuntar a nullptr
}

int numeroNodosRecursivo(struct NodoArbol * nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda)
        + numeroNodosRecursivo(nodo->derecha);
}

/*Determina el n�mero de elementos del �rbol*/
int numeroNodos(const struct ArbolBinario & arbol) {
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbol * nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}

int numeroHojas(const struct ArbolBinario & arbol) {
    return numeroHojasRecursivo(arbol.raiz);
}

int esEquilibradoRecursivo(struct NodoArbol * nodo) {
    /* 
     * Un árbol se considera equilibrado si todas las 
     * hojas del árbol se encuentran en el mismo nivel o, 
     * como máximo, con un nivel de diferencia unas respecto a otras 
     */
    if (esNodoVacio(nodo))
        return 1;
    else {
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia <= 1 and
                esEquilibradoRecursivo(nodo->izquierda) and
                esEquilibradoRecursivo(nodo->derecha);
    }
}

int esEquilibrado(const struct ArbolBinario & arbol) {
    return esEquilibradoRecursivo(arbol.raiz);
}

int esHoja(const struct ArbolBinario & arbol) {
    if (esArbolVacio(arbol))
        return 0;
    else
        return esNodoVacio(arbol.raiz->izquierda) and esNodoVacio(arbol.raiz->derecha);
}

void destruirArbolBinario(struct ArbolBinario & arbol) {
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoArbol * nodo) {
    if (not (esNodoVacio(nodo))) {
        //Eliminar nodo si es una hoja
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
        nodo = nullptr;
    }
}

