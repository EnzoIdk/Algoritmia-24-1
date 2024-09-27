/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <cstdlib>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
/*
 * 
 */
int main(int argc, char** argv) {

    struct ArbolBinario arbol;
    construir(arbol);
    
    cout<<"Es árbol vacio: "<<esArbolVacio(arbol)<<endl;
    plantarArbolBinario(arbol, nullptr, 100, nullptr);
    imprimeRaiz(arbol); cout<<endl;
    struct ArbolBinario arbol1, arbol2, arbol3, arbol4;
    plantarArbolBinario(arbol1, nullptr, 25, nullptr);
    plantarArbolBinario(arbol2, nullptr, 75, nullptr);
    plantarArbolBinario(arbol3, arbol1, 50, arbol2);
    plantarArbolBinario(arbol4, nullptr, 150, nullptr);
    plantarArbolBinario(arbol, arbol3, 100, arbol4);
    cout<<"Es árbol vacio: "<<esArbolVacio(arbol)<<endl;
    
    cout<<"Recorrer en orden: "<<endl;
    recorrerEnOrden(arbol); cout<<endl;
    cout<<"Recorrer en pre orden: "<<endl;
    recorrerPreOrden(arbol); cout<<endl;
    cout<<"Recorrer en post orden: "<<endl;
    recorrerPostOrden(arbol); cout<<endl;
    
    cout<<"Recorrer por niveles: "<<endl;
    recorridoPorNivel(arbol);
    cout<<endl<<"Recorrer en orden iterativo: "<<endl;
    enOrdenIterativo(arbol);
    cout<<endl<<"Recorrer en Pre orden iterativo: "<<endl;
    preOrdenIterativo(arbol); 
    
    cout<<endl;    
    cout<<endl<<"ALTURA arbol: "<<altura(arbol)<<endl;
    cout<<"NÚMERO DE HOJAS: "<<numeroHojas(arbol)<<endl;
    cout<<"NÚMERO DE NODOS: "<<numeroNodos(arbol)<<endl;
    cout<<"ES EQUILIBRADO: "<<esEquilibrado(arbol)<<endl;
    
    destruirArbolBinario(arbol);
    cout<<"Es árbol vacio: "<<esArbolVacio(arbol)<<endl;
      
    return 0;
}

/* 
 * File:   ArbolBB.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 06:01 PM
 */

#ifndef ARBOLBB_H
#define ARBOLBB_H

struct ArbolBinario{
    struct NodoArbol * raiz;
};

#endif /* ARBOLBB_H */

/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:55 PM
 */

#ifndef NODO_H
#define NODO_H

struct NodoArbol{
    int elemento;  //Este dato representa el Elemento
    struct NodoArbol * izquierda;  //puntero al hijo izquierdo
    struct NodoArbol * derecha;   //puntero al hijo derecho
};

#endif /* NODO_H */

/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:31 PM
 */

#ifndef NODO_H
#define NODO_H

struct Nodo{
    struct NodoArbol * nodo; /*aquí se cambia por el Elemento que se desee manejar*/
    struct Nodo * siguiente;
};

#endif /* NODO_H */

/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:28 AM
 */

#ifndef LISTA_H
#define LISTA_H

struct Lista{
    struct Nodo * cabeza;
    int longitud;
};

#endif /* LISTA_H */

/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef LISTA_H
#define LISTA_H

struct Lista{
    struct Nodo * cabeza;
    struct Nodo * cola;
    int longitud;
};

#endif /* LISTA_H */

/* 
 * File:   Cola.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef COLA_H
#define COLA_H

struct Cola{
    struct Lista lista;
};

#endif /* COLA_H */

/* 
 * File:   Pilas.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:33 AM
 */

#ifndef PILAS_H
#define PILAS_H

struct Pila{
    struct Lista lista;
};

#endif /* PILAS_H */

/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
bool esListaVacia( struct Lista  lista);
int longitud(struct Lista tad );
struct Nodo * crearNodo(struct NodoArbol *, struct Nodo * siguiente);
void insertarAlFinal(struct Lista & lista, struct NodoArbol *);
void imprime( struct Lista  lista);
void eliminaCabeza(struct Lista  & lista);
struct NodoArbol * retornaCabeza( struct Lista  lista);
void destruirLista(struct Lista &);

#endif /* FUNCIONESLISTA_H */

/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:32 AM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H


