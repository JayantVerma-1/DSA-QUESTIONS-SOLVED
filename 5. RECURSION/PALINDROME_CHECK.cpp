#include <iostream>
using namespace std;
//time complexity = 0{n/2 + 1} i.e = 0{n}
//space complexity = 0{n/2 +1} i.e = 0{n}
bool isPalindrome(string &s, int start, int end)
{
    // BASE CASE
    if (start >= end)
    {
        return true;
    }
    // EK CASE HAM SOLVE KARDEGE
    if (s[start] != s[end])
    {
        return false;
    }
    // BAAKI RECURSION SAMBHAL LEGA
    return isPalindrome(s, start + 1, end - 1);
}

int main()
{
    string s;
    cout << "enter the string" << endl;
    cin >> s;
    cout << isPalindrome(s, 0, s.size() - 1) << endl;
}