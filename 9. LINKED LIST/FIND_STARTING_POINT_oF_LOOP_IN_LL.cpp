//CODE FOR FINDING STARTING POINT OF A LOOP! 

#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }
};
void print(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
        cout << endl;
}

//CHECKING FOR LOOP IF PRESENT (USING FLOYDS LOOP FINDING ALGO.)
bool checkForLoop(Node* &head){
    if (head == NULL)
    {
        cout << "LL IS EMPTY : " << endl;
        return false;    
    }
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        if (slow == fast)
        {
            return true;
        }
        
    }
    
    return false;
}
//FINDING THE STARTING NODE OF THE LOOP PRESENT IN THE LINKED LIST:  

Node* startingPointLoop(Node* &head){
    if (head == NULL)
    {
        cout << "LL IS EMPTY : " << endl;
        return NULL;    
    }
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        if (slow == fast)
        {
        slow = head;
        break;
        }
        
    }
    while (slow!= fast)
    {
    slow = slow -> next;
    fast = fast -> next;
    }
    return slow;
    

}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(40);
    Node* fourth = new Node(50);
    Node* fifth = new Node(60);
    Node* sixth = new Node(70);
    Node* seventh = new Node(80);
    Node* eighth = new Node(90);
    Node* ninth = new Node(100);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = seventh;
    seventh -> next = eighth;
    eighth -> next = ninth;
    ninth -> next = fifth;

    cout<< " LOOP IS PRESENT OR NOT "<< checkForLoop(head)<<endl;;

    cout<< " STARTING POINT OF LOOP IS : "<< startingPointLoop(head) -> data<<endl;

    return 0;
}