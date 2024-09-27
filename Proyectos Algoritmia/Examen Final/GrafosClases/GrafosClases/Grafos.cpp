/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "ListaArista.h"
#include "ListaVertice.h" //Necesita
#include "Grafo.h"
using namespace std;
#include "funcionesListaVertice.h"
#include "funcionesGrafo.h"
#include "NodoListaVertice.h"

/*
 * IMPLEMENTA GRAFOS
 */
int main(int argc, char** argv) {

    struct Grafo grafo;
    
    //Construir el Grafo
    construirGrafo(grafo);
    
    //Agregar los vértices
    agregarVertice(grafo, 'A');
    agregarVertice(grafo, 'B');
    agregarVertice(grafo, 'C');
    agregarVertice(grafo, 'D');
    
    //Eliminar el vértice
    //eliminarVertice(grafo, 'B');
    
    //Agregar las aristas
    agregarArista(grafo, 'A', 'B');
    agregarArista(grafo, 'C', 'A');
    agregarArista(grafo, 'D', 'A');
    agregarArista(grafo, 'D', 'C');
   
    //eliminar la arista
    //eliminarArista(grafo, 'D', 'C');
   
    //Muestra los resultados
    destruirGrafo(grafo);
    mostrarVerticeYAristas(grafo);
   return 0;
}

/* 
 * File:   Grafo.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:17 AM
 */

#ifndef GRAFO_H
#define GRAFO_H

struct Grafo{
    struct ListaVertice listaVertice;
    int longitud;
};

#endif /* GRAFO_H */

/* 
 * File:   NodoListaArista.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:25 AM
 */

#ifndef NODOLISTAARISTA_H
#define NODOLISTAARISTA_H

struct NodoListaArista {
    char elemento;    //ElementoListaArista: ACÁ PUEDE CAMBIAR EL ELEMENTO
    struct NodoListaArista * siguiente;
} ;


#endif /* NODOLISTAARISTA_H */

/* 
 * File:   NodoListavertice.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:22 AM
 */

#ifndef NODOLISTAVERTICE_H
#define NODOLISTAVERTICE_H

struct NodoListaVertice{
    char elemento;    //ACÄ puede cambiar el elemento
    struct NodoListaVertice * siguiente;
    struct ListaArista listaArista;
};

#endif /* NODOLISTAVERTICE_H */

/* 
 * File:   ListaArista.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:25 AM
 */

#ifndef LISTAARISTA_H
#define LISTAARISTA_H

struct ListaArista{
    int longitud;
    struct NodoListaArista * cabeza;
};

#endif /* LISTAARISTA_H */

/* 
 * File:   ListaVertica.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:20 AM
 */

#ifndef LISTAVERTICA_H
#define LISTAVERTICA_H

struct ListaVertice{
    struct NodoListaVertice  * cabeza;
    int longitud;
};

#endif /* LISTAVERTICA_H */

/* 
 * File:   funcionesListaArista.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 11:01 AM
 */

#ifndef FUNCIONESLISTAARISTA_H
#define FUNCIONESLISTAARISTA_H

void construirListaAristas(struct ListaArista & listaArista);
bool seEncuentraAristaEnListaArista(struct ListaArista listaArista, char llave);
struct NodoListaArista * obtenerUltimoNodoA( struct ListaArista  listaArista);
struct NodoListaArista * crearNodoA(char elemento, struct NodoListaArista * siguiente);
void insertarAristaAlFinal(struct ListaArista & listaArista, char vertice);

void eliminarAristaEnLista(struct ListaArista & listaArista, char vertice);
void destruirListaArista(struct ListaArista & listaArista);

#endif /* FUNCIONESLISTAARISTA_H */

/* 
 * File:   funcionesListaVertice.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:38 AM
 */

#ifndef FUNCIONESLISTAVERTICE_H
#define FUNCIONESLISTAVERTICE_H

void construirListaVertice(struct ListaVertice & listaVertice);
bool esListaVerticeVacio(struct ListaVertice listaVercice);
bool seEncuentraVerticeLista(struct ListaVertice listaVercice, char elemento);
struct NodoListaVertice * crearNodoV(char elemento, struct NodoListaVertice * siguiente);
struct NodoListaVertice * obtenerUltimoNodoV( struct ListaVertice listaVertice);
void insertarVerticeAlFinal(struct ListaVertice & listaVertice, char element);
bool seEncuentraAristaLista(struct ListaVertice listaVertice, char verticeOrigen, char verticeDestino);
struct NodoListaVertice * obtenerNodoVertice(struct ListaVertice listaVertice, char clave);
void insertarListaAristas(struct ListaVertice &, char verticeOrigen, char verticeDestino);


