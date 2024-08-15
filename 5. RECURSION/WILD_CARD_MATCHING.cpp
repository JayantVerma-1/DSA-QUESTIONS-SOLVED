#include <iostream>
#include <string>

class Solution {
public:
    bool isMatchHelper(std::string&s, int si, std::string&p, int pi) {
        // BASE Case
        if(si == s.size() && pi == p.size()){
            return true;
        }
        
        if(si == s.size() && pi < p.size()){
            while(pi < p.size()){
                if( p[pi] != '*')
                    return false;
                pi++;
            }
            return true;
        }
        
        // single char matching
        if(s[si] == p[pi] || '?' == p[pi]){
            return isMatchHelper(s, si+1, p, pi+1);
            
        }
        
        if(p[pi]== '*'){
            // treat * as empty or null
            bool caseA = isMatchHelper(s, si, p, pi+1);
            
            // let '*' consume one char
            bool caseB = isMatchHelper(s, si+1, p, pi);
            return caseA || caseB;
        }
        // Char doesn't match
        return false;
    }
    
    bool isMatch(std::string s, std::string p){
        int si = 0; // pointer index for s string
        int pi = 0; // pointer index for p string
        
        return isMatchHelper(s, si, p, pi);
    }
};

int main() {
    Solution solution;
    std::string s = "aa";
    std::string p = "a*";
    
    if (solution.isMatch(s, p)) {
        std::cout << "String matches the pattern.\n";
    } else {
        std::cout << "String doesn't match the pattern.\n";
    }
    
    return 0;
}
