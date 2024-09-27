/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;


int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    cout<<"La cola está vacía: "<<esColaVacia(cola)<<endl;
    encolar(cola, 8);
    encolar(cola, 21);
    encolar(cola, 10);
    encolar(cola, 15);
    encolar(cola, 7);
    
    imprime(cola);
    cout<<desencolar(cola)<<endl;
    imprime(cola);
    
    destruirCola(cola);

    return 0;
}

