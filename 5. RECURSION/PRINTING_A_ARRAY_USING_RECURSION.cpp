#include<iostream>
using namespace std;

void printArray(int arr[], int n, int i){
    //BASE CASE
    if (i>=n){
        return;
    }
    //PROCESSING
    cout << arr[i] ; // --> (1CASE TUM SOLVE KARDO)

    //RECURSIVE RELATION 
    printArray(arr, n, i+1); // --> (BAAKI RECURSION SAMBHAL LEGA)
}

int main(){
    int arr[5] = {2,3,4,5,6};  
    int n = 5;
    int i = 0;
    printArray(arr, n, i);
    return 0;
}