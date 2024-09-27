/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 14 de junio de 2024, 06:55 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Pila.h"
#include "funcionesPila.h"        

using namespace std;
//frecuencias[15]={1,2,1,4,5,6,4,5,2,2,1}
int calcularAreaMax(int *frecuencias,int n,int &frecMax,int &durMax){
    int auxFrec,auxDur;
    struct Pila pila;
    construir(pila);
    int areaMax=0,aux,areaTop,i=0;
    while(i<n){
        if(esPilaVacia(pila) or frecuencias[cima(pila)]<=frecuencias[i]){
            apilar(pila,i);
            i++;
        }
        else{
            aux=desapilar(pila);
            if(esPilaVacia(pila)){
                auxFrec=frecuencias[aux];
                auxDur=i;
            }
            else{
                auxFrec=frecuencias[aux];
                auxDur=i-cima(pila)-1;
            }
            areaTop=auxFrec*auxDur;
            if(areaMax<areaTop){
                areaMax=areaTop;
                frecMax=auxFrec;
                durMax=auxDur;
            }
        }
    }
    while(!esPilaVacia(pila)){
        aux=desapilar(pila);
        if(esPilaVacia(pila)){
            auxFrec=frecuencias[aux];
            auxDur=i;
        }
        else{
            auxFrec=frecuencias[aux];
            auxDur=i-cima(pila)-1;
        }
        areaTop=auxFrec*auxDur;
        if(areaMax<areaTop){
            durMax=auxDur;
            frecMax=auxFrec;
            areaMax=areaTop;
        }
    }
    destruirPila(pila);
    return areaMax;
}

int main(int argc, char** argv) {
    int frecuencias[15]={1,2,1,4,5,6,4,5,2,2,1},n=11,frecMax=0,durMax=0;
    int areaMax=calcularAreaMax(frecuencias,n,frecMax,durMax);
    cout<<"El area maxima es: "<<areaMax<<endl;
    cout<<"Se da en la frecuencia "<<frecMax<<" con duracion de "<<durMax<<endl;
    return 0;
}

