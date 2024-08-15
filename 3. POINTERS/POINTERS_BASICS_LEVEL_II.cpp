#include<iostream>
using namespace std;

int main(){
     
    // 1.POINTER IMPLEMENTATION OVER AN INT ARR
    int arr[4] ={12,14,16,18};

    cout << arr << endl; // THis will give the base address for the array which is same as address for a[0]
    cout << arr[0] << endl; // It gives the value stored at index 0 of the array i.e. a[0]
    cout << &arr << endl; // This also gives the base address of the array 
    cout << &arr[0] << endl; // It gives the address of first index i.e 0 which is the base address for array
    cout << &arr[2] << endl; // it gives the address at index 2

    int* p = arr;
    cout << p << endl; // this also indicates the BASE ADDRESS
    cout << &p << endl; // IT INDICATES THE ADDRESS OF VARIABLE P.
    
    cout << *arr << endl; // Value at index 0 or say base address 
    cout << *arr + 1 << endl; // Value at base address , increased by 1
    cout << *(arr) + 1 << endl; //Same as previous 
    cout << *(arr + 1) << endl; // Value at one address further to base address i.e arr[1]
    cout << arr[1] << endl;
    cout << *(1 + arr) << endl; 
    cout << 1[arr] << endl;
    cout << *(arr + 2) << endl; // Value at 2 address ahead base adress i.e arr[2]
    cout << arr[2] << endl;
    cout << *(2 + arr) << endl;
    cout << 2 [ arr] << endl;
    // observe the above lines Carefully ! 
    // Thus, we notice that : arr[i] = *(arr + i) or say i[arr] = *(i + arr)
    
    // 2. POINTER IMPLEMENTATION OVER AN CHAR ARRAY (ITS DIFFERENT THAN INT ARRAY)
    char ch[] = "Jayant";
    char* c = ch;

    cout << ch << endl; // Prints the entire string
    cout << &ch << endl; // Gives the BASE ADDRESS of the string i.e. address of ch[0];
    cout << *ch << endl; // prints the first char in the string
    cout << ch[0] << endl; // Gives the character stored at ch[0]

    cout << c << endl; // UNLIKE INT it will give give the entire string stored at the address in the pointer.
    cout << &c << endl; // Prints the address of the Pointer
    cout << *c << endl; // Prints the value (character ) at the base address or index 0;
    
    //example 2 in char
    char name[100] = "SherBano";
    char* cptr = &name[0];

    cout << name << endl;
    cout << &name << endl;
    cout << *(name + 3) << endl;
    cout << cptr << endl;
    cout << &cptr << endl;
    cout << *(cptr+3) << endl;
    cout << cptr + 2 << endl;
    cout << *cptr << endl;
    cout << cptr + 8 << endl;

    // SPECIAL CASE (garbage value case)
    char j = 'k'; // when we have only one char
    char* cptrr = &j;

    cout << cptrr <<endl; // GARBAGE VALUE AFTER K TILL NULL IS ACHIEVED.
    // special case can be treated in this way to get the desired result
    char jj[10] = "k"; // when we have only one char
    char* cptrrr = &jj[0];

    cout << cptrrr <<endl;

     return 0;
}