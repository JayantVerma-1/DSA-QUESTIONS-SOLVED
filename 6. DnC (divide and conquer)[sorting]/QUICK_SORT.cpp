#include<iostream>
using namespace std;

int partition(int arr[] , int s, int e){
    //STEP 1 : CHOOSE PIVOT ELEMENT 
    int pivotIndex = s;
    int pivotElement = arr[s];

    //STEP 2 : FIND RIGHT POSITION FOR PIVOT ELEMENT AND PLACE IT THERE.
    int count = 0;
    for(int i = s+1 ; i<=e ;i++){
        if(arr[i] <= pivotElement){
            count++;
        }
    }

    //jab mai loop se bahar hua to mere paas pivot ki right position ka index ready hai 
    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    //STEP 3 : LEFT ME SAB CHOTE AUR RIGHT ME SAB BADE 
    int i = s;
    int j = e;
    while (i<pivotIndex && j>pivotIndex)
    {
        while (arr[i]<= pivotElement)
        {
            i++;
        }
        while (arr[j] > pivotElement)
        {
            j--;
        }
        //2 CASE HO SAKTE HAI 
        // first case : you found the elements to swap 
        //second case : you need to swap 
        if (i<pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
        
        return pivotIndex;

    }
    

}

void quickSort(int arr[], int s, int e){
    //BASE CASE
    if(s >= e)
    return;

    //PARTITION LOGIC to return pivot element index
    int p = partition(arr, s, e);

    //RECURSIVE CALLS
    
    //pivot --> LEFT
    quickSort(arr, s, p-1);

    //pivot element --> RIGHT
    quickSort(arr, p+1, e);

}

int main(){
    int arr[] = {8,1,3,4,20,50,30};
    int n = 7;
    
    int s = 0;
    int e = n-1;
    quickSort(arr, s, e);

    for(int i = 0; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}