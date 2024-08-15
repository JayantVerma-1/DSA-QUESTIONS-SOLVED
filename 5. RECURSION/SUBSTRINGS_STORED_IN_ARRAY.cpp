#include <iostream>
using namespace std;
#include <vector>

void printSubsequences(string str, string output, int i, vector<string> &v)
{

    // BASE CASE
    if (i >= str.length())
    {

        // STORE
        v.push_back(output);
        return;
    }

    // CASE 1 EXCLUDE condition
    printSubsequences(str, output, i + 1, v);

    // CASE 2 INCLUDE condition
    output.push_back(str[i]);                 // Output --> output = output+str[i];
    printSubsequences(str, output, i + 1, v); // CAN USE this single line --> printSubsequences(str, output+str[i], i+1); instead of 16th and 17th line.

    // NOTE : EXCLUDE KA CASE PEHLE LIKHNE KA REASON ye hai ki agr hamne include ka case pehle lelia to exclude me aane paer pehle hame pop yani remove karna padega added chizo ko
}

int main()
{
    string str = "abc";
    string output = " ";

    vector<string> v;

    int i = 0;
    printSubsequences(str, output, i, v);
    cout << "printing all subsequences: " << endl;
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout <<endl<< "SIZE OF VECTOR IS : " << v.size() << endl;
    return 0;
}