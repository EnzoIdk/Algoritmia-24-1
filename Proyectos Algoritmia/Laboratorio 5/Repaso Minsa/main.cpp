/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 14 de junio de 2024, 06:35 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

//se guardan los valores como (valor (2)- diasMayor (2))
void obtenerFrecuencias(int *contagios,int n){
    struct Pila pila;
    int solu[10],temp,valor,diasMayor;
    construir(pila);
    for(int i=0;i<n;i++){
        solu[i]=1;
        if(i==0) apilar(pila,contagios[i]*100+1);
        else{
            temp=cima(pila);
            valor=temp/100;
            if(contagios[i]<valor){
                apilar(pila,contagios[i]*100+1);
            }
            else{
                while(!esPilaVacia(pila)){
                    temp=cima(pila);
                    valor=temp/100;
                    if(contagios[i]<valor) break;
                    else{
                        temp=desapilar(pila);
                        valor=temp/100;
                        diasMayor=temp%100;
                        solu[i]=solu[i]+diasMayor;
                    }
                }
                apilar(pila,contagios[i]*100+solu[i]);
            }
        }
    }
    destruirPila(pila);
    cout<<"El intervalo de incrementos es: "<<endl;
    for(int i=0;i<n;i++){
        cout<<solu[i]-1<<' ';
    }
    cout<<endl;
}

int main(int argc, char** argv) {
    int contagios[10],n;
    cout<<"Ingrese la cantidad de dias a evaluar: ";
    cin>>n;
    cout<<"Ingrese los contagios de los "<<n<<" dias:"<<endl;
    for(int i=0;i<n;i++) cin>>contagios[i];
    obtenerFrecuencias(contagios,n);
    return 0;
}

