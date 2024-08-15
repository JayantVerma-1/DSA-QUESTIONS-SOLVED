#include<limits.h>
#include <iostream>
using namespace std;

void findMax(int arr[], int n, int i, int & maxi) // & denotes pass by reference as if we dont use this we will be doing pass by value which will return wrong value 
{
    // BASE CASE

    if (i >= n) 
    {
        return;
    }
    //CASE 1 HAME SOLVE KARNA HAI 
    //CURRENT ELEMENT KO CHECK KARO FOR MAX
    if (arr[i] > maxi)
    {
        maxi = arr[i];
    }

    // BAAKI RECURSION SAMBHAL LEGA
    findMax(arr, n, i + 1, maxi);
}

void findMini(int arr[], int n, int i, int &mini) // & denotes pass by reference as if we dont use this we will be doing pass by value which will return wrong value 
{
    // BASE CASE

    if (i >= n) 
    {
        return;
    }
    //CASE 1 HAME SOLVE KARNA HAI 
    //CURRENT ELEMENT KO CHECK KARO FOR MAX
    if (arr[i] < mini)
    {
        mini = arr[i];
    }

    // BAAKI RECURSION SAMBHAL LEGA
    findMini(arr, n, i + 1, mini);
}

int main()
{

    int arr[] = { 10,
                  30,
                  21,
                  44,
                  32,
                  17,
                  19,
                  66 };

    int n = 8;
    int maxi = INT_MIN;
    int mini = INT_MAX;

    int i = 0;
    findMax(arr, n, i, maxi);
    findMini(arr, n, i, mini);
    cout << "maximum number : " << maxi << endl;
    cout << "minimum of the all is : " << mini << endl;
    return 0;
}