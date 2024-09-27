/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 17 de mayo de 2024, 10:42 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Cola.h"
#include "funcionesCola.h"
#include "Lista.h"
#include "funcionesLista.h"

using namespace std;


void ordenaCola(struct Cola &cola,int n){
    int mayor,aux,i=1;
    if(n==1) return;
    mayor=desencolar(cola);
    while(i<n){
        aux=desencolar(cola);
        if(aux>mayor){
            encolar(cola,mayor);
            mayor=aux;
        }
        else encolar(cola,aux);
        i++;
    }
    ordenaCola(cola,n-1);
    encolar(cola,mayor);
}

void invertirCola(struct Cola &cola,int n){
    int aux;
    if(esColaVacia(cola) or n==1) return;
    aux=desencolar(cola);
    invertirCola(cola,n-1);
    encolar(cola,aux);
}

void combinarColas(struct Lista &lista1,struct Lista &lista2){
    if(lista1.cola->elemento<=lista2.cabeza->elemento){
        lista1.cola->siguiente=lista2.cabeza;
        lista1.cola=lista2.cola;
    }
    else{
        if(lista1.cabeza->elemento>=lista2.cola->elemento){
            lista2.cola->siguiente=lista1.cabeza;
            lista1.cabeza=lista2.cabeza;
        }
        else{
            struct Nodo *ini,*fin;
            ini=fin=nullptr;
            while(!esListaVacia(lista1) and !esListaVacia(lista2)){
                if(lista1.cabeza->elemento<=lista2.cabeza->elemento){
                    if(ini==nullptr){
                        ini=lista1.cabeza;
                        fin=lista1.cabeza;
                    }
                    else{
                        fin->siguiente=lista1.cabeza;
                        fin=lista1.cabeza;
                    }
                    lista1.cabeza=lista1.cabeza->siguiente;
                }
                else{
                    if(ini==nullptr){
                        ini=lista2.cabeza;
                        fin=lista2.cabeza;
                    }
                    else{
                        fin->siguiente=lista2.cabeza;
                        fin=lista2.cabeza;
                    }
                    lista2.cabeza=lista2.cabeza->siguiente;
                }
            }
            if(!esListaVacia(lista1)){
                fin->siguiente=lista1.cabeza;
                fin=lista1.cabeza;
            }
            if(!esListaVacia(lista2)){
                fin->siguiente=lista2.cabeza;
                fin=lista2.cabeza;
            }
            lista1.cabeza=ini;
            lista1.cola=fin;
        }
    }
}

int main(int argc, char** argv) {
//    struct Cola cola;
//    construir(cola);
//    encolar(cola,2);
//    encolar(cola,6);
//    encolar(cola,4);
//    encolar(cola,5);
//    encolar(cola,3);
//    encolar(cola,3);
//    imprime(cola);
//    ordenaCola(cola,longitud(cola));
//    imprime(cola);
//    invertirCola(cola,longitud(cola));
//    imprime(cola);
    struct Cola cola1,cola2;
    construir(cola1);
    construir(cola2);
    encolar(cola1,2);
    encolar(cola1,4);
    encolar(cola1,6);
    encolar(cola2,1);
    encolar(cola2,3);
    encolar(cola2,5);
    combinarColas(cola1.lista,cola2.lista);
    imprime(cola1);
    return 0;
}

