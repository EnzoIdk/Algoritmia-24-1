/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 26 de abril de 2024, 07:22 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Lista.h"
#include "funcionesLista.h"        

using namespace std;

/*reorganización de mayor a menor*/
void reorganizar(struct Lista &lista1,struct Lista &lista2){
    if(lista1.cola->nivel>=lista2.cabeza->nivel){
        lista1.cola->siguiente=lista2.cabeza;
        lista1.longitud+=lista2.longitud;
        lista1.cola=lista2.cola;
    }
    else{
        if(lista2.cola->nivel>lista1.cabeza->nivel){
            lista2.cola->siguiente=lista1.cabeza;
            lista1.longitud+=lista2.longitud;
            lista1.cabeza=lista2.cabeza;
        }
        else{ /*el caso que estén intercalados*/
            struct Lista listaFinal;
            listaFinal.cabeza=nullptr;
            listaFinal.cola=nullptr;
            while(!esListaVacia(lista1) and !esListaVacia(lista2)){
                if(lista1.cabeza->nivel>=lista2.cabeza->nivel){
                    if(listaFinal.cabeza==nullptr){
                        listaFinal.cabeza=lista1.cabeza;
                        listaFinal.cola=lista1.cabeza;
                    }
                    else{
                        listaFinal.cola->siguiente=lista1.cabeza;
                        listaFinal.cola=lista1.cabeza;
                    }
                    lista1.cabeza=lista1.cabeza->siguiente;
                }
                else{
                    if(listaFinal.cabeza==nullptr){
                        listaFinal.cabeza=lista2.cabeza;
                        listaFinal.cola=lista2.cabeza;
                    }
                    else{
                        listaFinal.cola->siguiente=lista2.cabeza;
                        listaFinal.cola=lista2.cabeza;
                    }
                    lista2.cabeza=lista2.cabeza->siguiente;
                }
            }
            if(!esListaVacia(lista1)){
                listaFinal.cola->siguiente=lista1.cabeza;
                listaFinal.cola=lista1.cola;
            }
            if(!esListaVacia(lista2)){
                listaFinal.cola->siguiente=lista2.cabeza;
                listaFinal.cola=lista2.cola;
            }
            lista1.cabeza=listaFinal.cabeza;
            lista1.cola=listaFinal.cola;
            lista1.longitud+=lista2.longitud;
        }
    }
}

int main(int argc, char** argv) {
    /*creamos las listas del problema*/
    struct Lista categoriaA,categoriaB,categoriaC,categoriaD,categoriaE;
    construir(categoriaA);
    construir(categoriaB);
    construir(categoriaC);
    construir(categoriaD);
    construir(categoriaE);
    insertarAlFinal(categoriaA,15,'A');
    insertarAlFinal(categoriaA,13,'A');
    insertarAlFinal(categoriaA,12,'A');
    insertarAlFinal(categoriaA,11,'A');
    insertarAlFinal(categoriaB,20,'B');    
    insertarAlFinal(categoriaB,19,'B');
    insertarAlFinal(categoriaC,18,'C');
    insertarAlFinal(categoriaC,17,'C');
    insertarAlFinal(categoriaC,16,'C');
    insertarAlFinal(categoriaD,17,'D');
    insertarAlFinal(categoriaD,15,'D');
    insertarAlFinal(categoriaD,14,'D');
    insertarAlFinal(categoriaD,13,'D');
    insertarAlFinal(categoriaD,12,'D');
    insertarAlFinal(categoriaE,14,'E');
    insertarAlFinal(categoriaE,12,'E');
    insertarAlFinal(categoriaE,10,'E');
    insertarAlFinal(categoriaE,8,'E');
    imprime(categoriaA);
    imprime(categoriaB);
    imprime(categoriaC);
    imprime(categoriaD);
    imprime(categoriaE);
    cout<<endl<<"Reorganizar"<<endl;
    reorganizar(categoriaA,categoriaB);
    reorganizar(categoriaA,categoriaC);
    reorganizar(categoriaA,categoriaD);
    reorganizar(categoriaA,categoriaE);
    imprime(categoriaA);
    cout<<longitud(categoriaA);
    return 0;
}

