/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 5 de julio de 2024, 06:02 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>      
#include <cstring>
#include "ArbolBinario.h"
#include "Lista.h"
#include "funcionesArbolesBinarios.h"
#include "funciones.h"
using namespace std;

bool estaPresente(struct Lista &lista,char letra,char *palabra){
    struct Nodo *aux=lista.cabeza,*ant=nullptr;
    while(aux){
        if(aux->elemento==letra){
            if(ant==nullptr) lista.cabeza=aux->siguiente;
            else ant->siguiente=aux->siguiente;
            aux->siguiente=nullptr;
            delete aux;
            return true;
        }
        ant=aux;
        aux=aux->siguiente;
    }
}

bool encuentraPalabra(struct Lista &lista,char palabra[],struct NodoArbol *parbol){
    bool ini,der,izq;
    if(esNodoVacio(parbol)) return true;
    else{
        if(estaPresente(lista,parbol->elemento,palabra)){
            ini=true;
        }
        else{
//            insertarAlFinal(lista,parbol->elemento);
            return false;
        }
        izq=encuentraPalabra(lista,palabra,parbol->izquierda);
        der=encuentraPalabra(lista,palabra,parbol->derecha);
        return ini and (izq or der);
    }
}

void buscaPalabras(char palabras[6][10],struct ArbolBinario arbol,int numPalabras){
    struct Lista lista;
    for(int i=0;i<numPalabras;i++){
        construir(lista);
        for(int j=0;palabras[i][j];j++){
            insertarAlFinal(lista,palabras[i][j]);
        }
        if(encuentraPalabra(lista,palabras[i],arbol.raiz)){
            cout<<palabras[i]<<' ';
        }
        destruir(lista);
    }
}

int main(int argc, char** argv) {
    struct ArbolBinario arbol,aux[15];
    construir(arbol);
    char palabras[6][10]={
        {'H','I','J','O'},
        {'F','I','N','A','L'},
        {'M','U','N','D','O'},
        {'D','E','L'},
        {'D','I','A'},
        {'C','I','C','L','O'}
    };
    int n=6;
    plantarArbolBinario(aux[0],nullptr,'T',nullptr);
    plantarArbolBinario(aux[1],nullptr,'O',nullptr);
    plantarArbolBinario(aux[2],nullptr,'F',nullptr);
    plantarArbolBinario(aux[3],nullptr,'T',nullptr);
    plantarArbolBinario(aux[4],nullptr,'R',nullptr);
    plantarArbolBinario(aux[5],nullptr,'E',nullptr);
    plantarArbolBinario(aux[6],aux[0].raiz,'G',nullptr);
    plantarArbolBinario(aux[7],aux[1].raiz,'C',nullptr);
    plantarArbolBinario(aux[8],aux[2],'A',aux[3]);
    plantarArbolBinario(aux[9],aux[4],'E',aux[6]);
    plantarArbolBinario(aux[10],aux[7].raiz,'C',nullptr);
    plantarArbolBinario(aux[11],aux[8].raiz,'N',nullptr);
    plantarArbolBinario(aux[12],aux[5],'D',aux[9]);
    plantarArbolBinario(aux[13],aux[10],'I',aux[11]);
    plantarArbolBinario(arbol,aux[12],'L',aux[13]);
//    recorrerEnOrden(arbol);
    buscaPalabras(palabras,arbol,n);
    return 0;
}
