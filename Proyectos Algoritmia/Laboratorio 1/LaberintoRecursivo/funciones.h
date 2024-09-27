/* 
 * File:   funciones.h
 * Author: ANA RONCAL
 * Created on 2 de septiembre de 2023, 10:44 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H


void inicializaTablero(int ** & matriz);
bool valida(int tablero[3][5], int fil, int col);
bool laberinto(int tablero[3][5], int, int);
void mostrar(int tablero[3][5]);

#endif /* FUNCIONES_H */

