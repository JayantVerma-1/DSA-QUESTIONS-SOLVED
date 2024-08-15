
//LEETCODE - 526

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void countArrangementHelper(vector<int> &v, int &n, int &ans, int carrNum)
    {
        // BASE CASE
        if (carrNum == n + 1)
        {
            ans++;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 0 && (carrNum % i == 0 || i % carrNum == 0))
            {
                v[i] = carrNum;
                countArrangementHelper(v, n, ans, carrNum + 1);
                v[i] = 0;
            }
        }
    }

    int countArrangement(int n)
    {
        vector<int> v(n + 1);
        int ans = 0;
        countArrangementHelper(v, n, ans, 1);
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    int result = sol.countArrangement(n);
    cout << "Number of beautiful arrangements for n = " << n << ": " << result << endl;
    return 0;
}
