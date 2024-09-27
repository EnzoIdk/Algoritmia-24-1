/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <cstdlib>
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

/*
 * IMPLEMENTA ARBOLES DE BÚSQUEDA BINARIA
 */
int main(int argc, char** argv) {

    struct ArbolBinarioBusqueda arbol, arbol2;
    int auxiliarElemento;
    
    construir(arbol);
    insertar(arbol, 100);
    insertar(arbol, 50);
    insertar(arbol, 150);
    insertar(arbol, 125);
    insertar(arbol, 175);
    insertar(arbol, 200);
    insertar(arbol, 25);
    insertar(arbol, 75);
    
    preOrden(arbol); 
    enOrden(arbol);  
    postOrden(arbol);
    
    construir(arbol2);
    insertar(arbol2, 5);
    insertar(arbol2, 15);
    insertar(arbol2, 3);
    insertar(arbol2, 7);
    insertar(arbol2, 10);
    
    preOrden(arbol2); 
    enOrden(arbol2); 
    postOrden(arbol2); 
    
    auxiliarElemento = minimoABB(arbol);
    cout<<"Mínimo ABB: "<<auxiliarElemento<<endl;
    
    auxiliarElemento = maximoABB(arbol);
    cout<<"Máximo ABB: "<<auxiliarElemento<<endl;
        
    cout<<"Sumar nodos: "<<sumarNodos(arbol)<<endl;
    
    //borraNodo(arbol, 100);
    cout<<"RECORRIDO POR NIVEL"<<endl;
    recorridoPorNivel(arbol); 
    enOrden(arbol); 
    
    /*cout<<"En orden iterativo "<<endl;
    enOrdenIterativo(arbol.arbolBinario);*/
    
    cout<<"Preorden iterativo"<<endl;
    preOrdenIterativo(arbol.arbolBinario);
      
    destruirArbolBB(arbol);
    destruirArbolBB(arbol2);
       
      
    return 0;
}

