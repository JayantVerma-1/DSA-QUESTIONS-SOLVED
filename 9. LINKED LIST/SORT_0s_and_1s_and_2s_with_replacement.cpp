//if data replacement in the existing linkedlist is allowed in QUESTION:(i.e seedhe purani value change kardena nodes ki nayi value se bina position changes kiye )

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
void sortZeroOneTwo(Node *head)
{
    // STEP 1 : FIND THE QUANTITY OF ZEROES , ONES , AND TWOS.
    int zero = 0;
    int one = 0;
    int two = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zero++;
        else if (temp->data == 1)
            one++;
        else if (temp->data == 2)
            two++;
        temp = temp->next;
    }
    // STEP 2 : FILL ZEROES , ONES , AND TWOS IN THE ORIGINAL L.L.
    temp = head;
    while (temp != NULL)
    {
        // FILL ZEROES
        while (zero--)
        {
            temp->data = 0;
            temp = temp->next;
        }

        // FILL ONES
        while (one--)
        {
            temp->data = 1;
            temp = temp->next;
        }

        // FILL TWOS
        while (two--)
        {
            temp->data = 2;
            temp = temp->next;
        }
    }
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(0);

    head->next = second;
    second->next = third;
    third->next = fourth;

    cout << " INPUT LL : ";
    print(head);

    sortZeroOneTwo(head);
    print(head);

    return 0;
}