/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 17 de mayo de 2024, 07:49 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Lista.h"
#include "funcionesLista.h"
#include "Bus.h"        

using namespace std;

void leerDatos(int &n,int &capL,int &capR,int &capD,int &capM){
    cout<<"Ingrese la cantidad de camiones: ";
    cin>>n;
    cout<<"Ingrese la capacidad maxima de carga de Leonardo: ";
    cin>>capL;
    cout<<"Ingrese la capacidad maxima de carga de Rafael: ";
    cin>>capR;
    cout<<"Ingrese la capacidad maxima de carga de Donatelo: ";
    cin>>capD;
    cout<<"Ingrese la capacidad maxima de carga de Miguel Angel: ";
    cin>>capM;
    cout<<endl;
}

void leerBuses(struct Bus *buses,int n){
    int aux;
    for(int i=0;i<n;i++){
        cout<<"Ingrese los pesos del Bus Nro. "<<i+1<<": ";
        construir(buses[i].pesos);
        buses[i].pesoTotalBus=0;
        while(true){
            cin>>aux;
            if(aux==0) break;
            insertarencola(buses[i].pesos,aux);
            buses[i].pesoTotalBus+=aux;
        }
    }
}

void cargaBase(int num,int *cromo,int base,int n){
    int i=0;
    for(int j=0;j<n;j++) cromo[j]=0;
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

void invertirListaRec(struct Lista &lista,int n){
    int cabeza;
    if(esListaVacia(lista) or n==1) return;
    cabeza=lista.cabeza->elemento;
    eliminaCabeza(lista);
    invertirListaRec(lista,n-1);
    insertarencola(lista,cabeza);
}

void bubbleSort(struct Lista &lista,int pos){
    struct Nodo *siguiente=lista.cabeza,*aux,*anterior=nullptr;
    int n=lista.longitud;
    for(int i=0;i<n-1;i++){
        siguiente=lista.cabeza;
        anterior=nullptr;
        for(int j=i+1;j<n;j++){
            aux=siguiente->siguiente;
            bool condicion;
            if(pos%2==1) condicion=(aux->elemento<=siguiente->elemento);
            else condicion=(aux->elemento>=siguiente->elemento);
            if(condicion){
                if(anterior==nullptr) lista.cabeza=siguiente->siguiente; 
                else anterior->siguiente=siguiente->siguiente; 
                siguiente->siguiente=aux->siguiente;
                aux->siguiente=siguiente;
            }
            anterior=siguiente;
            siguiente=aux;
        }
    }
}

void unirListas(struct Lista &lista1,struct Lista &lista2){
    lista1.cola->siguiente=lista2.cabeza;
    lista1.cola=lista2.cola;
}

void fusionar(struct Lista &lista1,struct Lista &lista2){
    if(lista1.cola->elemento<=lista2.cabeza->elemento){
        lista1.cola->siguiente=lista2.cabeza;
        lista1.cola=lista2.cola;
    }
    else{
        if(lista1.cabeza->elemento>lista2.cola->elemento){
            lista2.cola->siguiente=lista1.cabeza;
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
                fin=lista1.cola;
            }
            if(!esListaVacia(lista2)){
                fin->siguiente=lista2.cabeza;
                fin=lista2.cola;
            }
            lista1.cabeza=ini;
            lista1.cola=fin;
        }
    }
}

int main(int argc, char** argv) {
    int n=5,capL=34,capR=24,capD=12,capM=30;
    int sumaL,sumaR,sumaD,sumaM;
    struct Bus buses[10];
    leerDatos(n,capL,capR,capD,capM);
    leerBuses(buses,n);
    int cromo[n],solu=-1;
    int combinaciones=(int)pow(4+1,n);
    for(int i=1;i<combinaciones;i++){
        cargaBase(i,cromo,4+1,n);
        if(todoLleno(cromo,n)){
            sumaL=sumaR=sumaD=sumaM=0;
            for(int j=0;j<n;j++){
                if(cromo[j]==1) sumaL+=buses[j].pesoTotalBus;
                else if(cromo[j]==2) sumaR+=buses[j].pesoTotalBus;
                else if(cromo[j]==3) sumaD+=buses[j].pesoTotalBus;
                else if(cromo[j]==4) sumaM+=buses[j].pesoTotalBus;
            }
            if(capL>=sumaL and capR>=sumaR and capD>=sumaD and capM>=sumaM){
                cout<<endl<<"Resultado:"<<endl<<"Los tortuninjas completaron su mision"<<endl;
                solu=i;
                break;
            }
        }
    }
    bool primeraVez[4]{};
    int cant[4]{};
    int pos[4]{};
    if(solu!=-1){
        cargaBase(solu,cromo,4+1,n);
        cout<<endl<<"Los camiones a salvar son: "<<endl;
        for(int i=0;i<4;i++){
            for(int j=0;j<n;j++){
                if(cromo[j]==i+1){
                    cant[i]++;
                    if(cant[i]==1){
                        pos[i]=j;
                        primeraVez[i]=true;
                    }
                    else if(primeraVez[i]){
                        bubbleSort(buses[pos[i]].pesos,1);
                        primeraVez[i]=false;
                    }
                    if(!primeraVez[i]){
                        bubbleSort(buses[j].pesos,cant[i]);
                        unirListas(buses[pos[i]].pesos,buses[j].pesos);
//                        fusionar(buses[pos[i]].pesos,buses[j].pesos);
                    }
                }
            }
            if(i==0) cout<<"Leonardo: ";
            else if(i==1) cout<<"Rafael: ";
            else if(i==2) cout<<"Donatelo: ";
            else cout<<"Miguel Angel: ";
            imprime(buses[pos[i]].pesos);
        }
        cout<<endl;
    }
    else cout<<"Los tortuninjas no completaron su mision"<<endl;
    return 0;
}