void construirP(struct Lista &);
void insertarAlInicio(struct Lista &, struct NodoArbol *);
struct Nodo * crearNodoP(struct NodoArbol *, struct Nodo *);
struct NodoArbol * retornaCabezaP( struct Lista );
bool esListaVaciaP( struct Lista );
int longitudP( struct Lista );
void eliminaCabezaP(struct Lista  &);

void destruir(struct Lista &);
void imprimeP( struct Lista );                                  

#endif /* FUNCIONESLISTA_H */

/* 
 * File:   funcionesCola.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construir(struct Cola & cola);
bool esColaVacia( struct Cola  cola);
void encolar(struct Cola & cola, struct NodoArbol *);
struct NodoArbol * desencolar(struct Cola & cola);
int longitud(struct Cola cola);
void imprime( struct Cola  cola);
void simularFilaEspera(struct Cola & cola);
void destruirCola(struct Cola & cola);

#endif /* FUNCIONESCOLA_H */

/* 
 * File:   funcionesPilas.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:29 AM
 */

#ifndef FUNCIONESPILAS_H
#define FUNCIONESPILAS_H

void construir(struct Pila & );
int longitud(struct Pila  );
bool esPilaVacia( struct Pila );
void apilar(struct Pila &, struct NodoArbol * ); 
struct NodoArbol * desapilar(struct Pila &);
struct NodoArbol * cima( struct Pila );
void destruirPila(struct Pila );
void imprimir( struct Pila );

#endif /* FUNCIONESPILAS_H */

/* 
 * File:   funcionesArboles.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 06:00 PM
 */

#ifndef FUNCIONESARBOLES_H
#define FUNCIONESARBOLES_H

void construir(struct ArbolBinario & );

bool esArbolVacio(struct ArbolBinario arbol);
bool esNodoVacio(struct NodoArbol * nodo);

struct NodoArbol * crearNuevoNodoArbol(struct NodoArbol *, int, 
                                                          struct NodoArbol *);
void plantarArbolBinario(struct ArbolBinario &, struct NodoArbol *, int,
                                                       struct NodoArbol * );
void plantarArbolBinario(struct ArbolBinario &, struct ArbolBinario, int,
                                                       struct ArbolBinario );
int raiz(struct NodoArbol * nodo);
void imprimeRaiz(struct ArbolBinario arbol);
void imprimeNodo(struct NodoArbol * nodo);

struct  NodoArbol * hijoDerecho(struct ArbolBinario );
struct  NodoArbol * hijoIzquierdo(struct ArbolBinario );

void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo);
void recorrerEnOrdenRecursivo(struct NodoArbol * nodo);
void recorrerEnPostOrdenRecursivo(struct NodoArbol * nodo);

void recorrerEnOrden(struct ArbolBinario );
void recorrerPreOrden(struct ArbolBinario );
void recorrerPostOrden(struct ArbolBinario );

int altura(struct ArbolBinario);
int alturaRecursivo(struct NodoArbol * nodo);

int numeroNodos(struct ArbolBinario );
int numeroNodosRecursivo(struct NodoArbol * nodo);

int numeroHojas(struct ArbolBinario );

int esEquilibrado(struct ArbolBinario );
int esEquilibradoRecursivo(struct NodoArbol * nodo);

int esHoja(struct ArbolBinario );

void destruirArbolBinario(struct ArbolBinario );
void destruirRecursivo(struct NodoArbol *);


void recorridoPorNivel(struct ArbolBinario arbol);
void enOrdenIterativo(struct ArbolBinario arbol);
void preOrdenIterativo(struct ArbolBinario arbol);


#endif /* FUNCIONESARBOLES_H */

