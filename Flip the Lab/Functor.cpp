#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct LessThanTen
{
    bool operator()(int x) { return x < 10; }
};

int main()
{
    list<int> myList = {5, 10, 15, 20, 25};

    // Functor object to remove numbers less than 10
    myList.remove_if(LessThanTen()); // Removes all numbers less than 10

    // Print the myList2
    cout << "Modified list: ";
    for (int x : myList)
    {
        cout << x << " ";
    }

    return 0;
}