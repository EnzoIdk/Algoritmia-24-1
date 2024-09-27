// -*- C++ -*-

/* 
 * File:   funcionesVertice.h
 * Author: ANA RONCAL
 *
 * Created on 20 de junio de 2024, 13:02
 */

#ifndef FUNCIONESVERTICE_H
#define FUNCIONESVERTICE_H

void construirListaVertice(struct Vertice & listaVertice);
bool seEncuentraVerticeLista(struct Vertice listaVertice, int llave);
void insertarVerticeAlFinal(struct Vertice & listaVertice, int elemento);
struct NodoVertice * obtenerUltimoNodoV( struct Vertice  listaVertice);
struct NodoVertice * crearNodoV(int ciudad, struct NodoVertice * siguiente);
struct NodoVertice * obtenerNodoVertice(struct Vertice listaVertice, int clave);
bool seEncuentraAristaLista(struct Vertice listaVertice, int verticeOrigen, int verticeDestino);
bool esListaVerticeVacio(struct Vertice listaVertice);
void insertarListaAristas(struct Vertice & listaVertice, int verticeOrigen, int verticeDestino, double ponderado);

void eliminarVerticeEnLista(struct Vertice & listaVertice, int vertice);
void eliminarDeListaDeAristas(struct Vertice & listaVertice, int verticeOrigen, int verticeDestino);
void destruirListaVertice(struct Vertice & listaVertice);

#endif /* FUNCIONESVERTICE_H */