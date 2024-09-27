/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 4 de octubre de 2023, 09:42 AM
 */

#include <iostream>
#include <cstdlib>
#include "Cliente.h"
using namespace std;
#include "funciones.h"

#define MAXDATOS 100

/*
 * EJEMPLO DE USO DE TABLA HASH
 */
int main(int argc, char** argv) {
    
    struct Cliente cliente[MAXDATOS]{};
    int indice, clave;
    leerDatos("Clientes.txt", cliente);
   
    modificarDatos("Modificaciones.txt", cliente);
    
    clave = 19970234;
    indice = funcionHash(clave);
    cliente[indice].celular = 999888777;
    mostrarCliente(cliente[indice]);
    
    mostrarTodos(cliente);
  
    return 0;
}

