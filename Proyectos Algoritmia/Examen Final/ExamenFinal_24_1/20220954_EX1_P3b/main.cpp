/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 6 de julio de 2024, 08:18 AM
 */

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

void ruleta(struct Lista &lista,int k){
    do{
        struct Nodo *rec=lista.cabeza;
        for(int i=1;i<k;i++){
            rec=rec->siguiente;
        }
        Nodo *aux=rec->siguiente;
        //para que siga recorriendo a partir del puntos en donde se quedó
        lista.cabeza=aux;
//        cout<<"Se elimina: "<<rec->elemento<<endl;
        eliminaNodo(lista,rec->elemento);
        
    }while(longitud(lista)!=1);
}

void cargarLista(struct Lista &lista,int n){
    for(int i=1;i<=n;i++){
        insertarAlFinal(lista,i);
    }
}

int main(int argc, char** argv) {
    struct Lista lista1,lista2,lista3;
    construir(lista1);
    //n: número de empleados, k: cada cuanto se elimina
    int n=5,k=2;
    //cargando datos
    cargarLista(lista1,n);
//    cout<<"Lista inicial: "<<endl;
//    imprime(lista1);
    ruleta(lista1,k);
    cout<<"En una lista de "<<n<<" empleados, para k = "<<k<<", el elegido es: ";
    imprime(lista1); //imprimimos el que queda en la lista
    construir(lista2);
    n=7,k=3;
    cargarLista(lista2,n);
    ruleta(lista2,k);
    cout<<"En una lista de "<<n<<" empleados, para k = "<<k<<", el elegido es: ";
    imprime(lista2); //imprimimos el que queda en la lista
    construir(lista3);
    n=10,k=7;
    cargarLista(lista3,n);
    ruleta(lista3,k);
    cout<<"En una lista de "<<n<<" empleados, para k = "<<k<<", el elegido es: ";
    imprime(lista3); //imprimimos el que queda en la lista
    return 0;
}

