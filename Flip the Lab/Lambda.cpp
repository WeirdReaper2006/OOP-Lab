#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
int main()
{
    list<int> myList = {1, -2, 3, 4, 5, -17, 45, 0, -10, 20};

    // Print the myList
    cout << "Original list: ";
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    // Lambda function to remove all negative numbers
    myList.remove_if([](int x)
                     { return x < 0; }); // Removes all negative numbers

    // Print the myList
    cout << "Modified list: ";
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    // Lambda function to remove negative numbers
    list<int> myList2 = {-5, -10, 0, 5, 10};

    return 0;
}