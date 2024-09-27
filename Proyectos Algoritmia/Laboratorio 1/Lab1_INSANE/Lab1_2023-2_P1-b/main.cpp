#include <iostream>
#include <iomanip>

using namespace std;
#define MAXCOL 10
#define MAXFIL 4

int m[4][2];

void movements(){
    m[0][0]=-1;m[0][1]=0;
    m[1][0]=0;m[1][1]=1;
    m[2][0]=1;m[2][1]=0;
    m[3][0]=0;m[3][1]=-1;
}
bool buscaLetra(char board[][MAXCOL],int i,int j){
    if(board[i][j]!='H' and board[i][j]!='S' and board[i][j]!='O')return false;
    int nfil,ncol;
    bool h,s,o;
    for(int k=0;k<4;k++){
        nfil=i+m[k][0];
        ncol=j+m[k][1];
        h=false;
        s=false;
        o=false;
        if(board[i][j]=='H') h=true;
        if(board[i][j]=='S') s=true; 
        if(board[i][j]=='O') o=true;
        for(int p=0;p<2;p++){
            if(nfil<0 or ncol<0 or nfil>=MAXFIL or ncol>=MAXCOL)
                break;
            if(board[nfil][ncol]=='H') h=true;
            if(board[nfil][ncol]=='S') s=true; 
            if(board[nfil][ncol]=='O') o=true;
            
            nfil+=m[k][0];
            ncol+=m[k][1];
        }
        if(h and s and o)return true;
    }
    return false;
}
void pupiletras(char board[][MAXCOL],char*word,int n){
    bool cont=true;
    for(int i=0;i<MAXFIL;i++)
        for(int j=0;j<MAXCOL;j++){
            if(buscaLetra(board,i,j)){
                if(cont){ 
                    cout<<"Para estos datos el robot mostrará que el"<<endl;
                    cout<<"acido sulfurico se puede formar apartir de "<<endl;
                    cout<<"las siguientes posicioneS: "<<endl;
                    cont=false;
                }
                cout<<i<<','<<j<<"   ";
            }
        }
    cout<<endl;
}
int main(int argc, char** argv) {
    
    char word[]="HSO";
    int n=3;
    char board[][MAXCOL]={{'H','C','H','B','Y','S','O','S','O','H'},
                          {'S','C','S','S','Y','Q','O','S','Z','K'},
                          {'O','P','N','Y','O','K','F','H','C','K'},
                          {'O','B','N','I','Y','S','P','O','O','K'}};
    movements();
    
    pupiletras(board,word,n);

    return 0;
}

