#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    // Example of deleting an element from the middle of a list in C++ (if location is known)
    list<int> myList = {1, 2, 3, 4, 5};
    auto it = myList.begin();
    advance(it, 2);   // Move to the third element (value 3)
    myList.erase(it); // Erase the third element

    // Print the remaining elements
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    // Example of deleting an element from the middle of a list in C++ (if location is not known)
    list<int> myList2 = {1, 2, 3, 4, 5};
    int valueToDelete = 3;
    auto it2 = find(myList2.begin(), myList2.end(), valueToDelete);
    if (it2 != myList2.end())
    {
        myList2.erase(it2); // Erase the element with value 3
    }
    // Print the remaining elements
    for (int x : myList2)
    {
        cout << x << " ";
    }

    return 0;
}