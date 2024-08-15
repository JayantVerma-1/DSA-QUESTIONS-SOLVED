#include <iostream>

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
    
    SinglyLinkedListNode(int value) : data(value), next(nullptr) {}
};

void fun(SinglyLinkedListNode* head, int &positionFromTail, int& ans){
    if (head == nullptr) return;
    fun(head->next, positionFromTail, ans);
    
    if (positionFromTail == 0) {
        ans = head->data;
    }
    positionFromTail--;
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int ans = -1;
    fun(llist, positionFromTail, ans);
    return ans;
}

int main() {
    // Creating a sample linked list
    SinglyLinkedListNode* head = new SinglyLinkedListNode(1);
    head->next = new SinglyLinkedListNode(2);
    head->next->next = new SinglyLinkedListNode(3);
    head->next->next->next = new SinglyLinkedListNode(4);
    head->next->next->next->next = new SinglyLinkedListNode(5);
    
    // Position from tail to retrieve
    int positionFromTail = 4;
    
    // Retrieving the node value
    int nodeValue = getNode(head, positionFromTail);
    
    // Displaying the result
    std::cout << "Node value " << positionFromTail << " nodes from tail: " << nodeValue << std::endl;
    
    // Cleaning up the memory
    while (head) {
        SinglyLinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
