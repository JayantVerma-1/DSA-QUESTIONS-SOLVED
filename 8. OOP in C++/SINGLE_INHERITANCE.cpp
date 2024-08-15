//SINGLE INHERITANCE 

#include<iostream>
using namespace std;
class Car{
    public:
    string name;
    int weight;
    int age;

    void speedUp() {
        cout<<"speeding up"<<endl;
    }
    void brakeMaaro() {
        cout<<"brake maardi"<<endl;
    }
};
//inheritance
class Scorpio:public Car{ //isko read karne ka tareeka : scorpio is a car

};

int main(){
     Scorpio vermavaali;
     vermavaali.speedUp();
}