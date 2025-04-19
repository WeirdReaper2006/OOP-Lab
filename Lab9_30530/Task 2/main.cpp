// This lab task focuses on checking if an expression contains balanced opening and closing braces ({ and }).
// Utilize a custom functor and STL algorithms to achieve this.
// Create a custom functor named BalancedBraces that
// takes a string expression as input and returns true if the expression contains balanced opening and
// closing braces ({ and }), and false otherwise.

// Task Instructions:
// 1. Implement the operator() function within the BalancedBraces functor.
// 2. Inside the operator function, iterate through the characters of the expression string.
// 3. Maintain a counter for opening and closing braces.
// 4. Increment the opening brace counter for each encountered '{' and decrement the closing brace counter for each encountered '}'.
// 5. If a closing brace is encountered but the opening brace counter is zero, the expression is unbalanced.
// 6. Return true if the expression ends with balanced counters (both zero) and false otherwise.

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Functor to check if braces are balanced
struct BalancedBraces
{
    bool operator()(const string &expression) const
    {
        int openCount = 0;  // Counter for '{'
        int closeCount = 0; // Counter for '}'

        for (char ch : expression)
        {
            if (ch == '{')
                openCount++;
            else if (ch == '}')
            {
                closeCount++;
            }
        }

        return openCount == closeCount; // Check if both counts are equal
    }
};

int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression); // Read the entire line including spaces

    // Create an instance of the functor
    BalancedBraces checkBalanced;

    // Check if the expression is balanced
    if (checkBalanced(expression))
        cout << "The expression is balanced." << endl;
    else
        cout << "The expression is not balanced." << endl;

    return 0;
}