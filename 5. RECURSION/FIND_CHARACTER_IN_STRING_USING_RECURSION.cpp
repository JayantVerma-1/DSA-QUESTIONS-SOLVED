#include <iostream>
using namespace std;
bool checkKey(string str, int i, int n, char key)
{
    // BASE CASEE
    if (i >= n)
    {
        return false;
    }
    // CASE 1 SOLVE KARDO
    if (str[i] == key)
        return true;
    // BAAKI RECURSION SAMBHAL LEGA
    bool ans = checkKey(str, i + 1, n, key);
    return ans; //if you  want to get the index where key is placed put i instead of ans.
}

int main()
{
    string str = "JAYANTT";
    int n = str.length();
    char key = 'T';

    int i = 0;
    bool ans = checkKey(str, i, n, key);
    cout << "answer is : " << ans << endl;
    return 0;
}