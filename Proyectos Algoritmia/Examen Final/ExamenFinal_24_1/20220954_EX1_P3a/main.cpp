/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 6 de julio de 2024, 08:06 AM
 */

#include <iostream>
#include <iomanip>
#include <climits>
#define V 6
using namespace std;

int distMin(int dist[V],bool visitado[V]){
    int min=INT_MAX,indMin;
    for(int i=0;i<V;i++){
        if(!visitado[i] and dist[i]<=min){
            min=dist[i];
            indMin=i;
        }
    }
    return indMin;
}

void dijkstra(int grafo[V][V],int niveles[V][V],int src){
    int dist[V];
    bool visitado[V];
    int cantNodos[V]{};
    int sumaNiveles[V]{};
    //inicializando
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visitado[i]=false;
    }
    //origen
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        int actual=distMin(dist,visitado);
        //marcando el actual como visitado
        visitado[actual]=true;
        for(int j=0;j<V;j++){
            if(!visitado[j] and grafo[actual][j] and dist[actual]!=INT_MAX
                    and dist[actual]+grafo[actual][j]<dist[j]){
                dist[j]=dist[actual]+grafo[actual][j];
                sumaNiveles[j]=sumaNiveles[actual]+niveles[actual][j];
                cantNodos[j]=cantNodos[actual]+1;
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<"Servidor: "<<i+1<<" Latencia: "<<dist[i]<<" Seguridad Promedio: ";
        if(sumaNiveles[i]==0) cout<<0<<endl;
        else cout<<(double)sumaNiveles[i]/cantNodos[i]<<endl;
    }
}

int main(int argc, char** argv) {
    int matrizAdy1[V][V]={
        {0,0,0,3,0,0},
        {0,0,1,0,3,0},
        {0,1,0,2,5,7},
        {3,0,2,0,7,0},
        {0,3,5,7,0,2},
        {0,0,7,0,2,0},
    };
    int matrizAdy2[V][V]={
        {0,0,0,3,0,0},
        {0,0,3,0,3,0},
        {0,3,0,2,5,7},
        {3,0,2,0,7,0},
        {0,3,5,7,0,2},
        {0,0,7,0,2,0},
    };
    int niveles[V][V]={
        {0,0,0,9,0,0},
        {0,0,7,0,8,0},
        {0,7,0,7,5,7},
        {9,0,7,0,7,0},
        {0,8,5,7,0,9},
        {0,0,7,0,9,0},
    };
    cout<<"Resultados matriz 1: "<<endl;
    dijkstra(matrizAdy1,niveles,0);
    cout<<endl<<"Resultados matriz 2: "<<endl;
    dijkstra(matrizAdy2,niveles,0);
    return 0;
}

