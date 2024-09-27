/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 7 de mayo de 2024, 11:09 PM
 */

#include <iostream>
#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int n = 10;
    int arreglo[n] = {7, 2, 9, 10, 16, 10, 13, 8, 2, 10};

    int cuenta = cuentaIncrementos(arreglo, 0, n - 1);
    cout << "Incrementos: " << cuenta;
    return 0;
}

