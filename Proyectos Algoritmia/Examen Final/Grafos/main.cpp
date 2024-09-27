/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 17 de junio de 2024, 10:31 AM
 */

#include <vector>
#include <iostream>
#define N 4
using namespace std;

/*
 * 
 * Grafos No Dirigido: No tienen flecha, pueden ir de un lado al otro y viceversa.
 * Grafos Dirigidos:  Todas sus aristas son dirigidas.
 * Un grafo con todos sus pares de vértices conectados por una arista es completo.
 * Pocas aristas relativas al número de vértices es esparso
 * Pocas aristas faltantes respecto al num de vértices es llamado denso
 * Las no dirigidas tienen simetría
 * Vector es un stl
 * Vector: arreglo dinámico
 * List: lista doblemente enlazada
 * Map: Tabla hash
 */

void llenaMatrizAdy(int grafo[][N],vector<vector<int>> &mapa,int nvertices){
    for(int i=0;i<nvertices;i++){
        vector<int> vertice;
        for(int j=0;j<nvertices;j++){
            vertice.push_back(grafo[i][j]);
        }
        mapa.push_back(vertice);
    }   
}

void crearListaAdy(int lvert[][2],int naristas,vector<vector<int>> &mapa){
    for(int i=0;i<naristas;i++){
        int a=lvert[i][0];
        int b=lvert[i][1];
        mapa[a].push_back(b);
    }
}

int main(int argc, char** argv) {
    int grafo[N][N]={
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0},
    };
    int nvertices=N;
    //vector de vectors :O
    //matriz dinámica
    vector<vector<int>> mapa;
    llenaMatrizAdy(grafo,mapa,nvertices);
    for(int i=0;i<nvertices;i++){
        for(int j=0;j<mapa[i].size();j++){
            cout<<mapa[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl<<"Lista de adyacencia: "<<endl;
    //Lista de Ady//
    int lvert[][2]={{0,1},{0,2},{1,0},{1,2},{1,3},{2,0},{2,1},{2,3},{3,1},{3,2}};
    int m=sizeof(lvert)/sizeof(lvert[0]);
    vector<vector<int>> mapa2(nvertices); //se crean las 4 filas
    crearListaAdy(lvert,m,mapa2);
    for(int i=0;i<nvertices;i++){
        cout<<i<<" -> ";
        for(int j=0;j<mapa2[i].size();j++){
            cout<<mapa2[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

