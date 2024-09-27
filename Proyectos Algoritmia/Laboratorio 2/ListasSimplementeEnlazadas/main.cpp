/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>

#include "Lista.h"
using namespace std;
#include "funcionesLista.h"

void invierte(struct Lista &ptrlista){
    int n;
    Nodo *ptr,*pini;
    
    n=ptrlista.longitud;
    for(int i=1;i<n;i++){
        ptr = ptrlista.cabeza;
        for(int j=i+1;j<n;j++) ptr = ptr->siguiente;
       if(i==1) pini = ptr->siguiente; 
       ptr->siguiente->siguiente=ptr;
    }
    ptr->siguiente = nullptr;
    ptrlista.cabeza = pini;
        
}

Nodo* recorre(Nodo* ptrlista){
    
    if(ptrlista==nullptr) return nullptr;
    if(ptrlista->siguiente==nullptr) return ptrlista;
    Nodo *pini = recorre(ptrlista->siguiente);
    ptrlista->siguiente->siguiente = ptrlista;
    return pini;
}

void invierterec(struct Lista &ptrlista){
    Nodo *ptr=recorre(ptrlista.cabeza);
    ptrlista.cabeza->siguiente = nullptr;
    ptrlista.cabeza = ptr;
}


/*
 * IMPLEMENTACIÓN DE UNA LISTA SIMPLEMENTE ENLAZADA
 */
int main(int argc, char** argv) {

    struct Lista lnotas;
    
    construir(lnotas);
    
    insertarAlFinal(lnotas,5);
    insertarAlFinal(lnotas,13);
    insertarAlFinal(lnotas,15);
    insertarAlFinal(lnotas,20);
    imprime(lnotas);
    invierte(lnotas);
    imprime(lnotas);
    invierterec(lnotas);
    imprime(lnotas);   
    return 0;
}

