/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 2 de diciembre de 2023, 08:21 AM
 */

#include <iostream>

using namespace std;


#define N 9

int lista[N];


/*
 * 
 */


int valido(int paquetes[N][N],int i){
    int flag=1,cont=0;
    
    for(int j=0;j<=i;j++){
        if(paquetes[i][j]!=0 and lista[i]==lista[j])cont++;
        
    }
    if(cont>1) flag=0;
    
    
    return flag;
}



int AsignarEtiquetas(int paquetes[N][N],int etiquetas,int i){
    
    
    if(i==N){
        
        return 1;
        
    }
    
    
    for(int k=0;k<etiquetas;k++){
        lista[i]=k+1;
        if(valido(paquetes,i)){
            
            if(AsignarEtiquetas(paquetes,etiquetas,i+1)){
                return 1;
            }
            
            
        }
        lista[i]=0;
    }
    
    return 0;
    
}




int main(int argc, char** argv) {

    
    int paquetes[][N]={{1, 2, 0, 6, 0, 0, 0, 0, 2},
                        {7, 1, 5, 2, 0, 0, 0, 0, 7},
                        {0, 3, 1, 2, 3, 8, 9, 7, 5},
                        {2, 7, 5, 1, 2, 0, 0, 0, 0},
                        {0, 0, 5, 3, 1, 4, 0, 0, 0},
                        {0, 0, 9, 0, 6, 1, 2, 0, 0},
                        {0, 0, 3, 0, 0, 7, 1, 4, 0},
                        {0, 0, 4, 0, 0, 0, 9, 1, 9},
                        {5, 3, 6, 0, 0, 0, 0, 4, 1}}; 

    
    int etiquetas=4;
    
    int numEtiquetas=AsignarEtiquetas(paquetes,etiquetas,0);
    cout<<"Para "<<etiquetas<<" etiquetas se tiene:"<<endl;
    
    if(numEtiquetas!=0){
        for(int i=0;i<9;i++){
            cout<<i+1<<"  ";
        }
        cout<<endl;
        for(int i=0;i<9;i++){
            cout<<lista[i]<<"  ";
        }
        
    }
    else{
        cout<<"No hay solucion"<<endl;
    }
    
    
    
    
    return 0;
}

