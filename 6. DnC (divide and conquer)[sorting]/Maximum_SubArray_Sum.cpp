//TIME COMPLEXITY = O(nlogn)
//SPACE COMPLEXITY = O(logn)
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSumArrayHelper(vector<int>& v, int start, int end) {
        if (start == end) return v[start];
        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;

        int mid = start + (end - start) / 2;

        int maxLeftSum = maxSumArrayHelper(v, start, mid);
        int maxRightSum = maxSumArrayHelper(v, mid + 1, end);

        // MAX CROSS BORDER SUM
        int leftBorderSum = 0, rightBorderSum = 0;
        for (int i = mid; i >= start; i--) {
            leftBorderSum += v[i];
            if (leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
        }
        for (int i = mid + 1; i <= end; i++) {
            rightBorderSum += v[i];
            if (rightBorderSum > maxRightBorderSum) maxRightBorderSum = rightBorderSum;
        }
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(maxLeftSum, max(maxRightSum, crossBorderSum));
    }

    int maxSubArray(vector<int>& nums) {
        return maxSumArrayHelper(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input
    int maxSubArraySum = solution.maxSubArray(nums);
    cout << "Maximum contiguous sum is: " << maxSubArraySum << endl;
    return 0;
}
