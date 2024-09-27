/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 12 de abril de 2024, 05:37 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

void impresion1(int matriz[][5],int x,int y,int m){
    if(y==m){
        cout<<endl;
        return;
    }
    cout<<matriz[x][y]<<' ';
    impresion1(matriz,x,y+1,m);
}

void impresion2(int matriz[][5],int x,int y,int n){
    if(x==n){
        cout<<endl;
        return;
    }
    cout<<matriz[x][y]<<' ';
    impresion2(matriz,x+1,y,n);
}

void impresion3(int matriz[][5],int x,int y,int m){
    if(y<m){
        cout<<endl;
        return;
    }
    cout<<matriz[x][y]<<' ';
    impresion3(matriz,x,y-1,m);
}

void impresion4(int matriz[][5],int x,int y,int n){
    if(x<n){
        cout<<endl;
        return;
    }
    cout<<matriz[x][y]<<' ';
    impresion4(matriz,x-1,y,n);
}

void imprimirRemolino(int matriz[][5],int x,int y,int n,int m){
    /*caso base*/
    if(x>=n or y>=m) return;
    impresion1(matriz,x,y,m); /*hacia la derecha*/
    impresion2(matriz,x+1,m-1,n); /*hacia abajo*/
    impresion3(matriz,n-1,m-2,y); /*hacia la izquierda*/
    impresion4(matriz,n-2,y,x+1); /*hacia arriba*/
//    int nX=x,nY=y;
//    for(nY;nY<m-1;nY++) cout<<matriz[nX][nY]<<' ';
//    cout<<endl;
//    for(nX;nX<n-1;nX++) cout<<matriz[nX][nY]<<' ';
//    cout<<endl;
//    for(nY;nY>y;nY--) cout<<matriz[nX][nY]<<' ';
//    cout<<endl;
//    for(nX;nX>x;nX--) cout<<matriz[nX][nY]<<' ';
//    cout<<endl;
    imprimirRemolino(matriz,x+1,y+1,n-1,m-1);
}

int main(int argc, char** argv) {
    int matriz[5][5],m=5,n=3,valor=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matriz[i][j]=valor++;
        }
    }
    imprimirRemolino(matriz,0,0,n,m);
    return 0;
}

