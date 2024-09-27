/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RecorridoAmplitud_Recursivo_Cola.cpp
 * Author: TAKASHIMA ICHIKAWA, MARIA EDUARDA
 * Codigo: 20190152
 * Created on 29 de mayo de 2024, 08:49 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "RecorridoAmplitud_Recursivo_Cola.h"

void recorridoAmplitudRecursivoCola(struct ArbolBinario &arbol){
    struct Cola cola;
    construir(cola);
    /* Para recorrer por amplitud usando recursividad y cola
     * es suficiente con encolar solo el elemento de cada nodo
     */
    encolar(cola, arbol.raiz->elemento);
    recorridoAmplitudRecursivoCola(arbol.raiz, cola);
    imprimir(cola);
}

void recorridoAmplitudRecursivoCola(struct NodoArbol *nodo, struct Cola &cola){
    if(not esNodoVacio(nodo)){
        if(not esNodoVacio(nodo->izquierda))
            encolar(cola, nodo->izquierda->elemento);
        if(not esNodoVacio(nodo->derecha))
            encolar(cola, nodo->derecha->elemento);
        recorridoAmplitudRecursivoCola(nodo->izquierda, cola);
        recorridoAmplitudRecursivoCola(nodo->derecha, cola);
    }
}