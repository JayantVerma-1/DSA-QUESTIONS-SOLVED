#include <iostream>
using namespace std;

// RTL means right to left method
//TIME COMPLEXITY = O{n}
//SPACE COMPLEXITY - O{n}

void lastOccurRTL(string &str, char x, int i , int &ans)
{
    // BASE CASE
    if (i<0)
        return;

    // EK CASE SOLVE
    if (str[i] == x)
    {
        ans=i;
        return;
    }
    // baaki recursion khud karlega
    lastOccurRTL(str, x, i - 1, ans);
}

int main()
{
    string str;
    cout << "enter a string" << endl;
    cin >> str;

    char x;
    cout << "enter the character you want" << endl;
    cin >> x;

    int ans = -1;
    lastOccurRTL(str, x, str.length(), ans);
    cout << ans << endl;
}
