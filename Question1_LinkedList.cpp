
/*
 * CSC 301 - Data Structures
 * Tutor-Marked Assessment: Question 1
 * Implementing a Custom Singly Linked List
 *
 * Name: Christian Nnaji
 * Matric No: 2024/B/SENG/0246
 * Student ID: 30037606
 */

#include <iostream>
using namespace std;

// Node structure - each node holds an integer and a pointer to the next node
struct Node {
    int data;       // stores the actual value
    Node* next;     // pointer to the next node in the chain
};

// LinkedList class to manage all operations on the list
class LinkedList {
private:
    Node* head;     // pointer to the first node
    int size;       // keeps track of how many nodes are in the list

public:
    // Constructor - initializes an empty list
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    // Destructor - frees all allocated memory when list goes out of scope
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Returns the current number of nodes
    int getSize() {
        return size;
    }

    // INSERT AT BEGINNING
    // Creates a new node and makes it the new head
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;   // new node points to old head
        head = newNode;         // head now points to new node
        size++;
        cout << "[INSERT FRONT] Added " << value << " at the beginning." << endl;
    }

    // INSERT AT END
    // Traverses to the last node and attaches the new node there
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;    // last node always points to null

        // Special case: if the list is empty, new node becomes head
        if (head == nullptr) {
            head = newNode;
            size++;
            cout << "[INSERT END] Added " << value << " at the end (list was empty)." << endl;
            return;
        }

        // Traverse to the last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;    // link last node to new node
        size++;
        cout << "[INSERT END] Added " << value << " at the end." << endl;
    }

    // INSERT AT MIDDLE (at a specific position, 1-indexed)
    // Position 1 means after the first node, position 2 means after the second, etc.
    void insertAtPosition(int value, int position) {
        // Validate position
        if (position < 1 || position > size) {
            cout << "[ERROR] Position " << position << " is invalid. ";
            cout << "Valid range is 1 to " << size << "." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        // Navigate to the node at the given position
        Node* current = head;
        for (int i = 1; i < position; i++) {
            current = current->next;
        }

        // Insert after the current node
        newNode->next = current->next;
        current->next = newNode;
        size++;
        cout << "[INSERT MIDDLE] Added " << value << " after position " << position << "." << endl;
    }

    // DELETE BY VALUE
    // Searches for the first node with matching value and removes it
    void deleteByValue(int value) {
        // Check if list is empty
        if (head == nullptr) {
            cout << "[ERROR] Cannot delete - the list is empty!" << endl;
            return;
        }

        // Special case: if head node holds the value
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;        // free the memory
            size--;
            cout << "[DELETE VALUE] Removed node with value " << value << "." << endl;
            return;
        }

        // Search for the node before the one to delete
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        // If we reached the end without finding the value
        if (current->next == nullptr) {
            cout << "[ERROR] Value " << value << " not found in the list." << endl;
        } else {
            Node* toDelete = current->next;
            current->next = current->next->next;    // bypass the node
            delete toDelete;                         // free memory
            size--;
            cout << "[DELETE VALUE] Removed node with value " << value << "." << endl;
        }
    }

    // DELETE BY POSITION (1-indexed)
    // Removes the node at the specified position
    void deleteByPosition(int position) {
        // Check if list is empty
        if (head == nullptr) {
            cout << "[ERROR] Cannot delete - the list is empty!" << endl;
            return;
        }

        // Validate position
        if (position < 1 || position > size) {
            cout << "[ERROR] Position " << position << " is out of range. ";
            cout << "List has " << size << " node(s)." << endl;
            return;
        }

        Node* toDelete;

        // Special case: deleting the first node
        if (position == 1) {
            toDelete = head;
            head = head->next;
            cout << "[DELETE POS] Removed node at position 1 (value: " << toDelete->data << ")." << endl;
            delete toDelete;
            size--;
            return;
        }

        // Navigate to the node just before the target
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }

        toDelete = current->next;
        current->next = toDelete->next;     // bypass the target node
        cout << "[DELETE POS] Removed node at position " << position;
        cout << " (value: " << toDelete->data << ")." << endl;
        delete toDelete;
        size--;
    }

    // DISPLAY ALL NODES
    // Traverses the list and prints each node's value
    void display() {
        if (head == nullptr) {
            cout << "[DISPLAY] The list is empty." << endl;
            return;
        }

        cout << "[DISPLAY] List (" << size << " nodes): ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    cout << "============================================" << endl;
    cout << "   CSC 301 - Singly Linked List Program    " << endl;
    cout << "   Christian Nnaji | 2024/B/SENG/0246      " << endl;
    cout << "============================================" << endl;

    // ===== TEST SET 1: Basic Operations =====
    cout << "\n--- TEST SET 1: Building and Displaying the List ---" << endl;
    LinkedList myList;

    myList.insertAtBeginning(15);
    myList.insertAtEnd(45);
    myList.insertAtBeginning(5);
    myList.insertAtEnd(60);
    myList.insertAtPosition(30, 2);     // insert 30 after position 2
    myList.display();

    // ===== TEST SET 2: Deletion Operations =====
    cout << "\n--- TEST SET 2: Deleting Nodes ---" << endl;
    myList.deleteByValue(30);
    myList.display();

    myList.deleteByPosition(1);
    myList.display();

    myList.deleteByPosition(3);         // delete last node
    myList.display();

    // ===== TEST SET 3: Error Handling & Edge Cases =====
    cout << "\n--- TEST SET 3: Error Handling ---" << endl;

    // Try to delete a value that doesn't exist
    myList.deleteByValue(999);

    // Try to delete at an invalid position
    myList.deleteByPosition(10);

    // Create an empty list and try operations on it
    LinkedList emptyList;
    emptyList.display();
    emptyList.deleteByValue(5);
    emptyList.deleteByPosition(1);

    // Try inserting at an invalid position
    myList.insertAtPosition(100, 50);

    cout << "\n--- Final State ---" << endl;
    myList.display();

    cout << "\n============================================" << endl;
    cout << "   Program Completed Successfully           " << endl;
    cout << "============================================" << endl;

    return 0;
}

