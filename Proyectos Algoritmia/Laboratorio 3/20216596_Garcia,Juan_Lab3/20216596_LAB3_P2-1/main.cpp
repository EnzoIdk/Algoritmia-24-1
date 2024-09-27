/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 30 de septiembre de 2023, 09:26 AM
 */

#include <iostream>

using namespace std;
#define N 11



int max(int a,int b){
    if(a>=b)return a;
    else 
        return b;
}

int Compara(int *filas,int ini,int medio,int fin){
    
    int cont=1;
    
    for(int i=medio;i>ini;i--){
        if(filas[i]==filas[i-1])cont++;
        else break;
    }
    
    for(int j=medio;j<fin;j++){
        if(filas[j]==filas[j+1])cont++;
        else break;
    }
    
    return cont;
}

int ChequearMesa(int *filas,int ini,int fin,char &car){
    int izq,der,medio,centro;
    medio=(ini+fin)/2;
    
    
    if(ini==fin)return 1;
    
    
    
    izq=ChequearMesa(filas,ini,medio,car);
    der=ChequearMesa(filas,medio+1,fin,car);
    centro=Compara(filas,ini,medio,fin);
    if(centro==3){
        car=filas[medio];
    }
    
    return max(max(izq,der),centro);
}




void BuscarMalasfilas(int mesa[][N],int *filas,int &cantFilasMalas,int m,int n,char *car){
    
    int detector=0;
    for(int i=0;i<m;i++){
        char c;
        if(mesa[i][n-1]!=' '){
            
            detector=ChequearMesa(mesa[i],0,n-1,c);
            if(detector==3){
                filas[cantFilasMalas]=i;
                car[cantFilasMalas]=c;
                cantFilasMalas++;
                
            }
        }
        
    }
    
}


/*
 * 
 */
int main(int argc, char** argv) {

    int m=8,n=11;
    
    int mesa[][N]={{'O','O','C','C','A','A','E','E','R','R','R'},    
                    {'C','C','A','A','R','R','E','E','B','B',' '},
                    {'R','R','E','E','C','C','F','F','A','A',' '},
                    {'E','E','F','F','A','A','A','B','B','R','R'},
                    {'C','C','C','A','A','R','R','O','O','E','E'},
                    {'O','O','C','C','A','A','R','R','E','E',' '},
                    {'A','A','F','F','R','R','E','E','O','O',' '},
                    {'E','E','A','A','O','O','B','B','F','F',' '}};
    
    int filas[8];
    int cantFilasMalas=0;
    char car[8];
    BuscarMalasfilas(mesa,filas,cantFilasMalas,8,11,car);
    //cout<<cantFilasMalas;
    
    for(int i=0;i<cantFilasMalas;i++){
        cout<<"La fila "<<filas[i]+1<<" tiene un "<<car[i]<<" adicional"<<endl;
    }
    return 0;
}

