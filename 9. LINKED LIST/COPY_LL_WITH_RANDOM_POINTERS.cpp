// LEET CODE 138
/*we have also done it using map on leet code , can check it is saved in submissions. problem was that using map we used extra memory and thus...
the SPACE COMPLEXITY became O{n}. now in this we have done it WITHOUT USING MAPS instead of it we used pointers ans thus the SPACE COMPLEXITY = O{1}*/

#include <iostream>
using namespace std;

// Definition for a Node
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        // Step 1: Clone A -> A'
        Node *it = head;
        while (it)
        {
            Node *clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }

        // Step 2: Assign random links of A' with the help of old nodes
        it = head;
        while (it)
        {
            Node *clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }

        // Step 3: Detach A' from A
        it = head;
        Node *clonedHead = it->next;
        while (it)
        {
            Node *clonedNode = it->next;
            it->next = it->next->next;
            if (clonedNode->next != nullptr)
            {
                clonedNode->next = clonedNode->next->next;
            }
            it = it->next;
        }

        return clonedHead;
    }
};

// Utility function to print the linked list
void printLinkedList(Node *head)
{
    while (head)
    {
        cout << "(" << head->val << ", ";
        if (head->random)
            cout << head->random->val << ") -> ";
        else
            cout << "null) -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main()
{
    // Example usage
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;
    head->next->random = head;

    Solution solution;
    Node *clonedList = solution.copyRandomList(head);

    cout << "Original Linked List with Random Pointers:" << endl;
    printLinkedList(head);

    cout << "Cloned Linked List with Random Pointers:" << endl;
    printLinkedList(clonedList);

    return 0;
}
