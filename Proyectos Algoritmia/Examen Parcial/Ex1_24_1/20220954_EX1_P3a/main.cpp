/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani
 *
 * Created on 18 de mayo de 2024, 08:42 AM
 */

#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

struct Lista{
    int id;
    int impacto;
    int riesgo;
};

void mergeR(struct Lista *lista,int ini,int med,int fin){
    int tamIzq=med-ini+1,tamDer=fin-med;
    struct Lista listaIzq[tamIzq+1],listaDer[tamDer+1];
    for(int i=ini;i<=med;i++) listaIzq[i-ini]=lista[i];
    for(int i=med+1;i<=fin;i++) listaDer[i-med-1]=lista[i];
    listaIzq[tamIzq].riesgo=listaIzq[tamIzq].impacto=listaIzq[tamIzq].id=INT_MAX;
    listaDer[tamDer].riesgo=listaDer[tamDer].impacto=listaDer[tamDer].id=INT_MAX;
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        if(listaIzq[p].riesgo<listaDer[q].riesgo or (listaIzq[p].riesgo==listaDer[q].riesgo
                and listaIzq[p].impacto<listaDer[q].impacto) or (listaIzq[p].riesgo==listaDer[q].riesgo
                and listaIzq[p].impacto==listaDer[q].impacto and listaIzq[p].id<listaDer[q].id)){
            lista[i]=listaIzq[p];
            p++;
        }
        else{
            lista[i]=listaDer[q];
            q++;
        }
    }
}

void mergeSortRiesgo(struct Lista *lista,int ini,int fin){
    if(ini==fin) return;
    int med=(ini+fin)/2;
    mergeSortRiesgo(lista,ini,med);
    mergeSortRiesgo(lista,med+1,fin);
    mergeR(lista,ini,med,fin);
}

void mergeI(struct Lista *lista,int ini,int med,int fin){
    int tamIzq=med-ini+1,tamDer=fin-med;
    struct Lista listaIzq[tamIzq+1],listaDer[tamDer+1];
    for(int i=ini;i<=med;i++) listaIzq[i-ini]=lista[i];
    for(int i=med+1;i<=fin;i++) listaDer[i-med-1]=lista[i];
    listaIzq[tamIzq].riesgo=listaIzq[tamIzq].impacto=listaIzq[tamIzq].id=INT_MAX;
    listaDer[tamDer].riesgo=listaDer[tamDer].impacto=listaDer[tamDer].id=INT_MAX;
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        if(listaIzq[p].impacto<listaDer[q].impacto or (listaIzq[p].impacto==listaDer[q].impacto
                and listaIzq[p].riesgo<listaDer[q].riesgo) or (listaIzq[p].riesgo==listaDer[q].riesgo
                and listaIzq[p].impacto==listaDer[q].impacto and listaIzq[p].id<listaDer[q].id)){
            lista[i]=listaIzq[p];
            p++;
        }
        else{
            lista[i]=listaDer[q];
            q++;
        }
    }
}

void mergeSortImpacto(struct Lista *lista,int ini,int fin){
    if(ini==fin) return;
    int med=(ini+fin)/2;
    mergeSortImpacto(lista,ini,med);
    mergeSortImpacto(lista,med+1,fin);
    mergeI(lista,ini,med,fin);
}

void mergeID(struct Lista *lista,int ini,int med,int fin){
    int tamIzq=med-ini+1,tamDer=fin-med;
    struct Lista listaIzq[tamIzq+1],listaDer[tamDer+1];
    for(int i=ini;i<=med;i++) listaIzq[i-ini]=lista[i];
    for(int i=med+1;i<=fin;i++) listaDer[i-med-1]=lista[i];
    listaIzq[tamIzq].riesgo=listaIzq[tamIzq].impacto=listaIzq[tamIzq].id=INT_MAX;
    listaDer[tamDer].riesgo=listaDer[tamDer].impacto=listaDer[tamDer].id=INT_MAX;
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        if(listaIzq[p].id<listaDer[q].id or (listaIzq[p].id==listaDer[q].id
                and listaIzq[p].impacto<listaDer[q].impacto) or (listaIzq[p].id==listaDer[q].id
                and listaIzq[p].impacto==listaDer[q].impacto and listaIzq[p].riesgo<listaDer[q].riesgo)){
            lista[i]=listaIzq[p];
            p++;
        }
        else{
            lista[i]=listaDer[q];
            q++;
        }
    }
}

void mergeSortID(struct Lista *lista,int ini,int fin){
    if(ini==fin) return;
    int med=(ini+fin)/2;
    mergeSortID(lista,ini,med);
    mergeSortID(lista,med+1,fin);
    mergeID(lista,ini,med,fin);
}

void imprimirLista(struct Lista *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i].id<<'-'<<arr[i].impacto<<'-'<<arr[i].riesgo<<"  ";
    }
}

int main(int argc, char** argv) {
    cout<<"Lista de riesgos: (ID-Impacto-Nivel de Riesgo)"<<endl;
    int n=7;
    /*trabajando con estructura de arreglos para simplificar*/
    struct Lista lista[10]={
        {4,1,3},
        {1,2,4},
        {5,3,9},
        {7,2,2},
        {6,3,6},
        {3,2,6},
        {2,1,2}
    };
    imprimirLista(lista,n);
    cout<<endl;
    /*merge sort por cada uno*/
    mergeSortRiesgo(lista,0,n-1);
    imprimirLista(lista,n);
    cout<<"por Nivel de Riesgo"<<endl;
    mergeSortImpacto(lista,0,n-1);
    imprimirLista(lista,n);
    cout<<"por Impacto"<<endl;
    mergeSortID(lista,0,n-1);
    imprimirLista(lista,n);
    cout<<"por ID de Riesgo"<<endl;
    return 0;
}

