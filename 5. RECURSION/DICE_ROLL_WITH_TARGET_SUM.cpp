#include <iostream>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // BASE CASE
        if(target < 0) return 0;
        if(n == 0 && target != 0) return 0;
        if(n != 0 && target == 0) return 0;
        if(n == 0 && target == 0) return 1;
        
        int ans = 0;
        for(int i = 1; i <= k; i++) {
            ans = (ans + numRollsToTarget(n - 1, k, target - i)) % ((int)1e9 + 7);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n, k, target;
    cout << "Enter the number of dice: ";
    cin >> n;
    cout << "Enter the number of faces on each die: ";
    cin >> k;
    cout << "Enter the target sum: ";
    cin >> target;
    cout << "Number of ways to get target sum: " << solution.numRollsToTarget(n, k, target) << endl;
    return 0;
}
