#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

bool isEven(int x) { return x % 2 == 0; }

int main()
{
    list<int> myList1 = {1, 2, 3, 4, 5};

    // Print the myList1
    cout << "Original list: ";
    for (int x : myList1)
    {
        cout << x << " ";
    }
    cout << endl;

    // Remove even numbers from the list using a function pointer
    myList1.remove_if(isEven); // Removes all even numbers

    // Print the myList1
    cout << "Modified list: ";
    for (int x : myList1)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}