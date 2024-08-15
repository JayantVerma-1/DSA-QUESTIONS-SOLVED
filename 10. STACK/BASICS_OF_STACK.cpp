// IN THIS CODE WE IMPLEMENT STACK USING PREDEFINED FUNCT. i.e. #include<stack> , in next code we will IMPLEMENT STACK OURSELF WITHOUT USING PRE DEF FN+UNCT.

#include<iostream>
#include<stack>
using namespace std;

int main(){
    //CREATION OF STACK 
    stack<int> st;

    //INSERTION IN A STACK
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(45);
    st.push(49);
    st.push(50);

    //DELETION FROM A STACK
    st.pop(); //last element i.e 50 will be deleted.

    //CHECK ELEMENT ON TOP 
    cout << "ELEMENT ON THE TOP IS : " << st.top() << endl;

    //CHECKING THE SIZE OF A STACK
    cout << "THE SIZE OF THE STACK IS : " << st.size() << endl;

    //checking if empty stack or not
    if(st.empty())
    cout << "STACK IS EMPTY : " << endl;
    else
    cout << "STACK ISNT EMPTY : " << endl;

    //PRINTING A STACK :
    cout << "printing the stack ";
    while(!st.empty()) { //i.e. while stack is not empty 
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;


    return 0;
}