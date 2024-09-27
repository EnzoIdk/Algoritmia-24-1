#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Cola.h"
#include "Lista.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
#include "funciones.h"

void insertardatos(struct Lista &warriors, int &n, int &cant_warriros){
    
    cout<<"Ingrese el valor de n: ";
    cin>>n;
    cout<<"Ingrese la cantidad total de guerreros: ";
    cin>>cant_warriros;
    
    int warrior;
    for(int i=0; i<cant_warriros;i++){
        cin>>warrior;
        insertarencola(warriors,warrior);
    }
    cout<<endl;
}
void asignarEjercito(struct Lista warriors,struct Lista &bowser, struct Lista &peach,
                     struct Lista &donkey){
    int asingarEjer1=0,asingarEjer2=0,asingarEjer3=0;
    while (!esListaVacia(warriors)) {
        int ejercito = warriors.cabeza->elemento % 10;
        int level = warriors.cabeza->elemento / 10;
        
        if(ejercito == 1){
            if(asingarEjer1==0){
                bowser.numEjercito = 1;
                asingarEjer1=1;
            }
            bowser.cantLevel += level;
            insertarOrdenar(bowser, level);
        }else{
            if(ejercito == 2){
                if(asingarEjer2==0){
                    peach.numEjercito = 2;
                    asingarEjer2=1;
                }
                peach.cantLevel += level;
                insertarOrdenar(peach, level);
            }else{
                if(asingarEjer3==0){
                    donkey.numEjercito = 3;
                    asingarEjer3=1;
                }
                donkey.cantLevel += level;
                insertarOrdenar(donkey, level);
            }
        }
        eliminaCabeza(warriors); // eliminamos la cabeza
    } 
}

void insertarOrdenar(struct Lista &L, int e) {
    if (esListaVacia(L)) {
        Nodo *nuevo = crearNodo(e, nullptr);
        L.cabeza = nuevo;
        L.cola = nuevo;
    } else {
        Nodo *ant = ubicarAnterior(L, e);
        if (ant == nullptr) { // insertamos al final
            if (L.cabeza->elemento > e)
                insertarAlInicio(L, e);
            else {
                Nodo *nuevo = crearNodo(e, nullptr);
                L.cola->siguiente = nuevo;
                L.cola = nuevo;
            }
        } else {
            Nodo *nuevo = crearNodo(e, nullptr);
            nuevo->siguiente = ant->siguiente;
            ant->siguiente = nuevo;
        }
    }
}

struct Nodo* ubicarAnterior(struct Lista &L, int e) {
    Nodo *p, *pA;
    pA = nullptr;
    p = L.cabeza;
    while (p != nullptr) {
        if (p->elemento > e) {
            return pA;
        }
        pA = p;
        p = p->siguiente;
    }
    // no se encontro el anterior
    return nullptr;
}

void muestraEjercito(const struct Lista & tad){
    
    if(tad.numEjercito==1){
        cout<<"Ejercito 1 - Bowser:";
        imprime(tad);
    }
    
    if(tad.numEjercito==2){
        cout<<"Ejercito 2 - Peach:";
        imprime(tad);
    }
    
    if(tad.numEjercito==3){
        cout<<"Ejercito 3 - Donkey Kong:";
        imprime(tad);
    }
    
}

void mostraNivelEjercito(const struct Lista & tad){
    cout<<"Nivel total de ataque del ejercito "<<tad.numEjercito<<": "<<tad.cantLevel<<endl;
}

