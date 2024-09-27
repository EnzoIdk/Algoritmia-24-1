/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de abril de 2024, 03:59 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>    
#include "Cola.h"
#include "Pila.h"

using namespace std;

#include "funcionesCola.h"
#include "funcionesPila.h"

void ordenaColaRec(struct Cola &cola,int n){
    int mayor,aux,i=1;
    /*si la cola está vacía no se hace nada*/
    if(n==1) return;
    /*haremos que el menor encabece la cola*/
    mayor=desencolar(cola);
    while(i<n){
        aux=desencolar(cola);
        if(mayor<aux){
            encolar(cola,mayor);
            mayor=aux;
        }
        else encolar(cola,aux);
        i++;
    }
    ordenaColaRec(cola,n-1);
    encolar(cola,mayor);
}

void distribucion(struct Cola &cola, int n){
    int i,valor;
    int longitud_lote=n/3;
    struct Pila pila_aux;
    construir(pila_aux);
    cout<<"Desencolamos y encolamos A y B"<<endl;
    for (i=0; i<longitud_lote*2;i++){
        encolar(cola, desencolar(cola));
    }
    imprime(cola);
    cout<<"Desencolamos C y los perdemos"<<endl;
    for (i=0; i<longitud_lote;i++){
        valor=desencolar(cola);
    }
    imprime(cola);
    
    cout<<"Desencolar A y apilarlos"<<endl;
    for (i=0; i<longitud_lote;i++){
        apilar(pila_aux,desencolar(cola));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
    cout<<"Desapilamos A y encolamos"<<endl;
    for (i=0; i<longitud_lote;i++){
        encolar(cola,desapilar(pila_aux));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
    cout<<"Desencolamos B y apilamos"<<endl;
    for (i=0; i<longitud_lote;i++){
        apilar(pila_aux,desencolar(cola));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
    
    cout<<"Desapilamos 1 de B y lo encolamos Y desencolamos 1 de A y encolamos"<<endl;
    for (i=0; i<longitud_lote;i++){
        encolar(cola,desapilar(pila_aux));
        encolar(cola,desencolar(cola));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
    cout<<"Desencolamos A y B y apilamos"<<endl;
    for (i=0; i<longitud_lote*2;i++){
        apilar(pila_aux,desencolar(cola));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
    cout<<"Desapilamos A y B y encolamos"<<endl;
    for (i=0; i<longitud_lote*2;i++){
        encolar(cola,desapilar(pila_aux));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
}

int main(int argc, char** argv) {
    struct Cola cola;
    struct Pila pila;
    construir(cola);
    construir(pila);
    apilar(pila,1);
    apilar(pila,2);
    apilar(pila,3);
    cout<<"PILA: ";
    imprimir(pila);
    encolar(cola,8);
    encolar(cola,21);
    encolar(cola,10);
    imprime(cola);
    desencolar(cola);
    imprime(cola);
    encolar(cola,15);
    encolar(cola,7);
    imprime(cola);
    ordenaColaRec(cola,longitud(cola));
    imprime(cola);
    
//    struct Cola cola;
//    construir(cola);
//    cout<<"La cola esta vacia: "<<esColaVacia(cola)<<endl;
//    encolar(cola, 11);//A1
//    encolar(cola, 12);//A2
//    encolar(cola, 13);//A3
//    encolar(cola, 14);//A4
//    encolar(cola, 21);//B1
//    encolar(cola, 22);//B2
//    encolar(cola, 23);//B3
//    encolar(cola, 24);//B4
//    encolar(cola, 31);//C1
//    encolar(cola, 32);//C2
//    encolar(cola, 33);//C3
//    encolar(cola, 34);//C4
//    
//    cout<<"Cola Original:"<<endl;
//    imprime(cola);
//    
//    distribucion(cola, 12);
//    cout<<"Nueva Cola:"<<endl;
//    imprime(cola);
    
//    int dato;
//    construir(cola);
//    ifstream arch("Datos.txt",ios::in);
//    while(true){
//        arch>>dato;
//        if(arch.eof()) break;
//        encolar(cola,dato);
//    }
//    imprime(cola);
    return 0;
}

