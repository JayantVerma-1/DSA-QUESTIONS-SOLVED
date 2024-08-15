#include<iostream>
using namespace std;

void printDIGITS(int n)
{
    //BASE CASE
    if(n==0){
        return;
    }
    //BAAKI RECURSION SAMBHAL LEGA
    printDIGITS (n/10);

    //EK CASE M SOLVE KARUGA
    int digit = n%10;
    cout << digit << " " ;

    
}
int main(){
    int n = 647; // NOTE : 0647 ke liye code work nhi kar raha 
    if(n == 0)
    cout<< 0 << endl;
    printDIGITS(n);
    return 0; 
}