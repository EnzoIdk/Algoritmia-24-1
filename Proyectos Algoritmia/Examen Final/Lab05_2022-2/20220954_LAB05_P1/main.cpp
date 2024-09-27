/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Enzo
 * Problema con programación dinámica, no viene
 * (puro copy paste de la solu en el drive, 0 imaginación :c)
 * Created on 22 de junio de 2024, 07:24 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int maxPeso(int *arr,int n,int k){
    int i,j,temp;
    //bubble sort
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int dp[n];
    dp[0]=0;
    for(i=1;i<n;i++){
        dp[i]=dp[i-1];
        //los pavos deben tener una diferencia menor a k=5
        if(arr[i]-arr[i-1]<k){
            if(i>=2){
                dp[i]=max(dp[i],dp[i-2]+arr[i]+arr[i-1]);
            }
            else{
                dp[i]=max(dp[i],arr[i]+arr[i-1]);
            }
        }
    }
    return dp[n-1];
}

int main(int argc, char** argv) {
    int arr[10]={3,25,18,15,4,12,6};
    int n=7,k=5;
    cout<<maxPeso(arr,n,k);
    return 0;
}

