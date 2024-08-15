//HEIRARCHICAL INHERITANCE 

#include<iostream>
using namespace std;

class Car{
    public:
    int age;
    int weight;

    void speedUp() {
        cout << " Speeding up " << endl;
    }
};

class Scorpio:public Car{

};

class Fortuner:public Car{

};

int main(){
   Scorpio s12;
   s12.speedUp();
    
    Fortuner slr;
    slr.speedUp();      
    return 0;
}