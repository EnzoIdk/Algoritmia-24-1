/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 27 de abril de 2024, 12:19 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

#include "Cola.h"
#include "funcionesCola.h"
#include "Lista.h"
#include "funcionesLista.h"

using namespace std;

//1er paso: Modificar los nodos
//2do paso: Modificar las listas (agregarles los fin prioridad)
//3er paso: Modificar función encolar;
//4to paso: Modificar las funcionesLista;
//      construirLista(): agregarle los nuevos punteros de fin prioridad a nullptr;
//      insertaencola(struct,int,char):  
//          crearNodo(elemento,prioridad,nullptr); /*modificar la función tmbn con la prioridad*/ 
//     Cranear el inserta en cola
//5to paso: Modificar la función imprimir
//6to: Cambiar los .h

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

