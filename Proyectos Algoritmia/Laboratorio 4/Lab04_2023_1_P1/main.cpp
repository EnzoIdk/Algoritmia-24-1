/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 30 de mayo de 2024, 03:03 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "NodoArbol.h"
#include "NodoGen.h"
#include "ArbolBinario.h"
#include "Cola.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"

int buscarSkynerd(struct NodoArbol *nodo,struct NodoGen datos){
    struct NodoArbol *aux;
    if(esNodoVacio(nodo)) return 0;
    struct Cola cola;
    construir(cola);
    encolar(cola,nodo);
    while(!esColaVacia(cola)){
        aux=desencolar(cola);
        if(aux->elemento.velocidad==200){
            struct NodoArbol *aux1;
            if(!esNodoVacio(aux->izquierda)){
                aux1=aux->izquierda;
                if(aux1->elemento.servidor==datos.servidor and aux1->elemento.velocidad==datos.velocidad){
                    destruirCola(cola);
                    return alturaRecursivo(nodo)-alturaRecursivo(aux1);
                }
            }
            if(!esNodoVacio(aux->derecha)){
                aux1=aux->derecha;
                if(aux1->elemento.servidor==datos.servidor and aux1->elemento.velocidad==datos.velocidad){
                    destruirCola(cola);
                    return alturaRecursivo(nodo)-alturaRecursivo(aux1);
                }
            }
        }
        if(!esNodoVacio(aux->izquierda)) encolar(cola,aux->izquierda);
        if(!esNodoVacio(aux->derecha)) encolar(cola,aux->derecha);
    }
    destruirCola(cola);
    return 0;
}

int main(int argc, char** argv) {
    struct ArbolBinario Skynerd,arbol1,arbol2,arbol3,arbol4,arbol5,arbol6;
    struct ArbolBinario arbol7,arbol8,arbol9,arbol10,arbol11,arbol12;
    construir(Skynerd);
//    construir(arbol1);
//    construir(arbol2);
    plantarArbolBinario(Skynerd,nullptr,{'Z',100,1},nullptr);
    plantarArbolBinario(arbol1,nullptr,{'E',50,5},nullptr);
    plantarArbolBinario(arbol2,nullptr,{'E',100,5},nullptr);
    plantarArbolBinario(arbol3,arbol1.raiz,{'S',50,4},nullptr);
    plantarArbolBinario(arbol4,arbol2.raiz,{'Z',200,4},nullptr);
    plantarArbolBinario(arbol5,nullptr,{'S',100,4},nullptr);
    plantarArbolBinario(arbol6,nullptr,{'E',200,4},nullptr);
    plantarArbolBinario(arbol7,arbol3,{'E',100,3},arbol4);
    plantarArbolBinario(arbol8,nullptr,{'S',50,3},nullptr);
    plantarArbolBinario(arbol9,arbol5,{'S',200,3},arbol6);
    plantarArbolBinario(arbol10,nullptr,{'S',150,3},nullptr);
    plantarArbolBinario(arbol11,arbol7,{'Z',50,2},arbol8);
    plantarArbolBinario(arbol12,arbol9,{'E',200,2},arbol10);
    plantarArbolBinario(Skynerd,arbol11,{'Z',100,1},arbol12);
    recorrerPreOrden(Skynerd);cout<<endl;
    struct NodoGen datos={'S',200,0};
    int nivel=buscarSkynerd(Skynerd.raiz,datos);
    if(nivel){
        cout<<endl<<"Skynerd se encuentra en el nivel "<<nivel<<" del arbol"<<endl;
    }
    else cout<<endl<<"No se encontro Skynerd"<<endl;
    return 0;
}

