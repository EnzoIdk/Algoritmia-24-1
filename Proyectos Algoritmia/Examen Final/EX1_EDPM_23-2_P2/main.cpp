/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 4 de julio de 2024, 12:25 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#define V 7
using namespace std;

int minDistancia(double dist[V],bool visitado[V]){
    double min=9999;
    int indMin;
    for(int i=0;i<V;i++){
        if(!visitado[i] and dist[i]<=min){
            min=dist[i];
            indMin=i;
        }
    }
    return indMin;
}

void dijkstra(double grafo[][V],int src){
    double dist[V];
    bool visitado[V];
    //inicializando arreglos
    for(int i=0;i<V;i++){
        dist[i]=9999;
        visitado[i]=false;
    }
    //inicializando punto de partida
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        int indMin=minDistancia(dist,visitado);
        visitado[indMin]=true;
        for(int j=0;j<V;j++){
            if(!visitado[j] and grafo[indMin][j] and dist[indMin]!=9999
                    and dist[indMin]+grafo[indMin][j]<dist[j]){
                dist[j]=dist[indMin]+grafo[indMin][j];
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<(char)('A'+i)<<' '<<dist[i]<<endl;
    }
}

int main(int argc, char** argv) {
    //A B C D E F G
    double grafo[V][V]={
        {0,275.3,145.7,0,0,310.25,0},
        {0,0,0,150.1,0,0,0},
        {0,0,0,244.47,0,0,0},
        {0,0,0,0,175.5,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,250.5},
        {0,0,0,0,402,0,0},
    };
    
    dijkstra(grafo,0);
    return 0;
}

