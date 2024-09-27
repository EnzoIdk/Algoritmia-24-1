/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 * 
 * Created on 7 de abril de 2024, 09:49 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>       
#include <cmath>

using namespace std;

void leerPedidos(int pedidos[12][4]){
    ifstream archDatos("Datos.txt",ios::in);
    if(not archDatos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Datos.txt"<<endl;
        exit(1);
    }
    for(int i=0;i<12;i++){
        for(int j=0;j<4;j++){
            archDatos>>pedidos[i][j];
//            cout<<pedidos[i][j]<<' ';
        }
//        cout<<endl;
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
    int pedidos[12][4];
    /*(cod. pedido, tipo pedido, hora entrega, tiempo entrega)*/
    leerPedidos(pedidos);
    int horas[24],hayCruce,solucion=0;
    int n=12,cantPed1,cantPed2,cantPed3,cantPed4;
    int cromo[n];
    int combinaciones=pow(2,n);
    for(int i=1;i<combinaciones;i++){
        cargaBin(i,n,cromo);
        cantPed1=cantPed2=cantPed3=cantPed4=hayCruce=0; /*Inicializando todos los datos*/
        for(int h=0;h<24;h++) horas[h]=0;
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                if(pedidos[j][1]==1) cantPed1++;
                else if(pedidos[j][1]==2) cantPed2++;
                else if(pedidos[j][1]==3) cantPed3++;
                else cantPed4++;
                /*recien procede a entregar el pedido a la hora de entrega qqqq*/
                for(int k=pedidos[j][2];k<pedidos[j][2]+pedidos[j][3];k++){
                    if(horas[k]==0) horas[k]=1; /*se registran las horas ocupadas*/
                    else{
                        hayCruce=1;
                        break;
                    }
                }
            }
            if(hayCruce) break;
        }
        /*verificamos la condicion que pide Linio*/
        if(cantPed1>=2 and cantPed2>=2 and cantPed3>=1 and cantPed4>=1 and hayCruce==0){
            cout<<"Solucion "<<++solucion<<':'<<endl;
            for(int j=0;j<n;j++){
                if(cromo[j]==1){
                    cout<<pedidos[j][0]<<"  "<<pedidos[j][1]<<endl;
                }
            }
        }
    }
    return 0;
}

