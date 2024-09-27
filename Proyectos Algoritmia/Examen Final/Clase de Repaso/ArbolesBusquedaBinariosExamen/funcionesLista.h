/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 8 de octubre de 2023, 05:44 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
const bool esListaVacia(const struct Lista & tad);
struct NodoPuntaje * crearNodo(const char * equipo, int puntaje, struct NodoPuntaje * siguiente);
struct NodoPuntaje * obtenerNodoAnterior(const struct Lista & tad, int puntaje);
void insertarEnOrden(struct Lista &, const char *, int);
void imprime( struct Lista );
#endif /* FUNCIONESLISTA_H */

