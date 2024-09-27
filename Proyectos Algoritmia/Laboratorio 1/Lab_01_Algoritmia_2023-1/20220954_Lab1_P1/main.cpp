/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 26 de marzo de 2024, 12:14 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "funciones.h"
#define MAX_CAMION 10
#define MAX_PAQUETE 10

int main(int argc, char** argv) {

    int arrCapacidades[MAX_CAMION]{},numCamiones;
    int arrPesos[MAX_PAQUETE]{},numPaquetes;
    
    
    leerDatos(arrCapacidades,numCamiones,arrPesos,numPaquetes);
    mostrarDatos(arrCapacidades,numCamiones,arrPesos,numPaquetes);
    optimizarPaquetes(arrCapacidades,numCamiones,arrPesos,numPaquetes);
    
    return 0;
}


