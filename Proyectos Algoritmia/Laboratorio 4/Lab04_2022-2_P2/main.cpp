/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 31 de mayo de 2024, 11:20 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "ArbolBinarioBusqueda.h"
#include "NodoGen.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesArbolesBB.h"
using namespace std;

struct NodoArbol *buscarNodo(struct NodoArbol *nodo,struct NodoGen elemento){
    if(esNodoVacio(nodo)) return nullptr;
    else{
        if(nodo->elemento.fecha==elemento.fecha) return nodo;
        else{
            if(nodo->elemento.fecha>elemento.fecha) return buscarNodo(nodo->izquierda,elemento);
            else return buscarNodo(nodo->derecha,elemento);
        }
    }
}

void fusionar(struct NodoArbol *pEmisor,struct NodoArbol *pDestino){
    struct NodoArbol *aux;
    if(esNodoVacio(pEmisor)) return;
    else{
        fusionar(pEmisor->izquierda,pDestino);
        fusionar(pEmisor->derecha,pDestino);
        aux=buscarNodo(pDestino,pEmisor->elemento);
        if(esNodoVacio(aux)){
            insertarRecursivo(pDestino,pEmisor->elemento);
        }
        else{
            aux->elemento.cant+=pEmisor->elemento.cant;
        }
    }
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda destino,emisor;
    construir(destino);
    construir(emisor);
    insertar(destino,{20170620,20});
    insertar(destino,{20170810,20});
    insertar(destino,{20180211,20});
    insertar(destino,{20180409,10});
    insertar(emisor,{20170811,5});
    insertar(emisor,{20180211,10});
    insertar(emisor,{20180410,15});
    preOrden(destino);cout<<endl;
    preOrden(emisor);cout<<endl;
    fusionar(emisor.arbolBinario.raiz,destino.arbolBinario.raiz);
    destruirArbolBB(emisor);
    cout<<endl<<"Despues de la fusion"<<endl;
    enOrden(destino);
    return 0;
}

