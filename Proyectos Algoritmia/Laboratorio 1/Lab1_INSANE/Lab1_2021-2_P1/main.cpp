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
int main(int argc, char** argv) {
    
    int izqA[]={7,17,14,19},gainIzqA[]={10,10,10,5};
    int izqB[]={9,12,11,8},gainIzqB[]={15,10,10,10};
    int derA[]={8,6,10,12},gainDerA[]={10,20,10,5};
    int derB[]={18,7,15,11},gainDerB[]={10,10,5,10};
    int n=4,P=23;
    int cromo[n*4];
    int opciones=(int)pow(2,n*4);
    int sumaPesos,resto,cociente;
    int solus[opciones],numSolus=0;
    int sumaGains,maxGains=0,soluMaxGain;


    for(int i=1;i<opciones;i++){
        cargaBin(cromo,4*n,i);
        sumaGains=sumaPesos=0;
        for(int j=0;j<4*n;j++){
            if(cromo[j]){
                resto=j%n;
                cociente=j/n;
                if(cociente==0){ 
                    sumaPesos+=izqA[resto];
                    sumaGains+=gainIzqA[resto];
                }
                else if(cociente==1){ 
                    sumaPesos+=derA[resto];
                    sumaGains+=gainDerA[resto];
                }
                else if(cociente==2){ 
                    sumaPesos+=izqB[resto];
                    sumaGains+=gainIzqB[resto];
                }
                else {
                    sumaPesos+=derB[resto];
                    sumaGains+=gainDerB[resto];
                }
            }
        }
        if(sumaPesos<=P and maxGains<=sumaGains){
            soluMaxGain=i;
            maxGains=sumaGains;
            solus[numSolus]=i;
            numSolus++;
        }
    }
    cout<<"La mayor ganancia con peso maximo de "<<P<<" es:"<<endl;
    cout<<"Ganancia: "<<maxGains<<endl;
    cargaBin(cromo,4*n,soluMaxGain);
        cout<<"Resultado: ";
        for(int j=0;j<4*n;j++){
            if(cromo[j]){
                resto=j%n;
                cociente=j/n;
                if(cociente==0) cout<<izqA[resto];
                else if(cociente==1) cout<<derA[resto];
                else if(cociente==2) cout<<izqB[resto];
                else cout<<derB[resto];
                cout<<"kg     ";
            }
            
        }
        cout<<"Ubicaciones: ";
        for(int j=0;j<4*n;j++){
            if(cromo[j]){
                resto=j%n;
                cociente=j/n;
                if((cociente%2)==0) {
                    cout<<"I";
                    if(cociente==0) cout<<"A";
                    else cout<<"B";
                    cout<<resto+1<<" ";
                }
                else{
                    cout<<"D";
                    if(cociente==1) cout<<"A";
                    else cout<<"B";
                    cout<<resto+1<<" ";
                }
            }
        }
        cout<<endl;
    
//    for(int i=0;i<numSolus;i++){
//        cargaBin(cromo,4*n,solus[i]);
//        cout<<"Resultado "<<i+1<<" : ";
//        for(int j=0;j<4*n;j++){
//            if(cromo[j]){
//                resto=j%n;
//                cociente=j/n;
//                if(cociente==0) cout<<izqA[resto];
//                else if(cociente==1) cout<<derA[resto];
//                else if(cociente==2) cout<<izqB[resto];
//                else cout<<derB[resto];
//                cout<<"kg     ";
//            }
//            
//        }
//        cout<<"Ubicaciones: ";
//        for(int j=0;j<4*n;j++){
//            if(cromo[j]){
//                resto=j%n;
//                cociente=j/n;
//                if((cociente%2)==0) {
//                    cout<<"I";
//                    if(cociente==0) cout<<"A";
//                    else cout<<"B";
//                    cout<<resto+1<<" ";
//                }
//                else{
//                    cout<<"D";
//                    if(cociente==1) cout<<"A";
//                    else cout<<"B";
//                    cout<<resto+1<<" ";
//                }
//            }
//        }
//        cout<<endl;
//
//    }
    return 0;
}

