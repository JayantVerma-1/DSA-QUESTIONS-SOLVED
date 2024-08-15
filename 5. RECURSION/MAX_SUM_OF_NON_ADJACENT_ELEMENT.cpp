#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int solve(vector<int> &arr, int i, int sum, int &maxi)
{
    // BASE CASE
    if (i >= arr.size())
    {

        // MAXI UPDATE;
        maxi = max(sum, maxi);
        return 0;
    }

    // INCLUDE
    solve(arr, i+2, sum+arr[i], maxi);

    // EXCLUDE
    solve(arr, i + 1, sum, maxi);

}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;

    solve(arr, i, sum, maxi);

    cout << maxi << endl;

    return 0;
}