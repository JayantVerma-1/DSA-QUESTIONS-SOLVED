#include <iostream>
using namespace std;

void printSubsequences(string str , string output , int i){

    // BASE CASE
    if(i>=str.length()){
        cout << output << endl;
        return;
    }

    // CASE 1 EXCLUDE condition
    printSubsequences(str, output, i+1);

    // CASE 2 INCLUDE condition 
    output.push_back(str[i]); //Output --> output = output+str[i];
    printSubsequences(str, output, i+1); //CAN USE this single line --> printSubsequences(str, output+str[i], i+1); instead of 16th and 17th line.

    //NOTE : EXCLUDE KA CASE PEHLE LIKHNE KA REASON ye hai ki agr hamne include ka case pehle lelia to exclude me aane paer pehle hame pop yani remove karna padega added chizo ko 
}

int main(){
    string str = "abc";
    string output = "";

    int i = 0;
    printSubsequences (str, output, i);
    return 0;
}