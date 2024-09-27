/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 30 de enero de 2024, 12:30 AM
 */

#include <iostream>
#include <cstdlib>
#include "funciones.h"

using namespace std;

/*
 * Usando la técnica de Divide y vencerás
 * Acertijo de Hanoi
 */
int main(int argc, char** argv) {
    
    int numDiscos=3; //cambiar el número de discos según sea necesario
//    cout<<"Ingrese el número de discos: ";
//    cin >> numDiscos;
    /*A es la torre inicial, B es la torre auxiliar y C es la torre final*/
    cout <<"RESULTADO DE HANOI: "<<endl;
    hanoi(numDiscos, 'A', 'B', 'C'); 

    return 0;
}

