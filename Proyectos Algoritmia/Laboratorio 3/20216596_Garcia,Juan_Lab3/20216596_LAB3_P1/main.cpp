/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 30 de septiembre de 2023, 08:08 AM
 */

#include <iostream>

#include "Empresa.h"

using namespace std;


int HallarMaxPro(struct Empresa empresa,int ini,int fin){
    
    if(ini==fin)return empresa.produccion[ini];
    int izq,der,medio;
    
    medio=(ini+fin)/2;
    izq=HallarMaxPro(empresa,ini,medio);
    der=HallarMaxPro(empresa,medio+1,fin);
    
    if(izq<der)
        return der;
    else 
        return izq;
    
}

int HallarMenorPico(struct Empresa *empresas,int ini,int fin){
    
    if(ini==fin)return ini;
    
    int izq,der,medio;
    medio=(ini+fin)/2;
    
    
    izq=HallarMenorPico(empresas,ini,medio);
    der=HallarMenorPico(empresas,medio+1,fin);
    
    
    
    if(empresas[izq].cantPico<empresas[der].cantPico)return der;
    else return izq;
    
}

int max(int a,int b){
    if(a>b)return a;
    else return b;
}

int Merge(struct Empresa empresa,int ini,int medio,int fin){
    
    int cont;
    if(empresa.produccion[medio]==empresa.maxProduccion)cont=1;
    else return 0;
    for(int i=medio;i>ini;i--){
        if(empresa.produccion[i-1]==empresa.maxProduccion)cont++;
        else break;
    }
    for(int i=medio;i<fin;i++){
        if(empresa.produccion[i+1]==empresa.maxProduccion)cont++;
        else break;
    }
    return cont;
}

int MaxSeguidos(struct Empresa empresa,int ini,int fin){
    
    if(ini==fin){
        if(empresa.produccion[ini]==empresa.maxProduccion)return 1;
        else return 0;
    }
    
    int izq,der,medio,centro;
    
    medio=(ini+fin)/2;
    izq=MaxSeguidos(empresa,ini,medio);
    der=MaxSeguidos(empresa,medio+1,fin);
    centro=Merge(empresa,ini,medio,fin);
    
    return max(max(izq,der),centro);
}






/*
 * 
 */
int main(int argc, char** argv) {

    int numEmpresas;
    cin>>numEmpresas;
    
    struct Empresa empresas[numEmpresas];
    
     for(int i=0;i<numEmpresas;i++){
        for(int j=0;j<10;j++)cin>>empresas[i].produccion[j];
    }
    
    int maxProduccion[numEmpresas];
    /*
     3
    15 12 10 17 15 18 18 18 12 16
    14 17 17 17 17 12 14 14 12 12
    16 18 20 20 15 18 16 18 18 16
     */
    
    
   
    for(int i=0;i<numEmpresas;i++){
        empresas[i].maxProduccion=HallarMaxPro(empresas[i],0,9);
    }
    for(int i=0;i<numEmpresas;i++)cout<<empresas[i].maxProduccion<<" ";
    cout<<endl;
    
    for(int i=0;i<numEmpresas;i++){
        empresas[i].cantPico=MaxSeguidos(empresas[i],0,9);
    }
    for(int i=0;i<numEmpresas;i++)cout<<empresas[i].cantPico<<" ";
    cout<<endl;
    int menorPico=HallarMenorPico(empresas,0,numEmpresas);
   
        
    cout<<"la empresa ideal es la empresa "<<menorPico;
    
    
    
    
    
    return 0;
}

