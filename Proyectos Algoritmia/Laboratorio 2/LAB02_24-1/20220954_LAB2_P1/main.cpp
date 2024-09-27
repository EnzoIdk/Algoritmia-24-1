/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 27 de abril de 2024, 08:07 AM
 */

#include <iostream>
#include <iomanip>

#include "funcionesCola.h"
#include "funcionesLista.h"
#include "Cola.h"
#include "Lista.h"

using namespace std;

int main(int argc, char** argv) {
    struct Cola cola;
    
    /*las funciones de lista y cola fueron modificadas para la resolución del problema*/
    construir(cola);
    encolar(cola,30,5,1943,"BXQ778");
    encolar(cola,20,4,2014,"HRP112");
    encolar(cola,26,6,1975,"PRL625");
    encolar(cola,22,10,1949,"MKP157");
    encolar(cola,13,5,2020,"ARH749");
    encolar(cola,14,2,1930,"HRQ931");
    imprime(cola);
    return 0;
}

