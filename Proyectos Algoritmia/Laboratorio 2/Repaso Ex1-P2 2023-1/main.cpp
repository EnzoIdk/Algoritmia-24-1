/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 24 de abril de 2024, 22:45
 */

#include <iostream>

#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"

using namespace std;

/*
 * 
 */

void insertarencolaOrdenada(struct Lista &tad, int elemento, int prioridad){
    struct Nodo * ultimoNodo = tad.cola;
    struct Nodo * nuevoNodo = crearNodo(elemento, prioridad, nullptr);
    //SI ES COLA VACIA
    if (ultimoNodo == nullptr){/*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        tad.cola = nuevoNodo;
        //EL CASO INICIAL, TODO ESTA VACIO
        if(prioridad==3){
            tad.finPrioridad3=nuevoNodo;
//            tad.finPrioridad2=nullptr;
        }
        else if(prioridad==2){
            tad.finPrioridad2=nuevoNodo;
//            tad.finPrioridad3=nullptr;
        }
//        else{
//            tad.finPrioridad2=nullptr;
//            tad.finPrioridad3=nullptr;
//        }
    } 
    else{ //La lista ya tiene nodos
        if(prioridad==3){
            //EL PRIORIDAD 3 SIEMPRE IRA EN LA CABEZA
            if(tad.finPrioridad3==nullptr){
                //SI NO HABIAN 3 ANTERIORES ENTONCES;
                tad.finPrioridad3=nuevoNodo;
                //SE INSERTA ORDENADAMENTE PARA QUE EL PRIORIDAD 3 SEA LA NUEVA CABEZA
                tad.finPrioridad3->siguiente=tad.cabeza;
                tad.cabeza=tad.finPrioridad3;
            }
            else{
                //AHORA SI HAY ELEMENTOS EN PRIORIDAD 3 Y SE INSERTA
                //DE MANERA ORDENADA SIGUIENDO EL ORDEN DE LLEGADA
                nuevoNodo->siguiente=tad.finPrioridad3->siguiente;
                tad.finPrioridad3->siguiente=nuevoNodo;
                tad.finPrioridad3=nuevoNodo;
            }
        }
        else if(prioridad==2){
            //EN CASO NO HABIA NINGUN 2 ANTERIORMENTE
            if(tad.finPrioridad2==nullptr){
                //SI NO HAY finPrioridad2 DE TODOS MODOS SE DEBE ASIGNAR
                tad.finPrioridad2=nuevoNodo;
                //SI ES QUE NO HABIA NINGUN 3 ANTES
                if(tad.finPrioridad3==nullptr){
                    //EL 2 SE VUELVE LA NUEVA CABEZA HASTA QUE LLEGUE UN 3
                    tad.finPrioridad2->siguiente=tad.cabeza;
                    tad.cabeza=tad.finPrioridad2;
                }
                else{
                    //SI HABIAN 3 ANTES ENTONCES SE INSERTA DE MANERA ORDENADA
                    tad.finPrioridad2->siguiente=tad.finPrioridad3->siguiente;
                    tad.finPrioridad3->siguiente=tad.finPrioridad2;
                }
            }
            else{
                //SI YA HABIAN ELEMENTOS TIPO 2 ENTONCES SE INSERTA POR ORDEN DE
                //LLEGADA
                nuevoNodo->siguiente=tad.finPrioridad2->siguiente;
                tad.finPrioridad2->siguiente=nuevoNodo;
                tad.finPrioridad2=nuevoNodo;
            }
        }
        else{
            //SIMPLMENTE SE INSERTA AL FINAL
            nuevoNodo->siguiente=nullptr;
            tad.cola->siguiente=nuevoNodo;
            tad.cola=nuevoNodo;
        }
    }
    tad.longitud++;
}

void encolar_prioridad(struct Cola &cola, int elemento, int prioridad){
    insertarencolaOrdenada(cola.lista, elemento, prioridad);
}

int main(int argc, char** argv) {
    
    struct Cola colaOrdenada;
    
    construir(colaOrdenada);
    
    encolar_prioridad(colaOrdenada, 005, 2);
    encolar_prioridad(colaOrdenada, 004, 3);
    encolar_prioridad(colaOrdenada, 003, 1);
    encolar_prioridad(colaOrdenada, 002, 1);
    encolar_prioridad(colaOrdenada, 007, 1);
    encolar_prioridad(colaOrdenada, 006, 3);
    encolar_prioridad(colaOrdenada, 001, 2);
    
    imprime(colaOrdenada);
    
    return 0;
}

