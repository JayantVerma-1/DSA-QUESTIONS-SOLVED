#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> arr, int s, int e, int key)
{
    // BASE CASE
    //  CASE 1 --> KEY NOT FOUND
    //  s > e means invalid array
    if (s > e)
        return -1;

    int mid = (s + e) / 2;
    // CASE 2 --> KEY FOUND
    //  EK CASE HAM KARDEGE
    if (arr[mid] == key)
        return mid;

    // BAAKI RECURSION  KHUD SAMBHAL LEGA
    // line 21 - 30 ki jagah ham ternary operator ka bhi use karsakte hai code ko chota karne ke liye
    // ternary operator --> return (arr[mid] < key) ? binarySearch(arr, mid + 1, e, key) : binarySearch(arr, s, mid - 1, key);
    if (arr[mid] < key)
    {
        int ans = binarySearch(arr, mid + 1, e, key);
        return ans; //or can use return binarySearch(arr, mid + 1, e, key);
    }
    else
    {
        int ans = binarySearch(arr, s, mid - 1, key);
        return ans; //or can use return binarySearch(arr, s, mid - 1, key);
    }
}

int main()
{

    vector<int> v{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 90;
    int n = v.size();
    int s = 0;
    int e = n - 1;
    int ans = binarySearch(v, s, e, target);
    cout << "Ans is : " << ans << endl;
    return 0;
}