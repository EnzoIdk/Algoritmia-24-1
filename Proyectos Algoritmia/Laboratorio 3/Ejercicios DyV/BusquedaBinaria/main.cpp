/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de mayo de 2024, 12:22 PM
 */

#include <iostream>
#include <climits>
#include <iomanip>
#include <fstream>        

using namespace std;

int busquedaBinaria(int *arr,int dato,int ini,int fin){
    if(ini>fin) return -1;
    int med=(ini+fin)/2;
    if(arr[med]==dato) return med;
    else if(arr[med]>dato) busquedaBinaria(arr,dato,ini,med-1);
    else busquedaBinaria(arr,dato,med+1,fin);
}

void merge(int *arr,int ini,int med,int fin){
    /*crear tamaños de arreglos auxiliares*/
    int tamIzq=med-ini+1,tamDer=fin-med;
    /*crear los arreglos por cada mitad*/
    int auxIzq[tamIzq+1],auxDer[tamDer+1];
    /*se coloca estos indices para que se rellenen desde 0*/
    for(int i=ini;i<=med;i++) auxIzq[i-ini]=arr[i];
    for(int i=med+1;i<=fin;i++) auxDer[i-med-1]=arr[i];
    auxIzq[tamIzq]=auxDer[tamDer]=INT_MAX;
    /*si queremos ordenarlo descendente*/
//    auxIzq[tamIzq]=auxDer[tamDer]=INT_MIN;
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        /*llenamos de nuevo el arreglo con los arreglos auxiliares*/
        if(auxIzq[p]<auxDer[q]){ /*para descendente seria Izq>Der*/
            arr[i]=auxIzq[p];
            p++;
        }
        else{
            arr[i]=auxDer[q];
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

void mostrarArreglo(int *arr,int n){
    cout<<'[';
    for(int i=0;i<n;i++){
        if(i!=0) cout<<',';
        cout<<arr[i];
    }
    cout<<']'<<endl;
}
int main(int argc, char** argv) {
    int arreglo[6]={4,2,6,5,10,8};
    int pos,n=6;
    mostrarArreglo(arreglo,n);
    mergeSort(arreglo,0,n-1);
    mostrarArreglo(arreglo,n);
    int dato=8;
    pos=busquedaBinaria(arreglo,dato,0,n-1);
    cout<<"El dato "<<dato<<" se encuentra en la posicion "<<pos+1<<endl;
    return 0;
}

