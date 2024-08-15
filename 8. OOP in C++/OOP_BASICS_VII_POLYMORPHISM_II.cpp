//POLYMORPHISM KAISE KARTE HAI + in this code OPERATOR overloading is also explained

#include<iostream>
using namespace std;

class Param{
    public:
      int val;

      void operator+(Param& obj2){
            int value1 = this->val;
            int value2 = obj2.val;
            cout << (value2 - value1) << endl;
      }
};

int main (){
    Param obj1, obj2;
    obj1.val = 7;
    obj2.val = 2;

    //this line 21 should print the difference between them.
    obj1 + obj2; //OPERATOR OVERLOADING : i.e through + symbol we are making it work like - symbol.
    return 0;
}