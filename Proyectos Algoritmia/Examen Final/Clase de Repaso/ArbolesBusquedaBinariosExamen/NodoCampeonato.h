/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:55 PM
 */

#ifndef NODO_H
#define NODO_H

struct NodoCampeonato{
    struct Partido partido;  //Este dato representa el Elemento
    struct NodoCampeonato * izquierda;  //puntero al hijo izquierdo
    struct NodoCampeonato * derecha;   //puntero al hijo derecho
};

#endif /* NODO_H */

