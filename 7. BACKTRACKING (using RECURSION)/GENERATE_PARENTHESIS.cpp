#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    void solve(std::vector<std::string> &ans, int n, int open, int close, std::string output){
        //BASE CASE 
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }
        
        //INCLUDE OPEN BRACKET 
        if(open > 0){
            output.push_back('(');
            solve(ans, n, open - 1, close, output);
            //BACKTRACK
            output.pop_back();
        }
        //INCLUDE CLOSE BRACKET 
        if(close> open){
            output.push_back(')');
            solve(ans, n, open, close - 1, output);
            //BACKTRACK
            output.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        int open = n;
        int close = n;
        std::string output = "";
        solve(ans, n, open, close, output);
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::vector<std::string> result = sol.generateParenthesis(n);
    std::cout << "All valid parentheses combinations are:\n";
    for(const auto& str : result) {
        std::cout << str << "\n";
    }
    return 0;
}
