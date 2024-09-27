/* 
 * File:   Grafo.cpp
 * Author: Ana Roncal
 * 
 * Created on 20 de junio de 2024, 12:54
 */


#include <iostream>
#include <iomanip>
#include "Grafo.h"
#include "Pila.h"
using namespace std;
#include "funcionesVertice.h"
#include "funcionesGrafo.h"
#include "funcionesPila.h"
#include "Ciudad.h"

void construirGrafo(struct Grafo & grafo) {
    construirListaVertice(grafo.listaVertice);
    grafo.longitud = 0;
}

bool esGrafoVacio(struct Grafo grafo) {
    return esListaVerticeVacio(grafo.listaVertice);
}

bool seEncuentraVertice(const struct Grafo & grafo, char elemento) {
    return seEncuentraVerticeLista(grafo.listaVertice, elemento);
}

void agregarVertice(struct Grafo & grafo, char elemento) {
    if (not seEncuentraVertice(grafo, elemento)) {
        insertarVerticeAlFinal(grafo.listaVertice, elemento);
        grafo.longitud++;
    }
}

void eliminarVertice(struct Grafo & grafo, char vertice) {
    if (seEncuentraVertice(grafo, vertice)) {
        eliminarVerticeEnLista(grafo.listaVertice, vertice);
        grafo.longitud--;
    }
}

void eliminarArista(struct Grafo & grafo, char verticeOrigen, char verticeDestino) {
    bool seEncuentraVerticeO = seEncuentraVertice(grafo, verticeOrigen);
    if (seEncuentraVerticeO)
        eliminarDeListaDeAristas(grafo.listaVertice, verticeOrigen, verticeDestino);
}

void mostrarVerticeYAristas(const struct Grafo & grafo) {
    struct NodoVertice * recorridoG = new struct NodoVertice;
    struct NodoArista * recorridoA = new struct NodoArista;
    recorridoG = grafo.listaVertice.cabeza;

    if (recorridoG == nullptr) {
        cout << "No se puede mostrar, el grafo está vacío" << endl;
        return;
    } else {
        while (recorridoG != nullptr) {
            cout << left << setw(2) << recorridoG->elemento << "->";
            recorridoA = recorridoG->listaArista.cabeza;
            while (recorridoA != nullptr) {
                cout << ' ' << recorridoA->elemento << ' ' << recorridoA->ponderado << ", ";
                recorridoA = recorridoA->siguiente;
            }
            recorridoG = recorridoG->siguiente;
            cout << endl;
        }
        delete recorridoG;
    }

    cout << endl;
}

bool seEncuentraArista(struct Grafo grafo, char verticeOrigen, char verticeDestino) {
    return seEncuentraAristaLista(grafo.listaVertice, verticeOrigen, verticeDestino);
}

void agregarArista(struct Grafo & grafo, char verticeOrigen, char verticeDestino, double ponderado) {
    bool seEncuentraVerticeOrigen = seEncuentraVertice(grafo, verticeOrigen);
    bool seEncuentraVerticeDestino = seEncuentraVertice(grafo, verticeDestino);
    if ((not seEncuentraVerticeOrigen) or (not seEncuentraVerticeDestino)) {
        cout << "No se ha encontrado algún vértice";
        return;
    }

    if (not seEncuentraArista(grafo, verticeOrigen, verticeDestino)) {
        insertarListaAristas(grafo.listaVertice, verticeOrigen, verticeDestino, ponderado);
    }
}

void destruirGrafo(struct Grafo & grafo) {
    destruirListaVertice(grafo.listaVertice);
    grafo.longitud = 0;
}

void dameVecinosDeUnVertice(const struct Grafo & grafo, char vertice, struct Pila & pila) {

    struct NodoVertice * recorridoV = new struct NodoVertice;
    struct NodoArista * recorridoA = new struct NodoArista;

    //comenzamos el recorrido en la cabeza del grafo
    recorridoV = grafo.listaVertice.cabeza;
    struct Ciudad ciudad;
    if (esGrafoVacio(grafo)) {
        cout << "El grafo está vacío";
    } else {
        while (recorridoV != nullptr) {
            if (recorridoV->elemento == vertice) {
                //Debo colocar el puntero en la cabeza de la arista
                recorridoA = recorridoV->listaArista.cabeza;
                while (recorridoA != nullptr) {
                    ciudad.elemento = recorridoA->elemento;
                    ciudad.ponderado = recorridoA->ponderado;
                    apilar(pila, ciudad);
                    recorridoA = recorridoA->siguiente;
                }
            }
            recorridoV = recorridoV->siguiente;
        }
        delete recorridoV;
        delete recorridoA;
    }
}

void distanciaMinimaEntreUnVerticeYVecinos(const struct Grafo & grafo, struct Pila & pila,
        char verticeOrigen, double & minDistacia, char & letraCiudadMinDistancia) {

    struct Ciudad ciudad;

    while (not esPilaVacia(pila)) {
        ciudad = desapilar(pila);
        if (ciudad.ponderado < minDistacia) {
            minDistacia = ciudad.ponderado;
            letraCiudadMinDistancia = ciudad.elemento;
        }
    }
}

void mostrarTodosRecorridosDesdeUnaCiudad(const struct Grafo & grafo, char ciudadOrigen) {

    struct Pila pila;
    struct Ciudad ciudadP, ciudad;

    struct NodoVertice * recorridoV = new struct NodoVertice;
    struct NodoArista * recorridoA = new struct NodoArista;

    construir(pila);
    dameVecinosDeUnVertice(grafo, ciudadOrigen, pila);

    while (not esPilaVacia(pila)) {
        ciudadP = desapilar(pila);
        /*impresión de las rutas*/
        if (seEncuentraArista(grafo, ciudadOrigen, ciudadP.elemento))
            cout << endl << ciudadOrigen << ": " << ciudadP.elemento << " ";
        else
            cout << ciudadP.elemento << " ";
        recorridoV = grafo.listaVertice.cabeza;
        while (recorridoV != nullptr) {
            if (recorridoV->elemento == ciudadP.elemento) {
                recorridoA = recorridoV->listaArista.cabeza;
                while (recorridoA != nullptr) {
                    ciudad.elemento = recorridoA->elemento;
                    ciudad.ponderado = recorridoA->ponderado;
                    apilar(pila, ciudad);
                    recorridoA = recorridoA->siguiente;
                }
            }
            recorridoV = recorridoV->siguiente;
        }
    }
}