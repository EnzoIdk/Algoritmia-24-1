/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 5 de mayo de 2024, 12:07 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int cuentaSeguidas(int *evaluaciones,int peso,int &dia,int ini,int med,int fin){
    int cont=1;
    if(evaluaciones[med]!=peso) return 0;
    for(int i=med;i>ini;i--){
        if(evaluaciones[i-1]==peso) cont++;
        else break;
    }
    for(int i=med;i<fin;i++){
        if(evaluaciones[i+1]==peso) cont++;
        else{
            dia=i+1;
            break;
        }
    }
    return cont;
}

int hallarDias(int *evaluaciones,int peso,int &dia,int ini,int fin){
    if(ini==fin){
        if(evaluaciones[ini]==peso) return 1;
        else return 0;
    }
    int med=(ini+fin)/2;
    int izq=hallarDias(evaluaciones,peso,dia,ini,med);
    int der=hallarDias(evaluaciones,peso,dia,med+1,fin);
    int centro=cuentaSeguidas(evaluaciones,peso,dia,ini,med,fin);
    return max(max(izq,der),centro);
}

int hallarMenor(int *evaluaciones,int ini,int fin){
    if(ini==fin) return evaluaciones[ini];
    int med=(ini+fin)/2;
    int izq=hallarMenor(evaluaciones,ini,med);
    int der=hallarMenor(evaluaciones,med+1,fin);
    if(izq<der) return izq;
    else return der;
}

int main(int argc, char** argv) {
    int evaluaciones[30],n=30,dia=0;
    cout<<"Ingrese las evaluaciones del paciente dia por dia, desde el dia 1 al dia 30:"<<endl;
    for(int i=0;i<n;i++) cin>>evaluaciones[i];
    int menorPeso=hallarMenor(evaluaciones,0,n-1);
    int rango=hallarDias(evaluaciones,menorPeso,dia,0,n-1);
    cout<<"El menor peso fue de "<<menorPeso<<". El rango de dias en que lo obtuvo fue"<<
            " del "<<dia-rango+1<<" al "<<dia<<endl;
    return 0;
}

