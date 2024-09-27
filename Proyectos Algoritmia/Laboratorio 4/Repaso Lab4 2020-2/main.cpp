/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 31 de mayo de 2024, 21:20
 */

#include <iostream>
using namespace std;

#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

void despachar(struct NodoArbol * parbol, int cantidad){
    //CASO FIN
    if(cantidad==0) return;
    //
    struct NodoArbol * aux=minimoArbol(parbol);
    
    if(aux->elemento/10<=cantidad){ //SE BORRA TODO Y SE ELIMINA EL NODO
        cantidad-=aux->elemento/10;
        parbol=eliminarNodoRecursivo(parbol, aux->elemento);
        despachar(parbol, cantidad);
    }
    else{
        aux->elemento-=cantidad*10;
        cantidad=0;
    }
}

int main(int argc, char** argv) {
    
    struct ArbolBinarioBusqueda almacen;
    construir(almacen);
    
    //CANTIDAD - LOTE
    insertar(almacen, 10*10+1);
    insertar(almacen, 3*10+5);
    insertar(almacen, 8*10+6);
    insertar(almacen, 15*10+3);
    insertar(almacen, 14*10+7);
    insertar(almacen, 10*10+4);
    
    preOrden(almacen); cout<<endl;
    
    despachar(almacen.arbolBinario.raiz, 12);
    
    preOrden(almacen); cout<<endl;
    
    return 0;
}

