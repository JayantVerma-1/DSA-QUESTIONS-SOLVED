// LEET CODE - 61

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int getLength(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;

        int len = getLength(head);
        int actualRotateK = (k % len);
        if (actualRotateK == 0)
            return head;
        int newLastNodePos = len - actualRotateK - 1;

        ListNode *newLastNode = head;
        for (int i = 0; i < newLastNodePos; i++)
        {
            newLastNode = newLastNode->next;
        }
        ListNode *newHead = newLastNode->next;
        newLastNode->next = NULL;

        ListNode *it = newHead;
        while (it->next != NULL)
        {
            it = it->next;
        }
        it->next = head;
        return newHead;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int k = 2;

    cout << "Original list: ";
    printList(head);

    ListNode *rotatedHead = sol.rotateRight(head, k);

    cout << "List after rotation: ";
    printList(rotatedHead);

    return 0;
}
