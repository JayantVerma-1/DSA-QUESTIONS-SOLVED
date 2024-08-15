//FUNCTION/METHOD OVERRIDING explained in this.

#include<iostream>
using namespace std;

class Animal{
    public:
      int val;

      void Speak(){
        cout << "SPEAKING " << endl; //Zaroori nahi h ise define karna hi hai ham bina definition ke sirf declare krk bhi kaam kar skte. 
      }
};

class Dog: public Animal{
    public:
    //OVERRIDING , this means we are defining a function which is already inherited from parent class (Speak in this case) in a NEW WAY.    
    void Speak(){
        cout << "BARKING " <<endl;
    }
};
int main (){
    Animal A;
    A.Speak(); //here in this case the animal  fumction will run

    Dog Aa;
    Aa.Speak(); //here in this case the overrided function of Dog will run
    cout << endl;

    //UPCASTING : 
    Animal* a = new Dog(); 
    a->Speak(); //By default isme Pointer(*) vali CLASS ka FUNCTION run hoga i.e Animal but agar hum "virtual keyword" ka use kare class ke just pehle to result opposite hojaege i.e dog vala fn run hoga"

    //DOWNCASTING : 
    Dog* d = (Dog*)new Animal();
    d->Speak();//By default isme Pointer(*) vali CLASS ka FUNCTION run hoga i.e Dog but agar hum "virtual keyword" ka use kare class ke just pehle to result opposite hojaege i.e Animal vala fn run hoga"
    return 0;
}