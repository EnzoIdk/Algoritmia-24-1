/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 2 de julio de 2024, 08:39 PM
 */

#include "funcionesGrafo.h"


int main(int argc, char** argv) {
    
    vector<vector<int>> grafo={
        {1,2},//vertice 0 conectado con: 1, 2
        {2},//vertice 1 conectado con: 2
        {3,4},//vertice 2 conectado con: 3, 4
        {5},//vertice 3 conectado con: 5
        {5},//vertice 4 conectado con: 5
        {} //vertice 5 conectado con:
    };
    
    cout<<"Grafo: "<<endl;
    imprime(grafo);
    
    cout<<"Recorrido BFS(con cola): ";
    recorridoBFS(grafo,0);
    cout<<endl;
    
    cout<<"Recorrido DFS(con pila): ";
    recorridoDFS(grafo,0);
    cout<<endl;
    
    cout<<"Recorrido DFS Recursivo (la recursividad reemplaza la pila): ";
    recorridoDFSRecursivo(grafo,0);
    cout<<endl;
    
    return 0;
}

