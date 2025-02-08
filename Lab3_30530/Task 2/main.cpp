// Implement a browser history tracker to simulate webpage navigation using a singly linked list.
// When users browse the web, browsers track visited pages to allow backward/forward navigation.
// Your task is to model this using a singly linked list.
// Implement a BrowserHistory class with the following functionality:

// 1. Visit a New Page: Add a new URL to the history.
// 2. Navigate Backward: Move back N steps in the history.
// 3. Display History: Print the entire history with the current page highlighted.

// Class Structure
// 1. Node Class:

// o Attributes:
//  url (std::string): The webpage URL.
//  next (Node*): Pointer to the next node.

// o Constructor: Initializes url and sets next to nullptr.

// 2. BrowserHistory Class:

// o Private Attributes:
//  head (Node*): Oldest page in history.
//  tail (Node*): Newest page in history.
//  current (Node*): Current page for navigation.

// o Public Methods:
//  visitPage(std::string url):
//  Adds a new page to the end of the history.
//  Updates current to point to the newly added page.

//  goBack(int steps):
//  Moves the current pointer backward by steps pages.
//  If steps exceed available history, stop at the oldest page.
//  Print the current URL after navigation (e.g., Current URL: https://google.com).

//  displayHistory():
//  Prints all URLs from oldest to newest, marking the current page with [CURRENT].

// 3. Destructor: Deallocates all nodes to prevent memory leaks.

#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
    string url;
    Node *next;

public:
    Node(string url)
    {
        this->url = url;
        this->next = nullptr;
    }
    friend class BrowserHistory;
};

class BrowserHistory
{
private:
    Node *head;
    Node *tail;
    Node *current;

public:
    BrowserHistory()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->current = nullptr;
    }

    void visitPage(string url)
    {
        Node *newNode = new Node(url);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            current = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            current = newNode;
        }
    }

    void goBack(int steps)
    {
        Node *temp = head;
        Node *prev = nullptr;
        for (int i = 0; i < steps; i++)
        {
            if (temp == current)
            {
                current = prev;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Current URL: " << current->url << endl;
    }

    void displayHistory()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp == current)
            {
                cout << "[CURRENT] " << temp->url << endl;
            }
            else
            {
                cout << temp->url << endl;
            }
            temp = temp->next;
        }
    }

    ~BrowserHistory()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main()
{
    BrowserHistory history;
    history.visitPage("https://google.com");
    history.visitPage("https://youtube.com");
    history.visitPage("https://facebook.com");
    history.visitPage("https://twitter.com");
    history.displayHistory();
    history.goBack(2);
    history.displayHistory();
    return 0;
}