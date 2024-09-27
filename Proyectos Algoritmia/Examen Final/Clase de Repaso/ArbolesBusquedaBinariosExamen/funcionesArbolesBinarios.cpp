/* 
 * File:   funcionesArbolesBB.cpp
 * Author: ANA RONCAL
 * Created on 19 de septiembre de 2023, 10:46 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Partido.h"
#include "NodoCampeonato.h"
#include "ArbolCampeonato.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "funcionesArbolesBusquedaB.h"


void construir(struct ArbolCampeonato & arbol ){
    arbol.raiz = nullptr;
}

bool esNodoVacio(struct NodoCampeonato * nodo){
    return nodo == nullptr;
}

bool esArbolVacio( struct ArbolCampeonato arbol){
    return esNodoVacio(arbol.raiz);
}

struct NodoCampeonato * crearNuevoNodoArbol(struct NodoCampeonato * arbolIzquierdo, 
                                struct Partido partido, struct NodoCampeonato * arbolDerecho){
    struct NodoCampeonato * nuevoNodo = new struct NodoCampeonato;
    nuevoNodo->partido = partido;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinario(struct ArbolCampeonato & arbol, struct NodoCampeonato * arbolIzquierdo,
                         struct Partido partido, struct NodoCampeonato * arbolDerecho){
    
    struct NodoCampeonato * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo, partido, arbolDerecho);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(struct ArbolCampeonato & arbol, struct ArbolCampeonato arbolIzquierdo,
                         struct Partido partido, struct ArbolCampeonato arbolDerecho){
    
    struct NodoCampeonato * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo.raiz, partido, arbolDerecho.raiz);
    arbol.raiz = nuevoNodo;
}

struct Partido raiz(struct NodoCampeonato * nodo){
    if (esNodoVacio(nodo)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    return nodo->partido;
}

struct NodoCampeonato * hijoDerecho(struct ArbolCampeonato arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    return arbol.raiz->derecha;
}

struct  NodoCampeonato * hijoIzquierdo(struct ArbolCampeonato arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    
    return arbol.raiz->izquierda;
 }

void imprimeRaiz(struct ArbolCampeonato arbol){
    imprimeNodo(arbol.raiz);
}

void imprimeNodo(struct NodoCampeonato * nodo){
    cout<<setw(5)<<nodo->partido.local<<" / "<<nodo->partido.visitante<<endl;
    cout<<setw(5)<<nodo->partido.golesLocal;
    cout<<setw(5)<<nodo->partido.golesVisitante<<endl<<endl;
   
}

void recorrerEnOrdenRecursivo(struct NodoCampeonato * nodo, const char * nombre){
    if(not esNodoVacio(nodo)){
        recorrerEnOrdenRecursivo(nodo->izquierda, nombre);
        if(strcmp(nodo->partido.local, nombre) == 0 || strcmp(nodo->partido.visitante, nombre) == 0)
            imprimeNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha, nombre);
    }
}

/*En árbol, se lleva a cabo visitando el hijo izquierdo del nodo, luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerEnOrden(struct ArbolCampeonato arbol, const char * nombre){
    /*Imprime en orden*/
    if (not esArbolVacio(arbol)){
        recorrerEnOrdenRecursivo(arbol.raiz, nombre);
    }
    cout<<endl;
}

void recorrerEnOrdenRecursivoEstadisticas(struct NodoCampeonato * nodo, 
        const char * nombre, int & cantPartGanados, int & cantPartEmpatados, 
        int & cantPartPerdidos, int & golesAFavor, int & golesEnContra, 
        int & puntajeTotal){
    if(not esNodoVacio(nodo)){
        recorrerEnOrdenRecursivoEstadisticas(nodo->izquierda, nombre, 
                cantPartGanados, cantPartEmpatados, cantPartPerdidos,
                golesAFavor, golesEnContra, puntajeTotal);
        if(strcmp(nodo->partido.local, nombre) == 0 ){
            if(nodo->partido.golesLocal > nodo->partido.golesVisitante){
                cantPartGanados++;
                puntajeTotal += 3;
            }
            else
                if(nodo->partido.golesLocal < nodo->partido.golesVisitante)
                    cantPartPerdidos++;
                else{
                    cantPartEmpatados++;
                    puntajeTotal += 1;
                }
            golesAFavor = golesAFavor + nodo->partido.golesLocal;
            golesEnContra = golesEnContra + nodo->partido.golesVisitante;
            
        }
         if(strcmp(nodo->partido.visitante, nombre) == 0 ){
            if(nodo->partido.golesLocal < nodo->partido.golesVisitante){
                cantPartGanados++;
                puntajeTotal += 3;
            }
            else
                if(nodo->partido.golesLocal > nodo->partido.golesVisitante)
                    cantPartPerdidos++;
                else{
                    cantPartEmpatados++;
                    puntajeTotal += 1;
                }
            golesAFavor = golesAFavor + nodo->partido.golesVisitante;
            golesEnContra = golesEnContra + nodo->partido.golesLocal;
            
        }
        recorrerEnOrdenRecursivoEstadisticas(nodo->derecha, nombre, 
                cantPartGanados, cantPartEmpatados, cantPartPerdidos, 
                golesAFavor, golesEnContra, puntajeTotal);
    }
}

void recorrerEnOrdenEstadisticas(struct ArbolCampeonato arbol, const  char * nombre, 
         int & cantPartGanados, int & cantPartEmpatados, int & cantPartPerdidos,
         int & golesAFavor, int & golesEnContra, int & puntajeTotal){
    /*Imprime en orden*/
    if (not esArbolVacio(arbol)){
        recorrerEnOrdenRecursivoEstadisticas(arbol.raiz, nombre, cantPartGanados, 
                          cantPartEmpatados, cantPartPerdidos,
                          golesAFavor, golesEnContra, puntajeTotal);
    }
    cout<<endl;
}

