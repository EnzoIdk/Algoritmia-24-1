/* 
 * File:   funcionesGrafo.cpp
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:36 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "ListaArista.h"
#include "ListaVertice.h"
#include "Grafo.h"

using namespace std;
#include "funcionesListaArista.h"
#include "funcionesListaVertice.h"
#include "funcionesGrafo.h"

void construirGrafo(struct Grafo & grafo){
    construirListaVertice(grafo.listaVertice);
    grafo.longitud = 0;
}

bool esGrafoVacio(const struct Grafo & grafo){
    return esListaVerticeVacio(grafo.listaVertice);
}

bool seEncuentraVertice(const struct Grafo & grafo, int elemento){
    return seEncuentraVerticeLista(grafo.listaVertice, elemento);
}

/*Agregar añade un vértice, este puede ser de cualquier tipo de dato*/
/*es decir elemento está representando un tipo VERTICE*/
void agregarVertice(struct Grafo & grafo, char elemento){
    if(not seEncuentraVertice(grafo, elemento)){
        insertarVerticeAlFinal(grafo.listaVertice, elemento);
        grafo.longitud++;
    }
}

bool seEncuentraArista(const struct Grafo & grafo, char verticeOrigen, char verticeDestino){
    return seEncuentraAristaLista(grafo.listaVertice, verticeOrigen, verticeDestino);
}

void agregarArista(struct Grafo & grafo, char verticeOrigen, char verticeDestino){
    bool seEncuentraVerticeOrigen = seEncuentraVertice(grafo, verticeOrigen);
    bool seEncuentraVerticeDestino = seEncuentraVertice(grafo, verticeDestino);
    if((not seEncuentraVerticeOrigen) or (not seEncuentraVerticeDestino)){
        cout<<"No se ha encontrado algún vértice";
        return;
    }
    if(not seEncuentraArista(grafo, verticeOrigen, verticeDestino)){
        insertarListaAristas(grafo.listaVertice, verticeOrigen, verticeDestino);
    }
}

int longitudGrafo(const struct Grafo & grafo){
    return grafo.longitud;
}

void eliminarVertice(struct Grafo & grafo, char vertice){
    if (seEncuentraVertice(grafo, vertice)){	
        eliminarVerticeEnLista(grafo.listaVertice, vertice);
        grafo.longitud--;
    }
}

void eliminarArista(struct Grafo & grafo, char verticeOrigen, char verticeDestino){
    int seEncuentraVertOrigen = seEncuentraVertice(grafo, verticeOrigen);
    if (seEncuentraVertOrigen)
        eliminarDeListaDeAristas(grafo.listaVertice, verticeOrigen, verticeDestino);		
}

void mostrarVerticeYAristas(const struct Grafo & grafo){
    struct NodoListaVertice * recorridoG = new struct NodoListaVertice;
    struct NodoListaArista * recorridoA = new struct NodoListaArista;
    recorridoG = grafo.listaVertice.cabeza;
    
    if (recorridoG == nullptr){
        cout<<"No se puede mostrar, el grafo está vacío"<<endl;
        return;
    }
    else{
        while(recorridoG != nullptr){
            cout<<setw(5)<<recorridoG->elemento<<":";
            recorridoA = recorridoG->listaArista.cabeza;
            while(recorridoA != nullptr){
                cout<<setw(5)<<recorridoA->elemento;
                recorridoA = recorridoA->siguiente; 
            }
            recorridoG = recorridoG->siguiente; 
            cout<<endl;
        }
        delete recorridoG;
    }
}

void destruirGrafo(struct Grafo & grafo){
    destruirListaVertice(grafo.listaVertice);
    
    grafo.longitud = 0;
}