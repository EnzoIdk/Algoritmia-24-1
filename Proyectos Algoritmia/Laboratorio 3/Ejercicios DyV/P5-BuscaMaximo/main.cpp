/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de mayo de 2024, 09:02 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int valorMax(int *arreglo,int ini,int fin){
    if(ini>=fin) return arreglo[ini];
    int med=(ini+fin)/2;
    if(arreglo[med]<arreglo[med+1]) valorMax(arreglo,med+1,fin);
    else valorMax(arreglo,ini,med);
}

int main(int argc, char** argv) {
    int arreglo[11]={8,10,20,80,100,200,400,500,3,2,1},n=11;
    cout<<valorMax(arreglo,0,n-1);
    return 0;
}