/* 
 * File:   funcionesLista.cpp
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "Nodo.h"
#include "NodoArbol.h"
#include "Lista.h"
using namespace std;
#include "funcionesLista.h"
#include "funcionesArbolesBinarios.h"
#include "Nodo.h"
#include "Lista.h"


/*Valores iniciales de la lista*/
void construir(struct Lista & lista){
    lista.cabeza = nullptr;
    lista.cola = nullptr;
    lista.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVacia( struct Lista  lista){
    return lista.cabeza == nullptr;
}

/*DEVUELVE LA CANTIDAD DE ELEMENTOS DE LA LISTA*/
int longitud(struct Lista tad ){
    return tad.longitud;
}

/*CREA UN NUEVO ELEMENTO CON VALORES INICIALES*/
struct Nodo * crearNodo(struct NodoArbol * nodo, struct Nodo * siguiente){

    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->nodo = nodo;
    nuevoNodo->siguiente = siguiente; 
    return nuevoNodo;
}

/*INSERTA UN ELEMENTO AL FINAL DE LA LISTA*/
void insertarAlFinal(struct Lista & lista, struct NodoArbol * nodo){
   
    struct Nodo * nuevoNodo = crearNodo(nodo, nullptr);
    Nodo * ultimoNodo = lista.cola; /*obtiene el último nodo*/
    if (ultimoNodo == nullptr){
        lista.cabeza = nuevoNodo;
        lista.cola = nuevoNodo;
    }
    else{
        ultimoNodo->siguiente = nuevoNodo;
        lista.cola = nuevoNodo;
    }            
    lista.longitud++;  
}

struct NodoArbol * retornaCabeza( struct Lista  lista){
    if (esListaVacia(lista)){
        cout<<"No existe la cabeza por que la cola está vacía"<<endl;
        exit(1);
    }
   
    return lista.cabeza->nodo;
}

/*ELIMINA EL PRIMER ELEMENTO DE LA LISTA*/
void eliminaCabeza(struct Lista  & lista){
    struct Nodo * nodoEliminar = lista.cabeza;
    if (nodoEliminar == nullptr ){
        cout<<"No se puede eliminar la cabeza pues la lista estÃ¡ vacÃ­a";
        exit(1);
    }
    else{
        lista.cabeza = lista.cabeza->siguiente;
        if(lista.cabeza == nullptr)
            lista.cola = nullptr;
        delete nodoEliminar;
        lista.longitud--;
    }
}

/*LIBERA LA MEMORIA*/
void destruirLista(struct Lista & tad){
    struct Nodo * recorrido = tad.cabeza;
    struct Nodo * eliminarNodo;
    
    while(recorrido != nullptr){
        eliminarNodo = recorrido;        
        recorrido = recorrido->siguiente;
        delete eliminarNodo;
    }
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
}

void imprime(struct Lista lista){
       
    if (esListaVacia(lista)){
        cout<<"La cola esta vacía"<<endl;
    }
    else{
        struct Nodo * recorrido = lista.cabeza;
        while(recorrido != nullptr){
            imprimeNodo(recorrido->nodo);
            recorrido = recorrido->siguiente;
        }   
    }
    cout<<endl;
}

/* 
 * File:   funcionesLista.cpp
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:32 AM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "Nodo.h"
#include "NodoArbol.h"
#include "ListaP.h"
using namespace std;
#include "funcionesListaP.h"
#include "funcionesArbolesBinarios.h"
#include "Nodo.h"
#include "ListaP.h"

/*Valores iniciales de la lista*/
void construirP(struct Lista & tad){
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVaciaP(struct Lista  tad){
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitudP( struct Lista tad){
    return tad.longitud;
}

struct NodoArbol * retornaCabezaP(struct Lista tad){
    if (esListaVaciaP(tad)){
        cout<<"No existe la cabeza por que la cola está vacía"<<endl;
        exit(1);
    }
    return tad.cabeza->nodo;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, struct NodoArbol * nodo){
  
    /*Crea un nuevo nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo = crearNodoP(nodo, tad.cabeza);
    
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parÃ¡metros*/
struct Nodo * crearNodoP(struct NodoArbol * nodo, struct Nodo * siguiente){
    
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->nodo = nodo;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}


void eliminaCabezaP(struct Lista  & lista){
    struct Nodo * nodoEliminar = lista.cabeza;
    if (nodoEliminar == nullptr ){
        cout<<"No se puede eliminar la cabeza pues la lista estÃ¡ vacÃ­a";
        exit(1);
    }
    else{
        lista.cabeza = lista.cabeza->siguiente;
        delete nodoEliminar;
        lista.longitud--;
    }
}

void destruir(struct Lista & tad){
    /*recorrido apunta al inicio del tad*/
    struct Nodo * recorrido = tad.cabeza;
    
    while(recorrido != nullptr){
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;        
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimeP( struct Lista  tad){

    if (esListaVaciaP(tad)){
        cout<<"La Pila está vacía"<<endl;
    }
    else{
        
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout<<"[";

        while(recorrido != nullptr){
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout<<", ";
            estaImprimiendoLaCabeza = 0;
            imprimeNodo(recorrido->nodo);    
            recorrido = recorrido->siguiente;
        }
        cout<<"]"<<endl;
    }
}

/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#include <iostream>
#include <iomanip>
#include "ArbolBinario.h"
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
using namespace std;
#include "funcionesLista.h"
#include "funcionesCola.h"


#define PROCESO 120
#define MAX_CAJEROS 10
#define NUM_CLIENTES 100

void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia( struct Cola  cola){
    return esListaVacia(cola.lista);
}

int longitud(struct Cola cola){
    return longitud(cola.lista);
}

void encolar(struct Cola & cola, struct NodoArbol * nodo){
    insertarAlFinal(cola.lista, nodo);
}

struct NodoArbol *  desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(1);
    }
    
    struct NodoArbol * nodo = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return nodo;
}

void destruirCola(struct Cola & cola){
    destruirLista(cola.lista);
}

void imprime( struct Cola  cola){
    imprime(cola.lista);
}

/* 
 * File:   funcionesPilas.cpp
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:29 AM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "Nodo.h"
#include "ListaP.h"
#include "Pila.h"
using namespace std;
#include "funcionesListaP.h"
#include "funcionesPila.h"

/*constructor de Pila*/
void construir(struct Pila & pila){
    construirP(pila.lista);
}

/*Determina si la pila está vacía*/
bool esPilaVacia( struct Pila  pila){
    return esListaVaciaP(pila.lista);
}

/*Determina el número de elementos de la pila*/
int longitud( struct Pila   pila){
    return longitudP(pila.lista);
}

/*push, añade un elemento a la parte superior de la pila*/
void apilar(struct Pila & pila, struct NodoArbol * nodo){
    insertarAlInicio(pila.lista, nodo);
}

/*pop, elimina un elemento de la parte superior de la pila*/
struct NodoArbol * desapilar(struct Pila & pila){
    if (esPilaVacia(pila)){
        cout<<"La pila está vacía, por lo tanto no se puede desapilar"<<endl;
	exit(11);
    }	
    struct NodoArbol * nodo = cima(pila);
    eliminaCabezaP(pila.lista);
    return nodo;
}

/*examina un elemento situado en la parte superior de la pila*/
struct NodoArbol * cima(struct Pila pila){
    if (esPilaVacia(pila)){
	cout<<"La pila está vacía por lo tanto no posee cima"<<endl;
	exit(12);
    }		
    return retornaCabezaP(pila.lista);
}


/*destruye la pila*/
void destruirPila(struct Pila pila){
    destruir(pila.lista);
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimir(const struct Pila & pila){
    imprimeP(pila.lista);
}

///*imprime desapilando*/
//void imprime(struct Pila & pila){
//    
//    while(not esPilaVacia(pila)){
//        cout<<cima(pila)<<"-";
//        desapilar(pila);
//    }
//}

/* 
 * File:   funcionesArbolesBB.cpp
 * Author: ANA RONCAL
 * Created on 19 de septiembre de 2023, 10:46 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "NodoArbol.h"
#include "Nodo.h"
#include "ArbolBinario.h"
#include "Lista.h"
#include "ListaP.h"
#include "Cola.h"
#include "Pila.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"
#include "funcionesPila.h"

void construir(struct ArbolBinario & arbol ){
    arbol.raiz = nullptr;
}

bool esNodoVacio(struct NodoArbol * nodo){
    return nodo == nullptr;
}

bool esArbolVacio( struct ArbolBinario arbol){
    return esNodoVacio(arbol.raiz);
}

struct NodoArbol * crearNuevoNodoArbol(struct NodoArbol * arbolIzquierdo, 
                               int elemento, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct NodoArbol * arbolIzquierdo,
                         int elemento, struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo, elemento, arbolDerecho);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct ArbolBinario arbolIzquierdo,
                         int elemento, struct ArbolBinario arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo.raiz, elemento, arbolDerecho.raiz);
    arbol.raiz = nuevoNodo;
}

int raiz(struct NodoArbol * nodo){
    if (esNodoVacio(nodo)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    return nodo->elemento;
}

struct NodoArbol * hijoDerecho(struct ArbolBinario arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    return arbol.raiz->derecha;
}

struct  NodoArbol * hijoIzquierdo(struct ArbolBinario arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    
    return arbol.raiz->izquierda;
 }

void imprimeRaiz(struct ArbolBinario arbol){
    imprimeNodo(arbol.raiz);
}

void imprimeNodo(struct NodoArbol * nodo){
    cout<<setw(5)<<nodo->elemento;
}

void recorrerEnOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimeNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

/*En árbol, se lleva a cabo visitando el hijo izquierdo del nodo, luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerEnOrden(struct ArbolBinario arbol){
    /*Imprime en orden*/
    if (not esArbolVacio(arbol)){
        recorrerEnOrdenRecursivo(arbol.raiz);
    }
}

void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        imprimeNodo(nodo);
        recorrerEnPreOrdenRecursivo(nodo->izquierda);
        recorrerEnPreOrdenRecursivo(nodo->derecha);
    }
}

/*recorrido descendente, se lleva a cabo visitando cada nodo, seguido de sus hijos,
 luego todos los restantes, comenzando por la raíz*/
void recorrerPreOrden(struct ArbolBinario arbol){
    if (not esArbolVacio(arbol)){
        recorrerEnPreOrdenRecursivo(arbol.raiz);
    }
}

void recorrerEnPostOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnPostOrdenRecursivo(nodo->izquierda);
        recorrerEnPostOrdenRecursivo(nodo->derecha);
        imprimeNodo(nodo);
    }
}

