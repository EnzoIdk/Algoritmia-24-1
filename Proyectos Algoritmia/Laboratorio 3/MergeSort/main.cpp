/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 29 de abril de 2024, 10:52 AM
 */

#include <iostream>
#include <climits>

using namespace std;

void merge(int *arr,int ini,int med,int fin){
    int p1=med-ini+1;
    int p2=fin-med;
    int aux1[p1+1];
    int aux2[p2+1];
    //para arrancar los auxiliares en 0
    for(int i=ini;i<=med;i++) aux1[i-ini]=arr[i];
    for(int i=med+1;i<=fin;i++) aux2[i-med-1]=arr[i];
    aux1[p1]=INT_MAX;
    aux2[p2]=INT_MAX;
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        if(aux1[p]<aux2[q]){
            arr[i]=aux1[p];
            p++;
        }
        else{
            arr[i]=aux2[q];
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

int main(int argc, char** argv) {
    int arr[]={12,9,15,18,11,5};
    int n=6;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<' ';
    return 0;
}

