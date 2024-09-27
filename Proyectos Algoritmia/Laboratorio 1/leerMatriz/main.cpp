/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 7 de abril de 2024, 05:41 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

void leerDatos(int &x,int &y,int matriz[10][10]){
    ifstream archDatos("Datos.txt",ios::in);
    if(not archDatos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Datos.txt"<<endl;
        exit(1);
    }
    archDatos>>x>>y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            archDatos>>matriz[i][j];
        }
    }   
}

int main(int argc, char** argv) {
    int x,y,matriz[10][10];
    leerDatos(x,y,matriz);
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<matriz[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

