/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 19 de marzo de 2024, 04:53 PM
 */

#include <iostream>
#include <cmath>
#include "Funciones.h"
#include "Paquete.h"
#define CANT_PAQUETES 6
using namespace std;

int main() {
    //Ingresar los identificadores, pesos y ganancia de la  mochila
    struct Paquete paquetes[CANT_PAQUETES] = {{'A', 8, 15}, 
                                              {'B', 2, 20}, 
                                              {'C', 10, 5}, 
                                              {'D', 10, 10}, 
                                              {'E',  5,  8},
                                              {'F',  5,  5}};
   
    solucionMochilaPesoExacto(paquetes);
    solucionMochilaMaxPeso(paquetes);
    solucionMochilaMaxGanancia(paquetes);
    return 0;
}

