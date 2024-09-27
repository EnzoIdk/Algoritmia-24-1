/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>   
#include <cstring>

using namespace std;

#include "ColaConEnteros.h"

enum Nodo{DATO,SGTE};

void *leeEntero(ifstream &arch){
    int *dato=new int;
    int aux;
    arch>>aux;
    if(arch.eof()) return nullptr;
    *dato=aux;
    return dato;
}

int intcmp(const void *a,const void *b){
    int *dato1=(int*)a,*dato2=(int*)b;
    return *dato1-*dato2;
}

void imprimeInt(ofstream &arch,void *dat){
    int *dato=(int*)dat;
    arch<<*dato<<endl;
}

/*no hace nada, los inserta en el orden que aparecen*/
int intcmpAux(const void *a,const void *b){
    return -1;
}

int intcmpQsort(const void *a,const void *b){
    void **colaA=(void**)a,**colaB=(void**)b;
    void **nodoA=(void**)(colaA[0]),**nodoB=(void**)(colaB[0]);
    int *dato1=(int*)nodoA,*dato2=(int*)nodoB;
    return *dato1-*dato2;
}