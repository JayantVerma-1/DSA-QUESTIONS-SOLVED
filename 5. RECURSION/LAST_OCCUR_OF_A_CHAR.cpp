#include <iostream>
using namespace std;

// LTR means left to right method
//TIME COMPLEXITY = O{n}
//SPACE COMPLEXITY - O{n}

void lastOccurLTR(string &str, char x, int i, int &ans)
{
    // BASE CASE
    if (i >= str.size())
        return;

    // EK CASE SOLVE
    if (str[i] == x)
    {
        ans = i;
    }
    // baaki recursion khud karlega
    lastOccurLTR(str, x, i + 1, ans);
}

int main()
{
    string str;
    cout << "eter a string" << endl;
    cin >> str;

    char x;
    cout << "enter the character you want" << endl;
    cin >> x;

    int ans = -1;
    lastOccurLTR(str, x, 0, ans);
    cout << ans << endl;
}