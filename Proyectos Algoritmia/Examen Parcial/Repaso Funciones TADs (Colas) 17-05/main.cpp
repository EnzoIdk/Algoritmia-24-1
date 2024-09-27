/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 17 de mayo de 2024, 19:11
 */

#include <iostream>
using namespace std;

#include "funcionesLista.h"
#include "funcionesCola.h"
#include "Cola.h"

/*
 *  
 */

void ordenaCola(struct Cola &cola, int elementos){
    //CASO FIN
    if(esColaVacia(cola)) return;
    //SACAMOS EL MAYOR
    int mayor=desencolar(cola), aux;
    //EMPEZAMOS DESDE 1 PORQUE YA SACAMOS A UNO
    for(int i=1; i<elementos; i++){
        aux=desencolar(cola);
        if(aux<mayor){
            encolar(cola, mayor);
            mayor=aux;
        }
        else encolar(cola, aux);
    }
    //RECURSION
    ordenaCola(cola, elementos-1);
    //VA ENCOLADO DEL ULTIMO OBTENIDO AL PRIMERO
    encolar(cola, mayor);
}

void encolarPrioridad(struct Lista &tad, int elemento, int prioridad){
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);
    if(tad.cola==nullptr){
        tad.cabeza=nuevoNodo;
        tad.cola=nuevoNodo;
        if(prioridad==1) tad.fin1=nuevoNodo;
        if(prioridad==2) tad.fin2=nuevoNodo;
    }
    else{
        if(prioridad==1){
            if(tad.fin1==nullptr){
                nuevoNodo->siguiente=tad.cabeza;
                tad.cabeza=nuevoNodo;
            }
            else{
                if(tad.fin1->siguiente==nullptr) tad.cola=nuevoNodo;
                nuevoNodo->siguiente=tad.fin1->siguiente;
                tad.fin1->siguiente=nuevoNodo;
            }
            tad.fin1=nuevoNodo;
        }
        else if(prioridad==2){
            if(tad.fin2==nullptr){
                if(tad.fin1==nullptr){
                    nuevoNodo->siguiente=tad.cabeza;
                    tad.cabeza=nuevoNodo;
                }
                else{
                    if(tad.fin1->siguiente==nullptr) tad.cola=nuevoNodo;
                    nuevoNodo->siguiente=tad.fin1->siguiente;
                    tad.fin1->siguiente=nuevoNodo;
                }
                tad.fin2=nuevoNodo;
            }
            else{
                if(tad.fin2->siguiente==nullptr) tad.cola=nuevoNodo;
                nuevoNodo->siguiente=tad.fin2->siguiente;
                tad.fin2->siguiente=nuevoNodo;
            }
            tad.fin2=nuevoNodo;
        }
        else{
            tad.cola->siguiente=nuevoNodo;
            tad.cola=nuevoNodo;
        }
    }
    tad.longitud++;
}

int main(int argc, char** argv) {
    
    struct Cola cola;
    construir(cola);
    
    encolar(cola, 6);
    encolar(cola, 9);
    encolar(cola, 5);
    encolar(cola, 2);
    encolar(cola, 13);
    encolar(cola, 4);
    
    imprime(cola);
    ordenaCola(cola, cola.lista.longitud);
    imprime(cola);
    
    struct Cola cola2;
    construir(cola2);
    
    encolarPrioridad(cola2.lista, 11, 2);
    encolarPrioridad(cola2.lista, 92, 3);
    encolarPrioridad(cola2.lista, 12, 2);
    encolarPrioridad(cola2.lista, 55, 1);
    encolarPrioridad(cola2.lista, 75, 1);
    encolarPrioridad(cola2.lista, 82, 3);
    encolarPrioridad(cola2.lista, 22, 1);
    encolarPrioridad(cola2.lista, 44, 2);
    encolarPrioridad(cola2.lista, 65, 3);
    imprime(cola2);
    
    return 0;
}

