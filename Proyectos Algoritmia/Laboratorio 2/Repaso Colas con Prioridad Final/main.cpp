/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 26 de abril de 2024, 19:54
 */

#include <iostream>

using namespace std;

#include "Lista.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"

int main(int argc, char** argv) {
    
    struct Cola cola;
    
    construir(cola);
    
    encolar(cola, 7411, 'N');
    encolar(cola, 9951, 'N');
    encolar(cola, 3331, 'N');
    encolar(cola, 2513, 'C');
    encolar(cola, 8651, 'C');
    encolar(cola, 7615, 'C');
    encolar(cola, 7452, 'V');
    encolar(cola, 2641, 'V');
    encolar(cola, 8491, 'V');
    encolar(cola, 6542, 'C');
    encolar(cola, 9666, 'C');
    
    imprime(cola);
    
    return 0;
}

