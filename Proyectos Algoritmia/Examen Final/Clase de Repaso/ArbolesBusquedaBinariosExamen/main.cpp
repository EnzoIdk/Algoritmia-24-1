/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <cstdlib>
#include "Lista.h"
#include "ArbolCampeonato.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBusquedaB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesLista.h"

/*
 * IMPLEMENTA ARBOLES DE BÚSQUEDA BINARIA
 */
int main(int argc, char** argv) {

    struct ArbolBinarioBusqueda arbolBB;
    struct Lista lista;
    
    int cantPartGanados, cantPartEmpatados,cantPartPerdidos;
    int golesAFavor,golesEnContra, puntajeTotal;
    
    construir(lista);
    construir(arbolBB);
   
    cargarPartidos("campeonato.txt", arbolBB);
    mostrarPartidosEquipo(arbolBB, "ALFA");
   
    obtenerEstadisticaEquipo(arbolBB, "ALFA", cantPartGanados, cantPartEmpatados,
            cantPartPerdidos, golesAFavor, golesEnContra, puntajeTotal);
    
    cout<<"EQUIPO: ALFA"<<endl;
    cout<<"Partidos ganados  : "<<cantPartGanados<<endl;
    cout<<"Partidos empatados: "<<cantPartEmpatados<<endl;
    cout<<"Partidos perdidos : "<<cantPartPerdidos<<endl;
    cout<<"Goles a favor     : "<<golesAFavor<<endl;
    cout<<"Goles en contra   : "<<golesEnContra<<endl;
    cout<<"Puntaje total     : "<<puntajeTotal<<endl;
    
    elaborarTablaPosiciones("ALFA", "BETA", "GAMA", "KAPA", arbolBB, lista);
    imprime(lista);
    
    return 0;
}

