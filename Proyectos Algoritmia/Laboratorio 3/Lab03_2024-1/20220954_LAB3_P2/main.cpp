/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 11 de mayo de 2024, 08:03 AM
 */

#include <iostream>

using namespace std;

#define N 15

/*el cuentaceros*/
int cuentaNoPositivos(int *arr,int ini,int fin,int cont){
    if(ini>=fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]>0) return cuentaNoPositivos(arr,ini,med,cont);
    else return cuentaNoPositivos(arr,med+1,fin,med+1); 
}

/*el sube y baja*/
int buscaPico(int *arr,int ini,int fin){
    if(ini==fin) return arr[ini];
    int med=(ini+fin)/2;
    if(arr[med]>arr[med+1]) return buscaPico(arr,ini,med);
    else return buscaPico(arr,med+1,fin);
}

int main(int argc, char** argv) {
    int celda[N],n;
    /*14 datos para el primer ejemplo, 17 para el otro*/
    cout<<"Ingrese el numero de datos: ";
    cin>>n;
    cout<<"Ingrese los "<<n<<" datos: "<<endl;
    for(int i=0;i<n;i++) cin>>celda[i];
    /*Buscamos donde comienza la radiacion con un "cuentaCeros" pero de no positivos*/
    int pos=cuentaNoPositivos(celda,0,n-1,0);
    /*Buscamos el valor máximo en el sube y baja de la parte positiva*/
    int max=buscaPico(celda,pos,n-1);
    cout<<"La radiacion empieza a "<<pos<<" km. Potencia maxima "<<max<<" megatones"<<endl;
    return 0;
}

