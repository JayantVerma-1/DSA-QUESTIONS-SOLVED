// if data replacement in the existing linkedlist is NOT allowed in QUESTION
//this code is not working for some cases like 99 + 99
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
Node *solve(Node *&head1, Node* &head2)
{
    // STEP 1 : REVERSE BOTH LL.
    head1 = reverse(head1);
    head2 = reverse(head2);

    // STEP 2 : ADD BOTH LL.
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    int carry = 0;

    while (head1 != NULL && head2 != NULL )
    {
        // calculate sum
        int sum = carry + head1->data + head2->data;
        // find digit to create node for 
        int digit = sum % 10;
        // calculate the remaining carry
        int carry = sum / 10;

        // create a new node for the digit
        Node *newNode = new Node(digit);
        // attach the new node into ans wali linkedlist
        if (ansHead == NULL)
        {
            // that mean ki first node insert karre ho
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // in case when first lilnkedlist ki length second vaali se jyaada ho
    while (head1 != NULL)
    {
        int sum = carry + head1->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }
    // in case when second lilnkedlist ki length first vaali se jyaada ho
    while (head2 != NULL)
    {
        int sum = carry + head2->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }
    // handle carry ko alag se in case carry bach jae dono linkedlists ke null hone ke baad bhi!
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail -> next = newNode;
        ansTail = newNode;
    }

    // STEP 3 : REVERSE THE SOLUTION LL.
    ansHead = reverse(ansHead);
    return ansHead;
}
int main()
{
    // LINKEDLIST - ONE
    Node *head1 = new Node(9);
    Node *second1 = new Node(9);
    head1->next = second1;

    // LINKEDLIST - TWO
    Node *head2 = new Node(0);
    Node *second2 = new Node(9);
    Node *third2 = new Node(9);
    head2->next = second2;
    second2->next = third2;

    Node *ans = solve(head1, head2);

    print(ans);

    return 0;
}