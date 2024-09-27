/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 28 de mayo de 2024, 11:28
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesArbolesBB.h"

void harcodeArbol(struct ArbolBinarioBusqueda &arbol){
    insertar(arbol,5);
    insertar(arbol,2);
    insertar(arbol,1);
    insertar(arbol,3);
    insertar(arbol,4);
    insertar(arbol,12);
    insertar(arbol,8);
    insertar(arbol,18);
}
int encontrarAncestroComunRecursivo(struct NodoArbol *nodo,int valor1,int valor2){
    //CASO BASE
    /*Usaremos el 0 para indicar que se encuentra y el -1 para cuando no*/
    if(esNodoVacio(nodo))
        return -1;//es nullptr
    if(nodo->elemento==valor1 or nodo->elemento==valor2)
        return 0;//encuentra
    if(nodo->izquierda==nullptr and nodo->derecha==nullptr)
        return -1;//es hoja y no encuentra
    
    int izq = encontrarAncestroComunRecursivo(nodo->izquierda,valor1,valor2);
    int der = encontrarAncestroComunRecursivo(nodo->derecha,valor1,valor2);
    
    ////Si encontro en ambas ramas es pq se encontro al ancestro en comun
    if(izq==0 and der==0)     
        return nodo->elemento;
    //Si no encontro en ambas devuelve que no encontro
    else if(izq== -1 and der== -1)
        return -1;                
    //Cuando izq es mayor a 0, es pq ya se encontro el ancestro y devuelve izq
    else if(izq>0) 
        return izq;
    //Cuando der es mayor a 0, es pq ya se encontro el ancestro y devuelve der
    else if(der>0) 
        return der;
    //Si son diferentes (0 y -1) es pq se encontro en algun lado (izq o der)
    else         
        return 0;
}
int busca_primer_ancestro_comun(struct ArbolBinarioBusqueda &arbol,int valor1,int valor2){
    if(!esArbolVacio(arbol)){
        encontrarAncestroComunRecursivo(arbol.arbolBinario.raiz,valor1,valor2);
    }  
}
void devolverCodigoRecursivo(struct NodoArbol *nodo,int codigos[],int &index){
    //CASO BASE
    if(esNodoVacio(nodo))return;
    //Recorre en orden
    devolverCodigoRecursivo(nodo->izquierda,codigos,index);
    codigos[index++]=nodo->elemento;
    devolverCodigoRecursivo(nodo->derecha,codigos,index);
}
void devolverCodigo(struct ArbolBinarioBusqueda &arbol,int codigos[]){
    int index=0;
    if(!esArbolVacio(arbol)){
        devolverCodigoRecursivo(arbol.arbolBinario.raiz,codigos,index);
    }
}
void plantarArbolBalanceado(struct ArbolBinarioBusqueda &arbol,int codigos[],
        int posIni,int posFin){
    //CASO BASE
    if(posIni<=posFin){
        int posMed=(posIni+posFin)/2;

        insertar(arbol,codigos[posMed]);
        plantarArbolBalanceado(arbol,codigos,posIni,posMed-1);    
        plantarArbolBalanceado(arbol,codigos,posMed+1,posFin);  
    }
      
}
void recorrerPorNivelRecursivo(struct NodoArbol *raiz,int altura){
    if(esNodoVacio(raiz))return;
    if(altura==0){
        imprimeNodo(raiz);
    }else if(altura>0){
        recorrerPorNivelRecursivo(raiz->izquierda,altura-1);
        recorrerPorNivelRecursivo(raiz->derecha,altura-1);
    }
}
void recorrerPorNivel(struct ArbolBinarioBusqueda &arbol){
    int h=altura(arbol.arbolBinario);
    for(int i=0;i<=h;i++){
        cout<<"Nivel "<<i<<": ";
        recorrerPorNivelRecursivo(arbol.arbolBinario.raiz,i);
        cout<<endl;
    }
}
int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol_generado;
    struct ArbolBinarioBusqueda arbol_token;
    construir(arbol_generado);
    construir(arbol_token);
    
    int n=8;
    int codigos[n]={3,1,2,5,4,8,5,5};
    
    //Plantar arbol 1 (con condicion)
    for(int i=0;i<n;i++)
        insertar(arbol_generado,codigos[i]);//funcion modificada
    cout<<"Primer arbol: Arbol Generado:"<<endl;
    cout<<"En Orden: ";
    recorrerEnOrden(arbol_generado.arbolBinario);
    cout<<endl;
    cout<<"Por nivel: "<<endl;
    recorrerPorNivel(arbol_generado);
    
    //Devolver el codigo del arbol (en orden) al arreglo
    devolverCodigo(arbol_generado,codigos);
//    for(int i=0;i<n;i++) cout<<codigos[i]<<' ';
    //Plantar arbol token (DyV)
    plantarArbolBalanceado(arbol_token,codigos,0,n-1);//ABB
    
    cout<<endl<<"Segundo arbol: Arbol Balanceado (token)"<<endl;
    cout<<"En Orden: ";
    recorrerEnOrden(arbol_generado.arbolBinario);
    cout<<endl;
    cout<<"Por nivel: "<<endl;
    recorrerPorNivel(arbol_token);
    
    cout<<endl<<"Primer ancestro comun: "
        <<busca_primer_ancestro_comun(arbol_token,5,18);
    
    
    
    return 0;
}

