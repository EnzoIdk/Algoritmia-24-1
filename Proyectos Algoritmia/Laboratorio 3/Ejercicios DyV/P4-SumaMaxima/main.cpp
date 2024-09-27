/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de mayo de 2024, 08:31 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int max(int a ,int b){
    if(a>b) return a;
    else return b;
}

int sumaCentro(int *arr,int ini,int med,int fin,int &pos1,int &pos2){
    int sumIzq=0,sumMaxIzq=-9999,sumDer=0,sumMaxDer=-9999;
    int aux1,aux2;
    for(int i=med;i>=ini;i--){
        sumIzq+=arr[i];
        if(sumIzq>sumMaxIzq){
            pos1=i;
            sumMaxIzq=sumIzq;
        }
    }
    for(int i=med+1;i<=fin;i++){
        sumDer+=arr[i];
        if(sumDer>sumMaxDer){
            pos2=i;
            sumMaxDer=sumDer;
        }
    }
    int sumMaxTodo=sumMaxIzq+sumMaxDer;
    if(sumMaxTodo>=max(sumMaxIzq,sumMaxDer)) return sumMaxTodo;
    else{
        if(sumMaxDer>sumMaxIzq) pos1=med+1;
        else pos2=med;
        return max(sumMaxIzq,sumMaxDer);
    }
}
    
int sumaMax(int *arr,int ini,int fin,int &pos1,int &pos2){
    if(ini==fin) return arr[ini];
    int med=(ini+fin)/2;
    int izq=sumaMax(arr,ini,med,pos1,pos2);
    int der=sumaMax(arr,med+1,fin,pos1,pos2);
    int cen=sumaCentro(arr,ini,med,fin,pos1,pos2);
//    cout<<"Del "<<ini<<" al "<<fin<<": "<<max(cen,max(izq,der))<<endl;
    return max(cen,max(izq,der));
}

int main(int argc, char** argv) {
    int arreglo[8]={2,13,2,2,-3,0,-3,-6},n=8;
    int pos1,pos2;
    cout<<sumaMax(arreglo,0,n-1,pos1,pos2);
    cout<<" (Los elementos que suman el maximo son: ";
    for(int i=pos1;i<=pos2;i++){
        cout<<arreglo[i];
        if(i!=pos2) cout<<", ";
        else cout<<')';
    }
    return 0;
}

