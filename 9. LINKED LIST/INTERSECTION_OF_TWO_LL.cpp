//LEETCODE - 160

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        
        while(a->next && b->next){
            if(a == b){
                return a;
            }
            a = a->next;
            b = b->next;
        }
        
        if(a->next == NULL && b->next == NULL && a != b)
            return nullptr;
        
        if(a->next == NULL){
            // B LL is BIGGER THAN A;
            // now we need to find out how much bigger it is
            int blen = 0;
            while(b->next){
                blen++;
                b = b->next;
            }
        
            while(blen--){
                headB = headB->next;
            }
        }
        else{
            // A LL is BIGGER THAN B;
            // we now need to find out how much bigger it is from b
            int alen = 0;
            while(a->next){
                alen++;
                a = a->next;
            }
            while(alen--){
                headA = headA->next;
            }
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

int main() {
    // Example usage
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;

    Solution solution;
    ListNode *intersectionNode = solution.getIntersectionNode(headA, headB);

    if (intersectionNode)
        cout << "Intersection node value: " << intersectionNode->val << endl;
    else
        cout << "No intersection node found" << endl;

    // Deallocating memory
    ListNode *temp;
    while (headA) {
        temp = headA;
        headA = headA->next;
        delete temp;
    }
    while (headB) {
        temp = headB;
        headB = headB->next;
        delete temp;
    }

    return 0;
}
