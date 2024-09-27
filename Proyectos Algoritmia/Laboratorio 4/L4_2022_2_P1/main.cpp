/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "NodoGen.h"
using namespace std;
#include "funcionesArbolesBinarios.h"

void inserta_ab_izq(NodoArbol *base,NodoGen dato){
    NodoArbol *nuevo=crearNuevoNodoArbol(nullptr,dato,nullptr);
    base->izquierda=nuevo;
}

void inserta_ab_der(NodoArbol *base,NodoGen dato){
    NodoArbol *nuevo=crearNuevoNodoArbol(nullptr,dato,nullptr);
    base->derecha=nuevo;
}

void insertanivel(NodoArbol *nodoA,int *paq,int ini,int n){
    NodoGen temp;
    if(ini==n) return;
    temp.cromo=0;
    temp.peso=paq[ini];
    inserta_ab_izq(nodoA,temp);
    insertanivel(nodoA->izquierda,paq,ini+1,n);
    temp.cromo=1;
    inserta_ab_der(nodoA,temp);
    insertanivel(nodoA->derecha,paq,ini+1,n);
}

void crearCromo(ArbolBinario &arbol,int *paq,int n){
    NodoGen temp={0,0};
    plantarArbolBinario(arbol,nullptr,temp,nullptr);
    insertanivel(arbol.raiz,paq,0,n);
}

void calcularCombinaciones(NodoArbol *nodoA,int peso,int suma,int &cant){
    suma+=nodoA->elemento.cromo*nodoA->elemento.peso;
    if(nodoA->izquierda==nullptr and nodoA->derecha==nullptr){
        if(suma==peso) cant++;
        return;
    }
    calcularCombinaciones(nodoA->izquierda,peso,suma,cant);
    calcularCombinaciones(nodoA->derecha,peso,suma,cant);
}

int main(int argc, char** argv) {
    struct ArbolBinario arbol;
    int n=5,peso=70,cantidad=0,suma=0;
    int paq[]={10,50,20,30,40};
    construir(arbol);
    crearCromo(arbol,paq,n);
    calcularCombinaciones(arbol.raiz,peso,suma,cantidad);
    cout<<"Se encontraron "<<cantidad<<" combinaciones"<<endl;
    return 0;
}

