/* 
 * File:   NodoPuntaje.h
 * Author: ANA RONCAL
 * Created on 8 de octubre de 2023, 01:58 PM
 */

#ifndef NODOPUNTAJE_H
#define NODOPUNTAJE_H

struct NodoPuntaje{
	char equipo[15];		 // nombre del equipo
	int puntaje;			 // puntaje obtenido en el campeonato
	struct NodoPuntaje * siguiente;	 // puntero al siguiente nodo
};

#endif /* NODOPUNTAJE_H */

