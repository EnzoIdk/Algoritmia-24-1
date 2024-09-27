/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * Created on 2 de septiembre de 2023, 10:44 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "funciones.h"
#define PROBADA 3
#define RUTA 7

bool valida(int tablero[3][5], int fil, int col){
    bool resultado = false;
    /*dentro de los límites de la matriz*/
    if(fil >= 0 and fil < 3 and col >= 0 and col < 5)
        if(tablero[fil][col] == 1) /* no es pared y no ha sido probada*/
            resultado = true;
    return resultado;
}

bool laberinto(int tablero[3][5], int fil, int col){
    
    bool terminado = false;
    
    if(valida(tablero, fil, col)){
        tablero[fil][col] = PROBADA; /* ya ha sido probada*/
        mostrar(tablero);
        if(fil == 2 and col == 4)
            terminado = true;
        else{
            if (not terminado)
                terminado = laberinto(tablero, fil + 1, col); /*hacia abajo*/
            if (not terminado)
                terminado = laberinto(tablero, fil, col + 1); /*hacia la derecha*/
            if (not terminado)
                terminado = laberinto(tablero, fil -1, col); /*hacia arriba*/
            if(not terminado) 
                terminado = laberinto(tablero, fil, col - 1); /*hacia la izquierda*/  
        }
        mostrar(tablero);
        if(terminado)
            tablero[fil][col] = RUTA;
      
    }
    return terminado;
}

void mostrar(int tablero[3][5]){
 
    for(int i = 0; i< 3; i++){
        for(int j = 0; j < 5; j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}