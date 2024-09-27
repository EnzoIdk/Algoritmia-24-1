/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de mayo de 2024, 08:47 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int cuentaUnos(int *arr,int ini,int fin,int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==1) cuentaUnos(arr,ini,med-1,cont+fin+1-med);
    else cuentaUnos(arr,med+1,fin,cont);
}

int cuentaUnosv2(int *arr,int ini,int fin,int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==1) cuentaUnosv2(arr,med+1,fin,med+1);
    else cuentaUnosv2(arr,ini,med-1,cont);
}

int main(int argc, char** argv) {
    int arr[9]={0,0,0,0,1,1,1,1,1},n=9;
    cout<<cuentaUnos(arr,0,n-1,0)<<endl;
    int arr2[9]={1,1,1,1,0,0,0,0,0};
    cout<<cuentaUnosv2(arr2,0,n-1,0);
    return 0;
}

