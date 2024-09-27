/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 14 de junio de 2024, 11:34 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

void encontrarCercania(int *arr,int n){
    int solu[10]{};
    int aux;
    struct Pila pila;
    construir(pila);
    for(int i=0;i<n;i++){
        while(!esPilaVacia(pila) and arr[i]>arr[cima(pila)]){
            aux=desapilar(pila);
            solu[aux]=i-aux;
        }
        apilar(pila,i);
    }
    for(int i=0;i<n;i++) cout<<solu[i]<<' ';
    cout<<endl;
}

int main(int argc, char** argv) {
    int arreglo[10]={73,74,75,71,69,72,76,73},n=8;
    //cuanto le toma para encontrar el siguiente mayor
    encontrarCercania(arreglo,n);
    return 0;
}

