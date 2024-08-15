// REVERSE A LINKEDLIST

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
// REVERSE THE LINKEDLIST USING RECCURSION
Node *reverseUsingReccursion(Node *&prev, Node *&curr)
{
    // BASE CASE
    if (curr == NULL)
    {
        // Linkedlist reverse ho chuki hai!
        return prev;
    }

    // 1 CASE SOLVE KARDE BAAKI RECURSION WILL TAKE CARE OF!
    Node *forward = curr->next;
    curr->next = prev;

    // RECURSIVE CALL KARDO!
   return reverseUsingReccursion(curr, forward);
}

// REVERSE LINKEDLIST USING LOOPS!
Node* reverseUsingLoop(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
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
    print(head);

    cout << endl;
    Node *prev = NULL;
    Node *curr = head;
    cout << " Printing reverse list : ";
    head = reverseUsingReccursion(prev , curr);
    cout << endl;
    print(head);
    cout << endl;
    return 0;
}