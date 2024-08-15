#include <iostream>
using namespace std;

int climbStairs(int n)
{
    // BASE CASE
    if (n == 0 || n == 1)
        return 1;
    // RECURSIVE RELATION
    int ans = climbStairs(n - 1) + climbStairs(n - 2);
    return ans;
}
int main()
{
    int n;    
    cout << "enter the value of N " << endl;
    cin >> n;

    int ans = climbStairs(n);
    cout << "Amnswer is : " << ans << endl;
}