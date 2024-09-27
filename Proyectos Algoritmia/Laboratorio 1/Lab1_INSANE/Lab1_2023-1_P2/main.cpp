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
    
    int izquierda[]={100,90,95,85,105};
    int derecha[]={90,98,75,96,93};
    int n=5;
    int robots[]={77,82,81,90,92,75};
    int m=6;
    int cromo[n];
    int opciones=(int)pow(2,n);
    bool rompe;
    int solus[opciones],numSolus=0;
    for(int i=0;i<opciones;i++){
        cargaBin(cromo,n,i);
        rompe=false;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(cromo[j]==0){
                    if(robots[k]>izquierda[j]){
                        rompe=true;
                        break;
                    }
                }
                else{
                    if(robots[k]>derecha[j]){
                        rompe=true;
                        break;
                    }
                }
            }
            if(rompe)break;
        }
        if(!rompe){
            solus[numSolus]=i;
            numSolus++;
        }
    }
    
//    for(int i=0;i<numSolus;i++)
//        cout<<solus[i]<<endl;
    
    for(int i=0;i<numSolus;i++){
        cargaBin(cromo,n,solus[i]);
        cout<<"Solucion "<<i+1<<":"<<endl;
        for(int j=0;j<n;j++){
            cout<<"Nivel "<<j+1<<": ";
            if(cromo[j]==0) cout<<"Izquierda";
            else cout<<"Derecha";
            cout<<endl<<endl;
        }
    }
    
    return 0;
}

