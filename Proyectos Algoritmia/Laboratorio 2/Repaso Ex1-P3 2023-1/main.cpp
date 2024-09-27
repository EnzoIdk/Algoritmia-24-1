/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 26 de abril de 2024, 21:15
 */

#include <iostream>
#include <streambuf>
using namespace std;

#include "Lista.h"
#include "funciones.h"

int obtenerNodo(struct Lista &tad){
    int elemento;
    struct Nodo * aux;
    
    aux=tad.cabeza;
    elemento=tad.cabeza->elemento;
    tad.cabeza=tad.cabeza->siguiente;
    delete aux;
    return elemento;
}

void formarListas(struct Lista &listaGuerreros, struct Lista &bowser, 
        struct Lista &peach, struct Lista &donkeyKong, int cantGuerreros){
    int poder, lista, elemento;
    for(int i=0; i<cantGuerreros; i++){
        elemento=obtenerNodo(listaGuerreros);
        lista=elemento%10;
        poder=elemento/10;
        if(lista==1) insertarEnOrden(bowser, poder);
        else if(lista==2) insertarEnOrden(peach, poder);
        else insertarEnOrden(donkeyKong, poder);
    }
}

int sumarLista(struct Lista &lista){
    struct Nodo * recorre=lista.cabeza;
    int suma=0;
    while(recorre!=nullptr){
        suma+=recorre->elemento;
        recorre=recorre->siguiente;
    }
    return suma;
}

void insertarListaAListaOrdenada(struct Lista &peach, struct Lista &donkeyKong){
    struct Nodo * auxDD=donkeyKong.cabeza;
    int elemento;
    while(auxDD!=nullptr){
        elemento=auxDD->elemento;
        insertarEnOrden(peach, elemento);
        auxDD=auxDD->siguiente;
    }
}

void pelea(struct Lista &bowser, struct Lista &peach, struct Lista &donkeyKong, 
        int n){
    int nivelAtaquePeach=sumarLista(peach);
    int nivelAtaqueBowser=sumarLista(bowser);
    int nivelAtaqueDonkeyKong=sumarLista(donkeyKong);
    bool yaIntegro=false;
    int peleadorPeach, peleadorBowser;
    int contador=0;
        if(nivelAtaquePeach<nivelAtaqueBowser and not yaIntegro){ 
            insertarListaAListaOrdenada(peach, donkeyKong);
            yaIntegro=true;
            cout<<"DD se une a Peach"<<endl;
            nivelAtaquePeach+=nivelAtaqueDonkeyKong;
        }
    while(true){
        if(esListaVacia(bowser)){
            cout<<"Gana peach"<<endl;
            break;
        }
        if(esListaVacia(peach)){
            cout<<"Gana bowser"<<endl;
            break;
        }
        contador=0;
        while(contador<n){
            peleadorPeach=obtenerNodo(peach);
            peleadorBowser=obtenerNodo(bowser);
            if(peleadorPeach>peleadorBowser){
                insertarAlInicio(peach, peleadorPeach);
                nivelAtaqueBowser-=peleadorBowser;
            }
            else{
                insertarAlInicio(bowser, peleadorBowser);
                nivelAtaquePeach-=peleadorPeach;
            }
            contador++;
        }
    }
}

int main(int argc, char** argv) {
    
    int n=2, cantGuerreros=12;
    
    struct Lista listaGuerreros, bowser, peach, donkeyKong;
    
    construir(listaGuerreros);
    construir(bowser);
    construir(peach);
    construir(donkeyKong);
    
    insertarAlFinal(listaGuerreros, 723);
    insertarAlFinal(listaGuerreros, 182);
    insertarAlFinal(listaGuerreros, 123);
    insertarAlFinal(listaGuerreros, 262);
    insertarAlFinal(listaGuerreros, 851);
    insertarAlFinal(listaGuerreros, 352);
    insertarAlFinal(listaGuerreros, 653);
    insertarAlFinal(listaGuerreros, 103);
    insertarAlFinal(listaGuerreros, 561);
    insertarAlFinal(listaGuerreros, 841);
    insertarAlFinal(listaGuerreros, 391);
    insertarAlFinal(listaGuerreros, 241);
    
    imprime(listaGuerreros);
    
    formarListas(listaGuerreros, bowser, peach, donkeyKong, cantGuerreros);
    
    imprime(listaGuerreros);
    imprime(bowser);
    imprime(peach);
    imprime(donkeyKong);
    
    pelea(bowser, peach, donkeyKong, n);
    
    return 0;
}

