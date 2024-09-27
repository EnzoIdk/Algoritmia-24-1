#include <iostream>

using namespace std;

void MostrarMatriz(int matriz[][25], int filas, int columnas) {
	cout<<"Matriz:"<<endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
        	if (matriz[i][j]<0)
        		if (matriz[i][j]<10)
        			cout<<"";
        		else
        			cout<<" ";
        	else
        		if (matriz[i][j]<10)
        			cout <<" "; 
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void MostrarArreglo(int arreglo[], int longitud_arreglo) {
	cout<<"Arreglo:"<<endl;
    for (int i = 0; i < longitud_arreglo; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void PasaMatrizArreglo(int matriz[25][25], int arreglo[], int filas, int columnas){
    int i,j;
	int a=0;
    
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            arreglo[a]=matriz[i][j];
            a++;
        }
    }
}

void PasaArregloMatriz(int arreglo[], int matriz[25][25], int filas, int columnas){
    int i,j;
    int a=0;

    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            matriz[i][j]=arreglo[a];
            a++;
        }
    }
}

void merge(int arreglo1[], int arreglo2[], int posicion_inicial, int posicion_medio, int posicion_final){
	int i, p, q; //índices para los 3 arreglos
	//i es para arreglo[]
	//p es para arreglo[], mitad de la izquierda
	//q es para arreglo[], mitad de la derecha
	
	int longitud1, longitud2;
	longitud1=(posicion_medio+1)-posicion_inicial;
	longitud2=posicion_final-posicion_medio;
	
	//establecemos 2 arreglos auxiliares para reordenar el arreglo[]
	int P1[longitud1+1], P2[longitud1+1];//Un elemento más en el subarreglo con valor muuuuuy grande
	int Q1[longitud2+1], Q2[longitud2+1];//Un elemento más en el subarreglo con valor muuuuuy grande
	
	P1[longitud1]=999999;
	Q1[longitud2]=999999;
	
	for (i=posicion_inicial;i<posicion_medio+1;i++){
		P1[i-posicion_inicial]=arreglo1[i];//restamos posicion_inicial al índice para que comience desde 0 para P[]
		P2[i-posicion_inicial]=arreglo2[i];//restamos posicion_inicial al índice para que comience desde 0 para P[]
	}
	
		
	for (i=posicion_medio+1;i<=posicion_final;i++){
		Q1[i-(posicion_medio+1)]=arreglo1[i];//restamos posicion_medio+1 al índice para que comience desde 0 para Q[]
		Q2[i-(posicion_medio+1)]=arreglo2[i];//restamos posicion_medio+1 al índice para que comience desde 0 para Q[]
	}
		
	p=q=0;
	
	for (i=posicion_inicial; i<=posicion_final; i++)
		if (P1[p]<Q1[q]){//Si el elemento de P[] es el menor, insertamos en arreglo[]
			arreglo1[i]=P1[p];
			arreglo2[i]=P2[p];
			p++;
		}
		else{//Si el elemento de Q[] es el menor, insertamos en arreglo[]
			arreglo1[i]=Q1[q];
			arreglo2[i]=Q2[q];
			q++;
		}
}

void mergesort(int arreglo1[], int arreglo2[], int posicion_inicial, int posicion_final){
	//CASO BASE
	if (posicion_inicial==posicion_final)//porque cuando tenemos sólo un elemento, ese elemento ya está ordenado.
		return;
	
	//identificamos la posición del medio
	int posicion_medio=(posicion_inicial+posicion_final)/2;
	
	mergesort(arreglo1, arreglo2, posicion_inicial, posicion_medio);//la mitad del arreglo de la IZQUIERDA
	mergesort(arreglo1, arreglo2, posicion_medio+1, posicion_final);//la mitad del arreglo de la DERECHA
	//hasta aqui el arreglo viene "ordenado por partes", necesitamos ordenarlo POR COMPLETO
	
	merge(arreglo1, arreglo2, posicion_inicial, posicion_medio, posicion_final);//enviamos la posicion del medio pues es la que nos indica dónde están los 2 subarreglos ordenados por separado
}

