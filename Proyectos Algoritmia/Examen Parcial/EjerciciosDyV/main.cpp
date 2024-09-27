/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 17 de mayo de 2024, 11:39 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>  
#include <climits>

using namespace std;

int cuentaCeros(int *arr,int ini,int fin,int cont){
    if(ini>=fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==0) cuentaCeros(arr,ini,med,cont+fin-med+1);
    else cuentaCeros(arr,med+1,fin,cont);
}

int cuentaUnos(int *arr,int ini,int fin,int cont){
    if(ini>=fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==1) cuentaUnos(arr,med+1,fin,med+1);
    else cuentaUnos(arr,ini,med,cont);
}

void merge(int *arr,int ini,int med,int fin){
    int tamIzq=med-ini+1,tamDer=fin-med;
    int arrIzq[tamIzq+1]{},arrDer[tamDer+1]{};
    for(int i=ini;i<=med;i++) arrIzq[i-ini]=arr[i];
    for(int i=med+1;i<=fin;i++) arrDer[i-med-1]=arr[i];
    arrDer[tamDer]=arrIzq[tamIzq]=INT_MAX;
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        if(arrIzq[p]<arrDer[q]){
            arr[i]=arrIzq[p];
            p++;
        }
        else{
            arr[i]=arrDer[q];
            q++;
        }
    }
}

void mergeSort(int *arr,int ini,int fin){
    if(ini==fin) return;
    int med=(ini+fin)/2;
    mergeSort(arr,ini,med);
    mergeSort(arr,med+1,fin);
    merge(arr,ini,med,fin);
}

int busquedaBinaria(int *arr,int ini,int fin,int dato){
    if(ini>fin) return -1;
    int med=(ini+fin)/2;
    if(arr[med]==dato) return med;
    else if(arr[med]>dato) busquedaBinaria(arr,ini,med,dato);
    else busquedaBinaria(arr,med+1,fin,dato);
}

int buscaPico(int *arr,int ini,int fin){
    if(ini>=fin) return arr[ini];
    int med=(ini+fin)/2;
    if(arr[med]<arr[med+1]) buscaPico(arr,med+1,fin);
    else buscaPico(arr,ini,med);
}

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int sumaCentro(int *arr,int ini,int med,int fin){
    int sumMaxIzq=-999,sumMaxDer=-999,sumTotal;
    int sumIzq=0,sumDer=0;
    for(int i=med;i>=ini;i--){
        sumIzq+=arr[i];
        if(sumIzq>sumMaxIzq) sumMaxIzq=sumIzq;
    }
    for(int i=med+1;i<=fin;i++){
        sumDer+=arr[i];
        if(sumDer>sumMaxDer) sumMaxDer=sumDer;
    }
    sumTotal=sumMaxDer+sumMaxIzq;
    return max(sumTotal,max(sumMaxDer,sumMaxIzq));
}

int sumaMax(int *arr,int ini,int fin){
    if(ini==fin) return arr[ini];
    int med=(ini+fin)/2;
    int izq=sumaMax(arr,ini,med);
    int der=sumaMax(arr,med+1,fin);
    int cen=sumaCentro(arr,ini,med,fin);
    return max(cen,max(izq,der));
}

int datoMin(int *arr,int ini,int fin){
    if(ini==fin) return arr[fin];
    int med=(ini+fin)/2;
    if(arr[med]>arr[med+1]) return arr[med+1];
    if(arr[med]>=arr[fin]) return datoMin(arr,med+1,fin);
    return datoMin(arr,ini,med);
}

int buscaSolo(int *arr,int ini,int fin){
    if(ini==fin) return arr[ini];
    int med=(ini+fin)/2;
    if(med%2==0){
        if(arr[med]==arr[med+1]) buscaSolo(arr,med+2,fin);
        else buscaSolo(arr,ini,med);
    }
    else{
        if(arr[med]==arr[med-1]) buscaSolo(arr,med+1,fin);
        else buscaSolo(arr,ini,med-1);
    }
}

int cuentaCentro(int *arr,int ini,int med,int fin){
    int izq=0,der=0;
    if(arr[med]>arr[med+1]) return 1;
    for(int i=med;i>ini;i--){
        if(arr[i]>arr[i-1]) izq++;
        else break;
    }
    for(int i=med+1;i<fin;i--){
        if(arr[i]<arr[i+1]) der++;
        else break;
    }
    return izq+der;
}

int cuentaIncrementos(int *arr,int ini,int fin){
    if(ini==fin) return 1;
    int med=(ini+fin)/2;
    int izq=cuentaIncrementos(arr,ini,med);
    int der=cuentaIncrementos(arr,med+1,fin);
    int cen=cuentaCentro(arr,ini,med,fin);
    return max(cen,max(izq,der));
}

