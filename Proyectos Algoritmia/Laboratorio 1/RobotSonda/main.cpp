/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 5 de abril de 2024, 06:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int mapa[][6]={
    {0,0,0,1,0,1},
    {0,0,1,0,0,0},
    {0,1,0,0,0,1},
    {1,0,0,0,0,0},
    {0,1,0,0,0,0},
    {0,0,0,0,1,0}
};

/*
 derecha:   (0,1)
 izquierda: (0,-1)
 abajo:     (1,0)
 arriba:    (-1,0)
 */

/*mx: mov en x, my: mov en y*/
int busca(int x,int y,int mx,int my,int flagX,int flagY,int n,int m){
    int cont=0;
    if(x>=n or y>=m or x<0 or y<0) return 0; /*condiciones de parada*/
    if(mapa[x][y] and flagX==0 and flagY==0) cont++; /*se cuenta la posicion donde estamos una sola vez
                                                      y en la primera recursion*/
    /*movimiento fila a fila*/
    if(flagX==0){
        for(int i=x+1;i<n;i++) cont+=mapa[i][y]; /*desde abajo hacia donde estamos*/
        for(int i=0;i<x;i++) cont+=mapa[i][y]; /*desde arriba hacia donde estamos*/
    }
    /*movimiento columna a columna*/
    if(flagY==0){
        for(int i=y+1;i<m;i++) cont+=mapa[x][i]; /*desde la derecha hacia donde estamos*/
        for(int i=0;i<y;i++) cont+=mapa[x][i]; /*desde la izquierda hacia donde estamos*/
    }
    cont+=busca(x+mx,y+my,mx,my,mx,my,n,m); /*no se cambia el movimiento*/
    return cont;
}

int main(int argc, char** argv) {
    int n=6,m=6,x=3,y=1;
    int mx=0,my=-1; /*mov hacia la izquierda*/
    cout<<busca(x,y,mx,my,0,0,n,m);
    return 0;
}

