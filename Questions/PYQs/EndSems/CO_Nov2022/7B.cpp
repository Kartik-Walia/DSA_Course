#include <iostream>

// Definition for a singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Recursive function to create a copy of a linked list
ListNode* copyLinkedList(ListNode* head) {
    // Base case: If the current node is null, return null
    if (head == nullptr) {
        return nullptr;
    }

    // Create a new node with the same value as the current node
    ListNode* newNode = new ListNode(head->val);

    // Recursively copy the rest of the linked list
    newNode->next = copyLinkedList(head->next);

    return newNode;
}

// Function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to delete a linked list to free memory
void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create a sample linked list
    ListNode* originalList = new ListNode(1);
    originalList->next = new ListNode(2);
    originalList->next->next = new ListNode(3);
    originalList->next->next->next = new ListNode(4);

    // Print the original linked list
    std::cout << "Original Linked List: ";
    printLinkedList(originalList);

    // Create a copy of the linked list using the recursive function
    ListNode* copiedList = copyLinkedList(originalList);

    // Print the copied linked list
    std::cout << "Copied Linked List: ";
    printLinkedList(copiedList);

    // Clean up memory by deleting the linked lists
    deleteLinkedList(originalList);
    deleteLinkedList(copiedList);

    return 0;
}
