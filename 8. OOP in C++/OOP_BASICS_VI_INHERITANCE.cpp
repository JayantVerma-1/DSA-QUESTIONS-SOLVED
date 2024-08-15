//INHERITANCE KAISE KARTE HAI CODE ME , LETS UNDERSTAND THROUGH AN EXAMPLE !

#include<iostream>
using namespace std;

class Animal{
    public:
        int age;
        int weight;
    
        void eat(){
            cout << "Eating" << endl;
        }
};

//line 16+17 - inheritance
class Dog:public Animal{

};
int main(){
    Dog d1;
    d1.eat();
    return 0;
}
