/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 4 de julio de 2024, 01:54 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "NodoArbol.h"
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

struct NodoArbol *buscarNodo(struct NodoArbol *parbol,int dato){
    if(esNodoVacio(parbol)) return parbol;
    else{
        if(parbol->elemento/10==dato/10) return parbol;
        else{
            if(dato/10 < parbol->elemento/10) return buscarNodo(parbol->izquierda,dato);
            else return buscarNodo(parbol->derecha,dato);
        }
    }
}

void unirRec(struct NodoArbol *nodo,struct ArbolBinarioBusqueda &destino){
    if(esNodoVacio(nodo)) return;
    unirRec(nodo->izquierda,destino);
    unirRec(nodo->derecha,destino);
    struct NodoArbol *aux=buscarNodo(destino.arbolBinario.raiz,nodo->elemento);
    if(esNodoVacio(aux)){ //si no lo encuentra, se inserta normal
        insertar(destino,nodo->elemento);
    }
    else{
        aux->elemento+=nodo->elemento%10;
    }
}

void unirEjercitos(struct ArbolBinarioBusqueda &emisor,struct ArbolBinarioBusqueda &destino){
    unirRec(emisor.arbolBinario.raiz,destino);
    destruirArbolBB(emisor);
}

void enPreOrdenIterativo(struct ArbolBinarioBusqueda arbol){
    struct Pila pila;
    struct NodoArbol *parbol;
    if(esArbolVacio(arbol)) return;
    int dato;
    construir(pila);
    parbol=arbol.arbolBinario.raiz;
    apilar(pila,parbol->elemento);
    while(!esPilaVacia(pila)){
        dato=desapilar(pila);
        parbol=buscarNodo(arbol.arbolBinario.raiz,dato);
        imprimeNodo(parbol);
        if(!esNodoVacio(parbol->derecha)) apilar(pila,parbol->derecha->elemento);
        if(!esNodoVacio(parbol->izquierda)) apilar(pila,parbol->izquierda->elemento);
    }
    destruirPila(pila);
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda destino,emisor;
    construir(destino);
    construir(emisor);
    insertar(destino,522);
    insertar(destino,401);
    insertar(destino,253);
    insertar(destino,422);
    insertar(destino,601);
    insertar(emisor,651);
    insertar(emisor,251);
    insertar(emisor,122);
    insertar(emisor,341);
    insertar(emisor,752);
    insertar(emisor,701);
    cout<<"Ejercito emisor:  ";enOrden(emisor);cout<<endl;
    cout<<"Ejercito destino: ";enOrden(destino);cout<<endl;
    unirEjercitos(emisor,destino);
    cout<<"Ejercito emisor:  ";enOrden(emisor);cout<<endl;
    cout<<"Ejercito destino: ";enOrden(destino);cout<<endl;
    cout<<"Impresion en preorden: "<<endl;
    enPreOrdenIterativo(destino);cout<<endl;preOrden(destino);
    return 0;
}

