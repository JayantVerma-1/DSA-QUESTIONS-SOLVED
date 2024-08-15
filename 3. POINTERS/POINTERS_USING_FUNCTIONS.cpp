#include <iostream>
using namespace std;
// PASS BY VALUE
void solve1(int num)
{
    num++;
}
// PASS BY REFERENCE
void solve2(int& num)
{
    num++;
}
int main()
{
    int a = 5;
    solve1(a);
    cout << "ACCORDIN TO PASS BY VALUE , ANS = " << a << endl; // since its a Pass by value function to changes variable me reflect nahi hote
    solve2(a);
    cout << "ACCORDIN TO PASS BY REFERENCE , ANS = " << a << endl; //since its Pass by Reference so the value of variable changes 
    return 0;
}