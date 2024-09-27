/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 5 de mayo de 2024, 04:08 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

#define N 11

/*es como el busca solo, todos están en parejas menos uno que es el que tiene 3*/
char buscaTrio(char mesa[][N],int pos,int ini,int fin){
//    if(ini>fin) return "NADA";
    if(ini==fin) return mesa[pos][ini];
    int med=(ini+fin)/2;
    if(med%2==0){
        if(mesa[pos][med]==mesa[pos][med+1]) buscaTrio(mesa,pos,med+2,fin);
        else buscaTrio(mesa,pos,ini,med);
    }
    else{
        if(mesa[pos][med]==mesa[pos][med-1]) buscaTrio(mesa,pos,med+1,fin);
        else buscaTrio(mesa,pos,ini,med-1);
    }
}

void buscarFilasMalas(char mesa[][N],int &cant,int m,int n){
    char car;
    for(int i=0;i<m;i++){
        if(mesa[i][n-1]!=' '){
            car=buscaTrio(mesa,i,0,n-1);
            cout<<"La fila "<<i+1<<" tiene un "<<car<<" adicional"<<endl;
            cant++;
        }
    }
}

int main(int argc, char** argv) {
    int m=8,n=11,cant=0;  
    char mesa[][N]={{'O','O','C','C','A','A','E','E','R','R','R'},    
                    {'C','C','A','A','R','R','E','E','B','B',' '},
                    {'R','R','E','E','C','C','F','F','A','A',' '},
                    {'E','E','F','F','A','A','A','B','B','R','R'},
                    {'C','C','C','A','A','R','R','O','O','E','E'},
                    {'O','O','C','C','A','A','R','R','E','E',' '},
                    {'A','A','F','F','R','R','E','E','O','O',' '},
                    {'E','E','A','A','O','O','B','B','F','F',' '}};
    buscarFilasMalas(mesa,cant,m,n);
    cout<<cant<<endl;
    return 0;
}

