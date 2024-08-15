#include <iostream>
#include <vector>

using namespace std;

long merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;
    long c = 0;
    
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++];
        else { // arr[i] > arr[j] i.e. inversion count case
            temp[k++] = arr[j++];
            c += (mid - i) + 1;
        }
    }
    
    while (i <= mid) 
        temp[k++] = arr[i++];
    while (j <= end) 
        temp[k++] = arr[j++];
    for (int i = start; i <= end; i++) 
        arr[i] = temp[i];
    
    return c;
}

long mergeSort(vector<int>& arr, vector<int>& temp, int start, int end) {
    if (start >= end)
        return 0;
    int mid = start + (end - start) / 2;
    long c = 0;
    c += mergeSort(arr, temp, start, mid);
    c += mergeSort(arr, temp, mid + 1, end);
    c += merge(arr, temp, start, mid, end);
    return c;
}

long countInversions(vector<int> arr) {
    long c = 0;
    vector<int> temp(arr.size(), 0);
    c = mergeSort(arr, temp, 0, arr.size() - 1);
    return c;
}

int main() {
    // Input array
    vector<int> arr = {4, 3, 2, 1};
    
    // Count inversions
    long inversions = countInversions(arr);
    
    // Output result
    cout << "Number of inversions: " << inversions << endl;
    
    return 0;
}
