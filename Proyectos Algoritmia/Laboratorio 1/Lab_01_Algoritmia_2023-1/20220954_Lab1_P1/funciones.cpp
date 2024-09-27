/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

#include "funciones.h"
#define MAX_CAMION 10
#define MAX_PAQUETE 10


void leerDatos(int *arrCapacidades,int &numCamiones,int *arrPesos,int &numPaquetes){
    ifstream arch("DatosCargaPesos.txt",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo DatosCargaPesos.txt"<<endl;
        exit(1);
    }
    arch>>numCamiones>>numPaquetes;
    for(int i=0;i<numCamiones;i++){
        arch>>arrCapacidades[i];
    }
    for(int i=0;i<numPaquetes;i++){
        arch>>arrPesos[i];
    }
}

void mostrarDatos(int *arrCapacidades,int numCamiones,int *arrPesos,int numPaquetes){
    cout<<"Datos leidos:"<<endl;
    cout<<numCamiones<<' '<<numPaquetes<<endl;
    for(int i=0;i<numCamiones;i++) cout<<arrCapacidades[i]<<' ';
    cout<<endl;
    for(int i=0;i<numPaquetes;i++) cout<<arrPesos[i]<<' ';
    cout<<endl<<endl;
}

void optimizarPaquetes(int *arrCapacidades,int m,int *arrPesos,int n){
    int diferencia[m]{},carga[m]{};
    int cromo[n];
    int combinaciones=(int)pow(m+1,n);
    int maxDif,minDif;
    int solOptima=999,posSol;
    
    for(int i=1;i<combinaciones;i++){
        cargaBase(i,cromo,m+1,n);
        for(int j=0;j<m;j++){
            diferencia[j]=0;
            carga[j]=0;
        }
        /*todos los paquetes deben haber sido entregados a algún camión*/
        if(todoLleno(cromo,n)){
            /*recorre todos los paquetes y aumenta la carga al camion*/
            for(int j=0;j<n;j++) carga[cromo[j]-1]+=arrPesos[j];
            /*recorre todos los camiones y asigna la diferencia*/
            for(int k=0;k<m;k++) diferencia[k]=arrCapacidades[k]-carga[k];
            /*solo tomar si la diferencia no resultó negativa en ningún camión*/
            if(respetaCap(diferencia,m)){
                /*evaluando las diferencias de espacios por cada camión*/
                calculaMaxMinDif(diferencia,m,maxDif,minDif);
                if(maxDif-minDif<solOptima){
                    solOptima=maxDif-minDif;
                    posSol=i;
                }
            }
        }
    }
    cargaBase(posSol,cromo,m+1,n);
    cout<<"MEJOR SOLUCION"<<endl;
    for(int i=0;i<n;i++) cout<<"Paquete "<<i+1<<": Camion "<<cromo[i]<<endl;
    cout<<"Diferencia maxima: "<<solOptima<<endl;
}

void calculaMaxMinDif(int *diferencia,int nd,int &maxDif,int &minDif){
    maxDif=-1,minDif=999;
    for(int i=0;i<nd;i++){
        if(diferencia[i]>maxDif) maxDif=diferencia[i];
        if(diferencia[i]<minDif) minDif=diferencia[i];
    }
}

bool respetaCap(int *dif,int tam){
    for(int i=0;i<tam;i++){
        if(dif[i]<0) return false;
    }
    return true;
}

bool todoLleno(int *arr,int tam){
    for(int i=0;i<tam;i++){
        if(arr[i]==0) return false; /*si hay alguno vacío*/
    }
    return true;
}

/*cromo[i]=0,1,2,3,4. Se asigna a alguno de los 4 camiones o a ninguno (0)*/
void cargaBase(int num,int *cromo,int base,int n){
    int i=0;
    for(int i=0;i<n;i++) cromo[i]=0;
    while(num>0){
        cromo[i]=num%base;
        num/=base;
        i++;
    }
}

