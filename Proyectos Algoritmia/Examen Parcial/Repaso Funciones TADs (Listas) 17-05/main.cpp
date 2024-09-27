/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 17 de mayo de 2024, 20:04
 */

#include <iostream>
using namespace std;

#include "Lista.h"
#include "funciones.h"

/*
 * fusiondelista combinalista
 */

void invierteLista(struct Lista &lista){
    struct Nodo * anterior=nullptr;
    struct Nodo * actual=lista.cabeza;
    struct Nodo * siguiente=nullptr;
    
    while(actual!=nullptr){
        siguiente=actual->siguiente;
        actual->siguiente=anterior;
        
        anterior=actual;
        actual=siguiente;
    }
    lista.cabeza=anterior;
}

void eliminaCabeza(struct Lista &lista){
    struct Nodo * aux=lista.cabeza->siguiente;
    delete lista.cabeza;
    lista.cabeza=aux;
}

void invierteListaRec(struct Lista &lista, int elementos){
    //CASO FIN
    if(esListaVacia(lista) or elementos==1) return;
    //
    int cabeza=lista.cabeza->elemento;
    eliminaCabeza(lista);
    invierteListaRec(lista, elementos-1);
    insertarAlFinal(lista, cabeza);
}

int main(int argc, char** argv) {
    
    struct Lista lista;
    construir(lista);
    
    insertarAlFinal(lista, 23);
    insertarAlFinal(lista, 42);
    insertarAlFinal(lista, 54);
    insertarAlFinal(lista, 91);
    
    imprime(lista);
    invierteLista(lista);
    imprime(lista);
    
    invierteListaRec(lista, lista.longitud);
    imprime(lista);
    
    //fusionLista y combinarLista en pollosTikos
    
    return 0;
}

