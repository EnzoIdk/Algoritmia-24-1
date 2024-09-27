/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"

using namespace std;
#include "funcionesCola.h"

#define MAX_MENSAJE 30
#define MAX_CLAVE 4
/*
 * IMPLEMENTACIÓN DE UNA COLA
 * USANDO PUNTEROS CABEZA Y COLA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
int main(int argc, char** argv) {

//    struct Cola cola;
//    construir(cola);
//
//    /*Encolamos elementos en la Cola*/
//    encolar(cola, 4);
//    encolar(cola, 3);
//    encolar(cola, 12);
//    encolar(cola, 2);
//    imprimir(cola);
//    /*Desencolamos elementos de la cola*/
//    while(not esColaVacia(cola)){
//        cout<<"Desencolando: "<<desencolar(cola)<<endl;
//    }
//    imprimir(cola);
//    cout<<endl;
//    
    /*EJERCICIOS CON COLAS*/
    
    /*CIFRADO*/
    struct Cola clave, copiaClave;
    construir(clave);
    construir(copiaClave);
    
    /*Codifica y decodifica un mensaje utilizando una clave formada por diversos
    valores almacenados en una cola*/
    int llave[4] = {3, 1, 7, 4};
    char mensaje[MAX_MENSAJE] = {'h', 'o', 'l', 'a', ' ', 'm', 'u', 'n', 'd', 'o'};
    int longitud = 10;
    char codificado[MAX_MENSAJE]{};
    char decodificado[MAX_MENSAJE]{};
    int valorLlave;

    /*cargar cola de claves*/
    for (int i = 0; i < MAX_CLAVE; i++) {
        encolar(clave, llave[i]);
        encolar(copiaClave, llave[i]); //salva la clave en una copia
    }
    imprimir(clave);
    /*codificar el mensaje*/
    for (int i = 0; i < longitud; i++) {
        valorLlave = desencolar(clave); //desencola el valor clave
        codificado[i] = mensaje[i] + valorLlave; //codifica el mensaje
        encolar(clave, valorLlave); //encola el valor clave
    }
    cout << "COLAS PARA CIFRADO" << endl;
    cout << "Codificado: " << codificado << endl;

    /*decodificar el mensaje*/
    for (int i = 0; i < longitud; i++) {
        valorLlave = desencolar(copiaClave);
        decodificado[i] = codificado[i] - valorLlave;
        encolar(copiaClave, valorLlave);
    }
    cout << "Decodificado: " << decodificado << endl;
    
    
 
    return 0;
}

