//LEETCODE QUES - 2181
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return nullptr;
        ListNode* slow = head, *fast = head->next, *newLastNode = nullptr;
        int sum = 0;
        while (fast) {
            if (fast->val != 0) {
                sum += fast->val;
            }
            else {
                // i.e. fast->val = 0
                slow->val = sum;
                newLastNode = slow;
                slow = slow->next;
                sum = 0;
            }
            fast = fast->next;
        }
        ListNode* temp = newLastNode->next;
        
        // JUST FORMED NEW LIST:
        newLastNode->next = nullptr;
        
        // DELETING OLD LIST TO SAVE MEMORY
        while (temp) {
            ListNode* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
        return head;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Creating a linked list
    ListNode* head = new ListNode(0);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(0);

    cout << "Original list: ";
    printList(head);

    ListNode* mergedHead = sol.mergeNodes(head);

    cout << "List after merging nodes: ";
    printList(mergedHead);

    return 0;
}
