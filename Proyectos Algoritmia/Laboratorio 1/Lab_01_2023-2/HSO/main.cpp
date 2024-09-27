/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * aaaa
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;
#define MAX_COL 10
#define MAX_FIL 4

int mov[2][4];

void movimientos(){
    mov[0][0]=-1 ; mov[1][0]=0;
    mov[0][1]=0 ; mov[1][1]=1;
    mov[0][2]=1 ; mov[1][2]=0;
    mov[0][3]=0 ; mov[1][3]=-1;
}

int esLetra2HSO(char letraHSO,char hso[],int num1HSO,int letras){
    for(int i=0;i<letras;i++){
        if(letraHSO==hso[i] and i!=num1HSO) return i;
    }
    return -1;
}

int esLetra3HSO(char letraHSO,char hso[],int num1HSO,int num2HSO,int letras){
    for(int i=0;i<letras;i++){
        if(letraHSO==hso[i] and i!=num1HSO and i!=num2HSO) return i;
    }
    return -1;
}

int encuentraHSO(char datos[][MAX_COL],char hso[],int letras,int x,int y){
    int nuevoX,nuevoY,nuevoNX,nuevoNY;
    int i,num1HSO=-1,num2HSO,num3HSO;
    /*si no es ninguna de las letras, no tiene que seguir buscando en esa posición*/
    if(!(datos[x][y]==hso[0] or datos[x][y]==hso[1] or datos[x][y]==hso[2])) return 0;
    for(int i=0;i<letras;i++){
        if(datos[x][y]==hso[i]) num1HSO=i;
    }
    if(num1HSO==-1) return 0;
    for(int i=0;i<4;i++){
        nuevoX=x+mov[0][i];
        nuevoY=y+mov[1][i];
        if(nuevoX>=0 and nuevoX<MAX_FIL and nuevoY>=0 and nuevoY<MAX_COL){
            num2HSO=esLetra2HSO(datos[nuevoX][nuevoY],hso,num1HSO,letras);
            if(num2HSO!=-1){
                for(int j=0;j<4;j++){
                    nuevoNX=nuevoX+mov[0][j];
                    nuevoNY=nuevoY+mov[1][j];
                    if(nuevoNX>=0 and nuevoNX<MAX_FIL and nuevoNY>=0 and nuevoNY<MAX_COL){
                        num3HSO=esLetra3HSO(datos[nuevoNX][nuevoNY],hso,num1HSO,num2HSO,letras);
                        if(num3HSO!=-1) return 1;
                    }
                }
            } 
        }
    }
    return 0;
}

void buscarHSO(char datos[][MAX_COL],char hso[],int letras){
    for(int i=0;i<MAX_FIL;i++){
        for(int j=0;j<MAX_COL;j++){
            if(encuentraHSO(datos,hso,letras,i,j)){
                cout<<'('<<i<<','<<j<<')'<<setw(3)<<' ';
            }
        }
    }
}

int main(int argc, char** argv) {
    char datos[][MAX_COL]={
        {'H','C','H','B','Y','S','O','S','O','H'},
        {'S','C','S','S','Y','Q','O','S','Z','K'},
        {'O','P','N','Y','O','K','F','H','C','K'},
        {'O','B','N','I','Y','S','P','O','O','K'}
    };
    int letras=3;
    char hso[]={'H','S','O'};
    movimientos();
    buscarHSO(datos,hso,letras);
    return 0;
}

