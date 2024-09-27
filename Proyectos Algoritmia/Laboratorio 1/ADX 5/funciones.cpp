
/*/ 
 * Projecto:  ADX_5
 * Nombre del Archivo:  funciones.cpp
 * Autor: MetroCyndx
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;
#include "funciones.h"
#define TAMLINEA 55

                        /* - / Funciones en Main / - */

// Modulo de Lectura de Datos Iniciales
void leerDatos(ifstream &archDatos,int *arrCargaCamiones,int *arrPesoPaquetes,
        int &cantCamiones,int &cantPaquetes){
    // Declaracion de Variables
    char descarte[15]{};
        // Iterativa del Proceso de Lectura
        while(1){
            archDatos>>descarte;
            if(archDatos.eof()) break; // Validacion de Fin de Archivo
            while(archDatos.get()!=':'); // Descarte de Letras
            // Iterativa de Lectura de Datos de Camion
            for(cantCamiones = 0;archDatos.get()!='\n';cantCamiones++)
                archDatos>>arrCargaCamiones[cantCamiones];
            while(archDatos.get()!=':'); // Descarte de Letras
            // Iterativa de Lectura de Datos de Paquetes
            for(cantPaquetes = 0;archDatos.get()!='\n';cantPaquetes++) 
                archDatos>>arrPesoPaquetes[cantPaquetes];
        }
}
// Modulo de Impresion de Datos y Condiciones Iniciales
void imprimirInicio(int *arrCargaCamiones,int *arrPesoPaquetes,
                int cantCamiones,int cantPaquetes){
    // Proceso de Impresion
    cout<<"SE TIENEN LOS CAMIONES:"<<endl;
    imprimirLinea(TAMLINEA,'-');
    cout<<setw(12)<<"CAMION ID"<<setw(14)<<"Carga Max."<<endl;
    // Iterativa del Proceso de Impresion de Datos de Camion
    for(int i=0;i<cantCamiones;i++) 
        cout<<setw(8)<<i+1<<setw(14)<<arrCargaCamiones[i]<<endl;
    imprimirLinea(TAMLINEA,'=');
    cout<<"PARA LLEVAR LOS PAQUETES:"<<endl;
    imprimirLinea(TAMLINEA,'-');
    cout<<setw(12)<<"PAQUETE ID"<<setw(14)<<"Peso en Kg."<<endl;
    // Iterativa del Proceso de Impresion de Datos de Paquete
    for(int i=0;i<cantPaquetes;i++) 
        cout<<setw(8)<<i+1<<setw(14)<<arrPesoPaquetes[i]<<endl;
    imprimirLinea(TAMLINEA,'=');
    // Impresion de Condiciones
    cout<<"CON LAS CONDICIONES:"<<endl;
    imprimirLinea(TAMLINEA,'-');
    cout<<"- La diferencia entre el maximo espacio no ocupado"<<endl;
    cout<<" de los camiones con el minimo, sea la menor posible."<<endl;
    cout<<"- Todos los camiones deben tener carga."<<endl;
    imprimirLinea(TAMLINEA,'=');
}
// Modulo de Optimizacion de Impresion de Solucion Mas Optima
void optimizarPaquetes(int *arrCargaCamiones,int *arrPesoPaquetes,
                int cantCamiones,int cantPaquetes){
    // Declaracion de Variables
    bool camionSinCarga;
    int combinador[cantPaquetes]{},espNoUsado[cantCamiones]{};
    int combinaciones = pow(cantCamiones,cantPaquetes);
    int espMin,espMax,diferenciaExtrema,difMin = 999;
    int solucion[cantPaquetes]{};
        // Iterativa del Proceso de Seleccion para Optimizacion
        for(int i=1;i<combinaciones;i++){
            cargaPorBase(combinador,cantPaquetes,i,cantCamiones);
            espMax = 0;
            espMin = 999;
            for(int j=0;j<cantCamiones;j++) espNoUsado[j] = arrCargaCamiones[j]; // Iterativa de Iniciacializacion de Espacios
            // Iterativa del proceso de Resta por Espacios Usados
            for(int k=0;k<cantPaquetes;k++)
                espNoUsado[combinador[k]] -= arrPesoPaquetes[k];
            // Iterativa de Seleccion de Espacio No Usado Minimo y Maximo
            for(int n=0,espacio;n<cantCamiones;n++){
                espacio = espNoUsado[n];
                // Validacion de Uso de Camion
                if(espacio == arrCargaCamiones[n]){
                    camionSinCarga = true;
                    break;
                }else camionSinCarga = false;
                if(espacio>espMax) espMax = espacio; // Validacion de Espacio No Usado Maximo
                if(espacio<espMin) espMin = espacio; // Validacion de Espacio No Usado Minimo
            }
            diferenciaExtrema = espMax - espMin;
            // Validacion de Condiciones para Solucion
            if(espMin > 0 and diferenciaExtrema < difMin and !camionSinCarga){
                difMin = diferenciaExtrema;
                for(int n=0;n<cantPaquetes;n++) solucion[n] = combinador[n]; // Iterativa de Generacion de Solucion
            }
        }
    // Impresion de Solucion mas Optima
    imprimirSolucion(solucion,arrCargaCamiones,arrPesoPaquetes,
                cantCamiones,cantPaquetes,difMin);
}

                      /* - / Funciones Principales / - */

// Modulo de Impresion de Solucion Mas Optima
void imprimirSolucion(int *solucion,int *arrCargaCamiones,int *arrPesoPaquetes,
                int cantCamiones,int cantPaquetes,int difmin){
    // Proceso de Impresion
    cout<<"LA SOLUCION MAS OPTIMA SE DARA SI:"<<endl;
    imprimirLinea(TAMLINEA,'-');
    // Iterativa del Proceso de Impresion por Camiones
    for(int i=0,cantRecibidos=0;i<cantCamiones;i++){
        cout<<"El camion #"<<i+1<<" lleva:";
        cantRecibidos=0;
            // Iterativa del Proceso de Impresion por Seleccion de Paquetes
            for(int s=0;s<cantPaquetes;s++){
                if(solucion[s] == i){
                    if(cantRecibidos > 0) cout<<" y";
                    cantRecibidos++;
                    cout<<" el paquete #"<<s+1;
                }
            }
        cout<<endl;
    }
    // Impresion de Condicion Cumplida
    imprimirLinea(TAMLINEA,'-');
    cout<<"Diferencia entre el maximo espacio no ocupado de los"<<endl;
    cout<<"camiones con el minimo: "<<difmin<<endl;
    imprimirLinea(TAMLINEA,'=');
}

                     /* - / Funciones Auxiliares / - */

// Modulo de Apertura de Archivos IFSTREAM
ifstream abrirArchivo_IFS(const char *nombArch){
    ifstream archIFS(nombArch,ios::in);
    if(not archIFS.is_open()){
        cout<<"ERROR DE APERTURA: Archivo "<<nombArch<<endl;
        exit(1);
    }
    return archIFS;
}
// Modulo de Impresion de Datos en Linea
void imprimirLinea(int medida,char simbolo){
    for(int i=0;i<medida;i++) cout.put(simbolo);
    cout<<endl;
}
// Modulo de Carga de Arreglo Int con Numero en Base Ingresada
void cargaPorBase(int *arrBin,int medida,int num,int base){
    for(int i=0,digito;i<medida;i++){
        digito = num%base;
        arrBin[i] = digito;
        num /= base;
    }
}
