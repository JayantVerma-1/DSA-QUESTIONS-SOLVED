//REFER TO LEET CODE QUES NO 2058 :

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = { -1 , -1 }; // min dist , max dist 
        ListNode* prev = head;
        if (!prev) return ans;
        ListNode* curr = head->next;
        if (!curr) return ans;
        ListNode* nxt = head->next->next;
        if (!nxt) return ans;

        int firstCP = -1;
        int lastCP = -1;
        int minDist = INT_MAX;
        int i = 1;
        while (nxt) {
            bool isCP = ((curr->val > prev->val && curr->val > nxt->val) ||
                         (curr->val < prev->val && curr->val < nxt->val)
                         ? true : false);
            if (isCP && firstCP == -1) {
                firstCP = i;
                lastCP = i;
            }
            else if (isCP) {
                minDist = min(minDist, i - lastCP);
                lastCP = i;
            }
            ++i;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }
        if (lastCP == firstCP) {
            // only ONE CP was found
            return ans;
        }
        else {
            ans[0] = minDist;
            ans[1] = lastCP - firstCP;
        }
        return ans;
    }
};

// Function to print the vector
void printVector(vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Creating a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Linked List: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    vector<int> result = sol.nodesBetweenCriticalPoints(head);
    
    cout << "Result: ";
    printVector(result);

    return 0;
}
