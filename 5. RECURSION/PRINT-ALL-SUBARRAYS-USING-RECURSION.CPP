#include <iostream>
#include <vector>
using namespace std;
// TIME COMPLEX : O{n*n}
// SPACE COMPLE : O{n+2} = O{n}

void printSubarray_util(vector<int> &nums, int start, int end)
{
    // BASE CASE
    if (end == nums.size())
    {
        return;
    }

    // 1 CASE SOL
    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    // RE
    printSubarray_util(nums, start, end + 1);
}
void printSubarray(vector<int> &nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        int end = start;
        printSubarray_util(nums, start, end);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    printSubarray(nums);
    return 0;
}
