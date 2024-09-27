/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 25 de marzo de 2024, 09:08 AM
 */

#include <iostream>
using namespace std;
#include <climits> //MAXIMOS Y MINIMOS

#define MAX_COL 5
#define MAX_FIL 4

//VARIABLES GLOBALES
int mov[8][2]; //MATRIZ DE MOVIMIENTOS
void movimientos(){ //EN SENTIDO HORARIO
    //MOVIMIENTO DE FILA; MOVIMIENTO DE COLUMNA
    mov[0][0]=-1; mov[0][1]=0;
    mov[1][0]=-1; mov[1][1]=1;
    mov[2][0]=0; mov[2][1]=1;
    mov[3][0]=1; mov[3][1]=1;
    mov[4][0]=1; mov[4][1]=0;
    mov[5][0]=1; mov[5][1]=-1;
    mov[6][0]=0; mov[6][1]=-1;
    mov[7][0]=-1; mov[7][1]=-1;
}

/*
 * ALGOED: Clase 25/03
 * Temas Lab1: Recursoin y fuerza bruta
 * - Recursion: 
 * Cuando se puede definir en función de si mismo. Se tiene una función que 
 * internamente se contiene.
 * Ejemplo: El factorial: n! = n * (n-1)!; 0! = 1;
 * 
 * Toda recursion debe tener un caso base (condición de parada), nos debe 
 * asegurar que el programa no sea infinito.
 * 
 * Las variables que se definen en el amibto n, ese valor no necesariamente lo
 * tiene otro ambito (La variable 'a' dentro de la recursion no necesariamente
 * tiene el mismo valor, puede ser 5, luego 4, 3, 2 , 1 dependiendo de la 
 * instancia).
 * Ejemplo: Fibonacci, tiene 2 casos bases.
 * 
 */

//funciones.cpp
void triangulo(int a, int b){
    /*
     * ---1
     * a=3 b=5
     * ***
     *  ---2
     *  a=4 b=5
     *  ****
     *   ---3
     *   a=5 b=5
     *   *****
     *    ---4
     *    a=6 b=5
     *    return;
     *   ---3
     *   a=5 b=5
     *   *****
     *  ---2
     *  a=4 b=5
     *  ****
     * ---1
     * a=3 b=5
     * ***
     * ---Fin
     */
    
    //CONDICION DE PARADA (Es recomendable comenzar colocando la condición de parada)
    if(a>b) return;
    //IMPRESION
    for(int i=0; i<a; i++) cout<<'*';
    cout<<endl;
    //RECURSION
    triangulo(a+1, b);
    //SE DEBE IMPLEMENTAR OTRA ITERATIVA. 
    for(int i=0; i<a; i++) cout<<'*';
    cout<<endl;
}

int robot(int x, int y, int n, int m, int tablero[][3]){
    /*
     * El robot envia a otro robot para que le devuelva el valor del camino a 
     * seguir, pero ese robot vuelve a enviar a otro robot para que decida que 
     * camino seguir, asi sucesivamente hasta llegar a la ultima fila y columna, 
     * donde el robot regresa su valor, y el anterior regresa ese valor 
     * más su valor, siguiendo el mejor camino.
     */
    
    int derecha=-999999, abajo=-999999;
    
    //CONDICION DE PARADA
    if(x==n-1 and y==m-1) return tablero[x][y];
    
    //CONDICION PARA CUANDO YA NO IR A DERECHA O IZQUIERA
    //RECURSIONES (Por derecha y por abajo)
    if(x+1<m) derecha=robot(x+1, y, n, m, tablero);
    if(y+1<n) abajo=robot(x, y+1, n, m, tablero);
    
    //CONDICION PARA QUE VALOR REGRESAR AL ROBOT ANTERIOR
    if(derecha>abajo) return derecha+tablero[x][y];
    else return abajo+tablero[x][y]; //(abajo>derecha) or (abajo==derecha)
    
}

//Usar int mejor
bool buscar(char tabla[][MAX_COL], char *palabra, int row, int col, int k){
    int nrow, ncol;
    int j;
    if(tabla[row][col]!=palabra[0]) return false;
    
    for(int i=0; i<8; i++){
        nrow=row+mov[0][i];
        ncol=col+mov[1][i];
        
        for(j=1; j<k; j++){
            if(ncol<0 or nrow<0 or ncol>=MAX_COL or nrow>=MAX_FIL) break;
            if(tabla[nrow][ncol]!=palabra[j]) break;
            //SE DEBE MANTENER EN EL MISMO MOVIMIENTO DURANTE ESTE PASO
            nrow+=mov[0][i];
            ncol+=mov[1][i];
        }
        
        if(j==k) return true; //QUIERE DECIR QUE LLEGO HASTA EL FINAL, 
                              //O SEA, LO ENCONTRO.
    }
    return false;
}

void pupiletras(char *palabra, char tabla[][MAX_COL], int k){
    
    for(int i=0; i<MAX_FIL; i++){
        for(int j=0; j<MAX_COL; j++){
            if(buscar(tabla, palabra, i, j, k)){
                cout<<"Encontre la palabra en "<<i<<' '<<j<<endl;
            }
        }
    }
}

//main.cpp
int main(int argc, char** argv) {
    //TRIANGULO
    triangulo(3, 5);
    cout<<endl;
    
    //ROBOT
    int n=3, m=3; //Filas, columnas
    int tablero[][3]={{3,  8, 6}, //Siempre se define el numero de columnas
                      {3, 10, 2},
                      {0,  9, 1}};    
    cout<<"El resultado es: "<<robot(0, 0, n, m, tablero)<<endl;
    
    //PUPILETRAS
    char tabla[][MAX_COL]={
        {'G', 'A', 'T', 'O', 'G'},
        {'O', 'G', 'O', 'A', 'O'},
        {'N', 'B', 'O', 'C', 'L'},
        {'R', 'A', 'T', 'L', 'N'}
    };
    int k=3;
    char palabra[]={'G', 'O', 'L'};
    movimientos();
    pupiletras(palabra, tabla, k);
    
    
    return 0;
}

