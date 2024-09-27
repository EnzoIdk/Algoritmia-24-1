/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 1 de junio de 2024, 08:13
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "ArbolBinario.h"
#include "NodoGen.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesArbolesBinarios.h"
using namespace std;


void encontrarPrincipal(struct ArbolBinario arbol){
    struct Cola cola;
    struct NodoArbol *aux,*parbol=arbol.raiz;
    if(esNodoVacio(parbol)) return;
    construir(cola);
    encolar(cola,parbol);
    encolar(cola,nullptr);
    int nivel=0,nivelABuscar=-1;
    while(longitud(cola)>1){
        aux=desencolar(cola);
        if(!esNodoVacio(aux)){
            imprimeNodo(aux);
            if(strcmp(aux->elemento.titulo,"Principal")==0) nivelABuscar=nivel;
            if(!esNodoVacio(aux->izquierda)) encolar(cola,aux->izquierda);
            if(!esNodoVacio(aux->derecha)) encolar(cola,aux->derecha);
        }
        else{
            nivel++;
            cout<<endl;
            encolar(cola,aux);
        }
    }
    destruirCola(cola);
    if(nivelABuscar!=-1) cout<<endl<<"El nivel es: "<<nivelABuscar<<endl;
    else cout<<endl<<"No se encontro Principal"<<endl;
}

void eliminaParteDerecha(struct ArbolBinario &arbol){
    NodoArbol *nodo=arbol.raiz;
    destruirRecursivo(nodo->derecha);
    nodo->derecha=nullptr;
    nodo->tamanio=numeroNodos(arbol);
}

int main(int argc, char** argv) {
    struct ArbolBinario arbol,aux1,aux2,aux3,aux4,aux5,aux6,aux7,aux8;
    construir(arbol);
    struct NodoGen temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9;
    strcpy(temp1.titulo,"Titulo"); temp1.relevancia=7;
    strcpy(temp2.titulo,"Capitulo 1"); temp2.relevancia=8;
    strcpy(temp3.titulo,"Capitulo 2"); temp3.relevancia=5;
    strcpy(temp4.titulo,"Seccion 1.1"); temp4.relevancia=6;
    strcpy(temp5.titulo,"Principal"); temp5.relevancia=10;
    strcpy(temp6.titulo,"Seccion 2.1"); temp6.relevancia=3;
    strcpy(temp7.titulo,"Seccion 2.2"); temp7.relevancia=4;
    strcpy(temp8.titulo,"Seccion 1.1.1"); temp8.relevancia=4;
    strcpy(temp9.titulo,"Seccion 1.1.2"); temp9.relevancia=2;
    plantarArbolBinario(aux1,nullptr,temp8,nullptr);
    plantarArbolBinario(aux2,nullptr,temp9,nullptr);
    plantarArbolBinario(aux3,aux1,temp4,aux2);
    plantarArbolBinario(aux4,nullptr,temp5,nullptr);
    plantarArbolBinario(aux5,nullptr,temp6,nullptr);
    plantarArbolBinario(aux6,nullptr,temp7,nullptr);
    plantarArbolBinario(aux7,aux3,temp2,aux4);
    plantarArbolBinario(aux8,aux5,temp3,aux6);
    plantarArbolBinario(arbol,aux7,temp1,aux8);
    encontrarPrincipal(arbol);
    eliminaParteDerecha(arbol);cout<<endl;
    encontrarPrincipal(arbol);cout<<endl<<"Numero de nodos: "<<arbol.raiz->tamanio<<endl;
    return 0;
}

