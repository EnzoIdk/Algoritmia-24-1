/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * Created on 30 de enero de 2024, 12:36 AM
 */

#include <iostream>
using namespace std;


void hanoi(int n, char desde, char auxiliar, char hacia){
    
    //caso base
    if (n == 1){
        cout<<"Mover disco 1 desde la torre "<< desde << " hacia la torre "
            << hacia << endl;
        return;
    }
    //llevo los n-1 discos de A a B
    hanoi(n-1, desde, hacia, auxiliar);
    cout<<"Mover disco "<< n << " desde la torre " << desde << " hacia la torre " 
        << hacia << endl;
    //llevo los n-1 discos de B a C
    hanoi(n-1, auxiliar, desde, hacia);
}

