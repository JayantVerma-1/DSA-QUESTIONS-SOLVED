//LEETCODE 1655
// You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:

// The ith customer gets exactly quantity[i] integers,
// The integers the ith customer gets are all equal, and
// Every customer is satisfied.
// Return true if it is possible to distribute nums according to the above conditions.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canDistributeHelper(vector<int>& counts, vector<int>& quantity, int ithCustomer){
        // BASE CASE
        if(ithCustomer > quantity.size() - 1){
            return true;
        }
        
        for(int i = 0; i < counts.size(); i++){
            if(counts[i] >= quantity[ithCustomer]){
                counts[i] -= quantity[ithCustomer];
                
                if(canDistributeHelper(counts, quantity, ithCustomer + 1)){
                    return true;
                }
                
                // BACKTRACK...
                counts[i] += quantity[ithCustomer];
            }
        }
        
        return false;
    }
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> countMap;
        for(auto num:nums)
            countMap[num]++;
        vector<int> counts;
        for(auto it:countMap)
            counts.push_back(it.second);
        // Sort the quantity map in decreasing order
        sort(quantity.rbegin(), quantity.rend());
        // Check if distribution is possible recursively
        return canDistributeHelper(counts, quantity, 0);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 3, 3};
    vector<int> quantity = {2, 2};
    if(solution.canDistribute(nums, quantity))
        cout << "Yes, it's possible to distribute the quantities." << endl;
    else
        cout << "No, it's not possible to distribute the quantities." << endl;
    return 0;
}
