/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 * aaaa ya para que XD
 * Created on 2 de junio de 2024, 10:06 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

void nautilus(char *arr,int n){
    struct Pila pila;
    construir(pila);
    for(int i=0;i<=n;i++){
        apilar(pila,i+1);
        if(arr[i]=='S' or i==n){
            while(!esPilaVacia(pila)){
                cout<<desapilar(pila)<<' ';
            }
        }
    }
    destruirPila(pila);
}

int main(int argc, char** argv) {
    char orden[7]={'S','B','S','B','B','S','S'};
    int n=7;
    nautilus(orden,n);
    return 0;
}

