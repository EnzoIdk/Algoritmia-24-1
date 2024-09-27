/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 26 de abril de 2024, 03:58 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
#define N 7

using namespace std;

int maximo=0;

int estaSkynerd(int servidores[N][N],int n){
    struct Pila pila;
    int emisor,receptor,skynerd;
    construir(pila);
    for(int i=0;i<n;i++) apilar(pila,i); /*pila auxiliar para resolver el problema*/
//    [6,5,4,3,2,1,0]
    while(longitud(pila)>1){
        emisor=desapilar(pila);
        receptor=desapilar(pila);
        /*va probando en toda la columna menos en él mismo*/
        if(servidores[emisor][receptor]!=0) apilar(pila,emisor); /*si no cumple, se cambia de columna*/
        else apilar(pila,receptor); /*si cumple, sigue probando en la columna*/
    }
    skynerd=desapilar(pila);
    if(servidores[skynerd][skynerd]!=0) skynerd=-1;
    for(int i=0;i<n;i++){
        if(i!=skynerd and servidores[i][skynerd]!=0) skynerd=-1;
        if(servidores[skynerd][i]>maximo) maximo=servidores[skynerd][i];
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
    int skyNerd=estaSkynerd(servidores,n);
    if(skyNerd!=-1){
        cout<<"Se encontro Skynerd en el servidor: "<<skyNerd+1<<endl;
        cout<<"Maximo de paquetes enviados por Skynerd: "<<maximo<<endl;
    }
    else cout<<"Skynerd no esta en la red"<<endl;
    return 0;
}

