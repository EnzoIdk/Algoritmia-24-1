/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 3 de julio de 2024, 10:47 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>        
#include "Lista.h"
#include "Nodo.h"
#include "ArbolBinarioBusqueda.h"
#include "ArbolBinario.h"
#include "Partido.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funciones.h"
using namespace std;

void cargarPartidos(const char *nombArch,struct ArbolBinarioBusqueda &arbol){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    struct Partido aux;
    while(true){
        arch>>aux.local;
        if(arch.eof()) break;
        arch>>aux.golesLocal>>aux.visitante>>aux.golesVisitante;
        arch.get();
        insertar(arbol,aux);
    }
}

void recorrerEnOrdenRec(struct NodoArbol *nodo,const char *equipo){
    if(esNodoVacio(nodo)) return;
    recorrerEnOrdenRec(nodo->izquierda,equipo);
    if(strcmp(nodo->partido.local,equipo)==0 or 
            strcmp(nodo->partido.visitante,equipo)==0){
        imprimeNodo(nodo);
        cout<<endl;
    }
    recorrerEnOrdenRec(nodo->derecha,equipo);
}

void recorrerEnOrden(const struct ArbolBinario arbol,const char *equipo){
    if(!esArbolVacio(arbol)) recorrerEnOrdenRec(arbol.raiz,equipo);
}

void mostrarPartidosEquipo(struct ArbolBinarioBusqueda arbol,const char *equipo){
    cout<<endl;
    recorrerEnOrden(arbol.arbolBinario,equipo);
    cout<<endl;
}

void obtenerRec(struct NodoArbol *nodo,const char *equipo,int &cantW,
        int &cantD,int &cantL,int &golesFavor,int &golesContra,int &puntos){
    if(esNodoVacio(nodo)) return;
    obtenerRec(nodo->izquierda,equipo,cantW,cantD,cantL,golesFavor,golesContra,puntos);
    if(strcmp(nodo->partido.local,equipo)==0){
        golesFavor+=nodo->partido.golesLocal;
        golesContra+=nodo->partido.golesVisitante;
        if(nodo->partido.golesLocal>nodo->partido.golesVisitante){
            cantW++;
            puntos+=3;
        }
        else if(nodo->partido.golesLocal==nodo->partido.golesVisitante){
            cantD++;
            puntos++;
        }
        else cantL++;
    }
    else if(strcmp(nodo->partido.visitante,equipo)==0){
        golesFavor+=nodo->partido.golesVisitante;
        golesContra+=nodo->partido.golesLocal;
        if(nodo->partido.golesLocal<nodo->partido.golesVisitante){
            cantW++;
            puntos+=3;
        }
        else if(nodo->partido.golesLocal==nodo->partido.golesVisitante){
            cantD++;
            puntos++;
        }
        else cantL++;
    }
    obtenerRec(nodo->derecha,equipo,cantW,cantD,cantL,golesFavor,golesContra,puntos);
}

void obtenerEstadisticaEquipo(struct ArbolBinarioBusqueda arbol,const char *equipo,int &puntos){
    int cantW=0,cantD=0,cantL=0,golesFavor=0,golesContra=0;
    obtenerRec(arbol.arbolBinario.raiz,equipo,cantW,cantD,cantL,golesFavor,
            golesContra,puntos);
    cout<<"Cantidad de victorias: "<<cantW<<endl;
    cout<<"Cantidad de empates:   "<<cantD<<endl;
    cout<<"Cantidad de derrotas:  "<<cantL<<endl;
    cout<<"Goles a favor:         "<<golesFavor<<endl;
    cout<<"Goles en contra:       "<<golesContra<<endl<<endl;
}

void insertarEnOrden(struct Lista &lista,char *equipo,int puntos){
    struct Nodo *rec=lista.cabeza,*ant=nullptr;
    struct Nodo *nuevoNodo=new Nodo;
    strcpy(nuevoNodo->equipo,equipo);
    nuevoNodo->elemento=puntos;
    while(rec){
        if(rec->elemento < puntos) break; 
        ant=rec;
        rec=rec->siguiente;
    }
    nuevoNodo->siguiente=rec;
    if(ant!=nullptr) ant->siguiente=nuevoNodo;
    else lista.cabeza=nuevoNodo;
}

void elaborarTablaPosiciones(struct ArbolBinarioBusqueda arbol,
        struct Lista &lista,char nombreEquipos[4][15],int n){
    construir(lista);
    for(int i=0;i<n;i++){
        int puntos=0;
        cout<<"Partidos del equipo: "<<nombreEquipos[i]<<endl;
        mostrarPartidosEquipo(arbol,nombreEquipos[i]);
        obtenerEstadisticaEquipo(arbol,nombreEquipos[i],puntos);
        insertarEnOrden(lista,nombreEquipos[i],puntos);
    }
    
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    struct Lista lista;
    char nombreEquipos[4][15]={"ALFA","BETA","GAMA","KAPA"};
    int n=4;
    construir(arbol);
    cargarPartidos("campeonato.txt",arbol);
//    mostrarPartidosEquipo(arbol,"ALFA");
//    int puntos=0;
//    obtenerEstadisticaEquipo(arbol,"ALFA",puntos);
//    cout<<puntos<<endl;
    elaborarTablaPosiciones(arbol,lista,nombreEquipos,n);
    imprime(lista);
    return 0;
}

