/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de mayo de 2024, 12:04 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>

using namespace std;

int menor(int *arreglo,int ini,int fin){
    int med=(ini+fin)/2;
    if(ini==fin) return arreglo[ini];
    int izq=menor(arreglo,ini,med);
    int der=menor(arreglo,med+1,fin);
    if(izq<der) return izq;
    else return der;
}

int buscaSolo(int *arreglo,int ini,int fin){
    if(ini>fin) return 0;
    if(ini==fin) return arreglo[ini];
    int med=(ini+fin)/2;
    if(med%2==0){
        if(arreglo[med]==arreglo[med+1]) buscaSolo(arreglo,med+2,fin);
        else buscaSolo(arreglo,ini,med);
    }
    else{
        if(arreglo[med]==arreglo[med-1]) buscaSolo(arreglo,med+1,fin);
        else buscaSolo(arreglo,ini,med-1);
    }
}

void merge(int *arr,int ini,int med,int fin){
    int tamIzq=med+1-ini,tamDer=fin-med;
    int arrIzq[tamIzq],arrDer[tamDer];
    for(int i=ini;i<=med;i++) arrIzq[i-ini]=arr[i];  
    for(int i=med+1;i<=fin;i++) arrDer[i-med-1]=arr[i];
    arrIzq[tamIzq]=arrDer[tamDer]=INT_MAX;
    int numIzq=0,numDer=0;
    for(int i=ini;i<=fin;i++){
        if(arrIzq[numIzq]<arrDer[numDer]){
            arr[i]=arrIzq[numIzq];
            numIzq++;
        }
        else{
            arr[i]=arrDer[numDer];
            numDer++;
        }
    }
}

void mergeSort(int *arr,int ini,int fin){
    if(ini==fin) return;
    int med=(ini+fin)/2;
    mergeSort(arr,ini,med);
    mergeSort(arr,med+1,fin);
    merge(arr,ini,med,fin);
}

int main(int argc, char** argv) {
//    int arreglo[6]={6,7,8,3,4,5},n=6;
//    cout<<menor(arreglo,0,n-1)<<endl;
//    int parejas[9]={1,1,2,2,3,3,5,4,4},n2=9;
//    cout<<buscaSolo(parejas,0,n2-1)<<endl;
    int matriz[4][6]={
        {5,6,1,2,3,4},  
        {5,6,7,2,3,4},  
        {5,6,7,8,3,4},  
        {5,6,7,8,9,4},  
    };
    int m=6;
    for(int i=0;i<4;i++){
//        cout<<buscaMin(matriz[i],0,m-1)<<endl;
//        cout<<menor(matriz[i],0,m-1)<<endl;
        mergeSort(matriz[i],0,m-1);
        cout<<matriz[i][0]<<endl;
    }
    return 0;
}

