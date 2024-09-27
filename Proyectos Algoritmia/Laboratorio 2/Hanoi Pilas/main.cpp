/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de abril de 2024, 03:33 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "Pila.h"
#include "funcionesPila.h"

void hanoi(int n,struct Pila &A,struct Pila &B,struct Pila &C){
    if(n==0) return;
    hanoi(n-1,A,C,B);
    apilar(C,desapilar(A));
    hanoi(n-1,B,A,C);
}

int main(int argc, char** argv) {
    int n=4;
    struct Pila torreA,torreB,torreC;
    construir(torreA);
    construir(torreB);
    construir(torreC);
    for(int i=n;i>=1;i--) apilar(torreA,i);
    cout <<endl<<" Usando (PILAS): "<<endl;
    cout <<" ESTADO INICIAL DE LAS TORRES: "<<endl;
    cout <<" TORRE ORIGEN: ";
    imprimir(torreA);
    cout <<" TORRE DESTINO: ";
    imprimir(torreB);
    cout <<" TORRE AUXILIAR: ";
    imprimir(torreC);
    hanoi(n,torreA,torreB,torreC);
    cout <<endl<<" ESTADO FINAL DE LAS TORRES: "<<endl;
    cout <<" TORRE ORIGEN: ";
    imprimir(torreA);
    cout <<" TORRE DESTINO: ";
    imprimir(torreB);
    cout <<" TORRE AUXILIAR: ";
    imprimir(torreC);
    
    return 0;
}

