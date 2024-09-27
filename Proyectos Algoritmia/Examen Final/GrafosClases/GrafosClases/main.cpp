/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Grafo.h"
using namespace std;
#include "funcionesGrafo.h"


/*
 * IMPLEMENTACIÓN DE GRAFOS
 */
int main(int argc, char** argv) {

    struct Grafo grafo;
    
    //Construir el Grafo
    construirGrafo(grafo);
    
    //Agregar los vértices
    agregarVertice(grafo, 'A');
    agregarVertice(grafo, 'B');
    agregarVertice(grafo, 'C');
    agregarVertice(grafo, 'D');
    agregarVertice(grafo, 'E');
    agregarVertice(grafo, 'F');
    
    
    //Eliminar el vértice
    
    
    
    //Agregar las aristas
    agregarArista(grafo, 'A', 'C');
    agregarArista(grafo, 'B', 'C');
    agregarArista(grafo, 'B', 'F');
    agregarArista(grafo, 'C', 'E');
    agregarArista(grafo, 'D', 'A');
    agregarArista(grafo, 'D', 'E');
    agregarArista(grafo, 'E', 'C');
    agregarArista(grafo, 'E', 'F');
    mostrarVerticeYAristas(grafo);
    //eliminarArista(grafo, 'D', 'A');
    eliminarVertice(grafo, 'E');
    eliminarArista(grafo, 'C', 'E');
    eliminarArista(grafo, 'D', 'E');
    
    //Muestra los resultados
    //destruirGrafo(grafo);
    mostrarVerticeYAristas(grafo);
   return 0;
}

