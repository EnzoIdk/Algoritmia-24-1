/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 31 de mayo de 2024, 20:30
 */

#include <iostream>
using namespace std;

#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesArbolesBB.h"

//bool buscaArbolRecursivo(struct NodoArbol * nodo, int dato){
//    if(esNodoVacio(nodo)){
//        return false;
//    } 
//    if(comparaABB(nodo->elemento/100, dato) == 0)
//        return true;
//    if(comparaABB(nodo->elemento/100, dato) == 1)
//        return buscaArbolRecursivo(nodo->izquierda, dato);
//    else
//        if(comparaABB(nodo->elemento/100, dato) == -1) 
//            return buscaArbolRecursivo(nodo->derecha, dato);
//}

struct NodoArbol * buscaNodo(struct NodoArbol * parbol, int dato){
    if(parbol==nullptr) return nullptr;
    //
    if(comparaABB(parbol->elemento/100, dato)==0) return parbol;
    if(comparaABB(parbol->elemento/100, dato)==1)
        return buscaNodo(parbol->izquierda, dato);
    if(comparaABB(parbol->elemento/100, dato)==-1)
        return buscaNodo(parbol->derecha, dato);
}

void fusionarAlmacenes(struct NodoArbol * parbolEmisor, 
        struct NodoArbol * parbolDestino){
    struct NodoArbol * auxPos;
    if(parbolEmisor!=nullptr){
        //RECURSIVIDAD
        fusionarAlmacenes(parbolEmisor->izquierda, parbolDestino);
        fusionarAlmacenes(parbolEmisor->derecha, parbolDestino);
        //AHORA SI IMPLEMENTAMOS
        auxPos=buscaNodo(parbolDestino, parbolEmisor->elemento/100);
        if(auxPos!=nullptr){
            auxPos->elemento+=parbolEmisor->elemento%100;
        }
        else{
            insertarRecursivo(parbolDestino, parbolEmisor->elemento);
        }
    }
    else return;
}

int main(int argc, char** argv) {
    
    struct ArbolBinarioBusqueda destino, emisor;
    construir(destino);
    construir(emisor);
    
    insertar(destino, 20170620*100+20);
    insertar(destino, 20170810*100+20);
    insertar(destino, 20180211*100+20);
    insertar(destino, 20180409*100+10);
    
    insertar(emisor, 20170811*100+5);
    insertar(emisor, 20180211*100+10); 
    insertar(emisor, 20180410*100+15); 
   
    recorrerEnOrden(destino.arbolBinario); cout<<endl;
    recorrerEnOrden(emisor.arbolBinario); cout<<endl;
    
    fusionarAlmacenes(emisor.arbolBinario.raiz, destino.arbolBinario.raiz);
    destruirArbolBB(emisor);
    
    cout<<endl<<"Despues de la fusion:"<<endl;
    recorrerEnOrden(destino.arbolBinario); cout<<endl;
    
    return 0;
}

