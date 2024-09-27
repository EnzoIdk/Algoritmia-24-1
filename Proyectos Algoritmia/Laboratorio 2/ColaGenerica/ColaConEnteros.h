/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaConEnteros.h
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 05:43 PM
 */

#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H

void *leeEntero(ifstream &arch);
int intcmp(const void *a,const void *b);
void imprimeInt(ofstream &arch,void *dat);
int intcmpAux(const void*,const void*);
int intcmpQsort(const void *a,const void *b);

#endif /* COLACONENTEROS_H */

