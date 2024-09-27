/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de abril de 2024, 09:35 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Lista.h"

using namespace std;

#include "funcionesLista.h"

void insertarEnOrdenArchivo(const char * nombArchText, struct Lista & tad) {
    ifstream archText(nombArchText, ios::in);
    if (not archText.is_open()) {
        cout << "ERROR: No se puede abrir el archivo";
        exit(1);
    }

    int elemento;
    while (true) {
        archText>>elemento; //lee el elemento del archivo
        if (archText.eof()) break;
        insertarEnOrden(tad, elemento);
    }
}

Nodo *recorre(Nodo *ptrlista){
    if(ptrlista==nullptr) return nullptr;
    if(ptrlista->siguiente==nullptr) return ptrlista;
    Nodo *pini=recorre(ptrlista->siguiente);
    ptrlista->siguiente->siguiente=ptrlista;
    return pini;
}

void invierteRec(struct Lista &ptrlista){
    Nodo *ptr=recorre(ptrlista.cabeza);
    ptrlista.cabeza->siguiente=nullptr;
    ptrlista.cabeza=ptr;
}

void invierteListaRec(struct Lista &lista,int n){
    int cabeza,i=1;
    if(esListaVacia(lista) or n==1) return;
    cabeza=lista.cabeza->elemento; 
    eliminaCabeza(lista);
    invierteListaRec(lista,n-1);
    insertarAlFinal(lista,cabeza);
}

int main(int argc, char** argv) {
    struct Lista lista;
    construir(lista);
//    cout<<esListaVacia(lista)<<endl;
    insertarAlInicio(lista,5);
    insertarAlInicio(lista,3);
    insertarAlInicio(lista,1);
    imprime(lista);
    insertarAlFinal(lista,6);
    insertarAlFinal(lista,8);
    insertarAlFinal(lista,10);
    imprime(lista);
    insertarEnOrden(lista,4);
    insertarEnOrden(lista,2);
    insertarEnOrden(lista,7);
    imprime(lista);
    eliminaNodo(lista,5);
    eliminaNodo(lista,3);
    imprime(lista);
    eliminaCabeza(lista); /*elimina el primer nodo de la lista*/
    eliminaCola(lista); /*elimina el último nodo de la lista*/
    eliminaCola(lista);
    imprime(lista); 
    destruir(lista); /*libera la memoria de la lista*/
    imprime(lista);
    construir(lista);
//    insertarEnOrdenArchivo("Datos.txt",lista);
    insertarAlInicioArchivo("Datos.txt",lista);
    cout<<"La longitud es: "<<longitud(lista)<<endl;
    imprime(lista);
//    invierteRec(lista);
    invierteListaRec(lista,longitud(lista));
    imprime(lista);
    return 0;
}

