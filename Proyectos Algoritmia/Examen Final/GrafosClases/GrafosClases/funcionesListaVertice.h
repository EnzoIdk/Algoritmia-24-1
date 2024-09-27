/* 
 * File:   funcionesListaVertice.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:38 AM
 */

#ifndef FUNCIONESLISTAVERTICE_H
#define FUNCIONESLISTAVERTICE_H

void construirListaVertice(struct ListaVertice & listaVertice);
bool esListaVerticeVacio(struct ListaVertice listaVercice);
bool seEncuentraVerticeLista(struct ListaVertice listaVercice, char elemento);
struct NodoListaVertice * crearNodoV(char elemento, struct NodoListaVertice * siguiente);
struct NodoListaVertice * obtenerUltimoNodoV( struct ListaVertice listaVertice);
void insertarVerticeAlFinal(struct ListaVertice & listaVertice, char element);
bool seEncuentraAristaLista(struct ListaVertice listaVertice, char verticeOrigen, char verticeDestino);
struct NodoListaVertice * obtenerNodoVertice(struct ListaVertice listaVertice, char clave);
void insertarListaAristas(struct ListaVertice &, char verticeOrigen, char verticeDestino);

void eliminarVerticeEnLista(struct ListaVertice & listaVertice, char vertice);
void eliminarDeListaDeAristas(struct ListaVertice & listaVertice, char verticeOrigen, char verticeDestino);
void destruirListaVertice(struct ListaVertice & listaVertice);
#endif /* FUNCIONESLISTAVERTICE_H */

