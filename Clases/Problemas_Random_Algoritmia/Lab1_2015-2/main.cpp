/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 25 de marzo de 2024, 04:48 PM
 */

#include <iostream>      

using namespace std;

/*Realizar una función triangulo(int a,int b) [a<b] por recursión 
    que te muestre la disposición sgte: 
 
    * * *
    * * * *
    * * * * *
    * * * * *
    * * * * 
    * * *  
 
 */

void triangulo(int a,int b){
    if(a>b) return; /*condición de parada, NO OLVIDAR para no caer en bucle :'v*/
    for(int i=0;i<a;i++) cout<<" * ";
    cout<<endl;
    triangulo(a+1,b); /*recursión*/
    for(int i=0;i<a;i++) cout<<" * ";
    cout<<endl;
}

/*Forma de pensarlo:
 | a=3,b=5
 | * * *
 | | a=4,b=5 
 | | * * * *
 | | | a=5,b=5
 | | | * * * * *
 | | | [triangulo(6,5) no devuelve nada]
 | | | * * * * * [continúa con la sgte iterativa y sale del triangulo (5,5)]
 | | * * * *
 | * * *
 */

int main(int argc, char** argv) {

    int a=3,b=5;
    triangulo(a,b);
    
    return 0;
}

