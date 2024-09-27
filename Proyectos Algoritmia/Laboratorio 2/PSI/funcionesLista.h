/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista & tad, int nivel_impacto, char tipo_categoria) ;
void insertarAlFinal(struct Lista &, int nivel_impacto, char tipo_categoria);
void insertarEnOrden(struct Lista &, int);

struct Nodo * crearNodo(int nivel_impacto, char tipo_categoria, struct Nodo * siguiente);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
struct Nodo * seEncuentra(const struct Lista &, int);
int retornaCabeza(const struct Lista &);
void insertarencola(struct Lista & tad, int elemento);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, int);
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONESLISTA_H */

