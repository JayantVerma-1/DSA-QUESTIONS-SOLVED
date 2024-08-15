//BASICS OF RECURSION.
//FACTORIAL OF A NUMBER UDING RECURSION.
//RECURSION HAS THREE MAIN COMPONENTS , 1. BASE CASE , 2. RECURSIVE RELATION , 3. PROCESSING 
#include<iostream>
using namespace std;

int factorial(int n){
    //PROCESSING 
    cout << "function is called for n : " << n << endl;
    // BASE CASE : THIS TELLS CODE WHEN TO STOP
    if (n==1)
    return 1;
    //RECURSIVE RELATION
    int ans = n * factorial(n-1);
    return ans;
}

int main(){
    int n;
    cout<<" enter the value of n " << endl;
    cin >> n;
    
    int ans = factorial(n);
    cout << " ans is " << ans << endl;

}