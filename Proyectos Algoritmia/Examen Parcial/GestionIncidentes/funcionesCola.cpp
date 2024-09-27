/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * Created on 18 de abril de 2024, 03:57 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
using namespace std;

void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

void encolar(struct Cola & cola, int elemento){
    insertarAlFinal(cola.lista, elemento);
}

int desencolar(struct Cola & cola){
    
    int elemento = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return elemento;
  
}

int longitud(const struct Cola & cola){
    return longitud(cola.lista);
}

void imprimir(const struct Cola & cola){
    imprimir(cola.lista);
}