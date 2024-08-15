// GFG QUESTION

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution
{
public:
    void linkdelete(Node *head, int M, int N)
    {
        if (!head)
            return;
        Node *it = head;
        for (int i = 0; i < M - 1; i++)
        {
            // IF M NODES ARE NOT AVAILABLE:
            if (!it)
                return;
            it = it->next;
        }

        // it -> WOULD BE AT Mth NODE:
        if (!it)
            return;
        Node *MthNode = it;
        it = MthNode->next;

        for (int i = 0; i < N; i++)
        {
            if (!it)
                break;

            Node *temp = it->next;
            delete it;
            it = temp;
        }
        MthNode->next = it;

        //SOLVE FURTHER RECURSIVELY : 
        linkdelete(it, M, N);
    }
};

// Function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution sol;

    // Creating a linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int M = 3;
    int N = 1;

    cout << "Original list: ";
    printList(head);

    sol.linkdelete(head, M, N);

    cout << "List after deleting M nodes and keeping N nodes: ";
    printList(head);

    return 0;
}
