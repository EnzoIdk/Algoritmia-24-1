#include <iostream>

using namespace std;

/*DIVIDE Y VENCERÁS*/
//Divide un problema en instancias más pequeñas
//Resolver cada instancia de manera independiente
//Combinar las soluciones para solucionar problema original.
//Reserva pedidos: P1 Lab2

void buscaSolo(int *arr,int ini,int fin){
    if(ini>fin) return;
    if(ini==fin) {
        cout<<"El numero sin pareja es el "<<arr[ini]<<endl;
        return;
    }
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

int buscaMax(int *arr,int ini,int fin){
    int med=(ini+fin)/2;
    if(ini>=fin) return arr[ini]; /*se tiene que considerar el caso que haya un solo elemento*/
    if(arr[med]>arr[med+1])
        return buscaMax(arr,ini,med);
    else
        return buscaMax(arr,med+1,fin);
}

int cuentaCeros(int *arr,int ini,int fin,int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==0)
        return cuentaCeros(arr,med+1,fin,med+1);
    else
        return cuentaCeros(arr,ini,med-1,cont);
}

int cuentaUnos(int *arr,int ini,int fin,int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==0)
        return cuentaUnos(arr,med+1,fin,cont);
    else
        return cuentaUnos(arr,ini,med-1,cont+fin+1-med);
    
}

int busBinaria(int *arr,int ini,int fin,int dato){
    if(ini>fin) return -1;
    int pos=(ini+fin)/2;
    if(arr[pos]==dato) return pos;
    else if(arr[pos]>dato) return busBinaria(arr,ini,pos-1,dato);
    else return busBinaria(arr,pos+1,fin,dato);
}

int main(int argc, char** argv) {
    int arreglo[]={4,6,8,9,10,14,16,19};
    int arreglo2[]={0,0,1,1,1,1,1};
    int arreglo3[]={2,4,15,14,13,12,10,8};
    int arreglo4[]={3,3,4,5,5,6,6,7,7};
    int n1=8,n2=7,n3=8,n4=9;
    cout<<"El numero 14 esta en la posicion "<<busBinaria(arreglo,0,n1-1,14)<<endl;
    cout<<cuentaCeros(arreglo2,0,n2-1,0)<<" ceros"<<endl;
    cout<<cuentaUnos(arreglo2,0,n2-1,0)<<" unos"<<endl;
    cout<<buscaMax(arreglo3,0,n3-1)<<endl;
    /*SIEMPRE buscar el desfase*/
    buscaSolo(arreglo4,0,n4-1); /*cuál está sin pareja*/
    
    return 0;
}

