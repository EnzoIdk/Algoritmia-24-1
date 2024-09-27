/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 5 de julio de 2024, 10:50 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Lista.h"
#include "funciones.h"
using namespace std;

/* LISTAS CIRCULARES SIMPLES
* El ejercicio consiste en realizar un sorteo, cuya dinámica empieza formando
* una ronda con los participantes. Para elegir al ganador, dado un número (k),
* partiendo del inicio se van retirando de la ronda los participantes cuya
* posición sea igual sea múltiplo de k. Por ejemplo, para k = 3, el primer
* participante en salir será el de la posición 3, el siguiente será el 6 y así
* sucesivamente, hasta que quede un solo participante, ese será el ganador.
*/

void eliminaNodo(struct Lista &lista,int elemento){
    struct Nodo *ultimo=nullptr;
    struct Nodo *recorrido=lista.cabeza;
    int encontrado=0;
    do{
        if(recorrido->elemento==elemento){
            encontrado=1;
            break;
        }
        ultimo=recorrido;
        recorrido=recorrido->siguiente;
    }while(recorrido!=lista.cabeza);
    if(encontrado){
        //estamos al principio
        if(ultimo==nullptr){
            if(recorrido==recorrido->siguiente)
                lista.cabeza=nullptr;
            else{
                struct Nodo *ultimoNodo=obtenerUltimoNodo(lista);
                lista.cabeza=recorrido->siguiente;
                if(ultimoNodo!=nullptr){
                    ultimoNodo->siguiente=lista.cabeza;
                }
            }
        }
        else{
            ultimo->siguiente=recorrido->siguiente;
        }
        delete recorrido;
        lista.longitud--;
    }
}

void soluJosephus(struct Lista &lista,int k){
    struct Nodo *rec=lista.cabeza,*sig=nullptr;
    int longitud=lista.longitud;
    do{
        for(int i=0;i<k-1;i++){
            rec=rec->siguiente;
        }
        sig=rec->siguiente;
        cout<<"Se elimina: "<<rec->elemento<<endl;
        if(rec==lista.cabeza){
            lista.cabeza=rec->siguiente;
        }
        eliminaNodo(lista,rec->elemento);
        imprime(lista);
        rec=sig;
    }while(lista.longitud!=1);
}

int main(int argc, char** argv) {
    struct Lista lista;
    construir(lista);
    int m=12;
    for(int i=0;i<m;i++){
        insertarAlFinal(lista,i+1);
    }
    imprime(lista);
    soluJosephus(lista,2);
    imprime(lista);
    return 0;
}

