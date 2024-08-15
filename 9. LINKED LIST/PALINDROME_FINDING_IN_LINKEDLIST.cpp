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
// reverse of L L ka code
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool checkPalindrome(Node *&head)
{
    if (head == NULL)
    {
        cout << " LINKED LIST IS EMPTY" << endl;
        return true;
    }
    if (head->next == NULL)
    {
        // only one node
        return true;
    }
    // for Greater than one node in linkedlist
    // STEP 1 : FIND THE MIDDLE NODE
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        } // SLOW POINTER WILL BE POINTING TO THE MIDDLE NODE
    }
    // STEP 2 : REVERSE THE LINKEDLIST AFTER THE MIDDLE NODE
    Node *reverseLLKaHead = reverse(slow->next);
    slow->next = reverseLLKaHead;

    // STEP 3 : START COMPARISION
    Node *temp1 = head;
    Node *temp2 = reverseLLKaHead;
    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return false; // i.e not a palindrome
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}
int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(20);
    Node *fifth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    bool isPalindrome = checkPalindrome(head);

    if (isPalindrome)
    {
        cout << " LL IS A VALID PALINDROME " << endl;
    }
    else
    {
        cout << " LL ISNT A VALID PALINDROME" << endl;
    }

    return 0;
}