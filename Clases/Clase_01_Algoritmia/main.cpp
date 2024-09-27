/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 18 de marzo de 2024, 10:02 AM
 */

#include <iostream>
#include <cmath>

using namespace std;

/*PROBLEMA DE LA MOCHILA*/
/*Paquetes de 1,2,4,12 y 1kg que deben entrar en una mochila de 
 capacidad 15kg*/

void cargabin(int num,int n,int cromo[]){
    int res;
    /*asegurandose de que siempre se inicialicen en cero*/

    int i=0;
    while(num>0){
        res=num%2;
        num=num/2; /* 1/2=0 -> num=0, se detiene la iteración*/
        cromo[i]=res;
        i++;
    }
}

/* void *cromo[]  Arreglo de direcciones */

int main(int argc, char** argv) {
    /*colocando valores en duro*/
    int paq[]={1,2,4,12,1};
    int n=5;
    int pparcial,/*mayor peso*/mpeso=0,peso=15,mcomb;
    /*cromosoma que guardará 1s y 0s*/
    int cromo[n]{};
    int opcion=(int)pow(2,n);
    /*recorriendo todas las opciones*/
    for(int i=0;i<opcion;i++){
        cargabin(i,n,cromo);
        pparcial=0; /*inicializando en 0 en cada iteración*/
        for(int j=0;j<n;j++)
            pparcial+=cromo[j]*paq[j];
        if(pparcial<=peso and mpeso<=pparcial){
            /*<: se queda con el primero mejor que encontró*/
            /*<=:se queda con el último mejor*/
            mpeso=pparcial;
            mcomb=i;
        }
        if(pparcial==peso){
            cout<<i<<endl;
        }
    }
    cout<<"Llega al peso maximo de "<<mpeso<<"kg en la mejor combinacion "<<mcomb;
    return 0;
}



