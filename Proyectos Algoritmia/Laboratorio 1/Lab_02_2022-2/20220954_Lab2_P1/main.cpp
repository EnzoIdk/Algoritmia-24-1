/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 * RECURSION
 * Created on 7 de abril de 2024, 05:18 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>  
#include <cmath>

using namespace std;

/*2 casos: anaqueles impares y pares
 Ambos se busca que se llenen en forma triangular desde el centro de la primera fila
 Espacios disponibles: 0, Espacios llenos: 5, Soportes: 1 (no se colocan productos)
 Hasta completar toda la fila hacia abajo con la cantidad de productos disponibles
 */

void leerAnaquel(int anaquel[10][10],int &fil,int &col,int &prod){
    ifstream archDatos("Datos.txt",ios::in);
    if(not archDatos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Datos.txt"<<endl;
        exit(1);
    }
    archDatos>>fil>>col>>prod;
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            archDatos>>anaquel[i][j];
        }
    }
}

void llenarAnaquel(int anaquel[10][10],int f,int col,int fil,int prod,int num,bool &esPosible){
    if(prod==0) return;
    if(fil==f){ /*f: num de filas, fil: fila actual*/
        esPosible=false;
        return;
    }
    /*caso columnas impares*/
    if(col%2!=0){
        for(int i=0;i<=(num/2);i++){
            if(anaquel[fil][(col/2)-i]==0 and prod>0){ /*por la izquierda del centro*/
                anaquel[fil][(col/2)-i]=5;
                prod--;
            }
            if(anaquel[fil][(col/2)+i]==0 and prod>0){ /*por la derecha del centro*/
                anaquel[fil][(col/2)+i]=5;
                prod--;
            }
        }
    }
    /*caso columnas pares*/
    else{
        int a=col/2,b=col/2-1;
        for(int i=0;i<=(num/2);i++){
            if(anaquel[fil][b-i]==0 and prod>0){
                anaquel[fil][b-i]=5;
                prod--;
            }
            if(anaquel[fil][a+i]==0 and prod>0){
                anaquel[fil][a+i]=5;
                prod--;
            }
        }
    }
    llenarAnaquel(anaquel,f,col,fil+1,prod,num+2,esPosible);
}

void imprimirAnaquel(int anaquel[10][10],int fil,int col,bool esPosible){
    if(esPosible){
        for(int i=0;i<fil;i++){
            for(int j=0;j<col;j++){
                cout<<anaquel[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl<<"Si es posible ordenar los productos en el anaquel"<<endl;
    }
    else cout<<"No es posible utilizar este anaquel para la cantidad de"
            " productos solicitados"<<endl;
}

int main(int argc, char** argv) {
    int fil,col,productos;
    int anaquel[10][10];
    bool esPosible=true;
    int inicio=1;
    leerAnaquel(anaquel,fil,col,productos);
    llenarAnaquel(anaquel,fil,col,0,productos,inicio,esPosible);
    imprimirAnaquel(anaquel,fil,col,esPosible);
    return 0;
}

