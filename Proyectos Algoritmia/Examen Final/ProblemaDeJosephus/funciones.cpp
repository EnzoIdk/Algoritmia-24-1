/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 12:11 PM
 */

#include <iostream>
#include <iomanip> /*formato de números*/
#include <fstream>

#include "Lista.h"

#include "funciones.h"
using namespace std;
/*Valores iniciales de la lista*/
void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista  & tad) {
    return tad.longitud;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, int elemento) {

    /*Se va cambiar por la función crear nodo*/
    struct Nodo * nuevoNodo = crearNodo(elemento,tad.cabeza);
    struct Nodo *ultimo;
    if(tad.cabeza==nullptr){
        /*como es el primero, se apunta a si mismo*/
        tad.cabeza=nuevoNodo;
        /*nuevo*/
        nuevoNodo->siguiente=nuevoNodo;
    }
    else{
        ultimo=obtenerUltimoNodo(tad);
        ultimo->siguiente=nuevoNodo;
        tad.cabeza=nuevoNodo;
    }
//    nuevoNodo->elemento = elemento;
//    nuevoNodo->siguiente = tad.cabeza;
//
//    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

/*inserta un nodo siempre al final de la lista*/
void insertarAlFinal(struct Lista & tad, int elemento) {

    struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);
    struct Nodo * nuevoNodo = crearNodo(elemento, tad.cabeza);

    if (ultimoNodo == nullptr){ /*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        /*nuevo*/
        nuevoNodo->siguiente=nuevoNodo;
    }
    else //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(int elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía

/*Obtiene el último nodo de la lista*/
struct Nodo * obtenerUltimoNodo(const struct Lista & tad) {
    if(esListaVacia(tad)) return nullptr;
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = tad.cabeza;
    /*diferente*/
    do{
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }while(recorrido!=tad.cabeza);
    return ultimo;
}

/*inserta nodos al inicio de la lista desde un archivo*/
void insertarAlInicioArchivo(const char * nombArchText, struct Lista & tad) {
    ifstream archText(nombArchText, ios::in);
    if (not archText.is_open()) {
        cout << "ERROR: No se puede abrir el archivo";
        exit(1);
    }

    int elemento;
    while (true) {
        archText>>elemento; //lee el elemento del archivo
        if (archText.eof()) break;
        insertarAlInicio(tad, elemento);
    }
}

                                                                                                                                
void destruir(struct Lista & tad) {
    /*recorrido apunta al inicio del tad*/
    struct Nodo * recorrido = tad.cabeza;
    if(recorrido==nullptr) return;
    do {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }while(recorrido!=tad.cabeza);
    /*la lista queda vacia*/
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        do{
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento;
            recorrido = recorrido->siguiente;
        } while(recorrido!=tad.cabeza);
        cout << "]" << endl;
    }
}

//struct Nodo *obtenerNodoAnterior(const struct Lista &tad,int elemento){
//    if(esListaVacia(tad)) return nullptr;
//    struct Nodo *ant=nullptr;
//    struct Nodo *rec=tad.cabeza;
//    while(rec){ 
//        if(rec->elemento>=elemento) break;
//        ant=rec;
//        rec=rec->siguiente;
//    }
//    return ant;
//}

//void insertarEnOrden(struct Lista &tad,int elemento){
//    struct Nodo *nuevoNodo=crearNodo(elemento,nullptr);
//    struct Nodo *nodoAnterior=obtenerNodoAnterior(tad,elemento);
//    if(nodoAnterior==nullptr){
//        struct Nodo *ultimoNodo=obtenerNodoAnterior(tad,elemento);
//        nuevoNodo->siguiente=tad.cabeza;
//        tad.cabeza=nuevoNodo;
//        if(ultimoNodo!=nullptr){
//            ultimoNodo->siguiente=nuevoNodo;
//        }
//        else{
//            nuevoNodo->siguiente=nuevoNodo;
//        }
//    }
//    else{
//        nuevoNodo->siguiente=nodoAnterior->siguiente;
//        nodoAnterior->siguiente=nuevoNodo;
//    }
//    tad.longitud++;
//}

