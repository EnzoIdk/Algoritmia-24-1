/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: TAKASHIMA ICHIKAWA, MARIA EDUARDA
 * Codigo: 20190152
 * Created on 29 de mayo de 2024, 09:07 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "RecorridoAmplitud_Iterativo_Cola.h"

int main(int argc, char** argv) {

    struct ArbolBinario arbol, arbol1, arbol2, arbol3, arbol4;

    plantarArbolBinario(arbol, nullptr, 100, nullptr);
    plantarArbolBinario(arbol1, nullptr, 25, nullptr);
    plantarArbolBinario(arbol2, nullptr, 75, nullptr);
    plantarArbolBinario(arbol3, arbol1, 50, arbol2);
    plantarArbolBinario(arbol4, nullptr, 150, nullptr);
    plantarArbolBinario(arbol, arbol3, 100, arbol4);
    /* Arbol construido:     
     *          100
     *         /   \
     *       50     150
     *     /    \
     *    25    75
     */
    
    cout << "Recorrer por amplitud iterativamente usando cola: " << endl;
    recorridoAmplitudIterativoCola(arbol);
    cout << endl;

    return 0;
}


