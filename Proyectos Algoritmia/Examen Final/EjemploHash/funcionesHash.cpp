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

/* 
 * File:   Cliente.h
 * Author: ANA RONCAL
 * Created on 4 de octubre de 2023, 10:15 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

struct Cliente{
    int clave;
    char nombre[50];
    char sexo;
    int celular;

};

#endif /* CLIENTE_H */

* 
 * File:   funciones.h
 * Author: ANA RONCAL
 * Created on 4 de octubre de 2023, 09:42 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leerDatos(const char * nombreArch, struct Cliente * cliente);
int funcionHash(int clave);

void modificarDatos(const char * nombreArch, struct Cliente * cliente);
void mostrarCliente(struct Cliente cliente);
void mostrarTodos(struct Cliente * cliente);
void mostrarCabecera();

#endif /* FUNCIONES_H */

/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * Created on 4 de octubre de 2023, 09:43 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Cliente.h"
using namespace std;
#include "funciones.h"
#define MAXDATOS 100

void leerDatos(const char * nombreArch, struct Cliente * cliente){
    
    ifstream arch(nombreArch, ios::in);
    if(not arch.is_open()){
        cout<<"Error al abrir el archivo de Clientes"<<endl;
    }
    struct Cliente clienteAux;
  
    int clave;
    char sexo;
    char nombre[50];
    int indice;
    while(not arch.eof()){
        arch>>clave;
        if(arch.eof()) break;
        arch>>nombre;
        arch>>sexo;
        clienteAux.clave = clave;
        strcpy(clienteAux.nombre, nombre);
        clienteAux.sexo = sexo;
        indice = funcionHash(clave);
        cliente[indice] = clienteAux;
       
    }
    
}

int funcionHash(int clave){
   
    int dig, indice, suma = 0;
   
    while(clave){
        dig = clave % 10;
        suma = suma + (dig + '0');
        clave = clave / 10;
    } 
    
    indice = suma % MAXDATOS;
    return indice;
}

void modificarDatos(const char * nombreArch, struct Cliente * cliente){
    
    ifstream arch(nombreArch, ios::in);
    if(not arch.is_open()){
        cout<<"Error al abrir el archivo de Clientes"<<endl;
    }
 
    mostrarCabecera();
    struct Cliente clienteAux;
    int clave;
    int indice;
    int celular;
    while(not arch.eof()){
        arch>>clave;
        if(arch.eof()) break;
        arch>>celular;
        indice = funcionHash(clave);
        cliente[indice].celular = celular; 
        //mostrarCliente(cliente[indice]);
    }
}

void mostrarCliente(struct Cliente cliente){
    
    cout<<setw(10)<<cliente.clave
        <<setw(20)<<cliente.nombre
        <<setw(10)<<cliente.sexo
        <<setw(10)<<cliente.celular<<endl;
    
}

void mostrarTodos(struct Cliente * cliente){
    for(int i = 0; i< MAXDATOS; i++){
        if(cliente[i].clave != 0){
            mostrarCliente(cliente[i]);
        }   
    }
}

void mostrarCabecera(){
    cout<<left<<setw(10)<<"CLAVE"
        <<setw(18)<<"CLIENTE"
        <<setw(10)<<"SEXO"
        <<setw(10)<<"CELULAR"<<endl;
}