// A student learning about data structures wants to implement a linked list that is not limited to a single data type.
// Create a template class GenericLinkedList that includes:
// ● Methods for inserting and deleting elements at the end of tail of the list.
// ● Exception handling for attempts to delete from an empty list
// ● A method to display all elements in the list.
// ● Test cases that demonstrate the list’s functionality with different data types.

#include <iostream>
#include <exception>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class GenericLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    GenericLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Method to insert an element at the end of the list
    void insert(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Method to remove the last element from the list
    void remove()
    {
        if (head == nullptr)
        {
            throw runtime_error("Cannot delete from an empty list.");
        }
        Node<T> *temp = head;
        if (head == tail) // Only one element in the list
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            tail = temp;
        }
    }

    // Method to display all elements in the list
    void display()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
        cout << endl;
    }

    ~GenericLinkedList()
    {
        while (head != nullptr)
        {
            remove();
        }
    }
};

int main()
{
    try
    {
        GenericLinkedList<int> intList;
        intList.insert(10);
        intList.insert(20);
        intList.insert(30);
        cout << "Integer Linked List: " << endl;
        intList.display();

        GenericLinkedList<string> stringList;
        stringList.insert("Alice");
        stringList.insert("Bob");
        stringList.insert("Charlie");
        cout << "String Linked List: " << endl;
        stringList.display();

        // Testing exception handling
        cout << "Testing exception for empty list delete" << endl;
        GenericLinkedList<double> doubleList;
        doubleList.remove(); // This should throw an exception
    }
    catch (const runtime_error &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}