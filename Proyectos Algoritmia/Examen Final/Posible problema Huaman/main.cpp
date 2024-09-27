/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 5 de julio de 2024, 06:03 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <climits>
#define V 9
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

void dijkstra(int grafo[V][V],int src){
    int dist[V];
    bool visitado[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visitado[i]=false;
    }
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        int actual=distMin(dist,visitado);
        visitado[actual]=true;
        for(int j=0;j<V;j++){
            if(!visitado[j] and grafo[actual][j] and dist[actual]!=INT_MAX
                    and dist[actual]+grafo[actual][j]<dist[j]){
                dist[j]=dist[actual]+grafo[actual][j];
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<(char)('A'+i)<<' '<<dist[i]<<endl;
    }
}

int main(int argc, char** argv) {
       //A,B,C,D,E,F,G,H,I
    int grafo[V][V]={
        {0,5,0,0,0,0,4,0,6},
        {5,0,7,0,0,0,0,5,3},
        {0,7,0,4,0,0,0,1,0},
        {0,0,4,0,3,0,0,6,0},
        {0,0,0,3,0,5,0,4,0},
        {0,0,0,0,5,0,1,5,0},
        {4,0,0,0,0,1,0,3,5},
        {0,5,1,6,4,5,3,0,2},
        {6,3,0,0,0,0,5,2,0},
    };
    dijkstra(grafo,0);
    return 0;
}

