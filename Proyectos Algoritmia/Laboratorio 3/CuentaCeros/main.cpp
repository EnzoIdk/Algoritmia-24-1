/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 6 de mayo de 2024, 09:34 AM
 */

#include <iostream>

using namespace std;

int cuentaCerosAsc(int *arr,int ini,int fin,int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==0) cuentaCerosAsc(arr,med+1,fin,med+1);
    else cuentaCerosAsc(arr,ini,med-1,cont);
}

int cuentaUnosAsc(int *arr,int ini,int fin,int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==0) cuentaUnosAsc(arr,med+1,fin,cont);
    else cuentaUnosAsc(arr,ini,med-1,cont+fin+1-med);
}

int cuentaCerosDesc(int *arr,int ini,int fin,int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==0) cuentaCerosDesc(arr,ini,med-1,cont+fin+1-med);
    else cuentaCerosDesc(arr,med+1,fin,cont);
}

int cuentaUnosDesc(int *arr,int ini,int fin,int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==0) cuentaUnosDesc(arr,ini,med-1,cont);
    else cuentaUnosDesc(arr,med+1,fin,cont+fin+1-med);
}

int mayor(int *arr,int ini,int fin){
    int med=(ini+fin)/2;
    if(ini==fin) return arr[ini];
    int izq=mayor(arr,ini,med);
    int der=mayor(arr,med+1,fin);
    if(izq>der) return izq;
    else return der;
}

int menor(int *arr,int ini,int fin){
    if(ini==fin) return arr[ini];
    int med=(ini+fin)/2;
    int izq=menor(arr,ini,med);
    int der=menor(arr,med+1,fin);
    if(izq<der) return izq;
    else return der;
}

int encontrar3Datos(int *arr,int ini,int fin){
    if(ini>fin) return -1;
    int med=(ini+fin)/2;
    if(arr[med]==arr[med+1] and arr[med]==arr[med-1]) return arr[med+1];
    encontrar3Datos(arr,med+1,fin);
    encontrar3Datos(arr,ini,med-1);
}

int main(int argc, char** argv) {
    int arreglo[7]={0,0,0,0,0,1,1},n=7;
    int arreglo2[7]={1,1,1,1,1,0,0};
    int arreglo3[6]={7,8,3,4,5,6};
    cout<<cuentaCerosAsc(arreglo,0,n-1,0)<<endl;
    cout<<cuentaUnosAsc(arreglo,0,n-1,0)<<endl;
    cout<<cuentaCerosDesc(arreglo2,0,n-1,0)<<endl;
    cout<<cuentaUnosDesc(arreglo2,0,n-1,0)<<endl;
    cout<<mayor(arreglo3,0,5)<<endl;
    cout<<menor(arreglo3,0,5)<<endl;
    int arrRandom[9]={2,2,3,3,4,4,1,1,1};
    cout<<encontrar3Datos(arrRandom,0,8);
    return 0;
}

