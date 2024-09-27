/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de mayo de 2024, 08:23 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits> 
#define M 6
#define N 8

using namespace std;

void merge(char *tabla,int ini,int med,int fin){
    int tamIzq=med-ini+1,tamDer=fin-med;
    int auxIzq[tamIzq+1],auxDer[tamDer+1];
    for(int i=ini;i<=med;i++) auxIzq[i-ini]=tabla[i];
    for(int i=med+1;i<=fin;i++) auxDer[i-med-1]=tabla[i];
    auxIzq[tamIzq]=INT_MIN;
    auxDer[tamDer]=INT_MIN;
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        if(auxIzq[p]>auxDer[q]){
            tabla[i]=auxIzq[p];
            p++;
        }
        else{
            tabla[i]=auxDer[q];
            q++;
        }
    }
}

void mergeSort(char *tabla,int ini,int fin){
    if(ini==fin) return;
    int med=(ini+fin)/2;
    mergeSort(tabla,ini,med);
    mergeSort(tabla,med+1,fin);
    merge(tabla,ini,med,fin);
}

int busquedaBinaria(char *tabla,int ini,int fin){
    if(ini>fin) return N;
    int med=(ini+fin)/2;
    if(tabla[med]==' '){
        if(tabla[med-1]!=' ') return med;
        else busquedaBinaria(tabla,ini,med-1);
    }
    else if(tabla[med]>' ') busquedaBinaria(tabla,med+1,fin);
}

int cuentaC(char *tabla,int ini,int fin,int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(tabla[med]=='C') cuentaC(tabla,ini,med-1,cont+fin+1-med);
    else cuentaC(tabla,med+1,fin,cont);
}

int main(int argc, char** argv) {
    int numLotes=6,numProd=8,posEspacio,cantC;
    double porc=0.7,pi;
    char tabla[M][N]={
        {'F','F','F','C','C','F',' ',' '},
        {'C','F','C','C','C','F','C','F'},
        {'F','C','C','C','C','C','C','C'},
        {'C','C','C','C','C','F','C',' '},
        {'C','F','F','F','F','C',' ',' '},
        {'C','C','F','C','F','C','C',' '}
    };
    for(int i=0;i<numLotes;i++){
        mergeSort(tabla[i],0,numProd-1); /*ordenando descendente*/
        posEspacio=busquedaBinaria(tabla[i],0,numProd-1); /*posEspacio nos da la cantidad*/
        cantC=cuentaC(tabla[i],0,posEspacio-1,0);
        pi=(double)cantC/posEspacio;
        cout<<i+1<<' ';
        if(pi>=porc) cout<<"Aprobado"<<' '<<pi<<endl;
        else cout<<"Rechazado"<<' '<<pi<<endl;
    }
    return 0;
}

