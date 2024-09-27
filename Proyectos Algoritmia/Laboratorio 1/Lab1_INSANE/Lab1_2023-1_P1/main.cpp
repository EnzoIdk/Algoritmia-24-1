#include <iostream>
#include <cmath>
using namespace std;
void inicializarOs(int*cromo,int tam){
    for(int i=0;i<tam;i++){
        cromo[i]=0;
    }
}
void cargaBin(int num,int*cromo,int tam,int base){
    
    inicializarOs(cromo,tam);
    int resto;
    
    while(num>0){
        resto=num%base;
        num=num/base;
        cromo[tam-1]=resto;
        tam--;
    }
}

bool llenaTodoPaq(int* cromo,int tam){
    for(int i=0;i<tam;i++){
        if(cromo[i]==0) return false;
    }
    return true;
}
bool respetCap(int*dif,int tam){
    
    for(int i=0;i<tam;i++){
        if(dif[i]<0) return false;
    }
    return true;
}

int calMaxMin(int*dif,int tam,bool pide,int &pos){
    
    int maxi=0,mini,posMax,posMini;
    bool banderita=true;
    for(int i=0;i<tam;i++){
        if(maxi<dif[i]){
            maxi=dif[i];
            posMax=i;
        }
        if(banderita or mini>dif[i]){
            mini=dif[i];
            posMini=i;
            banderita=false;
        }
    }
    
    if(pide){
        pos=posMax;
        return maxi;
    }
    else{
        pos=posMini;
        return mini;
    }
}
int main(int argc, char** argv) {
    
    int M=4,N=5;
    int paq[N]={50,20,30,50,20};
    int cap[M]={25,50,100,100};
    int dif[M];
    int carga[M];
    int opcion=(int)pow(M+1,N);
    int cromo[N],maxDif,minDif;
    bool mini=false,maxi=true;
    int solPar[opcion],numSol=0;
    int opciones[opcion];
    int solOptima,pos;
    
//    cout<<"Ingrese la cantidad de camiones: ";
//    cin>>M;
//    cout<<"Ingrese la cantidad de paquetes: ";
//    cin>>N;
//    cout<<"Ahora ingrese los pesos de los paquetes respectivamente: ";
//    for(int i=0;i<N;i++){
//        cin>>paq[i];
//    }
//    cout<<"Ahora ingrese las capacidades de los camiones respectivamente: ";
//    for(int i=0;i<M;i++){
//        cin>>cap[i];
//    }
    
    for(int i=1;i<opcion;i++){
        cargaBin(i,cromo,N,M+1);
        inicializarOs(carga,M);
        inicializarOs(dif,M);
        if(llenaTodoPaq(cromo,N)){
            for(int j=0;j<N;j++){
                carga[cromo[j]-1]+=paq[j];
            }
            for(int k=0;k<M;k++){
                dif[k]=cap[k]-carga[k];
            }
            //Para la preg C en la condicional hago una disyuncion entre la 
            //funcion respetCap(dif,M) que verifica que se respeten las 
            //capacidades de los camiones y la funcion
            //llenaTodoPaq(carga,M) que verifica que todos los camiones
            //esten cargados
            if(respetCap(dif,M) and llenaTodoPaq(carga,M)){
                maxDif=calMaxMin(dif,M,maxi,pos);
                minDif=calMaxMin(dif,M,mini,pos);
                solPar[numSol]=maxDif-minDif;
                opciones[numSol]=i;
                numSol++;
            }
        }
    }
    solOptima=calMaxMin(solPar,numSol,mini,pos);
    cargaBin(opciones[pos],cromo,N,M+1);
    for(int i=0;i<N;i++){
        cout<<"Paquete "<<i+1<<": Camion "<<cromo[i]<<endl;
    }
    cout<<"Diferencia maxima: "<<solOptima<<endl;
    return 0;
}

