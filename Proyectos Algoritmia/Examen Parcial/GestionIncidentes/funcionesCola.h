/* 
 * File:   funcionesCola.h
 * Author: ANA RONCAL
 * Created on 18 de abril de 2024, 03:57 PM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construir(struct Cola & cola);
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, int elemento);
int desencolar(struct Cola & cola);
void imprimir(const struct Cola & cola);
int longitud(const struct Cola &);

#endif /* FUNCIONESCOLA_H */

