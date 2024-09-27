// -*- C++ -*-

/* 
 * File:   NodoArista.h
 * Author: ANA RONCAL
 *
 * Created on 20 de junio de 2024, 12:49
 */

#ifndef NODOARISTA_H
#define NODOARISTA_H

struct NodoArista {
    int elemento;    //ElementoListaArista: ACÁ PUEDE CAMBIAR EL ELEMENTO
    double ponderado;
    struct NodoArista * siguiente;
} ;

#endif /* NODOARISTA_H */