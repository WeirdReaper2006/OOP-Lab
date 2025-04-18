#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<int> myList;

    // Push elements to the end of the list
    myList.push_front(1);
    myList.push_front(2);
    myList.push_front(3);
    myList.push_front(4);
    myList.push_front(5);

    // Print the myList
    cout << "Original list: ";
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    // Remove elements from the end of the list
    myList.pop_front(); // Removes the last element (5)
    myList.pop_front(); // Removes the last element (4)

    // Print the myList after popping elements
    cout << "List after popping elements: ";
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}