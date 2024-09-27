/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

void insertarAlInicio(struct Lista &, struct Ciudad);
void insertarAlFinal(struct Lista &, struct Ciudad);
void insertarEnOrden(struct Lista &, struct Ciudad);

struct Nodo * crearNodo(struct Ciudad elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, struct Ciudad);
struct Nodo * seEncuentra(const struct Lista &, struct Ciudad);
struct Ciudad retornaCabeza( struct Lista );

const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, struct Ciudad);
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONESLISTA_H */

