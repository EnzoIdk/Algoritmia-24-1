/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 7 de mayo de 2023, 08:17 PM
 */
#include <iostream>
#include "pila.h"

using namespace std;

int fremax=0;
int duracion=0;

int CalculaAreaMax(int notas[], int n)
{       int tempfrec,tempdura;
	Pila s;
        construir(s);
	int areamax = 0,tp,areatop,i = 0;
	while (i < n ) {

            if (esPilaVacia(s) || notas[top(s)] <= notas[i]){
                apilar(s,i);
                i++;
            }
            else{
		tp = desapilar(s);
                if(esPilaVacia(s)){
                    areatop = notas[tp]*i;
                    tempfrec=notas[tp];
                    tempdura=i;
                }
                else{
                    areatop = notas[tp]*(i-top(s)- 1);
                    tempfrec=notas[tp];
                    tempdura=i-top(s)- 1;
		}
                if (areamax < areatop){
                    areamax = areatop;
                    fremax = tempfrec;
                    duracion = tempdura;
                }
            }
	}

	while (!esPilaVacia(s)) {
		tp = desapilar(s);
                if(esPilaVacia(s)){
                    tempfrec=notas[tp];
                    areatop = notas[tp]*i;
                    tempdura=i;
                }
                else{
                    areatop = notas[tp]*(i-top(s)- 1);
                    tempfrec=notas[tp];
                    tempdura=i-top(s)- 1;
                }
                if (areamax < areatop){
                    fremax = tempfrec;
                    areamax = areatop;
                    duracion = tempdura;
                }
	}

  	return areamax;
}


int main()
{
    int notas[] = { 1, 2, 1, 4, 5, 6, 4,5,2,2,1 };
    int n = sizeof(notas) / sizeof(notas[0]);

    
    printf("La maxima area es: %d\n",CalculaAreaMax(notas, n));
    printf("Frecuencia y duracion es:%d %d",fremax,duracion);

    return 0;
}

