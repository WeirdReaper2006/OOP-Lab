// A doubly linked list is a data structure where each node contains:
//  Data/Value: The information stored in the node.
//  Next Pointer: A reference to the next node in the list.
//  Previous Pointer: A reference to the previous node in the list.

// This structure allows you to traverse the list in both directions (forward and backward), making some operations more efficient.

// Implement a simple doubly linked list that supports the following operations:

//  Traverse Forward and Backward
//  Forward Traversal: Start at the head (beginning) of the list and move to the tail (end) by following the next pointers, printing or collecting each node's value.
//  Backward Traversal: Start at the tail of the list and move back to the head by following the previous pointers, printing or collecting each node's value.

//  Get Value at a Specific Index
//  Write a function/method that takes an index (with the head at index 0) and returns the value stored at that position in the list.
//  Consider how you would handle an invalid index (e.g., an index that is out of bounds).

//  Remove the First Element
//  Write a function/method that removes the first node (the head) of the list.
//  Update the pointers accordingly so that the list remains intact (i.e., the new head should have its previous pointer set to null or equivalent).

//  Add a Value at the End
//  Write a function/method that appends a new node with a given value at the end (tail) of the list.
//  Make sure to update the pointers: the current tail’s next pointer should point to the new node, and the new node’s previous pointer should point to the current tail.

#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    void forwardTraverse()
    {
        Node *current = this;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void backwardTraverse()
    {
        Node *current = this;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    int getValueAtIndex(int index)
    {
        Node *current = this;
        int i = 0;
        while (current != nullptr)
        {
            if (i == index)
            {
                return current->data;
            }
            current = current->next;
            i++;
        }
        return -1;
    }

    Node *removeFirstElement()
    {
        Node *current = this;
        Node *newHead = current->next;
        newHead->prev = nullptr;
        delete current;
        return newHead;
    }

    Node *addValueAtEnd(int value)
    {
        Node *current = this;
        Node *newNode = new Node(value);
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        return this;
    }
};

int main()
{
    Node *head = new Node(1);
    head->addValueAtEnd(2)->addValueAtEnd(3)->addValueAtEnd(4)->addValueAtEnd(5);
    head->forwardTraverse();
    head->backwardTraverse();
    cout << head->getValueAtIndex(2) << endl;
    head = head->removeFirstElement();
    head->forwardTraverse();
    return 0;
}