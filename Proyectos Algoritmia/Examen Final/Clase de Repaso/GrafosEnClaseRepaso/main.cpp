/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 20 de junio de 2024, 12:44
 */

#include <iostream>
#include "Grafo.h"
#include "Pila.h"
using namespace std;
#include "funcionesGrafo.h"
#include "funcionesPila.h"

/*
 * IMPLEMENTACIÓN DE GRAFO 2024-2
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
    agregarVertice(grafo, 'G');
    
    agregarArista(grafo, 'A', 'F', 310.25);
    agregarArista(grafo, 'A', 'C', 145.7);
    agregarArista(grafo, 'A', 'B', 275.3);
    agregarArista(grafo, 'B', 'D', 150.10);
    agregarArista(grafo, 'F', 'G', 250.5);
    agregarArista(grafo, 'C', 'D', 244.47);
    agregarArista(grafo, 'D', 'E', 175.50);
    agregarArista(grafo, 'G', 'E', 250.5);
             
    mostrarVerticeYAristas(grafo);
    struct Pila pila;
    construir(pila);
    dameVecinosDeUnVertice(grafo, 'A', pila);
    char letraCiudadMinDistancia;
    double minDistacia = 100000;
    distanciaMinimaEntreUnVerticeYVecinos(grafo, pila, 'A', minDistacia, letraCiudadMinDistancia);
        
    cout<<"Desde la ciudad A, la menor distancia es: "<<minDistacia<<" hacia la ciudad "<<letraCiudadMinDistancia;
    
    mostrarTodosRecorridosDesdeUnaCiudad(grafo, 'A');
    
    return 0;
}

