/* 
 * File:   funciones.h
 * Author: ANA RONCAL
 * Created on 8 de mayo de 2024, 06:27 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void pasarAPila(struct Cola & cola, struct Pila & pila1, struct Pila & pila2, int cant);
void reiniciaCola(struct Cola & cola, int longitud, struct Pila & pila1, struct Pila & pila2);
void ordenarPila(struct Pila & pila, int num);
void reclasificaPilas(struct Pila & pila1, struct Pila & pila2);

#endif /* FUNCIONES_H */

