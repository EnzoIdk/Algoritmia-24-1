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
bool seEncuentraAristaEnListaArista(struct Arista listaArista, char llave);
struct NodoArista * obtenerUltimoNodoA( struct Arista  listaArista);
void eliminarAristaEnLista(struct Arista & listaArista, char vertice);
void destruirListaArista(struct Arista & listaArista);

struct NodoArista * crearNodoA(char elemento, struct NodoArista * siguiente, double ponderado);
void insertarAristaAlFinal(struct Arista & listaArista, char vertice, double ponderado);


#endif /* FUNCIONESARISTA_H */