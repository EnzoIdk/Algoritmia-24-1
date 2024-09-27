/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 27 de abril de 2024, 08:07 AM
 */

#include <iostream>
#include <iomanip>

#include "funcionesLista.h"
#include "funcionesPila.h"
#include "Lista.h"
#include "Pila.h"

using namespace std;


void pasaPila(struct Pila &A,struct Pila &B){
    if(esPilaVacia(A)) return;
    int valor,valorP;
    valor=desapilar(A);
    valorP=desapilarPeso(A);
    pasaPila(A,B);
    apilar(B,valor,valorP);
}

void hanoi(int n,struct Pila &A,struct Pila &B,struct Pila &C){
    if(n==0) return;
    hanoi(n-1,A,C,B);
    apilar(C,desapilar(A),desapilarPeso(A));
    hanoi(n-1,B,A,C);
}

void robotHanoi(struct Lista &faja,struct Pila &pila,struct Pila &aux1,
        struct Pila &aux2,struct Pila &aux3,int n){
    int mayorP,mayor,auxP,aux,i=1;
    if(n==0) return;
    mayorP=retornaPeso(faja);
    mayor=retornaCabeza(faja);
    auxP=cimaP(pila);
    if(mayorP>auxP and esPilaVacia(pila)){
        hanoi(longitud(pila),pila,aux1,aux2); /*lo pasamos al auxiliar 2*/
        apilar(pila,mayor,mayorP);
        pasaPila(aux2,pila); /*lo devolvemos a la pila*/
    }
    else apilar(pila,mayor,mayorP);
    /*recorriendo la faja*/
    faja.cabeza=faja.cabeza->siguiente;
    robotHanoi(faja,pila,aux1,aux2,aux3,n-1);
} 

int main(int argc, char** argv) {
    struct Lista faja;
    struct Pila pila,aux1,aux2,aux3;
    construir(faja);
    construir(pila);
    construir(aux1);
    construir(aux2);
    construir(aux3);
    insertarAlInicio(faja,1,100);
    insertarAlInicio(faja,2,200);
    insertarAlInicio(faja,2,50);
    insertarAlInicio(faja,1,150);
    insertarAlInicio(faja,1,200);
    insertarAlInicio(faja,2,100);
    insertarAlInicio(faja,1,50);
    imprime(faja);
    robotHanoi(faja,pila,aux1,aux2,aux3,longitud(faja));
    imprimir(pila);
    return 0;
}

