/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 18 de mayo de 2024, 08:07 AM
 */

#include <iostream>
#include <cmath>
#include "Lista.h"
#include "Producto.h"
#include "funciones.h"


using namespace std;

void fusionaListas(struct Lista &lista1,struct Lista &lista2){
    struct Nodo *cola1=obtenerUltimoNodo(lista1);
    struct Nodo *cola2=obtenerUltimoNodo(lista2);
    if(cola1->elemento<=lista2.cabeza->elemento){
        cola1->siguiente=lista2.cabeza;
        cola1=cola2;
    }
    else{
        if(lista1.cabeza->elemento>=cola2->elemento){
            cola2->siguiente=lista1.cabeza;
            lista1.cabeza=lista2.cabeza;
        }
        else{
            struct Nodo *ini,*fin;
            ini=fin=nullptr;
            while(!esListaVacia(lista1) and !esListaVacia(lista2)){
                if(lista1.cabeza->elemento<=lista2.cabeza->elemento){
                    if(ini==nullptr){
                        ini=lista1.cabeza;
                        fin=lista1.cabeza;
                    }
                    else{
                        fin->siguiente=lista1.cabeza;
                        fin=lista1.cabeza;
                    }
                    lista1.cabeza=lista1.cabeza->siguiente;
                }
                else{
                    if(ini==nullptr){
                        ini=lista2.cabeza;
                        fin=lista2.cabeza;
                    }
                    else{
                        fin->siguiente=lista2.cabeza;
                        fin=lista2.cabeza;
                    }
                    lista2.cabeza=lista2.cabeza->siguiente;
                }
            }
            if(!esListaVacia(lista1)){
                fin->siguiente=lista1.cabeza;
                fin=lista1.cabeza;
            }
            if(!esListaVacia(lista2)){
                fin->siguiente=lista2.cabeza;
                fin=lista2.cabeza;
            }
            lista1.cabeza=ini;
            cola1=obtenerUltimoNodo(lista1);
            cola1=fin;
        }
    }
}

void ingresoDatos(int &cant,struct Producto *productos){
    cout<<"Ingrese la cantidad de tipos de producto: ";
    cin>>cant;
    int aux;
    for(int i=0;i<cant;i++){
        cout<<"Tipo de Producto: ";
        cin>>productos[i].tipo;
        cout<<"Calorias de los productos "<<productos[i].tipo<<": ";
        construir(productos[i].calorias);
        productos[i].totalCal=0;
        while(true){
            cin>>aux;
            insertarAlFinal(productos[i].calorias,aux);
            productos[i].totalCal+=aux;
            if(cin.get()=='\n') break;
        }
    }
}

struct Formula{
    int cant;
    char tipo;
    int calMax;
};

int cargaBase(int num,int *cromo,int base,int n){
    for(int i=0;i<n;i++) cromo[i]=0;
    int i=0;
    while(num>0){
        cromo[i]=num%base;
        num/=base;
        i++;
    }
}

bool todoLleno(int *cromo,int n){
    for(int i=0;i<n;i++){
        if(cromo[i]==0) return false;
    }
    return true;
}

int buscarProd(struct Producto *prod,int cant,char tipo){
    for(int i=0;i<cant;i++){
        if(prod[i].tipo==tipo) return i;
    }
}

int main(int argc, char** argv) {
    /*estructuras auxiliares para guardar datos*/
    struct Producto productos[6];
    struct Formula formulas[6];
    int cantTipos,cantForm;
    ingresoDatos(cantTipos,productos);
    cout<<"Ingrese la cantidad de productos a la formula: ";
    cin>>cantForm;
    for(int i=0;i<cantForm;i++){
        cout<<"Tipo de productos : ";
        cin>>formulas[i].tipo;
        cout<<"Cantidad de Productos del Tipo "<<formulas[i].tipo<<": ";
        cin>>formulas[i].cant;
        cout<<"Total de calorias maximas de todos los productos "<<formulas[i].tipo<<": ";
        cin>>formulas[i].calMax;
    }
    int pos,primero;
    bool solu=true;
    for(int i=0;i<cantForm;i++){
        pos=buscarProd(productos,cantTipos,formulas[i].tipo);
        if(i==0) primero=pos;
        /*si el total de las calorías que tenemos es mayor que el de la fórmula, no hay solución*/
        if(formulas[i].calMax<productos[pos].totalCal){
            cout<<"No hay solucion"<<endl;
            solu=false;
            break;
        }
        if(i!=0){
            fusionaListas(productos[primero].calorias,productos[pos].calorias);
        }
    }
    if(solu) imprime(productos[primero].calorias);
    return 0;
}

