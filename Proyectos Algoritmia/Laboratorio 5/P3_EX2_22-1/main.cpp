/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 14 de junio de 2024, 01:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ArbolBinarioBusqueda.h"
#include "funcionesABB.h"
#include "NodoGen.h"

using namespace std;

void leerRecursivo(ifstream &arch,struct ArbolBinarioBusqueda &arbol,int n){
    if(n==0) return;
    struct NodoGen aux;
    arch>>aux.id>>aux.letra;
    insertar(arbol,aux);
    leerRecursivo(arch,arbol,n-1);
}

void leerPalabra(const char *nombArch,struct ArbolBinarioBusqueda &arbol,int &cant){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch>>cant;
    leerRecursivo(arch,arbol,cant);
}

bool ordenCorrecto(struct NodoArbol *parbol,struct NodoGen dato){
    if(parbol==nullptr) return false;
    if(parbol->elemento.letra==dato.letra){
        return parbol->elemento.id==dato.id;
    }
    else if(parbol->elemento.id>dato.id){
        return ordenCorrecto(parbol->izquierda,dato);
    }
    else{
        return ordenCorrecto(parbol->derecha,dato);
    }
}

bool verificacion(int i,int n,struct ArbolBinarioBusqueda arbol,char *palabra,bool flag){
    if(i>n){
        return flag;
    }
    struct NodoGen auxNodo={i,palabra[i-1]};
    if(buscaArbol(arbol,auxNodo)){ //busca si la letra se encuentra en el arbol
        if(ordenCorrecto(arbol.arbolBinario.raiz,auxNodo)){ //te devuelve si está en su posición
                                                            //correcta o no
            cout<<auxNodo.letra<<" ";
        }
        else{
            cout<<auxNodo.letra<<"(X) ";
            flag=false;
        }
    }
    else{
        cout<<"_ ";
        flag=false;
    }
    //verificando siguientes letras
    return verificacion(i+1,n,arbol,palabra,flag);
}

void balword(int i,int n,ArbolBinarioBusqueda arbol){
    if(i>n){
        cout<<"Lo siento, se acabaron los intentos"<<endl;
        return;
    }
    char palabra[10];
    cout<<"Intento "<<i<<": ";
    cin>>palabra;
    while(strlen(palabra)!=n){
        cout<<"La longitud de la palabra ingresada no es la correcta. Vuelva "
                "a intentarlo"<<endl;
        cout<<"Intento "<<i<<": ";
        cin>>palabra;
    }
    if(verificacion(1,n,arbol,palabra,true)){
        cout<<endl<<"Felicitaciones por haber resuelto el reto"<<endl;
        return;
    }
    cout<<endl;
    balword(i+1,n,arbol);
}

void impresionAux(int i,int n){
    if(i>n){
        cout<<endl;
        return;
    }
    cout<<"_ ";
    impresionAux(i+1,n);
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda palabra;
    construir(palabra);
    int cant,intentos=5;
    leerPalabra("PalabraIncognita.txt",palabra,cant);
    cout<<"BIENVENIDO AL JUEGO DE BALWORD"<<endl;
    cout<<"Descubre la palabra de "<<cant<<" letras. Tiene maximo "<<intentos<<
            " intentos"<<endl;
    int i=1;
    impresionAux(i,intentos);
    balword(i,cant,palabra);
    return 0;
}

