/* 
 * File:   funcionesGrafo.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:19 AM
 */

#ifndef FUNCIONESGRAFO_H
#define FUNCIONESGRAFO_H

void construirGrafo(struct Grafo & grafo);
void agregarVertice(struct Grafo & grafo, char);
bool esGrafoVacio(const struct Grafo & grafo);
void agregarArista(struct Grafo & grafo, char vertice1, char vertice2);
void eliminarVertice(struct Grafo & grafo, char vertice);
int longitudGrafo(const struct Grafo & );

void mostrarVerticeYAristas(const struct Grafo & grafo);
int seEncuentraVerticeOrigen(const struct Grafo & grafo, char vertice);
void eliminarArista(struct Grafo & grafo, char verticeOrigen, char verticeDestino);
void destruirGrafo(struct Grafo & grafo);

#endif /* FUNCIONESGRAFO_H */

