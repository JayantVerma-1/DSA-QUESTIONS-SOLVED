//21 LEETCODE
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *ans = new ListNode(-1);
        ListNode *mptr = ans;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                mptr->next = list1;
                mptr = list1;
                list1 = list1->next;
            }
            else
            {
                mptr->next = list2;
                mptr = list2;
                list2 = list2->next;
            }
        }

        if (list1)
        {
            mptr->next = list1;
            mptr = list1;
            list1 = list1->next;
        }

        if (list2)
        {
            mptr->next = list2;
            mptr = list2;
            list2 = list2->next;
        }
        return ans->next;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating two sorted linked lists
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    // Merging the two lists
    Solution sol;
    ListNode *mergedList = sol.mergeTwoLists(list1, list2);

    // Printing the merged list
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
