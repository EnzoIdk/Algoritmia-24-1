/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de abril de 2024, 05:21 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int mov[8][2];

void movimientos(){
    mov[0][0]=-1; mov[0][1]=0;
    mov[1][0]=-1; mov[1][1]=1;
    mov[2][0]=0; mov[2][1]=1; /*derecha*/
    mov[3][0]=1; mov[3][1]=1; /*diagonal derecha hacia abajo*/
    mov[4][0]=1; mov[4][1]=0; /*abajo*/
    mov[5][0]=1; mov[5][1]=-1;
    mov[6][0]=0; mov[6][1]=-1;
    mov[7][0]=-1; mov[7][1]=-1;
}

int cantMinPasos(int tablero[9][5],int x,int y,int xFin,int yFin){
    int nuevoX,nuevoY,pasos,minPasos=100;
    if((x==xFin and y==yFin) or x<0 or y<0 or x>8 or y>4) return 0;
    for(int i=0;i<8;i++){
        nuevoX=x+mov[i][0];
        nuevoY=y+mov[i][1];
        if(nuevoX>=0 and nuevoX<9 and nuevoY>=0 and nuevoY<5 and tablero[nuevoX][nuevoY]==0){
            tablero[nuevoX][nuevoY]=1;
            pasos=cantMinPasos(tablero,nuevoX,nuevoY,xFin,yFin);
            if(pasos<minPasos) minPasos=pasos;
            tablero[nuevoX][nuevoY]=0;
        }
    }
    return minPasos+1;
}

int main(int argc, char** argv) {
    int cantPasos;
    int tablero[9][5]={
        {0,1,0,0,1},  
        {0,1,0,0,0},  
        {0,0,1,0,0},  
        {1,1,0,1,0},  
        {0,1,1,0,0},  
        {0,1,1,1,0},  
        {1,1,0,0,1},  
        {1,0,1,1,1},  
        {1,0,0,0,0}  
    };
    movimientos();
    cantPasos=cantMinPasos(tablero,0,0,8,4);
    if(cantPasos!=101) cout<<"El robot llega al punto final en "<<cantPasos<<" pasos"<<endl;
    else cout<<"No es posible llegar al punto final"<<endl;
    return 0;
}