int EncontrarEnMatriz(int ID[][25], int Instrucciones[][25], int registro, int fila_inicial, int fila_final, int columna_inicial,int columna_final){
	int fila_medio, columna_medio;
	
	int submatriz1, submatriz2, submatriz3, submatriz4, submatriz5, submatriz6;
	
	submatriz1=submatriz2=submatriz3=submatriz4=submatriz5=submatriz6=0;
	
	fila_medio=(fila_inicial+fila_final)/2;
	columna_medio=(columna_inicial+columna_final)/2;
	
	//CASO BASE: sólo queda un elemento en mi matriz (1x1)
	if (fila_inicial==fila_final && columna_inicial==columna_final)
		if (registro==ID[fila_inicial][columna_inicial])
			return Instrucciones[fila_inicial][columna_inicial];
		else
			return 0;
	
	//Caso: Cuando queda una columna 
	if (fila_inicial==fila_final){
		submatriz5=EncontrarEnMatriz(ID, Instrucciones, registro, fila_inicial, fila_final,columna_inicial,columna_medio);
		submatriz6=EncontrarEnMatriz(ID, Instrucciones, registro, fila_inicial, fila_final, columna_medio+1,columna_final);	
		return submatriz5+submatriz6;
	}
	//Caso: Cuando queda una fila
	if (columna_inicial==columna_final){
		submatriz5=EncontrarEnMatriz(ID, Instrucciones, registro, fila_inicial, fila_medio,columna_inicial,columna_final);
		submatriz6=EncontrarEnMatriz(ID, Instrucciones, registro, fila_medio+1, fila_final, columna_inicial,columna_final);	
		return submatriz5+submatriz6;
	}
	
	//luego los casos de las 4 submatrices habituales
	//Superior izquierda
	if (registro>=ID[fila_inicial][columna_inicial] && registro<=ID[fila_medio][columna_medio])
		submatriz1=EncontrarEnMatriz(ID, Instrucciones, registro, fila_inicial, fila_medio,columna_inicial,columna_medio);
	
	//inferior izquierda
	if (registro>=ID[fila_medio+1][columna_inicial] && registro<=ID[fila_final][columna_medio])
		submatriz2=EncontrarEnMatriz(ID, Instrucciones, registro, fila_medio+1, fila_final,columna_inicial,columna_medio);
		
	//superior derecha
	if (registro>=ID[fila_inicial][columna_medio+1] && registro<=ID[fila_medio][columna_final])
		submatriz3=EncontrarEnMatriz(ID, Instrucciones, registro, fila_inicial, fila_medio,columna_medio+1,columna_final);
	
	//inferior derecha
	if (registro>=ID[fila_medio+1][columna_medio+1] && registro<=ID[fila_final][columna_final])
		submatriz4=EncontrarEnMatriz(ID, Instrucciones, registro, fila_medio+1, fila_final,columna_medio+1,columna_final);
		
	return submatriz1+submatriz2+submatriz3+submatriz4;
}


int main() {
   int ID[25][25]={{-1, -2, -3, -4, -5, -6},
                     {-7, -8, 1, -9, 2, -10},
                     {-11, 1, 2, -12, -13, -14},
                     {-15, -16, -17, 1, -18, -19},
                     {-20, 1, 2, -21, -22, -23}};

	int Instrucciones[25][25]= {{10, 5, 8, 9, 8, 1},
                      {10, 5, 2, 8, 2, 3},
                      {4, 2, 1, 4, 8, 1},
                      {1, 2, 4, 3, 5, 3},
                      {8, 3, 3, 8, 5, 3}};
    
	int N=5,M=6;
	int registro,cantidad_instrucciones;
	
	int arreglo_ID[N*M], arreglo_Instrucciones[N*M];
  
  	MostrarMatriz(ID,N,M);
  	MostrarMatriz(Instrucciones,N,M);
	//Ordenamos las matrices
	//por condición del problema PUEDO utilizar arreglos para ordenar las matrices.
	//Pasamos las matrices a arreglos
	PasaMatrizArreglo(ID, arreglo_ID, N,M);
	PasaMatrizArreglo(Instrucciones, arreglo_Instrucciones, N,M);
  
	MostrarArreglo(arreglo_ID,N*M);
	MostrarArreglo(arreglo_Instrucciones,N*M);
	//ordenamos con mergesort() "modificado" porque tienen que ordenarse las 2 matrices en paralelo
	mergesort(arreglo_ID, arreglo_Instrucciones, 0, N*M-1);
	
	cout<<endl<<"Luego de ordenar - mergesort() "<<endl;
	MostrarArreglo(arreglo_ID,N*M);
	MostrarArreglo(arreglo_Instrucciones,N*M);
  
	//Una vez ordenado, pasamos nuevamente a matrices:
	//Enunciado: "Sólo puede usar arreglos unidimensionales para el ordenamiento de los datos de las matrices."
	PasaArregloMatriz(arreglo_ID, ID, N,M);
 	PasaArregloMatriz(arreglo_Instrucciones, Instrucciones, N,M);
  
	MostrarMatriz(ID,N,M);
  	MostrarMatriz(Instrucciones,N,M);
	//Ya ordenadas las matrices busco en la matriz de IDs los que tienen valores positivos (es decir son posibles virus)
	cout<<"Registro de virus a encontrar: ";
	cin>>registro;
	cantidad_instrucciones=EncontrarEnMatriz(ID, Instrucciones, registro, 0, N-1,0,M-1);//Función que dividirá la matriz en submatrices
	//descartará las submatrices que tengan puros IDs negativos,
	//sólo los positivos tienen posibles códigos maliciosos
	cout<<"Cantidad instrucciones= "<<cantidad_instrucciones<<endl;
	if (cantidad_instrucciones>=10)
		cout<<"El archivo tiene un posible código malicioso del virus con registro "<< registro<<endl;
	else
		cout<<"El archivo NO tiene un posible código malicioso del virus con registro "<< registro<<endl;
 
   return 0;
}
