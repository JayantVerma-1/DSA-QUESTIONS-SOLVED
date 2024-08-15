//POLYMORPHISM KAISE KARTE HAI + in this code FUNCTION overloading is also explained

#include<iostream>
using namespace std;

class Maths{
    public:
      //Line 9, 13, 17 clearly SUM function is implemented in MANY FORMS so it is Polymorphism.
      int sum(int a, int b){
        cout << "I am in First Signature " << endl;
        return a+b;
      }
      int sum(int a, int b, int c){
        cout << "I am in Second Signature " << endl;
        return a+b+c;
      }
      int sum(int a, float b){
        cout << "I am in Third Signature " << endl;
        return a+b+100;    
      }   
      //HERE FUNCTION OVERLOADING IS BEING USED AS IN EVERY fn either number of parameter or type of parameter is being changed.
};

int main (){
    Maths obj;
    cout << obj.sum(2, 5); //Here , 2 int are passed so 1st sum will get executed
    cout << endl;
    cout << obj.sum(2, 5, 7); //Here , 3 int are passed so 2nd sum will get executed
    cout << endl;
    cout << obj.sum(2, 5.16f);//here f in last represents the number as a floating number. clearly 3rd sum will be executed.
    cout << endl;
    return 0;
}