/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 4 de noviembre de 2023, 08:08 AM
 */

#include <iostream>

#include "ArbolBinarioBusqueda.h"
#include "NodoArbol.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

/*
 * 
 */

int min(int n,int m){
    if (n<m)
        return n;
    else
        return m;
}
int max(int n,int m){
    if (n>m)
        return n;
    else
        return m;
}
int Busca_primer_ancestro_comun(struct NodoArbol *raiz,int n,int m){
    if(esNodoVacio(raiz))
        return 0;
    
    if(raiz->elemento>=min(n,m) and raiz->elemento<=max(n,m))return raiz->elemento;
    
    if(raiz->elemento<n and raiz->elemento<m){
        Busca_primer_ancestro_comun(raiz->derecha,n,m);
    }
    else{
        Busca_primer_ancestro_comun(raiz->izquierda,n,m);
    }
        
}

void GuardarCodigos(int *cod,int n,struct NodoArbol *raiz){
    
    if(esNodoVacio(raiz)){
        GuardarCodigos(cod,n,raiz->izquierda);
        cod[n]=raiz->elemento;
        GuardarCodigos(cod,n,raiz->derecha);
        n++;
    }
    
    
    
}

void BalancearArbol(struct ArbolBinarioBusqueda &arbol_token){
    int cod[100];
    int n=0;
    
    GuardarCodigos(cod,n,arbol_token.arbolBinario.raiz);
    cout<<n;
}

void Sumar(struct NodoArbol *raiz1,struct NodoArbol *raiz2){
    if(not esNodoVacio(raiz1) or !esNodoVacio(raiz2)){
        raiz1->elemento+=raiz2->elemento;
        Sumar(raiz1->izquierda,raiz2->izquierda);
        Sumar(raiz1->derecha,raiz2->derecha);
    }
}

void BuscarAncestro(struct NodoArbol *raiz1,struct NodoArbol *raiz2,int ancestro){
    if(not esNodoVacio(raiz1) and not esNodoVacio(raiz2)){
        if(raiz1->elemento==ancestro){
            Sumar(raiz1,raiz2);
            return;
        }
        if(raiz1->elemento<ancestro){
            BuscarAncestro(raiz1->derecha,raiz2->derecha,ancestro);
        }
        else
            BuscarAncestro(raiz1->izquierda,raiz2->izquierda,ancestro);
    }
}

int VerificarArbol(struct NodoArbol *raiz){
    if(esNodoVacio(raiz->izquierda) and esNodoVacio(raiz->derecha))return 1;
    
    if(not esNodoVacio(raiz->derecha)){
        if(raiz->elemento<raiz->derecha->elemento){
            return VerificarArbol(raiz->derecha);
        }
        return 0;
    }
    if(not esNodoVacio(raiz->izquierda)){
        if(raiz->elemento<raiz->izquierda->elemento){
            return VerificarArbol(raiz->izquierda);
        }
        return 0;
    }
    
    
}


int suma_parcial_arboles(struct ArbolBinario &arbol_token,
        struct ArbolBinario arbol_sistema,int ancestro){
    
    BuscarAncestro(arbol_token.raiz,arbol_sistema.raiz,ancestro);
    return VerificarArbol(arbol_token.raiz);
    
}

int main(int argc, char** argv) {

    struct ArbolBinarioBusqueda arbol_token2,arbol_token;
    construir(arbol_token2);
    
    insertar(arbol_token2,3);
    insertar(arbol_token2,5);
    insertar(arbol_token2,3);
    insertar(arbol_token2,1);
    insertar(arbol_token2,5);
    insertar(arbol_token2,4);
    insertar(arbol_token2,5);
    insertar(arbol_token2,2);
    
    postOrden(arbol_token2);
    
    construir(arbol_token);
    
    insertar(arbol_token,5);
    insertar(arbol_token,2);
    insertar(arbol_token,12);
    insertar(arbol_token,1);
    insertar(arbol_token,3);
    insertar(arbol_token,8);
    insertar(arbol_token,4);
    insertar(arbol_token,18);
    
    struct ArbolBinarioBusqueda arbol_sistema;
    construir(arbol_sistema);
    
    insertar(arbol_sistema,3);
    insertar(arbol_sistema,1);
    insertar(arbol_sistema,2);
    insertar(arbol_sistema,5);
    insertar(arbol_sistema,4);
    insertar(arbol_sistema,6);
    insertar(arbol_sistema,7);
    
    
    
    int ancestro=Busca_primer_ancestro_comun(arbol_token.arbolBinario.raiz,1,4);
    cout<<endl;
    cout<<ancestro;
    
    
    int valido=suma_parcial_arboles(arbol_token.arbolBinario,arbol_sistema.arbolBinario,ancestro);
    
    if(valido){
        cout<<"se sumo bien"<<endl;
    }
    
    return 0;
}

