/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de abril de 2024, 09:27 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Lista.h"

using namespace std;

#include "funcionesLista.h"

/*Comenzando por 2, se eliminan todos sus múltiplos*/
/*Se eliminan los múltiplos de los siguientes primos y así sucesivamente 
 hasta que el cuadrado del primo sea mayor a n*/
void procesaCriba(struct Lista &lista,int n){
    struct Nodo *recorrido,*aux;
    int elementoEliminar;
    recorrido=lista.cabeza;
    while(recorrido->elemento*recorrido->elemento<n){
        aux=recorrido->siguiente;
        while(aux!=nullptr){
            /*quitando los múltiplos*/
            if(aux->elemento%recorrido->elemento==0){
                elementoEliminar=aux->elemento;
                aux=aux->siguiente;
                eliminaNodo(lista,elementoEliminar);
            }
            else aux=aux->siguiente;
        }
        recorrido=recorrido->siguiente;
    }
    imprime(lista);
}
        
void invierte(struct Lista &lista){
    struct Nodo *recorrido,*anterior,*siguiente;
    recorrido=lista.cabeza;
    anterior=nullptr;
    siguiente=nullptr;
    while(recorrido!=nullptr){
        siguiente=recorrido->siguiente;
        recorrido->siguiente=anterior;
        anterior=recorrido;
        recorrido=siguiente;
    }
    lista.cabeza=anterior;
}

int main(int argc, char** argv) {
    int n;
    struct Lista lista;
    n=30;
    construir(lista);
    for(int i=2;i<=n;i++) insertarAlFinal(lista,i);
    imprime(lista);
    cout<<endl;
    cout<<"Luego de la criba: "<<endl;
    procesaCriba(lista,n);
    invierte(lista);
    imprime(lista);
    
    return 0;
}

