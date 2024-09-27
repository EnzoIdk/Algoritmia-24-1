/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"



//void despacha(NodoArbol *ptrArbol, int cant){
//    int falta,lote;
//    NodoArbol *ptraux;
//    
//    if(cant==0)  return;
//    ptraux = ptrArbol;
//    ptraux = minimoArbol(ptraux);
//    if(ptraux->elemento.cantidad<=cant) 
//    {
//        falta = cant - ptraux->elemento.cantidad;
////        lote = ptraux->elemento.lote;
////        imprimeNodo(ptraux);
//        ptrArbol=eliminarNodoRecursivo(ptrArbol,ptraux->elemento.lote);
//        despacha(ptrArbol,falta);
//    }  
//    else{
//        ptraux->elemento.cantidad -= cant;
////        imprimeNodo(ptraux);
//    }
//}




void despacha(struct NodoArbol *parbol,int cant){
    if(cant==0) return;
    struct NodoArbol *aux=minimoArbol(parbol);
    if(aux->elemento.cantidad<=cant){
        cant-=aux->elemento.cantidad;
        parbol=eliminarNodoRecursivo(parbol,aux->elemento.lote);
        despacha(parbol,cant);
    }
    else{
        aux->elemento.cantidad-=cant;
        cant=0;
    }
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda almacen;
    
    construir(almacen);
    
    insertar(almacen,{20180211,20});
    insertar(almacen,{20170810,20});
    insertar(almacen,{20170620,20});
    insertar(almacen,{20180409,10});
    
    recorrerPreOrden(almacen.arbolBinario);
    cout <<endl;
    recorrerEnOrden(almacen.arbolBinario);
    cout <<endl;
    despacha(almacen.arbolBinario.raiz,35);
    cout <<endl;
    recorrerEnOrden(almacen.arbolBinario);         
            
    return 0;
}

