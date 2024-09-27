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
#include "BibliotecaColaGenerica.h"

enum Nodo{DATO,SGTE};
enum Cola{INICIO,FIN,LONG};

void crearCola(const char *nombArch,void *&cola,void *(*lee)(ifstream &),
        int (*cmp)(const void*,const void*)){
    void *dato;
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    construirCola(cola);
    while(true){
        dato=lee(arch);
        if(arch.eof()) break;
        insertar(cola,dato,cmp);
    }
}

void construirCola(void *&cola){
    cola=nullptr;
    inicializarCola(cola);
}

void inicializarCola(void *&cola){
    void **registro=new void*[2];
    int *longitud=new int{0};
    registro[INICIO]=nullptr;
    registro[FIN]=nullptr;
    registro[LONG]=longitud;
    cola=registro;
}


void encolar(void *&cola,int dat,int (*cmp)(const void*,const void*)){
    int *dato=new int{dat};
    insertar(cola,dato,cmp);
}

void insertar(void *&cola,void *dato,int (*cmp)(const void*,const void*)){
    void **registroCola=(void**)cola;
    void **nuevoNodo,**ptActual,**ptAnt=nullptr;
    int *longitud;
    crearNuevoNodo(nuevoNodo,dato);
    if(registroCola[INICIO]==nullptr){
        registroCola[INICIO]=nuevoNodo;
        registroCola[FIN]=nuevoNodo;
        longitud=(int*)registroCola[LONG];
        (*longitud)++;
    }
    else{
        ptActual=(void**)registroCola[INICIO];
        while(ptActual){
            if(cmp(ptActual[DATO],dato)>0) break;
            ptAnt=ptActual;
            ptActual=(void**)ptActual[SGTE];
        }
        nuevoNodo[SGTE]=ptActual;
        if(ptAnt==nullptr) registroCola[INICIO]=nuevoNodo;
        else{
            ptAnt[SGTE]=nuevoNodo;
            if(ptActual==nullptr) registroCola[FIN]=nuevoNodo;
        }
        longitud=(int*)registroCola[LONG];
        (*longitud)++;
    }
}

void crearNuevoNodo(void **&nuevoNodo,void *dato){
    nuevoNodo=new void*[2];
    nuevoNodo[DATO]=dato;
    nuevoNodo[SGTE]=nullptr;
}

void imprimirCola(void *cola,void (*imprime)(ofstream &,void*),const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void **regCola=(void**)cola;
    void **ptActual=(void**)regCola[INICIO];
    while(!esColaVacia(ptActual)){
        imprime(arch,ptActual[DATO]);
        ptActual=(void**)ptActual[SGTE];
    }
}

bool esColaVacia(void *cola){
    if(cola==nullptr) return true;
    else return false;
}

int longitud(void *cola){
    void **registroCola=(void**)cola;
    int *longitud=(int*)registroCola[LONG];
    return *longitud;
}

void fusionar(void *&cola1,void *&cola2){
    void **regCola1=(void**)cola1,**regCola2=(void**)cola2;
    void **fin1=(void**)regCola1[FIN];
    int *long1=(int*)regCola1[LONG],*long2=(int*)regCola2[LONG];
    fin1[SGTE]=regCola2[INICIO];
    regCola1[FIN]=regCola2[FIN];
    (*long1)+=(*long2);
}

int desencolar(void *&cola){
    void **regCola=(void**)cola;
    void **cabeza=(void**)regCola[INICIO];
    int *longitud=(int*)regCola[LONG];
    int *elemento=(int*)cabeza[DATO];
    
    cabeza=(void**)cabeza[SGTE];
    delete cabeza;
    (*longitud)--;
    return *elemento;
}

void problemaCueva(void *&cola1,void *&cola2,void *&cola3,int (*cmp)(const void*,const void*),
        int n){
    void **regCola1=(void**)cola1,**regCola2=(void**)cola2;
    void **cabeza1,**cabeza2=(void**)regCola2[INICIO];
    int elemento1,elemento2;
    for(int i=0;i<n;i++){
        elemento1=desencolar(cola1);
        elemento2=desencolar(cola2);
        if(elemento1>=elemento2) encolar(cola3,elemento1,cmp);
        else encolar(cola3,elemento2,cmp);
    }
}