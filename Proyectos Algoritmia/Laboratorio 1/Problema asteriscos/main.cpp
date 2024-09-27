/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 *
 * Created on 29 de marzo de 2024, 09:47 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;


/* patron (8,0)
 
 *                          1* desde columna 0
 * *                        2* desde columna 0
   *                            1* desde columna 1
 * * * *                    4* desde columna 0
     *                          1* desde columna 2
     * *                        2* desde columna 2
       *                        1* desde columna 3
 * * * * * * * *            8* desde columna 0
         *                          1* desde columna 4
         * *                        2* desde columna 4
           *                        1* desde columna 5
         * * * *            4* desde columna 4
             *                  1* desde columna 6
             * *                2* desde columna 6
               *                1* desde columna 7
 * 
 * | patron(8,0) n=8, i=0;
 * | | patron(4,0) n=4, i=0;
 * | | | patron(2,0) n=2, i=0;
 * | | | | patron(1,0);
 * | | | | *
 * | | |   * *
 * | | | | patron(1,1);
 * | | | |   *
 * | |     * * * *
 * | | | patron(2,2)
 * | | | | patron(1,2)
 * | | | |     *
 * | | |       * *
 * | | | | patron(1,3)
 * | | | |       *
 * |       * * * * * * * *
 * | | patron(4,4);
 * | | | patron(2,4);
 * | | | | patron(1,4);
 * | | | |         * 
 * | | |           * *
 * | | | | patron(1,5);
 * | | | |           *
 * | |             * * * *            
 * | | | |           
 * 
 * n es potencia de 2;
 * La linea más larga contiene n asteriscos y empieza desde la columna i;
 * Se puede hacer con 2 recursiones
 * 
 */
void patron(int n,int i){
    if(n==0) return;    /*condición de parada*/
    patron(n/2,i);      /*1ra recursión*/
    for(int esp=i;esp>0;esp--) cout<<"   ";
    for(int j=0;j<n;j++) cout<<" * ";
    cout<<endl;
    patron(n/2,n/2+i);      /*2da recursión*/
}

int main(int argc, char** argv) {
    
    int n=8,i=0;
    patron(n,i);
    
    return 0;
}

