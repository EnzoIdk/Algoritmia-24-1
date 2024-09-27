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
        num/=2;
        cromo[tam-1]=resto;
        tam--;
    }
}
bool confirmaCantUnos(int *cromo,int tam,int cantUnos){
    int cant=0;
    
    for(int i=0;i<tam;i++){
        if(cromo[i]) cant++;
    }
    return cant==cantUnos;
}
int main(int argc, char** argv) {

    char letra[]={'G','O','L','A','R','L','A','O','G','H'};
    int n=10;
    char myWord[]="HOLA";
    int cromo[n],m=4;
    int opciones=(int)pow(2,n),posSol;
    int solus[opciones],numSolus=0;
    
    for(int i=0;i<opciones;i++){
        cargaBin(cromo,n,i);
        if(confirmaCantUnos(cromo,n,m)){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(cromo[k]){
                        if(letra[k]==myWord[j]){
                            cromo[k]=0;
                            break;
                        }
                    }
                }
            }
            if(confirmaCantUnos(cromo,n,0)){
                //posSol=i;
                //break;
                solus[numSolus]=i;
                numSolus++;
            }
        }
    }
//    cargaBin(cromo,n,posSol);
//    cout<<"Una posible solucion es: ";
//    for(int i=0;i<n;i++){
//        if(cromo[i])
//            cout<<i+1<<" ";
//    }
//    cout<<endl;
    
    cout<<"Las soluciones son: "<<endl;
    for(int i=0;i<numSolus;i++){
        cargaBin(cromo,n,solus[i]);
        for(int j=0;j<n;j++){
            if(cromo[j])
                cout<<j+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}

