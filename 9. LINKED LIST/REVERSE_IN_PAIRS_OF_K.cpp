//CODE FOR REVERSING A L.L. IN PAIRS OF K

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
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        temp = temp -> next;
        len++;
    }
    return len;
}
Node* reverseKNodes(Node* &head, int k){
    if (head == NULL)
    {
        cout << "LL is EMPTY" << endl;
        return NULL;
    }
    
    int len = getLength(head);
    if (k>len)
    {
        return head;
    }

    //IT MEANS NUMBER OF NODES IN LL is >= k
    //STEP 1 : reverse first k nodes of ll
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr -> next;
    int count = 0;

    while (count < k)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    //STEP 2 : RECCURSIVE CALL 
    if (forward != NULL)
    {
        // we still have  nodes left to reverse 
        head -> next = reverseKNodes(forward, k);
    }
    //STEP 3 : return head of the modified Linkedlist
    return prev;
    
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
   head = reverseKNodes(head, 2);
   print(head);  
    
    return 0;
}