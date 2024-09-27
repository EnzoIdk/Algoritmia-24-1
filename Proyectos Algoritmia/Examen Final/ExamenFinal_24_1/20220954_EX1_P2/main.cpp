/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 6 de julio de 2024, 09:34 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ArbolBinarioBusqueda.h"
#include "Cola.h"
#include "funcionesArbolesBB.h"
#include "funcionesCola.h"
#include "funcionesArbolesBinarios.h"

using namespace std;

struct Emocion{
    char tipo;
    int pesos[3];
    int numPesos;
};

struct Combinacion{
    int tipos[3];
};

struct NodoArbol *buscaNodo(struct NodoArbol *parbol,int dato){
    if(esNodoVacio(parbol) or dato==-1) return nullptr;
    else{
        if(parbol->elemento==dato) return parbol;
        else{
            if(dato<parbol->elemento) buscaNodo(parbol->izquierda,dato);
            else buscaNodo(parbol->derecha,dato);
        }
    }
}

//vemos si tiene al menos un peso de la emoción que busca
bool seEncuentraEmocion(struct NodoArbol *parbol,struct Emocion emocion){
    for(int i=0;i<emocion.numPesos;i++){
        if(buscaArbolRecursivo(parbol,emocion.pesos[i])) return true;
    }
    return false;
}

//vemos que cumpla que tiene todos
bool cumpleCombinacion(struct NodoArbol *parbol, struct Emocion *emociones,
        struct Combinacion comb,int numEmociones){
    for(int i=0;i<3;i++){
        int posEmocion;
        for(posEmocion=0;posEmocion<numEmociones;posEmocion++){
            if(comb.tipos[i]==emociones[posEmocion].tipo) break; 
        }
        if(!seEncuentraEmocion(parbol,emociones[posEmocion])) return false;
    }
    return true;
}

//algoritmo para recorrer por niveles
void recorrerEnAmplitud(struct ArbolBinarioBusqueda arbol,struct Emocion *emociones,
        struct Combinacion *combinaciones,int numEmociones,int numComb){
    struct Cola cola;
    if(esArbolVacio(arbol)) return;
    construir(cola);
    struct NodoArbol *parbol=arbol.arbolBinario.raiz;
    encolar(cola,parbol->elemento);
    encolar(cola,-1); //ningún elemento tiene de dato 0
    int dato,nivel=0;
    int cantComb[5]{};
    while(longitud(cola)>1){
        dato=desencolar(cola);
        parbol=buscaNodo(arbol.arbolBinario.raiz,dato); 
        if(parbol){
            //verificamos en todas las combinaciones
            for(int i=0;i<numComb;i++){
                if(cumpleCombinacion(parbol,emociones,combinaciones[i],numEmociones)){
                    cantComb[nivel]++;
                    break;
                }
            }
            //encolamos para continuar con el recorrido
            if(!esNodoVacio(parbol->izquierda)) encolar(cola,parbol->izquierda->elemento);
            if(!esNodoVacio(parbol->derecha)) encolar(cola,parbol->derecha->elemento);
        }
        else{
            cout<<"Nivel "<<nivel+1<<" - "<<cantComb[nivel]<<" combinaciones"<<endl;
            nivel++;
            if(nivel==3) break;
            encolar(cola,-1);
        }
    }
}

//lectura de datos
void leerEmociones(const char *nombArch,struct Emocion *emociones,int &num){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir "<<nombArch<<endl;
        exit(1);
    }
    num=0;
    while(true){
        arch>>emociones[num].tipo;
        if(arch.eof()) break;
        arch>>emociones[num].numPesos;
        for(int i=0;i<emociones[num].numPesos;i++){
            arch>>emociones[num].pesos[i]; 
        }
        num++;
    }
}

void leerCombinaciones(const char *nombArch,struct Combinacion *combinaciones,int &num){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir "<<nombArch<<endl;
        exit(1);
    }
    arch>>num;
    for(int i=0;i<num;i++){
        for(int j=0;j<3;j++){
            arch>>combinaciones[num].tipos[j];
        }
    }
}
int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    struct Emocion emociones[10];
    struct Combinacion combinaciones[5];
    int numEmociones,numComb;
    leerEmociones("emociones.txt",emociones,numEmociones);
    leerCombinaciones("combinaciones.txt",combinaciones,numComb);
//    cout<<numEmociones<<' '<<numComb<<endl;
    construir(arbol);
    insertar(arbol,180);
    insertar(arbol,120);
    insertar(arbol,250);
    insertar(arbol,100);
    insertar(arbol,150);
    insertar(arbol,230);
    insertar(arbol,280);
    insertar(arbol,80);
    insertar(arbol,140);
    insertar(arbol,160);
    insertar(arbol,200);
    insertar(arbol,240);
    insertar(arbol,260);
    insertar(arbol,90);
//    enOrden(arbol);cout<<endl;
    recorrerEnAmplitud(arbol,emociones,combinaciones,numEmociones,numComb);
    return 0;
}

