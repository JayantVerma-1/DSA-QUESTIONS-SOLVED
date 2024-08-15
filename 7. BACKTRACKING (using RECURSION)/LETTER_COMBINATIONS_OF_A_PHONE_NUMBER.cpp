#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    void solve(std::vector<std::string> &ans, int index, std::string output, std::string digits, std::vector<std::string> &mapping){
        //BASE CASE
        if(index >= digits.length()) {
            ans.push_back(output);
            return;
        }
    
        // CASE SOLVE
        int digit = digits[index] - '0';
        std::string value = mapping[digit];
        for(int i = 0; i < value.length(); i++){
            char ch = value[i];
            // INCLUDE
            output.push_back(ch);
            // RECURSIVE CALL
            solve(ans, index+1, output, digits, mapping);
            // BACKTRACKING
            output.pop_back();
        }
    }
    
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> ans;
        // EMPTY STRING CASE
        if(digits.length() == 0)
            return ans;
        
        int index = 0;
        std::string output = "";
        std::vector<std::string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        
        solve(ans, index, output, digits, mapping);
        
        return ans;    
    }
};

int main() {
    Solution sol;
    std::string digits;
    std::cout << "Enter digits (2-9): ";
    std::cin >> digits;
    std::vector<std::string> result = sol.letterCombinations(digits);
    std::cout << "All possible letter combinations are:\n";
    for(const auto& str : result) {
        std::cout << str << "\n";
    }
    return 0;
}
