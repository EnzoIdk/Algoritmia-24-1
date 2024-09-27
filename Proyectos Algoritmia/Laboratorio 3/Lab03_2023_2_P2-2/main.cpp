/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 6 de mayo de 2024, 08:00 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int matriz[8][5]={
    {1,2,3,2,1},
    {2,3,2,2,1},
    {1,2,2,5,3},
    {2,5,3,3,1},
    {2,2,3,2,1},
    {1,2,3,2,1},
    {3,5,2,1,1},
    {2,3,2,1,1}
};

int buscaMax(int *arr,int ini,int fin){
    if(ini==fin) return ini;
    int med=(ini+fin)/2;
    if(arr[med]>arr[med-1] and arr[med]>arr[med+1]) return med;
    if(arr[med]<arr[med-1]) buscaMax(arr,ini,med);
    else buscaMax(arr,med,fin);
}

int main(int argc, char** argv) {
    int n=8,m=5;
    for(int i=0;i<n;i++){
        cout<<"En la fila "<<i+1<<", el pasajero del asiento "<<buscaMax(matriz[i],0,m-1)+1<<
                " tiene el bocadito mas caro que sus 2 vecinos"<<endl;
    }
    return 0;
}

