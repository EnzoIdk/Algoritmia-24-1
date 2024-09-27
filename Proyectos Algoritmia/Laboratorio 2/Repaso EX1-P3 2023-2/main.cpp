/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 20 de abril de 2024, 18:27
 */

#include <iostream>
using namespace std;

#include "Cola.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesPila.h"

/*
 * El robot tiene 2 brazos
 * SIEMPRE SE DEBE SEGUIR LA FORMA DE TORRES DE HANOI
 * lo que debemos hacer es llevar el mayor que encontremos al fondo de la pila 
 * destino
 */

void hanoiClasico(struct Pila &origen, struct Pila &aux, struct Pila &destino, 
        int elementos){
    if(elementos==0) return;
    //RECURSIVIDAD
    hanoiClasico(origen, destino, aux, elementos-1);
    apilar(destino, desapilar(origen));
    hanoiClasico(aux, origen, destino, elementos-1);
}

void hanoiOrdenado(int izq, int der, struct Pila &origen, struct Pila &aux, 
        struct Pila &destino, int elementos){
    for(int i=0; i<=elementos; i++){
        hanoiClasico(origen, aux, destino, i);
        if(i==elementos){
            apilar(origen, izq);
            hanoiClasico(destino, aux, origen, longitud(destino));
            break;
        }
        else{
            der=desapilar(origen);
            if(der>=izq){
                apilar(origen, der);
                apilar(origen, izq);
                hanoiClasico(destino, aux, origen, longitud(destino));
                break;
            }
            apilar(origen, der);
            hanoiClasico(destino, aux, origen, longitud(destino));   
        }
    }
}

void insertarPilaOrdenado(int izq, int der, struct Pila &pila, 
        struct Pila &aux1, struct Pila &aux2){
    //EN izq TENEMOS EL ELEMENTO SALIDO DE LA COLA Y EN der TENEMOS EL ELEMENTO
    //MAS PEQUEÑO DE LA PILA destino
    //HACEMOS UN HANOI HASTA QUE der>=izq LUEGO HACEMOS UN HANOI DE REGRESO
    //HANOI HASTA QUE izq<=der
    hanoiOrdenado(izq, der, pila, aux1, aux2, longitud(pila));
}

void robotHex(struct Cola &faja, struct Pila &pila, struct Pila &aux1, 
        struct Pila &aux2, int elementosEnCola){
    //CASO FIN
    if(elementosEnCola==0) return;
    //
    int izq=99999, der=9999999;
    
    izq=desencolar(faja); //SOLO VEMOS QUE ELEMENTO ES
    //PARA EL PRIMER CASO
    if(esPilaVacia(pila)) apilar(pila, izq);
    else{ //AHORA PARA LOS DEMAS CASOS
        insertarPilaOrdenado(izq, der, pila, aux1, aux2);
    }
    robotHex(faja, pila, aux1, aux2, elementosEnCola-1);
}


int main(int argc, char** argv) {
    
    struct Cola faja;
    struct Pila pila, aux1, aux2;
    
    construir(faja); //LA COLA
    construir(pila); //LA PILA
    construir(aux1); //LOS AUX
    construir(aux2);
    
    encolar(faja, 8);
    encolar(faja, 18);
    encolar(faja, 2);
    encolar(faja, 110);
    encolar(faja, 10);
    encolar(faja, 51);
    encolar(faja, 5);
    encolar(faja, 31);
    encolar(faja, 3);
    
    robotHex(faja, pila, aux1, aux2, longitud(faja));
    
    imprimir(pila);
    
    return 0;
}

