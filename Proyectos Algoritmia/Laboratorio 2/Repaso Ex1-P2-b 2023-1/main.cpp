/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 25 de abril de 2024, 10:33
 */

#include <iostream>
#include <memory>
using namespace std;

#include "Cola.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesPila.h"

/*
 * SOLO ITERATIVAS
 * NO MEMORIA EXTRA, NO RECURSION, NO TADs ADICIONALES. NO DOBLE FOR
 * SOLO VARIABLES SIMPLES
 */
void desencolarCola(struct Cola &cola, int &elemento, int &detector){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        return; //Cero o algún elemento que no esté en la cola
    }
    else{
        //SACAMOS
        elemento=cola.lista.finSistema->siguiente->elemento;
        detector=cola.lista.finSistema->siguiente->detector;
        //ELIMINAMOS
        struct Nodo * nodoAEliminar = cola.lista.finSistema->siguiente;
        if (nodoAEliminar != nullptr) {
            cola.lista.finSistema->siguiente = 
                    cola.lista.finSistema->siguiente->siguiente;
            delete nodoAEliminar;
            cola.lista.longitud--;
        }
        if(esColaVacia(cola))
            cola.lista.cola = nullptr;
        return;
    }
    
}

void intercalar(struct Cola &cola, struct Pila &nuevaCola){
    int elemento, elementoTra;
    int detector, detectorTra;
    int largo=longitud(cola);
    
    for(int i=0; i<largo/2; i++){
        if(cola.lista.cola!=cola.lista.finSistema->siguiente){
            desencolar(cola, elemento, detector);
            apilar(nuevaCola, elemento, detector);
            desencolarCola(cola, elementoTra, detectorTra);
            apilar(nuevaCola, elementoTra, detectorTra); 
        }
        else{
            desencolar(cola, elemento, detector);
            apilar(nuevaCola, elemento, detector);
            desencolar(cola, elemento, detector);
            apilar(nuevaCola, elemento, detector);
        }
    }
}

int main(int argc, char** argv) {
    
    struct Cola cola;
    struct Pila nuevaCola;
    
    construir(cola);
    construir(nuevaCola);
    
    encolar(cola, 6, 1);
    encolar(cola, 7, 1);
    encolar(cola, 8, 1);
    encolar(cola, 9, 1);
    encolar(cola, 10, 1);
    encolar(cola, 1, 2);
    encolar(cola, 2, 2);
    encolar(cola, 3, 2);
    encolar(cola, 4, 2);
    encolar(cola, 5, 2);
    
    imprime(cola);
    
    intercalar(cola, nuevaCola);
    
    imprime(cola);
    imprimir(nuevaCola);
    
    return 0;
}

