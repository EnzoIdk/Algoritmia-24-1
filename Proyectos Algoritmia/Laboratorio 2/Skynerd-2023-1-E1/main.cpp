/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 15 de abril de 2024, 11:24
 */

#include <cstdlib>
#include <iostream>
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
#define N 7

using namespace std;

/*
 * 
 */

int maximo=0;

int estaSkynerd(int servidores[N][N],int n){
    struct Pila pila;
    int emisor, receptor, skynerd;
    construir(pila);
    for (int i=0; i<n; i++){
        apilar(pila,i);
    }
    while (longitud(pila)>1){
        emisor = desapilar(pila);
        receptor = desapilar(pila);
        if (servidores[emisor][receptor]!=0){
            apilar(pila,emisor);
        }
        else{
           apilar(pila,receptor); 
        }
    }
    skynerd = desapilar(pila);
    /*Voy a validar que en realidad sea skynerd*/
    for (int i=0; i<n; i++){
        if (i!=skynerd && (servidores[i][skynerd]!=0 || servidores[skynerd][i]==0)){
            skynerd=-1;
        }
        if (servidores[skynerd][i]>maximo){
            maximo = servidores[skynerd][i];
        }
    }
    return skynerd;
}

int main(int argc, char** argv) {
    int servidores[N][N] = {{0,10,10,10,0,10,10},
                            {10,0,20,30,0,20,40},
                            {0,0,0,0,0,100,0},
                            {0,0,0,0,0,80,0},
                            {50,10,5,10,0,100,4},
                            {100,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0}};
    int n=7;
    int skynerd = estaSkynerd(servidores,n);
    if (skynerd!=-1){
        cout << "Skynerd ha sido detectado en el servidor " << skynerd+1 << endl;
        cout << "Maximo de paquetes enviados por skynerd: " << maximo;
    }
    else {
        cout << "Skynerd no está en la red";
    }
    return 0;
}

