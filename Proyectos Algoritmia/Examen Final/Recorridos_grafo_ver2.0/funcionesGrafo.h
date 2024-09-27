/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesGrafo.h
 * Author: Usuario
 *
 * Created on 2 de julio de 2024, 08:46 PM
 */

#ifndef FUNCIONESGRAFO_H
#define FUNCIONESGRAFO_H

#include <vector>
#include <iterator>
#include <iostream>

#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"

using namespace std;

void imprime(const vector<vector<int>> &grafo){
    int i=0;
    for(vector<int> v: grafo){
        cout<<i<<" : ";
        for(int i: v)
            cout<<i<<' ';
        cout<<endl;
        i++;
    }
}

void recorridoBFS(const vector<vector<int>> &grafo,int inicio){
    Cola cola;
    construir(cola);
    int n=grafo.size();
    bool visitados[n]={false};
    /***************************/
    
    encolar(cola,inicio);
    visitados[inicio]=true;
    
    while(not esColaVacia(cola)){
        int verticeActual=desencolar(cola);
        
        cout<<verticeActual<<' ';
        
        for(int verticeVecino: grafo[verticeActual]){
            if(not visitados[verticeVecino]){
                encolar(cola,verticeVecino);
                visitados[verticeVecino]=true;
            }
        }
    }
}

void recorridoDFS(const vector<vector<int>> &grafo,int inicio){
    Pila pila;
    construir(pila);
    int n=grafo.size();
    bool visitados[n]={false};
    /***************************/
    
    apilar(pila,inicio);
    
    while(not esPilaVacia(pila)){
        int verticeActual=desapilar(pila);
        
        if(not visitados[verticeActual]){
            visitados[verticeActual]=true;
            cout<<verticeActual<<' ';
            
            for(int verticeVecino: grafo[verticeActual]){// para que salga en orden en esta parte habria que recorrer el grafo al reves usando rbegin(), rend() y auto it
                if(not visitados[verticeVecino])
                    apilar(pila,verticeVecino);
            }
        }
    }
}

void recorridoDFSRecursivo_(const vector<vector<int>> &grafo,int verticeActual,
        bool *visitados){
    visitados[verticeActual]=true;
    
    cout<<verticeActual<<' ';
    
    for(int verticeVecino: grafo[verticeActual]){
        if(not visitados[verticeVecino])
            recorridoDFSRecursivo_(grafo,verticeVecino,visitados);
    }
}

void recorridoDFSRecursivo(const vector<vector<int>> &grafo,int inicio){
    int n=grafo.size();
    bool visitados[n]={false};
    
    recorridoDFSRecursivo_(grafo,inicio,visitados);
}
#endif /* FUNCIONESGRAFO_H */

