/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 2 de diciembre de 2023, 09:03 AM
 */

#include <iostream>
#include <cstring>
#include "funcionesArbolesBinarios.h"
#include "ArbolBinario.h"

#include "NodoArbol.h"

using namespace std;
#define N 10

int esParte(char palabra[N],char elemento,int longitud){
    
    
    for(int i=0;i<longitud;i++){
        if(palabra[i]==elemento) return i;
    }
    
    return -1;
}


int BuscarPalabra(char palabra[N],struct NodoArbol * arbol15,int longitud,int pos){
    if(arbol15==nullptr or pos>longitud)return 0;
    
    char a=arbol15->elemento;
    int lugar=esParte(palabra,a,longitud);
    
    char car=palabra[lugar];
    
    
    
    if(longitud-1==pos and lugar!=-1 and arbol15->derecha==nullptr and
            arbol15->izquierda==nullptr){
        palabra[lugar]='0';
        return 1;
    }
    
    
    
    if(lugar!=-1){
        palabra[lugar]='0';
        if(BuscarPalabra(palabra,arbol15->izquierda,longitud,pos+1)){
            return 1;
        }
        if(BuscarPalabra(palabra,arbol15->derecha,longitud,pos+1)){
            return 1;
        }
        
        palabra[lugar]=car;
    }
    
    
    return 0;
    
}



/*
 * 
 */
int main(int argc, char** argv) {

//    char palabra[10]={'F','I','N','A','L'};
    
    struct ArbolBinario arbol,arbol2,arbol3,arbol4;
    struct ArbolBinario arbol5,arbol6,arbol7,arbol8;
    struct ArbolBinario arbol9,arbol10,arbol11,arbol12;
    struct ArbolBinario arbol13,arbol14,arbol15;
    
    plantarArbolBinario(arbol,nullptr,'O',nullptr);
    plantarArbolBinario(arbol4,nullptr,'T',nullptr);
    plantarArbolBinario(arbol5,nullptr,'F',nullptr);
    plantarArbolBinario(arbol6,arbol5,'A',arbol4);
    plantarArbolBinario(arbol2,arbol.raiz,'C',nullptr);
    plantarArbolBinario(arbol3,arbol2.raiz,'C',nullptr);
    plantarArbolBinario(arbol7,arbol6.raiz,'N',nullptr);
    plantarArbolBinario(arbol8,arbol3,'I',arbol7);
    
    plantarArbolBinario(arbol9,nullptr,'T',nullptr);
    plantarArbolBinario(arbol10,arbol9.raiz,'G',nullptr);
    plantarArbolBinario(arbol11,nullptr,'R',nullptr);
    
    plantarArbolBinario(arbol12,arbol11.raiz,'E',arbol10.raiz);
    plantarArbolBinario(arbol13,nullptr,'E',nullptr);
    plantarArbolBinario(arbol14,arbol13.raiz,'D',arbol12.raiz);
    
    plantarArbolBinario(arbol15,arbol14.raiz,'L',arbol8.raiz);
    

    
    
    //PARTE B
    char frase[3][N]={{'F','I','N','A','L'},
                        {'D','E','L'},
                       {'C','I','C','L','O'}};
    
//    char frase[3][N]={{'F','I','N','A','L'},
//                        {'C','O','N'},
//                       {'B','I','K','A'}};
    int contador=0;
    for(int i=0;i<3;i++){
        char copia[10];
        char palabra[10];
        strcpy(palabra,frase[i]);
        strcpy(copia,frase[i]);
        
        
        int longitud=strlen(palabra);
        //FUNCION DE LA PARTE A
        int solucion=BuscarPalabra(palabra,arbol15.raiz,longitud,0);

        if(solucion){
            cout<<copia<<" ";
            contador++;
        }
        else{
            break;
        }
    }
    
    if(contador!=3){
        cout<<"No se encontro el mensaje completo.";
    }
    
    return 0;
}

