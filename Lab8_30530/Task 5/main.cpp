// Write a function int findpos(void *A, int n, ftype fp), where A is a generic array of size n and
// ftype is a function pointer that takes an array and size as its argument and apply the algorithm to find the position
// based on the function.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function for finding the position of the minimum element in the array
int findMinPosition(vector<int> &arr)
{
    return min_element(arr.begin(), arr.end()) - arr.begin();
}

// Function for finding the position of the maximum element in the array
int findMaxPosition(vector<int> &arr)
{
    return max_element(arr.begin(), arr.end()) - arr.begin();
}

// Function for finding the position for the given function pointer
int findpos(void *A, int n, int (*fp)(vector<int> &))
{
    vector<int> *arr = static_cast<vector<int> *>(A);
    return fp(*arr);
}

int main()
{
    // An example array of integers
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = arr.size();

    // Finding the position of the minimum element
    int minPos = findpos(&arr, n, findMinPosition);
    cout << "Position of minimum element: " << minPos << endl;

    // Finding the position of the maximum element
    int maxPos = findpos(&arr, n, findMaxPosition);
    cout << "Position of maximum element: " << maxPos << endl;

    return 0;
}