// INSERTION AT ANY GIVEN POSITION

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// I want to insert a node right at the HEAD of linkedlist.
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // CHECK FOR EMPTY L.L
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step1: create a node
    Node *newNode = new Node(data);
    // Step2: connect with head node
    newNode->next = head;
    // Step3: update head node
    head = newNode;
}
// I want to insert a node right at the TAIL of linkedlist.
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // CHECK FOR EMPTY L.L
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step1: create a node
    Node *newNode = new Node(data);
    // Step2: connect with tail node
    tail->next = newNode;
    // Step3: update tail
    tail = newNode;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int findLength(Node* & head){
    int len = 0;
    Node* temp = head;
    while (temp != NULL){
        temp = temp -> next;
        len ++ ;
    }
    return len;
    {
        /* code */
    }
    
}
//ANYPOSITION CODE from line 81 
void insertAtAnyPosition(int data, int position, Node* &head, Node* & tail){
    if(head == tail){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
      //STEP 1: FIND THE POSITION i.e. previous pointer and current pointer

      if (position == 0)
      {
        insertAtHead(head, tail, data);
        return;
      }
      int len = findLength(head);
      if (position >= len)
      {
        insertAtTail(head, tail, data);
        return;
      }
      
      int i = 1;
      Node* prev = head;
      while (i<position)
      {
        prev = prev-> next;
        i++;
      }
      Node* curr = prev -> next;

      //STEP 2: CREATE A NODE
      Node * newNode =new Node(data);

      //STEP 3: UPDATE THE NODES
      newNode -> next = curr;
      //STEP 4: UPDATE THE NODES
      prev -> next = newNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 200);
    insertAtHead(head, tail, 2000);
    insertAtHead(head, tail, 20000);
    insertAtHead(head, tail, 200000);
    insertAtTail(head, tail, 77);
    insertAtTail(head, tail, 770);

    insertAtAnyPosition(101,0,head,tail);
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;
    print(head);
    return 0;
}