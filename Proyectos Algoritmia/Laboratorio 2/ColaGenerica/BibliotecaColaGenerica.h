/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaColaGenerica.h
 * Author: Enzo
 *
 * Created on 2 de mayo de 2024, 05:43 PM
 */

#ifndef BIBLIOTECACOLAGENERICA_H
#define BIBLIOTECACOLAGENERICA_H

void crearCola(const char *nombArch,void *&cola,void *(*lee)(ifstream &),
        int (*cmp)(const void*,const void*));
void construirCola(void *&cola);
void inicializarCola(void *&cola);
void insertar(void *&cola,void *dato,int (*cmp)(const void*,const void*));
void crearNuevoNodo(void **&nuevoNodo,void *dato);
void imprimirCola(void *cola,void (*imprime)(ofstream &,void*),const char *nombArch);
bool esColaVacia(void *cola);
int longitud(void *cola);
void encolar(void *&cola,int dat,int (*cmp)(const void*,const void*));
void fusionar(void *&cola1,void *&cola2);
int desencolar(void *&cola);
void problemaCueva(void *&cola1,void *&cola2,void *&cola3,int (*cmp)(const void*,const void*),int);

#endif /* BIBLIOTECACOLAGENERICA_H */

