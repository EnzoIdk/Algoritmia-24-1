/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 29 de abril de 2024, 11:26
 */

#include <cstdlib>
#include <iostream>
#define M 11
#define N 5
#define R 5
using namespace std;


/*
 * 
 */

void imprimeSobrante(char letras[N][M],int i, int inicio,int fin){
    if (letras[i][inicio]==letras[i][fin]){
        if (fin!=inicio+1 && inicio!=fin){
            cout << "La fila " << i+1 << " tiene un " << letras[i][inicio] << " adicional" << endl;
        } 
        return ;
    }
    int medio = (inicio+fin)/2;
    if (medio%2==1){
        if (letras[i][medio-1]==letras[i][medio] && letras[i][medio]!=letras[i][medio+1]){
            imprimeSobrante(letras,i,medio+1,fin);
        }
        else {
            imprimeSobrante(letras,i,inicio,medio+1);
        }
    }
    else {
        if (letras[i][medio]!=letras[i][medio-1] && letras[i][medio]==letras[i][medio+1]){
            imprimeSobrante(letras,i,medio,fin);
        }
        else{
            imprimeSobrante(letras,i,inicio,medio);
        }
    }
}

void imprimePrecioMayor(int precios[N][R],int i,int inicio,int fin){
    int medio= (inicio+fin)/2;
    if (precios[i][medio]>precios[i][medio-1] && precios[i][medio+1]<precios[i][medio]){
        cout << "En la fila " << i+1 << ", el pasajero del asiento " << medio + 1 << " tiene el bocadito más caro que sus 2 vecinos" << endl;
        return ;
    }
    if (precios[i][medio]<precios[i][medio-1]){
        imprimePrecioMayor(precios,i,inicio,medio);
    }
    else{
        imprimePrecioMayor(precios,i,medio,fin);
    }
}

int main(int argc, char** argv) {
    char letras[N][M] = {{'O','O','C','C','A','A','E','E','R','R','R'},
                         {'C','C','A','A','R','R','E','E','B','B',' '},
                         {'R','R','E','E','C','C','F','F','A','A',' '},
                         {'E','E','F','F','A','A','A','B','B','R','R'},
                         {'C','C','C','A','A','R','R','O','O','E','E'}};
    int precios[N][R] = {{1,2,3,2,1},
                         {2,3,2,2,1},
                         {1,2,2,5,3},
                         {2,5,3,3,1},
                         {2,2,3,2,1}};
    int n=5, m=11, r=5;
    for (int i=0; i<n; i++){
        imprimeSobrante(letras,i,0,m-1);
    }

    for (int i=0; i<n; i++){
        imprimePrecioMayor(precios,i,0,r-1);
    }
        
    return 0;
}

