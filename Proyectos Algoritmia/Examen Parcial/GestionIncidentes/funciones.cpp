/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * Created on 8 de mayo de 2024, 06:27 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "funcionesLista.h"
using namespace std;

void pasarAPila(struct Cola & cola, struct Pila & pila1, struct Pila & pila2, int cant) {
    int elemento;
    while (not esColaVacia(cola)) {
        elemento = desencolar(cola);
        if (elemento / 100 == 1) {
            apilar(pila1, elemento);
        } else {
            apilar(pila2, elemento);
        }
        if (longitud(pila1) == cant or longitud(pila2) == cant) break;
    }
}

void ordenarPila(struct Pila & pila, int num) {

    if ((esPilaVacia(pila)) or longitud(pila) == 1) return;
    struct Nodo * recorrido = pila.lista.cabeza;
    struct Nodo * anterior = nullptr;
    while (recorrido != nullptr) {
        anterior = recorrido->siguiente;
        while (anterior != nullptr) {
            if (num == 1) {
                if (recorrido->elemento > anterior->elemento) {
                    int temp = recorrido->elemento;
                    recorrido->elemento = anterior->elemento;
                    anterior->elemento = temp;
                }
            } else {
                if (recorrido->elemento % 100 > anterior->elemento % 100) {
                    int temp = recorrido->elemento;
                    recorrido->elemento = anterior->elemento;
                    anterior->elemento = temp;
                }
            }
            anterior = anterior->siguiente;
        }
        recorrido = recorrido->siguiente;
    }
}

void reiniciaCola(struct Cola & cola, int longit, struct Pila & pila1, struct Pila & pila2) {

    //PASO 1
    int elemento, auxiliar;

    while (not esPilaVacia(pila2)) {
        elemento = desapilar(pila2);
        auxiliar = elemento;
        elemento = desapilar(pila2);
        apilar(pila1, elemento);
        apilar(pila1, auxiliar);
    }

    //PASO 2
    ordenarPila(pila1, 2);
    //PASO 3
    int n;

    n = longit - (longitud(pila1));
    while (n--) {
        elemento = desencolar(cola);
        encolar(cola, elemento);
    }
    n = longitud(pila1);
    while (n--) {
        elemento = desencolar(cola);
        apilar(pila2, elemento); // va a pila 2
    }
    n = longitud(pila1);
    while (n--) {
        elemento = desapilar(pila1);
        encolar(cola, elemento);
    }

    n = longit - (longitud(pila2)); // cambia por pila2
    while (n--) {
        elemento = desencolar(cola);
        encolar(cola, elemento);
    }
}

void reclasificaPilas(struct Pila & pila1, struct Pila & pila2) {

   struct Cola cola;
   construir(cola);
   while(not esPilaVacia(pila2)){
       int elemento = desapilar(pila2);
       encolar(cola, elemento);
   }
   pasarAPila(cola, pila1, pila2, 3);
}