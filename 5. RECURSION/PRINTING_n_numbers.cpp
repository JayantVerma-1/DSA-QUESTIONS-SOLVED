#include<iostream>
using namespace std;

void printCounting(int n){
    //BASE CASE
    if(n == 0){
        return;

    }
    //PROCESSING
    cout << n <<" " ;

    //RECCURSIVE RELATION
    printCounting(n-1);  
    
}

int main(){
   int n;
   cout << "enter the value of N " << endl;
   cin >> n;
   printCounting(n);

   return 0;

}