/* 
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 23 de junio de 2024, 02:46 PM
 */

#include <iostream>
#include <limits.h>

using namespace std;

#define V 5

int mindistancia(int dist[], bool visitado[])
{
    int indmin,min = INT_MAX;

    for (int i = 0; i < V; i++)
        if (visitado[i] == false && dist[i] <= min){
            min = dist[i];
            indmin = i;
        }    
    return indmin;
}

void imprimesolucion(int *dist)
{
    for (int i = 0; i < V; i++)
        cout << i << " " << dist[i] << endl;
}

void dijkstra(int grafo[V][V], int src)
{
    int dist[V]; 
    bool visitado[V];
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        visitado[i] = false;
    }    
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = mindistancia(dist, visitado);
        visitado[u] = true;
        for (int i = 0; i < V; i++)
            if (!visitado[i] && grafo[u][i]
                && dist[u] != INT_MAX
                && dist[u] + grafo[u][i] < dist[i])
                dist[i] = dist[u] + grafo[u][i];
    }
    imprimesolucion(dist);
}

int recursivo(int grafo[V][V],int ini,int fin){
    int min=INT_MAX;
    
    if(ini==fin)
        return 0;
    for(int i=ini+1;i<=fin;i++){
        if(grafo[ini][i]){
            int dist = grafo[ini][i]+recursivo(grafo,i,fin);
            if(min>dist)
                min = dist;
        }    
    }
    return min;

}

int main()
{
    int grafo[V][V] = { { 0, 3, 0, 7, 0 },
                        { 3, 0, 4, 2, 0 },
                        { 0, 4, 0, 5, 6 },
                        { 7, 2, 5, 0, 4 },
                        { 0, 0, 6, 4, 0 } };


    dijkstra(grafo, 0);
  
    cout << endl <<"Recursivo;" <<recursivo(grafo,0,4);

    return 0;
}



