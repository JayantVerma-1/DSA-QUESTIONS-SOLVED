#include <iostream>
#include <vector>
using namespace std;
void checkKey(string &str, int i, int &n, char &key, vector<int> &ans)
{
    // BASE CASEE
    if (i >= n)
    {
        return;
    }
    // CASE 1 SOLVE KARDO
    if (str[i] == key)
        // STORE IN VECTOR
        if (str[i] == key)
        {
            ans.push_back(i);
        }

    // BAAKI RECURSION SAMBHAL LEGA
    return checkKey(str, i + 1, n, key, ans);
}

int main()
{
    string str = "JAYANTT";
    int n = str.length();
    char key = 'T';

    int i = 0;
    vector<int> ans;

    checkKey(str, i, n, key, ans);
    cout << "PRINTING ans : " << endl;
    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}