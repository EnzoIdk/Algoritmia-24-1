/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 26 de abril de 2024, 10:23 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Cola.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesPila.h"

using namespace std;

void hanoiClasico(int n,struct Pila &pila1,struct Pila &pila2,struct Pila &pila3){
    if(n==0) return;
    hanoiClasico(n-1,pila1,pila3,pila2);
    apilar(pila3,desapilar(pila1));
    hanoiClasico(n-1,pila2,pila1,pila3);
}

void hanoiOrdenado(int izq, int der, struct Pila &origen, struct Pila &aux, 
        struct Pila &destino, int elementos){
    for(int i=0; i<=elementos; i++){
        hanoiClasico(i,origen, aux, destino);
        if(i==elementos){
            apilar(origen, izq);
            hanoiClasico(longitud(destino),destino, aux, origen);
            break;
        }
        else{
            der=desapilar(origen);
            if(der>=izq){
                apilar(origen, der);
                apilar(origen, izq);
                hanoiClasico(longitud(destino),destino, aux, origen);
                break;
            }
            apilar(origen, der);
            hanoiClasico(longitud(destino),destino, aux, origen);   
        }
    }
}

void robotHex(struct Cola &faja,struct Pila &pila,struct Pila &aux1,
        struct Pila &aux2,int n){
    if(n==0) return;
    int izq,der=9999;
    izq=desencolar(faja);
    cout<<endl;
    if(esPilaVacia(pila)) apilar(pila,izq);
    else hanoiOrdenado(izq,der,pila,aux1,aux2,longitud(pila));
    robotHex(faja,pila,aux1,aux2,n-1);
}

int main(int argc, char** argv) {
    struct Cola faja;
    struct Pila pila,aux1,aux2;
    construir(faja);
    construir(pila);
    construir(aux1);
    construir(aux2);
    encolar(faja,2);
    encolar(faja,8);
    encolar(faja,10);
    encolar(faja,8);
    encolar(faja,5);
    encolar(faja,3);
    robotHex(faja,pila,aux1,aux2,longitud(faja));
    imprimir(pila);
    return 0;   
}

