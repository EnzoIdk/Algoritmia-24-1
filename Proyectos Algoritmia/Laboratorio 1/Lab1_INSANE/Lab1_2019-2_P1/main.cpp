/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jordy Renzo Esteban Carhuallanqui
 * Code:   20196140
 * Created on 27 de marzo de 2024, 10:28 AM
 */
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
#define MAX_COL 3

void cargaBin(int num,int cromo[],int tam){
    
    for(int i=0;i<tam;i++)
        cromo[i]=0;
    int resto;
    while(num>0){
        resto=num%2;
        num=num/2;
        cromo[tam-1]=resto;
        tam--;
    }
}
bool verificaPredecesores(int*cromo,int predecesoresFila[]){
    
    for( int i=0;i<MAX_COL;i++){
        if(predecesoresFila[i]>0){
            if(cromo[predecesoresFila[i]-1]==0)
                return false;
        }
    }
    return true;
}
void intercambiar(int&dirA,int&dirB){
    int aux=dirA;
    dirA=dirB;
    dirB=aux;
}
//ORDEN BURBUJA
void ordenarSolus(int*solus,int numSolus){
    for(int i=numSolus-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(solus[j]>solus[j+1])
                intercambiar(solus[j],solus[j+1]);
        }
    }
}
int main(int argc, char** argv) {
    
    int N=8,P=250;
    int cost[]={80,20,100,100,50,10,50,50};
    int ganancia[]={150,80,300,150,80,50,120,150};
    int predecesores[][MAX_COL]={{0,0,0},
                           {0,0,0},
                           {1,2,0},
                           {0,0,0},
                           {0,0,0},
                           {2,0,0},
                           {6,0,0},
                           {6,0,0}};
    int opciones=int(pow(2,N));
    int cromo[N];
    int sumaCostoParcial,sumaGanParcial;
    bool cumplePredecesor;
    int ganMax=0,opcionSol;
    int solus[opciones],numSolus=0;
    int ganancias[opciones];
    for(int i=1;i<opciones;i++){
        cargaBin(i,cromo,N);
        sumaCostoParcial=0;
        sumaGanParcial=0;
        for(int j=0;j<N;j++){
            sumaCostoParcial+=cost[j]*cromo[j];
            sumaGanParcial+=ganancia[j]*cromo[j];
        }
        cumplePredecesor=true;
        for(int j=0;j<N;j++){
            if(!verificaPredecesores(cromo,predecesores[j])){
                cumplePredecesor=false;
                break;
            }
        }
        //if(sumaCostoParcial<=P and ganMax<sumaGanParcial and cumplePredecesor){

        if(sumaCostoParcial<=P /*and P<sumaGanParcial*/ and cumplePredecesor){    
            //ganMax=sumaGanParcial;
            //opcionSol=i;
            solus[numSolus]=i;
            ganancias[numSolus]=sumaGanParcial;
            numSolus++;
        }
    }
    
//    cout<<"La mejor solucion es: ";
//    cargaBin(opcionSol,cromo,N);
    ordenarSolus(ganancias,numSolus);
    for(int i=0;i<numSolus;i++){
        cargaBin(solus[i],cromo,N);
        for(int j=0;j<N;j++)
            if(cromo[j])
                cout<<j+1<<" ";
        cout<<endl;
        cout<<"La ganancia es: "<<ganancias[i]<<endl;
        
    }
//    for(int i=0;i<N;i++){
//        if(cromo[i])
//            cout<<i+1<<" ";
//    }
//    cout<<endl;
//    cout<<"La ganancia total Maxima es: "<<ganMax<<endl;
    
    return 0;
}

