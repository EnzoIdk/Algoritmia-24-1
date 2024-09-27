/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 13 de abril de 2024, 08:03 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

#include "Guerrero.h"
#include "Arma.h"

void leerDatosGuerreros(struct Guerrero *guerreros,int &numDatos){
    ifstream arch("Datos.txt",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Datos.txt"<<endl;
        exit(1);
    }
    int n;
    while(true){
        arch>>n;
        if(arch.eof()) break;
        arch>>guerreros[numDatos].poder;
        guerreros[numDatos].numArmas=0;
        while(true){
            arch>>guerreros[numDatos].tipoArma[guerreros[numDatos].numArmas];
            guerreros[numDatos].numArmas++;
            if(arch.get()=='\n') break;
        }
        numDatos++;
    }
}

void leerArmas(struct Arma *armas,int &numDatos){
    ifstream arch("Armas.txt",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Armas.txt"<<endl;
        exit(1);
    }
    while(true){
        arch>>armas[numDatos].arma;
        if(arch.eof()) break;
        arch>>armas[numDatos].poder>>armas[numDatos].tipo;
        armas[numDatos].numReq=0;
        if(arch.get()!='\n'){
            while(true){
                arch>>armas[numDatos].armasReq[armas[numDatos].numReq];
                armas[numDatos].numReq++;
                if(arch.get()=='\n') break;
            }
        }
        numDatos++;
    }
}

int buscarLetra(struct Arma *armas,int num,char arma){
    for(int i=0;i<num;i++){
        if(armas[i].arma==arma) return i;
    }
    return -1;
}

bool evaluaRequisitos(struct Arma *armas,int num,int *cromo){
    int posLetra;
    for(int i=0;i<num;i++){
        for(int j=0;j<armas[i].numReq;j++){
            posLetra=buscarLetra(armas,num,armas[i].armasReq[j]);
            if(cromo[i]!=0 and cromo[i]!=cromo[posLetra]) return false;
        }
    }
    return true;
}

bool evaluaTipo(struct Arma *armas,struct Guerrero *guerreros,int numA,int numG,
        int *cromo){
    int esTipo;
    for(int i=0;i<numG;i++){
        for(int j=0;j<numA;j++){
            if(cromo[j]==i+1){
                esTipo=0;
                for(int k=0;k<guerreros[i].numArmas;k++){
                    if(armas[j].tipo==guerreros[i].tipoArma[k]) esTipo=1;
                }
                if(!esTipo) return false;
            }
        }
    }
    return true;
}

bool superaGuerreros(int *poderTotal,struct Guerrero *guerreros,int num){
    for(int i=0;i<num;i++){
        if(poderTotal[i]<guerreros[i].poder) return false;
    }
    return true;
}

void cargaBase(int num,int *cromo,int n,int base){
    int i=0;
    for(int i=0;i<n;i++) cromo[i]=0;
    while(num>0){
        cromo[i]=num%base;
        num/=base;
        i++;
    }
}

int main(int argc, char** argv) {
    int numGue=0,numArm=0;
    struct Guerrero guerreros[3];
    struct Arma armas[12];
    leerDatosGuerreros(guerreros,numGue);
    leerArmas(armas,numArm);
    int cromo[numArm];
    int combinaciones=(int)pow(numGue+1,numArm);
    int poderTotal[3];
    for(int i=1;i<combinaciones;i++){
        cargaBase(i,cromo,numArm,numGue+1);
        for(int i=0;i<numGue;i++) poderTotal[i]=0;
        if(evaluaRequisitos(armas,numArm,cromo)){
            if(evaluaTipo(armas,guerreros,numArm,numGue,cromo)){
                for(int j=0;j<numGue;j++){
                    for(int k=0;k<numArm;k++){
                        if(cromo[k]==j+1){
                            poderTotal[j]+=armas[k].poder;
                        }
                    }
                }
            }
        }
        if(superaGuerreros(poderTotal,guerreros,numGue)){
            for(int i=0;i<numGue;i++){
                cout<<"Guerrero "<<i+1<<endl;
                cout<<"Poder: "<<guerreros[i].poder<<endl;
                cout<<"Armas en mochila para vencerlo: ";
                for(int j=0;j<numArm;j++){
                    if(cromo[j]==i+1){
                        cout<<armas[j].arma<<' ';
                    }
                }
                cout<<endl;
            }
            cout<<endl;
            break;
        }
    }
    return 0;
}

