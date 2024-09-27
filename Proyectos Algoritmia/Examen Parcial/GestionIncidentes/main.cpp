/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 8 de mayo de 2024, 05:58 PM
 */

#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "funciones.h"
#include "funcionesLista.h"
using namespace std;

/*
 * Pregunta 2 - Examen 1 de Algoritmia 2023-2
 */
int main(int argc, char** argv) {
    
    struct Cola cola;
    construir(cola);
    encolar(cola, 101);
    encolar(cola, 102);
    encolar(cola, 203);
    encolar(cola, 204);
    encolar(cola, 105);
    encolar(cola, 206);
    encolar(cola, 107);
    encolar(cola, 208);
    encolar(cola, 109);
    encolar(cola, 210);
    encolar(cola, 211);
    encolar(cola, 112);
    encolar(cola, 113);
          
    struct Pila pila1, pila2;
    construir(pila1);
    construir(pila2);
    
    pasarAPila(cola, pila1, pila2, 3);
   
    cout<<"INICIAL: "<<endl<<"Cola : "; imprimir(cola);
    cout<<"PILA 1: "; imprimir(pila1);
    cout<<"PILA 2: "; imprimir(pila2);
    
    /*PREGUNTA 1*/ /*función reinicia_cola()*/
    int n = longitud(cola);
    reiniciaCola(cola, n, pila1, pila2);
    
    cout<<endl<<"REINICIA COLA : "<<endl<<"Cola : ";
    imprimir(cola);
    cout<<"Pila 1 : ";
    imprimir(pila1);
    cout<<"Pila 2 : ";
    imprimir(pila2);
    
    /*PREGUNTA B */
    
    reclasificaPilas(pila1, pila2);
    cout<<endl<<"RECLASIFICA PILAS : "<<endl<<"Cola : ";
    imprimir(cola);
    cout<<"Pila 1 : ";
    imprimir(pila2);
    cout<<"Pila 2 : ";
    imprimir(pila1);
    
    return 0;
}

