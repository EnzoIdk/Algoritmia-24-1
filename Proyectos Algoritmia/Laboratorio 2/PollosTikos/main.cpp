/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de abril de 2024, 11:34 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Lista.h"
#include "funcionesLista.h"

using namespace std;

void fusionar(struct Lista &lista1,struct Lista &lista2){
    if (lista1.cola->elemento < lista2.cabeza->elemento){
        lista1.cola->siguiente = lista2.cabeza;
        lista1.cola = lista2.cola;
    }
    else {
        /*Aqui la lista 2 es disjunta a la lista 1 y es menor*/
        if (lista2.cola->elemento < lista1.cabeza->elemento){
            lista2.cola->siguiente = lista1.cabeza;
            lista1.cabeza = lista2.cabeza;
        }
        else {
            Nodo *inicio = nullptr;
            Nodo *fin = nullptr;
            while (!esListaVacia(lista1) && !esListaVacia(lista2)){
                if (lista1.cabeza->elemento<=lista2.cabeza->elemento){
                    if (inicio==nullptr){
                        inicio = lista1.cabeza;
                        fin = inicio;
                    }
                    else {
                        fin->siguiente = lista1.cabeza;
                        fin = lista1.cabeza;
                    }
                    lista1.cabeza = lista1.cabeza->siguiente; 
                }
                else{
                    if (inicio==nullptr){
                        inicio = lista2.cabeza;
                        fin = inicio;
                    }
                    else {
                        fin->siguiente = lista2.cabeza;
                        fin = lista2.cabeza;
                    }
                    lista2.cabeza = lista2.cabeza->siguiente;
                }
            }
            if (!esListaVacia(lista1)){
                fin->siguiente = lista1.cabeza;
                fin = lista1.cola;
            }
            if (!esListaVacia(lista2)){
                fin->siguiente = lista2.cabeza;
                fin = lista2.cola;
            }
            lista1.cabeza = inicio;
            lista1.cola = fin;
        }
    }
}

int main(int argc, char** argv) {
    struct Lista lunes,martes,miercoles,jueves,viernes;
    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);
    insertarAlFinal(lunes,8);
    insertarAlFinal(lunes,10);
    insertarAlFinal(lunes,12);
    insertarAlFinal(martes,9);
    insertarAlFinal(martes,11);
    insertarAlFinal(miercoles,8);
    insertarAlFinal(miercoles,9);
    insertarAlFinal(miercoles,10);
    insertarAlFinal(jueves,14);
    insertarAlFinal(jueves,15);
    insertarAlFinal(jueves,16);
    insertarAlFinal(viernes,17);
    insertarAlFinal(viernes,18);
    insertarAlFinal(viernes,19);
    imprime(lunes);
    imprime(martes);
    imprime(miercoles);
    imprime(jueves);
    imprime(viernes);
    fusionar(lunes,martes);
    fusionar(lunes,miercoles);
    fusionar(lunes,jueves);
    fusionar(lunes,viernes);
    imprime(lunes);
    return 0;
}

