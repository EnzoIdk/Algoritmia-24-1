/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de junio de 2024, 07:49 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#define M 10
#define N 6

int existeLetra(char letra,char palabra[N]){
    for(int i=0;palabra[i];i++){
        if(letra==palabra[i]) return 1;
    }
    return 0;
}

int verificaPalabra(char palabra[N],char aux[N],int pos){
    char aux2[N];
    int hay,size=0;
    for(int i=0;i<pos;i++){
        aux2[i]=aux[i];
    }
    for(int i=0;palabra[i];i++){
        hay=0;
        size++;
        for(int j=0;j<pos;j++){
            if(palabra[i]==aux2[j]){
                hay=1;
                aux2[j]=' ';
                break;
            }
        }
        if(!hay) break;
    }
    return hay and (size==pos);
}

int existePalabra(struct NodoArbol *raiz,char palabra[N],char aux[N],int pos){
    if(raiz==nullptr) return 0;
    if(existeLetra(raiz->elemento,palabra)){
        aux[pos]=raiz->elemento;
        pos++;
    }
    else return 0;
    if(esNodoVacio(raiz->izquierda) and esNodoVacio(raiz->derecha)){
        if(verificaPalabra(palabra,aux,pos)){
            return 1;
        }
        else return 0;
    }
    return existePalabra(raiz->izquierda,palabra,aux,pos)+existePalabra(raiz->derecha,palabra,aux,pos);
}

int main(int argc, char** argv) {
    struct ArbolBinario arbol;
    struct ArbolBinario auxArbol[15];
    construir(arbol);
    plantarArbolBinario(auxArbol[0],nullptr,'T',nullptr);
    plantarArbolBinario(auxArbol[1],nullptr,'O',nullptr);
    plantarArbolBinario(auxArbol[2],nullptr,'F',nullptr);
    plantarArbolBinario(auxArbol[3],nullptr,'T',nullptr);
    plantarArbolBinario(auxArbol[4],nullptr,'R',nullptr);
    plantarArbolBinario(auxArbol[5],auxArbol[0].raiz,'G',nullptr);
    plantarArbolBinario(auxArbol[6],auxArbol[1].raiz,'C',nullptr);
    plantarArbolBinario(auxArbol[7],auxArbol[2],'A',auxArbol[3]);
    plantarArbolBinario(auxArbol[8],nullptr,'E',nullptr);
    plantarArbolBinario(auxArbol[9],auxArbol[4],'E',auxArbol[5]);
    plantarArbolBinario(auxArbol[10],auxArbol[6].raiz,'C',nullptr);
    plantarArbolBinario(auxArbol[11],auxArbol[7].raiz,'N',nullptr);
    plantarArbolBinario(auxArbol[12],auxArbol[8],'D',auxArbol[9]);
    plantarArbolBinario(auxArbol[13],auxArbol[10],'I',auxArbol[11]);
    plantarArbolBinario(arbol,auxArbol[12],'L',auxArbol[13]);
    char palabras[M][N]={
        {'H','I','J','O',0},
        {'F','I','N','A','L',0},
        {'M','U','N','D','O',0},
        {'D','E','L',0},
        {'D','I','A',0},
        {'C','I','C','L','O',0}
    };
    char aux[N];
    int pos=0;
    for(int i=0;i<M;i++){
        if(existePalabra(arbol.raiz,palabras[i],aux,pos)){
            cout<<palabras[i]<<' ';
        }
    }
    return 0;
}

