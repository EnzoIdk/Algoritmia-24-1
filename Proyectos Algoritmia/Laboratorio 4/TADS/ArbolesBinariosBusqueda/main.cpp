/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBB.h"
/*
 * ESTRUCTURA ÁRBOL BINARIO BÚSQUEDA 2024-1 
 */
int main(int argc, char** argv) {

   struct ArbolBinarioBusqueda arbol;
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
    
   
    preOrden(arbol); cout<<endl;
    enOrden(arbol);  cout<<endl;
    postOrden(arbol); cout<<endl;
    cout<<"Se encuentra 125 en árbol: "<<buscaArbol(arbol, 125)<<endl;
     
    eliminarNodo(arbol, 125);
    enOrden(arbol);   cout<<endl;
      
    auxiliarElemento = minimoNodoABB(arbol);
    cout<<"Mínimo ABB: "<<auxiliarElemento<<endl;
    //LISTO
    auxiliarElemento = maximoNodoABB(arbol);
    cout<<"Máximo ABB: "<<auxiliarElemento<<endl;
        
    cout<<"Sumar nodos: "<<sumarNodos(arbol)<<endl;
    
    destruirArbolBB(arbol);
      
    return 0;
}

