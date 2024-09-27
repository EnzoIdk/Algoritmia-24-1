/* 
 * File:   funcionesArbolesBB.h
 * Author: ANA RONCAL
 * Created on 24 de septiembre de 2023, 10:34 PM
 */

#ifndef FUNCIONESARBOLESBB_H
#define FUNCIONESARBOLESBB_H

void construir(struct ArbolBinarioBusqueda & arbol);
bool esArbolVacio(struct ArbolBinarioBusqueda  arbol);
void plantarArbolBB(struct NodoCampeonato *& arbol, 
                    struct NodoCampeonato * arbolIzquierdo,  struct Partido, 
                    struct NodoCampeonato * arbolDerecho);

void mostrarPartidosEquipo(struct ArbolBinarioBusqueda arbol, const char *);

void recorrerEnOrdenRecursivoEstadisticas(struct NodoCampeonato * nodo, 
        const char * nombre, int & cantPartGanados, int & cantPartEmpatados, 
        int & cantPartPerdidos, int & golesAFavor, int & golesEnContra, 
        int & puntajeTotal);

void recorrerEnOrdenEstadisticas(struct ArbolCampeonato arbol, const char * nombre, 
         int & cantPartGanados, int & cantPartEmpatados, int & cantPartPerdidos,
         int & golesAFavor, int & golesEnContra, int & puntajeTotal);
void obtenerEstadisticaEquipo(struct ArbolBinarioBusqueda arbolBB, const char * nombre, 
         int & cantPartGanados, int & cantPartEmpatados, int & cantPartPerdidos,
         int & golesAFavor, int & golesEnContra, int & puntajeTotal);

void insertar(struct ArbolBinarioBusqueda & arbol, struct Partido);

void cargarPartidos(const char * nombreArch, struct ArbolBinarioBusqueda & arbolBB);
void elaborarTablaPosiciones(const char * alfa, const char * beta, const char * gama,
        const char *  kapa, struct ArbolBinarioBusqueda arbolBB, struct Lista & lista);

#endif /* FUNCIONESARBOLESBB_H */

