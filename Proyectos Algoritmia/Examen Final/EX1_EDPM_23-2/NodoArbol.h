/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:55 PM
 */

#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "Partido.h"

struct NodoArbol{
    Partido partido;  //Este dato representa el Elemento
    NodoArbol * izquierda;  //puntero al hijo izquierdo
    NodoArbol * derecha;   //puntero al hijo derecho
};

#endif /* NODO_H */

