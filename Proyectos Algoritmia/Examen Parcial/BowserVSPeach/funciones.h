/* 
 * File:   funciones.h
 * Author: melow
 *
 * Created on 17 de mayo de 2024, 11:03 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Cola.h"
#include "Lista.h"
#include "funcionesLista.h"
#include "funcionesCola.h"

void insertardatos(struct Lista &warriors, int &n, int &cant_warriros);
void asignarEjercito(struct Lista warriors,struct Lista &bowser, struct Lista &peach,
                     struct Lista &donkey);
void insertarOrdenar(struct Lista &L, int e);
struct Nodo* ubicarAnterior(struct Lista &L, int e);
void muestraEjercito(const struct Lista & tad);
void mostraNivelEjercito(const struct Lista & tad);
void batalla(struct Lista &bowser,struct Lista &peach, struct Lista &donkey, int n);
void fusionar(struct Lista &lista1,struct Lista &lista2);


#endif /* FUNCIONES_H */

