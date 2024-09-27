/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"

int skyNerd[7][7]={
    {0,10,10,10,0,10,10},
    {10,0,20,30,0,20,40},
    {0,0,0,0,0,100,0},
    {0,0,0,0,0,80,0},
    {50,10,5,10,1,100,4},
    {100,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};

int hallarSkynerd(struct Pila &pila,int n){
    int x,y,posible;
    while(longitud(pila)>1){
        x=desapilar(pila);
        y=desapilar(pila);
        if(skyNerd[x][y]==0) apilar(pila,y);
        else apilar(pila,x);
    }
    posible=desapilar(pila);
    if(skyNerd[posible][posible]!=0) return -1; /*no se envía a sí mismo*/
    for(int i=0;i<n;i++){
        if(i!=posible and (skyNerd[i][posible]!=0 and skyNerd[posible][i]==0)){
            return -1;
        }
    }
    return posible+1;
}

void pasaPila(struct Pila &pila1,struct Pila &pila2,int n){
    int aux;
    if(esPilaVacia(pila1)) return;
    aux=desapilar(pila1);
    pasaPila(pila1,pila2,n-1);
    apilar(pila2,aux);
}

int main(int argc, char** argv) {
    /*algoritmo del descarte*/
//    struct Pila pila;
//    int n=7;
//    construir(pila);
//    for(int i=0;i<n;i++) apilar(pila,i);
//    int pos=hallarSkynerd(pila,n);
//    if(pos!=-1) cout<<"Se encontro Skynerd en el servidor "<<pos<<endl;
//    else cout<<"Skynerd no esta en la red"<<endl;
    struct Pila pila1,pila2;
    construir(pila1);
    construir(pila2);
    apilar(pila1,1);
    apilar(pila1,2);
    apilar(pila1,3);
    apilar(pila1,4);
    cout<<"Pila 1: ";
    imprimir(pila1);
    pasaPila(pila1,pila2,4);
    cout<<"Pila 2: ";
    imprimir(pila2);
    return 0;
}

