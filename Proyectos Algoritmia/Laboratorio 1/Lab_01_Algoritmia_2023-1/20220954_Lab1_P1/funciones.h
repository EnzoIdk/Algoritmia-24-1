/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: aml
 *
 * Created on 26 de marzo de 2024, 12:30 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leerDatos(int *,int &numCamiones,int *arrPesos,int &numPaquetes);
void mostrarDatos(int *,int ,int *,int );
void optimizarPaquetes(int *arrCapacidades,int numCamiones,int *arrPesos,int numPaquetes);
void calculaMaxMinDif(int *diferencia,int nd,int &maxDif,int &minDif);
bool respetaCap(int *dif,int tam);
bool todoLleno(int *arr,int tam);
void cargaBase(int num,int *cromo,int base,int n);

#endif /* FUNCIONES_H */

