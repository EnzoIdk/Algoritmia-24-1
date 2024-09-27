/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 20 de junio de 2024, 12:44
 */

#include <iostream>
#include "Grafo.h"
using namespace std;
#include "funcionesGrafo.h"

/*
 * IMPLEMENTACIÓN DE GRAFO 2024-2
 */
int main(int argc, char** argv) {
    
    struct Grafo grafo;
    
    //Construir el Grafo
    construirGrafo(grafo);

    //Agregar los vértices
    agregarVertice(grafo, 1);
    agregarVertice(grafo, 2);
    agregarVertice(grafo, 3);
    agregarVertice(grafo, 4);
    agregarVertice(grafo, 5);
    agregarVertice(grafo, 6);
    agregarVertice(grafo, 7);
    
    agregarArista(grafo, 1, 6, 16.4);
    agregarArista(grafo, 1, 3, 19.1);
    agregarArista(grafo, 1, 2, 10.9);
    agregarArista(grafo, 2, 4, 9.4);
    agregarArista(grafo, 6, 7, 19);
    agregarArista(grafo, 3, 4, 11);
    agregarArista(grafo, 4, 5, 0.5);
    agregarArista(grafo, 7, 5, 20.0);
             
    mostrarVerticeYAristas(grafo);
  
    
    return 0;
}

