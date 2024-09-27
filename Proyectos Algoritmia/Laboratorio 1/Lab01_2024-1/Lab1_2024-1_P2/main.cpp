/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 14 de abril de 2024, 03:45 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>     
#define M 6
#define N 6

using namespace std;

int sonda(int tablero[N][M],int x,int y,int xFin,int yFin,int n,int m){
    int cont=0;
    if(x<0 or y<0 or xFin==n or yFin==m) return 0;
    if(x==xFin and y==yFin) cont=tablero[x][y];
    else{
        for(int i=y;i<=yFin;i++) cont+=tablero[x][i];
        for(int i=x+1;i<=xFin;i++) cont+=tablero[i][yFin];
        for(int i=yFin-1;i>=y;i--) cont+=tablero[xFin][i];
        for(int i=xFin-1;i>x;i--) cont+=tablero[i][y];
    }
    cont+=sonda(tablero,x-1,y-1,xFin+1,yFin+1,n,m);
    return cont;
}

int main(int argc, char** argv) {
    int n=6,m=6;
    int x=3,y=2;
    int tablero[M][N]={
        {0,0,0,1,0,1},
        {0,0,1,0,0,0},
        {0,1,0,0,0,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,1,0},
    };
    cout<<sonda(tablero,x,y,x,y,n,m);
    return 0;
}

