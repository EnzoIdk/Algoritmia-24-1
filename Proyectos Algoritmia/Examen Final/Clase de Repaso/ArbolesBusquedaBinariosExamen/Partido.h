/* 
 * File:   Partido.h
 * Author: ANA RONCAL
 * Created on 8 de octubre de 2023, 01:53 PM
 */

#ifndef PARTIDO_H
#define PARTIDO_H

struct Partido
{
	char local[15];      	// nombre del equipo local
	int golesLocal;		// goles anotados por el equipo local
	char visitante[15];   	// nombre del equipo visitante
	int golesVisitante;	// goles anotados por el equipo visitante
};


#endif /* PARTIDO_H */

