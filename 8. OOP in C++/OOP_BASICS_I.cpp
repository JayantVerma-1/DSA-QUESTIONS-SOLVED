//LEARNING TO CREATE A CLASS
//ACCESS MODIFIERS , HOW TO USE
#include <iostream>
using namespace std;

// CREATING A CLASS

class Animal
{
    // STATE OR PROPERTIES    
    public: //THIS IS A ACCESS MODIFIER ,SET IT TO "PUBLIC" BEFORE PROCEEDING IN ORDER TO ACCESS THE CLASS PROPERTIES OUTSIDE THE CLASS.
            //DEFAULT VALUE FOR IT IS PRIVATE i.e. CLASS PROPERTIES CAN BE ONLY ACCESSIBLE INSIDE THE CLASS.
    int age;
    string type;

    // BEHAVIOUR OR FUNCTION (KNOWN AS METHODS IN JAVA)

    void eat()
    {
        cout << "EATING" << endl;
    }

    void sleep()
    {
        cout << "SLEEPING" << endl;
    }

};

int main()
{
    //OBJECT CREATION - do tareeke se ho sakti h 1. static 2. dynamic
    //1. STATIC 
    Animal ramesh;
    ramesh.age = 12;
    ramesh.type = "LION";

    cout << "Age of ramesh is: " << ramesh.age << endl; // GIVES a GARBAGE VALUE if ramesh.age = 12;is not declared.
    cout << "Type of ramesh is: " << ramesh.type << endl; // GIVES NO VALUE if ramesh.name = ? is not declared.
     
    ramesh.eat();

    ramesh.sleep();     

    //2. DYNAMIC MEMORY 

    return 0;
}