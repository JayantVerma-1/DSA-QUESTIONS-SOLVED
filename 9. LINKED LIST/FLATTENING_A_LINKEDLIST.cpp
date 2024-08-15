//GFG QUES.
#include <iostream>
using namespace std;

// Definition for a Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;
};

// Function to merge two sorted linked lists RECURSIVELY
Node* merge(Node* a, Node* b) {
    if (!a) return b; // same meaning as " if(a == NULL)"
    if (!b) return a; // same meaning as " if(b == NULL)"
    
    Node* ans = nullptr;
    if (a->data < b->data) {
        ans = a;
        a->bottom = merge(a->bottom, b);
    } else {
        ans = b;
        b->bottom = merge(a, b->bottom);
    }
    return ans;
}

// Function to flatten a multilevel linked list (piche se merge kr rhe h)
Node* flatten(Node* root) {
    if (!root) return nullptr;
    Node* mergedLL = merge(root, flatten(root->next));
    return mergedLL;
}

// Main function
int main() {
    // Creating sample linked list
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 3;
    head->next->next = new Node();
    head->next->next->data = 5;

    head->bottom = new Node();
    head->bottom->data = 2;
    head->bottom->bottom = new Node();
    head->bottom->bottom->data = 4;

    head->next->bottom = new Node();
    head->next->bottom->data = 6;

    // Flattening the linked list
    Node* flattenedList = flatten(head);

    // Printing the flattened linked list
    cout << "Flattened Linked List: ";
    while (flattenedList) {
        cout << flattenedList->data << " ";
        flattenedList = flattenedList->bottom;
    }

    return 0;
}
