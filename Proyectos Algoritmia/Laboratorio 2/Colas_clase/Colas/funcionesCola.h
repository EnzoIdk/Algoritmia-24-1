/* 
 * File:   funcionesCola.h
 * Author: ANA RONCAL
 * Created on 18 de abril de 2024, 10:28 AM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construir(struct Cola & );       
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, int elemento);
void imprimir(const struct Cola & cola);
int desencolar(struct Cola & cola);

void cifrado(const struct Cola & clave, const struct Cola & copiaClave);

#endif /* FUNCIONESCOLA_H */

