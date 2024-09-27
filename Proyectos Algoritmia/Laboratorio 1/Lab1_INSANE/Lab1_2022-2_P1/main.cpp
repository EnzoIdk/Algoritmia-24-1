#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void cargaBin(int *cromo,int tam,int num){
    
    for(int i=0;i<tam;i++)
        cromo[i]=0;
    
    int resto;
    
    while(num>0){
        resto=num%2;
        num=num/2;
        cromo[tam-1]=resto;
        tam--;
    }
}
int main(int argc, char** argv) {
    
    int M=4;
    int P=19;
    int precioH[]={4,5,4,2,6,3,4,1};
    int cantRenov[]={3,2,1,1,3,3,2,4};
    int n=8;
    int cromo[n];
    int opciones=(int)pow(2,n);
    int sumaImporte,sumaCantH,sumaUnos,maxCant=0,opcion,montoTotal;
    for(int i=1;i<opciones;i++){
        cargaBin(cromo,n,i);
        sumaImporte=0;
        sumaCantH=0;
        sumaUnos=0;
        for(int j=0;j<n;j++ ){
            sumaImporte+=cromo[j]*precioH[j]*cantRenov[j];
            sumaCantH+=cromo[j]*cantRenov[j];
            sumaUnos+=cromo[j];
        }
        if(sumaImporte<=P and maxCant<sumaCantH and sumaUnos==M){
            maxCant=sumaCantH;
            opcion=i;
            montoTotal=sumaImporte;
        }
    }
    
    cargaBin(cromo,n,opcion);
    for(int i=0;i<n;i++){
        if(cromo[i]) cout<<i+1<<" ";
    }
    cout<<endl;
    cout<<"Monto total: "<<montoTotal<<endl;
    cout<<"Cantidad de herramientas: "<<maxCant<<endl;
    return 0;
}

