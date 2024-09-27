/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 27 de abril de 2024, 01:51 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"

using namespace std;

void encolar_prioridad(struct Cola &cola,const char *codigo,int prioridad){
    insertarencola(cola.lista,prioridad,codigo);
}

int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    encolar_prioridad(cola,"ISI007",1);
    encolar_prioridad(cola,"ISI006",3);
    encolar_prioridad(cola,"ISI005",2);
    encolar_prioridad(cola,"ISI004",3);
    encolar_prioridad(cola,"ISI003",1);
    encolar_prioridad(cola,"ISI002",1);
    encolar_prioridad(cola,"ISI001",2);
    imprime(cola);
    return 0;
}

