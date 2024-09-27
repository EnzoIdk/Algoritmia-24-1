/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Lista.h"

using namespace std;
#include "funcionesLista.h"


/*
 * IMPLEMENTACIÓN DE UNA COLA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

void reorganizar (struct Lista & lista1, struct Lista & lista2){
    //TODO SE REORGANIZA EN LISTA1
    
    //Primer caso: todos los elementos de Lista1 son mayores que todos los elementos de la Lista2
    if (lista1.cola->nivel_impacto >= lista2.cabeza->nivel_impacto){//es mayor igual porque siempre de las 5 listas siempre haré L1 en L2, L3 en el resultado de ésta, y así sucesivamente.
        lista1.cola->siguiente=lista2.cabeza;
        lista1.longitud+=lista2.longitud;
        lista1.cola=lista2.cola;
    }
    else{
        //Segundo caso: todos los elementos de Lista2 son mayores que todos los elementos de la Lista1
        if (lista2.cola->nivel_impacto > lista1.cabeza->nivel_impacto){
            lista2.cola->siguiente=lista1.cabeza;
            lista1.longitud+=lista2.longitud;
            lista1.cabeza=lista2.cabeza;
        }
        else{
            //Tercer caso: los elementos de lista1 y lista2 se traslapan en nivel_impacto
            Lista lista_final;
            lista_final.cabeza=nullptr;
            lista_final.cola=nullptr;
            
            while (lista1.cabeza!=nullptr && lista2.cabeza!=nullptr){
                //lista1.cabeza es mayor a lista2.cabeza
                if(lista1.cabeza->nivel_impacto>=lista2.cabeza->nivel_impacto){//es mayor igual porque siempre de las 5 listas siempre haré L1 en L2, L3 en el resultado de ésta, y así sucesivamente.
                    if (lista_final.cabeza==nullptr){//cuando lista_final está vacía
                        lista_final.cabeza=lista1.cabeza;
                        lista_final.cola=lista1.cabeza;
                    }
                    else{
                        //si es que hay elemento en lista_final
                        lista_final.cola->siguiente=lista1.cabeza;
                        lista_final.cola=lista1.cabeza;
                    }
                    lista1.cabeza=lista1.cabeza->siguiente;
                }
                else
                    //lista2.cabeza es mayor a lista1.cabeza
                    if(lista2.cabeza->nivel_impacto>lista1.cabeza->nivel_impacto){
                        if (lista_final.cabeza==nullptr){//cuando lista_final está vacía
                            lista_final.cabeza=lista2.cabeza;
                            lista_final.cola=lista2.cabeza;
                        }
                        else{
                            //si es que hay elemento en lista_final
                            lista_final.cola->siguiente=lista2.cabeza;
                            lista_final.cola=lista2.cabeza;
                        }
                        lista2.cabeza=lista2.cabeza->siguiente;
                    }
            }
            //cuando una de las lista ya se terminó
            //Caso en el que me han sobrado elementos en Lista1
            while (lista1.cabeza!=nullptr){
                if(lista_final.cabeza==nullptr){//es el primer elemento en la lista_final
                    lista_final.cabeza=lista1.cabeza;
                    lista_final.cola=lista1.cola;
                }
                else{//si es que ya hay elementos en la lista_final
                    lista_final.cola->siguiente=lista1.cabeza;
                    lista_final.cola=lista1.cabeza;
                }
                lista1.cabeza=lista1.cabeza->siguiente;
            }
            //Caso en el que me han sobrado elementos en Lista2
            while (lista2.cabeza!=nullptr){
                if(lista_final.cabeza==nullptr){//es el primer elemento en la lista_final
                    lista_final.cabeza=lista2.cabeza;
                    lista_final.cola=lista2.cola;
                }
                else{//si es que ya hay elementos en la lista_final
                    lista_final.cola->siguiente=lista2.cabeza;
                    lista_final.cola=lista2.cabeza;
                }
                lista2.cabeza=lista2.cabeza->siguiente;
            }
            //"devolver" la lista_final
            lista1.cabeza=lista_final.cabeza;
            lista1.cola=lista_final.cola;
            lista1.longitud+=lista2.longitud;
        }
    }
}


int main(int argc, char** argv) {
    	int i;
    Lista CategoriaA, CategoriaB, CategoriaC, CategoriaD, CategoriaE;
    int numCategoriaA, numCategoriaB, numCategoriaC, numCategoriaD, numCategoriaE;
    
    construir(CategoriaA);
    construir(CategoriaB);
    construir(CategoriaC);
    construir(CategoriaD);
    construir(CategoriaE);
    
   insertarAlFinal(CategoriaA, 15, 'A');
   insertarAlFinal(CategoriaA, 13, 'A');
   insertarAlFinal(CategoriaA, 12, 'A');
   insertarAlFinal(CategoriaA, 11, 'A');
   
   insertarAlFinal(CategoriaB, 20, 'B');
   insertarAlFinal(CategoriaB, 19, 'B');
   
   insertarAlFinal(CategoriaC, 18, 'C');
   insertarAlFinal(CategoriaC, 17, 'C');
   insertarAlFinal(CategoriaC, 16, 'C');
   
   insertarAlFinal(CategoriaD, 17, 'D');
   insertarAlFinal(CategoriaD, 15, 'D');
   insertarAlFinal(CategoriaD, 14, 'D');
   insertarAlFinal(CategoriaD, 13, 'D');
   insertarAlFinal(CategoriaD, 12, 'D');
   
   insertarAlFinal(CategoriaE, 14, 'E');
   insertarAlFinal(CategoriaE, 12, 'E');
   insertarAlFinal(CategoriaE, 10, 'E');
   insertarAlFinal(CategoriaE, 8, 'E');
   
        
        
	
	imprime( CategoriaA );
	imprime( CategoriaB );
	imprime( CategoriaC );
	imprime( CategoriaD );
	imprime( CategoriaE );
	
	cout << "Reorganizar"<< endl;
	
	reorganizar (CategoriaA, CategoriaB);
	reorganizar (CategoriaA, CategoriaC);
	reorganizar (CategoriaA, CategoriaD);
	reorganizar (CategoriaA, CategoriaE);
	
	imprime( CategoriaA );
	
    

    return 0;
}

