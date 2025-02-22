// Task 3
//  Stack Implementation
//  A text editor needs to support undo and redo operations efficiently. Implement two stacks using  a dynamic array to manage the undo and redo functionality.

// Operations:
// • Undo: Pop from the undo stack and push onto the redo stack.
// • Redo: Pop from the redo stack and push onto the undo stack.
// • Insert/Delete Text: Push changes onto the undo stack. write the complexity of each operation in comments.

#include <iostream>
#include <string>
using namespace std;

class UndoStack
{
private:
    string *arr;
    int top;
    int capacity;

public:
    UndoStack(int size = 1)
    {
        arr = new string[size];
        capacity = size;
        top = -1;
    };

    ~UndoStack()
    {
        delete[] arr;
    };

    void push(string x)
    {
        if (top == capacity - 1)
        {
            resize();
        }
        arr[++top] = x;
        cout << "Pushed: " << x << endl;
    };

    string pop()
    {
        return arr[top--];
        cout << "Popped: " << arr[top] << endl;
    };

    void resize()
    {
        string *newArr = new string[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity *= 2;
    };
};

class RedoStack
{
private:
    string *arr;
    int top;
    int capacity;

public:
    RedoStack(int size = 1)
    {
        arr = new string[size];
        capacity = size;
        top = -1;
    };

    ~RedoStack()
    {
        delete[] arr;
    };

    void push(string x)
    {
        if (top == capacity - 1)
        {
            resize();
        }
        arr[++top] = x;
        cout << "Pushed: " << x << endl;
    };

    string pop()
    {
        return arr[top--];
        cout << "Popped: " << arr[top] << endl;
    };

    void resize()
    {
        string *newArr = new string[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity *= 2;
    };
};

int main()
{
    UndoStack undoStack;
    RedoStack redoStack;

    // Insert text
    undoStack.push("Hello"); // O(1)

    // Undo
    string text = undoStack.pop(); // O(1)
    redoStack.push(text);          // O(1)

    // Redo
    text = redoStack.pop(); // O(1)
    undoStack.push(text);   // O(1)

    return 0;
}