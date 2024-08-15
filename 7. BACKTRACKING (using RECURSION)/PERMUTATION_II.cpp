#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void permuteUniqueHelper(vector<int>& nums, vector<vector<int>>& ans, int start){
        // BASE 
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_map<int, bool> visited;
        for(int i = start; i < nums.size(); i++){
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }
            visited[nums[i]] = true;
            swap(nums[i], nums[start]);
            permuteUniqueHelper(nums, ans, start + 1);
            swap(nums[i] , nums[start]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUniqueHelper(nums, ans, 0);
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = sol.permuteUnique(nums);

    cout << "Unique permutations:\n";
    for(const auto& permutation : result) {
        cout << "[ ";
        for(const auto& num : permutation) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
