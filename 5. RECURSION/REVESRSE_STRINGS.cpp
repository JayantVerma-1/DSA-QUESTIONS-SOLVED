#include <iostream>
#include <string>
using namespace std;
//TIME COMPLEXITY OF CODE = O{n}
//SPACE COMPLEXITY OF CODE = O{n}


void reverseString(string &s, int start, int end)
{
    // BASE CASE
    if (start >= end)
    {
        return;
    }

    // EK CASE HAM SOLVE KAREGE
    swap(s[start], s[end]);

    // BAAKI RE SAMBHAL LEGA
    reverseString(s, start + 1, end - 1);

}

int main()
{
    string s;
    cout << " enter the string" << endl;
    cin >> s;

    reverseString(s, 0, s.size() - 1);
    cout << s << endl;
    return 0;
}
