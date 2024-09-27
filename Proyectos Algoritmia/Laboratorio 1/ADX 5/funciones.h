
/*/ 
 * Projecto:  ADX_5
 * Nombre del Archivo:  funciones.h
 * Autor: MetroCyndx
/*/

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Funciones en Main
void leerDatos(ifstream &,int *,int *,int &,int &);
void imprimirInicio(int *,int *,int,int);
void optimizarPaquetes(int *,int *,int,int);


// Funciones Principales
void imprimirSolucion(int *,int *,int *,int,int,int);


// Funciones Auxiliares
ifstream abrirArchivo_IFS(const char *);
void imprimirLinea(int,char);
void cargaPorBase(int *,int ,int,int);

#endif /* FUNCIONES_H */
