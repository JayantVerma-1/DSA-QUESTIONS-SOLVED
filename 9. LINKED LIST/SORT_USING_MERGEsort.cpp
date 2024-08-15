// 148 LEETcode
// TC of code - O{logN}
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
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *ans = new ListNode(-1);
        ListNode *mptr = ans;

        while (list1 != NULL && list2 != NULL)
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
            list1 = list1;
        }

        if (list2)
        {
            mptr->next = list2;
            mptr = list2;
            list2 = list2->next;
        }
        return ans->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        // BREAK LL INTO TWO HALVES USING MID NODE
        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        // sort using recursion
        left = sortList(left);
        right = sortList(right);

        // merge both left and right LINKEDLISTS
        ListNode *mergedLL = merge(left, right);

        return mergedLL;
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
    // Creating a sample linked list
    ListNode *head = new ListNode(3);
    head->next = new ListNode(1);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);

    // Creating an instance of the Solution class
    Solution sol;

    // Sorting the linked list
    ListNode *sortedList = sol.sortList(head);

    // Printing the sorted list
    cout << "Sorted List: ";
    printList(sortedList);

    return 0;
}
