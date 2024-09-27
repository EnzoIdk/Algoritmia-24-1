/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 11 de mayo de 2024, 12:14 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int detectaColumna(int tablero[10][7],int ini,int fin,int filas,int &potencia,int &filaBomb){
    if(ini==fin) return ini;
    int med=(ini+fin)/2;
    int sumIzq=0,sumDer=0;
    for(int i=0;i<filas;i++){
        sumIzq+=tablero[i][med-1];
        sumDer+=tablero[i][med+1];
        if(tablero[i][med]>potencia){
            potencia=tablero[i][med];
            filaBomb=i;
        }
        if(tablero[i][med+1]>potencia){
            potencia=tablero[i][med+1];
            filaBomb=i;
        }
        if(tablero[i][med-1]>potencia){
            potencia=tablero[i][med-1];
            filaBomb=i;
        }
    }
    if(sumIzq>sumDer) detectaColumna(tablero,ini,med-1,filas,potencia,filaBomb);
    else detectaColumna(tablero,med+1,fin,filas,potencia,filaBomb);
}

int main(int argc, char** argv) {
    int n=7,m=10;
    int tablero[10][7]={
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,1,1,1,0,0,0},
        {0,1,2,1,0,0,0},
        {0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0},
    };
    int potencia=0,filaBomb;
    int columnaImp=detectaColumna(tablero,0,n-1,m,potencia,filaBomb);
    cout<<"Para este juego de datos, la potencia mas alta de bomba es "<<
            potencia<<endl<<"La columna donde se ubica es "<<columnaImp<<endl<<
            "La fila con el mayor impacto es la "<<filaBomb<<endl;
    return 0;
}

