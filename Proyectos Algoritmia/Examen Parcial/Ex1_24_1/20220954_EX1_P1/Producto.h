/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: alulab14
 *
 * Created on 18 de mayo de 2024, 08:14 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Lista.h"

struct Producto{
    struct Lista calorias;
    int totalCal;
    char tipo;
};

#endif /* PRODUCTO_H */

