// if data replacement in the existing linkedlist is NOT allowed in QUESTION

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *sort2(Node *&head)
{

    if (head == NULL)
    {
        // LINKEDLIST hi KHALI H EMPTY L.L.
        cout << " L.L is empty " << endl;
        return NULL;
    }
    if (head->next == NULL)
    {
        // EK HI NODE HAI LINKEDLIST HAI
        return head;
    }

    // CREATE DUMMY NODES
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    // TRAVERSE THE ORIGINA L.L
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            // TAKE OUT THE ZERO WALI NODE
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            // append the zero node in zeroHead LL
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (curr->data == 1)
        {
            // TAKE OUT THE ONE WALI NODE
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            // append the one node in zeroHead LL
            oneTail->next = temp;
            oneTail = temp;
        }
        else if (curr->data == 2)
        {
            // TAKE OUT THE TWO WALI NODE
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            // append the two node in zeroHead LL
            twoTail->next = temp;
            twoTail = temp;
        }
    }
    // YAHA PAR AAPKI TEENO LINKEDLIST READY HAIN

    // REMOVING DUMMY NODES
    // Remove oneHead dummynode (-1 data vali)
    Node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    // Remove twoHead dummynode (-1 data vali)
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // JOIN ALL THREE LINKEDLIST
    if (oneHead != NULL)
    {
        // i.e one vali list is NOT EMPTY
        zeroTail->next = oneHead;
        if (twoHead != NULL)
            oneTail->next = twoHead;
    }
    else
    {
        // i.e. one vali list is empty
        if (twoHead != NULL)
        {
            zeroTail->next = twoHead;
        }
    }

    // Remove zeroHead dummynode (-1 data vali)
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // task 4 : RETURN HEAD OF THE MODIFIED LINKEDLIST
    return zeroHead;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(0);
    Node *fifth = new Node(0);
    Node *sixth = new Node(0);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    cout << " INPUT LL : " << endl;
    print(head);

    cout << "Printing the sorted L.L. without replacement : " << endl;
    head = sort2(head);
    print(head);

    return 0;
}