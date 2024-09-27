/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 3 de julio de 2024, 5:53 p.m.
 */

#include <iostream>
using namespace std;

#include "Cola.h"
#include "funcionesCola.h"

#define V 9

//int darEtiqueta(int grafo[V][V], int numVertices, int numEtiquetas, 
//        int * etiquetado, int nodo){
//    //ETIQUETAS DISPONIBLES
//    int arrEtiqs[numEtiquetas];
//    for(int i=1; i<=numEtiquetas; i++) arrEtiqs[i]=i;
//    
//    int etiqNodo=etiquetado[nodo], numEtiq=0;
//    arrEtiqs[etiqNodo]=0;
//    //VEAMOS SI HAY ETIQUETAS VALIDAS
//    for(int i=0; i<numVertices; i++){
//        if(grafo[nodo][i] and etiquetado[i]){
//            arrEtiqs[etiquetado[i]]=0;
//            numEtiq++;
//            if(numEtiq>numEtiquetas) return -1;
//        }        
//    }
//    //
//    for(int i=0; i<numVertices; i++){
//        if(numEtiq>numEtiquetas) return -1;
//        if(grafo[nodo][i]){
//            
//        }
//    }
//}

bool esValido(int etiq, int grafo[V][V], int nV, int * etiquetado, int nodo){
    int temp;
    for(int i=0; i<nV; i++){
        if(grafo[nodo][i]){
            if(etiq==etiquetado[i]) return false;
        }
    }
    return true;
}

int darEtiqueta(int grafo[V][V], int numVertices, int numEtiquetas, 
        int * etiquetado, int nodo){
    for(int i=1; i<=numEtiquetas; i++){
        if(esValido(i, grafo, numVertices, etiquetado, nodo)) return i;
    }
    return -1;
}

void etiquetarNodos(int grafo[V][V], int inic, int numVertices, 
        int numEtiquetas){    
    struct Cola cola;
    construir(cola);
    int etiquetado[numVertices]{}, indice, etiquetaDada;
    //ENCOLAMOS AL INICIAL Y LE DAMOS UNA ETIQUETA
    encolar(cola, inic);
    etiquetado[inic]=1;
    //RECORRAMOS CON BFS
    while(not esColaVacia(cola)){
        //OBTENEMOS UN NODO A EVALUAR
        indice=desencolar(cola);
        //SI NO TIENE ETIQUEDA, LE DAMOS UNA
        if(not etiquetado[indice]){
            etiquetaDada=darEtiqueta(grafo, numVertices, numEtiquetas, 
                    etiquetado, indice);
            if(etiquetaDada!=-1) etiquetado[indice]=etiquetaDada;
            else{
                cout<<"No hay solucion"<<endl;
                return;
            }
        }
        //ENCOLAMOS A SUS HIJOS
        for(int i=0; i<numVertices; i++){
            if(not etiquetado[i] and grafo[indice][i]) encolar(cola, i);
        }
    }
    //IMPRESION
    for(int i=0; i<numVertices; i++) cout<<i+1<<' ';
    cout<<endl;
    for(int i=0; i<numVertices; i++) cout<<etiquetado[i]<<' ';
}

int main(int argc, char ** argv) {
    
    int matriz[V][V]={
       //0, 1, 2, 3, 4, 5, 6, 7, 8
        {1, 2, 0, 6, 0, 0, 0, 0, 2}, //0
        {7, 1, 5, 2, 0, 0, 0, 0, 7}, //1
        {0, 3, 1, 2, 3, 8, 9, 7, 5}, //2
        {2, 7, 5, 1, 2, 0, 0, 0, 0}, //3
        {0, 0, 5, 3, 1, 4, 0, 0, 0}, //4
        {0, 0, 9, 0, 6, 1, 2, 0, 0}, //5
        {0, 0, 3, 0, 0, 7, 1, 4, 0}, //6
        {0, 0, 4, 0, 0, 0, 9, 1, 9}, //7
        {5, 3, 6, 0, 0, 0, 0, 4, 1}  //8
    };
    int etiquetas=4;
    
    etiquetarNodos(matriz, 0, V, etiquetas);
    
    return 0;
}

