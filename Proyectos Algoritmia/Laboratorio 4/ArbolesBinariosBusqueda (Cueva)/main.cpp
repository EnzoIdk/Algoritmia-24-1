/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesPila.h"
#include "Pila.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO BÚSQUEDA 2024-1 
 */

/*Pos orden: Los hijos y luego el padre (IDR)*/
/*Para imprimir en pos orden, con pila*/

NodoArbol *busca(NodoArbol *parbol,int dato){
    if(parbol==nullptr) return parbol;
    else{
        if(parbol->elemento==dato) return parbol;
        else{
            if(parbol->elemento>dato) parbol=parbol->izquierda;
            else parbol=parbol->derecha;
            return busca(parbol,dato);
        }
    }
}

/*borrar e imprimir*/

void postOrdenIterativa(ArbolBinarioBusqueda arbol){
    NodoArbol *parbol; /*puntero al árbol*/
    int ultimo=0,alto;
    Pila stack;
    if(esArbolVacio(arbol)) return;
    construir(stack);
    parbol=arbol.arbolBinario.raiz;
    while(true){
        while(parbol){
            /*apilando todo a la izquierda*/
            apilar(stack,parbol->elemento);
            parbol=parbol->izquierda;
        }
        alto=cima(stack);
        parbol=busca(arbol.arbolBinario.raiz,alto);
        /*si la pata de la derecha en el punto más bajo es nullptr, se terminaría*/
        if(parbol->derecha!=nullptr and ultimo!=parbol->derecha->elemento)
            parbol=parbol->derecha;
        else{
            ultimo=desapilar(stack);
            cout<<ultimo<<" ";
            parbol=nullptr;
        }
        if(esPilaVacia(stack)) break;
    }
}

int main(int argc, char** argv) {

   struct ArbolBinarioBusqueda arbol;
    int auxiliarElemento;
    
    construir(arbol);
    insertar(arbol, 100);
    insertar(arbol, 50);
    insertar(arbol, 150);
    insertar(arbol, 125);
    insertar(arbol, 175);
    insertar(arbol, 200);
    insertar(arbol, 25);
    insertar(arbol, 75);
//    preOrden(arbol); cout<<endl;
//    enOrden(arbol);  cout<<endl;
//    postOrden(arbol); cout<<endl;
    postOrdenIterativa(arbol);
    return 0;
}

