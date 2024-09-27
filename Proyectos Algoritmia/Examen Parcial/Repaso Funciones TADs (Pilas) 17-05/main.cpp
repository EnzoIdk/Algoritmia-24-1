/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 17 de mayo de 2024, 18:50
 */

#include <iostream>
using namespace std;
#include <climits>

#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesLista.h"

/*
 * ordenacola invierteLista fusiondelista combinalista 
 * colaprioridad
 */

void ordenarPila(struct Pila &pila, struct Pila &pilaAux, int elementos){
    //CASO FIN
    if(elementos==1) return;
    if(esPilaVacia(pila)) return;
    //
    int aux;
    int mayor=desapilar(pila);
    //ITERACION
    while(not esPilaVacia(pila)){
        aux=desapilar(pila);
        if(aux>mayor){
            apilar(pilaAux, mayor);
            mayor=aux;
        }
        else{
            apilar(pilaAux, aux);
        }
    }
    apilar(pila, mayor);
    //PASAMOS TODO DE NUEVO A LA PILA INICIAL
    while(not esPilaVacia(pilaAux)) apilar(pila, desapilar(pilaAux));
    //RECURSION
    ordenarPila(pila, pilaAux, elementos-1);
}

void pasaPila(struct Pila &origen, struct Pila &aux, struct Pila &destino, 
        int elementos){
    if(elementos==0) return;
    pasaPila(origen, destino, aux, elementos-1);
    apilar(destino, desapilar(origen));
    pasaPila(aux, origen, destino, elementos-1);
}

int main(int argc, char** argv) {
    
    struct Pila pila, pilaAux;
    construir(pila);
    construir(pilaAux);
    
    apilar(pila, 9);
    apilar(pila, 1);
    apilar(pila, 6);
    apilar(pila, 15);
    
    imprimir(pila);
    ordenarPila(pila, pilaAux, pila.lista.longitud);
    imprimir(pila);
    
    struct Pila pila2, pilaAux2, pilaFin;
    construir(pila2);
    construir(pilaAux2);
    construir(pilaFin);
    
    apilar(pila2, 15);
    apilar(pila2, 10);
    apilar(pila2, 8);
    apilar(pila2, 3);
    apilar(pila2, 1);
    
    imprimir(pila2);
    pasaPila(pila2, pilaAux2, pilaFin, pila2.lista.longitud);
    imprimir(pilaFin);
    
    return 0;
}

