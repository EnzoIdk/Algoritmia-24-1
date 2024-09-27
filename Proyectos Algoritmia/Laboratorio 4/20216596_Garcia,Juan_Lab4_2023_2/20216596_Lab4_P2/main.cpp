/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 4 de noviembre de 2023, 08:18 AM
 */

#include <iostream>

using namespace std;
#define MAX_MOV 4
int mov[MAX_MOV][2];
int n=5;

#define M 9
void GenerarMov(){
    mov[0][0]=-1; mov[0][1]=0;
    mov[1][0]=0; mov[1][1]=1;
    mov[2][0]=1; mov[2][1]=0;
    mov[3][0]=0; mov[3][1]=-1;
}

/*
 * 
 */


int ChequearAlmacen(int almacen[][M],int P,int paso,int x,int y,int recorrido[][M]
        ,int almacen2[][M],int carga){
    if(x>=n and y>=M) return 0;
    
    if(carga==P) return carga;
    int x_nuevo,y_nuevo;
    
    for(int i=0;i<MAX_MOV;i++){
        x_nuevo=x+mov[i][0];
        y_nuevo=y+mov[i][1];
        if(x_nuevo>0 and y_nuevo>0){
           
            if(recorrido[x_nuevo][y_nuevo]==0){
                recorrido[x_nuevo][y_nuevo]=paso;
                if(almacen[x_nuevo][y_nuevo]!=0){
                    almacen2[x_nuevo][y_nuevo]=almacen[x_nuevo][y_nuevo];
                    int p;
                    p=carga+almacen[x_nuevo][y_nuevo];
                    if(ChequearAlmacen(almacen,P,paso+1,x_nuevo,y_nuevo,recorrido,almacen2,p)){
                        return 1;
                    }
                    
                }

                recorrido[x_nuevo][y_nuevo]=0;

            }
            
        }
        
    }
    
    
}


void Imprimir(int almacen2[][M]){
    for(int i=0;i<M;i++){
        for(int j=0;j<n;j++){
            cout<<almacen2[i][j]<<"  ";
        }
        cout<<endl;
    }
    
}

int main(int argc, char** argv) {

    int x=0,y=0;
    int P=29;
    int paso=2;
    int almacen[][M]={{0,5,0,5,4},
                       {0,10,0,7,2},
                       {0,7,0,15,10},
                       {0,0,0,0,0},
                       {8,0,6,8,0},
                       {12,0,10,15,0},
                       {0,0,20,5,0},
                       {0,0,0,0,0},
                       {8,8,0,0,0}};
    int recorrido[][M]={{0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0}};
    int almacen2[][M]={{0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0}};
    recorrido[x][y]=1;
    GenerarMov();
    int carga=0;
    int a=ChequearAlmacen(almacen,P,paso,x,y,recorrido,almacen2,carga);
    
    Imprimir(recorrido);
    cout<<endl;
    
    cout<<a<<endl;
    Imprimir(almacen2);
    
    return 0;
}

