/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * Created on 7 de mayo de 2024, 11:09 PM
 */

#include <iostream>
#include "funciones.h"
using namespace std;

int maxCentro(int * arreglo, int inicio, int centro, int fin) {
    int izq = 0, der = 0;
    
    if (arreglo[centro] > arreglo[centro + 1]) return 1;
    for (int i = centro; i > inicio; i--)
        if (arreglo[i] > arreglo[i - 1])
            izq++;
        else
            break;

    for (int i = centro + 1; i < fin; i++)
        if (arreglo[i + 1] > arreglo[i])
            der++;
        else
            break;
 
    return izq + der + 1 + (arreglo[centro] < arreglo[centro + 1]);
    
    
}

int cuentaIncrementos(int * arreglo, int inicio, int fin) {

    if (inicio == fin) return 1; //Por estar en el intervalo
    int centro = (inicio + fin) / 2;
    int izq = cuentaIncrementos(arreglo, inicio, centro);
    int der = cuentaIncrementos(arreglo, centro + 1, fin);
    int todos = maxCentro(arreglo, inicio, centro, fin);
    return max(max(izq, der), todos);
   
}

int max(int izq, int der) {
    if (izq > der) return izq;
    return der;
}