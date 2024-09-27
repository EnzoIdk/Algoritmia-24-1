/* 
 * File:   funcionesArbolesBB.cpp
 * Author: ANA RONCAL
 * Created on 24 de septiembre de 2023, 10:36 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "NodoPuntaje.h"
#include "Lista.h"
#include "Partido.h"
#include "ArbolCampeonato.h"
#include "NodoCampeonato.h"
#include "funcionesArbolesBusquedaB.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "funcionesLista.h"

void construir(struct ArbolBinarioBusqueda & arbol){
    construir(arbol.arbolBinario);
}

bool esArbolVacio(struct ArbolBinarioBusqueda  arbol){
    esArbolVacio(arbol.arbolBinario);
}

void plantarArbolBB(struct NodoCampeonato *& arbol, 
                         struct NodoCampeonato * arbolIzquierdo, struct Partido partido, 
                         struct NodoCampeonato * arbolDerecho){
    
    struct NodoCampeonato * nuevoNodo = new struct NodoCampeonato;
    nuevoNodo->partido = partido;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    arbol = nuevoNodo;
}

void insertarRecursivo(struct NodoCampeonato *& raiz, struct Partido partido){
    char cadena1[15], cadena2[15];
    cadena1[0] = '\0', cadena2[0] = '\0';
    if(raiz == nullptr)
        plantarArbolBB(raiz, nullptr, partido, nullptr);
    else{ //tengo que concatenar para la comparación
       
        strcat(cadena1, raiz->partido.local);
        strcat(cadena1, raiz->partido.visitante);
        strcat(cadena2, partido.local);
        strcat(cadena2, partido.visitante);
        if (strcmp(cadena1, cadena2) >= 1)
            insertarRecursivo(raiz->izquierda, partido);
        else
            insertarRecursivo(raiz->derecha, partido);
    }
}

void insertar(struct ArbolBinarioBusqueda & arbol, struct Partido partido){
    insertarRecursivo(arbol.arbolBinario.raiz, partido);
}

void mostrarPartidosEquipo(struct ArbolBinarioBusqueda arbol, const char * nombre){
    recorrerEnOrden(arbol.arbolBinario, nombre);
}

void cargarPartidos(const char * nombreArch, struct ArbolBinarioBusqueda & arbolBB){
    
    ifstream arch(nombreArch, ios::in);
    if(not arch.is_open()){
        cout<<"Error en el archivo "<<endl;
        exit(1);
    }
    char local[15], visitante[15];
    int golesLocal, golesVisitante;
    struct Partido partido;
    while(not arch.eof()){
        arch>>local;
        if(arch.eof()) break;
        arch>>golesLocal>>visitante>>golesVisitante;
        strcpy(partido.local, local);
        partido.golesLocal = golesLocal;
        strcpy(partido.visitante, visitante);
        partido.golesVisitante = golesVisitante;
        insertar(arbolBB, partido);
        
    }
   
}

void obtenerEstadisticaEquipo(struct ArbolBinarioBusqueda arbolBB, const char * nombre, 
         int & cantPartGanados, int & cantPartEmpatados, int & cantPartPerdidos,
         int & golesAFavor, int & golesEnContra, int & puntajeTotal){
    cantPartGanados = 0, cantPartEmpatados = 0,cantPartPerdidos = 0;
    golesAFavor = 0,golesEnContra = 0, puntajeTotal = 0;
    recorrerEnOrdenEstadisticas(arbolBB.arbolBinario, nombre, cantPartGanados,
                    cantPartEmpatados, cantPartPerdidos, golesAFavor, 
                    golesEnContra, puntajeTotal);
}

void elaborarTablaPosiciones(const char * alfa, const char * beta, const char * gama,
        const char *  kapa, struct ArbolBinarioBusqueda arbolBB, struct Lista & lista){
    int cantPartGanados, cantPartEmpatados,cantPartPerdidos;
    int golesAFavor,golesEnContra, puntajeTotal;
   
    obtenerEstadisticaEquipo(arbolBB, alfa, cantPartGanados, cantPartEmpatados,
            cantPartPerdidos, golesAFavor, golesEnContra, puntajeTotal);
    insertarEnOrden(lista, alfa, puntajeTotal);
    obtenerEstadisticaEquipo(arbolBB, beta, cantPartGanados, cantPartEmpatados,
            cantPartPerdidos, golesAFavor, golesEnContra, puntajeTotal);
    insertarEnOrden(lista, beta, puntajeTotal);
    obtenerEstadisticaEquipo(arbolBB, gama, cantPartGanados, cantPartEmpatados,
            cantPartPerdidos, golesAFavor, golesEnContra, puntajeTotal);
    insertarEnOrden(lista, gama, puntajeTotal);
    obtenerEstadisticaEquipo(arbolBB, kapa, cantPartGanados, cantPartEmpatados,
            cantPartPerdidos, golesAFavor, golesEnContra, puntajeTotal);
    insertarEnOrden(lista, kapa, puntajeTotal);
}