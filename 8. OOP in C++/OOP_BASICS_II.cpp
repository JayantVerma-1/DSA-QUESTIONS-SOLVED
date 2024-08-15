// HOW TO ACCESS A PRIVATE CLASS
// LEARNING TO USE GETTER SETTER

#include <iostream>
using namespace std;

// CREATING A CLASS

class Animal
{
    // STATE OR PROPERTIES
private:
    int weight;

public:
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

    //GETTER AND SETTER 

    int getWeight()
    {
        return weight;
    }

    void setWeight(int w)
    {
        weight = w;
    }
};

int main()
{
    // OBJECT CREATION - do tareeke se ho sakti h 1. static 2. dynamic
    // 1. STATIC
    Animal ramesh;
    ramesh.age = 12;
    ramesh.type = "LION";

    cout << "Age of ramesh is: " << ramesh.age << endl;   // GIVES a GARBAGE VALUE if ramesh.age = 12;is not declared.
    cout << "Type of ramesh is: " << ramesh.type << endl; // GIVES NO VALUE if ramesh.name = ? is not declared.

    ramesh.eat();

    ramesh.sleep();

    // TO PRIVATE MEMBER
    ramesh.setWeight(101); //SETTER
    cout << "weight " << ramesh.getWeight() << endl; //GETTER

    // 2. DYNAMIC MEMORY
    // next me seekhege iske baare mei
    return 0;
}