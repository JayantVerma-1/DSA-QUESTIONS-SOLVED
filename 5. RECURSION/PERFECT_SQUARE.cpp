#include <iostream>
#include <cmath>
#include <climits>

class Solution {
public:
    
    int numSquareHelper(int n){
        // base case
        if(n == 0) return 1;
        if (n < 0) return 0;
        
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i<=end){
            int perfectSquare = i*i;
            int numberOfPerfectSquares = 1 + numSquareHelper(n - perfectSquare);
            if(numberOfPerfectSquares < ans){
                ans = numberOfPerfectSquares;
                
            }
            
            i++;
            
        }
        
        return ans;
        
    }
    int numSquares(int n) {
        return numSquareHelper(n) -1;
    }
};

int main() {
    Solution sol;
    int n = 12;
    std::cout << "Minimum number of perfect squares that sum up to " << n << " is: " << sol.numSquares(n) << std::endl;
    return 0;
}
