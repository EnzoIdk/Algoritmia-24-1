/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 30 de septiembre de 2023, 10:47 AM
 */

#include <iostream>

using namespace std;

#define N 5

/*
 * 
 */

int HallarMaximo(int *asientos,int ini,int fin){
    
    if(ini==fin)return ini;
    
    int izq,der,medio;
    medio=(ini+fin)/2;
    
    izq=HallarMaximo(asientos,ini,medio);
    der=HallarMaximo(asientos,medio+1,fin);
    if(asientos[izq]<asientos[der])return der;
    else return izq;
    
}


void RevisarFilas(int asientos[][N],int n,int m){
    
    int maxPrecio;
    
    for(int i=0;i<n;i++){
        maxPrecio=HallarMaximo(asientos[i],0,m-1);
        cout<<"En la fila "<<i+1<<", el pasajero del asiento "<<maxPrecio+1
         <<" tiene el bocadito mas caro que";
        if(maxPrecio==0 or m-1)cout<<"sus 2 vecinos"<<endl;
        else cout<<"su vecino"<<endl;

    }
    
}




int main(int argc, char** argv) {

    int n=8,m=5;
    int asientos[][N]={{1,2,3,2,1},
                       {2,3,2,2,1},
                       {1,2,2,5,3},
                       {2,5,3,3,1},
                       {2,2,3,2,1},
                       {1,2,3,2,1},
                       {3,5,2,2,1},
                       {2,3,2,1,1}};
    
    RevisarFilas(asientos,n,m);
    
    
    
    return 0;
}

