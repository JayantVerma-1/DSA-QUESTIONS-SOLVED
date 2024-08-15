#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // ASSUME TO CREATE ARRAYS FOR LEN1 , LEN2 LENGTH
    int *left = new int[len1];
    int *right = new int[len2];

    // COPY VALUES
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }
    // MERGE LOGIC
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }

        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // COPY LOGIC FOR LEFT ARRAY
    while (leftIndex < len1)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    // COPY LOGIC FOR RIGHT ARRAY
    while (rightIndex < len2)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    // TODO: delete left and right waala newly created array!
}

void mergeSort(int *arr, int s, int e)
{
    // BASE CASE
    //  if s == e , it means single element.
    //  if s > e , it means invalid array.......
    if (s >= e)
        return;

    int mid = (s + e) / 2;

    // LEFT PART SOLVE KARDO RECURSION BHAIYA
    mergeSort(arr, s, mid);

    // RIGHT PART SORT KARDO RECURSION BHAIYA
    mergeSort(arr, mid + 1, e);

    // NOW MERGE THE BOTH SORTED ARRAY IN ONE
    merge(arr, s, e);
}

int main()
{
    int arr[] = {4, 5, 13, 2, 12};
    int n = 5;

    int s = 0;
    int e = n - 1;
    // CALLING THE MERGE SORT FUNCTION
    mergeSort(arr, s, e);

    // PRINTING THE ARRAY
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}