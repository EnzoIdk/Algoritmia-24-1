/*
 *  Intento de Lucas Mattias Alvites Galarza - 20221943
 */

/* 
 * File:   main.cpp
 * Author: Lucas
 *
 * Created on 4 de julio de 2024, 5:40 p.m.
 */

#include <iostream>
using namespace std;

#include "Pila.h"
#include "funcionesPila.h"

#define X 2
#define Y 2

/*
 * 1 agua 1 agua
 * 2 agua 1 tierra
 * 3 agua 1 aire
 * 1 tierra 1 tierra
 * 2 tierra 1 aire
 * 1 aire 1 aire
 */

struct Ejercito{
    int agua;
    int tierra;
    int aire;
};

bool venceActual(struct Ejercito princesa, struct Ejercito &bowser){
    //ERAN DEMASIADOS ifs
    int poderPeach=princesa.agua+2*princesa.tierra+3*princesa.aire;
    int poderBowser=bowser.agua+2*bowser.tierra+3*bowser.aire;
    if(poderPeach>=poderBowser){
        return false;
    }
    else{
        bowser.agua-=princesa.agua;
        bowser.tierra-=princesa.tierra;
        bowser.aire-=princesa.aire;
        return true;
    }
}

bool buscaCamino(struct Ejercito princesa[4], struct Ejercito &bowser, 
        int grafo[X*Y+2][X*Y+2], int fin, int act, int numNodos){
    //CASO FIN
    if(act==numNodos-1) return true;
    bool sigue,loVence;
    struct Ejercito bowserTemp=bowser;
    
    for(int i=0; i<numNodos; i++){
        bowser=bowserTemp;
        if(grafo[act][i]){
            if(i==numNodos-1) return true;
            if(i-1<=3){
                loVence=venceActual(princesa[i-1],bowser);
                if(loVence){
                    cout<<i<<' ';
                    sigue=buscaCamino(princesa,bowser,grafo,fin,i,numNodos);
                    if(sigue) return sigue;
                    else cout<<'X'<<endl;
                }
                else cout<<i<<" X"<<endl;
            }
            else return false;
        }
    }
    return false;
}

int main(int argc, char ** argv) {
    
    struct Ejercito princesa[4]={
        {30, 20, 10}, //1
        {35, 25, 15}, //2
        {18, 15, 12}, //3
        {22, 13, 10}  //4
    };
    struct Ejercito bowser={150, 80, 40};
    
    int grafo[X*Y+2][X*Y+2]={
       //B  1  2  3  4  P
        {0, 1, 1, 0, 0, 0}, //B
        {0, 0, 0, 1, 1, 0}, //1
        {0, 0, 0, 1, 1, 0}, //2
        {0, 0, 0, 0, 0, 1}, //3
        {0, 0, 0, 0, 0, 1}, //4
        {0, 0, 0, 0, 0, 0}  //P
    };
    int numNodos=(int)(sizeof(grafo)/sizeof(grafo[0]));
    
    if(buscaCamino(princesa, bowser, grafo, numNodos-1, 0, numNodos)) 
        cout<<"Bowser gana"<<endl;
    else cout<<"Princesa gana"<<endl;
    
    return 0;
}

