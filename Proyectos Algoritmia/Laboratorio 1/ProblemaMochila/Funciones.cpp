/* 
 * File:   Funciones.cpp
 * Author: ANA RONCAL
 * Created on 19 de marzo de 2024, 04:58 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <math.h>

#define CANT_PAQUETES 6
#define CAPACIDAD_MOCHILA 25
using namespace std;
#include "Funciones.h"
#include "Paquete.h"

void cargaBinario(int num, int * combinaciones){
    int i = 0;
    while(num > 0){
        combinaciones[i++] = num % 2;
        num = num / 2;
    }
}

void solucionMochilaPesoExacto(struct Paquete * paquetes){
    
    int combinaciones[CANT_PAQUETES] {};
    int opcion = (int)pow(2, CANT_PAQUETES);
    cout<<"La solucion PesoExacto es :"<<endl;
     
    for(int i = 0; i < opcion; i++){
        int pesoParcial = 0;
        cargaBinario(i, combinaciones);
        for(int j = 0; j < CANT_PAQUETES; j++){
            pesoParcial += combinaciones[j] * paquetes[j].peso;
        }	
        /*Todas las soluciones que cumplen con la capacidad exacta de la mochila*/
        if(pesoParcial == CAPACIDAD_MOCHILA){
            cout<<"Opción :"<< i <<endl;
            for(int j = 0; j < CANT_PAQUETES; j++){
                if(combinaciones[j]==1)
                    cout << paquetes[j].id<<" "<< paquetes[j].peso<<"; ";
            }	
            cout << endl;
        }		
    }
}

void solucionMochilaMaxPeso(struct Paquete * paquetes){
    
    int combinaciones[CANT_PAQUETES] {};
    int opcion = (int)pow(2, CANT_PAQUETES);
    int maxPeso = 0, maxCombinacion = 0;
    
    for(int i = 0; i < opcion; i++){
        int pesoParcial = 0;
        cargaBinario(i, combinaciones);
        for(int j = 0; j < CANT_PAQUETES; j++){
            pesoParcial += combinaciones[j] * paquetes[j].peso;
        }
        /*El max Peso de todos*/
        if(maxPeso <= pesoParcial and pesoParcial <= CAPACIDAD_MOCHILA){
            maxPeso = pesoParcial;
            maxCombinacion = i;
	}		        
    }
    
    cout<<endl<<"La solucion MaxPeso es:"<< maxCombinacion <<endl;
    cargaBinario(maxCombinacion, combinaciones);
    for(int j = 0; j < CANT_PAQUETES; j++){
        if(combinaciones[j]==1)
            cout << paquetes[j].id<<" "<< paquetes[j].peso<<", ";
    }	
	
     cout << endl;
}

void solucionMochilaMaxGanancia(struct Paquete * paquetes){
    
    int combinaciones[CANT_PAQUETES] {};
    int auxCombinaciones[CANT_PAQUETES] {};
    int maxCombinacion;
    int maxGanancia = 0, ganancia;
    int pesoParcial;
    int opcion = (int)pow(2, CANT_PAQUETES);
    
    for(int i = 0; i < opcion; i++){
        pesoParcial = 0;
        ganancia = 0;
        cargaBinario(i, combinaciones);
        for(int j = 0; j < CANT_PAQUETES; j++){
            pesoParcial += combinaciones[j] * paquetes[j].peso;
            ganancia += combinaciones[j] * paquetes[j].ganancia;
        }
        /*La ganancia debe ser máxima y el peso no debe sobrepasar la capacidad
         de la mochila*/
        if(ganancia > maxGanancia and pesoParcial <= CAPACIDAD_MOCHILA){
            maxGanancia = ganancia;
            maxCombinacion = i;
            //cout<<pesoParcial<<" "<<maxGanancia<<" "<<maxCombinacion<<endl;
	}		        
    }
    
    cout<<endl<<"La solucion MaxGanancia es:"<< maxCombinacion <<endl;
    cargaBinario(maxCombinacion, auxCombinaciones);
    for(int j = 0; j < CANT_PAQUETES; j++){
        if(auxCombinaciones[j] == 1){
            cout<<paquetes[j].id<<" "<<paquetes[j].peso<<" "
                <<paquetes[j].ganancia<<endl;
        }
    }	
    cout<<"Mayor ganancia: "<<maxGanancia;
	
}