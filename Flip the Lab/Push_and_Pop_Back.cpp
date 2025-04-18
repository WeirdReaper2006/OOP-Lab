#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<int> myList;

    // Push elements to the end of the list
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);

    // Print the myList
    cout << "Original list: ";
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    // Remove elements from the end of the list
    myList.pop_back(); // Removes the last element (5)
    myList.pop_back(); // Removes the last element (4)
    myList.pop_back(); // Removes the last element (3)
    myList.pop_back(); // Removes the last element (2)

    // Print the myList after popping elements
    cout << "List after popping elements: ";
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}