/* 
 * File:   funcionesListaArista.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 11:01 AM
 */

#ifndef FUNCIONESLISTAARISTA_H
#define FUNCIONESLISTAARISTA_H

void construirListaAristas(struct ListaArista & listaArista);
bool seEncuentraAristaEnListaArista(struct ListaArista listaArista, char llave);
struct NodoListaArista * obtenerUltimoNodoA( struct ListaArista  listaArista);
struct NodoListaArista * crearNodoA(char elemento, struct NodoListaArista * siguiente);
void insertarAristaAlFinal(struct ListaArista & listaArista, char vertice);

void eliminarAristaEnLista(struct ListaArista & listaArista, char vertice);
void destruirListaArista(struct ListaArista & listaArista);

#endif /* FUNCIONESLISTAARISTA_H */

