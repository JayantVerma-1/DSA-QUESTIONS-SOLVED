//MULTILEVEL INHERITANCE 

#include<iostream>
using namespace std;
class Fruit{
    public:
    string name;
};
//multilevel inheritance
class Mango:public Fruit { //isko read karne ka tareeka : Mango is a Fruit.
    public:
    int weight;
};
class LangdaAam:public Mango { //isko read karne ka tareeka : LangdaAam is a Mango.
    public:
    int sugarlevel;
};

int main(){
     LangdaAam a;
     cout<<a.name<<" "<<a.weight<<" "<<a.sugarlevel<<endl;

     return 0;
}