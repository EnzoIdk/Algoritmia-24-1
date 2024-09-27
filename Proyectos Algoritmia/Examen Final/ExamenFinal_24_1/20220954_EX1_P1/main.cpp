/* 
 * File:   main.cpp
 * Author: Enzo
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"

void pasar(struct Pila &A,struct Pila &B,int n){
    if(n==0) return;
    int dato=desapilar(A);
    pasar(A,B,n-1);
    apilar(A,dato);
    apilar(B,dato);
}

void imprimeAux(struct Pila &pila,int n){
    if(n==0) return;
    imprimeAux(pila,n-1);
    int dato=desapilar(pila);
    cout<<dato<<' ';
}

void copiarPila(struct Pila &original,struct Pila &copia){
    pasar(original,copia,longitud(original));
    imprimeAux(original,longitud(original));cout<<endl;
    imprimeAux(copia,longitud(copia));cout<<endl;
}

int main(int argc, char** argv) {
    struct Pila original,copia;
    construir(original);
    construir(copia);
    apilar(original,4);
    apilar(original,3);
    apilar(original,2);
    apilar(original,1);
    copiarPila(original,copia);
    return 0;
}

