/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 4 de julio de 2024, 04:35 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
#define V 9
using namespace std;

char vertices[7]={'a','b','c','d','e','f','g'};

//Breadth-First Search (en amplitud)
void recorrerBFS(int grafo[V][V],int ini,int n){
    struct Cola cola;
    construir(cola);
    bool visitado[V];
    for(int i=0;i<n;i++) visitado[i]=false; //inicializar
    encolar(cola,ini);
    visitado[ini]=true;
    while(!esColaVacia(cola)){
        int actual=desencolar(cola);
        cout<<vertices[actual]<<' ';
//        if(actual==1) break; //se detiene en 'b'
//        //sentido horario
//        for(int i=0;i<n;i++){
//            if(!visitado[i] and grafo[actual][i]){
//                encolar(cola,i);
//                visitado[i]=true;
//            }
//        }
        //sentido antihorario
        for(int i=n-1;i>=0;i--){
            if(!visitado[i] and grafo[actual][i]){
                encolar(cola,i);
                visitado[i]=true;
            }
        }
    }
    destruirCola(cola);
}

//Depth-First Search (búsqueda en profundidad)
void recorrerDFS(int grafo[V][V],int ini,int n){
    struct Pila pila;
    construir(pila);
    bool visitado[V];
    for(int i=0;i<n;i++) visitado[i]=false;
    apilar(pila,ini);
    while(!esPilaVacia(pila)){
        int actual=desapilar(pila);
        if(!visitado[actual]){
            cout<<vertices[actual]<<' ';
            visitado[actual]=true;
//            //sentido antihorario
//            for(int i=0;i<n;i++){
//                if(!visitado[i] and grafo[actual][i]){
//                    apilar(pila,i);
////                    visitado[i]=true;
//                }
//            }
            //esntido horario
            for(int i=n-1;i>=0;i--){
                if(!visitado[i] and grafo[actual][i]){
                    apilar(pila,i);
                }
            }
        }
    }
    destruirPila(pila);
}

void DFSRec(int grafo[V][V],int indice,bool visitado[V],int n){
    cout<<vertices[indice]<<' ';
    visitado[indice]=true;
    for(int i=0;i<n;i++){
        if(!visitado[i] and grafo[indice][i]){
            DFSRec(grafo,i,visitado,n);
        }
    }
}

void recorrerDFSRec(int grafo[V][V],int ini,int n){
    bool visitado[V];
    for(int i=0;i<n;i++) visitado[i]=false;
    DFSRec(grafo,ini,visitado,n);
}

int minDistancia(int dist[V],bool visitado[V],int n){
    int indMin,distMin=INT_MAX;
    for(int i=0;i<n;i++){
        if(!visitado[i] and dist[i]<=distMin){
            indMin=i;
            distMin=dist[i];
        }
    }
    return indMin;
}

void dijkstra(int grafo[V][V],int src,int n){
    int dist[V];
    bool visitado[V];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        visitado[i]=false;
    }
    dist[src]=0;
    for(int i=0;i<n-1;i++){
        int actual=minDistancia(dist,visitado,n);
        visitado[actual]=true;
        for(int j=0;j<n;j++){
            if(!visitado[j] and grafo[actual][j] and dist[actual]!=INT_MAX
                    and dist[actual]+grafo[actual][j]<dist[j]){
                dist[j]=dist[actual]+grafo[actual][j];
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<(char)('a'+i)<<' '<<dist[i]<<endl;
    }
}

bool esValido(int etiq,int matriz[V][V],int *etiquetado,int actual){
    for(int i=0;i<V;i++){
        if(matriz[actual][i] and etiq==etiquetado[i]) return false;
    }
    return true;
}

int darEtiqueta(int matriz[V][V],int numEtiquetas,int *etiquetado,int actual){
    for(int i=1;i<=numEtiquetas;i++){
        if(esValido(i,matriz,etiquetado,actual)) return i;
    }
    return -1;
}

void etiquetarNodos(int matriz[V][V],int ini,int numEtiquetas){
    struct Cola cola;
    construir(cola);
    int etiquetado[V]{},actual,etiquetaDada;
    encolar(cola,ini);
    etiquetado[ini]=1;
    while(!esColaVacia(cola)){
        actual=desencolar(cola);
        if(!etiquetado[actual]){
            etiquetaDada=darEtiqueta(matriz,numEtiquetas,etiquetado,actual);
            if(etiquetaDada!=-1) etiquetado[actual]=etiquetaDada;
            else{
                cout<<"No hay solucion"<<endl;
                return;
            }
        }
        for(int i=0;i<V;i++){
            if(!etiquetado[i] and matriz[actual][i]){
                encolar(cola,i);
            }
        }
    }
    destruirCola(cola);
    for(int i=0;i<V;i++) cout<<i+1<<' ';cout<<endl;
    for(int i=0;i<17;i++) cout.put('-');cout<<endl;
    for(int i=0;i<V;i++) cout<<etiquetado[i]<<' ';cout<<endl;
}

int main(int argc, char** argv) {
       //a b c d e f
    int grafo[V][V]={
        {0,0,1,1,0,0},
        {0,0,1,0,0,1},
        {1,1,0,0,1,0},
        {1,0,0,0,1,0},
        {0,0,1,1,0,1},
        {0,1,0,0,1,0},
    };
    int n=6;
    cout<<"Recorrido BFS: "<<endl;
    recorrerBFS(grafo,0,n);cout<<endl;
    cout<<"Recorrido DFS: "<<endl;
    recorrerDFS(grafo,0,n);cout<<endl;
    recorrerDFSRec(grafo,0,n);cout<<endl;
    dijkstra(grafo,0,n);cout<<endl;
    
    int grafo2[V][V]={
        {0,275,145,0,0,310,0},
        {0,0,0,150,0,0,0},
        {0,0,0,244,0,0,0},
        {0,0,0,0,175,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,250},
        {0,0,0,0,402,0,0},
    };
    int n2=7;
    cout<<"Recorrido BFS: "<<endl;
    recorrerBFS(grafo2,0,n2);cout<<endl;
    cout<<"Recorrido DFS: "<<endl;
    recorrerDFS(grafo2,0,n2);cout<<endl;
    dijkstra(grafo2,0,n2);cout<<endl;
    
    int matriz[V][V]={
        {1, 2, 0, 6, 0, 0, 0, 0, 2},
        {7, 1, 5, 2, 0, 0, 0, 0, 7},
        {0, 3, 1, 2, 3, 8, 9, 7, 5},
        {2, 7, 5, 1, 2, 0, 0, 0, 0},
        {0, 0, 5, 3, 1, 4, 0, 0, 0},
        {0, 0, 9, 0, 6, 1, 2, 0, 0},
        {0, 0, 3, 0, 0, 7, 1, 4, 0},
        {0, 0, 4, 0, 0, 0, 9, 1, 9},
        {5, 3, 6, 0, 0, 0, 0, 4, 1}
    };
    int etiquetas=4;
    etiquetarNodos(matriz,0,etiquetas);
    
    return 0;
}

