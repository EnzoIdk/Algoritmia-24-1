/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de mayo de 2024, 10:40 AM
 */

#include <iostream>
#include <climits>
#include <iomanip>
#include <fstream>        

using namespace std;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int numCentro(int *arr,int ini,int med,int fin){
    int cont=0;
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
            cont++;
            arr[i]=aux1[p];
            p++;
        }
        else{
            arr[i]=aux2[q];
            q++;
        }
    }
    return cont;
}

int numInversiones(int *arr,int ini,int fin){
   if(ini==fin) return 0;
   int med=(ini+fin)/2;
   int izq=numInversiones(arr,ini,med);
   int der=numInversiones(arr,med+1,fin);
   int cen=numCentro(arr,ini,med,fin);
   return izq+der+cen;
}

int main(int argc, char** argv) {
    int arr[6]={3,2,6,5,2,1},n=6;
    cout<<numInversiones(arr,0,n-1)<<endl;
    return 0;
}

