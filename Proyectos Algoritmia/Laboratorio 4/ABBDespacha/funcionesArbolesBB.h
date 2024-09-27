/* 
 * File:   funcionesArbolesBB.h
 * Author: ANA RONCAL
 * Created on 24 de septiembre de 2023, 10:34 PM
 */

#ifndef FUNCIONESARBOLESBB_H
#define FUNCIONESARBOLESBB_H


void recorrerEnOrdenRecursivo(struct Nodo * nodo);
void imprimeNodo(struct Nodo * nodo);

void insertar(struct ArbolBB & arbol, NodoLote elemento);
void insertarRecursivo(struct Nodo *& nodo, NodoLote elemento);
void eliminar(struct ArbolBB arbol, int elemento);
struct Nodo * eliminarRecursivo(struct Nodo * nodo, int elemento);
struct Nodo * minimoNodo(struct Nodo * nodo);

void construir(struct ArbolBinarioBusqueda & arbol);
bool esArbolVacio(const struct ArbolBinarioBusqueda & arbol);

void plantarArbolBB(struct NodoArbol *& arbol, 
                    struct NodoArbol * arbolIzquierdo, NodoLote elemento, 
                    struct NodoArbol * arbolDerecho);

void preOrden(const struct ArbolBinarioBusqueda & arbol);
void enOrden(const struct ArbolBinarioBusqueda & arbol);
void postOrden(const struct ArbolBinarioBusqueda & arbol);
void destruirArbolBB(struct ArbolBinarioBusqueda & arbol);

void insertar(struct ArbolBinarioBusqueda & arbol, NodoLote elemento);

int minimoNodoABB(const struct ArbolBinarioBusqueda &);
int maximoNodoABB(const struct ArbolBinarioBusqueda &);

struct NodoArbol *  minimoArbol(struct NodoArbol * nodo);
bool buscaArbol(const struct ArbolBinarioBusqueda & arbol ,int dato);
void eliminarNodo(struct ArbolBinarioBusqueda & ,int );
int comparaABB(int, int); 

void insertarRecursivo(struct NodoArbol *& raiz, NodoLote elemento);
int minimoNodo(struct NodoArbol * nodo);
int maximoNodo(struct NodoArbol * nodo);
bool buscaArbolRecursivo(struct NodoArbol * nodo, int dato);
struct NodoArbol * eliminarNodoRecursivo(struct NodoArbol * nodo, int elemento);

#endif /* FUNCIONESARBOLESBB_H */

