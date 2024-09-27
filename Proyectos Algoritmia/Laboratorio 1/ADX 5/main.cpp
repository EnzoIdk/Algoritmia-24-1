
/*/ 
 * Projecto:  ADX_5
 * Nombre del Archivo:  main.cpp
 * Autor: MetroCyndx
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funciones.h"
#define MAXCAMIONES 10
#define MAXPAQUETES 10
// Modulo Principal
int main(int argc, char** argv) {
    // APERTURA DE ARCHIVOS & DECLARACION DE VARIABLES
    ifstream archDatos = abrirArchivo_IFS("DatosCargaPesos.txt");
    int arrCargaCamiones[MAXCAMIONES]{};
    int arrPesoPaquetes[MAXPAQUETES]{};
    int cantCamiones = 0,cantPaquetes = 0;
    // LECTURA DE DATOS INICIALES
    leerDatos(archDatos,arrCargaCamiones,arrPesoPaquetes,cantCamiones,  
                                                                  cantPaquetes);
    // IMPRESION DE DATOS Y CONDICIONES INICIALES
    imprimirInicio(arrCargaCamiones,arrPesoPaquetes,cantCamiones,cantPaquetes);
    // OPTIMIZACION E IMPRESION DE SOLUCION OPTIMIZADA
    optimizarPaquetes(arrCargaCamiones,arrPesoPaquetes,cantCamiones,
                                                                  cantPaquetes);
    return 0;
}
