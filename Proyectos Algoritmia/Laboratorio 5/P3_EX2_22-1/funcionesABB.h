// -*- C++ -*-

/* 
 * File:   funcionesABB.h
 * Author: ANA RONCAL
 *
 * Created on 30 de mayo de 2024, 15:54
 */

#ifndef FUNCIONESABB_H
#define FUNCIONESABB_H

#include "NodoGen.h"


void construir(struct ArbolBinarioBusqueda & arbol);
void insertar(struct ArbolBinarioBusqueda & arbol, NodoGen elemento);
void insertarRecursivo(struct NodoArbol *& nodo, NodoGen elemento);
void enOrden(const struct ArbolBinarioBusqueda & arbol);
void plantarArbolBB(struct NodoArbol *& nodo, struct NodoArbol * arbolIzquierdo,
         NodoGen elemento, struct NodoArbol * arbolDerecha);
bool buscaArbol(const struct ArbolBinarioBusqueda & arbol, NodoGen dato);
bool buscaArbolRecursivo(struct NodoArbol * nodo, NodoGen dato);
int comparaABB(int elementoA, int elementoB);
void eliminarNodo(struct ArbolBinarioBusqueda & arbol, int dato);
struct NodoArbol * eliminarNodoRecursivo(struct NodoArbol * nodo, int elemento);
void destruirArbolBB(struct ArbolBinarioBusqueda & arbol);
#endif /* FUNCIONESABB_H */