/*recorrido ascendente, se lleva a cabo visitando los hijos, y luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerPostOrden(struct ArbolBinario arbol){
   
    if (not esArbolVacio(arbol)){
        recorrerEnPostOrdenRecursivo(arbol.raiz);
    }
}

int maximo(int a, int b){
    return a>=b ? a: b;
}

int alturaRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 0; 
    else
        return 1 + maximo( alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int altura(struct ArbolBinario arbol){
    return alturaRecursivo(arbol.raiz); //como el arbol ha sido construido no va apuntar a nullptr
}

int numeroNodosRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);   
}

/*Determina el número de elementos del árbol*/
int numeroNodos(struct ArbolBinario arbol){
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if ( esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha) )
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}

int numeroHojas(struct ArbolBinario arbol){
    return numeroHojasRecursivo(arbol.raiz);
}

int esEquilibradoRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 1;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia<=1 and 
               esEquilibradoRecursivo(nodo->izquierda) and 
               esEquilibradoRecursivo(nodo->derecha);
    }        
}

int esEquilibrado(struct ArbolBinario arbol ){
    return esEquilibradoRecursivo(arbol.raiz);
}

int esHoja(struct ArbolBinario arbol){
    if(esArbolVacio(arbol))
        return 0;
    else
        return esNodoVacio(arbol.raiz->izquierda) and esNodoVacio(arbol.raiz->derecha);
}

