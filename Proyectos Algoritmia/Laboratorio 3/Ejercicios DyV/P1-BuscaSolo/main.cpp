/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 5 de mayo de 2024, 05:01 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

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

int main(int argc, char** argv) {
    int arreglo[11]={1,1,3,3,4,5,5,7,7,8,8},n=11;
    cout<<buscaSolo(arreglo,0,n-1);
    return 0;
}

