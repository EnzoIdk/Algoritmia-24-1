/* 
 * File:   main.cpp
 * Author: melow
 *
 * Created on 17 de mayo de 2024, 10:10 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Cola.h"
#include "Lista.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
#include "funciones.h"

int main(int argc, char** argv) {
    Lista bowser, peach, donkey, warriors;
    
    int n, cant_warriors; //Cantidad de batallas y cantidad de guerreros;
    construir(bowser);
    construir(peach);
    construir(donkey);
    construir(warriors);
    
//    n = 2;
//    insertarencola(warriors,723);
//    insertarencola(warriors,182);
//    insertarencola(warriors,123);
//    insertarencola(warriors,262);
//    insertarencola(warriors,851);
//    insertarencola(warriors,352);
//    insertarencola(warriors,653);
//    insertarencola(warriors,103);
//    insertarencola(warriors,561);
//    insertarencola(warriors,841);
//    insertarencola(warriors,391);
//    insertarencola(warriors,241);
//    
    insertardatos(warriors, n, cant_warriors);
    
    cout<<"Lista de guerreros: ";
    imprime(warriors);
    cout<<endl;
    
    asignarEjercito(warriors,bowser, peach, donkey);
    
    cout<<"Los ejercitos formados son: "<<endl;
    muestraEjercito(bowser);
    mostraNivelEjercito(bowser);
    cout<<endl;
    muestraEjercito(peach);
    mostraNivelEjercito(peach);
    cout<<endl;
    muestraEjercito(donkey);
    mostraNivelEjercito(donkey);
    cout<<endl;
    
    batalla(bowser,peach, donkey, n);

    return 0;
}

