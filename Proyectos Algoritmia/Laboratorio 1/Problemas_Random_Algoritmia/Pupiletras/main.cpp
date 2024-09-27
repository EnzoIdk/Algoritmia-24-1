/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de marzo de 2024, 05:28 PM
 */

#include <iostream>
//#include <climits>  Biblioteca que tiene func. max y min
using namespace std;

#define MAX_COL 5
#define MAX_FIL 4

/*MATRIZ DE MOVIMIENTO, fijaza*/
int mov[8][2]; /*se define como variable global*/

/*recordar que cuando nos movemos hacia abajo estamos incrementando en 1 la fila
 y hacia la derecha, en 1 la columna*/
void movimientos(){ /*como la aguja de un reloj que comienza a las 12, apunta hacia
                     * arriba y a partir de allí consideramos movimientos horarios*/
    /*MOVIMIENTO DE FILA, MOVIMIENTO DE COLUMNA*/
    mov[0][0]=-1 ;  mov[0][1]=0;   /*Hacia arriba*/
    mov[1][0]=-1 ;  mov[1][1]=1;   /*Hacia arriba y derecha (45°)*/
    mov[2][0]=0  ;  mov[2][1]=1;   /*Hacia derecha*/
    mov[3][0]=1  ;  mov[3][1]=1;   /*Hacia abajo y derecha (45°)*/
    mov[4][0]=1  ;  mov[4][1]=0;   /*Hacia abajo, ya se entiende creo*/
    mov[5][0]=1  ;  mov[5][1]=-1;   
    mov[6][0]=0  ;  mov[6][1]=-1;   
    mov[7][0]=-1 ;  mov[7][1]=-1;   
}

/*se puede hacer con bool pero se recomienda con int, 
    aunque es la misma wea, 0: false y 1: true*/
/*palabra tmbn se puede pasar como parámetro dinámico *palabra */
int buscarPalabra(char palabra[],char tablero[][MAX_COL],int row,int col,int m){
    int nuevoRow,nuevaCol;
    int j;
    if(tablero[row][col]!=palabra[0]) return 0; /*si no coincide con la 'G', lo descarta*/
    /*Aplicando la matriz de movimiento*/
    for(int i=0;i<8;i++){
        nuevoRow=row+mov[i][0];
        nuevaCol=col+mov[i][1];
        for(j=1;j<m;j++){
            /*si se pasa de los límites, se detiene la segunda iterativa*/
            if(nuevoRow<0 or nuevaCol<0 or nuevoRow>=MAX_FIL or nuevaCol>=MAX_COL) break;
            /*si la sgte letra no es la 'O', se descarta ese resultado*/
            if(tablero[nuevoRow][nuevaCol]!=palabra[j]) break;
            /*debe seguir el mismo movimiento siempre según las reglas de un pupiletras*/
            nuevoRow+=mov[i][0];
            nuevaCol+=mov[i][1];
        }
        if(j==m) return 1; /*si cumplió con que coinciden las tres letras, 
                            devuelve 1 (true), o sea que se encontró una solución*/
    }
    return 0; /*se coloca este return para los casos que encuentre una 'G'
               y en ninguna de las direcciones la siguiente letra es 'O'*/
}


void pupiletras(char palabra[],char tablero[][MAX_COL],int m){
    for(int i=0;i<MAX_FIL;i++){
        for(int j=0;j<MAX_COL;j++){
            if(buscarPalabra(palabra,tablero,i,j,m)){
                cout<<"Se encontro la palabra en ("<<i<<','<<j<<')'<<endl;
            }
        }
    }
}

int main(int argc, char** argv) {
    char tablero[][MAX_COL]={
        {'G','A','G','G','G'},
        {'A','G','O','O','O'},
        {'N','L','O','C','G'},
        {'R','A','T','L','N'}
    };
    int m=3; /*cantidad de letras de la palabra*/
    char palabra[]={'G','O','L'}; /*se va a buscar esta palabra en el pupiletras*/
    movimientos();
    pupiletras(palabra,tablero,m);
    return 0;
}

