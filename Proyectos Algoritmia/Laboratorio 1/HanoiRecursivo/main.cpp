/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 12 de abril de 2024, 09:00 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

void hanoi(int n,char origen,char aux,char destino){
    /*caso base*/
    if(n==1){
        cout<<"Se manda disco 1 desde "<<origen<<" a "<<destino<<endl;
        return;
    }
    /*se llevan los n-1 discos del origen al auxiliar*/
    hanoi(n-1,origen,destino,aux);
    cout<<"Se manda disco "<<n<<" desde "<<origen<<" a "<<destino<<endl;
    /*se llevan los n-1 discos del auxiliar al destino*/
    hanoi(n-1,aux,origen,destino);
}

int main(int argc, char** argv) {
    int n=4;
    hanoi(n,'A','B','C');
    return 0;
}

