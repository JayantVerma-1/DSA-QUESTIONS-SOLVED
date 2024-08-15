#include<iostream>
using namespace std;
class Node{
   public:
   int data;
   Node* next;

   Node(int data){
   this -> data = data;
   this -> next = NULL;
}};
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl; 
}
void removeDuplicates(Node* & head){
    if (head == NULL)
    {
        cout <<" LL IS EMPTY " << endl;
        return;
    }
    if (head -> next == NULL)
    {
        cout << " SINGLE NODE IN LL : " << endl;
        return;
    }
   // >1 NODE IN LL
   Node* curr = head;
   while (curr != NULL)
   {
    if ((curr -> next != NULL) && (curr -> data == curr ->next -> data))
    {
        //equal
        Node* temp = curr -> next;
        curr -> next = curr -> next -> next;
        //DELETE NODE
        temp -> next = NULL;
        delete temp;
    }
    else{
        //Not Equal
        curr = curr -> next;
    }
   }
    
    
}
int main(){
    Node* head = new Node(10);
    Node* second = new Node(10);
    Node* third = new Node(20);
    Node* fourth = new Node(30); 

    head -> next = second;
    second -> next = third;
    third -> next = fourth;

    cout << " INPUT LL : ";
    print(head);

    removeDuplicates(head);
    cout << " OUTPUT LL : ";
    print(head);
    return 0;
}