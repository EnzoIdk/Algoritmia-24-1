/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 05:37 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstdlib>

using namespace std;

#include "BibliotecaColaGenerica.h"
#include "ColaConEnteros.h"

int main(int argc, char** argv) {
    void *cola1,*cola2;
    crearCola("datos.txt",cola1,leeEntero,intcmp);
    imprimirCola(cola1,imprimeInt,"reporte1.txt");
//    crearCola("datos2.txt",cola2,leeEntero,intcmpAux);
    crearCola("datos2.txt",cola2,leeEntero,intcmp);
    imprimirCola(cola2,imprimeInt,"reporte2.txt");
    void *cola3;
    construirCola(cola3);
//    cout<<desencolar(cola1)<<endl;
//    cout<<desencolar(cola1)<<endl;
//    cout<<desencolar(cola1)<<endl;
//    imprimirCola(cola1,imprimeInt,"reporte3.txt");
    encolar(cola3,10,intcmpAux);
    encolar(cola3,12,intcmpAux);
    encolar(cola3,11,intcmpAux);
    imprimirCola(cola3,imprimeInt,"prueba.txt");
//    fusionar(cola1,cola3);
//    cout<<longitud(cola1)<<endl;
//    imprimirCola(cola1,imprimeInt,"PruebaFusion.txt");
//    cout<<desencolar(cola1)<<endl;
//    cout<<longitud(cola1)<<endl;
//    encolar(cola3,desencolar(cola1),intcmpAux);
//    imprimirCola(cola3,imprimeInt,"prueba2.txt");
//    cout<<longitud(cola1)<<endl;
//    problemaCueva(cola1,cola2,cola3,intcmpAux,longitud(cola1));
//    imprimirCola(cola3,imprimeInt,"Resultado.txt");
    
//    qsort(cola2,longitud(cola2),sizeof(void*),intcmpQsort); 
//    imprimirCola(cola2,imprimeInt,"reporte2.txt");
    return 0;
}

