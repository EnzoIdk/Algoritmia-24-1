/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */

struct NodoArbol * crearNuevoNodoArbolNuevo(struct NodoArbol * arbolIzquierdo, 
                               int elemento, int dato, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->dato = dato;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

//Funcion para plantar arbol binario con referencia al arbol
void plantarArbolBinarioNuevo(struct ArbolBinario & arbol, struct NodoArbol * arbolIzquierdo,
                         int elemento, int dato, struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNuevo(arbolIzquierdo, elemento, dato, arbolDerecho);
    arbol.raiz = nuevoNodo;
}
//sobrecarga de la funcion para plantar el arbol con referencia a la raiz 
void plantarArbolBinarioNuevo(struct NodoArbol *& raiz, struct NodoArbol * arbolIzquierdo,
                         int elemento, int dato, struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNuevo(arbolIzquierdo, elemento, dato, arbolDerecho);
    raiz = nuevoNodo;
}

void insertaValorArbolRecursivo (struct NodoArbol *& raiz, int elemento,  int valor){
    if (raiz==nullptr){//CASO BASE: Si la raiz es nulo, planta un nuevo arbol
        plantarArbolBinarioNuevo(raiz, nullptr, elemento, valor,nullptr);
        return;
    }
    //Siguiendo el patrón del árbol cromosoma, siempre izquierda tiene el gen0 y derecha el gen1
    insertaValorArbolRecursivo(raiz->derecha, 1, valor);
    insertaValorArbolRecursivo(raiz->izquierda, 0, valor);
}

void insertaValorArbol(struct ArbolBinario & arbol, int valor){
    insertaValorArbolRecursivo (arbol.raiz, 0, valor);//"elemento" es 0 por ser la raiz del árbol-cromosoma.
}

int determinarCombinacionesRecursivo(struct NodoArbol * raiz, int peso, int peso_parcial){
    peso_parcial= peso_parcial + raiz->elemento*raiz->dato;//si elemento es 0, no se selecciona. Si es 1, se selecciona para la solución
    //primero tenemos que asegurarnos que estamnos en una hoja
    if (raiz->derecha==nullptr && raiz->izquierda==nullptr){
        if (peso_parcial==peso)
            return 1;
        else
            return 0;
    }
    return determinarCombinacionesRecursivo(raiz->izquierda, peso, peso_parcial) + determinarCombinacionesRecursivo(raiz->derecha, peso, peso_parcial);
}

int determinarCombinaciones(struct ArbolBinario cromosoma, int peso){
    int peso_parcial=0;
    return determinarCombinacionesRecursivo(cromosoma.raiz, peso, peso_parcial);
}
int main(int argc, char** argv) {

    
    
    int cantidad=5;
    int arreglo[cantidad]={10,50,20,30,40};//datos de entrada
    
    struct ArbolBinario cromosoma;
    construir(cromosoma);
    
    //plantar la raiz de nuestro arbol cromosoma
    plantarArbolBinarioNuevo(cromosoma, nullptr, 0,0,nullptr);
    for (int i=0; i<cantidad; i++){
        insertaValorArbol(cromosoma, arreglo[i]);
    }
    recorrerPreOrden(cromosoma);
    
    int peso=70;
    //encontraremos las soluciones que cumplen con la condición: peso=70
    cout<<endl<<"Combinaciones: " << determinarCombinaciones(cromosoma, peso)<<endl;
    return 0;
}

