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

bool confirmaCantUnos(int*cromo,int tam,int cantUnos){
    int cant=0;
    
    for(int i=0;i<tam;i++)
        if(cromo[i]) cant++;
    return cant==cantUnos;
}
int main(int argc, char** argv) {

    int C=20,N=4,M=5;
//    cout<<"Ingrese la cantidad de productos que tendra cada bahia: ";
//    cin>>N;
//    cout<<"Ingrese la carga maxima que un camion puede transportar: ";
//    cin>>C;
//    cout<<"Ingrese la cantidad de divisiones para transportar los productos: ";
//    cin>>M;
    
    int bahia1[]={2,5,6,10};
    int bahia2[]={7,8,15,3};
    int bahia3[]={11,9,6,4};
    int cromo[N*3];
    int opciones=pow(2,N*3);
    int sumaPesos,resto,cociente,opcion;
    bool haySol=false,B1=true,B2=true,B3=true;
    int solus[opciones],numSolus=0;
    
    for(int i=1;i<opciones;i++){
        cargaBin(cromo,N*3,i);
        sumaPesos=0;
        if(confirmaCantUnos(cromo,N*3,5)){
            for(int j=0;j<N*3;j++){
                if(cromo[j]){
                    resto=j%N;
                    cociente=j/N;
                    if(cociente==0) sumaPesos+=bahia1[resto];
                    else if(cociente==1) sumaPesos+=bahia2[resto];
                    else sumaPesos+=bahia3[resto];
                }
            }
            if(sumaPesos==C){
                solus[numSolus]=i;
                numSolus++;
                opcion=i;
                haySol=true;
                //break;
            }
        }
    }
    
    for(int j=0;j<numSolus;j++){
        
        B1=B2=B3=true;
        cargaBin(cromo,N*3,solus[j]);
        for(int i=0;i<N*3;i++){
            if(cromo[i]){
                resto=i%N;
                cociente=i/N;
                if(cociente==0){
                    if(B1){
                        cout<<"Bahia 1: ";
                        B1=false;
                    }
                    cout<<bahia1[resto]<<" ";
                }
                else if(cociente==1){
                    if(B2){
                        cout<<"Bahia 2: ";
                        B2=false;
                    }
                    cout<<bahia2[resto]<<" ";
                }
                else {
                    if(B3){
                        cout<<"Bahia 3: ";
                        B3=false;
                    }
                    cout<<bahia3[resto]<<" ";
                }
            }
        }
        cout<<endl;
    }
//    
//    if(haySol){
//        cargaBin(cromo,N*3,opcion);
//        for(int i=0;i<N*3;i++){
//            if(cromo[i]){
//                resto=i%N;
//                cociente=i/N;
//                if(cociente==0){
//                    if(B1){
//                        cout<<"Bahia 1: ";
//                        B1=false;
//                    }
//                    cout<<bahia1[resto]<<" ";
//                }
//                else if(cociente==1){
//                    if(B2){
//                        cout<<"Bahia 2: ";
//                        B2=false;
//                    }
//                    cout<<bahia2[resto]<<" ";
//                }
//                else {
//                    if(B3){
//                        cout<<"Bahia 3: ";
//                        B3=false;
//                    }
//                    cout<<bahia3[resto]<<" ";
//                }
//            }
//        }
//        cout<<endl;
//    }
//    
    return 0;
}

