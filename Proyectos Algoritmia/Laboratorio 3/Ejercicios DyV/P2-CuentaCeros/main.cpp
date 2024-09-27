/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 7 de mayo de 2024, 11:55 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>  
#include <climits>

using namespace std;

int cuentaCeros(int *arr,int ini,int fin,int cont){
    if(ini>=fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==0) cuentaCeros(arr,ini,med,cont+fin-med+1);
    else cuentaCeros(arr,med+1,fin,cont);
}

int cuentaUnos(int *arr,int ini,int fin,int cont){
    if(ini>=fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==1) cuentaUnos(arr,med+1,fin,med+1);
    else cuentaUnos(arr,ini,med,cont);
}

void merge(int *arr,int ini,int med,int fin){
    int tamIzq=med-ini+1,tamDer=fin-med;
    int arrIzq[tamIzq+1]{},arrDer[tamDer+1]{};
    for(int i=ini;i<=med;i++) arrIzq[i-ini]=arr[i];
    for(int i=med+1;i<=fin;i++) arrDer[i-med-1]=arr[i];
    arrDer[tamDer]=arrIzq[tamIzq]=INT_MAX;
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        if(arrIzq[p]<arrDer[q]){
            arr[i]=arrIzq[p];
            p++;
        }
        else{
            arr[i]=arrDer[q];
            q++;
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

int busquedaBinaria(int *arr,int ini,int fin,int dato){
    if(ini>fin) return -1;
    int med=(ini+fin)/2;
    if(arr[med]==dato) return med;
    else if(arr[med]>dato) busquedaBinaria(arr,ini,med,dato);
    else busquedaBinaria(arr,med+1,fin,dato);
}

int buscaPico(int *arr,int ini,int fin){
    if(ini>=fin) return arr[ini];
    int med=(ini+fin)/2;
    if(arr[med]<arr[med+1]) buscaPico(arr,med+1,fin);
    else buscaPico(arr,ini,med);
}

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int sumaCentro(int *arr,int ini,int med,int fin){
    int sumMaxIzq=-999,sumMaxDer=-999,sumTotal;
    int sumIzq=0,sumDer=0;
    for(int i=med;i>=ini;i--){
        sumIzq+=arr[i];
        if(sumIzq>sumMaxIzq) sumMaxIzq=sumIzq;
    }
    for(int i=med+1;i<=fin;i++){
        sumDer+=arr[i];
        if(sumDer>sumMaxDer) sumMaxDer=sumDer;
    }
    sumTotal=sumMaxDer+sumMaxIzq;
    return max(sumTotal,max(sumMaxDer,sumMaxIzq));
}

int sumaMax(int *arr,int ini,int fin){
    if(ini==fin) return arr[ini];
    int med=(ini+fin)/2;
    int izq=sumaMax(arr,ini,med);
    int der=sumaMax(arr,med+1,fin);
    int cen=sumaCentro(arr,ini,med,fin);
    return max(cen,max(izq,der));
}

int datoMin(int *arr,int ini,int fin){
    if(ini==fin) return arr[fin];
    int med=(ini+fin)/2;
    if(arr[med]>arr[med+1]) return arr[med+1];
    if(arr[med]>=arr[fin]) return datoMin(arr,med+1,fin);
    return datoMin(arr,ini,med);
}

int main(int argc, char** argv) {
    int arreglo[7]={1,1,0,0,0,0},n=6;
    cout<<cuentaCeros(arreglo,0,n-1,0)<<endl;
    cout<<cuentaUnos(arreglo,0,n-1,0)<<endl;
    int arreglo2[5]={2,3,1,5,4};
    mergeSort(arreglo2,0,4);
    int dato=5;
    cout<<busquedaBinaria(arreglo2,0,4,dato)<<endl;
    int arreglo3[6]={1,2,4,7,3,2};
    cout<<buscaPico(arreglo3,0,5)<<endl;
    int arreglo4[8]={-2,-5,6,-2,-3,1,5,-6};
    cout<<sumaMax(arreglo4,0,7)<<endl;
    int arreglo5[6]={5,6,7,8,3,4};
    cout<<datoMin(arreglo5,0,5);
    return 0;
}

