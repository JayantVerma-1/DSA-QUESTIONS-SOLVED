//CODE FOR FINDING MIDDLE ELEMENT IN A LINKED LIST

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
//FINDING THE MIDDLE NODE DATA
Node* getMiddle(Node* &head){
    if (head == NULL)
    {
        //EMPTY LL
       cout << "LL is EMPTY " << endl;
       return head;
    }
    if (head -> next == NULL)
    {
        //ONLY ONE NODE IN LL
        return head;
    }

    //LL HAVE > 1 NODE
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }   
    }
    return slow;
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(40);
    Node* fourth = new Node(50);
    Node* fifth = new Node(60);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = NULL;

    print(head);
    //PRINTING MIDDLE NODE
    cout << "MIDDLE NODE IS : " << getMiddle(head) -> data << endl; 
    
    return 0;
}