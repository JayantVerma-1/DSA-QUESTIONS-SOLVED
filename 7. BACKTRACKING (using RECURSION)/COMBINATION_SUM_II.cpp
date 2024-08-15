#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void combinationSum_helper(vector<int>& candidates, int target, vector<int>& v, vector<vector<int>>&ans, int index){
        // BASE CASE
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }
        
        for(int i = index ; i < candidates.size() ; i++){
            if(i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            v.push_back(candidates[i]);
            combinationSum_helper(candidates, target-candidates[i], v, ans, i + 1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum_helper(candidates , target , v , ans , 0);
        return ans;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    // Printing the result
    cout << "Possible combinations:\n";
    for(const auto& combination : result) {
        cout << "[ ";
        for(const auto& num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
