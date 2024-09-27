/* 
 * File:   funcionesArboles.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 06:00 PM
 */

#ifndef FUNCIONESARBOLES_H
#define FUNCIONESARBOLES_H

void construir(struct ArbolCampeonato & );

bool esArbolVacio(struct ArbolCampeonato arbol);
bool esNodoVacio(struct NodoCampeonato * nodo);

struct NodoCampeonato * crearNuevoNodoArbol(struct NodoCampeonato *, struct Partido, 
                                           struct NodoCampeonato *);
void plantarArbolBinario(struct ArbolCampeonato &, struct NodoCampeonato *, struct Partido,
                                        struct NodoCampeonato * );
void plantarArbolBinario(struct ArbolCampeonato &, struct ArbolCampeonato, struct Partido,
                                                       struct ArbolCampeonato );
struct Partido raiz(struct NodoCampeonato * nodo);
void imprimeRaiz(struct ArbolCampeonato arbol);
void imprimeNodo(struct NodoCampeonato * nodo);

struct  NodoCampeonato * hijoDerecho(struct ArbolCampeonato );
struct  NodoCampeonato * hijoIzquierdo(struct ArbolCampeonato );

void recorrerEnOrdenRecursivo(struct NodoCampeonato * nodo, const char *);
void recorrerEnOrden(struct ArbolCampeonato , const char *);

#endif /* FUNCIONESARBOLES_H */

