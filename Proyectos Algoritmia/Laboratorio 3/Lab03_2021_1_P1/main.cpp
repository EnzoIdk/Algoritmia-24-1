/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 10 de mayo de 2024, 06:03 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream> 
#include <climits>
#define N 7
#define M 7
using namespace std;

//char tablero[N][M]={
//    {'A','B','C','D','E','F','G'},
//    {'A','B','C','D','E','F','G'},
//    {'A','B','C','D','E','F','G'},
//    {'A','B','C','D','E','F','G'},
//    {'A','B','C','D','E','F','G'},
//    {'A','B','C','D','E','F','G'},
//    {'A','B','C','D','E','F','G'},
//};
//
//void leerDatos(int &numDias,int &numEmp,double &ibm,int valores[N][M],char letras[N][M],double prom[N]){
//    int suma;
//    cin>>numEmp>>numDias>>ibm;
//    for(int i=0;i<numDias;i++){
//        suma=0;
//        for(int j=0;j<numEmp;j++){
//            cin>>valores[i][j];
//            suma+=valores[i][j];
//            letras[i][j]=tablero[i][j];
//        }
//        prom[i]=(double)suma/numEmp;
//    }
//}

void merge(int *valores,char *letras,int ini,int med,int fin){
    int tamIzq=med-ini+1,tamDer=fin-med;
    int auxIntIzq[tamIzq+1],auxIntDer[tamDer+1];
    char auxCharIzq[tamIzq+1]{},auxCharDer[tamDer+1]{};
    for(int i=ini;i<=med;i++){
        auxIntIzq[i-ini]=valores[i];
        auxCharIzq[i-ini]=letras[i];
    }
    auxIntIzq[tamIzq]=INT_MAX;
    for(int i=med+1;i<=fin;i++){
        auxIntDer[i-med-1]=valores[i];
        auxCharDer[i-med-1]=letras[i];
    }
    auxIntDer[tamDer]=INT_MAX;
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        if(auxIntIzq[p]<auxIntDer[q]){
            valores[i]=auxIntIzq[p];
            letras[i]=auxCharIzq[p];
            p++;
        }
        else{
            valores[i]=auxIntDer[q];
            letras[i]=auxCharDer[q];
            q++;
        }
    }
}

void mergeSort(int *valores,char *letras,int ini,int fin){
    if(ini==fin) return;
    int med=(ini+fin)/2;
    mergeSort(valores,letras,ini,med);
    mergeSort(valores,letras,med+1,fin);
    merge(valores,letras,ini,med,fin);
}

/*si vende, buscamos la primera posición en la que lo hace*/
/*si no vende(compra), buscamos la última posición en la que lo hace*/
int busquedaBinaria(int *arr,int ini,int fin,bool vende,double ibd){
    if(ini>fin) return -1;
    int med=(ini+fin)/2;
    if(vende){ /*valores mayores al ibd*/
        if((double)arr[med]>=ibd){
            if((double)arr[med-1]<ibd) return med;
            else busquedaBinaria(arr,ini,med-1,vende,ibd);
        }
        else busquedaBinaria(arr,med+1,fin,vende,ibd);
    }
    else{ /*valores menores al ibd*/
        if((double)arr[med]<=ibd){
            if((double)arr[med+1]>ibd) return med;
            else busquedaBinaria(arr,med+1,fin,vende,ibd);
        }
        else busquedaBinaria(arr,ini,med-1,vende,ibd);
    }
}

int obtenerMonto(int *valores,int pos,int num,bool vende){
    int monto=0;
    if(vende)
        for(int i=pos;i<num;i++) monto+=valores[i];
    else
        for(int i=0;i<=pos;i++) monto+=valores[i];
    return monto;
}

void imprimirEmpresas(char *letras,int pos,int num,bool vende){
    if(vende)
        for(int i=pos;i<num;i++) cout<<letras[i]<<' ';
    else
        for(int i=0;i<=pos;i++) cout<<letras[i]<<' ';
    cout<<endl;
}

int main(int argc, char** argv) {
    int numEmp=7,numDias=6;
    double ibm=4.2,ibd[N]{};
    char letras[N][M]={
        {'A','B','C','D','E','F','G'},
        {'A','B','C','D','E','F','G'},
        {'A','B','C','D','E','F','G'},
        {'A','B','C','D','E','F','G'},
        {'A','B','C','D','E','F','G'},
        {'A','B','C','D','E','F','G'},
    };
    
    int valores[N][M]={
        {8,4,5,6,7,1,2},
        {3,4,5,7,1,2,6},
        {5,6,5,2,1,6,8},
        {3,4,5,6,2,1,9},
        {3,4,5,4,5,3,2},
        {3,4,4,8,9,7,6},
    };
    int pos,monto,suma;
    bool vende;
    for(int i=0;i<numDias;i++){
        suma=0;
        for(int j=0;j<numEmp;j++){
            suma+=valores[i][j];
        }
        ibd[i]=(double)suma/numEmp;
    }
//    leerDatos(numDias,numEmp,ibm,valores,letras,ibd);
    cout<<setprecision(3)<<fixed;
    for(int i=0;i<numDias;i++){
        mergeSort(valores[i],letras[i],0,numEmp-1);
        cout<<i+1<<' '<<ibd[i]<<' ';
        if(ibd[i]>ibm){
            cout<<"Vende  ";
            vende=true;
        }
        else{
            cout<<"Compra ";
            vende=false;
        }
        pos=busquedaBinaria(valores[i],0,numEmp-1,vende,ibd[i]);
        monto=obtenerMonto(valores[i],pos,numEmp,vende);
        cout<<setw(4)<<monto<<' ';
        imprimirEmpresas(letras[i],pos,numEmp,vende);
    }
    return 0;
}

