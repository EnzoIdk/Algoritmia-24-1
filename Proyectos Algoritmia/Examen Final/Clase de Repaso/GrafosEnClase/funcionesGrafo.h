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
bool seEncuentraVertice(const struct Grafo & grafo, int elemento);
void agregarVertice(struct Grafo & grafo, int elemento);
void mostrarVerticeYAristas(const struct Grafo & grafo);
bool esGrafoVacio(struct Grafo grafo);
void agregarArista(struct Grafo & grafo, int vertice1, int vertice2, double ponderado);

void eliminarVertice(struct Grafo & grafo, int vertice);
void eliminarArista(struct Grafo & grafo, int verticeOrigen, int verticeDestino);
void destruirGrafo(struct Grafo & grafo);


#endif /* FUNCIONESGRAFO_H */