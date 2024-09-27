/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBB.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO BÚSQUEDA 2024-1 
 */
int main(int argc, char** argv) {
    ArbolBinarioBusqueda almacen;
    
    construir(almacen);
    insertar(almacen,{20180211,20});
    insertar(almacen,{20170620,20});
    insertar(almacen,{20170810,20});
    insertar(almacen,{20180409,10});
      
    postOrden(almacen);
    
    return 0;
}

