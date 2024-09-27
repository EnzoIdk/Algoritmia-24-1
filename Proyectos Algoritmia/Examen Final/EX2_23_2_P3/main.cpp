/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 2 de julio de 2024, 03:03 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#define V 9
using namespace std;

bool servidores(int matriz[][9], int cantEtiquetas, int cantActivos, int *arrAct){
    for(int i=0;i<cantActivos;i++){
        for(int j=i+1;j<cantActivos;j++){
            if(matriz[i][j]>1){
                if(arrAct[i]==arrAct[j])
                    arrAct[j]++;
                if(arrAct[j]>cantEtiquetas){
                    cout<<"No hay solucion";
                    return false;
                }
            }
        }
    }
    return true;
}

int main(int argc, char** argv) {
    int matriz[][9]={{1,2,0,6,0,0,0,0,2},
                     {7,1,5,2,0,0,0,0,7},
                     {0,3,1,2,3,8,9,7,5},
                     {2,7,5,1,2,0,0,0,0},
                     {0,0,5,3,1,4,0,0,0},
                     {0,0,9,0,6,1,2,0,0},
                     {0,0,3,0,0,7,1,4,0},
                     {0,0,4,0,0,0,9,1,9},
                     {5,3,6,0,0,0,0,4,1}};
    int arrAct[9]={1,1,1,1,1,1,1,1,1};
    if(servidores(matriz,4,9,arrAct)){
        for(int i=0;i<9;i++){
            cout<<i+1<<' '<<arrAct[i]<<endl;
        }
    }
    return 0;
}

