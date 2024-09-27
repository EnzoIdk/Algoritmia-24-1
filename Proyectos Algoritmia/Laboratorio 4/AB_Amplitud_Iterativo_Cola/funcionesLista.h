/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

void insertarAlInicio(struct Lista &, struct NodoArbol *);
void insertarAlFinal(struct Lista &, struct NodoArbol *);
void insertarEnOrden(struct Lista &, struct NodoArbol *);

struct Nodo * crearNodo(struct NodoArbol *elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, struct NodoArbol *);
struct Nodo * seEncuentra(const struct Lista &, struct NodoArbol *);
struct NodoArbol *retornaCabeza(const struct Lista &);

const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, int);
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprimir(const struct Lista &);

#endif /* FUNCIONESLISTA_H */

