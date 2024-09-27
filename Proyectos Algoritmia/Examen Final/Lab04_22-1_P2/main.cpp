/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 4 de julio de 2024, 08:34 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>      
#include "Pila.h"
#include "funcionesPila.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
using namespace std;

void despachar(struct NodoArbol *parbol,int cant){
    if(cant==0) return;
    struct NodoArbol *aux=minimoArbol(parbol);
    if(aux->elemento%100<=cant){
        cant-=aux->elemento%100;
        parbol=eliminarNodoRecursivo(parbol,aux->elemento);
        despachar(parbol,cant);
    }
    else{
        aux->elemento-=cant;
        cant=0;
    }
}

struct NodoArbol *buscaNodo(struct NodoArbol *parbol,int dato){
    if(esNodoVacio(parbol)) return parbol;
    else{
        if(dato==parbol->elemento) return parbol;
        else{
            if(dato/10<parbol->elemento/10) return buscaNodo(parbol->izquierda,dato);
            else return buscaNodo(parbol->derecha,dato);
        }
    }
}

void preOrdenIterativo(struct ArbolBinarioBusqueda arbol){
    struct Pila pila;
    if(esArbolVacio(arbol)) return;
    struct NodoArbol *parbol=arbol.arbolBinario.raiz;
    construir(pila);
    apilar(pila,parbol->elemento);
    int dato;
    while(!esPilaVacia(pila)){
        dato=desapilar(pila);
        parbol=buscaNodo(arbol.arbolBinario.raiz,dato);
        imprimeNodo(parbol);
        if(!esNodoVacio(parbol->derecha)) apilar(pila,parbol->derecha->elemento);
        if(!esNodoVacio(parbol->izquierda)) apilar(pila,parbol->izquierda->elemento);
    }
    destruirPila(pila);
}

void enOrdenIterativo(struct ArbolBinarioBusqueda arbol){
    struct Pila pila;
    if(esArbolVacio(arbol)) return;
    construir(pila);
    struct NodoArbol *parbol=arbol.arbolBinario.raiz;
    int dato;
    while(true){
        while(parbol){
            apilar(pila,parbol->elemento);
            parbol=parbol->izquierda;
        }
        if(esPilaVacia(pila)) break;
        dato=desapilar(pila);
        parbol=buscaNodo(arbol.arbolBinario.raiz,dato);
        imprimeNodo(parbol);
        parbol=parbol->derecha;
    }
    destruirPila(pila);
}

void postOrdenIterativo(struct ArbolBinarioBusqueda arbol){
    struct Pila pila;
    if(esArbolVacio(arbol)) return;
    construir(pila);
    struct NodoArbol *parbol=arbol.arbolBinario.raiz;
    construir(pila);
    int alto,ultimo=0;
    while(true){
        while(parbol){
            apilar(pila,parbol->elemento);
            parbol=parbol->izquierda;
        }
        alto=cima(pila);
        parbol=buscaNodo(arbol.arbolBinario.raiz,alto);
        if(parbol->derecha!=nullptr and parbol->derecha->elemento!=ultimo){
            parbol=parbol->derecha;
        }
        else{
            ultimo=desapilar(pila);
            imprimeNodo(parbol);
            parbol=nullptr;
        }
        if(esPilaVacia(pila)) break;
    }
    destruirPila(pila);
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    int n;
    construir(arbol);
    insertar(arbol,2022081540);
    insertar(arbol,2022071050);
    insertar(arbol,2022072050);
    insertar(arbol,2022063050);
    insertar(arbol,2022062440);
    insertar(arbol,2022061540);
    insertar(arbol,2022061840);
    insertar(arbol,2022093030);
    cout<<"Arbol inicial: "<<endl;
    preOrden(arbol);cout<<endl;
    preOrdenIterativo(arbol);cout<<endl;
    enOrdenIterativo(arbol);cout<<endl;
    postOrdenIterativo(arbol);cout<<endl;
//    cout<<"Ingrese la cantidad de solicitudes de despacho: ";
//    cin>>n;
//    cout<<endl;
//    int cant;
//    for(int i=0;i<n;i++){
//        cout<<"Ingrese la cantidad de unidades para el despacho "<<i+1<<": ";
//        cin>>cant;
//        despachar(arbol.arbolBinario.raiz,cant);
//        preOrdenIterativo(arbol);
//        cout<<endl;
//    }
    return 0;
}

