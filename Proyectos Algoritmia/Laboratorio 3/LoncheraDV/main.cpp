/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 29 de abril de 2024, 10:21
 */

#include <cstdlib>
#include <iostream>

using namespace std;
#define N 5
#define M 5

/*
 * 
 */

int buscarMenorCaloria(int calorias[N][M],int i,int inicio,int fin){
    if (inicio==fin){
        return calorias[i][inicio];
    }
    int medio = (inicio+fin)/2;
    int menorIzq = buscarMenorCaloria(calorias,i,inicio,medio);
    int menorDer = buscarMenorCaloria(calorias,i,medio+1,fin);
    if (menorIzq<menorDer){
        return menorIzq;
    }
    else {
        return menorDer;
    }
}

void merge(int menorCalorias[N], int inicio, int medio, int fin){
    int aux[N], p, q, m;
    for (p=inicio, q=medio+1, m = inicio; p<=medio && q<=fin; m++){
        if (menorCalorias[p]<menorCalorias[q]){
            aux[m] = menorCalorias[p];
            p++;
        }
        else{
            aux[m] = menorCalorias[q];
            q++;
        }
    }
    
    /*Vamos a verificar si quedan productos en alguno de los lados*/
    while (p<=medio){
        aux[m] = menorCalorias[p];
        m++;
        p++;
    }
    
    while (q<=fin){
        aux[m] = menorCalorias[q];
        m++;
        q++;
    }
    
    /*Ahora paso lo que tenia en auxiliar al arreglo original*/
    for (int i=inicio; i<=fin; i++){
        menorCalorias[i] = aux[i];
    }
}

void mergeSort(int menorCalorias[N],int inicio,int fin){
    if (inicio==fin){
        return ; //Esto es porque cuando se trata de solo un elemento, no debo ordenar nada porque ya esta ordenado
    }
    int medio = (inicio+fin)/2;
    mergeSort(menorCalorias,inicio,medio);
    mergeSort(menorCalorias,medio+1,fin);
    merge(menorCalorias,inicio,medio,fin);
}

int main(int argc, char** argv) {
/*    int calorias[N][M] = {{12,7,9,5,18},
                          {3,7,2,10,20},
                          {25,12,7,8,19},
                          {7,9,2,3,5},
                          {10,12,15,17,9}};*/
    int calorias[N][M];
    int n, m;
    int menorCalorias[N];
    
    cout << "Ingrese la cantidad de tipos de productos: ";
    cin >> n;
    cout << "Ingrese la cantidad de productos por tipo: ";
    cin >> m;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << "Ingrese las calorias del Producto " << j+1 << " del Tipo " << i+1 << ": ";
            cin >> calorias[i][j];
        }
    }
    
    //Vamos a determinar cual es la menor caloria por cada tipo de producto
    for (int i=0; i<n; i++){
        menorCalorias[i] = buscarMenorCaloria(calorias,i,0,m-1);
    }
    //Vamos a imprimir los menores
    for (int i=0; i<n; i++){
        cout << menorCalorias[i] << " ";
    }
    //Vamos a ordenar los productos de menor caloria con mergeSort
    mergeSort(menorCalorias,0,n-1);
    cout << endl;
    //Vamos a imprimir los menores
    for (int i=0; i<n; i++){
        cout << menorCalorias[i] << " ";
    }
    return 0;
}

