/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

//void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista & tad, int elemento, int detector) ;
//void insertarAlFinal(struct Lista &, int);
void insertarEnOrden(struct Lista &, int);

struct Nodo * crearNodo(int elemento, int detector, struct Nodo * siguiente);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
struct Nodo * seEncuentra(const struct Lista &, int);
void retornaCabeza(const struct Lista & tad, int &elemento, int &detector);
void insertarencola(struct Lista & tad, int detector, int elemento);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, int);
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONESLISTA_H */

