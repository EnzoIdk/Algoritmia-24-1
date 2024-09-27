/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 4 de mayo de 2024, 12:58 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int buscaMax(int *arreglo,int ini,int fin){
    int med=(ini+fin)/2;
    if(ini>=fin) return arreglo[ini];
    if(arreglo[med]>=arreglo[med+1]) return buscaMax(arreglo,ini,med);
    else return buscaMax(arreglo,med+1,fin);
}

int main(int argc, char** argv) {
    int arreglo[]={1,2,20,9,8,4};
    int n=6;
    cout<<buscaMax(arreglo,0,n-1);
    return 0;
}

