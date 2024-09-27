/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani
 *
 * Created on 24 de junio de 2024, 11:09 AM
 */

#include <iostream>
#include <iomanip>
#include <climits>
#define V 5
using namespace std;

int minDistancia(int dist[],bool visitado[]){
    int indMin,min=INT_MAX;
    for(int i=0;i<V;i++){
        if(visitado[i]==false && dist[i]<=min){
            min=dist[i];
            indMin=i;
        }
    }
    return indMin;
}

//no tiene sentido porque al ser grafo no dirigido buscaría infinitamente
int maxDistancia(int dist[],bool visitado[]){
    int indMax,max=INT_MIN;
    for(int i=0;i<V;i++){
        if(!visitado[i] and dist[i]>=max){
            max=dist[i];
            indMax=i;
        }
    }
    return indMax;
}
//src: source
void dijkstra(int grafo[V][V],int src){
    int dist[V];
    bool visitado[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visitado[i]=false;
    }
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        int u=minDistancia(dist,visitado);
        visitado[u]=true;
        for(int j=0;j<V;j++){
            if(!visitado[j] && grafo[u][j] && dist[u]!=INT_MAX
                    && (dist[u]+grafo[u][j])<dist[j]){
                dist[j]=dist[u]+grafo[u][j];
            }
        }
    }
    //ruta mínima desde el comienzo hasta determinado vértice
    for(int i=0;i<V;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}

//no tiene sentido porque al ser grafo no dirigido buscaría infinitamente
void dijkstraInv(int grafo[V][V],int src){
    int dist[V];
    bool visitado[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MIN;
        visitado[i]=false;
    }
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        int u=maxDistancia(dist,visitado);
        visitado[u]=true;
        for(int j=0;j<V;j++){
            if(!visitado[j] && grafo[u][j] && dist[u]!=INT_MIN
                    && dist[u]+grafo[u][j]>dist[j]){
                dist[j]=dist[u]+grafo[u][j];
            }
        }
    }
    cout<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}

int rutaRecMin(int grafo[V][V],int ini,int fin){
    int min=INT_MAX;
    if(ini==fin) return 0;
    for(int i=ini+1;i<=fin;i++){
        if(grafo[ini][i]){
            int dist=grafo[ini][i]+rutaRecMin(grafo,i,fin);
            if(min>dist)
                min=dist;
        }
    }
    return min;
}

int rutaRecMax(int grafo[V][V],int ini,int fin){
    int max=INT_MIN;
    if(ini==fin) return 0;
    for(int i=ini+1;i<=fin;i++){
        if(grafo[ini][i]){
            int dist=grafo[ini][i]+rutaRecMax(grafo,i,fin);
            if(max<dist){
                max=dist;
            }
        }
    }
    return max;
}

int main(int argc, char** argv) {
    //grafo dirigido: se coloca 0 en la relación inversa
    //grafo no dirigido: se coloca el mismo valor (simetrico)
    int grafo[V][V]={
        {0,3,0,7,0},
        {3,0,4,2,0},
        {0,4,0,5,6},
        {7,2,5,0,4},
        {0,0,6,4,0}
    };
    dijkstra(grafo,0);
    dijkstraInv(grafo,0);
    cout<<"Ruta minima recursiva: "<<rutaRecMin(grafo,0,V-1)<<endl;
    cout<<"Ruta maxima recursiva: "<<rutaRecMax(grafo,0,V-1)<<endl;
    return 0;
}

