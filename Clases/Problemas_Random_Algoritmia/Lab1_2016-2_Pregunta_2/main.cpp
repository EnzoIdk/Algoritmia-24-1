/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de marzo de 2024, 05:03 PM
 */

#include <iostream>        

using namespace std;

#define MIN_NUM -9999

/*Imagina un tablero 3x3 con números random, se busca programar un robot que 
    debe encontrar el mejor camino de tal manera que obtenga la mayor suma posible
    recorriendo los números, sus únicos movimientos permitidos son hacia la derecha y abajo*/

/*en la matriz es obligatorio colocar el #columnas, el de filas
 se puede trabajar como dinámico, da igual si colocar el número o no*/
int robot(int x,int y,int n,int m,int tablero[][3]){
    int derecha=MIN_NUM,abajo=MIN_NUM; /*para q solo tome un valor si solo tiene un camino posible*/
    if(x==n-1 and y==m-1) return tablero[x][y]; /*condición de parada*/
    /*Recursión para ambos caminos posibles*/
    if(y+1<m) derecha=robot(x,y+1,n,m,tablero);
    if(x+1<n) abajo=robot(x+1,y,n,m,tablero);
    /*Selectiva, el robot decide que dirección tomar*/
    if(derecha>abajo) return derecha+tablero[x][y];
    else return abajo+tablero[x][y];
}

int main(int argc, char** argv) {
    int n=3,m=3; /*n: cant. filas, m: cant. columnas*/
    int tablero[][3]={{3,8,6},
                      {3,10,2},
                      {0,9,1}
    }; /*piensa esta matriz como el tablero*/
    int resultado=robot(0,0,n,m,tablero); /*(0,0) como punto de partida*/
    cout<<"El resultado de la mejor suma es: "<<resultado<<endl;
    return 0;
}

