/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 2 de septiembre de 2023, 10:43 PM
 */

#include <cstdlib>
using namespace std;
#include "funciones.h"

/*
 * RESOLVER EL LABERINTO
 */
int main(int argc, char** argv) {
 
    int tablero[3][5] = {{1, 0, 1, 1, 1},
                         {1, 1, 1, 0, 1},
                         {0, 0, 1, 0, 1}};
    bool terminado;
    
    //inicializaTablero(matriz);
    mostrar(tablero);
    terminado = laberinto(tablero, 0, 0);
    mostrar(tablero);
    
    return 0;
}

