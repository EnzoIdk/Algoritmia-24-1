/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
using namespace std;


/*
 * IMPLEMENTACIÓN DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
int main(int argc, char** argv) {

    struct Lista lista;
    /*Construimos la lista, la lista esta vacía*/
    construir(lista);
    cout<<esListaVacia(lista)<<endl;
       
    /*Inserta datos comenzando desde el inicio de la lista*/
    insertarAlInicio(lista, 5);
    insertarAlInicio(lista, 3);
    insertarAlInicio(lista, 1);
    imprime(lista);
    

    return 0;
}

