/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"

int servidor[7][7]={
        {0,0,0,0,0,0,0},
        {10,0,20,30,0,20,40},
        {0,0,0,0,0,100,0},
        {0,0,0,0,0,80,0},
        {50,10,5,10,0,100,4},
        {100,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
};

void apilarRec(struct Pila &pila,int i,int n){
    if(i==n) return;
    apilar(pila,i);
    apilarRec(pila,i+1,n);
}

int encontrarPosible(struct Pila &pila){
    if(longitud(pila)==1){
        return desapilar(pila);
    }
    int x=desapilar(pila);
    int y=desapilar(pila);
    if(servidor[x][y]!=0) apilar(pila,x);
    else apilar(pila,y);
    encontrarPosible(pila);
}

void verificarPosible(int i,int n,int &posible,int &mayor){
    if(i==n) return;
    if((servidor[posible][i]==0 and i!=posible) or servidor[i][posible]){
        posible=-1;
        return;
    }
    if(mayor<servidor[posible][i]) mayor=servidor[posible][i];
    verificarPosible(i+1,n,posible,mayor);
}

int buscarSkyNerd(int n,int &mayor){
    struct Pila pila;
    construir(pila);
    apilarRec(pila,0,n);
    int posible=encontrarPosible(pila);
    destruirPila(pila);
    mayor=-1;
    verificarPosible(0,n,posible,mayor);
    return posible;
}

int main(int argc, char** argv) {
    int n=7,mayor;
    int skynerd=buscarSkyNerd(n,mayor);
    if(skynerd!=-1){
        cout<<"Se encontro Skynerd en el servidor "<<skynerd+1<<endl;
        cout<<"Maximo de paquetes enviados por Skynerd: "<<mayor<<endl;
    }
    else cout<<"Skynerd no esta en la red"<<endl;
    return 0;
}

