/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 3 de julio de 2024, 12:00 p.m.
 */

#include <iostream>
using namespace std;
#include <cstring>

#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

int imprimePalabra(struct NodoArbol * nodo, char palabra, int &cont, int cl){    
    int izq, der;
    if(not esNodoVacio(nodo)){
        izq=imprimePalabra(nodo->izquierda, palabra, cont, cl);
        
        if(nodo->elemento.letra==palabra){
            cout<<nodo->elemento.letra;
            cont++;
            return nodo->elemento.orden;
        }
        
        der=imprimePalabra(nodo->derecha, palabra, cont, cl);
        
        if(izq!=-1) return izq;
        if(der!=-1) return der;
        return -1;
    }
    return -1;
}

void cuentaPalabra(struct ArbolBinarioBusqueda &palabra, char * busca, 
        int &cont){
    int cantLetras=numeroNodos(palabra.arbolBinario);
    int pos;
    
    for(int i=0; i<strlen(busca); i++){
        pos=imprimePalabra(palabra.arbolBinario.raiz, busca[i], cont, 
                cantLetras);
        if(pos!=-1){
            if(i!=pos-1) cout<<"(X)";
            cout<<" ";
        }
        else cout<<"_ ";
        if(cont==5){
            cout<<endl<<"Felicidades"<<endl;
            break;
        }
    }
    cout<<endl;
}

void buscaPalabra(struct ArbolBinarioBusqueda &palabra, char intentos[][10], 
        int cantIntentos){
    int cont=0, j=1;
    for(int i=0; i<cantIntentos; i++){
        cont=0;
        cout<<"Intento "<<j<<":"<<endl;
        j++;
        if(strlen(intentos[i])>numeroNodos(palabra.arbolBinario)){
            cout<<"La longitud de la pablabra es invalida"<<endl;
            j--;
            continue;
        }
        cuentaPalabra(palabra, intentos[i], cont);
        if(cont==5) break;
    }
    
}

int main(int argc, char ** argv) {
    
    struct ArbolBinarioBusqueda palabra;
    construir(palabra);
    
    struct NodoLetra temp;
    
    temp.letra='E';
    temp.orden=2;
    insertar(palabra, temp);
    
    temp.letra='H';
    temp.orden=1;
    insertar(palabra, temp);
    
    temp.letra='I';
    temp.orden=4;
    insertar(palabra, temp);
    
    temp.letra='L';
    temp.orden=3;
    insertar(palabra, temp);
    
    temp.letra='O';
    temp.orden=5;
    insertar(palabra, temp);
    
    char intentos[][10]={
        {'H', 'D', 'O', 'R', 'A'},
        {'T', 'E', 'O', 'R', 'I', 'A'},
        {'O', 'E', 'N', 'I', 'O'},
        {'H', 'E', 'L', 'I', 'O'}
    };
    
    buscaPalabra(palabra, intentos, 5);
    
    return 0;
}

