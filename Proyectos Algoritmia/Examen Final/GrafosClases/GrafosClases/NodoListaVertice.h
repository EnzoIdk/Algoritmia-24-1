/* 
 * File:   NodoListavertice.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:22 AM
 */

#ifndef NODOLISTAVERTICE_H
#define NODOLISTAVERTICE_H

#include "ListaArista.h"
struct NodoListaVertice{
    char elemento;    //ACÄ puede cambiar el elemento
    struct NodoListaVertice * siguiente;
    struct ListaArista listaArista;
};

#endif /* NODOLISTAVERTICE_H */

