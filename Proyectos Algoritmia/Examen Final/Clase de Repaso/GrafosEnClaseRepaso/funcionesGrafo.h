// -*- C++ -*-

/* 
 * File:   funcionesGrafo.h
 * Author: ANA RONCAL
 *
 * Created on 20 de junio de 2024, 12:56
 */

#ifndef FUNCIONESGRAFO_H
#define FUNCIONESGRAFO_H

void construirGrafo(struct Grafo & grafo);
bool seEncuentraVertice(const struct Grafo & grafo, char elemento);
void agregarVertice(struct Grafo & grafo, char elemento);
void mostrarVerticeYAristas(const struct Grafo & grafo);
bool esGrafoVacio(struct Grafo grafo);
void agregarArista(struct Grafo & grafo, char vertice1, char vertice2, double ponderado);

void eliminarVertice(struct Grafo & grafo, char vertice);
void eliminarArista(struct Grafo & grafo, char verticeOrigen, char verticeDestino);
void destruirGrafo(struct Grafo & grafo);

void dameVecinosDeUnVertice(const struct Grafo & grafo, char vertice, struct Pila & pila);
void distanciaMinimaEntreUnVerticeYVecinos(const struct Grafo & grafo, struct Pila & pila, 
        char verticeOrigen, double & minDistacia, char & letraCiudadMinDistancia);
void mostrarTodosRecorridosDesdeUnaCiudad(const struct Grafo & grafo, char ciudadOrigen);
#endif /* FUNCIONESGRAFO_H */