void eliminarVerticeEnLista(struct ListaVertice & listaVertice, char vertice);
void eliminarDeListaDeAristas(struct ListaVertice & listaVertice, char verticeOrigen, char verticeDestino);
void destruirListaVertice(struct ListaVertice & listaVertice);
#endif /* FUNCIONESLISTAVERTICE_H */

/* 
 * File:   funcionesGrafo.h
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:19 AM
 */

#ifndef FUNCIONESGRAFO_H
#define FUNCIONESGRAFO_H
void construirGrafo(struct Grafo & grafo);
void agregarVertice(struct Grafo & grafo, char);
bool esGrafoVacio(struct Grafo grafo);
void agregarArista(struct Grafo & grafo, char vertice1, char vertice2);
void eliminarVertice(struct Grafo & grafo, char vertice);
int longitudGrafo(Grafo);

void mostrarVerticeYAristas(struct Grafo grafo);
int seEncuentraVerticeOrigen(struct Grafo grafo, char vertice);
void eliminarArista(struct Grafo & grafo, char verticeOrigen, char verticeDestino);
void destruirGrafo(struct Grafo & grafo);
#endif /* FUNCIONESGRAFO_H */

/* 
 * File:   funcionesListaArista.cpp
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 11:02 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaArista.h"
#include "ListaVertice.h"
#include "NodoListaArista.h"

using namespace std;
#include "funcionesListaArista.h"

void construirListaAristas(struct ListaArista & listaArista){
    listaArista.cabeza = nullptr;
    listaArista.longitud = 0;
}

bool seEncuentraAristaEnListaArista(struct ListaArista listaArista, char llave){
    struct NodoListaArista * recorrido = listaArista.cabeza;
    while((recorrido != nullptr) and (recorrido->elemento != llave)){        
        recorrido = recorrido->siguiente;
    }
    return recorrido != nullptr;    
}

struct NodoListaArista * crearNodoA(char elemento, struct NodoListaArista * siguiente){
    struct NodoListaArista * nuevoNodo = new struct NodoListaArista;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía
/*Obtiene el último nodo de la lista*/
struct NodoListaArista * obtenerUltimoNodoA(struct ListaArista  listaArista){
    struct NodoListaArista * ultimo = nullptr;
    struct NodoListaArista * recorrido = listaArista.cabeza;
    
