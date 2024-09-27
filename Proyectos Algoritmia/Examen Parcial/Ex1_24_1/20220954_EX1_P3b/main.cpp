/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo Andre Avila Mamani (20220954)
 *
 * Created on 18 de mayo de 2024, 09:25 AM
 */

#include <iostream>
#include <iomanip>

#include "Cola.h"
#include "funcionesCola.h"

using namespace std;

/*ordenando cola recursivamente*/
void ordenaCola(struct Cola &cola,int n){
    long long mayor,aux;
    int mayorH,auxH;
    int i=1;
    if(n==1) return;
    mayor=desencolar(cola);
    mayorH=(mayor/10000)%10000;
    while(i<n){
        aux=desencolar(cola);
        auxH=(aux/10000)%10000;
        if(auxH>mayorH){
            encolar(cola,mayor);
            mayorH=auxH;
            mayor=aux;
        }
        else encolar(cola,aux);
        i++;
    }
    ordenaCola(cola,n-1);
    encolar(cola,mayor);
}

void actualizarCola(struct Cola &cola,int n){
    long long actual;
    int dato1=2101,dato2=2105;
    for(int i=0;i<n;i++){
        actual=desencolar(cola);
        if(actual/100000000==dato1) actual-=40;
        else if(actual/100000000==dato2) actual+=88;
        encolar(cola,actual);
    }
}

void ordenaCola2(struct Cola &cola,int n){
    long long mayor,aux;
    int mayorH,auxH;
    int i=1;
    if(n==1) return;
    mayor=desencolar(cola);
    mayorH=mayor%10000;
    while(i<n){
        aux=desencolar(cola);
        auxH=aux%10000;
        if(auxH>mayorH){
            encolar(cola,mayor);
            mayorH=auxH;
            mayor=aux;
        }
        else encolar(cola,aux);
        i++;
    }
    ordenaCola2(cola,n-1);
    encolar(cola,mayor);
}

int main(int argc, char** argv) {
    struct Cola aviones;
    construir(aviones);
    /*agrupamos todos los datos en un solo longlong a encolar*/
    encolar(aviones,210100550055);
    encolar(aviones,110201450145);
    encolar(aviones,411100300030);
    encolar(aviones,210501220122);
    encolar(aviones,310805250525);
    cout<<"INFORME INICIAL:"<<endl;
    cout<<"Avion"<<setw(3)<<' '<<"Hora de llegada"<<setw(2)<<' '<<"Nueva hora de llegada"<<endl;
    imprime(aviones);
    ordenaCola(aviones,longitud(aviones));
    cout<<endl<<"HORA DE LLEGADA:"<<endl;
    cout<<"Avion"<<setw(3)<<' '<<"Hora de llegada"<<setw(2)<<' '<<"Nueva hora de llegada"<<endl;
    imprime(aviones);
    actualizarCola(aviones,longitud(aviones));
    cout<<endl<<"NUEVA HORA DE LLEGADA:"<<endl;
    cout<<"Avion"<<setw(3)<<' '<<"Hora de llegada"<<setw(2)<<' '<<"Nueva hora de llegada"<<endl;
    ordenaCola2(aviones,longitud(aviones));
    imprime(aviones);
    return 0;
}

