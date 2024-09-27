/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 * FUERZA BRUTA: se hace con el cargabin aea
 * Created on 7 de abril de 2024, 03:48 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>    
#include <cmath>

using namespace std;

void cargaBin(int num,int n,int *cromo){
    int i=0;
    for(int i=0;i<n;i++) cromo[i]=0;
    while(num>0){
        cromo[i]=num%2;
        num/=2;
        i++;
    }
}

/*cromo*/

int main(int argc, char** argv) {
    int pesoMax=100,n=4;
    int pesos[n*n]={20,20,20,20,10,30,10,30,10,10,10,10,15,15,15,15};
    int valores[n*n]={10,10,10,50,80,10,10,20,20,20,20,20,50,50,50,50};
    int cromo[n*n]{}; //los cromosomas se guardan con 0s y 1s
    int pesoCromo,valorCromo,mayorValor=0,solucion;
    int combinaciones=pow(2,n*n);
    /*recorriendo todas las opciones*/
    for(int i=0;i<combinaciones;i++){
        cargaBin(i,n*n,cromo);
        /*inicializando para cada iteracion*/
        pesoCromo=valorCromo=0;
        for(int j=0;j<n*n;j++){
            if(cromo[j]==1){
                pesoCromo+=pesos[j];
                valorCromo+=valores[j];
            }
        }
        if(pesoCromo<=pesoMax and valorCromo>mayorValor){
            solucion=i;
            mayorValor=valorCromo;
        }
    }
    cargaBin(solucion,n*n,cromo);
    cout<<"Valor maximo: "<<mayorValor<<endl;
    cout<<"PESOS (toneladas): "<<endl;
    for(int i=0;i<n*n;i++){
        if(cromo[i]==1) cout<<pesos[i]<<' ';
        else cout<<"00 ";
        if((i+1)%n==0) cout<<endl; /*salto de linea en los multiplos de 4*/
    }
    cout<<endl<<"VALORES (Miles de $): "<<endl;
    for(int i=0;i<n*n;i++){
        if(cromo[i]==1) cout<<valores[i]<<' ';
        else cout<<"00 ";
        if((i+1)%n==0) cout<<endl; /*salto de linea en los multiplos de 4*/
    }
    cout<<endl;
    return 0;
}

