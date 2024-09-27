/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 26 de abril de 2024, 09:08 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesLista.h"

using namespace std;

//void hanoi(int n,struct Pila &A,struct Pila &B,struct Pila &D){
//    if(n==0) return;
//    hanoi(n-1,A,D,B);
//    apilar(D,desapilar(A));
//    hanoi(n-1,B,A,D);
//}
//
void hanoi4pilas(int n,struct Pila &A,struct Pila &B,struct Pila &C,struct Pila &D){
    if(n==0) return;
    if(n>=2){
        hanoi4pilas(n-2,A,C,D,B);
        apilar(D,desapilar(A));
        apilar(D,desapilar(A));
        hanoi4pilas(n-2,B,A,C,D);
    }
    else apilar(D,desapilar(A));
}

void unirPilas(struct Pila &pila1,struct Pila &pila2){
    while(!esPilaVacia(pila2)){
        apilar(pila1,desapilar(pila2));
    }
    imprimir(pila1);
//    cout<<longitud(pila1);
}

void ordenaPilaRec(struct Pila &pila1,int n){
    int mayor,aux,i=1;
    if(n==1) return;
    struct Pila pilaAux;
    construir(pilaAux);
    mayor=desapilar(pila1);
    while(i<n){
        aux=desapilar(pila1);
        if(mayor<aux){
            apilar(pilaAux,mayor);
            mayor=aux;
        }
        else apilar(pilaAux,aux);
        i++;
    }
    apilar(pila1,mayor);
    while(!esPilaVacia(pilaAux)) apilar(pila1,desapilar(pilaAux));
    destruirPila(pilaAux);
    ordenaPilaRec(pila1,n-1);
}

void pasaPilaRec(struct Pila &pila1,struct Pila &pila2){
    if(esPilaVacia(pila1)) return;
    int valor=desapilar(pila1);
    pasaPilaRec(pila1,pila2);
    apilar(pila2,valor);
}

int main(int argc, char** argv) {
    struct Pila Kupa1,Kupa2;
    struct Pila A,B,C,D;
    construir(A);
    construir(B);
    construir(C);
    construir(D);
    apilar(A,1);
    apilar(A,2);
    apilar(A,3);
    apilar(A,4);
    apilar(A,5);
    imprimir(A);
    imprimir(D);
    hanoi4pilas(longitud(A),A,B,C,D);
    imprimir(D);
    imprimir(A);
    construir(Kupa1);
    construir(Kupa2);
    apilar(Kupa1,85);
    apilar(Kupa1,15);
    apilar(Kupa1,56);
    apilar(Kupa1,30);
    apilar(Kupa1,27);
    apilar(Kupa2,45);
    apilar(Kupa2,22);
    apilar(Kupa2,68);
    apilar(Kupa2,20);
    unirPilas(Kupa1,Kupa2);
    ordenaPilaRec(Kupa1,longitud(Kupa1));
    imprimir(Kupa1);
    struct Pila champ;
    construir(champ);
    imprimir(champ);
    pasaPilaRec(Kupa1,champ);
    imprimir(champ);
    return 0;
}

