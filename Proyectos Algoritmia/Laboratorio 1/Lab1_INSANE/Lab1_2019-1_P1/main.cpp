/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jordy Renzo Esteban Carhuallanqui
 * Code:   20196140
 * Created on 27 de marzo de 2024, 08:33 AM
 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void cargaBin(int num,int*cromo,int tam){
    
    for(int i=0;i<tam;i++){
        cromo[i]=0;
    }
    
    int resto;
    
    while(num>0){
        resto=num%2;
        num=num/2;
        cromo[tam-1]=resto;
        tam--;
    }
}

int main(int argc, char** argv) {
    
    int M=6,W=25;
    int articulos[]={8,2,10,10,5,5};
    int ganancias[]={15,20,5,10,8,5};
    int opciones=(int)pow(2,M);
    int cromo[M];
    int sumaPesosParcial,sumaGanParcial;
    int ganMax=0,opcionSol;
    for(int i=1;i<opciones;i++){
        cargaBin(i,cromo,M);
        sumaPesosParcial=0;
        sumaGanParcial=0;
        for(int j=0;j<M;j++){
            sumaPesosParcial+=cromo[j]*articulos[j];
            sumaGanParcial+=cromo[j]*ganancias[j];
        }
        if(sumaPesosParcial<=W and sumaGanParcial>ganMax){
            ganMax=sumaGanParcial;
            opcionSol=i;
        }
    }
    cargaBin(opcionSol,cromo,M);
    cout<<"Los articulos con la mejor solución: ";
    for(int i=0;i<M;i++){
        if(cromo[i])
            cout<<i+1<<" ";
    }
    cout<<endl;
    cout<<"La ganancia maxima es: "<<ganMax<<endl;
    return 0;
}

