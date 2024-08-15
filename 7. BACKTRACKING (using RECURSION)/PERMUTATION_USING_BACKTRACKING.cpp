// THIS CODE IS FOR PRINTING PERMUTATION OF A STRING (abc) , USING BACKTRACKING WHICH IS A CASE FOR SPECIAL TYPE OF RECURSION.
#include <iostream>
using namespace std;
void printPermutation(string &str, int i)
{
    // BASE CASE
    if (i >= str.length())
    {
        cout << str << " ";
        return;
    }
    // SWAPPING
    for (int j = i; j < str.length(); j++)
    {
        // SWAP
        swap(str[i], str[j]);
        // RECURSION
        printPermutation(str, i + 1);
        // BACKTRACKING - to recreate the original input string as we are calling function by reference.
        swap(str[i], str[j]);
    }
}

int main()
{
    string str = "abc";
    int i = 0;
    printPermutation(str, i);
    return 0;
}