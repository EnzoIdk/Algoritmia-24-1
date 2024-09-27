/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"
#include "funcionesLista.h"

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

void ordenarRec(Pila &pila1,int n){
    int i=n,max,valor;
    if(esPilaVacia(pila1) or n==1) return;
    Pila pila2;
    construir(pila2);
    max=desapilar(pila1);
    i--;
    while(i>0){
        valor=desapilar(pila1);
        if(max<valor){
            apilar(pila2,max);
            max=valor;
        }
        else apilar(pila2,valor);
        i--;
    }
    apilar(pila1,max);
    while(!esPilaVacia(pila2)){
        valor=desapilar(pila2);
        apilar(pila1,valor);
    }
    destruirPila(pila2); /*pq sino con cada recursión se creará una pila y no queremos eso*/
    ordenarRec(pila1,n-1);
}

void pasaPila(Pila &pila1,Pila &pila2){
    int valor,n;
    while(!esPilaVacia(pila1)){
        valor=desapilar(pila1);
        n=0;
        while(!esPilaVacia(pila1)){
            apilar(pila2,valor);
            valor=desapilar(pila1);
            n++;
        }
        while(!esPilaVacia(pila2) and n>0){ /*que n no llegue nunca al valor de 0*/
            apilar(pila1,desapilar(pila2));
            n--;
        }
        apilar(pila2,valor);
    }
}

/*3 pilas: la de origen, la de apoyo (pivote)y la de destino*/
void hanoi(int n,Pila &A,Pila &B,Pila &C){
    if(n==0) return; /*no hay valores*/
    hanoi(n-1,A,C,B);
    apilar(C,desapilar(A));
    hanoi(n-1,B,A,C);
}

int main(int argc, char** argv) {

    struct Pila pila,pila2,pila3;
    construir(pila);
    /*Apilamos elementos en la pila*/
    apilar(pila, 1);
    apilar(pila, 3);
    apilar(pila, 2);
    apilar(pila, 4);
    imprimir(pila);
    ordenarRec(pila,longitud(pila));
    imprimir(pila);
//    construir(pila2);
//    pasaPila(pila,pila2);
//    imprimir(pila2);
    construir(pila2);
    construir(pila3);
    hanoi(longitud(pila),pila,pila2,pila3);
    cout<<"Pila generada por Hanoi: ";
    imprimir(pila3);
//    /*Desapilamos elementos en la pila*/
//    while(not esPilaVacia(pila)){
//        cout<<"Desapilando: "<<desapilar(pila)<<endl;
//    }
//    imprimir(pila);
    return 0;
}

