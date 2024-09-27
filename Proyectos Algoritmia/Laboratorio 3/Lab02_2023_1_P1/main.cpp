/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de mayo de 2024, 11:37 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;
#define N 5
#define M 6

int detectaVirus(int registro[N][M],int instrucciones[N][M],int buscar,
        int i_ini,int i_fin,int j_ini,int j_fin){
    int i_med,j_med,a1,a2,a3,a4;
    if(i_ini>i_fin or j_ini>j_fin) return 0;
    else if(i_ini==i_fin and j_ini==j_fin){
        if(registro[i_ini][j_ini]==buscar) return instrucciones[i_ini][j_ini];
        else return 0;
    }
    else{
        i_med=(i_ini+i_fin)/2;
        j_med=(j_ini+j_fin)/2;
        a1=detectaVirus(registro,instrucciones,buscar,i_ini,i_med,j_ini,j_med);
        a2=detectaVirus(registro,instrucciones,buscar,i_ini,i_med,j_med+1,j_fin);
        a3=detectaVirus(registro,instrucciones,buscar,i_med+1,i_fin,j_ini,j_med);
        a4=detectaVirus(registro,instrucciones,buscar,i_med+1,i_fin,j_med+1,j_fin);
        return a1+a2+a3+a4;
    }
}

int main(int argc, char** argv) {
    int matriz_registro[N][M]={
        {-1,-2,-3,-4,-5,-6},
        {-7,-8,1,-9,2,-10},
        {-11,1,2,-12,-13,-14},
        {-15,-16,-17,1,-18,-19},
        {-20,1,2,-21,-22,-23},
    };
    int matriz_lineas_instruccion[N][M]={
        {10,5,8,9,8,1},
        {10,5,2,8,2,3},
        {4,2,1,4,8,1},
        {1,2,4,3,5,3},
        {8,3,3,8,5,3},
    };
    int n=5,m=6;
    int buscar;
    int coincidencias,mayor=0,mayorReg;
    for(buscar=1;buscar<=2;buscar++){
        coincidencias=detectaVirus(matriz_registro,matriz_lineas_instruccion,
            buscar,0,n-1,0,m-1);
        cout<<"Para el virus de registro "<<buscar<<", se obtienen "<<coincidencias<<
            " coincidencias en total"<<endl;
        if(coincidencias>mayor){
            mayor=coincidencias;
            mayorReg=buscar;
        }
    }
    if(mayor>=10) cout<<endl<<"Por lo que se considera que el archivo cuenta con"
            " codigo malicioso, especificamente del virus de registro "<<mayorReg<<endl;
    
    return 0;
}

