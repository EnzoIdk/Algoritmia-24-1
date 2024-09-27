/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alvaro P.
 *
 * Created on 01 July 2024, 17:19
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int verificarEtiqueta(int matriz[][9], int valorActual, 
        int *etiquetas, int etiquetaMax){
    
    bool noConectanEntreSi;
    
    for (int i = 1; i <= etiquetaMax; i++) {  //pruebo etiquetas
        noConectanEntreSi = true;
        for (int k = 0; k < valorActual; k++) //recorre arreglo etiquetas (evaluo las redes)
            if(i == etiquetas[k]) //si la etiqueta que estoy probando tiene la misma etiqueta que la red evaluada entra
                if(matriz[valorActual][k] != 0) //evaluo en la fila del valor actual si se cruza con la red evaluada
                    noConectanEntreSi = false; //si es diferente de 0 si se conectan y la descarto xq 2 redes con la misma etiqueta no deben cruzarse
        if(noConectanEntreSi) return i; //en caso nunca entre a la condicion anterior (no se cruzan) le asigno la etiqueta que estaba probando
    }
}
void encuentraSolucion(int matriz[][9], int cantEtiquetasMax){
    int etiquetas[9]{}, etiqueta = 1; //valor que lleva la cuenta de las etiquetas asignadas
    
    for (int i = 0; i < 9; i++) {
        if(matriz[0][i] != 0){ //en caso conectan
            if(etiqueta > cantEtiquetasMax){
                cout<<"No existe solucion";
                return;
            }
            etiquetas[i] = etiqueta; //asigno etiqueta
            etiqueta++; //aumento su valor para que no se repita
        }
        else{ //si no se conectan debo evaluar cual etiqueta le asigno
            int valor = verificarEtiqueta(matriz, i, etiquetas, etiqueta);
            etiquetas[i] = valor;
        }
    }
    cout<<"Paquetes:  ";
    for (int i = 1; i <= 9; i++) {
        cout<<i<<"   ";
    }
    cout<<endl<<"Etiquetas: ";
    for (int i = 0; i < 9; i++) {
        cout<<etiquetas[i]<<"   ";
    }
}



int main(int argc, char** argv) {
    
    int matriz[9][9]{
        {1, 2, 0, 6, 0, 0, 0, 0, 2}, //== 0 -> no envia
        {7, 1, 5, 2, 0, 0, 0, 0, 7}, //!= 0 -> envia
        {0, 3, 1, 2, 3, 8, 9, 7, 5},
        {2, 7, 5, 1, 2, 0, 0, 0, 0},
        {0, 0, 5, 3, 1, 4, 0, 0, 0},
        {0, 0, 9, 0, 6, 1, 2, 0, 0},
        {0, 0, 3, 0, 0, 7, 1, 4, 0},
        {0, 0, 4, 0, 0, 0, 9, 1, 9},
        {5, 3, 6, 0, 0, 0, 0, 4, 1},
    };
    
    int cantEtiquetas = 4;
    
    encuentraSolucion(matriz, cantEtiquetas);
    
    return 0;
}