void destruirArbolBinario(struct ArbolBinario arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoArbol * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
        nodo = nullptr;
    }
}

/*recorre el árbol por niveles usando una cola*/
void recorridoPorNivel(struct ArbolBinario arbol){
    struct Cola cola; /*Se usa una cola para acceder a los nodos*/
    construir(cola);
    if(not esArbolVacio(arbol)){
        encolar(cola, arbol.raiz);
        while(not esColaVacia(cola)){
            struct NodoArbol * nodo = desencolar(cola);
            imprimeNodo(nodo);
            if (not esNodoVacio(nodo->izquierda)){
                encolar(cola, nodo->izquierda);
            }
            if (not esNodoVacio(nodo->derecha)){
                encolar(cola, nodo->derecha);  
            }
        }
    }
    destruirCola(cola);   
}

void enOrdenIterativo(struct ArbolBinario arbol){
    struct Pila pila; /*Se usa una pila para acceder a los nodos*/
    construir(pila);
    int fin = 0;
    do{
        while (not esArbolVacio(arbol)){
            apilar(pila, arbol.raiz);
            arbol.raiz = arbol.raiz->izquierda;
        }
        if (esPilaVacia(pila))
            fin = 1;
        else{
            arbol.raiz = desapilar(pila);
            imprimeRaiz(arbol);
            arbol.raiz = arbol.raiz->derecha;
        }
    } while(fin == 0);
    destruirPila(pila);
}

void preOrdenIterativo(struct ArbolBinario arbol){
    struct Pila pila;  /*Se usa una pila para acceder a los nodos*/
    construir(pila);
    if (not esArbolVacio(arbol)){        
        apilar(pila, arbol.raiz);
        while(not esPilaVacia(pila)){
            struct NodoArbol * nodo = desapilar(pila);
            imprimeNodo(nodo);
            if (not esNodoVacio(nodo->derecha))
                apilar(pila, nodo->derecha);
            if (not esNodoVacio(nodo->izquierda))
                apilar(pila, nodo->izquierda);           
        }
    }
    destruirPila(pila);   
}
