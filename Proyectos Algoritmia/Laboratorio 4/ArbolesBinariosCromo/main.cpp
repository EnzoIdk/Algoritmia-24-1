/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"

int y=0;

void insertar_ab_izq(NodoArbol* tad,NodoGen dato){
   NodoArbol* nuevo = crearNuevoNodoArbol(NULL,dato,NULL);
   tad->izquierda = nuevo; 
}
void insertar_ab_der(NodoArbol* tad,NodoGen dato){
   NodoArbol* nuevo = crearNuevoNodoArbol(NULL,dato,NULL);
   tad->derecha=nuevo; 
}

void insertanivel(NodoArbol* arbol1,int pesos[],int ini,int n){
    NodoGen temp;
    
    if(ini>=n) return;
    
    temp.cromo=0;
    temp.cantidad=pesos[ini];
    insertar_ab_izq(arbol1,temp);
    insertanivel(arbol1->izquierda,pesos,ini+1,n);
    
    temp.cromo=1;
    temp.cantidad=pesos[ini];
    insertar_ab_der(arbol1,temp);
    insertanivel(arbol1->derecha,pesos,ini+1,n);    
    
}

void creaarbolcromo(ArbolBinario &arbol1,int paq[],int n){
    NodoGen temp;
    
    temp.cromo = 0;
    temp.cantidad = 0;
    plantarArbolBinario(arbol1,nullptr,temp,nullptr);
    insertanivel(arbol1.raiz,paq,0,n);   
}


void calcula(NodoArbol *tad,int parcial,int peso){
   
    if(!esNodoVacio(tad)){
        parcial=parcial+tad->elemento.cantidad*tad->elemento.cromo;
        if(esNodoVacio(tad->izquierda)){
            if(peso==parcial) y++;
        }    
        else{
            calcula(tad->izquierda,parcial,peso);
            calcula(tad->derecha,parcial,peso);   
        }
    }
}


int main(int argc, char** argv) {

    ArbolBinario arbol1;

    int n=5,peso=70;
    int paq[]={10,50,20,30,40};
    
    construir(arbol1);
    
    creaarbolcromo(arbol1,paq,n);
    recorrerEnPreOrdenRecursivo(arbol1.raiz);
    cout << endl;
    calcula(arbol1.raiz,0,peso);
    cout << "Numero de soluciones: " << y; 
    
    return 0;
}

