// DOUBLY LINKEDLIST , INSERTION at start , end and at any given position && DELETION AT start, end, and at any given POSITION.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        cout << " NODE WITH VALUE : " << this -> data << " dleted " << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node *head)
{
    int length = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

// INSERTION AT THE BEGINNING!
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // i.e ll is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        // i.e ll is not empty
        // STEP 1: CREATE A NODE
        Node *newNode = new Node(data);
        // STEP 2:
        newNode->next = head;
        // STEP 3:
        head->prev = newNode;
        // STEP 4:
        head = newNode;
    }
}
// INSERTION AT LAST i.e. TAIL
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // i.e ll is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        // L.L. is not empty
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // IF LL IS EMPTY
        if (position == 1)
        {
            insertAtHead(head, tail, data);
            return;
        }
        int len = getLength(head);
        if (position > len)
        {
            insertAtTail(head, tail, data);
            return;
        }
        // INSERTION IN MIDDLE
        // STEP 1 FIND PREV AND CURR
        int i = 1;
        Node *prevNode = head;
        while (i < position - 1)
        {
            prevNode = prevNode->next;
            i++;
        }
        Node *curr = prevNode->next;
        // STEP 2 CREATE A NODE
        Node *newNode = new Node(data);
        // STEP 3
        prevNode->next = newNode;
        newNode->prev = prevNode;
        curr->prev = newNode;
        newNode->next = curr;
        return;
    }
}
// DELETION CODE : 
void deleteFromPos(Node* &head, Node* &tail, int position){
    if (head == NULL){
        cout << "LINKEDLIST IS EMPTY" << endl;
        return ;
    }

    if(head -> next == NULL){
        //SINGLE NODE : 
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    int leng = getLength(head); 
    if (position > leng)
    {
      cout << "PLEASE ENTER A VALID POSITION" << endl;
      return;
    }
    
    if (position == 1)
    {
        //WANT TO DELETE FIRST NODE :
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return;
    }
    int len = getLength(head);  
    if (position == len)
    {
        //DELETE LAST NODE
        Node* temp = tail;
        tail = tail -> prev;
        temp -> prev = NULL;
        tail -> next = NULL;
        delete temp;
        return;
    }
      ///DELETE FROM A MIDDLE OF POSITION 
      //STEP 1 : FIND LEFT RIGHT AND CURR 
      int i = 1;
      Node* left = head;
      while (i < position - 1)
      {
        left = left -> next;
        i++;
      }
      Node* curr = left -> next;
      Node* right = curr -> next;
      //STEP 2:
      
      left -> next = right;

      //STEP 3:

      right -> prev = left;

      //STEP 4 :

      curr -> next = NULL;
      curr -> prev = NULL;
      delete curr;

}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);
    cout << endl;

    insertAtHead(head, tail, 101);
    cout << endl;
    print(head);

    cout << endl;

    insertAtTail(head, tail, 501);
    cout << endl;
    print(head);

    cout << endl;

    insertAtPosition(head, tail, 50, 5);
    cout << endl;
    print(head);

    deleteFromPos(head, tail , 10);
    cout << endl;
    print ( head);
    cout << endl;
    return 0;
}