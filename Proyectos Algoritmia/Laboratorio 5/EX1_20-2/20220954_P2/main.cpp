/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 13 de junio de 2024, 08:58 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

//cuantos dias seguidos anteriores tuvieron menos contagiados
void calculaFrecuencia(int *cifras,int n){
    struct Pila pila;
    int valor,intervalo,solu[8];
    construir(pila);
    for(int i=0;i<n;i++){
        solu[i]=1;
        if(i==0){
            apilar(pila,cifras[i]*100+1); 
        }
        else{
            int temp=cima(pila);
            valor=temp/100;
            if(cifras[i]<valor)
                apilar(pila,cifras[i]*100+1);
            else{
                while(!esPilaVacia(pila)){
                    temp=cima(pila);
                    valor=temp/100;
                    intervalo=temp%100;
                    if(cifras[i]<valor) break;
                    else{
                        temp=desapilar(pila);
                        valor=temp/100;
                        intervalo=temp%100;
                    }
                    solu[i]=solu[i]+intervalo;
                }
                apilar(pila,cifras[i]*100+solu[i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<solu[i]-1<<' ';
    }
}

int main(int argc, char** argv) {
    int n=8;
    int cifras[8]={10,20,15,10,12,10,13,18};
    calculaFrecuencia(cifras,n);
    return 0;
}

