//isme seekhenge DESTRUCTOR KO USE KARNA.

#include <iostream>
using namespace std;
class Animal
{
private:
    int weight;

public:
    int age;
    string type;

    ~Animal() {
        cout << "I am INSIDE DESTRUCTOR: " << endl;
    }
 };

int main()
{
    //FOR STATIC( STACK ) , DESTRUCTOR RUNS AUTOMATICALLY.
    Animal a;
    a.age =5;

    //FOR DYNAMIC( HEAP ) ,DESTRUCTOR WONT RUN AUTOMATICALLY. i.e. DESTRUCTOR NEEDS TO BE RUN MANUALLY.
    Animal* b = new Animal();
    b->age=12;
    //MANUALLY DESTRUCTOR SYNTAX
    delete b;
    return 0;
}