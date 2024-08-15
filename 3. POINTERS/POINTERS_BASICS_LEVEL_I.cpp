#include<iostream>
using namespace std;
int main(){
    int a = 5;
    int b = 115;
    cout << a << endl;
    cout << &a << endl; // (&)used for finding address , gives a hexadecimal value.
    cout << &b << endl; // 2 addresses of different variables  can NEVER BE SAME.      
    int* ptr = &a; // this is how we use pointer NOTE pointer aways stores an address of a variable.
    cout <<"address of a is : " << &a << endl;
    cout <<"value stored in ptr : " << ptr << endl; // if we print ptr , since it stores the address of a variable so the adress itself gets printed.
    cout <<"value ptr is pointing to : "<< *ptr << endl; // inorder to get the value of the variable to which the pointer is assigned to we use *ptr.
    cout <<"address of ptr :   "<< &ptr << endl;
     //calculating size of different pointers using syntax sizeof()
    int j = 9;
    int* p = &j;
    cout << sizeof(p) << endl;

    char ch = 'b';
    char* c = &ch;
    cout << sizeof(c) << endl;
    
    double dtr = 5.03;
    double* d = &dtr;
    cout << sizeof(d) << endl;
// hence we come to know that size of differnt pointrs remain same i.e. 4 for a 32 bit computer and 8 for a 64 bit computer
return 0;
}