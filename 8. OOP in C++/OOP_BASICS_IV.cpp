//isme seekhenge CONSTRUCTOR KO USE KARNA.

#include <iostream>
using namespace std;
class Animal
{
private:
    int weight;

public:
    int age;
    string type;

    //CONSTRUCTORS :

    //type 1. default constructor
    Animal(){
        this->weight = 0; // this-> used for good coding practice , only weight can also work.
        this->age = 0 ;
        this->type = "" ; 
        cout << "DEFAULT CONSTRUCTOR CALLED " << endl;
    }
    //type 2. PARAMETERIZED CONSTRUCTOR
    Animal(int age){
        this-> age = age;
        cout << "PARAMETERIZED CONSTRUCTOR CALLED " << endl;
    }

    Animal(int age, int weight, string type){
        this-> age = age;
        this-> weight = weight;
        this-> type = type ;
        cout << "PARAMETERIZED CONSTRUCTOR @TWO CALLED " << endl;
    }
    //type 3. COPY CONSTRUCTOR
    Animal(Animal &obj){
        this -> age = obj.age;
        this -> weight = obj.weight;
        this -> type = obj.type;
        cout << "I AM INSIDE COPY CONSTRUCTOR " << endl;
    }
 };

int main()
{
    Animal a;
    Animal *aa = new Animal; // THE OTHER WAY TO WRITE LINE 39

    Animal b(200);
    Animal * ba = new Animal(200); //yaha hamne ek parameter paas kia integer type ka , ab compiler aisa constructor dhundega jisme ek parameter hi ho integer type ka aur fir use call krdega. 
    
    Animal c(100, 20, "BABBA");//yaha hamne teen parameter paas kie do integer type ke and ek string type ka , ab compiler aisa constructor dhundega jisme do integer type ke and ek string type ka parameter hoh aur fir use call krdega. 
    Animal *cc = new Animal(100, 20, "BABBA");// THE OTHER WAY TO WRITE LINE 43

    //OBJECT COPY
    Animal c = a;
    // Animal animal1(c);
    return 0;
}