void batalla(struct Lista &bowser,struct Lista &peach, struct Lista &donkey, int n){
    int refuerzo=1;
    while(true){
        cout<<"Inicia batalla:"<<endl;
        struct Nodo *soldado1, *soldado2;
        soldado1= bowser.cabeza;
        soldado2= peach.cabeza;
        int peleador1= soldado1->elemento;
        int peleador2= soldado2->elemento;
        
        //Mostra ejercitos
        muestraEjercito(bowser);
        muestraEjercito(peach);
        
        //Comienza pelea
        for(int i=0; i<n; i++){
            cout << "Pelea " << (i + 1) << ":"
                    << peleador1 << " vs " << peleador2;
            // Nos preparamos para la sgte batalla
            soldado1 = soldado1->siguiente;
            soldado2 = soldado2->siguiente;
            
            // la pelea
            // el Profeso Allasi, dijo que no se tiene que considerar 
            // caso de empate
            if (peleador1 > peleador2) { // la pelea la gana bowser
                cout << ",gana " << peleador1 << endl;
                eliminaCabeza(peach);
                //Actualizamo el nivel de poder de peach
                peach.cantLevel-=peleador2;
                
            } else if (peleador1 < peleador2) { // la pele la gana peach
                cout << ",gana " << peleador2 << endl;
                //Actualizamo el nivel de poder de bowser
                bowser.cantLevel-=peleador1;
                eliminaCabeza(bowser);
            }
            
            // una de los 2 ejercitos ya no pueden pelear, porque se quedaron sin soldados
            // Y el ejercito de peach ya no necesita ayuda
            if (soldado1 == nullptr or (soldado2 == nullptr and refuerzo==0)) {
                break;
            }
            // los siguiente peleadores
            peleador1 = soldado1->elemento;
            peleador2 = soldado2->elemento;
        }
        
        mostraNivelEjercito(bowser);
        mostraNivelEjercito(peach);
        
        //sale del while
        if(esListaVacia(bowser) || esListaVacia(peach)) break;
        
        // usamos los refuerzos si es que se dispone y si Peach va perdiendo
        if (refuerzo==1 && (bowser.cantLevel>peach.cantLevel)) { 
            refuerzo = 0;
            fusionar(peach, donkey); // fucionamos la lista
            cout << "El ejercito de DonKey Kong se une al ejercito de Peach" << endl;
        } else {
            cout << "Ya no se puede unir nadie al ejercito de Peach" << endl;
        }
        cout<<endl;
    }
    if(esListaVacia(peach)){
        cout << "Gana la batalla Bowser" <<endl;
    }else{
        cout << "gana la batalla Peach" <<endl;
    }
}


//Algoritmo de polloTiko
void fusionar(struct Lista &lista1,struct Lista &lista2){
    
    //Sumamos poder
    lista1.cantLevel += lista2.cantLevel;
    
    /*Aqui la lista 1 es disjunta a la lista 2 y es menor*/
    if (lista1.cola->elemento < lista2.cabeza->elemento){
        lista1.cola->siguiente = lista2.cabeza;
        lista1.cola = lista2.cola;
    }
    else {
        /*Aqui la lista 2 es disjunta a la lista 1 y es menor*/
        if (lista2.cola->elemento < lista1.cabeza->elemento){
            lista2.cola->siguiente = lista1.cabeza;
            lista1.cabeza = lista2.cabeza;
        }
        else {
            Nodo *inicio = nullptr;
            Nodo *fin = nullptr;
            while (!esListaVacia(lista1) && !esListaVacia(lista2)){
                if (lista1.cabeza->elemento<=lista2.cabeza->elemento){
                    if (inicio==nullptr){
                        inicio = lista1.cabeza;
                        fin = lista1.cabeza;
                    }
                    else {
                        fin->siguiente = lista1.cabeza;
                        fin = lista1.cabeza;
                    }
                    lista1.cabeza = lista1.cabeza->siguiente; 
                }
                else{
                    if (inicio==nullptr){
                        inicio = lista2.cabeza;
                        fin = lista2.cabeza;
                    }
                    else {
                        fin->siguiente = lista2.cabeza;
                        fin = lista2.cabeza;
                    }
                    lista2.cabeza = lista2.cabeza->siguiente;
                }
            }
            if (!esListaVacia(lista1)){
                fin->siguiente = lista1.cabeza;
                fin = lista1.cola;
            }
            if (!esListaVacia(lista2)){
                fin->siguiente = lista2.cabeza;
                fin = lista2.cola;
            }
            lista1.cabeza = inicio;
            lista1.cola = fin;
        }
    }
}



