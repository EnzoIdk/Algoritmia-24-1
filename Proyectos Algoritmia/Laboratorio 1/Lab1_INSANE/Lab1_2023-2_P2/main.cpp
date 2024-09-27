#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
#define MAXCOL 3
#define MAXFIL 8

void cargaBin(int num,int*cromo,int tam){
    
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
bool noCumpleReq(int*cromo,int requisitos[]){
    
    for(int i=0;i<3;i++){
        if(requisitos[i]>0){
            if(cromo[requisitos[i]-1]==0)return true;
        }
    }
    return false;
}
int main(int argc, char** argv) {
    
    int inversion[]={32000,8000,40000,40000,20000,4000,16000,16000};
    int beneficio[]={60000,32000,120000,60000,32000,20000,48000,60000};
    int requisitos[][MAXCOL]={{0,0,0},
                              {0,0,0},  
                              {1,2,0},  
                              {0,0,0},  
                              {0,0,0},  
                              {2,0,0},  
                              {6,0,0},  
                              {6,0,0}};
    int N=8;
    int P=100000;
    int cromo[N];
    int opciones=(int)pow(2,N);
    int sumaInversion,sumaBeneficio,maxBene=0,opcion;
    bool noCumple;
    for(int i=1;i<opciones;i++){
        cargaBin(i,cromo,N);
        sumaInversion=0;
        sumaBeneficio=0;
        noCumple=false;
        for(int j=0;j<N;j++){
            sumaBeneficio+=cromo[j]*beneficio[j];
            sumaInversion+=cromo[j]*inversion[j];
        }
        for(int j=0;j<N;j++){
            if(cromo[j]){
                if(noCumpleReq(cromo,requisitos[j])){
                    noCumple=true;
                    break;
                }
            }
        }
        if(sumaInversion==P and sumaBeneficio>maxBene and !noCumple){
            maxBene=sumaBeneficio;
            opcion=i;
        }
    }
    
    cargaBin(opcion,cromo,N);
    cout<<"El maximo beneficio es: "<<maxBene<<endl;
    cout<<"Con una inversion de: "<<P<<endl;
    cout<<"Los controles fueron: "<<endl;
    for(int i=0;i<N;i++){
        if(cromo[i])
            cout<<i+1<<" ";
    }
    cout<<endl;

    return 0;
}

