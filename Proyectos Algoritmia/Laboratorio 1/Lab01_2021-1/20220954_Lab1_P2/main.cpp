/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 8 de abril de 2024, 09:05 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

/*
 3 bahías, cada una de N productos.
 Cada camion soporta hasta C toneladas.
 Cuentan con M divisiones para transportar los productos
 Se quiere que los productos sean la misma cantidad M y el
 peso de todo sea el C.
 */

void leerDatos(int &n,int &m,int &c,int bahias[3][15]){
    /*EL ARCHIVO LO CREAS TU aaaa*/
    ifstream archDatos("Datos.txt",ios::in);
    if(not archDatos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Datos.txt"<<endl;
        exit(1);
    }
    int num;
    char car;
    archDatos>>car>>car>>n>>car>>car>>m>>car>>car>>c;
    archDatos.get(); /*el salto de linea*/
    while(archDatos.get()!='\n');
    for(int i=0;i<3;i++){
        archDatos>>num>>car;
        for(int j=0;j<n;j++){
            archDatos>>bahias[i][j];
        }
    }
}

void cargaBin(int num,int n,int *cromo){
    int i=0;
    for(int i=0;i<n;i++) cromo[i]=0;
    while(num>0){
        cromo[i]=num%2;
        num/=2;
        i++;
    }
}

int main(int argc, char** argv) {
    int n,m,c,bahias[3][15];
    leerDatos(n,m,c,bahias);
    int solucion=-1,peso,cantProd;
    int cromo1[n],cromo2[n],cromo3[n];
    int combinaciones=pow(2,n);
    bool coma; 
    /*combinaciones primera bahia*/
    for(int i=0;i<combinaciones;i++){
        cargaBin(i,n,cromo1);
        /*combinaciones segunda bahia*/
        for(int j=0;j<combinaciones;j++){
            cargaBin(j,n,cromo2);
            /*combinaciones tercera bahia*/
            for(int k=0;k<combinaciones;k++){
                cargaBin(k,n,cromo3);
                /*verificando combinaciones de las 3 bahias*/
                peso=cantProd=0;
                for(int l=0;l<n;l++){
                    if(cromo1[l]==1){
                        peso+=bahias[0][l];
                        cantProd++;
                    }
                    if(cromo2[l]==1){
                        peso+=bahias[1][l];
                        cantProd++;
                    }
                    if(cromo3[l]==1){
                        peso+=bahias[2][l];
                        cantProd++;
                    }
                }
                if(peso==c and cantProd==m){
                    solucion++;
                    cout<<"SOLUCION "<<solucion+1<<") ";
                    cout<<"Bahia 1: ";
                    coma=false;
                    for(int l=0;l<n;l++){
                        if(cromo1[l]==1) {
                            if(coma) cout<<", "<<bahias[0][l];
                            else{
                                cout<<bahias[0][l];
                                coma=true;
                            }
                        }
                    }
                    cout<<" Bahia 2: ";
                    coma=false;
                    for(int l=0;l<n;l++){
                        if(cromo2[l]==1) {
                            if(coma) cout<<", "<<bahias[1][l];
                            else{
                                cout<<bahias[1][l];
                                coma=true;
                            }
                        }
                    }
                    cout<<" Bahia 3: ";
                    coma=false;
                    for(int l=0;l<n;l++){
                        if(cromo3[l]==1) {
                            if(coma) cout<<", "<<bahias[2][l];
                            else{
                                cout<<bahias[2][l];
                                coma=true;
                            }
                        }
                    }
                    cout<<endl;
                }
            }
        }
    }
    if(solucion==-1) cout<<"No hay respuesta valida"<<endl;
    return 0;
}

