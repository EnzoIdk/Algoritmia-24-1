/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de mayo de 2024, 10:52 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int maxCentro(int *arr,int ini,int med,int fin){
    int izq=0,der=0;
    if(arr[med]>arr[med+1]) return 1;
    for(int i=med;i>ini;i--){
        if(arr[i]>arr[i-1]) izq++;
        else break;
    }
    for(int i=med+1;i<fin;i++){
        if(arr[i]<arr[i+1]) der++;
        else break;
    }
    return izq+der;
}

int solve(int *arreglo,int ini,int fin){
    if(ini==fin) return 1;
    int med=(ini+fin)/2;
    int izq=solve(arreglo,ini,med);
    int der=solve(arreglo,med+1,fin);
    int cen=maxCentro(arreglo,ini,med,fin);
    return max(cen,max(izq,der));
}

int main(int argc, char** argv) {
    int arreglo[10],n;
    cout<<"Ingrese la cantidad de dias a evaluar: ";
    cin>>n;
    cout<<"Ingrese los contagios por dia: "<<endl;
    for(int i=0;i<n;i++) cin>>arreglo[i];
    int numIncrementos=solve(arreglo,0,n-1);
    double indice=(double)numIncrementos/n;
    cout<<"Intervalo maximo de incrementos: "<<numIncrementos<<endl;
    cout<<"Indice con respecto a "<<n<<" dias: "<<indice<<endl;
    return 0;
}

