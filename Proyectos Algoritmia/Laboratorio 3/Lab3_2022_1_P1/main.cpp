/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 29 de abril de 2024, 11:31 AM
 */

#include <iostream>

using namespace std;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int maxcentro(int *arr,int ini,int med,int fin,int &pos1,int &pos2){
    int izq=1,der=1; /*se igualan a 1 porque los elementos se cuentan a sí mismos*/
    if(arr[med]>arr[med+1]) return 1;
    for(int i=med;i>ini;i--){
        if(arr[i]>arr[i-1]){
            pos1=i-1;
            izq++;
        }
        else break; /*si el que viene es mayor, lo cortas*/
    }
    for(int i=med+1;i<fin;i++){
        if(arr[i+1]>arr[i]){
            pos2=i+1;
            der++;
        }
        else break;
    }
    return der+izq;
}

/*cuenta cuantos días seguidos hay incremento*/
int cuentaIncremento(int *arr,int ini,int fin,int &pos1,int &pos2){
    if(ini==fin) return 1;
    int med=(ini+fin)/2;
    /*navegadores, solo separan*/
    int izq=cuentaIncremento(arr,ini,med,pos1,pos2);
    int der=cuentaIncremento(arr,med+1,fin,pos1,pos2);
    /*esto hace todo*/
    int cen=maxcentro(arr,ini,med,fin,pos1,pos2);
    return max(max(izq,der),cen);
}

int main(int argc, char** argv) {
    int n=8,pos1,pos2;
    int arr[]={10,15,5,10,12,20,25,18};
    cout<<cuentaIncremento(arr,0,n-1,pos1,pos2)<<endl;
    cout<<"("<<pos1<<','<<pos2<<")"<<endl;
    for(int i=pos1;i<=pos2;i++) cout<<arr[i]<<' ';
    return 0;
}

