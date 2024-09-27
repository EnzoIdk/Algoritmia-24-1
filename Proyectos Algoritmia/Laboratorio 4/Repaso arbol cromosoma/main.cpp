/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 30 de mayo de 2024, 12:13 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "ArbolBinario.h"
#include "NodoGen.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "funcionesArbolesBB.h"

void arbolEnIzq(struct NodoArbol *nodo,struct NodoGen dato){
    struct NodoArbol *nuevo=crearNuevoNodoArbol(nullptr,dato,nullptr);
    nodo->izquierda=nuevo;
}

void arbolEnDer(struct NodoArbol *nodo,struct NodoGen dato){
    struct NodoArbol *nuevo=crearNuevoNodoArbol(nullptr,dato,nullptr);
    nodo->derecha=nuevo;
}

void insertanivel(struct NodoArbol *nodo,int pesos[],int ini,int n){
    struct NodoGen temp;
    if(ini>=n) return;
    temp.cromo=0;
    temp.cantidad=pesos[ini];
//    arbolEnIzq(nodo,temp);
    nodo->izquierda=crearNuevoNodoArbol(nullptr,temp,nullptr);
    insertanivel(nodo->izquierda,pesos,ini+1,n);
    temp.cromo=1;
    temp.cantidad=pesos[ini];
//    arbolEnDer(nodo,temp);
    nodo->derecha=crearNuevoNodoArbol(nullptr,temp,nullptr);
    insertanivel(nodo->derecha,pesos,ini+1,n);
}

void crearArbolCromo(struct ArbolBinario &arbol,int pesos[],int n){
    struct NodoGen temp={0,0};
    plantarArbolBinario(arbol,nullptr,temp,nullptr);
    insertanivel(arbol.raiz,pesos,0,n);
}

void recorrerEnAmplitudRec(struct NodoArbol *nodo,int nivel){
    if(esNodoVacio(nodo)) return;
    if(nivel==0) imprimeNodo(nodo);
    else if(nivel>0){
        recorrerEnAmplitudRec(nodo->izquierda,nivel-1);
        recorrerEnAmplitudRec(nodo->derecha,nivel-1);
    }
}

void recorrerEnAmplitud(struct ArbolBinario arbol){
    int alto=altura(arbol);
    for(int i=0;i<=alto;i++){
        recorrerEnAmplitudRec(arbol.raiz,i);
    }
}

void calcular(struct NodoArbol *nodo,int parcial,int peso,int &cant){
    if(!esNodoVacio(nodo)){
        parcial+=(nodo->elemento.cantidad*nodo->elemento.cromo);
        if(esNodoVacio(nodo->izquierda)){
            if(peso==parcial) cant++;
        }
        else{
            calcular(nodo->izquierda,parcial,peso,cant);
            calcular(nodo->derecha,parcial,peso,cant);
        }
    }
}

void insertarRecursivo(struct NodoArbol *&nodo,struct NodoGen dato){
    if(esNodoVacio(nodo)){
        nodo=crearNuevoNodoArbol(nullptr,dato,nullptr);
    }
    else{
        if(nodo->elemento.cromo>dato.cromo) insertarRecursivo(nodo->izquierda,dato);
        else if(nodo->elemento.cromo<dato.cromo) insertarRecursivo(nodo->derecha,dato);
        else cout<<"El elemento "<<dato.cromo<<" ya esta en el arbol"<<endl;
    }
}

void insertar(struct ArbolBinario &arbol,struct NodoGen dato){
    insertarRecursivo(arbol.raiz,dato);
}

int main(int argc, char** argv) {
    struct ArbolBinario arbol;
    int n=5,peso=70;
    int paq[5]={10,50,20,30,40};
    construir(arbol);
    crearArbolCromo(arbol,paq,n);
//    recorrerPreOrden(arbol);
    recorrerEnAmplitud(arbol);cout<<endl;
    int cantidad=0;
    calcular(arbol.raiz,0,peso,cantidad);
    cout<<"La cantidad de soluciones es: "<<cantidad<<endl;
    struct ArbolBinario arbol2;
    construir(arbol2);
    plantarArbolBinario(arbol2,nullptr,{50,20},nullptr);
    insertar(arbol2,{20,20});
    insertar(arbol2,{10,20});
    insertar(arbol2,{30,30});
    insertar(arbol2,{50,20});
    insertar(arbol2,{70,70});
    insertar(arbol2,{90,70});
    insertar(arbol2,{60,60});
    recorrerPreOrden(arbol2);cout<<endl;
    recorrerEnAmplitud(arbol2);
    return 0;
}

