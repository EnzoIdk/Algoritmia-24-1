/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"


/*Examen 2020-2 P2*/

void calculafrecuencia(int *precios, int n){
    Pila pila;
    int precio,intervalo;
    int solu[100];
    construir(pila);
    for(int i=0;i<n;i++){
       solu[i]=1;
       	if(i==0)
            apilar(pila,precios[i]*100+1);
        else{
            int temp=cima(pila);
            precio=temp/100;
            if(precios[i]<precio)
                apilar(pila,precios[i]*100+1);
            else{
                while(!esPilaVacia(pila)){
                    temp = cima(pila);
                    precio = temp/100;
                    intervalo = temp%100;
                    if(precios[i]<precio)
                        break;
                    else{
                        temp = desapilar(pila);
                        precio = temp/100;
                        intervalo = temp%100;
                    }	
                    solu[i]=solu[i]+intervalo;
                } 
                apilar(pila,precios[i]*100+solu[i]);
            }
        }       
    }
    
    for(int i=0;i<n;i++)
        cout <<solu[i]-1 <<" ";    
  
}



int main(int argc, char** argv) {
    int n=8;
   // int precios[]={12,13,14,15,16,17,18};//arreglo de entrada
    int precios[]={10,20,15,10,12,10,13,18};

    calculafrecuencia(precios,n);


    return 0;
}

