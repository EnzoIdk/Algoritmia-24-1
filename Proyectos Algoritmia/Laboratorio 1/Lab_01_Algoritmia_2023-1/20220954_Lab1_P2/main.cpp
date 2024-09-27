/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 12 de abril de 2024, 11:39 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cmath>

using namespace std;

void cargaBin(int num,int *cromo,int n){
    int i=0;
    for(int i=0;i<n;i++) cromo[i]=0;
    while(num>0){
        cromo[i]=num%2;
        num/=2;
        i++;
    }
}

int main(int argc, char** argv) {
    
    int izq[5]={100,90,95,85,105},n=5;
    int der[5]={90,98,75,96,93};
    int robots[6]={77,82,81,90,92,75},r=6;
    int cromo[n]; /*0 para izquierda y 1 para derecha*/
    int combinaciones=pow(2,n),solu=0;
    bool rompe;
    for(int i=1;i<combinaciones;i++){
        cargaBin(i,cromo,n);
        rompe=false;
        for(int j=0;j<n;j++){
            for(int k=0;k<r;k++){
                if(cromo[j]==0){
                    if(robots[k]>izq[j]){
                        rompe=true;
                        break;
                    }
                }
                else{
                    if(robots[k]>der[j]){
                        rompe=true;
                        break;
                    }
                }
            }
            if(rompe) break;
        }
        if(!rompe){
            solu++;
            cout<<"SOLUCION "<<solu<<':'<<endl;
            for(int j=0;j<n;j++){
                cout<<setw(4)<<' '<<"Nivel "<<j+1<<": ";
            }
            cout<<endl<<setw(4)<<' ';
            for(int j=0;j<n;j++){
                if(cromo[j]==0) cout<<"Izquierda"<<setw(4)<<' ';
                else cout<<"Derecha"<<setw(6)<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}

