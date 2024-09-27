/* 
 * File:   funciones.h
 * Author: ANA RONCAL
 * Created on 4 de octubre de 2023, 09:42 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leerDatos(const char * nombreArch, struct Cliente * cliente);
int funcionHash(int clave);

void modificarDatos(const char * nombreArch, struct Cliente * cliente);
void mostrarCliente(struct Cliente cliente);
void mostrarTodos(struct Cliente * cliente);
void mostrarCabecera();

#endif /* FUNCIONES_H */

