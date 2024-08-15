#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> &arr, int &n, int i)
{
    // BASE CASE
    if (i == n - 1)
    {
        return true;
    }

    // 1 CASE HAME SOLVE KARNA HAI
    if (arr[i] > arr[i + 1])

        return false;

    // BAAKI RECURSION KHUD SAMBHAL LEGA
    return checkSorted(arr, n, i + 1);
}
int main()
{
    vector<int> v{10, 20, 40, 50,  50};
    int n = v.size();
    int i = 0;

    bool isSorted = checkSorted(v, n, i);

    if (isSorted)
    {
        cout << "ARRAY IS SORTED " << endl;
    }

    else
        cout << "ARRAY IS NOT SORTED " << endl;

    return 0;
}