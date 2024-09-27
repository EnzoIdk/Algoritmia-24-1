/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RecorridoAmplitud_Iterativo_Cola.cpp
 * Author: TAKASHIMA ICHIKAWA, MARIA EDUARDA
 * Codigo: 20190152
 * Created on 29 de mayo de 2024, 09:10 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "RecorridoAmplitud_Iterativo_Cola.h"

void recorridoAmplitudIterativoCola(struct ArbolBinario &arbol){
    struct NodoArbol *desencolado;
    /* Modificar la cola de tal manera que almacene
     * el NodoArbol en el elemento de cola
     */
    struct Cola cola;
    construir(cola);
    //Se empieza encolando la raiz del arbol
    encolar(cola, arbol.raiz);
    while(not esColaVacia(cola)){
        //Desencolar un NodoArbol
        desencolado = desencolar(cola);
        imprimeNodo(desencolado);
        //Encolar a los hijos del desencolado
        if(not esNodoVacio(desencolado->izquierda))
            encolar(cola, desencolado->izquierda);
        if(not esNodoVacio(desencolado->derecha))
            encolar(cola, desencolado->derecha);
    }
}