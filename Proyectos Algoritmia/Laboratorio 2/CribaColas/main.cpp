/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de abril de 2024, 10:43 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Cola.h"
#include "Lista.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
#include "Pila.h"        

using namespace std;

void procesaCriba(struct Lista &lista,struct Cola &cola,int n){
    struct Nodo *recorrido,*aux;
    int elementoEliminar;
    recorrido=lista.cabeza;
    while(recorrido->elemento*recorrido->elemento<=n){
        aux=recorrido->siguiente;
        while(aux!=nullptr){
            if(aux->elemento%recorrido->elemento==0){
                elementoEliminar=aux->elemento;
                encolar(cola,elementoEliminar);
                aux=aux->siguiente;
                eliminaNodo(lista,elementoEliminar);
            }
            else aux=aux->siguiente;
        }
        cout<<"Numero procesado: "<<recorrido->elemento<<endl;
        if(!esColaVacia(cola)){
            cout<<"Numeros tachados para el "<<recorrido->elemento<<" : ";
            imprime(cola);
            while(!esColaVacia(cola)) desencolar(cola); /*reiniciamos la cola*/
        }
        else{
            cout<<"No tiene numeros tachados"<<endl;
        }
        recorrido=recorrido->siguiente;
    }
    imprime(lista);
}

void invierte(struct Lista &lista,int n){
    int cabeza;
    if(n==1) return;
    cabeza=lista.cabeza->elemento;
    eliminaCabeza(lista);
    invierte(lista,n-1);
    insertarAlFinal(lista,cabeza);
}

int main(int argc, char** argv) {
    int n;
    struct Lista lista;
    struct Cola cola;
    n=15;
    construir(lista);
    construir(cola);
    for(int i=2;i<=n;i++) insertarAlFinal(lista,i);
    imprime(lista);
    cout<<endl;
    cout<<"Luego de la criba"<<endl;
    procesaCriba(lista,cola,n);
    invierte(lista,longitud(lista));
    imprime(lista);
    return 0;
}

