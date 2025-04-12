// Create a function template named sumAll that accepts a variable number of arguments
// using variadic templates and returns the sum of all arguments passed to it.

// ● The function should work with any numeric type (e.g., int, float, double, long, etc.).
// ● Make sure the return type is correctly deduced based on the input.
// ● Write a main function to test sumAll with different combinations of data types and argument counts.

#include <iostream>
using namespace std;

template <typename T>
T sumAll(T value)
{
    return value; // Base case: if only one argument is passed, return it
}

template <typename T, typename... Args>
T sumAll(T value, Args... args)
{
    return value + sumAll(args...); // Recursive case: add the first argument to the sum of the rest
}

int main()
{
    cout << "Sum of 1, 2, 3: " << sumAll(1, 2, 3) << endl;             // int
    cout << "Sum of 1.5, 2.5, 3.5: " << sumAll(1.5, 2.5, 3.5) << endl; // double
    cout << "Sum of 1, 2.5, 3: " << sumAll(1, 2.5, 3) << endl;         // mixed types
    cout << "Sum of 1L, 2L, 3L: " << sumAll(1L, 2L, 3L) << endl;       // long
    return 0;
}