int cuentaSegCentro(int *arr,int ini,int med,int fin,int valor){
    int izq=0,der=0;
    if(arr[med]!=arr[med+1]) return 0;
    for(int i=med;i>=ini;i--){
        if(arr[i]==valor) izq++;
        else break;
    }
    for(int i=med+1;i<=fin;i++){
        if(arr[i]==valor) der++;
        else break;
    }
    return izq+der;
}

int cuentaSeguidas(int *arr,int ini,int fin,int valor){
    if(ini==fin){
        if(arr[ini]==valor) return 1;
        else return 0;
    }
    int med=(ini+fin)/2;
    int izq=cuentaSeguidas(arr,ini,med,valor);
    int der=cuentaSeguidas(arr,med+1,fin,valor);
    int cen=cuentaSegCentro(arr,ini,med,fin,valor);
    return max(cen,max(izq,der));
}

/*(0,0,0,0,1,1)*/
int cuentaCerosAsc(int *arr,int ini,int fin,int cont){
    if(ini>=fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==0) cuentaCerosAsc(arr,med+1,fin,med+1);
    else cuentaCerosAsc(arr,ini,med,cont);
}

int cuentaUnosAsc(int *arr,int ini,int fin,int cont){
    if(ini>=fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==1) cuentaUnosAsc(arr,ini,med,cont+fin-med+1);
    else cuentaUnosAsc(arr,med+1,fin,cont);
}

int cantInversionesCentro(int *arr,int ini,int med,int fin){
    int cant=0;
    int indIzq=ini,indDer=med+1;
    while(indDer<=fin){
        indIzq=ini;
        while(indIzq<=med){
            if(arr[indIzq]>arr[indDer]) cant++;
            indIzq++;
        }
        indDer++;
    }
    return cant;
}

int cantInversiones(int *arr,int ini,int fin){
    int cantidad=0;
    if(ini>=fin) return cantidad;
    int med=(ini+fin)/2;
    cantidad+=cantInversiones(arr,ini,med);
    cantidad+=cantInversiones(arr,med+1,fin);
    cantidad+=cantInversionesCentro(arr,ini,med,fin);
    return cantidad;
}

int main(int argc, char** argv) {
    int arreglo[7]={1,1,0,0,0,0},n=6;
    for(int i=0;i<n;i++) cout<<arreglo[i]<<' ';
    cout<<endl<<"Cant 0: "<<cuentaCeros(arreglo,0,n-1,0)<<endl;
    cout<<"Cant 1: "<<cuentaUnos(arreglo,0,n-1,0)<<endl;
    mergeSort(arreglo,0,5);
    for(int i=0;i<n;i++) cout<<arreglo[i]<<' ';
    cout<<endl<<"Cant 0: "<<cuentaCerosAsc(arreglo,0,n-1,0)<<endl;
    cout<<"Cant 1: "<<cuentaUnosAsc(arreglo,0,n-1,0)<<endl;
    int arreglo2[5]={2,3,1,5,4};
    mergeSort(arreglo2,0,4);
    int dato=5;
    cout<<"Pos por busq binaria: "<<busquedaBinaria(arreglo2,0,4,dato)<<endl;
    int arreglo3[6]={1,2,4,7,3,2};
    cout<<"Pico: "<<buscaPico(arreglo3,0,5)<<endl;
    int arreglo4[8]={-2,-5,6,-2,-3,1,5,-6};
    cout<<"Mayor suma: "<<sumaMax(arreglo4,0,7)<<endl;
    int arreglo5[6]={5,6,7,8,3,4};
    cout<<"Minimo: "<<datoMin(arreglo5,0,5)<<endl;
    int arreglo6[11]={1,1,3,3,4,5,5,7,7,8,8};
    cout<<"Busca solo: "<<buscaSolo(arreglo6,0,10)<<endl;
    int incrementos[10]={1,2,3,2,5,6,3,4,5,6};
    cout<<"Mayor cant incrementos seguidos: "<<cuentaIncrementos(incrementos,0,9)<<endl;
    int seguidas[10]={1,1,2,2,2,3,2,3,3,2},valor=2;
    cout<<"Mayor cantidad de veces seguidas que aparece el "<<valor
            <<": "<<cuentaSeguidas(seguidas,0,9,valor)<<endl;
    int arreglo7[8]={2,1,4,3,5,8,9,4};
    cout<<cantInversiones(arreglo7,0,7)<<endl;
    return 0;
}
