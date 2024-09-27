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
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"

using namespace std;

#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

/*función recursiva que devuelve el arbol_resultado (su raiz)*/
struct NodoArbol *aplicar_arbol(struct NodoArbol *pArbolBB,struct NodoArbol *pArbol1){
    if(esNodoVacio(pArbolBB)) return nullptr;
    struct NodoArbol *izq,*der,*parbol2;
    izq=aplicar_arbol(pArbolBB->izquierda,pArbol1->izquierda);
    der=aplicar_arbol(pArbolBB->derecha,pArbol1->derecha);
    int elemento=pArbolBB->elemento+numeroNodosRecursivo(pArbol1)-numeroHojasRecursivo(pArbol1);
    parbol2=crearNuevoNodoArbol(izq,elemento,der);
    return parbol2;
}

bool verificarABB(struct NodoArbol *parbol){
    if(esNodoVacio(parbol)) return true;
    else{
        bool izq=verificarABB(parbol->izquierda);
        bool der=verificarABB(parbol->derecha);
        bool cumple=true;
        if(!esNodoVacio(parbol->izquierda) and !esNodoVacio(parbol->derecha)){
            cumple=parbol->elemento>parbol->izquierda->elemento and
                    parbol->elemento<parbol->derecha->elemento;
        }
        else if(!esNodoVacio(parbol->izquierda)) cumple=parbol->elemento>parbol->izquierda->elemento;
        else if(!esNodoVacio(parbol->derecha)) cumple=parbol->elemento<parbol->derecha->elemento;
        return izq and der and cumple;
    }
}

bool detectar_anomalia(struct ArbolBinario arbol1){
    int sumaNodos=sumarNodos(arbol1);
    bool estado=verificarABB(arbol1.raiz);
    if(sumaNodos%2==0 and estado) return false;
    else return true;
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol_paquetes;
    struct ArbolBinario arbol_sistema,arbol_resultado,aux1,aux2,aux3,aux4;
    construir(arbol_paquetes);
    construir(arbol_sistema);
    construir(arbol_resultado);
    insertar(arbol_paquetes,6);
    insertar(arbol_paquetes,3);
    insertar(arbol_paquetes,9);
    plantarArbolBinario(aux1,nullptr,2,nullptr);
    plantarArbolBinario(aux2,nullptr,3,nullptr);
    plantarArbolBinario(aux3,aux1,7,aux2);
    plantarArbolBinario(aux4,nullptr,8,nullptr);
    plantarArbolBinario(arbol_sistema,aux3,1,aux4);
    cout<<"Arbol_paquetes en orden: ";
    enOrden(arbol_paquetes);
    cout<<endl;
    cout<<"Arbol_sistema en orden: ";
    recorrerEnOrden(arbol_sistema);
    cout<<endl;
//    cout<<numeroHojas(arbol_sistema);cout<<endl;
//    cout<<numeroNodos(arbol_sistema);cout<<endl;
    arbol_resultado.raiz=aplicar_arbol(arbol_paquetes.arbolBinario.raiz,arbol_sistema.raiz);
    cout<<"Arbol_resultado en orden: ";
    recorrerEnOrden(arbol_resultado);
    cout<<endl;
    if(detectar_anomalia(arbol_resultado)) cout<<"Anomalia detectada"<<endl;
    else cout<<"Sin eventos sospechosos"<<endl;
    
    return 0;
}

