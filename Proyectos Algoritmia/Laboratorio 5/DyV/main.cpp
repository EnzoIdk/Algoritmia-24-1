/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 15 de junio de 2024, 12:15 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#define N 5
#define M 6
using namespace std;

int buscaPico(int *arr,int ini,int fin){
    if(ini>=fin) return arr[ini];
    int med=(ini+fin)/2;
    if(arr[med]<arr[med+1]) return buscaPico(arr,med+1,fin);
    else return buscaPico(arr,ini,med);
}

void buscaPicoMatriz(int matriz[N][M],int m,int n,int i){
    if(i==n) return;
    cout<<buscaPico(matriz[i],0,m-1)<<endl;
    buscaPicoMatriz(matriz,m,n,i+1);
}

int main(int argc, char** argv) {
    int matriz[N][M]={
        {1,2,3,2,1,0},
        {1,5,3,2,1,1},
        {8,7,6,5,4,3},
        {1,2,8,10,4,3},
        {3,4,5,6,7,5}
    };
    int m=6,n=5;
    buscaPicoMatriz(matriz,m,n,0);
    return 0;
}

