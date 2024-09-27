#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

void cargaBin(int*cromo,int num,int tam){
    
    for(int i=0;i<tam;i++){
        cromo[i]=0;
    }
    
    int resto;
    
    while(num>0){
        resto=num%2;
        num=num/2;
        cromo[tam-1]=resto;
        tam--;
    }
}
int main(int argc, char** argv) {

    int n=4,P=100;
    int pesos[]={20,20,20,20,
                 10,30,10,30,
                 10,10,10,10,
                 15,15,15,15}; 
    int valores[]={10,10,10,50,
                   80,10,10,20,
                   20,20,20,20,
                   50,50,50,50};
    
    int totalDatos=pow(n,2);
    int opciones=(int)pow(2,totalDatos);
    int cromo[totalDatos];
    int sumaPesos,sumaValores,valorMax=0,opcion;
    
    for(int i=0;i<opciones;i++){
        cargaBin(cromo,i,totalDatos);
        sumaPesos=0;
        sumaValores=0;
        for(int j=0;j<totalDatos;j++){
            sumaPesos+=cromo[j]*pesos[j];
            sumaValores+=cromo[j]*valores[j];
        }
        if(sumaPesos<=P and valorMax<=sumaValores){
            valorMax=sumaValores;
            opcion=i;
        }
    }
    
    cout<<"Valor Máximo: "<<valorMax<<" (en miles de $)"<<endl;
    cargaBin(cromo,opcion,totalDatos);
            
    for(int i=0;i<totalDatos;i++){
        cout<<setw(2)<<cromo[i]*pesos[i]<<" ";
        if((i+1)%4==0) cout<<endl;    
    }
    cout<<endl;
    for(int i=0;i<totalDatos;i++){
        cout<<setw(2)<<cromo[i]*valores[i]<<" ";
        if((i+1)%4==0) cout<<endl;    
    }
    
    return 0;
}