    while(recorrido != nullptr){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

void insertarAristaAlFinal(struct ListaArista & listaArista, char vertice){
    struct NodoListaArista * ultimoNodo = obtenerUltimoNodoA(listaArista);
    struct NodoListaArista * nuevoNodo = crearNodoA(vertice, nullptr);
   
    if (ultimoNodo == nullptr)  /*Si la lista está vacia*/
        listaArista.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else    //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    listaArista.longitud++;
}

void eliminarAristaEnLista(struct ListaArista & listaArista, char vertice){
    struct NodoListaArista * ultimo = nullptr;
    struct NodoListaArista * recorrido = listaArista.cabeza;
    while(recorrido != nullptr and recorrido->elemento != vertice){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    if (recorrido != nullptr){
        if (ultimo == nullptr)
            listaArista.cabeza = recorrido->siguiente;
        else    
            ultimo->siguiente = recorrido->siguiente;        
        delete recorrido;
        listaArista.longitud--;
    }
}

void destruirListaArista(struct ListaArista & listaArista){    
    struct NodoListaArista * recorrido = listaArista.cabeza;
    while(recorrido != nullptr){
        struct NodoListaArista * nodoAEliminar = recorrido;        
        recorrido = recorrido->siguiente;
        delete(nodoAEliminar);
    }
    listaArista.cabeza = nullptr;
    listaArista.longitud = 0;
}

/* 
 * File:   funcionesListavertice.cpp
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:39 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaArista.h" //necesita
#include "ListaVertice.h"
#include "NodoListaVertice.h"
using namespace std;
#include "funcionesListaArista.h"
#include "funcionesListaVertice.h"

void construirListaVertice(struct ListaVertice & listaVertice){
    listaVertice.cabeza = nullptr;
    listaVertice.longitud = 0;
}

bool esListaVerticeVacio(struct ListaVertice listaVertice){
    return listaVertice.cabeza == nullptr;
}

bool seEncuentraVerticeLista(struct ListaVertice listaVertice, char llave){
    struct NodoListaVertice * recorrido = listaVertice.cabeza;
    while(recorrido != nullptr and recorrido->elemento != llave){        
        recorrido = recorrido->siguiente;
    }
    return recorrido != nullptr; 
}

struct NodoListaVertice * crearNodoV(char elemento, struct NodoListaVertice * siguiente){
    struct NodoListaVertice * nuevoNodo = new struct NodoListaVertice;
    
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    construirListaAristas(nuevoNodo->listaArista);
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía
/*Obtiene el último nodo de la lista*/
struct NodoListaVertice * obtenerUltimoNodoV( struct ListaVertice  listaVertice){
    struct NodoListaVertice * ultimo = nullptr;
    struct NodoListaVertice * recorrido = listaVertice.cabeza;
    
    while(recorrido != nullptr){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

void insertarVerticeAlFinal(struct ListaVertice & listaVertice, char elemento){
    struct NodoListaVertice * ultimoNodo = obtenerUltimoNodoV(listaVertice);
    struct NodoListaVertice * nuevoNodo = crearNodoV(elemento, nullptr);
   
    if (ultimoNodo == nullptr)  /*Si la lista está vacia*/
        listaVertice.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else    //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    listaVertice.longitud++;
}

struct NodoListaVertice * obtenerNodoVertice(struct ListaVertice listaVertice, char clave){
    struct NodoListaVertice * recorrido = listaVertice.cabeza;
    while((recorrido != nullptr) and (recorrido->elemento != clave)){        
        recorrido = recorrido->siguiente;
    }
    return recorrido;        
}

bool seEncuentraAristaLista(struct ListaVertice listaVertice, char verticeOrigen, char verticeDestino){
    struct NodoListaVertice * nodoVerticeOrigen = obtenerNodoVertice(listaVertice, verticeOrigen);
    if (nodoVerticeOrigen == nullptr)
	return false;
    return seEncuentraAristaEnListaArista(nodoVerticeOrigen->listaArista, verticeDestino);
}

void insertarListaAristas(struct ListaVertice & listaVertice, char verticeOrigen, char verticeDestino){
    struct NodoListaVertice * nodoVerticeOrigen = obtenerNodoVertice(listaVertice, verticeOrigen);
    if (nodoVerticeOrigen == nullptr){
        cout<<"Error al insertar la lista de arista. No se ha encontrado el vértice"<<verticeOrigen<<endl;
        return;
    }

    if ( not seEncuentraAristaEnListaArista(nodoVerticeOrigen->listaArista, verticeDestino)){
        insertarAristaAlFinal(nodoVerticeOrigen->listaArista, verticeDestino);
    }
}

void eliminarDeListaDeAristas(struct ListaVertice & listaVertice, char verticeOrigen, char verticeDestino){
    struct NodoListaVertice * nodoVerticeOrigen = obtenerNodoVertice(listaVertice, verticeOrigen);
    if (nodoVerticeOrigen != nullptr)
        eliminarAristaEnLista(nodoVerticeOrigen->listaArista, verticeDestino);

}

void eliminarVerticeEnLista(struct ListaVertice & listaVertice, char vertice){
    struct NodoListaVertice * ultimoNodo = nullptr;
    struct NodoListaVertice * recorrido = listaVertice.cabeza;

    while(recorrido != nullptr and recorrido->elemento != vertice){
        ultimoNodo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    if (recorrido != nullptr){
        if (ultimoNodo == nullptr)
            listaVertice.cabeza=recorrido->siguiente;
        else    
            ultimoNodo->siguiente = recorrido->siguiente;
        destruirListaArista(recorrido->listaArista);
        free(recorrido);
        listaVertice.longitud--;
    }
}

void destruirListaVertice(struct ListaVertice & listaVertice){    
    struct NodoListaVertice * recorrido = listaVertice.cabeza;
    while(recorrido != nullptr){
    	destruirListaArista(recorrido->listaArista);
        struct NodoListaVertice * nodoAEliminar = recorrido;        
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    listaVertice.cabeza = nullptr;
    listaVertice.longitud = 0;
}

/* 
 * File:   funcionesGrafo.cpp
 * Author: ANA RONCAL
 * Created on 27 de septiembre de 2023, 09:36 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "NodoListaArista.h"
#include "ListaArista.h"
#include "NodoListaVertice.h"
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

bool esGrafoVacio(struct Grafo grafo){
    return esListaVerticeVacio(grafo.listaVertice);
}

bool seEncuentraVertice(struct Grafo grafo, int elemento){
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

bool seEncuentraArista(struct Grafo grafo, char verticeOrigen, char verticeDestino){
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

int longitudGrafo(struct Grafo grafo){
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

void mostrarVerticeYAristas(struct Grafo grafo){
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