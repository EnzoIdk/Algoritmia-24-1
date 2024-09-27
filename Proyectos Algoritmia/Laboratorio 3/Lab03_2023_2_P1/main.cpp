/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 5 de mayo de 2024, 08:27 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;
#include "Empresa.h"

void leerDatos(struct Empresa *empresas,int &n){
    cout<<"Ingrese el numero de empresas: ";
    cin>>n;
    cout<<"Ingrese los pedidos por horario de cada una (10 valores): "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            cin>>empresas[i].pedidos[j];
        }
        empresas[i].maxProd=empresas[i].horasPico=0;
    }
}

int hallarMax(struct Empresa empresa,int ini,int fin){
    if(ini==fin) return empresa.pedidos[ini];
    int med=(ini+fin)/2;
    int izq=hallarMax(empresa,ini,med);
    int der=hallarMax(empresa,med+1,fin);
    if(izq>der) return izq;
    else return der;
}

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int cuentaSeguidas(struct Empresa empresa,int ini,int med,int fin){
    int cont=1;
    if(empresa.pedidos[med]!=empresa.maxProd) return 0;
    for(int i=med;i>ini;i--){
        if(empresa.pedidos[i-1]==empresa.maxProd) cont++;
        else break;
    }
    for(int i=med;i<fin;i++){
        if(empresa.pedidos[i+1]==empresa.maxProd) cont++;
        else break;
    }
    return cont;
}

int horasSeguidasPico(struct Empresa empresa,int ini,int fin){
    if(ini==fin){
        if(empresa.pedidos[ini]==empresa.maxProd) return 1;
        else return 0;
    }
    int med=(ini+fin)/2;
    int izq=horasSeguidasPico(empresa,ini,med);
    int der=horasSeguidasPico(empresa,med+1,fin);
    int centro=cuentaSeguidas(empresa,ini,med,fin);
    return max(max(izq,der),centro);
}

int hallarMin(struct Empresa *empresas,int ini,int fin){
    if(ini==fin) return ini;
    int med=(ini+fin)/2;
    int izq=hallarMin(empresas,ini,med);
    int der=hallarMin(empresas,med+1,fin);
    if(empresas[izq].horasPico<empresas[der].horasPico) return izq;
    else return der;
}

int main(int argc, char** argv) {
    struct Empresa empresas[3];
    int n;
    leerDatos(empresas,n);
    for(int i=0;i<n;i++){
        empresas[i].maxProd=hallarMax(empresas[i],0,9);
        cout<<endl<<"Mayor cantidad de producciones de empresa "<<i+1<<
                ": "<<empresas[i].maxProd<<endl;
        empresas[i].horasPico=horasSeguidasPico(empresas[i],0,9);
        cout<<"Horas seguidas con mayor pico: "<<empresas[i].horasPico<<endl;
    }
    cout<<endl<<"La empresa donde debe comprar es la "<<hallarMin(empresas,0,n-1)+1<<endl;
    return 0;
}

