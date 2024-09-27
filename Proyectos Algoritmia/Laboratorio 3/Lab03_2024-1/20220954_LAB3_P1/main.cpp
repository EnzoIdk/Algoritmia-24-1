/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 11 de mayo de 2024, 08:02 AM
 */

#include <iostream>
#include <climits>

using namespace std;

#define N 10

int min(int a,int b){
    if(a<b) return a;
    else return b;
}

int sumaCentro(int *arr,int ini,int med,int fin){
    int sumaIzq=0,sumaMinIzq=9999,sumaDer=0,sumaMinDer=9999,sumaTotal=0;
    if(med==ini) return arr[med];
    /*obtenemos las suman del lado izquierdo hasta el medio y del
     medio hacia la derecha*/
    for(int i=med+1;i>ini;i--){
        sumaIzq+=arr[i-1];
        if(sumaIzq<sumaMinIzq) sumaMinIzq=sumaIzq;
    }
    for(int i=med;i<fin;i++){
        sumaDer+=arr[i+1];
        if(sumaDer<sumaMinDer) sumaMinDer=sumaDer;
    }
    sumaTotal=sumaMinDer+sumaMinIzq;
    /*devolvemos el mínimo valor de todo*/
    return min(sumaTotal,min(sumaMinIzq,sumaMinDer));
}

int sumaNegativa(int *arr,int ini,int fin){
    if(ini==fin) return arr[ini];
    int med=(ini+fin)/2;
    int izq=sumaNegativa(arr,ini,med);
    int der=sumaNegativa(arr,med+1,fin);
    int cen=sumaCentro(arr,ini,med,fin);
    return min(cen,min(izq,der));
}

/*solo píden mostrar la suma*/
int main(int argc, char** argv) {
    int arr[N]={2,5,-6,2,3,-1,-5,6},n=8;
    int arr2[N]={2,-3,4,-5,-7},n2=5;
    int arr3[N]={-4,5,6,-4,3,-1,-5,6},n3=8;
    int suma=sumaNegativa(arr,0,n-1);
    cout<<"CASO 1: ";
    if(suma<0) cout<<suma<<endl;
    else cout<<"No hay negativos"<<endl;
    cout<<"CASO 2: ";
    int suma2=sumaNegativa(arr2,0,n2-1);
    if(suma2<0) cout<<suma2<<endl;
    else cout<<"No hay negativos"<<endl;
    cout<<"CASO 3: ";
    int suma3=sumaNegativa(arr3,0,n3-1);
    if(suma3<0) cout<<suma3<<endl;
    else cout<<"No hay negativos"<<endl;
    return 0;
}

