// -*- C++ -*-

/* 
 * File:   funcionesArista.h
 * Author: ANA RONCAL
 *
 * Created on 20 de junio de 2024, 13:12
 */

#ifndef FUNCIONESARISTA_H
#define FUNCIONESARISTA_H

void construirListaAristas(struct Arista & listaArista);
bool seEncuentraAristaEnListaArista(struct Arista listaArista, int llave);
struct NodoArista * obtenerUltimoNodoA( struct Arista  listaArista);
void eliminarAristaEnLista(struct Arista & listaArista, int vertice);
void destruirListaArista(struct Arista & listaArista);

struct NodoArista * crearNodoA(int elemento, struct NodoArista * siguiente, double ponderado);
void insertarAristaAlFinal(struct Arista & listaArista, int vertice, double ponderado);


#endif /* FUNCIONESARISTA_H */