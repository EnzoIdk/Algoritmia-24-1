/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de mayo de 2024, 09:24 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#define N 11
#define NO_ENCONTRADO -1
#include "Almacen.h"

/*2 algoritmos, el del pico máximo para hallar su posición*/
/*luego busquedas binarias ascendente y descendente*/

void leerAlmacenes(struct Almacen *almacenes,int &numAlm,int &codProd){
    cout<<"N= ";
    cin>>numAlm;
    cout<<"Producto= ";
    cin>>codProd;
    cout<<"Ingrese los datos del almacen: "<<endl;
    for(int i=0;i<numAlm;i++) cin>>almacenes[i].codigo>>almacenes[i].stock;
}

int buscaPico(struct Almacen *almacenes,int ini,int fin){
    if(ini>=fin){
        return ini;
    }
    int med=(ini+fin)/2;
    if(almacenes[med].codigo<almacenes[med+1].codigo) buscaPico(almacenes,med+1,fin);
    else buscaPico(almacenes,ini,med);
}

int busquedaBinariaAsc(struct Almacen *almacenes,int ini,int fin,int dato){
    if(ini>fin) return NO_ENCONTRADO;
    int med=(ini+fin)/2;
    if(almacenes[med].codigo==dato) return med;
    else if(almacenes[med].codigo>dato) busquedaBinariaAsc(almacenes,ini,med-1,dato);
    else busquedaBinariaAsc(almacenes,med+1,fin,dato);
}

int busquedaBinariaDesc(struct Almacen *almacenes,int ini,int fin,int dato){
    if(ini>fin) return NO_ENCONTRADO;
    int med=(ini+fin)/2;
    if(almacenes[med].codigo==dato) return med;
    else if(almacenes[med].codigo<dato) busquedaBinariaAsc(almacenes,ini,med-1,dato);
    else busquedaBinariaAsc(almacenes,med+1,fin,dato);
}

int buscaTrio(struct Almacen *almacenes,int ini,int fin){
    if(ini==fin){
        if(almacenes[ini].codigo==almacenes[ini-1].codigo and
                almacenes[ini].codigo==almacenes[ini-2].codigo) return ini;
        else return NO_ENCONTRADO;
    }
    int med=(ini+fin)/2;
    if(med%2==0){
        if(almacenes[med].codigo==almacenes[med+1].codigo) buscaTrio(almacenes,med+2,fin);
        else buscaTrio(almacenes,ini,med);
    }
    else{
        if(almacenes[med].codigo==almacenes[med-1].codigo) buscaTrio(almacenes,med+1,fin);
        else buscaTrio(almacenes,ini,med-1);
    }
}

int main(int argc, char** argv) {
    struct Almacen almacenes[N]
    {
        {10,20},
        {15,20},
        {20,30},
        {80,10},
        {1000,10},
        {200,10},
        {100,20},
        {50,20},
        {20,20},
        {10,10}
    };
    int numAlm=10,codProd=20,posPico,pos1,pos2,cantStock=0;
//    leerAlmacenes(almacenes,numAlm,codProd);
    posPico=buscaPico(almacenes,0,numAlm-1);
//    cout<<almacenes[posPico].codigo<<' '<<almacenes[posPico].stock;
    pos1=busquedaBinariaAsc(almacenes,0,posPico,codProd);
    pos2=busquedaBinariaDesc(almacenes,posPico+1,numAlm-1,codProd);
    if(pos1!=NO_ENCONTRADO) cantStock+=almacenes[pos1].stock;
    if(pos2!=NO_ENCONTRADO) cantStock+=almacenes[pos2].stock;
    cout<<"La cantidad de Stock del producto "<<codProd<<" es: "<<cantStock<<" cajas"<<endl;
    cout<<"Se encuentran en las posiciones: "<<pos1<<" y "<<pos2<<" dentro del almacen"<<endl;
    
    struct Almacen almacenes2[N]
    {
        {1,20},
        {1,20},
        {2,30},
        {2,10},
        {4,10},
        {4,10},
        {5,20},
        {5,20},
        {5,20},
        {6,10},
        {6,10},
    };
    int numAlm2=11,sumaRep=0;
    int posRep=buscaTrio(almacenes2,0,numAlm2-1);
//    cout<<almacenes2[posRep].codigo<<endl;
    cout<<endl<<"Las cajas se encuentran en las posiciones: ";
    for(int i=posRep-2;i<=posRep;i++){
        cout<<i<<' ';
        sumaRep+=almacenes2[i].stock;
    }
    cout<<endl<<"Son del producto "<<almacenes2[posRep].codigo<<endl;
    cout<<"Su stock suma: "<<sumaRep<<endl;
    return 0;
}

