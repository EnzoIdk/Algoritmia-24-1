/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RecorridoAmplitud_Recursivo_SinCola.cpp
 * Author: TAKASHIMA ICHIKAWA, MARIA EDUARDA
 * Codigo: 20190152
 * Created on 29 de mayo de 2024, 09:28 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "NodoArbol.h"
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "RecorridoAmplitud_Recursivo_SinCola.h"

void RecorridoAmplitudRecursivoSinCola(struct ArbolBinario &arbol) {
    //Función para recorrer el árbol por amplitud sin estructura auxiliar
    int alto = altura(arbol);
    cout << "Recorrer desde la raiz hasta las hojas:" << endl;
    for (int nivel = 0; nivel <= alto; nivel++)
        RecorridoAmplitudRecursivoSinCola(arbol.raiz, nivel);
    cout << endl << "Recorrer desde las hojas hasta la raiz:" << endl;
    for (int nivel = alto; 0 <= nivel; nivel--)
        RecorridoAmplitudRecursivoSinCola(arbol.raiz, nivel);
}

void RecorridoAmplitudRecursivoSinCola(struct NodoArbol* nodo, int nivel) {
    //Función para imprimir los nodos de un nivel 
    if (nodo == nullptr)
        return;
    if (nivel == 0)
        imprimeNodo(nodo);
    else if (nivel > 0) {
        RecorridoAmplitudRecursivoSinCola(nodo->izquierda, nivel - 1);
        RecorridoAmplitudRecursivoSinCola(nodo->derecha, nivel - 1);
    }
}
