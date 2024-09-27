/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de abril de 2024, 06:03 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

// Función recursiva para calcular el coeficiente binomial C(n, k)
int coeficiente(int n, int i) {
    if (i==0||i==n) return 1;
    return coeficiente(n-1,i-1)+coeficiente(n-1,i);
}

// Imprimiendo fila tras fila mediante recursion
void trianguloPascal(int n, int nFila) {
    if (nFila==n) return;
    for (int i=0;i<=nFila;i++) cout<<coeficiente(nFila,i)<<' ';
    cout<<endl;
    trianguloPascal(n,nFila+1);
}

int main(int argc, char** argv) {
    int n=4;
    trianguloPascal(n,0);
    return 0;
}
