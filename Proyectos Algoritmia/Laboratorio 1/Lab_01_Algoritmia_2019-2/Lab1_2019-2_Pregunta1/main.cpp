/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 7 de abril de 2024, 06:14 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>    
#include <cmath>

using namespace std;

#include "Proyecto.h"

void cargaBin(int num,int n,int *cromo){
    int i=0;
    for(int i=0;i<n;i++) cromo[i]=0;
    while(num>0){
        cromo[i]=num%2;
        num/=2;
        i++;
    }
}

void buscarSolucion(struct Proyecto *proyectos,int n,int maxPresupuesto){
    int cromoCosto,cromoGan,mayorGan=-1,predecesores,solucion;
    int cromo[n];
    int combinaciones=pow(2,n);
    for(int i=1;i<combinaciones;i++){
        cargaBin(i,n,cromo);
        cromoCosto=cromoGan=0; /*inicializando en cada iteración*/
        for(int j=0;j<n;j++){
            if(cromo[j]){
                predecesores=1;
                for(int k=0;k<proyectos[j].numPred;k++){
                    if(cromo[proyectos[j].predecesores[k]]!=1){
                       predecesores=0;
                      break;
                    }
                }
                if(predecesores!=1) break;
                else{
                    cromoCosto+=proyectos[j].costo;
                    cromoGan+=proyectos[j].ganancia;
                }
            } 
        }
        if(cromoCosto<=maxPresupuesto and cromoGan>=mayorGan and predecesores){
            solucion=i;
            mayorGan=cromoGan;
        }
    }
    int costoSolu=0;
    cargaBin(solucion,n,cromo);
    cout<<"La mayor ganancia es: "<<mayorGan<<endl;
    cout<<solucion<<endl;
    cout<<"Los proyectos seleccionados fueron: ";
    for(int i=0;i<n;i++){
        if(cromo[i]){
            cout<<i+1<<' ';
            costoSolu+=proyectos[i].costo;
        }
    }
    cout<<endl<<"El costo fue de: "<<costoSolu<<endl;
}

int main(int argc, char** argv) {
    
    struct Proyecto proyectos[8]={
        {80,150,0},
        {20,80,0},
        {100,300,2,{0,1}},
        {100,150,0},
        {50,80,0},
        {10,50,1,{1}},
        {50,120,1,{5}},
        {50,150,1,{5}}
    };
//    for(int i=0;i<8;i++){
//        for(int j=0;j<proyectos[i].numPred;j++){
//            cout<<proyectos[i].predecesores[j]<<' ';
//        }
//        if(proyectos[i].numPred>0) cout<<endl;
//    }
    int n=8,p=250;
    buscarSolucion(proyectos,n,p);
    return 0;
}

