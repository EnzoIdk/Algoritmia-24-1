/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 9 de junio de 2024, 11:06 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "funcionesLista.h"
#include "funcionesPila.h"
using namespace std;
#include "Pila.h"

/*ayuda a no romper la condición de fragilidad*/
void hanoi(struct Pila &A,struct Pila &B,struct Pila &C,int n){
    if(n==0) return;
    hanoi(A,C,B,n-1);
    apilar(C,desapilar(A));
    hanoi(B,A,C,n-1);
}

void robotApilador(struct Lista &faja,struct Pila &pila){
    struct Pila aux1,aux2,aux3;
    struct Nodo *rec=faja.cabeza,*ant;
    int valor;
    construir(aux1);
    construir(aux2);
    construir(aux3);
    while(rec){
        //recorre la lista hasta el ultimo elemento
        while(rec->siguiente){
            ant=rec;
            rec=rec->siguiente;
        }
        ant->siguiente=nullptr;
        valor=rec->elemento;
        faja.longitud--;
        if(faja.cabeza->elemento==rec->elemento) faja.cabeza=nullptr;
        delete rec;
//        cout<<valor%10<<'-'<<valor/10<<' ';
        while(true){
            if(esPilaVacia(pila) or valor<=cima(pila)){
                apilar(pila,valor);
                /*se pasa todo lo guardado en aux1 a pila*/
                if(!esPilaVacia(aux1)) hanoi(aux1,aux2,pila,longitud(aux1));
//                imprimir(pila);
                break;
            }
            else{
                int aux=desapilar(pila);
//                cout<<"mayor que "<<aux%10<<'-'<<aux/10<<" ";
                /*se pasa del aux1 al aux3*/
                if(!esPilaVacia(aux1)) hanoi(aux1,aux2,aux3,longitud(aux1));
                apilar(aux1,aux); /*se coloca el valor más frágil en aux1*/
                /*se devuelve del aux3 al aux1*/
                if(!esPilaVacia(aux3)) hanoi(aux3,aux2,aux1,longitud(aux3));
            }
        }
        rec=faja.cabeza;
    }
    destruirPila(aux1);
    destruirPila(aux2);
    destruirPila(aux3);
}

int main(int argc, char** argv) {
    struct Lista faja;
    construir(faja);
    insertarAlInicio(faja,501);
    insertarAlInicio(faja,1002);
    insertarAlInicio(faja,2001);
    insertarAlInicio(faja,1501);
    insertarAlInicio(faja,502);
    insertarAlInicio(faja,2002);
    insertarAlInicio(faja,1001);
    cout<<"Faja: ";
    imprime(faja);
    struct Pila pila;
    construir(pila);
    robotApilador(faja,pila);
    cout<<"Pila: ";
    imprimir(pila);
    return 0;
}

