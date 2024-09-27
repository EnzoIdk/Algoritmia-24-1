/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de abril de 2024, 01:00 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesLista.h"

void pasaPila(struct Pila &pila,struct Pila &pila2){
    int valor,n,aux;
    while(!esPilaVacia(pila)){
        valor=desapilar(pila);
        n=0;
        while(!esPilaVacia(pila)){
            apilar(pila2,valor);
            n++;
            valor=desapilar(pila);
        }
        cout<<endl;
        while(n>0){
            aux=desapilar(pila2);
            apilar(pila,aux);
            n--;
        }
        cout<<endl;
        apilar(pila2,valor);
        cout<<endl;
    }
}

void pasaPilaRecursivo(struct Pila &pila1,struct Pila &pila2){
    if(esPilaVacia(pila1)) return;
    int valor=desapilar(pila1);
    pasaPilaRecursivo(pila1,pila2);
    apilar(pila2,valor);
}

void ordenaRec(struct Pila &pila,int n){
    int i=1,max,valor;
    if(esPilaVacia(pila) or n==1) return;
    struct Pila pilaAux;
    construir(pilaAux);
    max=desapilar(pila);
    while(i<n){
        valor=desapilar(pila);
        if(max<valor){
            apilar(pilaAux,max);
            max=valor;
        }
        else apilar(pilaAux,valor);
        i++;
    }
    apilar(pila,max);
    while(!esPilaVacia(pilaAux)){
        apilar(pila,desapilar(pilaAux));
    }
    destruirPila(pilaAux);
    ordenaRec(pila,n-1);
}

int main(int argc, char** argv) {
    struct Pila pila;
    struct Pila pila2;
    construir(pila);
    construir(pila2);
    apilar(pila,1);
    apilar(pila,2);
    apilar(pila,3);
    apilar(pila,4);
    cout<<"Pila"<<endl;
    imprimir(pila);
    cout<<"Pila2"<<endl;
    imprimir(pila2);
//    pasaPila(pila,pila2);
//    cout<<"Pasa pila iterativo"<<endl;
//    cout<<"Pila"<<endl;
//    imprimir(pila);
//    cout<<"Pila 2"<<endl;
//    imprimir(pila2);
    pasaPilaRecursivo(pila,pila2);
    cout<<"Pasa pila recursivo"<<endl;
    cout<<"Pila"<<endl;
    imprimir(pila);
    cout<<"Pila 2"<<endl;
    imprimir(pila2);
    ordenaRec(pila2,longitud(pila2));
    cout<<"Pila 2 ordenada"<<endl;
    imprimir(pila2);
    return 0;
}

