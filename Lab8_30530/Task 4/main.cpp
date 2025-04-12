// You are required to implement a program that demonstrates the usage of function pointers along with
// different algorithms provided by the C++ Standard Library's algorithm library.
// The program will perform various operations on a list of integers based on user input.

// Implement the following functions to perform various operations on a list of integers:
// ● sortArray: Sorts the elements in the array in non-decreasing order.
// ● reverseArray: Reverses the order of the elements in the array.
// ● rotateArray: Rotates the order of the elements in the array.
// ● findMinElement: Finds the minimum element in the array.
// ● findMaxElement: Finds the maximum element in the array.
// ● countOccurrences: Counts the number of occurrences of a specific value in the array.

// Define a function custom_algorithm that takes a vector of integers and a function pointer as arguments.
// This function will apply the operation specified by the function pointer to the vector of integers.

// In the main function, demonstrate the usage of function pointers by calling the custom_algorithm function
// with different function pointers corresponding to the operations mentioned above.

// Hints:
// Import: #include<algorithm> and use following built-in functions
// ● Sort: std::sort(arr.begin(), arr.end());
// ● Reverse: std::reverse(arr.begin(), arr.end());
// ● Rotate: std::rotate(arr.begin(), arr.begin() + 1, arr.end());
// ● MinElement= std::min_element(arr.begin(), arr.end());
// ● MaxElement= std::max_element(arr.begin(), arr.end());
// ● Count= std::count(arr.begin(), arr.end(), value);

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to sort the array in non-decreasing order
void sortArray(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}

// Function to reverse the order of the elements in the array
void reverseArray(vector<int> &arr)
{
    reverse(arr.begin(), arr.end());
}

// Function to rotate the order of the elements in the array
void rotateArray(vector<int> &arr)
{
    rotate(arr.begin(), arr.begin() + 1, arr.end());
}

// Function to find the minimum element in the array
void findMinElement(vector<int> &arr)
{
    cout << "Minimum Element: " << *min_element(arr.begin(), arr.end()) << endl;
}

// Function to find the maximum element in the array
void findMaxElement(vector<int> &arr)
{
    cout << "Maximum Element: " << *max_element(arr.begin(), arr.end()) << endl;
}

// Function to count the number of occurrences of a specific value in the array
void countOccurrences(vector<int> &arr)
{
    int value;
    cout << "Enter the value to count: ";
    cin >> value;
    cout << "Count: " << count(arr.begin(), arr.end(), value) << endl;
}

// Function to apply the specified operation on the array using a function pointer
void custom_algorithm(vector<int> &arr, void (*operation)(vector<int> &))
{
    operation(arr);
}

// Function to display the array
void displayArray(const vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    int choice;

    cout << "Original array: ";
    displayArray(arr);

    cout << "Choose an operation:\n";
    cout << "1. Sort\n";
    cout << "2. Reverse\n";
    cout << "3. Rotate\n";
    cout << "4. Find Min Element\n";
    cout << "5. Find Max Element\n";
    cout << "6. Count Occurrences\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        custom_algorithm(arr, sortArray);
        break;
    case 2:
        custom_algorithm(arr, reverseArray);
        break;
    case 3:
        custom_algorithm(arr, rotateArray);
        break;
    case 4:
        custom_algorithm(arr, findMinElement);
        break;
    case 5:
        custom_algorithm(arr, findMaxElement);
        break;
    case 6:
        custom_algorithm(arr, countOccurrences);
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 1;
    }

    cout << "Modified array: ";
    displayArray(arr);

    return 0;
}