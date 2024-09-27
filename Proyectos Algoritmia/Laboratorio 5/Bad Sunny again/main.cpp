/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 14 de junio de 2024, 11:17 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

int calcularAreaMax(int *frecuencias,int n,int &frecMax,int &durMax){
    int frecTemp,durTemp,temp;
    struct Pila pila;
    construir(pila);
    int areaMax=0,areaTop,i=0;
    while(i<n){
        if(esPilaVacia(pila) or frecuencias[cima(pila)]<=frecuencias[i]){
            apilar(pila,i);
            i++;
        }
        else{
            temp=desapilar(pila);
            if(esPilaVacia(pila)){
                frecTemp=frecuencias[temp];
                durTemp=i;
            }
            else{
                frecTemp=frecuencias[temp];
                durTemp=i-cima(pila)-1;
            }
            areaTop=frecTemp*durTemp;
            if(areaMax<areaTop){
                frecMax=frecTemp;
                durMax=durTemp;
                areaMax=areaTop;
            }
        }
    }
    while(!esPilaVacia(pila)){
        temp=desapilar(pila);
        if(esPilaVacia(pila)){
            frecTemp=frecuencias[temp];
            durTemp=i;
        }
        else{
            frecTemp=frecuencias[temp];
            durTemp=i-cima(pila)-1;
        }
        areaTop=frecTemp*durTemp;
        if(areaMax<areaTop){
            frecMax=frecTemp;
                durMax=durTemp;
                areaMax=areaTop;
        }
    }
    destruirPila(pila);
    return areaMax;
}

//int main(int argc, char** argv) {
//    int frecuencias[15]={1,2,1,4,5,6,4,5,2,2,1},n=11,frecMax=0,durMax=0;
//    int areaMax=calcularAreaMax(frecuencias,n,frecMax,durMax);
//    cout<<"El area maxima es: "<<areaMax<<endl;
//    cout<<"Se da en la frecuencia "<<frecMax<<" con duracion de "<<durMax<<endl;
//    return 0;
//}

int main(int argc, char** argv) {
    int fq[11]={1,2,1,4,5,6,4,5,2,2,1};
    struct Pila pila;
    construir(pila);
    int i=1, areaMax=0, fqMax=0, dMax=0;
    int areaActual=0, dActual;
    int fqdesapilado, tdesapilado, d;
    while(i<=11){
        if (esPilaVacia(pila) or fq[i-1]>=cima(pila)/100){
            apilar(pila, (fq[i-1]*100)+i);
//            cout<<(fq[i-1]*100)+(*t)<<endl;
            i++;
        }
        else{
            d=desapilar(pila);
            tdesapilado=d%100;
            fqdesapilado=d/100;
//            cout<<tdesapilado<<"     "<<fqdesapilado<<endl;
            if(esPilaVacia(pila)){//si no queda nada en la pila
                areaActual=fqdesapilado*i;//la frecuencia está ahí desde el t=0
                dActual=i;
            }
            else{
                areaActual=fqdesapilado*(i-tdesapilado);
                dActual=i-tdesapilado;
            }
            if (areaActual>areaMax){
                areaMax=areaActual;
                fqMax=fqdesapilado;
                dMax=dActual;
            }
        }
    }
    cout<<"fq max= "<<fqMax<<"    duracion="<<dMax<<endl;
    cout<<"Area max= "<<areaMax<<endl;
    return 0;
}