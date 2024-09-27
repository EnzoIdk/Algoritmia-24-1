/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 5 de julio de 2024, 08:01 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Lista.h"
#include "funciones.h"
using namespace std;

void eliminaCabeza(struct Lista &tad){
    struct Nodo *aux=tad.cabeza;
    if(aux){
        tad.cabeza=tad.cabeza->siguiente;
        delete aux;
        tad.longitud--;
    }
}
void invierteListaRec(struct Lista &lista,int n){
    int cabeza;
    if(esListaVacia(lista) or n==1) return;
    cabeza=lista.cabeza->elemento;      
    eliminaCabeza(lista);
    invierteListaRec(lista,n-1);
    insertarAlFinal(lista,cabeza);
}

int main(int argc, char** argv) {
    struct Lista lista1,lista2;
    construir(lista1);
    insertarAlInicio(lista1,20);
    insertarAlFinal(lista1,25);
    insertarAlFinal(lista1,20);
    insertarAlFinal(lista1,30);
    insertarAlFinal(lista1,40);
    insertarAlInicio(lista1,10);
    imprime(lista1);cout<<endl;
    invierteListaRec(lista1,longitud(lista1));
    imprime(lista1);cout<<endl;
//    struct Nodo *rec=lista1.cola;
//    while(rec){
//        cout<<rec->elemento<<' ';
//        rec=rec->anterior;
//    }
//    cout<<endl<<lista1.cola->elemento<<endl;
    return 0;
}

