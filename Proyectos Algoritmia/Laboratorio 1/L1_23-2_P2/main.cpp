/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 13 de abril de 2024, 01:31 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#include "Control.h"

int main(int argc, char** argv) {
    struct Control controles[10];
    int numControles=0,num;
    ifstream arch("Datos.txt",ios::in);
    while(true){
        arch>>controles[numControles].num;
        if(arch.eof()) break;
        arch>>controles[numControles].inversion>>controles[numControles].beneficio;
        controles[numControles].numRequisitos=0;
        if(arch.get()!='\n'){
            while(true){
                arch>>controles[numControles].requisitos[controles[numControles].numRequisitos];
                controles[numControles].numRequisitos++;
                if(arch.get()=='\n') break;
            }
        }
        numControles++;
    }
    
    for(int i=0;i<numControles;i++){
        cout<<controles[i].inversion<<endl;
    }
    
    return 0;
}

